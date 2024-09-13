%{
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "ast.h"
#include "symbol_table.h"

using namespace std;

extern int yylex();
void yyerror(const char *s);

extern ASTNode *ast_root;

%}

%define api.namespace {Parser}
%define parser_class_name {Parser}

%code requires {
    #include "ast.h"
}

%union {
    int int_val;
    bool bool_val;
    char *id;
    ASTNode *node;
    std::vector<ASTNode*> *node_list;
}

%token <int_val> UNSIGNED_INT
%token <bool_val> BOOL_CONST
%token <id> IDENTIFIER

%token ASSIGN SEMICOLON COMMA LPAREN RPAREN LBRACKET RBRACKET LBRACE RBRACE
%token PLUS MINUS MULTIPLY DIVIDE MODULO
%token INC DEC NOT OR GT LT
%token UINT BOOLEAN CUINT CBOOLEAN
%token ARRAY1DBOOL ARRAY2DBOOL ARRAY1DUINT ARRAY2DUINT
%token EXTEND1 EXTEND2 SIZE1 SIZE2
%token WHILE DO IF ELSE FUNCTION
%token FORW BACK RIGHT_OP LEFT_OP GETF GETB GETR GETL PUSHF PUSHB PUSHR PUSHL UNDO

%left OR
%left GT LT
%left PLUS MINUS
%left MULTIPLY DIVIDE MODULO
%right NOT

%type <node> program statement variable_declaration constant_declaration array_declaration array_extension assignment increment decrement loop conditional function_declaration function_call robot_operation group_of_statements expression arithmetic_expression logical_expression comparison array_access arithmetic_expression_list return_variables parameters variables expressions movement_operator sensor_operator

%%

program:
    /* empty */
    | program statement
        {
            if ($1) {
                $1->addSibling($2);
                $$ = $1;
            } else {
                $$ = $2;
            }
        }
    ;

statement:
    variable_declaration
    | constant_declaration
    | array_declaration
    | array_extension
    | assignment
    | increment
    | decrement
    | loop
    | conditional
    | function_declaration
    | function_call
    | robot_operation
    | group_of_statements
    ;

variable_declaration:
    UINT IDENTIFIER ASSIGN arithmetic_expression SEMICOLON
        {
            $$ = new VarDeclarationNode($2, VarType::UINT, $4);
        }
    | BOOLEAN IDENTIFIER ASSIGN logical_expression SEMICOLON
        {
            $$ = new VarDeclarationNode($2, VarType::BOOLEAN, $4);
        }
    ;

constant_declaration:
    CUINT IDENTIFIER ASSIGN arithmetic_expression SEMICOLON
        {
            $$ = new ConstDeclarationNode($2, VarType::UINT, $4);
        }
    | CBOOLEAN IDENTIFIER ASSIGN logical_expression SEMICOLON
        {
            $$ = new ConstDeclarationNode($2, VarType::BOOLEAN, $4);
        }
    ;

array_declaration:
    ARRAY1DBOOL IDENTIFIER ASSIGN LBRACKET logical_expression_list RBRACKET SEMICOLON
        {
            $$ = new ArrayDeclarationNode($2, VarType::BOOLEAN, 1, $5);
        }
    | ARRAY2DBOOL IDENTIFIER ASSIGN LBRACKET logical_expression_matrix RBRACKET SEMICOLON
        {
            $$ = new ArrayDeclarationNode($2, VarType::BOOLEAN, 2, $5);
        }
    | ARRAY1DUINT IDENTIFIER ASSIGN LBRACKET arithmetic_expression_list RBRACKET SEMICOLON
        {
            $$ = new ArrayDeclarationNode($2, VarType::UINT, 1, $5);
        }
    | ARRAY2DUINT IDENTIFIER ASSIGN LBRACKET arithmetic_expression_matrix RBRACKET SEMICOLON
        {
            $$ = new ArrayDeclarationNode($2, VarType::UINT, 2, $5);
        }
    ;

array_extension:
    EXTEND1 IDENTIFIER arithmetic_expression SEMICOLON
        {
            $$ = new ArrayExtensionNode($2, 1, $3);
        }
    | EXTEND2 IDENTIFIER arithmetic_expression arithmetic_expression SEMICOLON
        {
            $$ = new ArrayExtensionNode($2, 2, $3, $4);
        }
    ;

assignment:
    IDENTIFIER ASSIGN expression SEMICOLON
        {
            $$ = new AssignmentNode($1, $3);
        }
    | array_access ASSIGN expression SEMICOLON
        {
            $$ = new ArrayAssignmentNode($1, $3);
        }
    ;

increment:
    INC IDENTIFIER SEMICOLON
        {
            $$ = new IncDecNode($2, 1);
        }
    ;

decrement:
    DEC IDENTIFIER SEMICOLON
        {
            $$ = new IncDecNode($2, -1);
        }
    ;

loop:
    WHILE LPAREN logical_expression RPAREN DO group_of_statements
        {
            $$ = new WhileNode($3, $6);
        }
    ;

conditional:
    IF LPAREN logical_expression RPAREN group_of_statements
        {
            $$ = new IfNode($3, $5);
        }
    | IF LPAREN logical_expression RPAREN group_of_statements ELSE group_of_statements
        {
            $$ = new IfNode($3, $5, $7);
        }
    ;

function_declaration:
    return_variables FUNCTION IDENTIFIER LPAREN parameters RPAREN group_of_statements
        {
            $$ = new FunctionDeclarationNode($3, $1, $5, $7);
        }
    ;

function_call:
    variables ASSIGN IDENTIFIER LPAREN expressions RPAREN SEMICOLON
        {
            $$ = new FunctionCallNode($3, $5, $1);
        }
    | IDENTIFIER LPAREN expressions RPAREN SEMICOLON
        {
            $$ = new FunctionCallNode($1, $3);
        }
    ;

robot_operation:
    movement_operator SEMICOLON
        {
            $$ = new RobotOperationNode($1);
        }
    | sensor_operator SEMICOLON
        {
            $$ = new RobotOperationNode($1);
        }
    ;

group_of_statements:
    LBRACE statements RBRACE
        {
            $$ = $2;
        }
    ;

statements:
    /* empty */
        {
            $$ = nullptr;
        }
    | statements statement
        {
            if ($1) {
                $1->addSibling($2);
                $$ = $1;
            } else {
                $$ = $2;
            }
        }
    ;

expression:
    arithmetic_expression
        { $$ = $1; }
    | logical_expression
        { $$ = $1; }
    ;

arithmetic_expression:
    arithmetic_expression PLUS arithmetic_expression
        {
            $$ = new ArithmeticOpNode('+', $1, $3);
        }
    | arithmetic_expression MINUS arithmetic_expression
        {
            $$ = new ArithmeticOpNode('-', $1, $3);
        }
    | arithmetic_expression MULTIPLY arithmetic_expression
        {
            $$ = new ArithmeticOpNode('*', $1, $3);
        }
    | arithmetic_expression DIVIDE arithmetic_expression
        {
            $$ = new ArithmeticOpNode('/', $1, $3);
        }
    | arithmetic_expression MODULO arithmetic_expression
        {
            $$ = new ArithmeticOpNode('%', $1, $3);
        }
    | LPAREN arithmetic_expression RPAREN
        {
            $$ = $2;
        }
    | UNSIGNED_INT
        {
            $$ = new IntNode($1);
        }
    | IDENTIFIER
        {
            $$ = new VariableNode($1);
        }
    | function_call
        {
            $$ = $1;
        }
    | array_access
        {
            $$ = $1;
        }
    ;

logical_expression:
    logical_expression OR logical_expression
        {
            $$ = new LogicalOpNode('O', $1, $3);
        }
    | NOT logical_expression
        {
            $$ = new LogicalOpNode('N', $2);
        }
    | comparison
        {
            $$ = $1;
        }
    | BOOL_CONST
        {
            $$ = new BoolNode($1);
        }
    | IDENTIFIER
        {
            $$ = new VariableNode($1);
        }
    | function_call
        {
            $$ = $1;
        }
    | array_access
        {
            $$ = $1;
        }
    ;

comparison:
    arithmetic_expression GT arithmetic_expression
        {
            $$ = new ComparisonNode('G', $1, $3);
        }
    | arithmetic_expression LT arithmetic_expression
        {
            $$ = new ComparisonNode('L', $1, $3);
        }
    ;

array_access:
    IDENTIFIER LPAREN arithmetic_expression_list RPAREN
        {
            $$ = new ArrayAccessNode($1, $3);
        }
    ;

arithmetic_expression_list:
    arithmetic_expression
        {
            $$ = new std::vector<ASTNode*>();
            $$->push_back($1);
        }
    | arithmetic_expression_list COMMA arithmetic_expression
        {
            $1->push_back($3);
            $$ = $1;
        }
    ;

logical_expression_list:
    logical_expression
        {
            $$ = new std::vector<ASTNode*>();
            $$->push_back($1);
        }
    | logical_expression_list COMMA logical_expression
        {
            $1->push_back($3);
            $$ = $1;
        }
    ;

logical_expression_matrix:
    logical_expression_list
        {
            $$ = new std::vector<ASTNode*>();
            $$->push_back(new MatrixRowNode($1));
        }
    | logical_expression_matrix SEMICOLON logical_expression_list
        {
            $1->push_back(new MatrixRowNode($3));
            $$ = $1;
        }
    ;

arithmetic_expression_matrix:
    arithmetic_expression_list
        {
            $$ = new std::vector<ASTNode*>();
            $$->push_back(new MatrixRowNode($1));
        }
    | arithmetic_expression_matrix SEMICOLON arithmetic_expression_list
        {
            $1->push_back(new MatrixRowNode($3));
            $$ = $1;
        }
    ;

return_variables:
    LBRACKET variables RBRACKET
        { $$ = $2; }
    | variables
        { $$ = $1; }
    ;

parameters:
    variables
        { $$ = $1; }
    | /* empty */
        { $$ = new std::vector<ASTNode*>(); }
    ;

variables:
    IDENTIFIER
        {
            $$ = new std::vector<ASTNode*>();
            $$->push_back(new VariableNode($1));
        }
    | variables COMMA IDENTIFIER
        {
            $1->push_back(new VariableNode($3));
            $$ = $1;
        }
    ;

expressions:
    expression
        {
            $$ = new std::vector<ASTNode*>();
            $$->push_back($1);
        }
    | expressions COMMA expression
        {
            $1->push_back($3);
            $$ = $1;
        }
    | /* empty */
        { $$ = new std::vector<ASTNode*>(); }
    ;

movement_operator:
    FORW
        { $$ = new MovementNode("FORW"); }
    | BACK
        { $$ = new MovementNode("BACK"); }
    | RIGHT_OP
        { $$ = new MovementNode("RIGHT"); }
    | LEFT_OP
        { $$ = new MovementNode("LEFT"); }
    ;

sensor_operator:
    GETF
        { $$ = new SensorNode("GETF"); }
    | GETB
        { $$ = new SensorNode("GETB"); }
    | GETR
        { $$ = new SensorNode("GETR"); }
    | GETL
        { $$ = new SensorNode("GETL"); }
    | PUSHF
        { $$ = new SensorNode("PUSHF"); }
    | PUSHB
        { $$ = new SensorNode("PUSHB"); }
    | PUSHR
        { $$ = new SensorNode("PUSHR"); }
    | PUSHL
        { $$ = new SensorNode("PUSHL"); }
    | UNDO
        { $$ = new SensorNode("UNDO"); }
    ;

%%

void yyerror(const char *s) {
    std::cerr << "Error: " << s << std::endl;
    exit(1);
}

%{
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "ast.h"
#include "symbol_table.h"

// Forward declarations
int yylex(ParserNS::ParserClass::semantic_type *yylval);
void yyerror(const std::string& message);

extern ASTNode *ast_root;
%}

%language "C++"

%define api.namespace {ParserNS}
%define api.parser.class {ParserClass}
%define api.value.type variant
%define api.token.constructor
%defines

%code requires {
    #include "ast.h"
    #include <vector>
    #include <string>
}

%token <int> UNSIGNED_INT
%token <bool> BOOL_CONST
%token <std::string> IDENTIFIER

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

%nonassoc ASSIGN
%nonassoc COMMA
%nonassoc RPAREN
%nonassoc LPAREN

%type <ASTNode*> program statement variable_declaration
%type <ASTNode*> constant_declaration array_declaration array_extension assignment
%type <ASTNode*> function_call increment decrement loop conditional function_declaration
%type <ASTNode*> robot_operation group_of_statements expression array_access movement_operator sensor_operator
%type <std::vector<ASTNode*>*> expressions variables return_variables parameters statements

%%

program:
    /* empty */
        {
            $$ = new BlockNode(new std::vector<ASTNode*>());
            ast_root = $$;
        }
    | program statement
        {
            static_cast<BlockNode*>($1)->addStatement($2);
            $$ = $1;
        }
    ;

statement:
    variable_declaration
    | constant_declaration
    | array_declaration
    | array_extension
    | assignment
    | function_call
    | increment
    | decrement
    | loop
    | conditional
    | function_declaration
    | robot_operation
    | group_of_statements
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

function_call:
    IDENTIFIER LPAREN expressions RPAREN SEMICOLON
        {
            $$ = new FunctionCallNode($1, $3);
        }
    ;

variable_declaration:
    UINT IDENTIFIER ASSIGN expression SEMICOLON
        {
            $$ = new VarDeclarationNode($2, VarType::UINT, $4);
        }
    | BOOLEAN IDENTIFIER ASSIGN expression SEMICOLON
        {
            $$ = new VarDeclarationNode($2, VarType::BOOLEAN, $4);
        }
    ;

constant_declaration:
    CUINT IDENTIFIER ASSIGN expression SEMICOLON
        {
            $$ = new ConstDeclarationNode($2, VarType::UINT, $4);
        }
    | CBOOLEAN IDENTIFIER ASSIGN expression SEMICOLON
        {
            $$ = new ConstDeclarationNode($2, VarType::BOOLEAN, $4);
        }
    ;

array_declaration:
    ARRAY1DBOOL IDENTIFIER ASSIGN LBRACKET expressions RBRACKET SEMICOLON
        {
            $$ = new ArrayDeclarationNode($2, VarType::BOOLEAN, 1, $5);
        }
    | ARRAY2DBOOL IDENTIFIER ASSIGN LBRACKET expressions RBRACKET SEMICOLON
        {
            $$ = new ArrayDeclarationNode($2, VarType::BOOLEAN, 2, $5);
        }
    | ARRAY1DUINT IDENTIFIER ASSIGN LBRACKET expressions RBRACKET SEMICOLON
        {
            $$ = new ArrayDeclarationNode($2, VarType::UINT, 1, $5);
        }
    | ARRAY2DUINT IDENTIFIER ASSIGN LBRACKET expressions RBRACKET SEMICOLON
        {
            $$ = new ArrayDeclarationNode($2, VarType::UINT, 2, $5);
        }
    ;

array_extension:
    EXTEND1 IDENTIFIER expression SEMICOLON
        {
            $$ = new ArrayExtensionNode($2, 1, $3, nullptr);
        }
    | EXTEND2 IDENTIFIER expression COMMA expression SEMICOLON
        {
            $$ = new ArrayExtensionNode($2, 2, $3, $5);
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
    WHILE LPAREN expression RPAREN DO group_of_statements
        {
            $$ = new WhileNode($3, $6);
        }
    ;

conditional:
    IF LPAREN expression RPAREN group_of_statements
        {
            $$ = new IfNode($3, $5);
        }
    | IF LPAREN expression RPAREN group_of_statements ELSE group_of_statements
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

robot_operation:
    movement_operator SEMICOLON
        { $$ = new RobotOperationNode($1); }
    | sensor_operator SEMICOLON
        { $$ = new RobotOperationNode($1); }
    ;

group_of_statements:
    LBRACE statements RBRACE
        {
            $$ = new BlockNode($2);
            delete $2; // Clean up the vector as it's now encapsulated within BlockNode
        }
    ;

statements:
    /* empty */
        {
            $$ = new std::vector<ASTNode*>();
        }
    | statements statement
        {
            $1->push_back($2);
            $$ = $1;
        }
    ;

expression:
    expression OR expression
        {
            $$ = new LogicalOpNode('O', $1, $3);
        }
    | NOT expression
        {
            $$ = new LogicalOpNode('N', $2, nullptr);
        }
    | expression GT expression
        {
            $$ = new ComparisonNode('G', $1, $3);
        }
    | expression LT expression
        {
            $$ = new ComparisonNode('L', $1, $3);
        }
    | expression PLUS expression
        {
            $$ = new ArithmeticOpNode('+', $1, $3);
        }
    | expression MINUS expression
        {
            $$ = new ArithmeticOpNode('-', $1, $3);
        }
    | expression MULTIPLY expression
        {
            $$ = new ArithmeticOpNode('*', $1, $3);
        }
    | expression DIVIDE expression
        {
            $$ = new ArithmeticOpNode('/', $1, $3);
        }
    | expression MODULO expression
        {
            $$ = new ArithmeticOpNode('%', $1, $3);
        }
    | LPAREN expression RPAREN
        {
            $$ = $2;
        }
    | UNSIGNED_INT
        {
            $$ = new IntNode($1);
        }
    | BOOL_CONST
        {
            $$ = new BoolNode($1);
        }
    | IDENTIFIER
        {
            $$ = new VariableNode($1);
        }
    | array_access
        {
            $$ = $1;
        }
    ;

array_access:
    IDENTIFIER LPAREN expressions RPAREN
        {
            $$ = new ArrayAccessNode($1, $3);
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

void yyerror(const std::string& message) {
    std::cerr << "Error: " << message << std::endl;
    exit(1);
}

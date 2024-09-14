%{
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "ast.h"
#include "symbol_table.h"

using namespace std;

// Declare yylex with the correct signature expected by Bison
int yylex(Parser::semantic_type *yylval, Parser::location_type &loc);

// Update yyerror to match Bison's expectations
void yyerror(Parser::context_type& context, const char *s);

extern ASTNode *ast_root;
%}

%skeleton "lalr1.cc"

%define api.namespace {Parser}
%define api.parser.class {Parser}

%code requires {
    #include "ast.h"
}

%union {
    int int_val;
    bool bool_val;
    char *id;
    ASTNode *node;
    std::vector<ASTNode*> *node_list;           // For lists of statements
    std::vector<VariableNode*> *var_list;       // For lists of variables
    std::vector<ASTNode*> *expr_list;           // For lists of expressions
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

%nonassoc ASSIGN
%nonassoc COMMA
%nonassoc RPAREN
%nonassoc LPAREN

%type <node> program statement variable_declaration
             constant_declaration array_declaration array_extension
             assignment increment
             decrement loop conditional function_declaration
             function_call robot_operation group_of_statements
             expression array_access movement_operator sensor_operator

%type <node_list> statements

%type <var_list> variables return_variables parameters

%type <expr_list> expressions

%%

program:
    /* empty */
        {
            $$ = new BlockNode(new std::vector<ASTNode*>());
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
            $$ = new AssignmentNode(std::string($1), $3);
        }
    | array_access ASSIGN expression SEMICOLON
        {
            $$ = new ArrayAssignmentNode($1, $3);
        }
    ;

function_call:
    IDENTIFIER LPAREN expressions RPAREN SEMICOLON
        {
            $$ = new FunctionCallNode(std::string($1), $3);
        }
    ;

variable_declaration:
    UINT IDENTIFIER ASSIGN expression SEMICOLON
        {
            $$ = new VarDeclarationNode(std::string($2), VarType::UINT, $4);
        }
    | BOOLEAN IDENTIFIER ASSIGN expression SEMICOLON
        {
            $$ = new VarDeclarationNode(std::string($2), VarType::BOOLEAN, $4);
        }
    ;

constant_declaration:
    CUINT IDENTIFIER ASSIGN expression SEMICOLON
        {
            $$ = new ConstDeclarationNode(std::string($2), VarType::UINT, $4);
        }
    | CBOOLEAN IDENTIFIER ASSIGN expression SEMICOLON
        {
            $$ = new ConstDeclarationNode(std::string($2), VarType::BOOLEAN, $4);
        }
    ;

array_declaration:
    ARRAY1DBOOL IDENTIFIER ASSIGN LBRACKET expressions RBRACKET SEMICOLON
        {
            $$ = new ArrayDeclarationNode(std::string($2), VarType::BOOLEAN, 1, $5);
        }
    | ARRAY2DBOOL IDENTIFIER ASSIGN LBRACKET expressions RBRACKET SEMICOLON
        {
            $$ = new ArrayDeclarationNode(std::string($2), VarType::BOOLEAN, 2, $5);
        }
    | ARRAY1DUINT IDENTIFIER ASSIGN LBRACKET expressions RBRACKET SEMICOLON
        {
            $$ = new ArrayDeclarationNode(std::string($2), VarType::UINT, 1, $5);
        }
    | ARRAY2DUINT IDENTIFIER ASSIGN LBRACKET expressions RBRACKET SEMICOLON
        {
            $$ = new ArrayDeclarationNode(std::string($2), VarType::UINT, 2, $5);
        }
    ;

array_extension:
    EXTEND1 IDENTIFIER expression SEMICOLON
        {
            $$ = new ArrayExtensionNode(std::string($2), 1, $3);
        }
    | EXTEND2 IDENTIFIER expression COMMA expression SEMICOLON
        {
            $$ = new ArrayExtensionNode(std::string($2), 2, $3, $5);
        }
    ;

increment:
    INC IDENTIFIER SEMICOLON
        {
            $$ = new IncDecNode(std::string($2), 1);
        }
    ;

decrement:
    DEC IDENTIFIER SEMICOLON
        {
            $$ = new IncDecNode(std::string($2), -1);
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
            $$ = new FunctionDeclarationNode(std::string($3), $1, $5, $7);
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
            delete $2;  // Clean up the vector as it's now encapsulated within BlockNode
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
            $$ = new LogicalOpNode('N', $2);
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
            $$ = new VariableNode(std::string($1));
        }
    | array_access
        {
            $$ = $1;
        }
    ;

array_access:
    IDENTIFIER LPAREN expressions RPAREN
        {
            $$ = new ArrayAccessNode(std::string($1), $3);
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
        { $$ = new std::vector<VariableNode*>(); }
    ;

variables:
    IDENTIFIER
        {
            $$ = new std::vector<VariableNode*>();
            $$->push_back(new VariableNode(std::string($1)));
        }
    | variables COMMA IDENTIFIER
        {
            $1->push_back(new VariableNode(std::string($3)));
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

void yyerror(Parser::context_type& context, const char *s) {
    std::cerr << "Error at " << context.location.begin.filename << ":"
              << context.location.begin.line << ":"
              << context.location.begin.column << " - " << s << std::endl;
    exit(1);
}
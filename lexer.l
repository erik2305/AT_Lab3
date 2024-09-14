%{
#include "parser.hpp"
#include "ast.h"
#include <cstring>
#include <cstdlib>

// Use the correct namespace
using namespace Parser;

// Define the yylex function signature as expected by Bison
#define YY_DECL int yylex(semantic_type * yylval, location_type &loc)
%}

%option noyywrap

%%

[0-9]+ {
    yylval->int_val = atoi(yytext);
    return UNSIGNED_INT;
}

"true" {
    yylval->bool_val = true;
    return BOOL_CONST;
}

"false" {
    yylval->bool_val = false;
    return BOOL_CONST;
}

"WHILE"       { return WHILE; }
"do"          { return DO; }
"if"          { return IF; }
"else"        { return ELSE; }
"function"    { return FUNCTION; }
"forw"        { return FORW; }
"back"        { return BACK; }
"right"       { return RIGHT_OP; }
"left"        { return LEFT_OP; }
"getf"        { return GETF; }
"getb"        { return GETB; }
"getr"        { return GETR; }
"getl"        { return GETL; }
"pushf"       { return PUSHF; }
"pushb"       { return PUSHB; }
"pushr"       { return PUSHR; }
"pushl"       { return PUSHL; }
"undo"        { return UNDO; }

[a-zA-Z_][a-zA-Z0-9_]* {
    yylval->id = strdup(yytext);
    return IDENTIFIER;
}

"1DARRAYOFBOOL"     { return ARRAY1DBOOL; }
"2DARRAYOFBOOL"     { return ARRAY2DBOOL; }
"1DARRAYOFUINT"     { return ARRAY1DUINT; }
"2DARRAYOFUINT"     { return ARRAY2DUINT; }

"=" { return ASSIGN; }
";" { return SEMICOLON; }
"," { return COMMA; }
"(" { return LPAREN; }
")" { return RPAREN; }
"[" { return LBRACKET; }
"]" { return RBRACKET; }
"{" { return LBRACE; }
"}" { return RBRACE; }
"+" { return PLUS; }
"-" { return MINUS; }
"*" { return MULTIPLY; }
"/" { return DIVIDE; }
"%" { return MODULO; }
"++" { return INC; }
"--" { return DEC; }
"!" { return NOT; }
"||" { return OR; }
">" { return GT; }
"<" { return LT; }

[ \t\r\n]+ ;  // Ignore whitespace

. {
    std::cerr << "Unknown character: " << yytext << std::endl;
    exit(1);
}

%%

int yylex(Parser::semantic_type * yylval, Parser::location_type &loc) {
    return yylex(yylval, loc);
}

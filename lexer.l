%{
#include "parser.hpp"
#include <iostream>
#include <cstdlib>
#include <cstring>

#undef yyFlexLexer
#define yyFlexLexer MazeFlexLexer
#include <FlexLexer.h>

using namespace std;

%}

%option noyywrap

DIGIT      [0-9]
LETTER     [a-zA-Z]
IDENTIFIER {LETTER}({LETTER}|{DIGIT})*

%%

"UINT"              { return UINT; }
"BOOLEAN"           { return BOOLEAN; }
"CUINT"             { return CUINT; }
"CBOOLEAN"          { return CBOOLEAN; }
"1DARRAYOFBOOL"     { return ARRAY1DBOOL; }
"2DARRAYOFBOOL"     { return ARRAY2DBOOL; }
"1DARRAYOFUINT"     { return ARRAY1DUINT; }
"2DARRAYOFUINT"     { return ARRAY2DUINT; }
"EXTEND1"           { return EXTEND1; }
"EXTEND2"           { return EXTEND2; }
"SIZE1"             { return SIZE1; }
"SIZE2"             { return SIZE2; }
"INC"               { return INC; }
"DEC"               { return DEC; }
"NOT"               { return NOT; }
"OR"                { return OR; }
"GT"                { return GT; }
"LT"                { return LT; }
"WHILE"             { return WHILE; }
"DO"                { return DO; }
"IF"                { return IF; }
"ELSE"              { return ELSE; }
"FUNCTION"          { return FUNCTION; }
"FORW"              { return FORW; }
"BACK"              { return BACK; }
"RIGHT"             { return RIGHT_OP; }
"LEFT"              { return LEFT_OP; }
"GETF"              { return GETF; }
"GETB"              { return GETB; }
"GETR"              { return GETR; }
"GETL"              { return GETL; }
"PUSHF"             { return PUSHF; }
"PUSHB"             { return PUSHB; }
"PUSHR"             { return PUSHR; }
"PUSHL"             { return PUSHL; }
"UNDO"              { return UNDO; }
"TRUE"              { yylval.bool_val = true; return BOOL_CONST; }
"FALSE"             { yylval.bool_val = false; return BOOL_CONST; }
{IDENTIFIER}        { yylval.id = strdup(yytext); return IDENTIFIER; }
{DIGIT}+            { yylval.int_val = atoi(yytext); return UNSIGNED_INT; }
"="                 { return ASSIGN; }
";"                 { return SEMICOLON; }
","                 { return COMMA; }
"("                 { return LPAREN; }
")"                 { return RPAREN; }
"["                 { return LBRACKET; }
"]"                 { return RBRACKET; }
"{"                 { return LBRACE; }
"}"                 { return RBRACE; }
"+"                 { return PLUS; }
"-"                 { return MINUS; }
"*"                 { return MULTIPLY; }
"/"                 { return DIVIDE; }
"%"                 { return MODULO; }
"//".*              { /* skip single-line comments */ }
[ \t\r\n]+          { /* skip whitespace */ }

.                   { std::cerr << "Unknown character: " << yytext << std::endl; exit(1); }

%%

int yyFlexLexer::yywrap() {
    return 1;
}

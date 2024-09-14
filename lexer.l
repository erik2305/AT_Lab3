%{
#include "parser.hpp" // Ensure this matches the Bison-generated header
#include <FlexLexer.h>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdio.h> // For fileno()

using namespace ParserNS;

// Define the Lexer class
class Lexer : public yyFlexLexer {
public:
    Lexer(std::istream* in = &std::cin, std::ostream* out = &std::cout)
        : yyFlexLexer(in, out) {}

    int yylex(ParserClass::semantic_type* yylval);
};

#define YY_DECL int Lexer::yylex(ParserClass::semantic_type* yylval)

%}

%option noyywrap c++

%%

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

"1DARRAYOFBOOL"     { return ARRAY1DBOOL; }
"2DARRAYOFBOOL"     { return ARRAY2DBOOL; }
"1DARRAYOFUINT"     { return ARRAY1DUINT; }
"2DARRAYOFUINT"     { return ARRAY2DUINT; }

"++" { return INC; }
"--" { return DEC; }
"||" { return OR; }

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
"!" { return NOT; }
">" { return GT; }
"<" { return LT; }

"true"       { *yylval = true; return BOOL_CONST; }
"false"      { *yylval = false; return BOOL_CONST; }

[0-9]+       { *yylval = std::stoi(yytext); return UNSIGNED_INT; }

[a-zA-Z_][a-zA-Z0-9_]* { 
                *yylval = std::string(yytext); 
                return IDENTIFIER; 
            }

[ \t\r\n]+   ; // Ignore whitespace

. {
    std::cerr << "Unknown character: " << yytext << std::endl;
    exit(1);
}

%%

int Lexer::yylex(ParserClass::semantic_type* yylval) {
    return yylex(yylval);
}

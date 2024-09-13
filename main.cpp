#include <iostream>
#include "ast.h"

extern int yyparse();
extern ASTNode *ast_root;

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <source_file>" << std::endl;
        return 1;
    }

    // Open the source file
    FILE *source = fopen(argv[1], "r");
    if (!source) {
        perror("fopen");
        return 1;
    }

    // Set the input file for the lexer
    extern FILE *yyin;
    yyin = source;

    // Parse the source code
    if (yyparse() == 0) {
        // Successfully parsed
        // Interpret the AST
        interpret(ast_root);
    } else {
        std::cerr << "Parsing failed." << std::endl;
    }

    fclose(source);
    return 0;
}

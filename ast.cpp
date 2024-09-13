#include "ast.h"
#include <iostream>

void VarDeclarationNode::interpret() {
    // Interpret the expression to get the value
    // Then add the variable to the symbol table
    expression->interpret();
    // Assuming expression evaluates to a value stored somewhere
    // Add variable to symbol table
    SymbolTable::getInstance().addVariable(id, varType, false);
}

// Implement other interpret methods...

void interpret(ASTNode *node) {
    if (!node) return;
    node->interpret();
    interpret(node->sibling);
}
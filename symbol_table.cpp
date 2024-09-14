#include "symbol_table.h"
#include <iostream>
#include <cstdlib>

// Destructor to clean up allocated Variables
SymbolTable::~SymbolTable() {
    for (auto &pair : table) {
        delete pair.second;
    }
}

// Variable Management
void SymbolTable::addVariable(const std::string &name, VarType type, bool isConstant) {
    if (table.find(name) != table.end()) {
        std::cerr << "Variable " << name << " already declared." << std::endl;
        exit(1);
    }
    table[name] = new Variable(type, isConstant);
}

Variable* SymbolTable::getVariable(const std::string &name) {
    auto it = table.find(name);
    if (it != table.end()) {
        return it->second;
    }
    std::cerr << "Variable " << name << " not found." << std::endl;
    exit(1);
    return nullptr;
}

void SymbolTable::assignVariable(const std::string &name, ASTNode *expr) {
    Variable* var = getVariable(name);
    if (var->isConstant) {
        std::cerr << "Cannot assign to constant variable " << name << "." << std::endl;
        exit(1);
    }
    
    // Assuming expr is an IntNode or BoolNode
    if (var->type == VarType::UINT) {
        IntNode* intNode = dynamic_cast<IntNode*>(expr);
        if (!intNode) {
            std::cerr << "Type mismatch: Expected UINT for variable " << name << "." << std::endl;
            exit(1);
        }
        var->intValue = intNode->value;
    }
    else if (var->type == VarType::BOOLEAN) {
        BoolNode* boolNode = dynamic_cast<BoolNode*>(expr);
        if (!boolNode) {
            std::cerr << "Type mismatch: Expected BOOLEAN for variable " << name << "." << std::endl;
            exit(1);
        }
        var->boolValue = boolNode->value;
    }
}

int SymbolTable::getVariableValue(const std::string &name) {
    Variable* var = getVariable(name);
    if (var->type != VarType::UINT) {
        std::cerr << "Type mismatch: Variable " << name << " is not of type UINT." << std::endl;
        exit(1);
    }
    return var->intValue;
}

bool SymbolTable::getBooleanValue(ASTNode *expr) {
    // Assuming expr is a BoolNode or VariableNode
    if (expr->type == NodeType::BoolLiteral) {
        BoolNode* boolNode = dynamic_cast<BoolNode*>(expr);
        return boolNode->value;
    }
    else if (expr->type == NodeType::Variable) {
        VariableNode* varNode = dynamic_cast<VariableNode*>(expr);
        Variable* var = getVariable(varNode->getName());
        if (var->type != VarType::BOOLEAN) {
            std::cerr << "Type mismatch: Variable " << varNode->getName() << " is not of type BOOLEAN." << std::endl;
            exit(1);
        }
        return var->boolValue;
    }
    else {
        std::cerr << "Unsupported expression type for boolean evaluation." << std::endl;
        exit(1);
    }
}

// Array Management (Stub Implementations)
void SymbolTable::addArray(const std::string &name, VarType type, int dimensions) {
    // Implement array addition logic
    std::cout << "Array '" << name << "' added with " << dimensions << " dimensions." << std::endl;
}

void SymbolTable::extendArray(const std::string &name, int dimensions) {
    // Implement array extension logic
    std::cout << "Array '" << name << "' extended to " << dimensions << " dimensions." << std::endl;
}

void SymbolTable::assignArrayElement(ASTNode *arrayAccess, ASTNode *expr) {
    // Implement array element assignment logic
    std::cout << "Array element assigned." << std::endl;
}

// Function Management (Stub Implementations)
void SymbolTable::addFunction(const std::string &name, std::vector<ASTNode*> *returnVars, std::vector<ASTNode*> *parameters, ASTNode *body) {
    // Implement function addition logic
    std::cout << "Function '" << name << "' added." << std::endl;
}

void SymbolTable::callFunction(const std::string &name, std::vector<ASTNode*> *arguments) {
    // Implement function call logic
    std::cout << "Function '" << name << "' called." << std::endl;
}
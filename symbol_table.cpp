#include "symbol_table.h"
#include <iostream>

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
    return nullptr;
}

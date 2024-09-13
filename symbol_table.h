#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <string>
#include <unordered_map>

enum class VarType {
    UINT,
    BOOLEAN,
    // Add array types if necessary
};

class Variable {
public:
    VarType type;
    bool isConstant;
    int intValue;
    bool boolValue;
    // Add fields for arrays and other types

    Variable(VarType type, bool isConst) : type(type), isConstant(isConst) {}
};

class SymbolTable {
private:
    std::unordered_map<std::string, Variable*> table;
    SymbolTable() {}
    SymbolTable(const SymbolTable&) = delete;
    SymbolTable& operator=(const SymbolTable&) = delete;

public:
    static SymbolTable& getInstance() {
        static SymbolTable instance;
        return instance;
    }

    void addVariable(const std::string &name, VarType type, bool isConstant);
    Variable* getVariable(const std::string &name);
};

#endif // SYMBOL_TABLE_H

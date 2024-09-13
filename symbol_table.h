#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <string>
#include <unordered_map>
#include <vector>
#include "ast.h"

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

    Variable(VarType type, bool isConst) : type(type), isConstant(isConst), intValue(0), boolValue(false) {}
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

    // Variable Management
    void addVariable(const std::string &name, VarType type, bool isConstant);
    Variable* getVariable(const std::string &name);
    void assignVariable(const std::string &name, ASTNode *expr);
    int getVariableValue(const std::string &name);
    bool getBooleanValue(ASTNode *expr);

    // Array Management
    void addArray(const std::string &name, VarType type, int dimensions);
    void extendArray(const std::string &name, int dimensions);
    void assignArrayElement(ASTNode *arrayAccess, ASTNode *expr);

    // Function Management
    void addFunction(const std::string &name, std::vector<ASTNode*> *returnVars, std::vector<ASTNode*> *parameters, ASTNode *body);
    void callFunction(const std::string &name, std::vector<ASTNode*> *arguments);

    // Destructor to clean up allocated Variables
    ~SymbolTable();
};

#endif // SYMBOL_TABLE_H

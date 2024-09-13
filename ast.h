#ifndef AST_H
#define AST_H

#include <vector>
#include <string>
#include "symbol_table.h"

enum class NodeType {
    Program,
    VarDeclaration,
    ConstDeclaration,
    ArrayDeclaration,
    ArrayExtension,
    Assignment,
    ArrayAssignment,
    IncDec,
    WhileLoop,
    IfStatement,
    FunctionDeclaration,
    FunctionCall,
    RobotOperation,
    ArithmeticOp,
    LogicalOp,
    Comparison,
    IntLiteral,
    BoolLiteral,
    Variable,
    ArrayAccess,
    StatementList,
    ExpressionList,
    VariableList,
    MatrixRow,
    Movement,
    Sensor
};

class ASTNode {
public:
    NodeType type;
    ASTNode *sibling;

    ASTNode(NodeType type) : type(type), sibling(nullptr) {}
    virtual ~ASTNode() {}
    void addSibling(ASTNode *node) {
        if (!sibling) sibling = node;
        else sibling->addSibling(node);
    }

    virtual void interpret() = 0;
};

class VarDeclarationNode : public ASTNode {
public:
    std::string id;
    VarType varType;
    ASTNode *expression;

    VarDeclarationNode(const std::string &id, VarType type, ASTNode *expr)
        : ASTNode(NodeType::VarDeclaration), id(id), varType(type), expression(expr) {}

    void interpret() override;
};

// Define other ASTNode derived classes similarly...

// Function to interpret the AST
void interpret(ASTNode *node);

#endif // AST_H

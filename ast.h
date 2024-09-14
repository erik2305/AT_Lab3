#ifndef AST_H
#define AST_H

#include <vector>
#include <string>
#include "types.h"

class SymbolTable;

// Base class for all AST Nodes
class ASTNode {
public:
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
    ASTNode *sibling;

    ASTNode(NodeType type) : type(type) {}
    virtual ~ASTNode() {}
    
    void addSibling(ASTNode *node) {
        if (!sibling) sibling = node;
        else sibling->addSibling(node);
    }

    virtual int evaluateInt() { return 0; } // Default implementation
    virtual bool evaluateBool() { return false; } // Default implementation
    virtual void interpret() = 0;  // Pure virtual function to interpret the AST
    NodeType getType() const { return type; }
private:
    NodeType type;
};

// Variable Declaration Node
class VarDeclarationNode : public ASTNode {
public:
    std::string id;
    VarType varType;
    ASTNode *expression;

    VarDeclarationNode(const std::string &id, VarType type, ASTNode *expr)
        : ASTNode(NodeType::VarDeclaration), id(id), varType(type), expression(expr) {}

    void interpret() override;
};

// Constant Declaration Node
class ConstDeclarationNode : public ASTNode {
public:
    std::string id;
    VarType constType;
    ASTNode *expression;

    ConstDeclarationNode(const std::string &id, VarType type, ASTNode *expr)
        : ASTNode(NodeType::ConstDeclaration), id(id), constType(type), expression(expr) {}

    void interpret() override;
};

// Array Declaration Node
class ArrayDeclarationNode : public ASTNode {
public:
    std::string id;
    VarType arrayType;
    int dimensions;
    std::vector<ASTNode*> *elements;

    ArrayDeclarationNode(const std::string &id, VarType type, int dims, std::vector<ASTNode*> *elems)
        : ASTNode(NodeType::ArrayDeclaration), id(id), arrayType(type), dimensions(dims), elements(elems) {}

    void interpret() override;
};

// Array Extension Node
class ArrayExtensionNode : public ASTNode {
public:
    std::string id;
    int dimensions;
    ASTNode *size1;
    ASTNode *size2;  // For 2D arrays, nullptr for 1D

    // Constructor for 1D array extension
    ArrayExtensionNode(const std::string &id, int dims, ASTNode *size1)
        : ASTNode(NodeType::ArrayExtension), id(id), dimensions(dims), size1(size1), size2(nullptr) {}

    // Constructor for 2D array extension
    ArrayExtensionNode(const std::string &id, int dims, ASTNode *size1, ASTNode *size2)
        : ASTNode(NodeType::ArrayExtension), id(id), dimensions(dims), size1(size1), size2(size2) {}

    void interpret() override;
};

// Assignment Node
class AssignmentNode : public ASTNode {
public:
    std::string id;
    ASTNode *expression;

    AssignmentNode(const std::string &id, ASTNode *expr)
        : ASTNode(NodeType::Assignment), id(id), expression(expr) {}

    void interpret() override;
};

// Array Assignment Node
class ArrayAssignmentNode : public ASTNode {
public:
    ASTNode *arrayAccess;
    ASTNode *expression;

    ArrayAssignmentNode(ASTNode *arrayAccess, ASTNode *expr)
        : ASTNode(NodeType::ArrayAssignment), arrayAccess(arrayAccess), expression(expr) {}

    void interpret() override;
};

// Increment/Decrement Node
class IncDecNode : public ASTNode {
public:
    std::string id;
    int incrementValue;  // +1 for increment, -1 for decrement

    IncDecNode(const std::string &id, int incValue)
        : ASTNode(NodeType::IncDec), id(id), incrementValue(incValue) {}

    void interpret() override;
};

// While Loop Node
class WhileNode : public ASTNode {
public:
    ASTNode *condition;
    ASTNode *body;

    WhileNode(ASTNode *cond, ASTNode *body)
        : ASTNode(NodeType::WhileLoop), condition(cond), body(body) {}

    void interpret() override;
};

// If Statement Node
class IfNode : public ASTNode {
public:
    ASTNode *condition;
    ASTNode *thenBody;
    ASTNode *elseBody;

    IfNode(ASTNode *cond, ASTNode *thenBody)
        : ASTNode(NodeType::IfStatement), condition(cond), thenBody(thenBody), elseBody(nullptr) {}

    IfNode(ASTNode *cond, ASTNode *thenBody, ASTNode *elseBody)
        : ASTNode(NodeType::IfStatement), condition(cond), thenBody(thenBody), elseBody(elseBody) {}

    void interpret() override;
};

// Function Declaration Node
class FunctionDeclarationNode : public ASTNode {
public:
    FunctionDeclarationNode(const std::string &id, std::vector<ASTNode*> *returnVars,
                            std::vector<ASTNode*> *params, ASTNode *body)
        : ASTNode(NodeType::FunctionDeclaration), id(id), returnVars(returnVars), params(params), body(body) {}

    void interpret() override;

private:
    std::string id;
    std::vector<ASTNode*> *returnVars;
    std::vector<ASTNode*> *params;
    ASTNode *body;
};

// Function Call Node
class FunctionCallNode : public ASTNode {
public:
    std::string id;
    std::vector<ASTNode*> *arguments;
    std::vector<ASTNode*> *returnVars;

    // Constructor for function call without return variables
    FunctionCallNode(const std::string &id, std::vector<ASTNode*> *args)
        : ASTNode(NodeType::FunctionCall), id(id), arguments(args), returnVars(nullptr) {}

    // Constructor for function call with return variables
    FunctionCallNode(const std::string &id, std::vector<ASTNode*> *args, std::vector<ASTNode*> *retVars)
        : ASTNode(NodeType::FunctionCall), id(id), arguments(args), returnVars(retVars) {}

    void interpret() override;
};

// Robot Operation Node
class RobotOperationNode : public ASTNode {
public:
    ASTNode *operationNode;  // Holds a MovementNode or SensorNode

    RobotOperationNode(ASTNode *opNode)
        : ASTNode(NodeType::RobotOperation), operationNode(opNode) {}

    void interpret() override;
};

// Movement Node
class MovementNode : public ASTNode {
public:
    std::string movementAction;

    MovementNode(const std::string &action)
        : ASTNode(NodeType::Movement), movementAction(action) {}

    void interpret() override;
};

// Sensor Node
class SensorNode : public ASTNode {
public:
    std::string sensorAction;

    SensorNode(const std::string &action)
        : ASTNode(NodeType::Sensor), sensorAction(action) {}

    void interpret() override;
};

// Arithmetic Operation Node
class ArithmeticOpNode : public ASTNode {
public:
    char operation;
    ASTNode *left;
    ASTNode *right;

    ArithmeticOpNode(char op, ASTNode *left, ASTNode *right)
        : ASTNode(NodeType::ArithmeticOp), operation(op), left(left), right(right) {}

    void interpret() override;
    int evaluateInt() override {
        int leftVal = left->evaluateInt();
        int rightVal = right->evaluateInt();
        switch (operation) {
            case '+': return leftVal + rightVal;
            case '-': return leftVal - rightVal;
            case '*': return leftVal * rightVal;
            case '/': return leftVal / rightVal; // Add division by zero check
            case '%': return leftVal % rightVal; // Add modulo by zero check
        }
        return 0; // Default case
    }
};

// Logical Operation Node
class LogicalOpNode : public ASTNode {
public:
    char operation;
    ASTNode *left;
    ASTNode *right;  // nullptr for unary operations like NOT

    // Constructor for binary operations (e.g., OR)
    LogicalOpNode(char op, ASTNode *left, ASTNode *right)
        : ASTNode(NodeType::LogicalOp), operation(op), left(left), right(right) {}

    // Constructor for unary operations (e.g., NOT)
    LogicalOpNode(char op, ASTNode *operand)
        : ASTNode(NodeType::LogicalOp), operation(op), left(operand), right(nullptr) {}

    void interpret() override;
};

// Comparison Node
class ComparisonNode : public ASTNode {
public:
    char operation;
    ASTNode *left;
    ASTNode *right;

    ComparisonNode(char op, ASTNode *left, ASTNode *right)
        : ASTNode(NodeType::Comparison), operation(op), left(left), right(right) {}

    void interpret() override;
};

// Int Literal Node
class IntNode : public ASTNode {
public:
    int value;

    IntNode(int val)
        : ASTNode(NodeType::IntLiteral), value(val) {}

    void interpret() override;
    int evaluateInt() override { return value; }
};

// Bool Literal Node
class BoolNode : public ASTNode {
public:
    bool value;

    BoolNode(bool val)
        : ASTNode(NodeType::BoolLiteral), value(val) {}

    void interpret() override;
    bool evaluateBool() override { return value; }
};

class VariableNode : public ASTNode {
public:
    VariableNode(const std::string &name)
        : ASTNode(NodeType::Variable), name(name) {}
    
    void interpret() override;
    
    const std::string& getName() const { return name; }

private:
    std::string name;
};

// Array Access Node
class ArrayAccessNode : public ASTNode {
public:
    std::string id;
    std::vector<ASTNode*> *indices;

    ArrayAccessNode(const std::string &id, std::vector<ASTNode*> *indices)
        : ASTNode(NodeType::ArrayAccess), id(id), indices(indices) {}

    void interpret() override;
};

class BlockNode : public ASTNode {
public:
    BlockNode(std::vector<ASTNode*> *stmts)
        : ASTNode(NodeType::StatementList), statements(*stmts) {}
    void interpret() override;
    void addStatement(ASTNode* stmt);

private:
    std::vector<ASTNode*> statements;
};

class MatrixRowNode : public ASTNode {
public:
    std::vector<ASTNode*> elements;

    MatrixRowNode(std::vector<ASTNode*>* elems)
        : ASTNode(NodeType::MatrixRow), elements(*elems) {}

    void interpret() override {
        // Interpretation logic for a matrix row
    }
};


// Generic interpretation function for traversing the AST
void interpret(ASTNode *node);

#endif // AST_H
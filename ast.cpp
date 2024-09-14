#include "ast.h"
#include "symbol_table.h"
#include <iostream>

// VarDeclarationNode interpretation
void VarDeclarationNode::interpret() {
    // Interpret the expression to get the value
    expression->interpret();

    // Add variable to the symbol table
    SymbolTable::getInstance().addVariable(id, varType, false);

    std::cout << "Variable '" << id << "' declared of type " 
              << (varType == VarType::UINT ? "UINT" : "BOOLEAN") << "." << std::endl;
}

// ConstDeclarationNode interpretation
void ConstDeclarationNode::interpret() {
    // Interpret the expression to get the constant value
    expression->interpret();

    // Add constant to the symbol table
    SymbolTable::getInstance().addVariable(id, constType, true);

    std::cout << "Constant '" << id << "' declared of type " 
              << (constType == VarType::UINT ? "UINT" : "BOOLEAN") << "." << std::endl;
}

// ArrayDeclarationNode interpretation
void ArrayDeclarationNode::interpret() {
    // Interpret all elements in the array
    for (ASTNode* element : *elements) {
        element->interpret();
    }

    // Add array to the symbol table
    SymbolTable::getInstance().addArray(id, arrayType, dimensions);

    std::cout << "Array '" << id << "' declared with " << dimensions << " dimensions." << std::endl;
}

// ArrayExtensionNode interpretation
void ArrayExtensionNode::interpret() {
    // Interpret size extensions
    size1->interpret();
    if (size2) size2->interpret();

    // Extend the array in the symbol table
    SymbolTable::getInstance().extendArray(id, dimensions);

    std::cout << "Array '" << id << "' extended to " << dimensions << " dimensions." << std::endl;
}

// AssignmentNode interpretation
void AssignmentNode::interpret() {
    // Interpret the expression to get the value to assign
    expression->interpret();

    // Assign the value in the symbol table
    SymbolTable::getInstance().assignVariable(id, expression);

    std::cout << "Variable '" << id << "' assigned a new value." << std::endl;
}

// ArrayAssignmentNode interpretation
void ArrayAssignmentNode::interpret() {
    // Interpret the array access to determine which element to assign to
    arrayAccess->interpret();

    // Interpret the expression to get the value
    expression->interpret();

    // Assign the value to the array in the symbol table
    SymbolTable::getInstance().assignArrayElement(arrayAccess, expression);

    std::cout << "Array element assigned a new value." << std::endl;
}

// IncDecNode interpretation (Increment/Decrement)
void IncDecNode::interpret() {
    // Retrieve the current value from the symbol table
    int currentValue = SymbolTable::getInstance().getVariableValue(id);

    // Increment or decrement the value
    if (incrementValue == 1) {
        currentValue++;
        std::cout << "Variable '" << id << "' incremented to " << currentValue << "." << std::endl;
    } else {
        currentValue--;
        std::cout << "Variable '" << id << "' decremented to " << currentValue << "." << std::endl;
    }

    // Update the variable's value in the symbol table
    // Create a new IntNode with the updated value
    IntNode updatedValue(currentValue);
    SymbolTable::getInstance().assignVariable(id, &updatedValue);
}

// WhileNode interpretation (While loop)
void WhileNode::interpret() {
    while (true) {
        condition->interpret();
        bool conditionResult = SymbolTable::getInstance().getBooleanValue(condition);

        if (!conditionResult) break;

        body->interpret();
    }
    std::cout << "While loop executed." << std::endl;
}

// IfNode interpretation (If-else statement)
void IfNode::interpret() {
    condition->interpret();
    bool conditionResult = SymbolTable::getInstance().getBooleanValue(condition);

    if (conditionResult) {
        thenBody->interpret();
        std::cout << "If condition true, then branch executed." << std::endl;
    } else if (elseBody) {
        elseBody->interpret();
        std::cout << "If condition false, else branch executed." << std::endl;
    }
}

// FunctionDeclarationNode interpretation
void FunctionDeclarationNode::interpret() {
    // Add the function to the symbol table
    SymbolTable::getInstance().addFunction(id, returnVars, parameters, body);
    std::cout << "Function '" << id << "' declared." << std::endl;
}

// FunctionCallNode interpretation
void FunctionCallNode::interpret() {
    // Call the function
    SymbolTable::getInstance().callFunction(id, arguments);
    std::cout << "Function '" << id << "' called." << std::endl;
}

// RobotOperationNode interpretation
void RobotOperationNode::interpret() {
    // Interpret the contained operation node (MovementNode or SensorNode)
    operationNode->interpret();
}

// MovementNode interpretation
void MovementNode::interpret() {
    // Execute movement action
    std::cout << "Executing Movement Action: " << movementAction << std::endl;
    // Add actual robot movement logic here
}

// SensorNode interpretation
void SensorNode::interpret() {
    // Execute sensor action
    std::cout << "Executing Sensor Action: " << sensorAction << std::endl;
    // Add actual sensor logic here
}

// ArithmeticOpNode interpretation (Binary arithmetic operations)
void ArithmeticOpNode::interpret() {
    left->interpret();
    right->interpret();
    int leftValue = SymbolTable::getInstance().getVariableValue(dynamic_cast<VariableNode*>(left)->id);
    int rightValue = SymbolTable::getInstance().getVariableValue(dynamic_cast<VariableNode*>(right)->id);
    int result = 0;

    switch (operation) {
        case '+': result = leftValue + rightValue; break;
        case '-': result = leftValue - rightValue; break;
        case '*': result = leftValue * rightValue; break;
        case '/': 
            if (rightValue == 0) {
                std::cerr << "Division by zero error." << std::endl;
                exit(1);
            }
            result = leftValue / rightValue; break;
        case '%': 
            if (rightValue == 0) {
                std::cerr << "Modulo by zero error." << std::endl;
                exit(1);
            }
            result = leftValue % rightValue; break;
    }

    std::cout << "Arithmetic operation: " << leftValue << " " << operation << " " << rightValue << " = " << result << std::endl;

    // Optionally, store the result somewhere or assign it to a variable
}

// LogicalOpNode interpretation (Binary and Unary logical operations)
void LogicalOpNode::interpret() {
    if (operation == 'N') {  // NOT operation (Unary)
        left->interpret();
        bool operand = SymbolTable::getInstance().getBooleanValue(left);
        bool result = !operand;
        std::cout << "Logical NOT operation: !" << operand << " = " << result << std::endl;
    }
    else {  // Binary operations like OR
        left->interpret();
        right->interpret();
        bool leftValue = SymbolTable::getInstance().getBooleanValue(left);
        bool rightValue = SymbolTable::getInstance().getBooleanValue(right);
        bool result = false;

        if (operation == 'O') {  // OR operation
            result = leftValue || rightValue;
            std::cout << "Logical OR operation: " << leftValue << " || " << rightValue << " = " << result << std::endl;
        }
        // Add other logical operations like AND if needed
    }

    // Optionally, store the result somewhere or use it in control structures
}

// ComparisonNode interpretation (Comparison operations)
void ComparisonNode::interpret() {
    // Interpret both sides of the comparison
    left->interpret();
    right->interpret();
    int leftValue = SymbolTable::getInstance().getVariableValue(dynamic_cast<VariableNode*>(left)->id);
    int rightValue = SymbolTable::getInstance().getVariableValue(dynamic_cast<VariableNode*>(right)->id);
    bool result = false;

    if (operation == 'G') {
        result = (leftValue > rightValue);
        std::cout << "Comparison: " << leftValue << " > " << rightValue << " = " << result << std::endl;
    }
    else if (operation == 'L') {
        result = (leftValue < rightValue);
        std::cout << "Comparison: " << leftValue << " < " << rightValue << " = " << result << std::endl;
    }

    // Optionally, store the result somewhere or use it in control structures
}

// IntNode interpretation
void IntNode::interpret() {
    // Int literal is already a value, no interpretation needed
    std::cout << "Integer Literal: " << value << std::endl;
}

// BoolNode interpretation
void BoolNode::interpret() {
    // Bool literal is already a value, no interpretation needed
    std::cout << "Boolean Literal: " << (value ? "true" : "false") << std::endl;
}

// VariableNode interpretation
void VariableNode::interpret() {
    // Retrieve the value of the variable from the symbol table
    Variable* var = SymbolTable::getInstance().getVariable(id);
    if (var->type == VarType::UINT) {
        std::cout << "Variable '" << id << "' has value: " << var->intValue << std::endl;
    }
    else if (var->type == VarType::BOOLEAN) {
        std::cout << "Variable '" << id << "' has value: " << (var->boolValue ? "true" : "false") << std::endl;
    }
}

// ArrayAccessNode interpretation
void ArrayAccessNode::interpret() {
    // Interpret each index to get the array element
    for (ASTNode* index : *indices) {
        index->interpret();
    }
    std::cout << "Accessing array '" << id << "'." << std::endl;

    // Implement actual array access logic based on indices
}

// Generic interpretation function for traversing the AST
void interpret(ASTNode *node) {
    if (!node) return;
    node->interpret();
    interpret(node->sibling);  // Interpret sibling nodes in sequence
}

void BlockNode::interpret() {
    for (auto stmt : statements) {
        stmt->interpret();
    }
}

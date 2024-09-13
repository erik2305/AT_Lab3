#include "ast.h"
#include <iostream>

// VarDeclarationNode interpretation
void VarDeclarationNode::interpret() {
    // Interpret the expression to get the value (recursive interpretation)
    expression->interpret();

    // Add the variable to the symbol table, assuming expression evaluates to a value
    SymbolTable::getInstance().addVariable(id, varType, false);

    std::cout << "Variable '" << id << "' declared of type " << (varType == VarType::UINT ? "UINT" : "BOOLEAN") << std::endl;
}

// ConstDeclarationNode interpretation
void ConstDeclarationNode::interpret() {
    // Interpret the expression to get the constant value
    expression->interpret();

    // Add constant to the symbol table
    SymbolTable::getInstance().addVariable(id, constType, true);

    std::cout << "Constant '" << id << "' declared of type " << (constType == VarType::UINT ? "UINT" : "BOOLEAN") << std::endl;
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

    std::cout << "Variable '" << id << "' assigned a value." << std::endl;
}

// ArrayAssignmentNode interpretation
void ArrayAssignmentNode::interpret() {
    // Interpret the expression to get the value
    expression->interpret();
    // Interpret the array access to determine which element to assign to
    arrayAccess->interpret();

    // Assign the value to the array in the symbol table
    SymbolTable::getInstance().assignArrayElement(arrayAccess, expression);

    std::cout << "Array element assigned a value." << std::endl;
}

// IncDecNode interpretation (Increment/Decrement)
void IncDecNode::interpret() {
    // Retrieve the current value from the symbol table
    int currentValue = SymbolTable::getInstance().getVariableValue(id);

    // Increment or decrement the value
    if (incrementValue == 1) {
        currentValue++;
        std::cout << "Variable '" << id << "' incremented." << std::endl;
    } else {
        currentValue--;
        std::cout << "Variable '" << id << "' decremented." << std::endl;
    }

    // Update the variable's value in the symbol table
    SymbolTable::getInstance().assignVariable(id, new IntNode(currentValue));
}

// WhileNode interpretation (While loop)
void WhileNode::interpret() {
    // While loop with interpreted condition
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
    } else if (elseBody) {
        elseBody->interpret();
    }
    std::cout << "If statement executed." << std::endl;
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
    // Interpret the contained operation node
    operationNode->interpret();

    // Depending on the type of operationNode, perform specific actions
    if (operationNode->type == NodeType::Movement) {
        MovementNode *movNode = dynamic_cast<MovementNode*>(operationNode);
        if (movNode) {
            // Execute movement action
            std::cout << "Executing Movement: " << movNode->movementAction << std::endl;
            // Add actual robot movement logic here
        }
    }
    else if (operationNode->type == NodeType::Sensor) {
        SensorNode *senNode = dynamic_cast<SensorNode*>(operationNode);
        if (senNode) {
            // Execute sensor action
            std::cout << "Executing Sensor Action: " << senNode->sensorAction << std::endl;
            // Add actual sensor logic here
        }
    }
}


// MovementNode interpretation
void MovementNode::interpret() {
    std::cout << "Movement operation '" << movementAction << "' executed." << std::endl;
}

// SensorNode interpretation
void SensorNode::interpret() {
    std::cout << "Sensor operation '" << sensorAction << "' executed." << std::endl;
}

// ArithmeticOpNode interpretation (Binary arithmetic operations)
void ArithmeticOpNode::interpret() {
    left->interpret();
    right->interpret();
    int leftValue = SymbolTable::getInstance().getIntValue(left);
    int rightValue = SymbolTable::getInstance().getIntValue(right);
    int result = 0;

    switch (operation) {
        case '+': result = leftValue + rightValue; break;
        case '-': result = leftValue - rightValue; break;
        case '*': result = leftValue * rightValue; break;
        case '/': result = leftValue / rightValue; break;
        case '%': result = leftValue % rightValue; break;
    }

    std::cout << "Arithmetic operation: " << leftValue << " " << operation << " " << rightValue << " = " << result << std::endl;
}

// LogicalOpNode interpretation (Binary logical operations)
void LogicalOpNode::interpret() {
    left->interpret();
    if (right) right->interpret();
    
    bool result = false;
    bool leftValue = SymbolTable::getInstance().getBooleanValue(left);
    if (right) {
        bool rightValue = SymbolTable::getInstance().getBooleanValue(right);
        if (operation == 'O') result = leftValue || rightValue;
    } else if (operation == 'N') {
        result = !leftValue;
    }

    std::cout << "Logical operation executed." << std::endl;
}

// ComparisonNode interpretation (Comparison operations)
void ComparisonNode::interpret() {
    left->interpret();
    right->interpret();
    int leftValue = SymbolTable::getInstance().getIntValue(left);
    int rightValue = SymbolTable::getInstance().getIntValue(right);
    bool result = false;

    if (operation == 'G') result = (leftValue > rightValue);
    else if (operation == 'L') result = (leftValue < rightValue);

    std::cout << "Comparison operation: " << leftValue << " " << operation << " " << rightValue << " = " << result << std::endl;
}

// IntNode interpretation
void IntNode::interpret() {
    // Int literal is already a value, no interpretation needed
    std::cout << "Integer value: " << value << std::endl;
}

// BoolNode interpretation
void BoolNode::interpret() {
    // Bool literal is already a value, no interpretation needed
    std::cout << "Boolean value: " << value << std::endl;
}

// VariableNode interpretation
void VariableNode::interpret() {
    // Retrieve the value of the variable from the symbol table
    std::cout << "Variable '" << id << "' interpreted." << std::endl;
}

// ArrayAccessNode interpretation
void ArrayAccessNode::interpret() {
    // Interpret each index to get the array element
    for (ASTNode* index : *indices) {
        index->interpret();
    }
    std::cout << "Array access interpreted for array '" << id << "'." << std::endl;
}

// Generic interpretation function for traversing the AST
void interpret(ASTNode *node) {
    if (!node) return;
    node->interpret();
    interpret(node->sibling);  // Interpret sibling nodes in sequence
}

// Divide.cpp

#include "Divide.h"
#include <sstream>
#include "Literal.h"

Divide::Divide() {}


//Functions
double Divide::evaluate(std::map<std::string, double> &varsMap) const {
    const double leftDbl = getLeftChild()->evaluate(varsMap);
    const double rightDbl = getRightChild()->evaluate(varsMap);
    if (rightDbl == 0.0) {
        throw std::runtime_error("Division by zero error.");
    }
    return leftDbl / rightDbl;
}

INode* Divide::clone() {
    Divide* newNode = new Divide(*this);
    if (hasLeftChild()) {
        INode* newLeftChild = getLeftChild()->clone();
        newNode->allocateLeftChild(newLeftChild);
    }
    if (hasRightChild()) {
        INode* newRightChild = getRightChild()->clone();
        newNode->allocateRightChild(newRightChild);
    }
    return newNode;
}

//getters
std::string Divide::getStrValue() const {
    return "/";
}




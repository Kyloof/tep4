// Multiply.cpp

#include "Multiply.h"
#include <sstream>
#include "Literal.h"

Multiply::Multiply() {}


//Functions
double Multiply::evaluate(std::map<std::string, double> &varsMap) const {
    const double leftDbl = getLeftChild()->evaluate(varsMap);
    const double rightDbl = getRightChild()->evaluate(varsMap);
    return leftDbl * rightDbl;
}

INode* Multiply::clone() {
    Multiply* newNode = new Multiply(*this);
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
std::string Multiply::getStrValue() const {
    return "+";
}


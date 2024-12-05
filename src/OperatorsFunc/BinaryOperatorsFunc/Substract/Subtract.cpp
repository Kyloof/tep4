// Subtraction.cpp

#include "Subtract.h"
#include <sstream>
#include "Literal.h"

Subtract::Subtract() {}


//Functions
double Subtract::evaluate(std::map<std::string, double> &varsMap) const {
    const double leftDbl = getLeftChild()->evaluate(varsMap);
    const double rightDbl = getRightChild()->evaluate(varsMap);
    return leftDbl - rightDbl;
}

INode* Subtract::clone() {
    Subtract* newNode = new Subtract(*this);
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
std::string Subtract::getStrValue() const {
    return "-";
}


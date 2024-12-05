//
// Created by janku on 20.11.2024.
//

#include "Cos.h"

#include <cmath>
#include <sstream>
#include "Literal.h"

Cos::Cos(){}

double Cos::evaluate(std::map<std::string, double> &varsMap) const {
    return std::cos(getChild()->evaluate(varsMap));
}

INode* Cos::clone() {
    Cos* newNode = new Cos(*this);
    if (hasChild()) {
        INode* newChild = getChild()->clone();
        newNode->allocateChild(newChild);
    }
    return newNode;
}
std::string Cos::getStrValue() const{
    return "cos";
}




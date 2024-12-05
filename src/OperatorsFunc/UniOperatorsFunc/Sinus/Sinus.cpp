//
// Created by janku on 20.11.2024.
//

#include "Sinus.h"

#include <cmath>
#include <sstream>
#include "Literal.h"

Sinus::Sinus() {}

double Sinus::evaluate(std::map<std::string, double> &varsMap) const {
    return std::sin(getChild()->evaluate(varsMap));
}

INode* Sinus::clone() {
    Sinus* newNode = new Sinus(*this);
    if (hasChild()) {
        INode* newChild = getChild()->clone();
        newNode->allocateChild(newChild);
    }
    return newNode;
}


std::string Sinus::getStrValue() const {
    return "sin";
}


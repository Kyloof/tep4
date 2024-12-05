//
// Created by Jan Kubow on 19/11/2024.
//

#include "Literal.h"
#include <iostream>
#include <sstream>


//Constructors
Literal::Literal(const std::string& value) {
    parent = 0;
    std::stringstream ss;
    ss << value;
    double dbl;
    ss >> dbl;
    this->value = dbl;
}

Literal::Literal(const double value) {
    this->value = value;
    parent = 0;
}

Literal::~Literal() {}


//functions
double Literal::evaluate(std::map<std::string, double> &varsMap) const {
    return value;
}

bool Literal::inputChild(INode* node, const bool change, INode *nodeToSwitch) {
    return false;
}

INode *Literal::traverseDown() const {
    return NULL;
}

bool Literal::isLeaf() const {
    return true;
}

std::queue<INode *> Literal::addChildrenToQueue(std::queue<INode *> nodeQueue) const {return nodeQueue;}

INode* Literal::clone() {
    return new Literal(*this);
}


// getters&setters
INode* Literal::getParent() const {
    return parent;
}

void Literal::setParent(INode* node) {
    parent = node;
}

std::string Literal::getStrValue() const {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

const std::string& Literal::getFormula(std::string &formula) const {
    formula += getStrValue() + " ";
    return formula;
}






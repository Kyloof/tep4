//
// Created by janku on 20.11.2024.
//

#include "AUniOperator.h"
//Constructors
AUniOperator::AUniOperator() : child(0) {}

AUniOperator::~AUniOperator() {
    delete child;
    child = 0;
}


//Functions
bool AUniOperator::inputChild(INode* node, const bool change, INode *nodeToSwitch) {
    if (change) {
        if (nodeToSwitch != NULL) {
            if (child == nodeToSwitch) {
                allocateChild(node);
                return true;
            }
            return false;
        }
        else {
            delete child;
            allocateChild(node);
            return true;
        }
    }
    if (hasChild()) return false;
    allocateChild(node);
    return true;
}

std::queue<INode *> AUniOperator::addChildrenToQueue(std::queue<INode *> nodeQueue) const {
    if (hasChild()) nodeQueue.push(child);
    return nodeQueue;
}

INode *AUniOperator::traverseDown() const {
    return getChild();
}

bool AUniOperator::isLeaf() const {
    return getChild()!=0;
}

bool AUniOperator::hasChild() const {
    return this->child != 0;
}

void AUniOperator::allocateChild(INode* node) {
    this->child = node;
    node->setParent(this);
}

//getters
const std::string& AUniOperator::getFormula(std::string &formula) const {
    formula+=this->getStrValue() + " ";
    if(hasChild()) child->getFormula(formula);
    return formula;
}

INode* AUniOperator::getChild() const {
    return this->child;
}






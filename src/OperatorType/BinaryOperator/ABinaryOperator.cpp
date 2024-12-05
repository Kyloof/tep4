//
// Created by Jan Kubow on 19/11/2024.
//

#include "ABinaryOperator.h"

#include <queue>

//constructors
ABinaryOperator::ABinaryOperator() : leftChild(0), rightChild(0) {}

ABinaryOperator::~ABinaryOperator() {
    delete leftChild;
    delete rightChild;
    leftChild = 0;
    rightChild = 0;
}

//Functions
bool ABinaryOperator::hasLeftChild() const {
    return leftChild != 0;
}

bool ABinaryOperator::hasRightChild() const {
    return rightChild != 0;
}

void ABinaryOperator::allocateLeftChild(INode* node) {
    this->leftChild = node;
    leftChild->setParent(this);
}

void ABinaryOperator::allocateRightChild(INode* node) {
    this->rightChild = node;
    rightChild->setParent(this);
}

bool ABinaryOperator::inputChild(INode* node, const bool change, INode *nodeToSwitch) {
    if (change) {
        if (nodeToSwitch != NULL) {
            if (leftChild == nodeToSwitch) {
                allocateLeftChild(node);
                return true;
            }
            if (rightChild == nodeToSwitch) {
                allocateRightChild(node);
                return true;
            }
            return false;
        }
        else {
            if (hasLeftChild()) {
                delete leftChild;
                allocateLeftChild(node);
                return true;
            }
            delete rightChild;
            allocateRightChild(node);
            return true;
        }
    }
    if (hasLeftChild()) {
        if (hasRightChild()) {
            return false;
        }
        allocateRightChild(node);
        return true;
    }
    allocateLeftChild(node);
    return true;
}

INode *ABinaryOperator::traverseDown() const {
    if (hasLeftChild()) return leftChild;
    return 0;
}

bool ABinaryOperator::isLeaf() const {
    return !hasLeftChild();
}

std::queue<INode *> ABinaryOperator::addChildrenToQueue(std::queue<INode *> nodeQueue) const {
    if (hasLeftChild()) nodeQueue.push(leftChild);
    if (hasRightChild()) nodeQueue.push(rightChild);
    return nodeQueue;
}


//getters&setters
INode* ABinaryOperator::getRightChild() const {
    return this->rightChild;
}

INode* ABinaryOperator::getLeftChild() const {
    return this->leftChild;
}

const std::string &ABinaryOperator::getFormula(std::string &formula) const {
    formula += this->getStrValue() + " ";
    if(hasLeftChild()) leftChild->getFormula(formula);
    if(hasRightChild()) rightChild->getFormula(formula);
    return formula;
}











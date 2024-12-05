//
// Created by janku on 20.11.2024.
//

#include "AOperator.h"
#include <iostream>

//Constructors
AOperator::AOperator() : parent(0) {}
AOperator::~AOperator() {}


//getters&setters
INode* AOperator::getParent() const {
    return this->parent;
}

void AOperator::setParent(INode* node) {
    this->parent = node;
}





//
// Created by janku on 20.11.2024.
//

#ifndef MULTIPLY_H
#define MULTIPLY_H
#include "INode.h"
#include "../../../OperatorType/BinaryOperator/ABinaryOperator.h"


class Multiply : public ABinaryOperator{
public:
    Multiply();

    //Functions
    double evaluate(std::map<std::string, double> &varsMap) const;
    INode *clone();

    //getters
    std::string getStrValue() const;
};



#endif //MULTIPLY_H

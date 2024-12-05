//
// Created by janku on 20.11.2024.
//

#ifndef ADDITION_H
#define ADDITION_H
#include "../../../OperatorType/BinaryOperator/ABinaryOperator.h"


class Addition : public ABinaryOperator{
public:
    Addition();

    //Functions
    double evaluate(std::map<std::string, double> &varsMap) const;
    INode *clone();

    //getters
    std::string getStrValue() const;
};



#endif //ADDITION_H

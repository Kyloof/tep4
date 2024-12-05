//
// Created by janku on 20.11.2024.
//

#ifndef DIVIDE_H
#define DIVIDE_H
#include "../../../OperatorType/BinaryOperator/ABinaryOperator.h"


class Divide : public ABinaryOperator{
public:
    Divide();

    //Functions
    double evaluate(std::map<std::string, double> &varsMap) const;
    INode *clone();

    //getters
    std::string getStrValue() const;
};



#endif //DIVIDE_H

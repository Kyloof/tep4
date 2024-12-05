//
// Created by janku on 20.11.2024.
//

#ifndef SUBSTRACT_H
#define SUBSTRACT_H

#include "../../../OperatorType/BinaryOperator/ABinaryOperator.h"


class Subtract : public ABinaryOperator {
public:
    Subtract();

    //Functions
    double evaluate(std::map<std::string, double> &varsMap) const;
    INode *clone();

    //getters
    std::string getStrValue() const;
};



#endif //SUBSTRACT_H

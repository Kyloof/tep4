//
// Created by janku on 20.11.2024.
//

#ifndef SINUS_H
#define SINUS_H
#include "../../../OperatorType/UniOperator/AUniOperator.h"

class Sinus : public AUniOperator {
public:
    Sinus();

    //Functions
    double evaluate(std::map<std::string, double> &varsMap) const;
    INode *clone();

    //getters
    std::string getStrValue() const;
};



#endif //SINUS_H

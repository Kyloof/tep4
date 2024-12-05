//
// Created by janku on 20.11.2024.
//

#ifndef COS_H
#define COS_H
#include "../../../OperatorType/UniOperator/AUniOperator.h"


class Cos : public AUniOperator {
public:
    Cos();

    //Functions
    double evaluate(std::map<std::string, double> &varsMap) const;
    INode *clone();

    //getters
    std::string getStrValue() const;
};


#endif //COS_H

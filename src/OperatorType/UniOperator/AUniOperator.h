//
// Created by janku on 20.11.2024.
//

#ifndef UNIOPERATOR_H
#define UNIOPERATOR_H
#include "AOperator.h"
#include "INode.h"


class AUniOperator : public AOperator {

public:
    AUniOperator();
    ~AUniOperator();

    //virtual
    double evaluate(std::map<std::string, double> &varsMap) const = 0;
    std::string getStrValue() const = 0;
    INode *clone() = 0;

    //Functions
    bool hasChild() const;
    void allocateChild(INode* node);
    bool inputChild(INode* node, bool change, INode *nodeToSwitch);
    INode* traverseDown() const;
    bool isLeaf() const;
    std::queue<INode *> addChildrenToQueue(std::queue<INode *> nodeQueue) const;

    //getters&setters
    INode* getChild() const;
    const std::string &getFormula(std::string &formula) const;

private:
    INode* child;
};



#endif //UNIOPERATOR_H

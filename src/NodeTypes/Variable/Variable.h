//
// Created by Jan Kubow on 19/11/2024.
//

#ifndef VARIABLE_H
#define VARIABLE_H
#include <string>

#include "INode.h"


class Variable : public INode{
public:
    //Constructors
    explicit Variable(const std::string& newName);
    ~Variable();

    //Func
    double evaluate(std::map<std::string, double> &varsMap) const;
    bool inputChild(INode* node, bool change, INode *nodeToSwitch);
    INode* traverseDown() const;
    bool isLeaf() const;
    std::queue<INode *> addChildrenToQueue(std::queue<INode *> nodeQueue) const;
    INode *clone();

    //getters&setters
    INode* getParent() const;
    void setParent(INode* node);
    std::string getStrValue() const;
    const std::string &getFormula(std::string &formula) const;

private:
    std::string name;
    INode* parent;
    mutable double value;
};



#endif //VARIABLE_H

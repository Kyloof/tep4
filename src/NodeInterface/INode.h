//
// Created by Jan Kubow on 19/11/2024.
//

#ifndef NODE_H
#define NODE_H


#include <map>
#include <queue>
#include <string>




class INode {
public:
    //Constructors
    virtual ~INode() {}

    //Func
    virtual double evaluate(std::map<std::string, double> &varsMap) const = 0; //evaluates sequence from current node
    //returns true if child was inputted, false if not
    virtual bool inputChild(INode* node, bool change, INode *nodeToSwitch) = 0;
    virtual INode* traverseDown() const = 0;     //traverses down the tree... useful for joining
    virtual bool isLeaf() const = 0;
    virtual std::queue<INode *> addChildrenToQueue(std::queue<INode *> nodeQueue) const = 0;
    virtual INode* clone() = 0;

    //getters&setters
    virtual INode* getParent() const = 0;
    virtual void setParent(INode* node) = 0;
    virtual std::string getStrValue() const = 0;
    virtual const std::string& getFormula(std::string &formula) const = 0;

private:


};


#endif //NODE_H

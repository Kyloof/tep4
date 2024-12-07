//
// Created by Jan Kubow on 19/11/2024.
//

#ifndef ABSTRACTSYNTAXTREE_H
#define ABSTRACTSYNTAXTREE_H
#include <set>

#include "../NodeInterface/INode.h"
#include "../NodeTypes/Literal/Literal.h"
#include "../NodeTypes/Variable//Variable.h"
#include "../OperatorsFunc/BinaryOperatorsFunc/Addition/Addition.h"
#include "../OperatorsFunc/BinaryOperatorsFunc/Divide/Divide.h"
#include "../OperatorsFunc/BinaryOperatorsFunc/Multiply/Multiply.h"
#include "../OperatorsFunc/BinaryOperatorsFunc/Substract/Subtract.h"
#include "../OperatorsFunc/UniOperatorsFunc/Cos/Cos.h"
#include "../OperatorsFunc/UniOperatorsFunc/Sinus/Sinus.h"
#include "../CError/CError.h"
#include <string>

#include "../CResult/CResult.h"


class AbstractSyntaxTree {

public:
    //Constructors
    AbstractSyntaxTree();
    AbstractSyntaxTree(const AbstractSyntaxTree& other);
    ~AbstractSyntaxTree();

    //Operators
    AbstractSyntaxTree& operator=(const AbstractSyntaxTree& other);
    CResult<AbstractSyntaxTree*, CError> operator+(const AbstractSyntaxTree& other) const;


    //Functions
    CResult<AbstractSyntaxTree*, CError> enter(const std::string& formula);
    CResult<AbstractSyntaxTree*, CError> join(const std::string& formula);
    CResult<std::string, CError> vars();
    CResult<std::string, CError> comp(const std::string& vars) const;
    CResult<std::string, CError> returnFormula() const;
    bool partialSwap(AbstractSyntaxTree& other, const std::string& token);




private:
    INode* root;
    INode* inputNode;
    std::set<std::string> varsSet;
    INode* createNode(const std::string& formula, bool isNumber);
    INode* searchTokenBFS(const std::string& token) const;

    bool fixTree();
    void deleteTree();
    bool addFormula(const std::string& formula, bool isNumber);
};



#endif //ABSTRACTSYNTAXTREE_H

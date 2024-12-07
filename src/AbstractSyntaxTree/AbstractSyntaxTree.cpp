//
// Created by Jan Kubow on 19/11/2024.
//

#include "AbstractSyntaxTree.h"
#include <iterator>
#include <string>
#include <map>
#include <queue>
#include <sstream>
#include <vector>

#include "../CResult/CResult.h"


//Constructors
AbstractSyntaxTree::AbstractSyntaxTree() : root(nullptr), inputNode(root){}

AbstractSyntaxTree::AbstractSyntaxTree(const AbstractSyntaxTree &other) {
    root = nullptr;
    inputNode = nullptr;
    if (other.root != nullptr) {
        root = other.root->clone();
    }
}


AbstractSyntaxTree::~AbstractSyntaxTree() {
    if (root != nullptr && root->getParent()==nullptr) {
        deleteTree();
    }
}

AbstractSyntaxTree& AbstractSyntaxTree::operator=(const AbstractSyntaxTree& other) {
    if (this == &other) return *this;
    deleteTree();
    if (other.root != nullptr) {
        root = other.root->clone();
        varsSet = other.varsSet;
    }
    return *this;
}

CResult<AbstractSyntaxTree*, CError> AbstractSyntaxTree::operator+(const AbstractSyntaxTree& other) const {
    AbstractSyntaxTree newTree = *this;

    std::string formula;
    CResult<AbstractSyntaxTree*,CError> result = newTree.join(other.root->getFormula(formula));
    if (result.isSuccess()) return result;
    return CResult<AbstractSyntaxTree*, CError>::fail(result.getErrors());
}


//Functions
INode* AbstractSyntaxTree::createNode(const std::string& formula, const bool isNumber) {
    if (isNumber) return new Literal(formula);
    if (formula == "+") {
        return new Addition();
    } if (formula == "-") {
        return new Subtract();
    } if (formula == "*") {
        return new Multiply();
    } if (formula == "/") {
        return new Divide();
    } if (formula == "sin") {
        return new Sinus();
    } if (formula == "cos") {
        return new Cos();
    }
    varsSet.insert(formula);
    return new Variable(formula);
}

bool AbstractSyntaxTree::addFormula(const std::string& formula, const bool isNumber) {
    bool inputBool = false;
    INode* newNode = createNode(formula, isNumber);

    if (root == nullptr) {
        root = newNode;
        inputNode = root;
        return true;
    }

    while (!inputBool) {
        inputBool = inputNode->inputChild(newNode, false, nullptr);
        if (inputBool == true) {
            inputNode = newNode;
            return true;
        }
        //tree is already filled up cuz inputNode == root
        if (inputNode->getParent() == nullptr) {
            return false;
        }
        inputNode = inputNode->getParent();
    }
    return false;
}

void AbstractSyntaxTree::deleteTree() {
    if (root != nullptr) {
        delete root;
        root = nullptr;
        inputNode = nullptr;
    }
    this->varsSet.clear();
}


bool AbstractSyntaxTree::fixTree() {
    if (root == nullptr) {
        return false;
    }
    bool hadToFix = false;

    //fix children
    while(inputNode!=root) {
        while(inputNode->inputChild(new Literal(1), false, nullptr)) hadToFix = true;
        inputNode = inputNode->getParent();
    }

    //fix root
    while (inputNode->inputChild(new Literal(1), false, nullptr)) {
        hadToFix = true;
    }

    if (hadToFix) {
        return false;
    }
    return true;
}


CResult<std::string, CError> AbstractSyntaxTree::comp(const std::string &vars) const {
    if (root == nullptr) {
        return CResult<std::string, CError>::fail(new CError("Error: the tree is empty \n"));
    }
    std::istringstream iss(vars);
    std::vector<double> values;
    double value;

    while (iss >> value) {
        values.push_back(value);
    }
    if (values.size() != varsSet.size()) {
        return CResult<std::string, CError>::fail(new CError("Error: Number of variables is not equal to values entered. \n"));
    }

    std::map<std::string, double> varsMap;
    std::set<std::string>::const_iterator varIt = varsSet.begin();
    std::vector<double>::const_iterator valIt = values.begin();

    for (; varIt != varsSet.end() && valIt != values.end(); ++varIt, ++valIt) {
        varsMap[*varIt] = *valIt;
    }

    double returnValue = root->evaluate(varsMap);
    std::ostringstream oss;
    oss << returnValue;
    std::string str = oss.str();
    return str;
}

CResult<AbstractSyntaxTree*,CError> AbstractSyntaxTree::join(const std::string &formula) {
    AbstractSyntaxTree tempTree = *this;

    AbstractSyntaxTree other;
    CResult<AbstractSyntaxTree*, CError> result = other.enter(formula);
    if (!result.isSuccess()) return CResult<AbstractSyntaxTree*, CError>::fail(result.getErrors());

    tempTree.varsSet.insert(other.varsSet.begin(), other.varsSet.end());

    const INode* nodeToJoin = tempTree.root;

    if (nodeToJoin != nullptr) {
        while (!nodeToJoin->isLeaf()) {
            nodeToJoin = nodeToJoin->traverseDown();
        }

        INode* parentNode = nodeToJoin->getParent();
        if (parentNode != nullptr) {
            parentNode->inputChild(other.root, true, nullptr);
        } else {
            delete tempTree.root;
            tempTree.root = nullptr;

            result = tempTree.enter(formula);
            if (!result.isSuccess()) {
                return CResult<AbstractSyntaxTree*, CError>::fail(result.getErrors());
            }
        }
    } else {
        tempTree = other;
    }

    *this = tempTree;
    return CResult<AbstractSyntaxTree*, CError>::success(this);
}

CResult<AbstractSyntaxTree*, CError> AbstractSyntaxTree::enter(const std::string &formula) {
    AbstractSyntaxTree tempTree;
    std::vector<CError*> cerrVector;

    std::string currentFormula;
    bool isNumber = true;

    for (size_t i = 0; i <= formula.size(); i++) {
        if (formula[i] == ' ' || i == formula.size()) {
            if (!currentFormula.empty()) {
                const bool result = tempTree.addFormula(currentFormula, isNumber);
                if (!result) {
                    CError cerr("Error: invalid token: " + currentFormula);
                    cerrVector.push_back(new CError(cerr));
                }
                currentFormula = "";
                isNumber = true;
            }
        } else {
            if (!std::isdigit(formula[i]) && formula[i] != '.') {
                isNumber = false;
            }
            currentFormula += formula[i];
        }
    }
    if (!cerrVector.empty()) return CResult<AbstractSyntaxTree*, CError>::fail(cerrVector);

    if (!tempTree.fixTree()) {
        return CResult<AbstractSyntaxTree*, CError>::fail(new CError("Error: Invalid formula entered. \n"));
    }

    *this = tempTree;

    return CResult<AbstractSyntaxTree*, CError>::success(this);
}



CResult<std::string, CError> AbstractSyntaxTree::vars() {
    std::ostringstream oss;
    std::copy(
        varsSet.begin(),
        varsSet.end(),
        std::ostream_iterator<std::string>(oss, " ")
    );
    return CResult<std::string,CError>::success(oss.str());;
}

CResult<std::string, CError> AbstractSyntaxTree::returnFormula() const {

    if (root == nullptr) {
        CError err("Error: the tree is empty \n");
        return CResult<std::string,CError>::fail(new CError("Error: the tree is empty \n"));

    }
    std::string str;
    root->getFormula(str);
    str += "\n";
    return CResult<std::string,CError>::success(str);
}

INode* AbstractSyntaxTree::searchTokenBFS(const std::string& token) const {
    std::queue<INode*> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty()) {
        INode* currentNode = nodeQueue.front();
        nodeQueue.pop();

        if (currentNode->getStrValue() == token) return currentNode;
        nodeQueue = currentNode->addChildrenToQueue(nodeQueue);
    }
    return nullptr;
}



bool AbstractSyntaxTree::partialSwap(AbstractSyntaxTree &other, const std::string& token) {

    INode* thisNode = this->searchTokenBFS(token);
    INode* otherNode = other.searchTokenBFS(token);
    if (thisNode == nullptr || otherNode == nullptr) return false;

    if (thisNode == this->root) this->root = otherNode;
    else thisNode->getParent()->inputChild(otherNode, true, thisNode);

    if (otherNode == other.root) other.root = thisNode;
    else otherNode->getParent()->inputChild(thisNode, true, otherNode);
    return true;
}




//
// Created by janku on 20.11.2024.
//

#ifndef COMMAND_H
#define COMMAND_H
#include <vector>

#include "../AbstractSyntaxTree/AbstractSyntaxTree.h"


class Command {

public:
    Command();
    void commandLine();


private:
    void enterCommand(const std::string& formula);
    void printCommand() const;
    void joinCommand(const std::string& formula);
    static void helpCommand();
    void compCommand(const std::string& formula) const;
    void varsCommand();
    CResult<bool, CError> checkFormula(const std::string& formula);
    AbstractSyntaxTree AST;
    CResult<AbstractSyntaxTree, CError> prepareEnter(const std::string &formula);
};



#endif //COMMAND_H

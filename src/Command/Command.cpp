//
// Created by janku on 20.11.2024.
//

#include "Command.h"

#include <algorithm>
#include <functional>
#include <iostream>
#include <sstream>

Command::Command() {}


void Command::commandLine() {
    std::string line;
    std::cout << "Welcome, everything is ok\n";
    std::cout << "Enter command, for more info type 'help'\n";
    bool run = true;
    while (run) {
        std::cout << "> ";
        std::getline(std::cin, line);

        std::istringstream iss(line);
        std::string command;
        iss >> command;
        std::string arguments;
        std::getline(iss, arguments);
        //delete the first spaces from args
        arguments.erase(arguments.begin(), std::find_if(arguments.begin(), arguments.end(), std::bind1st(std::not_equal_to<char>(), ' ')));


        if (command == "help") {
            helpCommand();
        } else if (command == "enter") {
            if (arguments.empty()) CResult<void, CError>::fail(new CError("Error: no arguments entered. Please try again.\n")).showErrors();
            else enterCommand(arguments);
        } else if (command == "join") {
            if (arguments.empty()) CResult<void, CError>::fail(new CError("Error: no arguments entered. Please try again.\n")).showErrors();
            else joinCommand(arguments);
        } else if (command == "print") {
            printCommand();
        } else if (command == "comp") {
            compCommand(arguments);
        } else if (command == "vars") {
            varsCommand();
        } else if (command == "exit") {
            run = false;
        } else {
            CResult<void, CError>::fail(new CError("Wrong value entered! Please try again.\n")).showErrors();
        }
    }
}

void Command::helpCommand() {
    std::cout << "Available commands:\n"
              << "help  - Show this help message\n"
              << "enter - Enter values (e.g., 'enter + 1 - 2 3')\n"
              << "join  - Join tree\n"
              << "print - Print tree\n"
              << "comp  - compile <var1> <var2> ...\n"
              << "vars  - Show variables\n"
              << "exit  - Exit the program\n"
              << "error - view error log\n";
}

void Command::enterCommand(const std::string& formula) {
    CResult result = this->prepareEnter(formula);
    if (!result.isSuccess()) result.showErrors();
}

void Command::joinCommand(const std::string& formula) {
    CResult result = AST.join(formula);
    if (!result.isSuccess()) result.showErrors();
}

void Command::printCommand() const {
    CResult<std::string, CError> result = this->AST.returnFormula();
    if(result.isSuccess()) std::cout << (*result.getValue());
    else result.showErrors();
}

void Command::varsCommand() {
    CResult<std::string, CError> result = this->AST.vars();
    if(result.getValue()->empty()) CResult<void, CError>(new CError("Error: there are no variables in the tree")).showErrors();
    else if(result.isSuccess()) std::cout << result.getValue();
    else result.showErrors();
}

void Command::compCommand(const std::string& formula) const {
    CResult<std::string, CError> result = this->AST.comp(formula);
    if(result.isSuccess()) std::cout << result.getValue();
    else result.showErrors();
}

CResult<bool, CError> Command::checkFormula(const std::string &formula) {
    if (formula.empty()) {
        return CResult<bool,CError>::fail(new CError("Error: formula is empty! \n"));
    }
    if (formula == "+" || formula == "*" || formula == "sin" || formula == "cos" || formula == "-" || formula == "/") {
        return CResult<bool,CError>::success(true);
    }

    std::string wrongValues;

    for (int i = 0; i < formula.size(); i++) {
        char c = formula[i];
        if (!std::isdigit(c) && !std::isalpha(c) && c != '.' && c != '+' && c != '-' && c != '*' && c != '/') {
            wrongValues += c;
            wrongValues += " ";
        }
    }
    if (!wrongValues.empty()) {
        return CResult<bool,CError>::fail(new CError("detected wrong values in formula: \n" +  wrongValues + '\n'));
    }
    return CResult<bool,CError>::success(true);
}

CResult<AbstractSyntaxTree, CError> Command::prepareEnter(const std::string &formula) {
    std::string fixedFormula;
    std::string currentFormula;

    for (int i = 0; i <= formula.size(); i++) {
        if (i < formula.size() && formula[i] != ' ') {
            currentFormula += formula[i];
        } else {
            if (!currentFormula.empty()) {
                CResult<bool, CError> resultFormula = checkFormula(currentFormula);
                if (resultFormula.isSuccess()) {
                    fixedFormula += currentFormula + " ";
                    currentFormula.clear();
                } else {
                    return CResult<AbstractSyntaxTree, CError>::fail(resultFormula.getErrors());
                }
            }
        }
    }


    return AST.enter(fixedFormula);
}







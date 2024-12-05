#include <iostream>

#include "src/Command/Command.h"
#include "src/CResult/CResult.h"
#include "src/Save/Save.h"
//
// Created by janku on 1.12.2024.
//
CResult<double,CError> divide(double left, double right) {
    if (right == 0) {
        return new CError("cannot divid by zero");
    }

    return left/right;
}

int main() {
    CResult<double,CError> cr = divide(5.0,0);
    cr.showErrors();

    AbstractSyntaxTree* tree = new AbstractSyntaxTree;;
    tree->enter("+ 1 - 2 3");

    Save::saveToFile(tree, "astSuccess.txt");
    Save::saveToFile(tree->enter("+ 1 - 2 ! @"), "astFail.txt");

    Save::saveToFile(cr, "fail");

    return 0;
}
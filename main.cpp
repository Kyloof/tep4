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

    Command cmd;
    cmd.commandLine();
    return 0;
}
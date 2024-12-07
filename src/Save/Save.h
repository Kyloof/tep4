//
// Created by janku on 5.12.2024.
//

#ifndef SAVE_H
#define SAVE_H
#include <fstream>

#include "../AbstractSyntaxTree/AbstractSyntaxTree.h"
#include "../CError/CError.h"
#include "../CResult/CResult.h"

/**
    * @tparam T - template class of type T
    * @param result - result of some operation.
    * @param filename - file to save the result of CResult class.
 */
template <typename T>
class Save {
public:
    static void saveToFile(const CResult<T, CError>& result, const std::string& filename) {
        std::ofstream file(filename, std::ios::out);

        if (!file) {
            std::cerr << "Can't open file" << std::endl;
            return;
        }

        if (!result.isSuccess()) {
            for (CError* error : result.getErrors()) {
                file << error->getDescription() << std::endl;
            }
        }
        file.close();
    }
};
template <>
class Save<AbstractSyntaxTree*> {
public:
    // AST Specialization
    static void saveToFile(const CResult<AbstractSyntaxTree*, CError>& result, const std::string& filename) {
        std::ofstream file(filename, std::ios::out);

        if (!file) {
            CError err(std::string("Can't open file"));
            CResult<void,CError>::fail(&err).showErrors();
            return;
        }

        if (result.hasErrors()) {
            for (CError* error : result.getErrors()) {
                file << error->getDescription() << std::endl;
            }
        }

        if (result.isSuccess() && result.getValue() != nullptr) {
            const AbstractSyntaxTree *tree = *result.getValue();
            file << *tree->returnFormula().getValue() << std::endl;
        }
        file.close();
    }
};


#endif //SAVE_H

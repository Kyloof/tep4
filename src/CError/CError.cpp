//
// Created by Jan Kubow on 01/12/2024.
//

#include "CError.h"

#include <iostream>

CError::CError(const std::string& description) {
    this->description = description;
}

std::string CError::getDescription() {
    return description;
}

std::ostream& operator<<(std::ostream& os, const CError& error) {
    os << error.description;
    return os;
}

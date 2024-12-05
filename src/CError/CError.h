//
// Created by Jan Kubow on 01/12/2024.
//

#ifndef CERROR_H
#define CERROR_H
#include <string>


class CError {
public:
    CError(const std::string& description);
    std::string getDescription();
    friend std::ostream& operator<<(std::ostream& os, const CError& error);
private:
    std::string description;
};




#endif //CERROR_H

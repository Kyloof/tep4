//
// Created by Jan Kubow on 01/12/2024.
//

#include "CResult.h"
/*
#include "../CError/CError.h"
//Constructors
template<typename T, typename E>
CResult<T, E>::CResult(const T &value) {
    this->value = value;
}

template<typename T, typename E>
CResult<T, E>::CResult(E *error) {
    this->errors = error;
    value = nullptr;
}

template<typename T, typename E>
CResult<T, E>::CResult(std::vector<E *> &errors) {
    this->errors = errors;
    value = nullptr;
}

template<typename T, typename E>
CResult<T, E>::CResult(const CResult<T, E> &other) {
    if (other.value) value = new T(*other.value);
    else value = nullptr;
    errors = other.errors;
}

template<typename T, typename E>
CResult<T, E>::~CResult() {
    for(int i = errors.size() - 1; i >= 0; i--) {
        delete errors[i];
    }
    delete value;
}


//Functions
template<typename T, typename E>
CResult<T, E> CResult<T, E>::fail(E *error) {
    return CResult(error);
}

template<typename T, typename E>
CResult<T, E> CResult<T, E>::fail(std::vector<E *> &errors) {
    return CResult(errors);
}

template<typename T, typename E>
CResult<T, E> CResult<T, E>::success(const T &value) {
    return CResult(value);
}

//Getters
template<typename T, typename E>
std::vector<E *> &CResult<T, E>::getErrors() {
    return errors;
}

template<typename T, typename E>
T CResult<T, E>::getValue() {
    return value;
}

template<typename T, typename E>
bool CResult<T, E>::isSuccess() {
    return errors.empty();
}

//when T is void

template<typename E>
CResult<void, E>::CResult() {}

template<typename E>
CResult<void, E>::CResult(E *error) {
    this->errors = error;
}

template<typename E>
CResult<void, E>::CResult(std::vector<E *> &errors) {
    this->errors = errors;
}

template<typename E>
CResult<void, E>::CResult(const CResult<void, E> &other) {
    this-> errors = other.errors;
}

template<typename E>
CResult<void, E>::~CResult() {
    for(int i = errors.size() - 1; i >= 0; i--) {
        delete errors[i];
    }
}


//Operator
template<typename E>
CResult<void, E> &CResult<void, E>::operator=(const CResult<void, E> &other) {
    if (other==this) return *this;

    for(int i = errors.size() - 1; i >= 0; i--) {
        delete errors[i];
    }

    this->errors = other.errors;

    return *this;
}


//Functions
template<typename E>
CResult<void, E> CResult<void, E>::fail(E *error) {
    return CResult(error);
}

template<typename E>
CResult<void, E> CResult<void, E>::fail(std::vector<E *> &errors) {
    return CResult(errors);
}

template<typename E>
CResult<void, E> CResult<void, E>::success() {
    return CResult();
}


//Getters
template<typename E>
std::vector<E *> &CResult<void, E>::getErrors() {
    return errors;
}

template<typename E>
bool CResult<void, E>::isSuccess() {
    return errors.empty();
}





*/







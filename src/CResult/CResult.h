//
// Created by Jan Kubow on 01/12/2024.
//

#ifndef CRESULT_H
#define CRESULT_H
#include <iostream>
#include <vector>


//T - type returned | E - error type
template<typename T, typename E>
class CResult {
public:
    // Constructors
    CResult(const T& value) : value(new T(value)), errors() {}

    CResult(E* error) : value(nullptr) {
        if (error) errors.push_back(new E(*error));
    }

    //Takes ownership of pointers
    CResult(const std::vector<E*>& errors) : value(nullptr) {
        for (E* error : errors) if (error) this->errors.push_back(new E(*error));
    }

    CResult(const CResult<T, E>& other) : value(nullptr), errors() {
        if (other.value) value = new T(*other.value);
        for (E* error : other.errors) if (error) errors.push_back(new E(*error));
    }

    ~CResult() {
        delete value;
        for (E* error : errors) delete error;
    }

    CResult<T, E>& operator=(const CResult<T, E>& other) {
        if (this != &other) {
            delete value;
            for (E* error : errors) delete error;
            errors.clear();
            //if possible to assign deep copy value
            value = other.value ? new T(*other.value) : nullptr;
            //deep copy errors
            for (E* error : other.errors) errors.push_back(new E(*error));
        }
        return *this;
    }

    static CResult<T, E> success(const T& value) {
        return CResult(value);
    }

    static CResult<T, E> fail(E* error) {
        return CResult(error);
    }

    static CResult<T, E> fail(const std::vector<E*>& errors) {
        return CResult(errors);
    }

    void showErrors() {
        for (int i = 0; i < errors.size(); i++) std::cout << *errors[i];
    }

    // Accessors
    bool isSuccess() const {
        return errors.empty();
    }

    bool hasErrors() const {
        return !errors.empty();
    }

    T* getValue() const {
        return value;
    }

    const std::vector<E*>& getErrors() const {
        return errors;
    }

private:
    T* value;
    std::vector<E*> errors;
};

//when value is void
template <typename E>
class CResult<void, E>
{
public:
    // Constructors
    CResult(){}

    //Takes ownership of pointer
    CResult(E* error){
        if (error) errors.push_back(error);
    }

    //Takes ownership of pointers
    CResult(const std::vector<E*>& errors) {
        for (E* error : errors) if (error) this->errors.push_back(error);
    }

    CResult(const CResult<void, E>& other) {
        for (E* error : other.errors) if (error) errors.push_back(new E(*error));
    }

    ~CResult() {
        for (E* error : errors) delete error;
    }

    // Functions
    static CResult<void, E> success() {
        return CResult();
    }

    static CResult<void, E> fail(E* error) {
        return CResult(error);
    }

    static CResult<void, E> fail(std::vector<E*>& errors) {
        return CResult(errors);
    }

    CResult<void, E>& operator=(const CResult<void, E>& other) {
        if (this != &other) {
            for (E* error : errors) delete error;
            errors.clear();

            //deep copy errors
            for (int i = 0; i < errors.size(); i++) this->errors.push_back(new E*(errors[i]));
        }
        return *this;
    }

    void showErrors() {
        for (int i = 0; i < errors.size(); i++) std::cout << *errors[i] << std::endl;
    }

    // Getters
    bool isSuccess() const {
        return errors.empty();
    }

    const std::vector<E*>& getErrors() const {
        return errors;
    }

private:
    std::vector<E*> errors;
};





#endif //CRESULT_H

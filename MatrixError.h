//
// Created by mfbut on 3/1/2018.
//

#ifndef MATRIX_MATRIXERROR_H
#define MATRIX_MATRIXERROR_H

#include <exception>
#include <string>

class MatrixError : std::exception {
protected:

public:
    virtual const char *what() const noexcept override;
    static std::string outOfRange(std::string IteratorType, int upperBound, int curPos);

protected:
    std::string errString;
};

#endif //MATRIX_MATRIXERROR_H

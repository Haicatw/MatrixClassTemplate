//
// Created by mfbut on 3/1/2018.
//

#include <sstream>
#include "MatrixError.h"

const char *MatrixError::what() const noexcept {
    return errString.c_str();
}

std::string MatrixError::outOfRange(std::string IteratorType, int upperBound, int curPos) {
    std::stringstream errorStream;
    errorStream << IteratorType << " dereferenced out of bounds. Acceptable values 0 - "
                << upperBound << ". Current position: " << curPos << std::endl;
    return errorStream.str();
}
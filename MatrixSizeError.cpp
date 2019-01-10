

#include <sstream>
#include "MatrixSizeError.h"

MatrixSizeError::MatrixSizeError(int expected, int difference) noexcept {
    std::stringstream errorStream;
    errorStream << "All rows of the matrix should have the same number of elements. Expected rows to contain " << expected
                << " elements but found row that contained " << difference << " elements." << std::endl;
    errString = errorStream.str();
}

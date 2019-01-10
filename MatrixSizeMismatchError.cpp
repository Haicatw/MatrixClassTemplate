
#include "MatrixSizeMismatchError.h"
#include <sstream>

MatrixSizeMismatchError::MatrixSizeMismatchError(Matrix matrix1, Matrix matrix2) noexcept {
    std::stringstream errorStream;
    errorStream << "Matrices must be the same size but Matrix1 is "
                << matrix1.getNumRows() << " X " << matrix1.getNumCols()
                << " and Matrix2 is " << matrix2.getNumRows() << " X " << matrix2.getNumCols()
                << std::endl;
    errString = errorStream.str();
}

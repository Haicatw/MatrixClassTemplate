#include <sstream>
#include "MatrixInnerDimensionMismatchError.h"

MatrixInnerDimensionMismatchError::MatrixInnerDimensionMismatchError(Matrix matrix1, Matrix matrix2) noexcept {
    std::stringstream errorStream;
    errorStream << "Inner dimensions do not agree. First matrix has "
                << matrix1.getNumCols() << " columns but second matrix has "
                << matrix2.getNumRows() <<" rows." << std::endl;
    errString = errorStream.str();
}

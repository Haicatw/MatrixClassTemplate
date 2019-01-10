#include "Matrix.h"
#include "MatrixSizeError.h"
#include "MatrixInnerDimensionMismatchError.h"
#include "MatrixSizeMismatchError.h"

Matrix::Matrix() = default;

Matrix::Matrix(const std::vector<std::vector<double>> &mat) {
    numRows = mat.size();
    numCols = mat.at(0).size();
    matrixVect = mat;

    int tempSize = numCols;
    for (int i = 0; i < numRows; ++i) {
        if ((unsigned)tempSize != (unsigned)mat.at(i).size()) {
            throw MatrixSizeError(numCols, mat.at(i).size());
        }
    }
}

Matrix::Matrix(const double val, const int numRows, const int numCols) : numRows(numRows), numCols(numCols) {
    matrixVect.resize(numRows);
    for (int k = 0; k < numRows; ++k) {
        matrixVect.at(k).resize(numCols);
    }
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            matrixVect[i][j] = val;
        }
    }
}

std::ostream& operator<<(std::ostream& out,  Matrix&  matrix) {
    for (int i = 0; i <  matrix.numRows; ++i) {
        for (int j = 0; j <  matrix.numCols; ++j) {
            out <<  matrix. matrixVect[i][j] << " ";
        }
        out << std::endl;
    }
    return out;
}

std::istream &operator>>(std::istream &in, Matrix & matrix) {
    in >> matrix.numRows;
    in >> matrix.numCols;
    matrix.matrixVect.resize(matrix.numRows);
    for (int k = 0; k < matrix.numRows; ++k) {
        matrix.matrixVect.at(k).resize(matrix.numCols);
    }
    for (int i = 0; i < matrix.numRows; ++i) {
        for (int j = 0; j < matrix.numCols; ++j) {
            in >> matrix.matrixVect[i][j];
        }
    }
    return in;
}

int Matrix::getNumRows() const {
    return numRows;
}

int Matrix::getNumCols() const {
    return numCols;
}

Matrix Matrix::operator-() const {
    Matrix copy(*this);
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            copy[i][j] = -(matrixVect[i][j]);
        }
    }
    return copy;
}

Matrix &Matrix::operator+=(const Matrix &rhs) {
    if (numCols != rhs.numCols || numRows != rhs.numRows) {
        throw MatrixSizeMismatchError(*this, rhs);
    }
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            matrixVect[i][j] = matrixVect[i][j] + rhs.matrixVect[i][j];
        }
    }
    return *this;
}

Matrix &Matrix::operator+=(const double &rhs) {
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            matrixVect[i][j] = matrixVect[i][j] + rhs;
        }
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix &rhs) const {
    Matrix copy(*this);
    copy += rhs;
    return copy;
}

Matrix Matrix::operator+(const double &rhs) const {
    Matrix copy(*this);
    copy += rhs;
    return copy;
}

Matrix operator+(const double lhs, const Matrix &rhs) {
    return Matrix(lhs, rhs.getNumRows(), rhs.getNumCols()) + rhs;
}

Matrix &Matrix::operator-=(const Matrix &rhs) {
    if (numCols != rhs.numCols || numRows != rhs.numRows) {
        throw MatrixSizeMismatchError(*this, rhs);
    }
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            matrixVect[i][j] = matrixVect[i][j] - rhs.matrixVect[i][j];
        }
    }
    return *this;
}

Matrix &Matrix::operator-=(const double &rhs) {
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            matrixVect[i][j] = matrixVect[i][j] - rhs;
        }
    }
    return *this;
}

Matrix Matrix::operator-(const Matrix &rhs) const {
    Matrix copy(*this);
    copy -= rhs;
    return copy;
}

Matrix Matrix::operator-(const double &rhs) const {
    Matrix copy(*this);
    copy -= rhs;
    return copy;
}

Matrix operator-(const double lhs, const Matrix &rhs) {
    return Matrix(lhs, rhs.getNumRows(), rhs.getNumCols()) - rhs;
}

Matrix &Matrix::operator*=(const Matrix &rhs) {
    if (numRows != rhs.numCols) {
        throw MatrixInnerDimensionMismatchError(*this, rhs);
    }

    Matrix tempMetrix(0, numRows, rhs.numCols);
    for (int i = 0; i < tempMetrix.numRows; ++i) {
        for (int j = 0; j < tempMetrix.numCols; ++j) {
            for (int k = 0; k < rhs.numRows; ++k) {
                tempMetrix.matrixVect[i][j] += matrixVect[i][k] * rhs.matrixVect[k][j]; //TODO:check
            }
        }
    }

    for (int l = 0; l < numRows; ++l) {
        this->matrixVect.at(l).resize(numRows);
    }
    this->matrixVect.resize(rhs.numCols);
    numCols = rhs.numCols;

    for (int m = 0; m < numRows; ++m) {
        for (int i = 0; i < numCols; ++i) {
            this->matrixVect.at(m).at(i) = tempMetrix.matrixVect.at(m).at(i);
        }
    }

    return *this;
}

Matrix &Matrix::operator*=(const double &rhs) {
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            matrixVect[i][j] = matrixVect[i][j] * rhs;
        }
    }
    return *this;
}

Matrix Matrix::operator*(const Matrix &rhs) const {
    Matrix copy(*this);
    copy *= rhs;
    return copy;
}

Matrix Matrix::operator*(const double &rhs) const {
    Matrix copy(*this);
    copy *= rhs;
    return copy;
}

Matrix operator*(const double &lhs, const Matrix &rhs) {
    Matrix copy(rhs);
    return copy *= lhs;
}

RowItr Matrix::operator[](int i) {
    if (i >= numRows || i < 0) {
        throw std::out_of_range(MatrixError::outOfRange("RowItr", numRows - 1, i));
    }
    return RowItr(*this, i);
}

RowItr Matrix::rowBegin() {
    return RowItr(*this, 0);
}

RowItr Matrix::rowEnd() {
    return RowItr(*this, numRows);
}

ColItr Matrix::colBegin() {
    return ColItr(*this, 0);
}

ColItr Matrix::colEnd() {
    return ColItr(*this, numCols);
}

bool Matrix::operator==(const Matrix &rhs) const {
    if (numRows != rhs.numRows) {
        return false;
    }
    if (numCols != rhs.numCols) {
        return false;
    }
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (matrixVect[i][j] != rhs.matrixVect[i][j]) {
                return false;
            }
        }
    }
    return true;
}
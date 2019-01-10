#include "RowItr.h"
#include "MatrixError.h"

RowItr::RowItr(Matrix &matrix, int position) : matrix(matrix), position(position) {

}

RowElementItr RowItr::operator*() {
    if (position >= matrix.getNumRows() || position < 0) {
        throw std::out_of_range(MatrixError::outOfRange("RowItr", matrix.getNumRows() - 1, position));
    }
    return RowElementItr(*this, matrix); //TODO:CHECK
}
/*
RowElementItr RowItr::operator*(int elementPosition) {
    return RowElementItr(*this, matrix, elementPosition);
}
*/
RowItr &RowItr::operator++() {
    position++;
    return *this;
}

RowItr &RowItr::operator++(int) {
    return ++(*this);
}

RowItr &RowItr::operator--() {
    position--;
    return *this;
}

RowItr &RowItr::operator--(int) {
    return --(*this);
}

RowItr &RowItr::operator+=(const int &rhs) {
    position += rhs;
    return *this;
}

RowItr RowItr::operator+(const int &rhs) {
    RowItr copy(*this);
    return copy += rhs;
}

RowItr &RowItr::operator-=(const int &rhs) {
    position -= rhs;
    return *this;
}

RowItr RowItr::operator-(const int &rhs) {
    RowItr copy(*this);
    return copy -= rhs;
}

RowItr::operator bool() const {
    return position >= 0 && position < matrix.getNumRows();
}

bool RowItr::operator!() const {
    return !static_cast<bool>(*this);
}

bool RowItr::operator==(const RowItr &rhs) const {
    return (matrix == rhs.matrix) && (position == rhs.position || !(static_cast<bool>(*this)));
    //return matrix == rhs.matrix && position == rhs.position && static_cast<bool>(*this);
}

bool RowItr::operator!=(const RowItr &rhs) const {
    return !(*this == rhs);
}

bool RowItr::operator<(const RowItr &rhs) const {
    return matrix == rhs.matrix && position < rhs.position;
}

bool RowItr::operator>(const RowItr &rhs) const {
    return matrix == rhs.matrix && position > rhs.position;
}

bool RowItr::operator<=(const RowItr &rhs) const {
    return !(*this > rhs);
}

bool RowItr::operator>=(const RowItr &rhs) const {
    return !(*this < rhs);
}

double &RowItr::operator[](int i) {
    if (i >= matrix.getNumRows() || i < 0) {
        throw std::out_of_range(MatrixError::outOfRange("RowElementItr", matrix.getNumCols() - 1, i));
    }
    return matrix.matrixVect.at(position).at(i);
}

RowElementItr RowItr::begin() {
    return RowElementItr(*this, matrix, 0);
}

RowElementItr RowItr::end() {
    return RowElementItr(*this, matrix, matrix.getNumCols());
}
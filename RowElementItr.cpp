#include "RowElementItr.h"
#include "RowItr.h"
#include "MatrixError.h"

RowElementItr::RowElementItr(RowItr &rowItr, Matrix &matrix, int positionElement) : rowItr(rowItr), matrix(matrix), positionElement(positionElement) {

}

double &RowElementItr::operator*() {
    if (positionElement >= matrix.getNumCols() || positionElement < 0) {
        throw std::out_of_range(MatrixError::outOfRange("RowElementItr", matrix.getNumCols() - 1, positionElement));
    }
    return rowItr[positionElement];
}

RowElementItr &RowElementItr::operator++() {
    positionElement++;
    return *this;
}

RowElementItr &RowElementItr::operator++(int) {
    return ++(*this);
}

RowElementItr &RowElementItr::operator--() {
    positionElement--;
    return *this;
}

RowElementItr &RowElementItr::operator--(int) {
    return --(*this);
}

RowElementItr &RowElementItr::operator+=(const int &rhs) {
    positionElement += rhs;
    return *this;
}

RowElementItr RowElementItr::operator+(const int &rhs) {
    RowElementItr copy(*this);
    return copy += rhs;
}

RowElementItr &RowElementItr::operator-=(const int &rhs) {
    positionElement -= rhs;
    return *this;
}

RowElementItr RowElementItr::operator-(const int &rhs) {
    RowElementItr copy(*this);
    return copy -= rhs;
}

RowElementItr::operator bool() const {
    return positionElement >= 0 && positionElement < matrix.getNumCols();
}

bool RowElementItr::operator!() const {
    return !static_cast<bool>(*this);
}

bool RowElementItr::operator==(const RowElementItr &rhs) const {
    return (matrix == rhs.matrix) && (positionElement == rhs.positionElement || !(static_cast<bool>(*this)));
}

bool RowElementItr::operator!=(const RowElementItr &rhs) const {
    return !(*this == rhs);
}

bool RowElementItr::operator<(const RowElementItr &rhs) const {
    return matrix == rhs.matrix && positionElement < rhs.positionElement;
}

bool RowElementItr::operator>(const RowElementItr &rhs) const {
    return matrix == rhs.matrix && positionElement > rhs.positionElement;
}

bool RowElementItr::operator<=(const RowElementItr &rhs) const {
    return !(*this > rhs);
}

bool RowElementItr::operator>=(const RowElementItr &rhs) const {
    return !(*this < rhs);
}
#include "ColElementItr.h"
#include "ColItr.h"
#include "MatrixError.h"

ColElementItr::ColElementItr(ColItr &colItr, Matrix &matrix, int positionElement) : colItr(colItr), matrix(matrix), positionElement(positionElement) {

}

double &ColElementItr::operator*() {
    if (positionElement >= matrix.getNumRows() || positionElement < 0) {
        throw std::out_of_range(MatrixError::outOfRange("ColElementItr", matrix.getNumRows() - 1, positionElement));
    }
    return colItr[positionElement];
}

ColElementItr &ColElementItr::operator++() {
    positionElement++;
    return *this;
}

ColElementItr &ColElementItr::operator++(int) {
    return ++(*this);
}

ColElementItr &ColElementItr::operator--() {
    positionElement--;
    return *this;
}

ColElementItr &ColElementItr::operator--(int) {
    return --(*this);
}

ColElementItr &ColElementItr::operator+=(const int &rhs) {
    positionElement += rhs;
    return *this;
}

ColElementItr ColElementItr::operator+(const int &rhs) {
    ColElementItr copy(*this);
    return copy += rhs;
}

ColElementItr &ColElementItr::operator-=(const int &rhs) {
    positionElement -= rhs;
    return *this;
}

ColElementItr ColElementItr::operator-(const int &rhs) {
    ColElementItr copy(*this);
    return copy -= rhs;
}

ColElementItr::operator bool() const {
    return positionElement >= 0 && positionElement < matrix.getNumRows();
}

bool ColElementItr::operator!() const {
    return !static_cast<bool>(*this);
}

bool ColElementItr::operator==(const ColElementItr &rhs) const {
    return (matrix == rhs.matrix) && (positionElement == rhs.positionElement || !(static_cast<bool>(*this)));
}

bool ColElementItr::operator!=(const ColElementItr &rhs) const {
    return !(*this == rhs);
}

bool ColElementItr::operator<(const ColElementItr &rhs) const {
    return matrix == rhs.matrix && positionElement < rhs.positionElement;
}

bool ColElementItr::operator>(const ColElementItr &rhs) const {
    return matrix == rhs.matrix && positionElement > rhs.positionElement;
}

bool ColElementItr::operator<=(const ColElementItr &rhs) const {
    return !(*this > rhs);
}

bool ColElementItr::operator>=(const ColElementItr &rhs) const {
    return !(*this < rhs);
}
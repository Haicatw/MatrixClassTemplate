#include "ColItr.h"
#include "MatrixError.h"

ColItr::ColItr(Matrix &matrix, int position) : matrix(matrix), position(position) {

}

ColElementItr ColItr::operator*() {
    if (position >= matrix.getNumCols() || position < 0) {
        throw std::out_of_range(MatrixError::outOfRange("ColItr", matrix.getNumCols() - 1, position));
    }
    return ColElementItr(*this, matrix); //TODO:CHECK
}

ColItr &ColItr::operator++() {
    position++;
    return *this;
}

ColItr &ColItr::operator++(int) {
    return ++(*this);
}

ColItr &ColItr::operator--() {
    position--;
    return *this;
}

ColItr &ColItr::operator--(int) {
    return --(*this);
}

ColItr &ColItr::operator+=(const int &rhs) {
    position += rhs;
    return *this;
}

ColItr ColItr::operator+(const int &rhs) {
    ColItr copy(*this);
    return copy += rhs;
}

ColItr &ColItr::operator-=(const int &rhs) {
    position -= rhs;
    return *this;
}

ColItr ColItr::operator-(const int &rhs) {
    ColItr copy(*this);
    return copy -= rhs;
}

ColItr::operator bool() const {
    return position >= 0 && position < matrix.getNumCols();
}

bool ColItr::operator!() const {
    return !static_cast<bool>(*this);
}

bool ColItr::operator==(const ColItr &rhs) const {
    return (matrix == rhs.matrix) && (position == rhs.position || !(static_cast<bool>(*this)));
}

bool ColItr::operator!=(const ColItr &rhs) const {
    return !(*this == rhs);
}

bool ColItr::operator<(const ColItr &rhs) const {
    return matrix == rhs.matrix && position < rhs.position;
}

bool ColItr::operator>(const ColItr &rhs) const {
    return matrix == rhs.matrix && position > rhs.position;
}

bool ColItr::operator<=(const ColItr &rhs) const {
    return !(*this > rhs);
}

bool ColItr::operator>=(const ColItr &rhs) const {
    return !(*this < rhs);
}

double &ColItr::operator[](int i) {
    return matrix.matrixVect.at(i).at(position); //TODO:CHECK
}

ColElementItr ColItr::begin() {
    return ColElementItr(*this, matrix, 0);
}

ColElementItr ColItr::end() {
    return ColElementItr(*this, matrix, matrix.getNumRows());
}
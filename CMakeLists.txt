cmake_minimum_required(VERSION 3.9)
project(Matrix)

set(CMAKE_CXX_STANDARD 14)
set(GPP_ENABLE_WARNINGS "-O0 -Wall -Werror -Wno-unused-result")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GPP_ENABLE_WARNINGS}")

add_executable(Matrix main.cpp ColElementItr.cpp Matrix.cpp MatrixInnerDimensionMismatchError.cpp MatrixSizeMismatchError.cpp RowItr.cpp ColElementItr.h Matrix.h MatrixInnerDimensionMismatchError.h MatrixSizeMismatchError.h RowItr.h ColItr.cpp MatrixError.cpp MatrixSizeError.cpp RowElementItr.cpp ColItr.h MatrixError.h MatrixSizeError.h RowElementItr.h)
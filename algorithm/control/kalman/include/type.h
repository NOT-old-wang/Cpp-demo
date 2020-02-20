#ifndef KALMAN_INCLUDE_TYPES_H_
#define KALMAN_INCLUDE_TYPES_H_

#include "Matrix.hpp"

namespace Kalman {
// N * N 的协方差矩阵
template <typename T, int N>
using SquareMatrix = Matrix<T, N, N>;

/**
 * @class Kalman::Covariance
 * @brief Template type for covariance matrices
 * @param Type The vector type for which to generate a covariance (usually a
 * state or measurement type)
 */
template <class Type>
using Covariance = SquareMatrix<typename Type::Scalar, Type::RowsAtCompileTime>;

/**
 * @class Kalman::CovarianceSquareRoot
 * @brief Template type for covariance square roots
 * @param Type The vector type for which to generate a covariance (usually a
 * state or measurement type)
 */
template <class Type>
using CovarianceSquareRoot = Cholesky<Covariance<Type> >;

// 卡尔曼增益
template <class State, class Measurement>
using KalmanGain = Matrix<typename State::Scalar, State::RowsAtCompileTime,
                          Measurement::RowsAtCompileTime>;

// 雅克比矩阵
template <class A, class B>
using Jacobian =
    Matrix<typename A::Scalar, A::RowsAtCompileTime, B::RowsAtCompileTime>;
}  // namespace Kalman

#endif
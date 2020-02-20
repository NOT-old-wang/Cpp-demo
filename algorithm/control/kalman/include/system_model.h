#ifndef KALMAN_INCLUDE_SYSTEMMODEL_H_
#define KALMAN_INCLUDE_SYSTEMMODEL_H_

#include <type_traits>

#include "Matrix.hpp"
#include "StandardBase.hpp"

namespace Kalman {
/**
 * @brief Abstract base class of all system models
 *
 * @param StateType The vector-type of the system state (usually some type
 * derived from Kalman::Vector)
 * @param ControlType The vector-type of the control input (usually some type
 * derived from Kalman::Vector)
 * @param CovarianceBase The class template used for covariance storage (must be
 * either StandardBase or SquareRootBase)
 */
template <class StateType,
          class ControlType = Vector<typename StateType::Scalar, 0>,
          template <class> class CovarianceBase = StandardBase>
class SystemModel : public CovarianceBase<StateType> {
  static_assert(
      /*StateType::RowsAtCompileTime == Dynamic ||*/ StateType::
              RowsAtCompileTime > 0,
      "State vector must contain at least 1 element" /* or be dynamic */);
  static_assert(
      /*ControlType::RowsAtCompileTime == Dynamic ||*/ ControlType::
              RowsAtCompileTime >= 0,
      "Control vector must contain at least 0 elements" /* or be dynamic */);
  static_assert(std::is_same<typename StateType::Scalar,
                             typename ControlType::Scalar>::value,
                "State and Control scalar types must be identical");

 public:
  // 状态向量
  typedef StateType State;

  // 控制向量
  typedef ControlType Control;

 public:
  // 运动方程 --》 预测下一时刻的状态
  virtual State f(const State& x, const Control& u) const = 0;

 protected:
  SystemModel() {}
  virtual ~SystemModel() {}
};
}  // namespace Kalman

#endif
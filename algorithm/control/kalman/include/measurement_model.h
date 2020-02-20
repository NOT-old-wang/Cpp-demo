#ifndef KALMAN_MEASUREMENT_MODEL_H_
#define KALMAN_MEASUREMENT_MODEL_H_

#include <type_traits>

#include "standard_base.h"

namespace Kalman {
/**
 * @brief Abstract base class of all measurement models
 *
 * @param StateType The vector-type of the system state (usually some type
 * derived from Kalman::Vector)
 * @param MeasurementType The vector-type of the measurement (usually some type
 * derived from Kalman::Vector)
 * @param CovarianceBase The class template used for covariance storage (must be
 * either StandardBase or SquareRootBase)
 */
template <class StateType, class MeasurementType,
          template <class> class CovarianceBase = StandardBase>
class MeasurementModel : public CovarianceBase<MeasurementType> {
  static_assert(
      /*StateType::RowsAtCompileTime == Dynamic ||*/ StateType::
              RowsAtCompileTime > 0,
      "State vector must contain at least 1 element" /* or be dynamic */);
  static_assert(
      /*MeasurementType::RowsAtCompileTime == Dynamic ||*/ MeasurementType::
              RowsAtCompileTime > 0,
      "Measurement vector must contain at least 1 element" /* or be dynamic */);
  static_assert(std::is_same<typename StateType::Scalar,
                             typename MeasurementType::Scalar>::value,
                "State and Measurement scalar types must be identical");

 public:
  //! System state type
  typedef StateType State;

  //! Measurement vector type
  typedef MeasurementType Measurement;

 public:
  /**
   * Measurement Model Function h
   *
   * Predicts the estimated measurement value given the current state estimate x
   */
  virtual Measurement h(const State& x) const = 0;

 protected:
  MeasurementModel() {}
  virtual ~MeasurementModel() {}
};
}  // namespace Kalman

#endif

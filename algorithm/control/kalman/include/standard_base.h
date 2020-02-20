#ifndef KALMAN_INCLUDE_STANDARDBASE_H_
#define KALMAN_INCLUDE_STANDARDBASE_H_

#include "types.h"

namespace Kalman {

/**
 * @brief Abstract base class for standard (non-square root) filters and models
 *
 * @param StateType The vector-type of the system state (usually some type
 * derived from Kalman::Vector)
 */
template <class StateType>
class StandardBase {
 protected:
  //! Covariance
  Covariance<StateType> P;

 public:
  /**
   * Get covariance
   */
  const Covariance<StateType>& getCovariance() const { return P; }

  /**
   * Get covariance (as square root)
   */
  CovarianceSquareRoot<StateType> getCovarianceSquareRoot() const {
    return CovarianceSquareRoot<StateType>(P);
  }

  /**
   * Set Covariance
   */
  bool setCovariance(const Covariance<StateType>& covariance) {
    P = covariance;
    return true;
  }

  /**
   * @brief Set Covariance using Square Root
   *
   * @param covSquareRoot Lower triangular Matrix representing the covariance
   *                      square root (i.e. P = LLˆT)
   */
  bool setCovarianceSquareRoot(const Covariance<StateType>& covSquareRoot) {
    CovarianceSquareRoot<StateType> S;
    S.setL(covSquareRoot);
    P = S.reconstructedMatrix();
    return true;
  }

 protected:
  StandardBase() { P.setIdentity(); }
};
}  // namespace Kalman

#endif

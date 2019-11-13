#include <Arduino.h>
#include <Eigen.h>
#include <Eigen/Dense>
#include <math.h>
#include <Streaming.h>


class KalmanFilter
{
public:
  KalmanFilter(float E_MEA, float E_EST, float Q);
  
  void setMeasurementError(float E_MEA);
  void setEstimateError(float E_EST);
  void setProcessNoise(float Q);
  
  float updateEstimate(float MEA);
  float getKalmanGain();
  float getEstimateError();

private:
  float _INT_MEA; // intial measurement
  float _INT_EST; // intial estimate
  float _KG;      // kalman gain
  float _Q;       // process noise

  float _err_measure;
  float _err_estimate;
  float _q;
  float _current_estimate;
  float _last_estimate;
};

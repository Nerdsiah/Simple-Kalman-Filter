#include "KalmanFilter.h"


KalmanFilter::KalmanFilter(float E_MEA, float E_EST, float Q)
{
  _err_estimate = E_EST; 
  _err_measure = E_MEA;   
  _Q = Q;
}

float KalmanFilter::updateEstimate(float MEA)
{
  _KG = _err_estimate / (_err_estimate + _err_measure);
  _current_estimate = _INT_EST + _KG * (MEA - _INT_EST);
  _err_estimate =  (1.0 - _KG) * _err_estimate + fabs(_last_estimate - _current_estimate) * _Q;
  
  _last_estimate = _current_estimate;
  _INT_EST = _last_estimate;

  return _current_estimate;
}

#include <Wire.h>
#include "KalmanFilter.h"
#include "compass.h"


/*
 SimpleKalmanFilter(E_MEA, e_est, INT_MEA);
 E_MEA: Measurement Uncertainty 
 E_EST: Estimation Uncertainty 
 INT_MEA; Initial Measurement
*/

KalmanFilter simpleKalmanFilter(4, 2, 0.01);

// Serial output refresh time
const long SERIAL_REFRESH_TIME = 100;
long refresh_time;

float real_value;
float measured_value;
float estimated_value;

void setup() 
{
  Serial.begin(115200);

  Wire.begin();

  compass_x_offset = 122.17;
  compass_y_offset = 230.08;
  compass_z_offset = 389.85;
  compass_x_gainError = 1.12;
  compass_y_gainError = 1.13;
  compass_z_gainError = 1.03;

  compass_init(2);
}

void loop() 
{
  compass_heading();
  
  // add a noise to the reference value and use as the measured value
  measured_value = heading;

  // calculate the estimated value with Kalman Filter
  estimated_value = simpleKalmanFilter.updateEstimate(measured_value);

  // send to Serial output every 100ms
  // use the Serial Ploter for a good visualization
  if (millis() > refresh_time) {
    Serial.print(measured_value, 2);
    Serial.print(",");
    Serial.print(estimated_value, 2);
    Serial.println();
    
    refresh_time = millis() + SERIAL_REFRESH_TIME;
  }
}

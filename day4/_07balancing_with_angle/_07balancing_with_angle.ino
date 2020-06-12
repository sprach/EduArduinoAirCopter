#include <MPU6050Sensor.h>

MPU6050Sensor Sensor;

void setup() {  
  Sensor.begin(0x68);
  Serial.begin(115200);
}

void loop() {
  float roll_angle, pitch_angle, yaw_angle;
  Sensor.read_rpy_angle(roll_angle, pitch_angle, yaw_angle);  

  float roll_balancing, pitch_balancing, yaw_balancing;
  float roll_target_angle=0, pitch_target_angle=0, yaw_target_angle=0;
  calc_balancing_with_angle(
    roll_target_angle, pitch_target_angle, yaw_target_angle,
    roll_angle, pitch_angle, yaw_angle,
    roll_balancing, pitch_balancing, yaw_balancing);
  
  print_rpy_balancing(
    roll_angle, pitch_angle, yaw_angle,
    roll_balancing, pitch_balancing, yaw_balancing);
}

void calc_balancing_with_angle(float roll_target_angle, 
                              float pitch_target_angle, 
                              float yaw_target_angle,
                              float roll_angle, 
                              float pitch_angle, 
                              float yaw_angle,
                              float &roll_balancing, 
                              float &pitch_balancing, 
                              float &yaw_balancing) {
  
  roll_balancing = roll_target_angle - roll_angle;
  pitch_balancing = pitch_target_angle - pitch_angle;
  yaw_balancing = yaw_target_angle - yaw_angle;
}

void print_rpy_balancing(float roll_angle, 
                              float pitch_angle, 
                              float yaw_angle,
                              float roll_balancing, 
                              float pitch_balancing, 
                              float yaw_balancing) {

  Serial.print("#RPY:");
  Serial.print(roll_angle);
  Serial.print(",");
  Serial.print(pitch_angle);
  Serial.print(",");
  Serial.print(yaw_angle);
  
  Serial.print("#BAL:");
  Serial.print(roll_balancing);
  Serial.print(",");
  Serial.print(pitch_balancing);
  Serial.print(",");
  Serial.print(yaw_balancing);
  
  Serial.println();
}

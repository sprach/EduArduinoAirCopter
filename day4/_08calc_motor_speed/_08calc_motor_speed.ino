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

  float throttle = 100; 
  float motorA_speed, motorB_speed, motorC_speed, motorD_speed;
  calc_motor_speed(
    throttle, roll_balancing, pitch_balancing, yaw_balancing,
    motorA_speed, motorB_speed, motorC_speed, motorD_speed);
  
  print_motor_speed(
    roll_angle, pitch_angle, yaw_angle,
    roll_balancing, pitch_balancing, yaw_balancing,
    motorA_speed, motorB_speed, motorC_speed, motorD_speed);
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

void print_motor_speed(float roll_angle, 
                              float pitch_angle, 
                              float yaw_angle,
                              float roll_balancing, 
                              float pitch_balancing, 
                              float yaw_balancing,
                              float motorA_speed,
                              float motorB_speed, 
                              float motorC_speed,
                              float motorD_speed) {
                                
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

  Serial.print("#A:");
  Serial.print(motorA_speed);
  Serial.print("#B:");
  Serial.print(motorB_speed);
  Serial.print("#C:");
  Serial.print(motorC_speed);
  Serial.print("#D:");
  Serial.print(motorD_speed);
  
  Serial.println();
}

void calc_motor_speed(float throttle,
                      float roll_balancing,
                      float pitch_balancing, 
                      float yaw_balancing,
                      float &motorA_speed,
                      float &motorB_speed, 
                      float &motorC_speed,
                      float &motorD_speed) {
                        
  motorA_speed = 
    throttle + yaw_balancing + roll_balancing + pitch_balancing;
  motorB_speed = 
    throttle - yaw_balancing - roll_balancing + pitch_balancing;
  motorC_speed = 
    throttle + yaw_balancing - roll_balancing - pitch_balancing;
  motorD_speed = 
    throttle - yaw_balancing + roll_balancing - pitch_balancing;
    
  if(motorA_speed < 0) motorA_speed = 0; 
  if(motorA_speed > 255) motorA_speed = 255;
  if(motorB_speed < 0) motorB_speed = 0; 
  if(motorB_speed > 255) motorB_speed = 255;
  if(motorC_speed < 0) motorC_speed = 0; 
  if(motorC_speed > 255) motorC_speed = 255;
  if(motorD_speed < 0) motorD_speed = 0; 
  if(motorD_speed > 255) motorD_speed = 255;
}


#include <MPU6050Sensor.h>

MPU6050Sensor Sensor;

void setup() {  
  Sensor.begin(0x68); 
  Serial.begin(115200); 
}

void loop() {
  float roll_angle, pitch_angle, yaw_angle;
  Sensor.read_rpy_angle(roll_angle, pitch_angle, yaw_angle);

  print_rpy_angle(roll_angle, pitch_angle, yaw_angle);  
}

void print_rpy_angle(float roll_angle, 
                      float pitch_angle,
                      float yaw_angle) {
                        
  Serial.print("#RPY:");
  Serial.print(roll_angle, 2);
  Serial.print(",");
  Serial.print(pitch_angle, 2);
  Serial.print(",");
  Serial.print(yaw_angle, 2);
  
  Serial.println();
}

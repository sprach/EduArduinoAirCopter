#include <HM10BLE.h>

#define THROTTLE_INI 5

HM10BLE Ble;

void setup() {
  Ble.begin(115200);

  init_motor_speed(THROTTLE_INI);
}

void loop() {
  int roll, pitch, yaw, throttle;
  Ble.receive_user_rpyt(roll, pitch, yaw, throttle);

  update_motor_speed(throttle); 
}

int motorA_pin = 6;
int motorB_pin = 10;
int motorC_pin = 9;
int motorD_pin = 5;

void init_motor_speed(int speed) {
  analogWrite(motorA_pin, speed);  
  analogWrite(motorB_pin, speed);  
  analogWrite(motorC_pin, speed);  
  analogWrite(motorD_pin, speed);  
}

void update_motor_speed(int speed) {
  analogWrite(motorA_pin, speed);
  analogWrite(motorB_pin, speed);
  analogWrite(motorC_pin, speed);
  analogWrite(motorD_pin, speed);
}

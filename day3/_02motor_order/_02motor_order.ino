void setup() {}

void loop() {
  analogWrite( 6, 10); delay(1000);
  analogWrite(10, 10); delay(1000);
  analogWrite( 9, 10); delay(1000);
  analogWrite( 5, 10); delay(5000);
  
  analogWrite( 6, 0);  
  analogWrite(10, 0);  
  analogWrite( 9, 0);  
  analogWrite( 5, 0); delay(2000);
}



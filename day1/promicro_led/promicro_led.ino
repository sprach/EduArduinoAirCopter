/*
The RX LED has a defined Arduino pin
The TX LED was not so lucky, we'll need to use pre-defined
macros (TXLED1, TXLED0) to control that.
(We could use the same macros for the RX LED too -- RXLED1, and RXLED0.)
 */
int RXLED = 17;
 
void setup()
{
  // Set RX LED as an output
  // TX LED is set as an output behind the scenes
  pinMode(RXLED, OUTPUT); 

  Serial.begin(9600);   //This pipes to the serial monitor
  while (!Serial) ;

  Serial.println("Ready...");
}
 
void loop()
{
  // set the LED on
  digitalWrite(RXLED, LOW);
  // TX LED는 미리 정의된 매크로 사용
  // TXLED0은 LED On
  TXLED0;
  // wait for a second
  delay(1000);

  // set the LED off
  digitalWrite(RXLED, HIGH);
  // TXLED1은 LED Off
  TXLED1;
  // wait for a second
  delay(1000);
}

int RXLED = 17;

void setup() {
  Serial.begin( 115200 ); // 시리얼 모니터 속도
  Serial1.begin( 115200 );     // 블루투스 시리얼 속도
  
  while (!Serial) ;
  while (!Serial1) ;
  
  Serial.println("Ready...");
  Serial1.println("Hello!");
}

void loop() {
  if ( Serial1.available() ) {
    // 블루투스에서 값이 있는 경우 읽는다.
    char cmd = (char) Serial1.read();
    Serial.print( "Command = " );
    Serial.println( cmd );

    switch ( cmd ) {
      case '1' :
        Serial.println( "Pressed ON key" );
        Serial1.println( "Pressed ON key" );
        // set the LED on
        digitalWrite(RXLED, LOW);
        break;
      case '2' :
        Serial.println( "Pressed OFF key" );
        Serial1.println( "Pressed OFF key" );
        // set the LED on
        digitalWrite(RXLED, HIGH);
        break;
      default :
        Serial.print( "Unknown command : " );
        Serial.print( cmd );
        Serial.println();
        Serial1.print( "Unknown command : " );
        Serial1.print( cmd );
        Serial1.println();
        break;
    }  // switch
  }  // if
}

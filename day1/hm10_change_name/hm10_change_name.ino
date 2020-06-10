String bleName = "AIR0031"; //바꾸고 싶은 이름으로 변경

void setup() {
  Serial.begin(115200); //USB 시리얼 포트

  //--------블루투스 설정----------------
  SlaveSet();  //블루투스 슬레이브로 설정
}

void loop() {
  Serial.println("ok");
  delay(2000);
}

void SlaveSet(){
    Serial1.begin(115200); //통신속도 115200
    delay(1000);
    Serial1.write("AT+RENEW"); //설정 초기화
    delay(2000);
    Serial1.write("AT+RESET"); //리셋
    delay(1000);

    Serial1.begin(9600); //통신속도 9600
    delay(1000);
    Serial1.write("AT+RENEW"); //설정 초기화
    delay(2000);
    Serial1.write("AT+RESET"); //리셋
    delay(1000);

    Serial1.write("AT"); //AT
    delay(1000);
    Serial1.write("AT+BAUD4"); //통신속도 115200으로 변경
    delay(1000);
    Serial1.write("AT+RESET"); //리셋
    delay(1000);

    Serial1.begin(115200); //통신속도 115200
    delay(1000);

    Serial1.write("AT+NAME");   // 이름 설정
    Serial1.print(bleName);
    delay(1000);
    
    Serial1.write("AT+RESET"); //리셋
    delay(1000);
}

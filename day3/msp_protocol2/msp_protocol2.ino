// ASCII Table
// https://blog.sweetchip.kr/271

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(115200);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  static uint8_t cnt_msg;
  
  if (Serial1.available() > 0) {
    while (Serial1.available() > 0) {
      uint8_t msp_data = Serial1.read();

      if (msp_data == '$') cnt_msg = 0;
      else cnt_msg++;

      if (cnt_msg >= 4 && cnt_msg <= 8) {
        if (cnt_msg == 4) Serial.print("Type=");
        else if (cnt_msg == 5) Serial.print(" | R=");
        else if (cnt_msg == 6) Serial.print(" | P=");
        else if (cnt_msg == 7) Serial.print(" | Y=");
        else if (cnt_msg == 8) Serial.print(" | T=");

        Serial.print(msp_data);
        if (cnt_msg == 8) Serial.println();
      }
    }
  }
}

// ASCII Table
// https://blog.sweetchip.kr/271

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(115200);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial1.available() > 0) {
    while (Serial1.available() > 0) {
        uint8_t msp_data = Serial1.read();

        Serial.print((char)msp_data); // Ascii
        Serial.print('\t');
        Serial.print(msp_data, HEX);  // 16진수
        Serial.print('\t');
        Serial.print(msp_data, DEC);  // 10진수
        Serial.println();
    }
  }
}

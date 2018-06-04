#include "M4Stack.h"

void setup() {
  // put your setup code here, to run once:
  M4.begin();
}

void loop() {

  // put your main code here, to run repeatedly:
    if(M4.BtnA.wasPressed()) {
    //M5.Lcd.printf("wasPressed A \r\n");
    Serial.printf("wasPressed A \r\n");
  }

  if(M4.BtnA.wasReleased()) {
    //M5.Lcd.printf("wasReleased A \r\n");
    Serial.printf("wasReleased A \r\n");
  }

  if(M4.BtnA.pressedFor(2000)) {
    //M5.Lcd.printf("pressedFor 2s A \r\n");
    Serial.printf("pressedFor 2s A \r\n");
  }
  if(M4.BtnB.wasPressed()) {
    //M5.Lcd.printf("wasPressed B \r\n");
    Serial.printf("wasPressed B \r\n");
  }

  if(M4.BtnB.wasReleased()) {
    //M5.Lcd.printf("wasReleased B \r\n");
    Serial.printf("wasReleased B \r\n");
  }

  if(M4.BtnB.pressedFor(2000)) {
    //M5.Lcd.printf("pressedFor 2s B \r\n");
    Serial.printf("pressedFor 2s B \r\n");
  }

  if(M4.BtnC.wasPressed()) {
    //M5.Lcd.printf("wasPressed C \r\n");
    Serial.printf("wasPressed C \r\n");
  }

  if(M4.BtnC.wasReleased()) {
    //M5.Lcd.printf("wasReleased C \r\n");
    Serial.printf("wasReleased C \r\n");
  }

  if(M4.BtnC.pressedFor(2000)) {
    //5.Lcd.printf("pressedFor 2s C \r\n");
    Serial.printf("pressedFor 2s C \r\n");
  }
   M4.update();
}

#include "M4Stack.h"


void M4Stack::begin() {
    
    // UART 
    Serial.begin(115200);
    Serial.flush();
    Serial.print("T10 Button test");



    // Setup the button with an internal pull-up
    pinMode(BUTTON_A_PIN, INPUT_PULLUP);
    pinMode(BUTTON_B_PIN, INPUT_PULLUP);
    pinMode(BUTTON_C_PIN, INPUT_PULLUP);



    // Set wakeup button
//    setWakeupButton(BUTTON_A_PIN);

    // MPU9250
#ifdef MPU9250_INSDE
    Wire.begin();
#endif

    Serial.println("OK");
}

void M4Stack::update() {

    //Button update
    BtnA.read();
    BtnB.read();
    BtnC.read();

    //Speaker update
}



void M4Stack::setWakeupButton(uint8_t button) {
    _wakeupPin = button;
}



M4Stack M4;


//#ifndef _M4STACK_H_
//#define _M4STACK_H_

#if defined(ESP32)
#include <Arduino.h>
#include "Config.h"
#include "Button.h"
//#include DEBOUNCE_MS 5

class M4Stack {

 public:
    void begin();
    void update();

    void setWakeupButton(uint8_t button);

    // Button API
    #define DEBOUNCE_MS 5
    Button BtnA = Button(BUTTON_A_PIN, true, DEBOUNCE_MS);
    Button BtnB = Button(BUTTON_B_PIN, true, DEBOUNCE_MS);
    Button BtnC = Button(BUTTON_C_PIN, true, DEBOUNCE_MS);

    // SPEAKER

 private:
    uint8_t _wakeupPin;
};

extern M4Stack M4;
#define m4 M4

#else
#error “This library only supports boards with ESP32 processor.”
#endif



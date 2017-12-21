// ESP32 + 1.44" TFT v2.1                                  // 2017.02.08 macsbug
// http://www.sipatechmeetup.com/media/uploads/arduinoesp32dev.pdf
#include <Adafruit_GFX.h>                                  // Core graphics library
#include <Adafruit_ST7735.h>                               // Hardware-specific library
Adafruit_ST7735 tft = Adafruit_ST7735(16, 17, 23, 5, 9); // CS,A0,SDA,SCK,RESET
float r, x1, ya, z1, x2, y2, z2, x3, y3, z3;               //
int f[8][2], x, y;                                         // Draw box, x, y center
int c[8][3] = {                                            // Cube
 {-20,-20, 20},{20,-20, 20},{20,20, 20},{-20,20, 20},
 {-20,-20,-20},{20,-20,-20},{20,20,-20},{-20,20,-20} };
 
void setup(void) {
  //Serial.begin(115200);
  tft.initR(INITR_18GREENTAB);                             // 1.44 v2.1
  tft.fillScreen(ST7735_BLACK);                            // CLEAR
  tft.setTextColor(0x5FCC);                                // GREEN
  tft.setRotation(1);                                      // 
  x = tft.width() /2; x = x + 14;                          // x Center Calculate
  y = tft.height()/2;                                      // y Center Calculate
}
 
void loop(){
 for (int a = 0; a <= 360; a = a + 2 ) {                   // 0 to 360 degree
   for (int i = 0; i < 8; i++) {                           //
    r  = a * 0.0174532;                                    // 1 degree
    x1 = c[i][2] * sin(r) + c[i][0] * cos(r);              // rotate Y
    ya = c[i][1];                                          //
    z1 = c[i][2] * cos(r) - c[i][0] * sin(r);              //
    x2 = x1;                                               //
    y2 = ya * cos(r) - z1 * sin(r);                        // rotate X
    z2 = ya * sin(r) + z1 * cos(r);                        //
    x3 = x2 * cos(r) - y2 * sin(r);                        // rotate Z
    y3 = x2 * sin(r) + y2 * cos(r);                        //
    z3 = z2; x3 = x3 + x ; y3 = y3 + y ;                   //
    f[i][0] = x3; f[i][1] = y3; f[i][2] = z3;              // store new values
   }
   tft.fillScreen(ST7735_BLACK);
   tft.drawLine(f[0][0],f[0][1],f[1][0],f[1][1],ST7735_WHITE);
   tft.drawLine(f[1][0],f[1][1],f[2][0],f[2][1],ST7735_WHITE);
   tft.drawLine(f[2][0],f[2][1],f[3][0],f[3][1],ST7735_WHITE);
   tft.drawLine(f[3][0],f[3][1],f[0][0],f[0][1],ST7735_WHITE);
   tft.drawLine(f[4][0],f[4][1],f[5][0],f[5][1],ST7735_WHITE);
   tft.drawLine(f[5][0],f[5][1],f[6][0],f[6][1],ST7735_WHITE);
   tft.drawLine(f[6][0],f[6][1],f[7][0],f[7][1],ST7735_WHITE);
   tft.drawLine(f[7][0],f[7][1],f[4][0],f[4][1],ST7735_WHITE);
   tft.drawLine(f[0][0],f[0][1],f[4][0],f[4][1],ST7735_WHITE);
   tft.drawLine(f[1][0],f[1][1],f[5][0],f[5][1],ST7735_WHITE);
   tft.drawLine(f[2][0],f[2][1],f[6][0],f[6][1],ST7735_WHITE);
   tft.drawLine(f[3][0],f[3][1],f[7][0],f[7][1],ST7735_WHITE);
   tft.drawLine(f[1][0],f[1][1],f[3][0],f[3][1],ST7735_WHITE);// cross
   tft.drawLine(f[0][0],f[0][1],f[2][0],f[2][1],ST7735_WHITE);// cross
 }
}

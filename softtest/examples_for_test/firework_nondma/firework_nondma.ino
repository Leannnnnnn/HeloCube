#include <TimeLib.h>
#include <TFT_eSPI.h> 
#include <SPI.h>

#include "img/firework_img.h" 

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite clk = TFT_eSprite(&tft);

#include <TJpg_Decoder.h>

// This next function will be called during decoding of the jpeg file to
// render each block to the TFT.  If you use a different TFT library
// you will need to adapt this function to suit.
bool tft_output(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t* bitmap)
{
   // Stop further decoding as image is running off bottom of screen
  if ( y >= tft.height() ) return 0;

  // This function will clip the image block rendering automatically at the TFT boundaries
  tft.pushImage(x, y, w, h, bitmap);

  // This might work instead if you adapt the sketch to use the Adafruit_GFX library
  // tft.drawRGBBitmap(x, y, bitmap, w, h);

  // Return 1 to decode next block
  return 1;
}

void setup()
{

  // Initialise the TFT
  tft.init();
  tft.setRotation(2);
  tft.fillScreen(TFT_WHITE);
  tft.setTextColor(0xFFFF, 0x0000);

    //背光调节
  ledcSetup(0,5000,8);
  ledcAttachPin(22,0);
  ledcWrite(0,180);

  // The jpeg image can be scaled by a factor of 1, 2, 4, or 8
  TJpgDec.setJpgScale(1);

  // The byte order can be swapped (set true for TFT_eSPI)
  TJpgDec.setSwapBytes(true);

  // The decoder must be given the exact name of the rendering function above
  TJpgDec.setCallback(tft_output);
}

unsigned long oldTime = 0, imgNum = 1; 
int dt = 1;  //单帧100ms

void loop()
{

  // Time recorded for test purposes
  //uint32_t t = millis();

  // Get the width and height in pixels of the jpeg if you wish
  //uint16_t w = 0, h = 0;
  //TJpgDec.getJpgSize(&w, &h, test_img, sizeof(test_img));
  //Serial.print("Width = "); Serial.print(w); Serial.print(", height = "); Serial.println(h);

  if(millis() - oldTime >= dt) {
      imgNum = imgNum + 1;
      oldTime = millis();
    }
  switch(imgNum) {
    case 1: TJpgDec.drawJpg(0,0,img_0, sizeof(img_0));break;
    case 2: TJpgDec.drawJpg(0,0,img_1, sizeof(img_1));break;
    case 3: TJpgDec.drawJpg(0,0,img_2, sizeof(img_2));break;
    case 4: TJpgDec.drawJpg(0,0,img_3, sizeof(img_3));break;
    case 5: TJpgDec.drawJpg(0,0,img_4, sizeof(img_4));break;
    case 6: TJpgDec.drawJpg(0,0,img_5, sizeof(img_5));break;
    case 7: TJpgDec.drawJpg(0,0,img_6, sizeof(img_6));break;
    case 8: TJpgDec.drawJpg(0,0,img_7, sizeof(img_7));break;
    case 9: TJpgDec.drawJpg(0,0,img_8, sizeof(img_8));break;
    case 10: TJpgDec.drawJpg(0,0,img_9, sizeof(img_9));break;
    case 11: TJpgDec.drawJpg(0,0,img_10, sizeof(img_10));break;
    case 12: TJpgDec.drawJpg(0,0,img_11, sizeof(img_11));break;
    case 13: TJpgDec.drawJpg(0,0,img_12, sizeof(img_12));break;
    case 14: TJpgDec.drawJpg(0,0,img_13, sizeof(img_13));break;
    case 15: TJpgDec.drawJpg(0,0,img_14, sizeof(img_14));break;
    case 16: TJpgDec.drawJpg(0,0,img_15, sizeof(img_15));break;
    case 17: TJpgDec.drawJpg(0,0,img_16, sizeof(img_16));break;
    case 18: TJpgDec.drawJpg(0,0,img_17, sizeof(img_17));break;
    case 19: TJpgDec.drawJpg(0,0,img_18, sizeof(img_18));break;
    case 20: TJpgDec.drawJpg(0,0,img_19, sizeof(img_19));break;
    case 21: TJpgDec.drawJpg(0,0,img_20, sizeof(img_20));break;
    case 22: TJpgDec.drawJpg(0,0,img_21, sizeof(img_21));break;
    case 23: TJpgDec.drawJpg(0,0,img_22, sizeof(img_22));break;
    case 24: TJpgDec.drawJpg(0,0,img_23, sizeof(img_23));break;
    case 25: TJpgDec.drawJpg(0,0,img_24, sizeof(img_24));break;
    case 26: TJpgDec.drawJpg(0,0,img_25, sizeof(img_25));break;
    case 27: TJpgDec.drawJpg(0,0,img_26, sizeof(img_26));break;
    case 28: TJpgDec.drawJpg(0,0,img_27, sizeof(img_27));break;
    case 29: TJpgDec.drawJpg(0,0,img_28, sizeof(img_28));break;
    case 30: TJpgDec.drawJpg(0,0,img_29, sizeof(img_29));break;
    case 31: TJpgDec.drawJpg(0,0,img_30, sizeof(img_30));break;
    case 32: TJpgDec.drawJpg(0,0,img_31, sizeof(img_31));break;
    case 33: TJpgDec.drawJpg(0,0,img_32, sizeof(img_32));break;
    case 34: TJpgDec.drawJpg(0,0,img_33, sizeof(img_33));break;
    case 35: TJpgDec.drawJpg(0,0,img_34, sizeof(img_34));break;
    case 36: TJpgDec.drawJpg(0,0,img_35, sizeof(img_35));break;
    case 37: TJpgDec.drawJpg(0,0,img_36, sizeof(img_36));break;
    case 38: TJpgDec.drawJpg(0,0,img_37, sizeof(img_37));break;
    case 39: TJpgDec.drawJpg(0,0,img_38, sizeof(img_38));break;
    case 40: TJpgDec.drawJpg(0,0,img_39, sizeof(img_39));break;
    case 41: TJpgDec.drawJpg(0,0,img_40, sizeof(img_40));break;
    case 42: TJpgDec.drawJpg(0,0,img_41, sizeof(img_41));break;
    case 43: TJpgDec.drawJpg(0,0,img_42, sizeof(img_42));imgNum=1;break;
  }
  // Draw the image, top left at 0,0
  //TJpgDec.drawJpg(0, 0, firework, sizeof(test_img));

  // How much time did rendering take (ESP8266 80MHz 262ms, 160MHz 149ms, ESP32 SPI 111ms, 8bit parallel 90ms
  //t = millis() - t;
  //Serial.print(t); Serial.println(" ms");

  // Wait before drawing again
  //delay(2000);
}
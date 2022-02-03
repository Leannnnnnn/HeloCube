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
  tft.pushImage(x, y, w, h, bitmap);   //调用了TFT_eSPI中的显示图像函数

  // This might work instead if you adapt the sketch to use the Adafruit_GFX library
  // tft.drawRGBBitmap(x, y, bitmap, w, h);

  // Return 1 to decode next block
  return 1;
}

void setup()
{

  // Initialise the TFT
  tft.init();
  tft.setRotation(2);  //设置屏幕旋转：0：0°，1：90°，2：180°，3：270°
  tft.fillScreen(TFT_WHITE);
  tft.setTextColor(0xFFFF, 0x0000);

    //背光PWM调节
  ledcSetup(0,5000,8);
  ledcAttachPin(22,0);
  ledcWrite(0,180);

  // The jpeg image can be scaled by a factor of 1, 2, 4, or 8
  TJpgDec.setJpgScale(1);

  // The byte order can be swapped (set true for TFT_eSPI)
  TJpgDec.setSwapBytes(true);

  // The decoder must be given the exact name of the rendering function above
  TJpgDec.setCallback(tft_output);  //绑定自定义的output回调函数，用于解码库显示图像时调用
}

void loop()
{

  //该函数获取JPG数组地址，完成解码后将调用output显示在屏幕
  TJpgDec.drawJpg(0,0,img_0, sizeof(img_0));  // Draw the image, top left at 0,0

  // Wait before drawing again
  delay(2000);
}
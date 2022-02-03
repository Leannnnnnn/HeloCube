#include <TimeLib.h>
#include <TFT_eSPI.h> 
#include <SPI.h>
#include <TJpg_Decoder.h>

#include "img/firework_img.h" 

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite clk = TFT_eSprite(&tft);


uint16_t  PROGMEM dmaBuffer1[32*32]; // Toggle buffer for 32*32 MCU block, 1024bytes
uint16_t  PROGMEM dmaBuffer2[32*32]; // Toggle buffer for 32*32 MCU block, 1024bytes
uint16_t* dmaBufferPtr = dmaBuffer1;
bool dmaBufferSel = 0;

// This next function will be called during decoding of the jpeg file to
// render each block to the TFT.  If you use a different TFT library
// you will need to adapt this function to suit.
bool tft_output(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t* bitmap)
{
  if ( y >= tft.height() ) return 0;
 
  // Double buffering is used, the bitmap is copied to the buffer by pushImageDMA() the
  // bitmap can then be updated by the jpeg decoder while DMA is in progress
  if (dmaBufferSel) dmaBufferPtr = dmaBuffer2;
  else dmaBufferPtr = dmaBuffer1;
  dmaBufferSel = !dmaBufferSel; // Toggle buffer selection
  //  pushImageDMA() will clip the image block at screen boundaries before initiating DMA
  tft.pushImageDMA(x, y, w, h, bitmap, dmaBufferPtr); // Initiate DMA - blocking only if last DMA is not complete
  return 1;
}

void setup()
{

  // Initialise the TFT
  tft.begin();
  tft.initDMA();
  tft.setRotation(2);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(0xFFFF, 0x0000);

    //背光调节
  ledcSetup(0,5000,8);
  ledcAttachPin(22,0);
  ledcWrite(0,220);

  // The jpeg image can be scaled by a factor of 1, 2, 4, or 8
  TJpgDec.setJpgScale(1);

  // The byte order can be swapped (set true for TFT_eSPI)
  TJpgDec.setSwapBytes(true);

  // The decoder must be given the exact name of the rendering function above
  TJpgDec.setCallback(tft_output);
}

unsigned long oldTime = 0, imgNum = 0; 
int dt = 90;  //单帧100ms

void loop()
{

  // Time recorded for test purposes
  //uint32_t t = millis();

  // Get the width and height in pixels of the jpeg if you wish
  //uint16_t w = 0, h = 0;
  //TJpgDec.getJpgSize(&w, &h, test_img, sizeof(test_img));
  //Serial.print("Width = "); Serial.print(w); Serial.print(", height = "); Serial.println(h);



  tft.startWrite();//必须先使用startWrite，以便TFT芯片选择保持低的DMA和SPI通道设置保持配置
  //TJpgDec.drawJpg(0,0,firework_img[imgNum], sizeof(firework_img[imgNum]));//在左上角的0,0处绘制图像——在这个草图中，DMA请求在回调tft_output()中处理
  //tft.endWrite();//必须使用endWrite来释放TFT芯片选择和释放SPI通道吗
  //memset(&img_buff,0,sizeof(img_buff));//清空buff
    

if(millis() - oldTime >= dt) {
      imgNum = imgNum + 1;
      oldTime = millis();
    
  switch(imgNum) {
    case 1: TJpgDec.drawJpg(0,0,img_0, sizeof(img_0));
            delay(4000);
            break;
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
    case 43: TJpgDec.drawJpg(0,0,img_42, sizeof(img_42));
              imgNum=0;
              delay(3000);
              break;
    }
  }  
  // Draw the image, top left at 0,0
  //TJpgDec.drawJpg(0, 0, firework, sizeof(test_img));
}





/*
TJpgDec.drawJpg(0,0,img_0, sizeof(img_0));
    TJpgDec.drawJpg(0,0,img_1, sizeof(img_1));
    TJpgDec.drawJpg(0,0,img_2, sizeof(img_2));
    TJpgDec.drawJpg(0,0,img_3, sizeof(img_3));
    TJpgDec.drawJpg(0,0,img_4, sizeof(img_4));
    TJpgDec.drawJpg(0,0,img_5, sizeof(img_5));
    TJpgDec.drawJpg(0,0,img_6, sizeof(img_6));
    TJpgDec.drawJpg(0,0,img_7, sizeof(img_7));
    TJpgDec.drawJpg(0,0,img_8, sizeof(img_8));
    TJpgDec.drawJpg(0,0,img_9, sizeof(img_9));
    TJpgDec.drawJpg(0,0,img_10, sizeof(img_10));


*/
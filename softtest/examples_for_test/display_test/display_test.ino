#include <TimeLib.h>
#include <TFT_eSPI.h> 
#include <SPI.h>

#include "font/ZdyLwFont_20.h"

/*
#include "img/main_img/main_img.h"
#include "img/taikongren/i0.h"
#include "img/taikongren/i1.h"
#include "img/taikongren/i2.h"
#include "img/taikongren/i3.h"
#include "img/taikongren/i4.h"
#include "img/taikongren/i5.h"
#include "img/taikongren/i6.h"
#include "img/taikongren/i7.h"
#include "img/taikongren/i8.h"
#include "img/taikongren/i9.h"
#include "img/setWiFi_img.h"
*/



TFT_eSPI tft = TFT_eSPI();
TFT_eSprite clk = TFT_eSprite(&tft);
uint16_t bgColorB = 0x0000;  //黑色背景
uint16_t bgColorW = 0xffff;  //白色背景
uint16_t transp_0 = 0x0000;  //不透明
uint16_t transp_ff = 0xffff; //透明
uint16_t oldTime = 0;
uint16_t flagx = 0;
uint16_t flagy = 0;
uint16_t locatex = 40;
uint16_t locatey = 10;

void setup() {
   tft.init();
   tft.setRotation(2);
   tft.fillScreen(TFT_WHITE);

   //背光调节
   ledcSetup(0,5000,8);
   ledcAttachPin(22,0);
   ledcWrite(0,180);
}

void loop() {
   /*绘制文字*/
   clk.setColorDepth(8);
   clk.loadFont(ZdyLwFont_20);
   clk.createSprite(84,24);

   if(millis() - oldTime>=40){
      oldTime = millis();
      if(flagx == 0){
         ++locatex;
         if(locatex==160)
            flagx = 1;
      }
      if(flagx == 1){
         --locatex;
         if(locatex == 0)
            flagx = 0;
      }

      if(flagy == 0){
         ++locatey;
         if(locatey==220)
            flagy = 1;
      }
      if(flagy == 1){
         --locatey;
         if(locatey == 0)
            flagy = 0;
      }
   }
   clk.fillSprite(bgColorW);  //背景
   clk.setTextDatum(CC_DATUM);
   clk.setTextColor(TFT_RED,TFT_WHITE);
   clk.drawString("新年快乐",42,12);  //sprite中心坐标
   clk.pushSprite(locatex,locatey); //左上角位置
   clk.deleteSprite();

   //clk.deleteSprite();
   //clk.unloadFont();

}

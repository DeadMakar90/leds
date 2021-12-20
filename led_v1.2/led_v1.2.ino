#include <FastLED.h>

#define NUM_LEDS 30  //Количество диодов в ленте
#define DATA_PIN 3   //Пин управления
#define COLOR_ORDER GRB //Цветовая схема ленты.
#define CHIPSET WS2813 //Модель диодов
#define BUTTON 5
int mode = 0;
boolean buttonWasUp = true;
CRGB leds[NUM_LEDS];  //Массив с размером = количеству диодов

void setup(){
pinMode(BUTTON,INPUT_PULLUP);
FastLED.addLeds<CHIPSET,DATA_PIN,COLOR_ORDER>(leds,NUM_LEDS); 
FastLED.clear();
FastLED.show();

}

void loop(){ 

if (buttonWasUp && !digitalRead(BUTTON)) {
    delay(10);
    if (!digitalRead(BUTTON))
      mode = (mode + 1);

switch (mode)
{
case 1:
    for (int i = 0; i < NUM_LEDS; i++)
    {
        leds[i] = CRGB :: Red;
        FastLED.show();
        delay(100);
    }
      for (int i = NUM_LEDS; i > 0; i++)
    {
        leds[i] = CRGB :: Green;
        FastLED.show();
        delay(100);
    }
    break;
case 2: 
     leds[0] = CRGB::GreenYellow;
     FastLED.show();
     delay(1000);
     leds[1] = CRGB::Indigo;
     FastLED.show();
     delay(100);
     break;
default:
    break;
  }
 }
}
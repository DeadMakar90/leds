#include <GyverButton.h>
#include <FastLED.h>


#define NUM_LEDS 30  //Количество диодов в ленте
#define DATA_PIN 3   //Пин управления
#define COLOR_ORDER GRB //Цветовая схема ленты.
#define CHIPSET WS2813 //Модель диодов
#define BUTTON 5
int mode = 0;
CRGB leds[NUM_LEDS];  //Массив с размером = количеству диодов
GButton butt1(BUTTON);

void setup(){
butt1.setDebounce(90);  
FastLED.addLeds<CHIPSET,DATA_PIN,COLOR_ORDER>(leds,NUM_LEDS); 
FastLED.clear();
FastLED.show();
}
void pin_ISR(){
    mode++;
    if (mode >=3){
        mode = 0;
    }
}

void loop(){ 
    switch(mode){
        case 1: 
        for ( int i = 0; i < NUM_LEDS; i++)
        {
            leds[i]=CRGB::Aqua;
            FastLED.show();
            delay(100);
        }
        for (int i = NUM_LEDS; i >=0 ; i--)
        {
            leds[i]=CRGB::Yellow;
            FastLED.show();
            delay(100);
        }
        break;
        case 2: 
             for (int i = 0; i < NUM_LEDS; i++)
        {
            leds[i]=CRGB::Red;
            FastLED.show();
            delay(100);
        }
        for (int i = NUM_LEDS; i >=0 ; i--)
        {
            leds[i]=CRGB::Green;
            FastLED.show();
            delay(100);
        }
        break;
        default:
         leds[0]=CRGB::Blue;
         FastLED.show();
         delay(100);
         leds[0]=CRGB::Black;
         FastLED.show();
         delay(100);
        break;
    }

}
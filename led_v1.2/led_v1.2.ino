#include <GyverButton.h>
#include <FastLED.h>


#define NUM_LEDS 30  //Количество диодов в ленте
#define DATA_PIN 3   //Пин управления
#define COLOR_ORDER GRB //Цветовая схема ленты.
#define CHIPSET WS2813 //Модель диодов
#define BUTTON 5       //Пин кнопки
byte mode = 1;         //Режим
CRGB leds[NUM_LEDS];  //Массив с размером = количеству диодов
//static byte tempButton = LOW;
//static byte button = LOW;

void setup(){
pinMode(BUTTON, INPUT); 
FastLED.addLeds<CHIPSET,DATA_PIN,COLOR_ORDER>(leds,NUM_LEDS); 
FastLED.clear();
FastLED.show();
}

void loop(){

  button = digitalRead(BUTTON);
  if (tempButton && !button)
  {
  // Небольшой анти дребезг.
    tempButton = button;
    delay(10);
    button = digitalRead(BUTTON);
    // Все хорошо, меняем эффект.
    if (button == tempButton)
    {
      // Переключаем на следующий эффект.
      mode++;
      if (mode > 3) mode = 1; // Зацикливаем эффекты по кругу.
    }
    //tempButton = button;
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

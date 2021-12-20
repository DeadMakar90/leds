#include <FastLED.h>


#define NUM_LEDS 30 
#define DATA_PIN 3
#define COLOR_ORDER GRB
#define CHIPSET WS2813
byte counter;
CRGB leds[NUM_LEDS];
void setup() {
FastLED.addLeds<CHIPSET, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
FastLED.clear();
FastLED.show();
}

/*void loop() {
leds[0] = CRGB::Red;
FastLED.show();
delay(1000);
leds[0] = CRGB::Black;
FastLED.show();
delay(1000);
leds[1] = CRGB::Orange;
FastLED.show();
delay(1000);
leds[1] = CRGB::Black;
FastLED.show();
delay(1000);
} */
/*void loop(){
    for (int i = 0; i < NUM_LEDS; i++)
    {
        leds[i]= CRGB::Green ;
        FastLED.show();
        delay(100);
        if (i > 0){
          FastLED.clear();
        }
    }
       for (int i = NUM_LEDS; i >= 0; i--)
    {
        leds[i]= CRGB::Orange ;
        FastLED.show();
        delay(100);
        if (i > 0){
          FastLED.clear();
        }
    }
} /*
/*void loop(){
 for (int i = 0; i < NUM_LEDS; i++ ) {         // от 0 до первой трети
    leds[i] = CHSV(counter + i * 2, 255, 255);  // HSV. Увеличивать HUE (цвет)
    // умножение i уменьшает шаг радуги
  }
  counter++;        // counter меняется от 0 до 255 (тип данных byte)
  FastLED.show();
  delay(5);  

} */


void loop(){
  int half = NUM_LEDS/2;
  for (int i = 0; i < half ; i++){
   
    leds[i]=CRGB::Red;
    FastLED.show();
    delay(100);
    }
    for (int i = half; i < NUM_LEDS; i++){
    leds[i]=CRGB::Green;
    FastLED.show();
    delay(100);  
  }
  for (int i = NUM_LEDS;i> 0;i--){
    leds[i]=CRGB::Black;
    FastLED.show();
    delay(100); 
  }

}
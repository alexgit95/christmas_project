#include<FastLED.h>
#define DATA_PIN 6//PIN de controlle
#define NB_LEDS 133
#define NB_LEDS_SIMUL 30

CRGB leds[NB_LEDS];

void setup() { 
  FastLED.addLeds<NEOPIXEL,6>(leds, NB_LEDS); 
}

void loop(){
  EVERY_N_MILLISECONDS(200){
      for(int i=0;i<NB_LEDS_SIMUL;i++){
        int temp=rand()%(NB_LEDS-1);
        leds[temp].setRGB(255,255,255);
        leds[temp].fadeToBlackBy(180);
    }
    FastLED.show();
  }
}

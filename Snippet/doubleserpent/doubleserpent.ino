#include<FastLED.h>
 //DOUBLE SERPENT - AB 2018
#define DATA_PIN 6//PIN de controlle
#define NOMBRE_PIXEL 133//nombre de pixel sur la bande
#define DELAIS_ENTRE_MOUVEMENT 10//(en ms) plus le delais est long, plus le serpent va lentement
#define NB_ALLER_RETOUR 3//nombre d'aller retour avant de commencer une nouvelle boucle

CRGB leds[NOMBRE_PIXEL];
 


void setup() {
  delay(2000);//sanity check
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NOMBRE_PIXEL);
}

void loop() {
  doubleSnake(NB_ALLER_RETOUR,NOMBRE_PIXEL,DELAIS_ENTRE_MOUVEMENT);
}



void doubleSnake(int nbartot,int nbpixel,int delais){
  int nbar=0;//nombre d'aller retour en cours
  while(nbar<nbartot) {
    for(int i=0;i<NOMBRE_PIXEL;i++){
      //on eteint la led precedente
      leds[i-1]=CRGB::Black;
      //allumer i
      leds[i]=CRGB::White;
      //on eteint la led precedente
      leds[NOMBRE_PIXEL-i]=CRGB::Black;
      //allumer NOMBRE_PIXEL-1-i
      leds[NOMBRE_PIXEL-1-i]=CRGB::White;
      FastLED.show();
      
      delay(DELAIS_ENTRE_MOUVEMENT);
    }

    nbar++;
   }
}

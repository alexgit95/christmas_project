 #include<FastLED.h>
 #define DATA_PIN 6//PIN de controlle
 //SERPENT - AB 2018
 
const int NOMBRE_PIXEL=133;//nombre de pixel sur la bande
const int TAILLE_SERPENT=5;//longueur en pixel du serpent
const int DELAIS_ENTRE_MOUVEMENT=10;//(en ms) plus le delais est long, plus le serpent va lentement
const int NB_ALLER_RETOUR=3;//nombre d'aller retour avant de commencer une nouvelle boucle

CRGB leds[NOMBRE_PIXEL];

 
void setup() {
  // sanity check delay - allows reprogramming if accidently blowing power w/leds
  delay(2000);
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NOMBRE_PIXEL);

}

void loop() {
    
    int nbar=0;//nombre d'aller retour en cours
    int positiontete=TAILLE_SERPENT+1;
    boolean sensVersGauche=true;
    
    while(nbar<NB_ALLER_RETOUR) {
      
        if(positiontete==NOMBRE_PIXEL-TAILLE_SERPENT||positiontete==TAILLE_SERPENT) {
          if(!sensVersGauche) {
            nbar++;
          }
          sensVersGauche=!sensVersGauche;
        }
        if(sensVersGauche) {
          positiontete++;
           //On eteint position tete - taille serpent
           leds[positiontete-TAILLE_SERPENT]=CRGB::Wheat;     
          
        }else {
          positiontete--;
         //On eteint position tete + taille serpent
         leds[positiontete+TAILLE_SERPENT]=CRGB::Wheat;
        }
        //on allume position tete
        leds[positiontete-TAILLE_SERPENT]=CRGB::White;

        
        FastLED.show();
        delay(DELAIS_ENTRE_MOUVEMENT);
        
      
    }

}

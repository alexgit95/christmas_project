#include<FastLED.h>
#define DATA_PIN 6//PIN de controlle
#define NB_LEDS 133
#define NB_LEDS_SIMUL 15
#define VITESSE_DEFILEMENT 100



const int NOMBRE_PIXEL=133;//nombre de pixel sur la bande
const int TAILLE_SERPENT=5;//longueur en pixel du serpent
const int DELAIS_ENTRE_MOUVEMENT=10;//(en ms) plus le delais est long, plus le serpent va lentement
const int NB_ALLER_RETOUR=3;//nombre d'aller retour avant de commencer une nouvelle boucle

CRGB leds[NB_LEDS];

int statut2=HIGH;
int statut3=LOW;
int statut4=HIGH;

void setup() {
  Serial.begin(9600); 
  delay(1000);
  FastLED.addLeds<WS2811, DATA_PIN, BRG>(leds, NB_LEDS);
   /* FastLED.setTemperature( CoolWhiteFluorescent  );
    FastLED.setCorrection(TypicalLEDStrip );*/
  FastLED.setBrightness(150);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  
  
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  delay(1000);
}

void loop(){
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  Serial.println("Demarrage blanc chaud"); 
  blancchaud();
  delay(30000);
  Serial.println("Fin blanc chaud"); 
  Serial.println("Demarrage serpent"); 
  //SERPENT
  serpent();
  //FIN SERPENT
  Serial.println("Fin serpent"); 
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  FastLED.setBrightness(150);
  int nb=0;
  Serial.println("Demarrage mode sapin"); 
  // 2min = 600
  while(nb<150){
   sapincandy(0,100,nb);
   nb++;
   
  }
  extinction();
  allumage();
  Serial.println("Fin mode sapin"); 
  Serial.println("Demarrage mode candy cane"); 
  
  //2min 600
  nb=0;
  while(nb<150){
   sapincandy(1,100,nb);
  
  }
  extinction();
  allumage();
  Serial.println("Fin mode candy cane"); 
  Serial.println("Debut serpent");
  //SERPENT
  serpent();
  //FIN SERPENT
  Serial.println("Fin serpent");
  Serial.println("Debut double serpent");
  doubleSnake(5,NB_LEDS,10);
  Serial.println("Fin double serpent");
      
     
}


void sapincandy(int mode, int vitesse,int nb){
  int i=1;
      for(int i=0;i<NB_LEDS;i++){
        if(i%2==0){
          if(mode==0){
             leds[i].setRGB(0,255,0);
          }else{
             leds[i].setRGB(255,255,255);
          }
         
        }else{
          leds[i].setRGB(255,0,0);
        }
      }

      
         FastLED.show();
         delay(vitesse);

      for(int i=0;i<NB_LEDS;i++){
        if(i%2==1){
          if(mode==0){
             leds[i].setRGB(0,255,0);
          }else{
             leds[i].setRGB(255,255,255);
          }
        }else{
          leds[i].setRGB(255,0,0);
        }
      }

     if(nb%10==0){
        if(statut2==HIGH){
          digitalWrite(2, LOW);
          statut2=LOW;
      
       }else{
        digitalWrite(2, HIGH);
         statut2=HIGH;
       }
       if(statut3==HIGH){
          digitalWrite(3, LOW);
          statut3=LOW;
      
       }else{
        digitalWrite(3, HIGH);
        statut3=HIGH;
       }
       if(statut4==HIGH){
          digitalWrite(4, LOW);
          statut4=LOW;
      
       }else{
        digitalWrite(4, HIGH);
         statut4=HIGH;
       }
     }



      
      FastLED.show();
      delay(vitesse);
}

void extinction(){
  for(int i=100;i>0;i--){
    FastLED.setBrightness(i);
    delay(10);
     FastLED.show();
  }
}

void allumage(){
  for(int i=0;i<100;i++){
    FastLED.setBrightness(i);
    delay(10);
     FastLED.show();
  }
}

void blancchaud(){
           FastLED.setBrightness( 40 );
FastLED.setTemperature( Candle );
  for(int i=0;i<NB_LEDS;i++){
      leds[i]=CRGB::White;
    }
     FastLED.show();

}

void serpent(){
           FastLED.setBrightness( 40 );
FastLED.setTemperature( Candle );

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
           leds[positiontete-TAILLE_SERPENT]=CRGB::Black;     
          
        }else {
          positiontete--;
         //On eteint position tete + taille serpent
         leds[positiontete+TAILLE_SERPENT]=CRGB::Black;
        }
        //on allume position tete
        leds[positiontete]=CRGB::White;

        
        FastLED.show();
      delay(DELAIS_ENTRE_MOUVEMENT);
   }
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

  

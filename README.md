# Projet Noel
Mon projet pour Noel

## Bande Leds de Noel

### Matériel
Vous aurez besoin :
- 1 Arduino Uno http://amzn.eu/d/i5jxBHh
- 1 bande led http://amzn.eu/d/epV8oWh à remplacer par http://amzn.eu/d/iVtQyhz
- 1 Alimentation 12V 5A

#### Vous pourriez avoir besoin
Pour fabriquer des rallonges pour l'alimentation des leds  : http://amzn.eu/d/83QCUha

Une alimentation 5V 40A : http://amzn.eu/d/gm8GYq0
A savoir que les WS2812B sont en 5V, bien verifier qu'elle sont individuellement adressable, et que chaque "led" consomme 60ma
Pour une bande de 5 m * 60 leds par metre on aura donc besoin de 5 * 60(led/m) * 0.06 = 18A
Sachant que la plupart des alimentation on 2 sorties, 40Amp me semble etre la bonne solution

### Avant de commencer
Tout d'abord penser à calibrer votre led :
https://github.com/FastLED/FastLED/blob/master/examples/RGBCalibrate/RGBCalibrate.ino

Puis verifier les corrections à apporter :
https://github.com/FastLED/FastLED/wiki/FastLED-Color-Correction

### Premier test

#### Montage
Commencer par réaliser le montage suivant : https://github.com/alexgit95/christmas_project/blob/master/Montages/montageLed.PNG
#### Code
Recuperer le code du serpent : https://github.com/alexgit95/christmas_project/blob/master/Snippet/serpent.ino

Il n'y a plus qu'à verser sur l'arduino et c'est parti !

## Moteur pas à pas

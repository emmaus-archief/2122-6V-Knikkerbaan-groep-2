//testcode werkt nog niet (ligt misschien aan LCD scherm)

#include <Wire.h>
#include "rgb_lcd.h"
 
rgb_lcd lcd;
 
/*
const int colorR = 255;
const int colorG = 0;
const int colorB = 0;
*/
 
 int y = 40; //gemeten afstand die knikker aflegt op rechter pad, moet nog aangepast worden
 int tijd = 20; //gemeten tijd door sensor 'snelheidsmeter' , moet nog aangepast worden

void setup() 
{
    //setup van de rijen en kolommen LCD scherm, dus 16x2
    lcd.begin(16, 2);
 
    // print de snelheid op LCD scherm
    lcd.print("Snelheid:")

    delay(1000);
}
 
void loop() 
{
    // cursor op 0,1 dus linksboven van het scherm
    lcd.setCursor(0, 1);
    
    delay(100);
}
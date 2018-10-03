/*
Ryhmä 1
Jari Pietikäinen
Oona Rauhala
Suvi Rannisto
*/

#include <Servo.h >
#include <LiquidCrystal.h>
#include "pitches.h"
//------------------------------------------------------------

int melody[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  16, 16, 16, 16, 16, 16, 16, 16
};
//--------------------------------------------------------------

const int buttonPin = 7;     // ykkös painike pin(7)/ ^ (muuttaa lukua 0-9)
const int buttonPin2 = 10; // kakkos painike pin(10)/ -> (muuttaa cursorin sijaintia 'x' 0-4)
const int buttonPin3 = 13; // kolmos painike/enter pin(13) (tarkistaa pin koodin kun sijainti x == 4)
//------------------------------------------------------------

const int servoPin =  9;      // 9g servon pin (9)
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; //(LCD-näytön pin paikkoja)

//------------------------------------------------------------
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Servo servo;  
//------------------------------------------------------------
int servoAngle = 0;   // servo asteen muutos

int buttonState = 0;  
int buttonState2 = 0;
int buttonState3 = 0;

int luku1 = 0; // kohdan 1,0 luku 0-9 (kun x=0)
int luku2 = 0; // kohdan 1,1 luku 0-9 (kun x=1)
int luku3 = 0; // kohdan 1,2 luku 0-9 (kun x=2)
int luku4 = 0; // kohdan 1,3 luku 0-9 (kun x=3)

int x = 0; // alarivin kohta vasemmalta oikealle. 0=ensimmäinen.
int pin =0; //pin muutetaan jos luvut oikein.

//------------------------------------------------------------
void setup() {
  Serial.begin(9600);  
  servo.attach(servoPin);
  
   // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Perus viesti ylärivillä:
  lcd.print("Anna Pin:");
//--------------------------------------------------------

  // merkataan 9g servo OUTPUT:ksi.
  pinMode(servoPin, OUTPUT);
  
  // merkataan painikkeet INPUT:eiksi.
  pinMode(buttonPin, INPUT);//pin 7
  pinMode(buttonPin2, INPUT);//pin 10
  pinMode(buttonPin3, INPUT);//pin 13
/*----------------------------------------------------------
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    // !!ALUNPERIN KERTOIMENA 1.30!!
    int pauseBetweenNotes = noteDuration * 1.10;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
*/
}
//----------------void setup päättyy--------------

//lcd.display()

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  
  //lcd.setCursor(0,1);
  //lcd.print(luku1);
//---------------------------------------------------------------

  // Jos painike on pohjassa on ButtonState 'HIGH'.

  
  if (buttonState == HIGH) {
    //lcd.clear();
    
 //--------------0,1---------------------
    if (x==0 && luku1 >=9)  {
      lcd.setCursor(0,1);

      luku1 = 0;
      lcd.print(luku1);
      delay(250);
    }
    else if (x==0 && buttonState == HIGH){
      lcd.setCursor(0,1);
      luku1 = luku1 + 1;
      lcd.print(luku1);
      delay(250);
      }

    
 //---------------1,1---------------------
    if (x==1 && luku2 >=9)  {
      lcd.setCursor(1,1);

      luku2 = 0;
      lcd.print(luku2);
    }
    else if (x==1 ){
      lcd.setCursor(1,1);
      luku2 = luku2 + 1;
      lcd.print(luku2);
      delay(500);
      }

    
 //--------------2,1---------------------
    if (x==2 && luku3 >=9)  {
      lcd.setCursor(2,1);

      luku3 = 0;
      lcd.print(luku3);
      delay(250);

    }
    else if (x==2 ){
      lcd.setCursor(2,1);

      luku3 = luku3 + 1;
      lcd.print(luku3);
      delay(250);

      }


 //--------------3,1----------------------
     if (x==3 && luku4 >=9)  {
      lcd.setCursor(3,1);

      luku4 = 0;
      lcd.print(luku4);
      delay(250);

    }
     else if (x==3){
      lcd.setCursor(3,1);

      luku4 = luku4 + 1;
      lcd.print(luku4);
      delay(250);

      }
    }
 /*/------------------------------------

    else {
      lcd.setCursor(0,1);

      luku1=luku1 + 1;
      lcd.print(luku1);
      delay(500);

    }
  */  
 //-------Button 1 komennot päättyy!!!!-----------------------------


 
 
 //-------Button 2 komennot alkavat!!!!-----------------------------
 if (buttonState2 == HIGH){
  if (x==0 && buttonState2 == HIGH){ //cursori alarivin 1
    x=1;
    delay(250);

    }
  else if (x==1 && buttonState2 == HIGH){ //cursori alarivin 2
    x=2;
    delay(250);

    }
  else if (x==2 && buttonState2 == HIGH){ //cursori alarivin 3
    x=3;
    delay(250);

    }
  else if (x==3 && buttonState2 == HIGH){ //cursori alarivin 4
    x=4;
    delay(250);

    }  
  else if (x==4 && buttonState2 == HIGH){ //cursori alarivin 5 *NS "ENTER"
    x=0;
    delay(250);

    }
  }







  if (x==4 && buttonState3 == HIGH && pin==1234)  {
  lcd.setCursor(0,0);
  lcd.print("PIN KOODI OIKEIN");
  lcd.setCursor(0,1);
  lcd.print("!!!!!!!!!!!!!!!!");
  servo.write(180);
  //MOOTTORIN KÄÄNTÖ TÄHÄN!!___------------____


  
  }   
//---------------------------------------------------------------------------------
      
   
  if (buttonState2 == HIGH) {
    //lcd.setCursor(1,1);
    //lcd.print(luku2);

  }
//----------------------------------------------------------------- 
  if (buttonState3 == HIGH && pin==1234) {
    
      for (int thisNote = 0; thisNote < 8; thisNote++) {
    
        // to calculate the note duration, take one second divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000 / noteDurations[thisNote];
        tone(8, melody[thisNote], noteDuration);
    
        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        // !!ALUNPERIN KERTOIMENA 1.30!!
        int pauseBetweenNotes = noteDuration * 1.10;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(8);
      }
      //lcd.clear();
      lcd.setCursor(0,0);
      //lcd.print("btn 3");
      //delay(250);   
      lcd.display();
      pin=0;
      delay(100);
            
    // turn LED on:
    //digitalWrite(servoPin, HIGH);
  } 
  if (buttonState == LOW) {
    if (luku1 == 1 && luku2 == 2 && luku3 == 3 && luku4 == 4){
      pin = 1234; //muuttaa pin koodin oikeaksi
      }else{
        pin = 0; 
        }
    
    
    /*
    lcd.setCursor(0, 0);
    lcd.print("Anna Pin:");
    lcd.setCursor(0,1);
    lcd.print(luku1);   
    lcd.display();
    //delay(500); 
    */
  }
}


// https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/
/*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/

#include <Button.h>
#define ledV 9
#define ledK 10
#define ledP 11
#define kaiutin 8
#define lednappi 14
#define kaiutinnappi 15
#define NOTONE 0
#define TONE 1
#define trigPin 13
#define echoPin 12
Button S1(0, 200);
char noise=TONE;
#include <LiquidCrystal.h> // includes the LiquidCrystal Library
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
long duration;
int distanceCm, distanceInch;
int viive = 60;
void setup() {
lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode (ledV, OUTPUT);
pinMode (ledK, OUTPUT);
pinMode (ledP, OUTPUT);
pinMode (kaiutin, OUTPUT);
pinMode (lednappi, INPUT);
pinMode (kaiutinnappi, INPUT);
Serial.begin(9600);
}


void loop() {

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
distanceInch = duration*0.0133/2;
delay(100);



lcd.clear(); // Lisäsin koska cm ja inch jäi näkymään taululle eri kohtiin.

lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
lcd.print("Sentit: "); // Prints string "Distance" on the LCD
lcd.print(distanceCm); // Prints the distance value from the sensor
lcd.print(" cm");
lcd.setCursor(0,1);
lcd.print("Tuumat: ");
lcd.print(distanceInch);
lcd.print(" inch");
delay(viive);

if(S1.pressed()){
  if(noise==TONE){
    noise=NOTONE;
    Serial.println("NOTONE");
    noTone(kaiutin);
  }else{
    noise=TONE;
    Serial.println("TONE");
  }
}
  

if (distanceCm < 20){ 
  digitalWrite(ledV, HIGH);
  digitalWrite(ledK, LOW);
  digitalWrite(ledP, LOW);
  if(noise==TONE){
//    tone(kaiutin, 1600, viive);
    tone(kaiutin, 1700);
  }
}
else if (distanceCm < 50){ 
  digitalWrite(ledV, LOW);
  digitalWrite(ledK, HIGH);
  digitalWrite(ledP, LOW);
  if(noise==TONE){
//    tone(kaiutin, 900, viive);
    tone(kaiutin, 1000);
  }
}
else if(distanceCm < 100){ 
  digitalWrite(ledV, LOW);
  digitalWrite(ledK, LOW);
  digitalWrite(ledP, HIGH);
  if(noise==TONE){
//    tone(kaiutin, 300, viive);
    tone(kaiutin, 400);
  }
}else{digitalWrite(ledV, LOW);
       digitalWrite(ledK, LOW);
       digitalWrite(ledP, LOW);
       noTone(kaiutin);
}

delay(viive);

}

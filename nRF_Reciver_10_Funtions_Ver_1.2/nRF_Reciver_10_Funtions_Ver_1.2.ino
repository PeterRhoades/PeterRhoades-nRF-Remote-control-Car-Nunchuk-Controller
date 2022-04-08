/*
 nRF Tranciver 
  1 = GRN  Black   
  2 = 3.3v Red
  3 = CE   Pin 7  Blue
  4 = CSN  Pin 8  Breen
  5 = SCK  Pin 13 Yellow
  6 = MOSI Pin 11 White
  7 = MISO Pin 12 Orange
   _______________________
  | 1 | 2 |              |
  | 3 | 4 |              | 
  | 5 | 6 |              |
  |_7_|___|______________|
*/

#include  <SPI.h>
#include "RF24.h"
byte msg[1];
RF24 radio(7,8);
const uint64_t pipe = 0x8675309ABCll; //Pipe Number same as nRF Sender:

// Motor A Right connections
int enA = 9;
int in1 = A0;
int in2 = A1;
// Motor B connections
int enB = 3;
int in3 = A2;
int in4 = A3;
int myTime = millis();

void setup(void)
{
  
 Serial.begin(9600);
  Serial.println("In Setup");
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();
 pinMode(enA, OUTPUT); // Set all the motor control pins to outputs:
 pinMode(enB, OUTPUT);
 pinMode(in1, OUTPUT);
 pinMode(in2, OUTPUT);
 pinMode(in3, OUTPUT);
 pinMode(in4, OUTPUT);
  digitalWrite(in1, LOW); // Turn off motors - Initial State:
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  Serial.println("Slave Nunchuk Ready");
 }

void loop(void)
  {
  if(radio.available())
  {
  
    radio.read(msg, sizeof(msg));
    //delay(50);
    
  if(msg[0] == 1)
  {
  Serial.print(" Left Turn ");
  Serial.println("Reciver");
  analogWrite(enA, 255); //Turn on motor A & B
  analogWrite(enB, 255); 
 digitalWrite(in1, HIGH);
 digitalWrite(in2, LOW);
 digitalWrite(in3, LOW);
 digitalWrite(in4, HIGH);
  }
  else if(msg[0] == 2)
  {
   Serial.print(" Right Turn ");
   Serial.println("Reciver");
   analogWrite(enA, 255); //Turn on motor A & B
   analogWrite(enB, 255); 
 digitalWrite(in1, LOW);
 digitalWrite(in2, HIGH);
 digitalWrite(in3, HIGH);
 digitalWrite(in4, LOW);
  }
  else if(msg[0] == 3)
  {
   Serial.print(" Forward 50% ");
   Serial.println("Reciver");
   analogWrite(enA, 155); //Turn on motor A & B
   analogWrite(enB, 155); 
 digitalWrite(in1, HIGH);
 digitalWrite(in2, LOW);
 digitalWrite(in3, HIGH);
 digitalWrite(in4, LOW);
  }
  else if(msg[0] == 4)
  {
   Serial.print(" Forward 100% ");
   Serial.println("Reciver");
   analogWrite(enA, 255); //Turn on motor A & B
   analogWrite(enB, 255); 
 digitalWrite(in1, HIGH);
 digitalWrite(in2, LOW);
 digitalWrite(in3, HIGH);
 digitalWrite(in4, LOW);
  }
  else if(msg[0] == 5)
  {
   Serial.print(" Reverse 50% ");
   Serial.println("Reciver");
   analogWrite(enA, 155); //Turn on motor A & B
   analogWrite(enB, 155); 
 digitalWrite(in1, LOW);
 digitalWrite(in2, HIGH);
 digitalWrite(in3, LOW);
 digitalWrite(in4, HIGH);
  }
  else if(msg[0] == 6)
  {
   Serial.print(" Reverse 100% ");
   Serial.println("Reciver");
   analogWrite(enA, 255); //Turn on motor A & B
   analogWrite(enB, 255); 
 digitalWrite(in1, LOW);
 digitalWrite(in2, HIGH);
 digitalWrite(in3, LOW);
 digitalWrite(in4, HIGH);
  }
  else if(msg[0] == 7)
  {
   Serial.print(" Button C ");
   Serial.println("Reciver");
  }
  else if(msg[0] == 8)
  {
   Serial.print(" Button Z ");
   Serial.println("Reciver");
  }
  else if(msg[0] == 9)
  {
   Serial.print(" Nunchuk Foward");
   Serial.println(" Reciver");
  }
  else if(msg[0] == 10)
  {
   Serial.print(" Nunchuk Back");
   Serial.println(" Reciver");
  }
  else if(msg[0] == 11)
  {
 Serial.println(" Stop Reciver");
 digitalWrite(in1, LOW);
 digitalWrite(in2, LOW);
 digitalWrite(in3, LOW);
 digitalWrite(in4, LOW);
 }
  }
  }

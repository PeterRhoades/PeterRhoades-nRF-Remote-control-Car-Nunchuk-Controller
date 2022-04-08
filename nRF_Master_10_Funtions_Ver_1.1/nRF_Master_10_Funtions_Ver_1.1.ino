/*                          

Nunchuk info inc library https://create.arduino.cc/projecthub/infusion/using-a-wii-nunchuk-with-arduino-597254

                               
                                   nRF Tranciver 
 msg[0] 1 = Left                  1 = GRN  Black   
 msg[0] 2 = Right                 2 = 3.3v Red
 msg[0] 3 = Forward50             3 = CE   Pin 7  Blue
 msg[0] 4 = Forward100            4 = CSN  Pin 8  Breen
 msg[0] 5 = Reverse50             5 = SCK  Pin 13 Yellow
 msg[0] 6 = Reverse100            6 = MOSI Pin 11 White
 msg[0] 7 = Button C              7 = MISO Pin 12 Orange
 msg[0] 8 = Button Z               _______________________
 msg[0] 9 = Nunchuk Foward         | 1 | 2 |              |
 msg[0] 10 = Nunchuk Reverse       | 3 | 4 |              | 
 msg[0] 11 = Stop                  | 5 | 6 |              |
                                   |_7_|___|______________|
*/                                 

#include <Wire.h>
#include  <SPI.h>
#include "RF24.h"
#include "nunchuk.h"
byte msg[1];
RF24 radio(7,8);
const uint64_t pipe = 0x8675309ABCll; //Pipe Number same as nRF Riciver:

void setup() {
  Serial.begin(9600);
  Serial.println("In Setup");
  Wire.begin();
  nunchuk_init();
  radio.begin();
  radio.openWritingPipe(pipe);
  Serial.println("Master Nunchuk Ready");

}

void loop() {
 (nunchuk_read()); 
  delay(50);
 
 if (nunchuk_joystickX() < -120) //Joystick Left: 
  {
  int left = nunchuk_joystickX();
  msg[0] = 1; 
  radio.write(msg, sizeof(msg));
   Serial.print(msg[0]);
   Serial.print (" = Left Turn "); Serial.print (left);
   Serial.println("  Sender");
  }
 if (nunchuk_joystickX() > 120) //Joystick Right: 
  {
  int right = nunchuk_joystickX();
  msg[0] = 2; 
  radio.write(msg, sizeof(msg));
   Serial.print(msg[0]);
   Serial.print (" = Right Turn "); Serial.print (right);
   Serial.println("  Sender");
  }
 if (nunchuk_joystickY() > 20 && nunchuk_joystickY() < 80) //Joystick forward 50%:
  {
  int forward50 = nunchuk_joystickY();
  msg[0] = 3; 
  radio.write(msg, sizeof(msg));
   Serial.print(msg[0]);
   Serial.print (" = Formard 50% "); Serial.print (forward50);
   Serial.println("  Sender");
  }
 if (nunchuk_joystickY() > 80) //Joystick forward 100%:
  {
  int forward100 = nunchuk_joystickY();
  msg[0] = 4; 
  radio.write(msg, sizeof(msg));
   Serial.print(msg[0]);
   Serial.print (" = Formard 100% "); Serial.print (forward100);
   Serial.println("  Sender");
  }
 if (nunchuk_joystickY() < -20 && nunchuk_joystickY() > -80) //Joystick reverse50%:
  {
  int reverse50 = nunchuk_joystickY();
  msg[0] = 5; 
  radio.write(msg, sizeof(msg));
   Serial.print(msg[0]);
   Serial.print (" = Reverse 50% "); Serial.print (reverse50);
   Serial.println("  Sender");
  }
  
 if (nunchuk_joystickY() < -80) //Joystick reverse100%:
  {
  int reverse100 = nunchuk_joystickY();
  msg[0] = 6; 
  radio.write(msg, sizeof(msg));
   Serial.print(msg[0]);
   Serial.print (" = Reverse 100% "); Serial.print (reverse100);
   Serial.println("  Sender");
  }
 if (nunchuk_buttonC() > 0) //Top Button Clossed
    {
  int buttonc = nunchuk_buttonC();
  msg[0] = 7; 
  radio.write(msg, sizeof(msg));
   Serial.print(msg[0]);
   Serial.print (" = ButtonC "); Serial.print (buttonc);
   Serial.println("  Sender");
  }
 if (nunchuk_buttonZ() > 0) //Bottom Button Clossed
  {
  int buttonz = nunchuk_buttonZ();
  msg[0] = 8; 
  radio.write(msg, sizeof(msg));
   Serial.print(msg[0]);
   Serial.print (" = ButtonZ "); Serial.print (buttonz);
   Serial.println("  Sender");
  }
 if (nunchuk_accelY() > 150) //Nunchuk Foward
  {
      int nunchukF = nunchuk_accelY();
  msg[0] = 9; 
  radio.write(msg, sizeof(msg));
   Serial.print(msg[0]);
   Serial.print (" = Nunchuk Foward "); Serial.print (nunchukF);
   Serial.println("  Sender");
  }
 if (nunchuk_accelY() < -150) //Nunchuk Reverse
  {
      int nunchukR = nunchuk_accelY();
  msg[0] = 10; 
  radio.write(msg, sizeof(msg));
   Serial.print(msg[0]);
   Serial.print (" = Nunchuk Reverse "); Serial.print (nunchukR);
   Serial.println("  Sender");
 }
 if (nunchuk_joystickX() > -120 && nunchuk_joystickX() < 120 && nunchuk_joystickY() < 20 && nunchuk_joystickY() > -20 && nunchuk_buttonZ() <1 &&nunchuk_buttonC()< 1)
 {
  msg[0] = 11; 
  radio.write(msg, sizeof(msg));
   Serial.print(msg[0]);
   Serial.println (" = Stop Sender"); 
}
}

Radio controlled car using two nRF24 transceiver and Nunchuk I2C controller. 
Nunchuk Range

nunchuk_accelY() Nunchuk Forward Range -1 to -200

nunchuk_accelY() Nunchuk Back  Range  1 to 200  

nunchuk_accelX()  Nunchuk Right Range 1 to  200

nunchuk_accelX()  Nunchuk Left Range -1 to -200

nunchuk_joystickX()  Joystick Left  Range  -1  to  -127

nunchuk_joystickX()  Joystick Right  Range  1  to  127

nunchuk_joystickY()  Joystick Up    Range   1  to  127

nunchuk_joystickY()  Joystick Down  Range  -1 to -128

C = nunchuk_buttonC()  Fire Top Button Range   On= HIGH

Z = nunchuk_buttonZ()  Fire Bottom Button Range  On= HIGH

Pins Used:

•	SDA  A4  Nunchuk Yellow Wire 

•	SCL  A5  Nunchuk White Wire

nRF Transceiver wire diagram:

MEGA 2560:
  CE →   7
CSN →  8
MISO → 50
MOSI → 51
SCK  → 52

ESP32:
  CE  →   4
CSN →   5
MISO →  19
MOSI →  23
SCK   → 18

UNO:
  CE  →  7
CSN →   8
MISO →  13
MOSI →  11
SCK   → 12

Code soon to be updated...

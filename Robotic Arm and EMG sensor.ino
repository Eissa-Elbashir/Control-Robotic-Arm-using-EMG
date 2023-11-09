#include <Servo.h>
const float Alpha = 0.1;

int ThumbFingerPin = A0;    // Declaring the variable with the right type
float Cur_avg_Thumb;
float Las_avg_Thumb;
int ThumbRead = 0;
float ThumbVoltage;  
int ThumbFingerServo = 3;
int ThumbFingerPos = 0;

int IndexFingerPin = A1;
float Cur_avg_Index;
float Las_avg_Index;
int IndexRead = 0;
float IndexVoltage;  
int IndexFingerServo = 4;
int IndexFingerPos = 0;

int MidFingerPin = A2;
float Cur_avg_Mid;
float Las_avg_Mid;
int MidRead = 0;
float MidVoltage;  
int MidFingerServo = 5;
int MidFingerPos = 0;

int RingFingerPin = A3;
float Cur_avg_Ring;
float Las_avg_Ring;
int RingRead = 0;
float RingVoltage;
int RingFingerServo = 6;
int RingFingerPos = 0;

int PinkyFingerPin = A4;
float Cur_avg_Pinky;
float Las_avg_Pinky;
int PinkyRead = 0;
float PinkyVoltage;  
int PinkyFingerServo = 7;
int PinkyFingerPos = 0;


Servo ThumbFinger;    // Declaring the servos 
Servo IndexFinger;
Servo MidFinger;
Servo RingFinger;
Servo PinkyFinger;


void setup() {
  pinMode(ThumbFingerPin, INPUT);   // Configuring the pins as input or output 
  pinMode(IndexFingerPin, INPUT);
  pinMode(MidFingerPin, INPUT);
  pinMode(RingFingerPin,INPUT);
  pinMode(PinkyFingerPin,INPUT);
  
  Serial.begin(9600);   // Running the Serial plotter at baud rate of 9600
  
  ThumbFinger.attach(ThumbFingerServo);   // Configuring the pins as input or output
  IndexFinger.attach(IndexFingerServo);
  MidFinger.attach(MidFingerServo);
  RingFinger.attach(RingFingerServo);
  PinkyFinger.attach(PinkyFingerServo);
}

void loop() { 
  ThumbRead = analogRead(ThumbFingerPin); 
  ThumbVoltage = (9. / 223.) * ThumbRead;
  Cur_avg_Thumb = (ThumbVoltage * Alpha) + (Las_avg_Thumb * (1 - Alpha));
  Las_avg_Thumb = Cur_avg_Thumb;
  
  IndexRead = analogRead(IndexFingerPin); 
  IndexVoltage = (9. / 223.) * IndexRead;
  Cur_avg_Index = (IndexVoltage * Alpha) + (Las_avg_Index * (1 - Alpha));
  Las_avg_Index = Cur_avg_Index;
  
  MidRead = analogRead(MidFingerPin);
  MidVoltage = (9. / 223.) * MidRead;
  Cur_avg_Mid = (MidVoltage * Alpha) + (Las_avg_Mid * (1 - Alpha));
  Las_avg_Mid = Cur_avg_Mid;
  
  RingRead = analogRead(RingFingerPin);
  RingVoltage = (9. / 223.) * RingRead;   // 9 is an integer _ 9. is a float number _ by making it float number the answer will be float number  
  Cur_avg_Ring = (RingVoltage * Alpha) + (Las_avg_Ring * (1 - Alpha));
  Las_avg_Ring = Cur_avg_Ring;

  PinkyRead = analogRead(PinkyFingerPin);
  PinkyVoltage = (9. / 223.) * PinkyRead;   // 9 is an integer _ 9. is a float number _ by making it float number the answer will be float number  
  Cur_avg_Pinky = (PinkyVoltage * Alpha) + (Las_avg_Pinky * (1 - Alpha));
  Las_avg_Pinky = Cur_avg_Pinky;


  Serial.println(Cur_avg_Thumb);
  /*Serial.print(",");
  Serial.print(Cur_avg_Index);
  Serial.print(",");
  Serial.print(Cur_avg_Mid);
  Serial.print(",");
  Serial.print(Cur_avg_Ring);
  Serial.print(",");
  Serial.println(Cur_avg_Pinky);
  */


  ThumbFingerPos = 40 * Cur_avg_Thumb;
  ThumbFinger.write(ThumbFingerPos);
  IndexFingerPos = 40 * Cur_avg_Index;
  IndexFinger.write(IndexFingerPos);
  MidFingerPos = (-50 * Cur_avg_Mid) + 180;
  MidFinger.write(MidFingerPos);
  RingFingerPos = 40 * Cur_avg_Ring;
  RingFinger.write(RingFingerPos);
  PinkyFingerPos = 40 * Cur_avg_Pinky;
  PinkyFinger.write(PinkyFingerPos);  
}

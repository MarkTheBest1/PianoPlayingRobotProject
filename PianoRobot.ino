#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "Notes.h"
#include "dstepper.h"

//STEPPER DRIVER
Dstepper myStepper(22,23);

//SERVO SHIELD
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN  265 // This is the 'minimum' pulse length count (out of 4096)   ***** 90 degrees *****
#define SERVOMAX  320 // This is the 'maximum' pulse length count (out of 4096)   ***** 180 degrees *****
#define USMIN  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

uint8_t Servos[4] = {0,1,2,3};

///// Initialize starting position of each finger
int FingerPositions[4] = {C, F, B, Eh};
//int FingerPositions[4] = {-233, D, G, Ch};

int SongSize;


  
void setup() {
  Serial.begin(9600);
 // AFMS.begin();  // create with the default frequency 1.6KHz
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  pwm.setPWM(Servos[0], 0, SERVOMAX);
  pwm.setPWM(Servos[1], 0, SERVOMAX);
  pwm.setPWM(Servos[2], 0, SERVOMAX);
  pwm.setPWM(Servos[3], 0, SERVOMAX); 
  delay(1000);
}

void loop() {
  slider();
}

void slider(){
  int nextSongKeyPos;
  int nextFingerPressIndex;
  int startTime, elapsedTime, currentTime;
  int distance, difference;
  
  SongSize= sizeof(Song);
  
  for ( int i = 0; i < SongSize; i++){
    startTime = millis();


    nextSongKeyPos = Song[i];
    nextFingerPressIndex = closestFinger(nextSongKeyPos); //call function to check which finger is the closest to desired note
    difference = nextSongKeyPos - FingerPositions[nextFingerPressIndex];     //difference will give us how many steps we need to move

    //move slider
    distance = abs(difference);
    myStepper.sMove(distance,difference); //Modified-Derian

    currentTime = millis();
    elapsedTime = currentTime - startTime;
    

    //Serial.print(i,":"); 
    Serial.println(elapsedTime);

    
    //position reached, ready to press
    delay(SongMaxKeyTime - elapsedTime);
    pwm.setPWM(Servos[nextFingerPressIndex], 0, SERVOMIN);
    delay(SongKeyDelay[i]); //additional delay for a song key    
    pwm.setPWM(Servos[nextFingerPressIndex], 0, SERVOMAX);
   
    
   
    //update finger positions
    FingerPositions[0] += difference;
    FingerPositions[1] += difference;
    FingerPositions[2] += difference;
    FingerPositions[3] += difference;
     
  }
}



///// Find the closest finger /////
int closestFinger(int keyPos){
  int arr[4] = {FingerPositions[0], FingerPositions[1], FingerPositions[2], FingerPositions[3]};
  for ( int i = 0; i < 4; i++) {
    arr[i] = abs(keyPos - arr[i]);
  }

  int smallest = arr[0];
  int smallestIndex = 0;
  for(int i = 1;i < 4; i++) { 
    if(arr[i] < smallest ) {
     smallest = arr[i];
     smallestIndex = i;
    } 
  } 
  return smallestIndex;
};

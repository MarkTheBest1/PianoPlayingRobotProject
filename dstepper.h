#ifndef DSTEPPERH
#define DSTEPPERH


class Dstepper{
  public:
    Dstepper(int stepPin, int dirPin);
    void setStepsPerRev(int srev){stepsPerRev = srev;}
    void setStepSpeed(int ss){stepSpeed = ss;}
    void stepLeft(int stps);
    void stepRight(int stps); 
    void sMove(int distance, int difference);
  private: 
    int stepPin;
    int dirPin;
    int stepSpeed;
    int stepsPerRev;
    
};

Dstepper::Dstepper(int sPin, int dPin){
  stepPin = sPin;
  dirPin = dPin;
  stepsPerRev = 200; //default value for Nema 17
  stepSpeed = stepsPerRev*4;//default fastest value for Nema 17 with current driver settings
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}

void Dstepper::stepLeft(int stps){

  digitalWrite(dirPin, HIGH);// set direction
    for(int x = 0; x < stps; x++)
    {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(stepSpeed);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(stepSpeed);
    }
  
}
 void Dstepper::stepRight(int stps){
  
    digitalWrite(dirPin, LOW);// set direction
    for(int x = 0; x < stps; x++)
    {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(stepSpeed);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(stepSpeed);
    }
  
 }
  void Dstepper::sMove(int distance, int difference){
if ( difference > 0 ){
      stepLeft(distance);
    }
    else if ( difference < 0) {
      stepRight(distance);
    } 
    else {
      delay(10);
    }
    
  }








#endif

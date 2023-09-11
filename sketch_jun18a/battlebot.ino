//ir sensors
#define ir1 1
#define ir2 2
#define ir3 3


// Motors
#define leftmotor1 9
#define leftmotor2 10
#define rightmotor1 11
#define rightmotor2 12 

//PWM
#define leftpwm 4
#define rightpwm 5

//ultrasonic sensor
#define ultrasonic 6
void setup(){
    Serial.begin(9600);
    pinMode(ir1,INPUT);
    pinMode(ir2,INPUT);
    pinMode(ir3,INPUT);
    pinMode(leftmotor1,OUTPUT);
    pinMode(leftmotor2,OUTPUT);
    pinMode(rightmotor1,OUTPUT);
    pinMode(rightmotor2,OUTPUT); 


} 
void loop(){
  vala=digitalRead(ir1);
  valb=digitalRead(ir2);
  valc=digitalRead(ir3);


  
if ((vala == 1)&&(valb == 0)&&(valc == 1))
    {
      forward();
    }
if ((vala == 0)&&(valb == 0)&&(valc == 1))
    {
      SlightLeft();
    }
if ((vala == 0)&&(valb == 1)&&(valc == 1)) 
    {
      turnLeft();
    }
if ((vala == 1)&&(valb == 0)&&(valc == 0))
    {
      SlightRight();
    }
if ((vala == 1)&&(valb == 1)&&(valc == 0))
    {
      turnRight();
    }
if ((vala == 1)&&(valb == 1)&&(valc == 1))
    {
      Stop();
    }
if ((vala == 0)&&(valb == 0)&&(valc == 0))
    {
      Stop();
    }


 



}

void forward(){
digitalWrite(leftmotor1, HIGH);
digitalWrite(leftmotor2, LOW);
digitalWrite(rightmotor1, HIGH);
digitalWrite(rightmotor2, LOW);  
}
void SlightLeft(){
digitalWrite(leftmotor1, LOW);
digitalWrite(leftmotor2, HIGH);
digitalWrite(rightmotor1, HIGH);
digitalWrite(rightmotor2, LOW);  
}
void turnLeft(){
digitalWrite(leftmotor1, LOW);
digitalWrite(leftmotor2, LOW);
digitalWrite(rightmotor1, HIGH);
digitalWrite(rightmotor2, LOW);  
}
void SlightRight(){
digitalWrite(leftmotor1, HIGH);
digitalWrite(leftmotor2, LOW);
digitalWrite(rightmotor1, LOW);
digitalWrite(rightmotor2, HIGH);
}
void turnRight(){
digitalWrite(leftmotor1, HIGH);
digitalWrite(leftmotor2, LOW);
digitalWrite(rightmotor1, LOW);
digitalWrite(rightmotor2, LOW);
}
void Stop(){
digitalWrite(leftmotor1, LOW);
digitalWrite(leftmotor2, LOW);
digitalWrite(rightmotor1, LOW);
digitalWrite(rightmotor2, LOW);
}
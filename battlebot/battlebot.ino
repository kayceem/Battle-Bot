//ir sensors
#define ir1 2
#define ir2 3
#define ir3 4


// Motors
#define leftmotor1 6
#define leftmotor2 7
#define rightmotor1 8
#define rightmotor2 9

//ultrasonic sensor
#define echo 12
#define trig 11

//pwm
#define pwm1 5
#define pwm2 10
double x,distance;
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

    digitalWrite(trig,0);
    digitalWrite(trig,1);
    delayMicroseconds(10);  
    digitalWrite(trig,0);
    x=pulseIn(echo,1);
    distance=x*0.032/2;
    Serial.println(distance);
    if(distance>20){


  int l =!digitalRead(ir1);
  int m =!digitalRead(ir2);
  int r =!digitalRead(ir3);
  
      if((l==0)&&(m==0)&&(r==0))
          Stop();
  else if((l==0)&&(m==1)&&(r==0))
    forward();
  else if((l==0)&&(m==0)&&(r==1))
    SturnRight();
  else if((l==1)&&(m==0)&&(r==0))
    SturnLeft();
  else if((l==0)&&(m==1)&&(r==1))
    turnRight();
  else if((l==1)&&(m==1)&&(r==0))
  turnLeft();
  
    }
    else {
      Stop();
    }
}


void forward(){
analogWrite(pwm1,200);
analogWrite(pwm2,200);
digitalWrite(leftmotor1, HIGH);
digitalWrite(leftmotor2, LOW);
digitalWrite(rightmotor1, HIGH);
digitalWrite(rightmotor2, LOW);  
}
void SturnRight(){
analogWrite(pwm1,200);
analogWrite(pwm2,200);
digitalWrite(leftmotor1, LOW);
digitalWrite(leftmotor2, HIGH);
digitalWrite(rightmotor1, HIGH);
digitalWrite(rightmotor2, LOW);  
}
void turnRight(){
analogWrite(pwm1,200);
analogWrite(pwm2,200);
digitalWrite(leftmotor1, LOW);
digitalWrite(leftmotor2, LOW);
digitalWrite(rightmotor1, HIGH);
digitalWrite(rightmotor2, LOW);  
}
void SturnLeft(){
analogWrite(pwm1,200);
analogWrite(pwm2,200);
digitalWrite(leftmotor1, HIGH);
digitalWrite(leftmotor2, LOW);
digitalWrite(rightmotor1, LOW);
digitalWrite(rightmotor2, HIGH);
}
void turnLeft(){
analogWrite(pwm1,200);
analogWrite(pwm2,200);
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

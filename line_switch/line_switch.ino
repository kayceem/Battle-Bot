// IR Sensor pins

#define L 2 //left IR
#define M 3 //Middle IR
#define R 4 //Right IR

// Motor pins
#define ENA 5 //PWM LEFT MOTOR
#define Ml1 6
#define Ml2 7
#define Mr1 8
#define Mr2 9
#define ENB 10//PWM RIGHT MOTOR

#define ims 140 //Inital Maximum Motor Speed

//Ultrasonic pins
#define trig 11
#define echo 12




void setup()
{
  //IR_pinMode
  for(int i =2; i <=4; i++)
    pinMode(i, INPUT);
  

  //Motor_pinMode 
  for(int j =5; j <=10; j++)
    pinMode(j, OUTPUT);
  

  //Ultrasonic_pinMode
    pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

}
void loop()
{
  digitalWrite(trig, 0);
  digitalWrite(trig, 1);
  delayMicroseconds(10);
  digitalWrite(trig, 0);
  float time = pulseIn(echo, INPUT);
  float distance = time * 0.32/2;
  if(distance<=20){
    digitalWrite(ENA, 0);
        digitalWrite(ENB, 0);
     }
  
  else
  {
    int sensorValue = !digitalRead(L) << 2 | !digitalRead(M) << 1 | !digitalRead(R);

  switch (sensorValue) {
  case 0b000:
analogWrite(ENA, ims);
    analogWrite(ENB, ims);
  digitalWrite(Ml1, 0);
  digitalWrite(Ml2, 1);
  digitalWrite(Mr2, 0);
  digitalWrite(Mr2, 1);    
    break;
  case 0b001:
    analogWrite(ENA, ims);
  analogWrite(ENB, ims);
  digitalWrite(Ml1, 1);
  digitalWrite(Ml2, 0);
  digitalWrite(Mr2, 0);
  digitalWrite(Mr2, 0);
    break;
  case 0b010:
    analogWrite(ENA, ims);
  digitalWrite(Ml1, 1);
  digitalWrite(Ml2, 0);
  digitalWrite(Mr2, 1);
  digitalWrite(Mr2, 0);
  analogWrite(ENB, ims);
    break;
  case 0b011:
    analogWrite(ENA, ims);
  analogWrite(ENB, ims-50);
  digitalWrite(Ml1, 1);
  digitalWrite(Ml2, 0);
  digitalWrite(Mr2, 0);
  digitalWrite(Mr2, 1);
    break;
  case 0b100:
    analogWrite(ENA, ims);
  analogWrite(ENB, ims);
  digitalWrite(Ml1, 0);
  digitalWrite(Ml2, 0);
  digitalWrite(Mr2, 1);
  digitalWrite(Mr2, 0);
  break;

   case 0b110:
    analogWrite(ENA, ims-50);
  analogWrite(ENB, ims);
  digitalWrite(Ml1, 0);
  digitalWrite(Ml2, 1);
  digitalWrite(Mr2, 1);
  digitalWrite(Mr2, 0);
  break;

  case 0b111:
    digitalWrite(ENA, 0);
    digitalWrite(ENB, 0);
    break;
  }
}
}

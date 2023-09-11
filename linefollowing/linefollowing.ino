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

//Ultrasonic pins
#define trig 11
#define echo 12


void setup()
{
	//IR_pinMode
	pinMode(L, INPUT);
	pinMode(M, INPUT);
	pinMode(R, INPUT);

	//Motor_pinMode
	pinMode(ENA, OUTPUT);
	pinMode(Ml1, OUTPUT);
	pinMode(Ml2, OUTPUT);
	pinMode(Mr1, OUTPUT);
	pinMode(Mr2, OUTPUT);
	pinMode(ENB, OUTPUT);

	//Ultrasonic_pinMode
    pinMode(trig, OUTPUT);
	pinMode(echo, INPUT);	
  Serial.begin(9600);
}
void loop()
{
  analogWrite(ENA,140);
  analogWrite(ENB,140);
	void ultrasonic();
	void sensorvalues();
}
void ultrasonic(){
	digitalWrite(trig, 0);
	digitalWrite(trig, 1);
	delayMicroseconds(10);
	digitalWrite(trig, 0);
	float time = pulseIn(echo,1);
	float distance = time * 0.32/2;
 Serial.print(distance);
	if(distance<=20)
		void stop();
}

void sensorvalues(){
	int l =!digitalRead(L);
	int m =!digitalRead(M);
	int r =!digitalRead(R);

	
	if((l==0)&&(m==0)&&(r==0))
         void stop();
	else if((l==0)&&(m==1)&&(r==0))
		void forward();
	else if((l==0)&&(m==0)&&(r==1))
		void right();
	else if((l==1)&&(m==0)&&(r==0))
		void left();
	else if((l==0)&&(m==1)&&(r==1))
		void sharpright();
	else if((l==1)&&(m==1)&&(r==0))
	void sharpleft();
	else if((l==1)&&(m==1)&&(r==1))
		void backward();

}

void forward()
{
	digitalWrite(Ml1, 1);
	digitalWrite(Ml2, 0);
	digitalWrite(Mr2, 1);
	digitalWrite(Mr2, 0);
}

void backward()
{
	digitalWrite(Ml1, 0);
	digitalWrite(Ml2, 1);
	digitalWrite(Mr2, 0);
	digitalWrite(Mr2, 1);
}
void right()
{
	digitalWrite(Ml1, 1);
	digitalWrite(Ml2, 0);
	digitalWrite(Mr2, 0);
	digitalWrite(Mr2, 0);
}

void sharpright(){
	digitalWrite(Ml1, 1);
	digitalWrite(Ml2, 0);
	digitalWrite(Mr2, 0);
	digitalWrite(Mr2, 1);
}

void left()
{
	digitalWrite(Ml1, 0);
	digitalWrite(Ml2, 0);
	digitalWrite(Mr2, 1);
	digitalWrite(Mr2, 0);
}

void sharpleft(){
	digitalWrite(Ml1, 0);
	digitalWrite(Ml2, 1);
	digitalWrite(Mr2, 1);
	digitalWrite(Mr2, 0);
}

void stop()
{
	digitalWrite(Ml1, 0);
	digitalWrite(Ml2, 0);
	digitalWrite(Mr2, 0);
	digitalWrite(Mr2, 0);
}

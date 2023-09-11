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

//Initial Speed of Motor
#define ims 140

//Ultrasonic pins
#define trig 11
#define echo 12

// PID Constants
float Kp = 1;
float Ki = 1;
float Kd = 1;

float error = 0, P = 0, I = 0, D = 0, pid = 0;
float previous_error = 0, previous_I = 0;

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
}
void loop()
{
	void ultrasonic();
	void sensorvalues();
}
void ultrasonic(){
	digitalWrite(trig, 0);
	digitalWrite(trig, 1);
	delay(10);
	digitalWrite(trig, 0);
	float time = pulseIn(echo, INPUT);
	float distance = time * 0.32/2;
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
		error=0;
	else if((l==0)&&(m==0)&&(r==1))
		error=-1;
	else if((l==1)&&(m==0)&&(r==0))
		error=1;
	else if((l==0)&&(m==1)&&(r==1))
		error=-2;
	else if((l==1)&&(m==1)&&(r==0))
	    error=2;
	else if((l==1)&&(m==1)&&(r==1))
		void backward();

}
void calculate_pid(){
	P = error;
  I = I + previous_I;
  D = error - previous_error;

  pid = (Kp * P) + (Ki * I) + (Kd * D);

  previous_I = I;
  previous_error = error;
}
void motorcontrol(){
	//calculating the effective motor value
int lms=ims-pid;
int rms=ims+pid;
//motor speed shouldn't exceed maximum value
lms=constrain(lms, 0, 255);
rms=constrain(rms, 0, 255);

analogWrite(ENA, lms);
analogWrite(ENB, rms);
forward;
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


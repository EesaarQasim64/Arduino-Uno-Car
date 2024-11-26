#include <AFMotor.h>

#define	trigPin	12
#define	echoPin	13

AF_DCMotor	motor1(1, MOTOR12_64KHZ);
AF_DCMotor	motor2(2, MOTOR12_8KHZ);

char command;

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	if(Serial.available())
	{
		command = Serial.read();
		Stop();
		if(command == 'F')
		{
			goForward();
		}
		else if (command == 'B')
		{
			goBack();
		}
		else if(command == 'L')
		{
			goLeft();
		}
		else if(command == 'R')
		{
			goRight();
		}
	}
}

void Stop()
{
	motor1.setSpeed(0);
	motor1.run(RELEASE);
	motor2.setSpeed(0);
	motor2.run(RELEASE);
}

void goForward()
{
	motor1.setSpeed(100);
	motor1.run(FORWARD);
	motor2.setSpeed(100);
	motor2.run(FORWARD);
}

void goBack()
{
	motor1.setSpeed(100);
	motor1.run(BACKWARD);
	motor2.setSpeed(100);
	motor2.run(BACKWARD);
}

void goLeft()
{
	motor1.setSpeed(100);
	motor1.run(BACKWARD);
	motor2.setSpeed(100);
	motor2.run(RELEASE);
}

void goRight()
{
	motor1.setSpeed(100);
	motor1.run(RELEASE);
	motor2.setSpeed(100);
	motor2.run(FORWARD);
}
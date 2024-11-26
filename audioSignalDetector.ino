boolean			bAlarm = false;
unsigned int 	lastSoundDetectTime;
int				soundAlarmTime = 500
void setup()
{
	Serial.begin(9600);
	pinMode(soundDetectedPin, INPUT);
	pinMode(buzzer, OUTPUT);
}

void loop()
{
	soundDetectedVal = digitalRead(soundDetectedPin);
	if(soundDetectedVal == 1)
	{
		tone(buzzer, 500);	// Send 1KHz sound signal
		delay(2000);		// Wait for 2 seconds
		noTone(buzzer);
		delay(2000);		// Wait for 2 seconds
	}
}
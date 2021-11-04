int ANALOG_PIN = A0;
int val = 0;
bool led_state = false;

void setup()
{
	pinMode(LED_BUILTIN, OUTPUT);
	Serial.begin(9600);
}

void loop()
{
	val = analogRead(ANALOG_PIN);
	if (val >= 400)
		digitalWrite(LED_BUILTIN, HIGH);
	else
		digitalWrite(LED_BUILTIN, LOW);
	delay(200);
}

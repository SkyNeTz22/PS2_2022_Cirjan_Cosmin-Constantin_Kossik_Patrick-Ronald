char buffer[6];
unsigned long int valoare;
unsigned long int copie;
char val;

void setup()
{
	pinMode(3, OUTPUT);
	pinMode(13, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	Serial.begin(9600);
}

void loop()
{ 
    if(Serial.available() >= 3)
    {
		v = Serial.read();
		
		if(val == '1')
		{
			Serial.read();
			v=Serial.read();
			
			if(val == 'S')
				digitalWrite(13, LOW);
			
			else if(val == 'A')
				digitalWrite(13, HIGH);
		}
		
		else if(val == '2')
		{
			Serial.read();
			Serial.readBytes(buffer, 6);
			valoare = strtoul(buffer, NULL, 16);
			Serial.println("Am primit: ");
			Serial.println(valoare, HEX);
			copie = valoare & 0xFF;
			analogWrite(3, copie);
			valoare = valoare >> 8;
			copie = valoare & 0xFF;
			analogWrite(5, copie);
			valoare = valoare >> 8;
			copie = valoare & 0xFF;
			analogWrite(6, copie);
		}
    }
}
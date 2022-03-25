#include <EEPROM.h>

char messageArray[10][32];
int temperatura;
int prezent;
int inundatie;
int ultima=0;
String message;


void loop()
{
	prezent = millis();
	if((prezent - ultima) >= 1000)
	{	
		inundatie = digitalRead(2);
		temperatura = analogRead(A0);
	 	Serial.write("3, ");
	 	Serial.println(temperatura);
		Serial.write("4, ");
	 	Serial.println(inundatie);
	 	Serial.write("\n");
		ultima = prezent;
	}

	for(int i=0;i<=9;i++)
     	{
     	 	message=Serial.readString();
     		message.toCharArray(messageArray[i], 32);
      		EEPROM.put(eeAddress, messageArray[i]);
    	}
}

void setup(){
	pinMode(A0, INPUT);
	pinMode(2, INPUT);
	Serial.begin(9600);

	while(!Serial) {;}
	EEPROM.get(0, string);
	Serial.println(string);
	string = Serial.readString();
	string.toCharArray(messageArray,32);
	for(int index=0; index<=8; index++)
 	{
   		EEPROM.get(0, messageArray[i]);
   		Serial.println(messageArray[i]);
 	}
	Serial.print("Saved");
}

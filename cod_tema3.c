#include <LiquidCrystal.h>

const int RS=2, EN=3, d4=4, d5=5, d6=6, d7=7;
LiquidCrystal lcd(RS, EN, d4, d5, d6, d7);

String a_s;
int optiune, now, last;
int valR, valG, valB;

int f, s;

void setup()
{
  pinMode(8, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop()
{
 	Serial.print("\nOptiune:");
  	while(Serial.available()==0){;}
  	optiune = Serial.readString().toInt();
   	Serial.print(optiune);
  
  switch(optiune)
  {
  	case 1:	lcd.clear();
    		while(Serial.available()==0){;}
    		a_s=Serial.readString();
    		if(a_s=="A")
            {
              	Serial.print("A");
    			digitalWrite(8,HIGH);
    			lcd.write("Aprins");
            }
    		if(a_s=="S")
            {
              	Serial.print("S");
    			digitalWrite(8,LOW);
    			lcd.write("Stins");
            }
      		break;
    
    case 2:	lcd.clear();
    		while(Serial.available()==0){;}
    		valR=Serial.readString().toInt();
      		Serial.print("\nrosu=");	
      		Serial.print(valR);
        	while(Serial.available()==0){;}
      		valG=Serial.readString().toInt();
      		Serial.print("\nverde=");	
      		Serial.print(valG);
    
    		while(Serial.available()==0){;}
      		valB=Serial.readString().toInt();
      		Serial.print("\nalbastru=");	
      		Serial.print(valB);
    
    		RGB(valR,valG,valB);
    		break;
    
    case 3:	now=millis();
			if((now-last) >= 1000)
            	Temp();
    		last = now;
    		break;	
    
    case 4:	now=millis();
			if((now-last) >= 1000)
          		Ind();
    		last = now;
    		break;
    
    case 5: do
    		{
      			Meniu();
    		}while(digitalRead(9)==LOW);
    		lcd.clear();
    		break;
    
    default:break;
  }
}
//----------Functii----------
  
void RGB(int valR,int valG,int valB)
{
	analogWrite(A0,valR);
  	analogWrite(A1,valG);
  	analogWrite(A2,valB);
}

void Temp()
{
  lcd.clear();
  double temp;
  int data=analogRead(A3);
  temp=((data)*(5000.00/1024)-500)/10;
  Serial.print("\nTemperatura:");
  Serial.print(temp);
  lcd.print(temp);
}

void Ind()
{
  lcd.clear();
  int ind=analogRead(A4)/(1024-1);
  Serial.print("\nInundatie:");
  if(ind==1)
    Serial.print("Da");
  else
    Serial.print("Nu");
  lcd.print(ind);
}
  
void First()
{
  	if(digitalRead(12)==HIGH)
      f++;
    if(digitalRead(11)==HIGH)
      f--;
}
  
void Second()
{
  	if(digitalRead(12)==HIGH)
      s++;
    if(digitalRead(11)==HIGH)
      s--;
}
  
void Meniu()
{
	lcd.clear();
  	s=0;
  	First();
  	switch(f)
    {
    	case 0:		lcd.write("Pg OK");	
      				break;
      
      	case 1:		lcd.write("Mesaje");
      				if(digitalRead(10)==HIGH)
                    {
                      do
                      {
      					Submeniu1();
                      }while(digitalRead(9)==LOW);
                    }
      				break;
      
      	case 2:		lcd.write("Control");
      				if(digitalRead(10)==HIGH)
                    {
                      do
                      {
      					Submeniu2();
                      }while(digitalRead(9)==LOW);
                    }
      				break;
      
      	case 3:		lcd.write("Temperatura");
      				if(digitalRead(10)==HIGH)
                    {
      					//Temp_curenta();
                    }
      				break;
      
      	case 4:		lcd.write("Inundatii");
     				if(digitalRead(10)==HIGH)
                    {
      					//Save();
                    }
      				break;
      
      	default:	f=0;
      				break;
    }
  	delay(250);
}

void Submeniu1()
{
	lcd.clear();
  	Second();
  	switch(s)
    {
    	case 0:		lcd.write("---");	
      				break;
      
      	case 1:		lcd.write("Necitite");
      				if(digitalRead(10)==HIGH)
                    {
      					//Afisare_necitite();
                    }
      				break;
      
      	case 2:		lcd.write("Citite");
      				if(digitalRead(10)==HIGH)
                    {
      					//Afisare_citite();
                    }
      				break;
      
      	case 3:		lcd.write("Stergere");
      				if(digitalRead(10)==HIGH)
                    {
      					//Stergere_mesaje();
                    }
      				break;
      
      	default:	s=0;
      				break;
    }
  	delay(250);
}

void Submeniu2()
{
	lcd.clear();
  	Second();
  	switch(s)
    {
    	case 0:		lcd.write("---");	
      				break;
      
      	case 1:		lcd.write("Manual");
      				if(digitalRead(10)==HIGH)
                    {
      					//Manual();
                    }
      				break;
      
      	case 2:		lcd.write("Automat");
      				if(digitalRead(10)==HIGH)
                    {
      					//Automat();
                    }
      				break;
      
      	default:	s=0;
      				break;
    }
  	delay(250);
}
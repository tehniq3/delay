/*   
 delay off without delay (use millis)
 progrma scris de Nicu Florica (niq_ro)
 http;//www.arduinotehniq.com/
 http://nicuflorica.blogspot.ro/
 http://arduinotehniq.blogspot.com
 v.0 - 20.04.2019 - Craiova, Romania
*/

#define pinbutton 3  // pin for trigger)
#define pinled 4  // pin for led
unsigned long delaytime = 3000;  // 30000 = 30s, time on the led
unsigned long pushtime; // variable for store time of push

byte aprins = 0; // led is off

void setup()
{
Serial.begin(9600); // serial monitor
Serial.println("-----------------");
 Serial.println("Delay off without delay by Nicu FLORICA (niq_ro) !");
Serial.println("-----------------");
pinMode(pinbutton,INPUT);
digitalWrite(pinbutton,HIGH);

pinMode(pinled,OUTPUT);
digitalWrite(pinled,LOW);
Serial.println("LED is OFF !"); 
}

void loop() 
{
if ((digitalRead(pinbutton) == LOW) and (aprins == 0)) // if button was pushed and led is off
{
  Serial.println("button is pushed !");
  digitalWrite(pinled, HIGH); // led on
  Serial.println("LED on !");
  pushtime = millis();  // store the time of push
  aprins = 1;
}

if ((aprins == 1) and (millis() - pushtime > delaytime)) // if led is on and time is end
{
  Serial.println("LED off !");
  digitalWrite(pinled, LOW); // led off
  aprins = 0;
  Serial.println("-------------------");
}



} // end of main loop

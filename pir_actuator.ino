#include <SimpleSDAudio.h>
int ledPin = 13;                 
int pirPin = 2;                 
int pirStat = 0;
int count = 1;
void setup() {
    pinMode(6, OUTPUT); //relay/actuator 
    pinMode(7, OUTPUT);
    
    pinMode(ledPin, OUTPUT);     
    pinMode(pirPin, INPUT);     
    Serial.begin(9600);
    
    SdPlay.setSDCSPin(4); // sd card cs pin
  if (!SdPlay.init(SSDA_MODE_HALFRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER)) // setting mode 
  { 
    while(1); 
  }

  
}


void extendActuator() 
{
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
}


void retractActuator() 
{
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
}


void stopActuator() 
{
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
}

void playmusic()
{
    if(!SdPlay.setFile("music.wav")) 
          { 
            while(1);          
          }
    SdPlay.play();
}


void loop()
{
        
 pirStat = digitalRead(pirPin); 
 if (pirStat == HIGH) 
    {            
        digitalWrite(ledPin, HIGH); 
        Serial.println("motion_detected");
        playmusic();
        extendActuator();
        delay(1000);
        retractActuator();
        delay(1000);
        stopActuator();
        delay(3000)
        digitalWrite(ledPin, LOW);
        
    } 
 else {
        digitalWrite(ledPin, LOW);
 }
} 

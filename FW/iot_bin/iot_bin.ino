
const int trig = 5;                 // PROXIMITY: trigger connected to digital pin 5
const int echo = 4;                 // PROXIMITY: echo connected to digital pin 4


void setup()
{
  unsigned long level =0;
  unsigned long int wakeUpTime=60000000;   //default wake up time is 1 min
  Serial.begin(115200);
  while(!Serial) { }
  pinMode(trig, OUTPUT);      // sets the digital pin as output
  Serial.println("NANINO\n");
  level = measure();
  Serial.println(level);
  Serial.println("\n");
  

  
  
  
  ESP.deepSleep(wakeUpTime);
}


void loop()
{
}

unsigned long int measure()
{
  digitalWrite(trig, HIGH);   // sets the LED on
  delayMicroseconds(10);                  // waits for a second
  digitalWrite(trig, LOW);    // sets the LED off
  return pulseIn(echo, HIGH);
//  delay(1000);                  // waits for a second
}


int buzzerPin = 13;                 // arduino output pin for the buzzer/alarm
//for PIR setup
int pirPin = 2;                     // arduino input pin for PIR sensor
int pirVal = 0;                     // variable for reading the pirPin status

//for MQ2 setup
int mqPin = A5;                     // arduino input pin for MQ2 sensor
int mqVal = 0;                      // variable for reading the mqPin status

void setup() {
  pinMode(buzzerPin, OUTPUT);       // declare buzzer/alarm as output
  pinMode(pirPin, INPUT);           // declare PIR sensor as input
  pinMode(mqPin, INPUT);            // declare MQ2 sensor as input
  Serial.begin(9600);
}
 
void loop(){
  pirVal = digitalRead(pirPin);               // read PIR input value
  mqVal = digitalRead(mqPin);                 // read MQ2 input value
  delay(500);
 
  //PIR value check
  if (pirVal == HIGH || mqVal==HIGH) {        // check if the input is HIGH
    digitalWrite(buzzerPin, HIGH);
    if (pirVal == HIGH){
      Serial.println(1);                      //1 for intruder
    }
    
    if (mqVal==HIGH){
      Serial.println(2);                      //2 for fire accident
    }

  } else {
      digitalWrite(buzzerPin, LOW);
      Serial.println(0);                      //0 for ALL OK
    }
  
}

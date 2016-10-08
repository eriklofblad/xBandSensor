const int xPin = 12;
const int enPin = 11;
const int ledPin = 13;
boolean lastState = false;
int motionCount =0;
static long unsigned lastUpdate = 0;
int updateInt = 500;
int motionThresh = 20;

void setup() {
  Serial.begin(9600);
  pinMode(xPin, INPUT);
  pinMode(enPin, OUTPUT);
  digitalWrite(xPin, LOW);
  delay(20);
  digitalWrite(xPin, HIGH);
}
void loop() {
 static unsigned long currentMillis = millis();
 int currentState = digitalRead(xPin);

 if(currentState != lastState){
    motionCount++;
    lastState = currentState;
    delay(1);
    }
 if(currentMillis - lastUpdate > updateInt){
  Serial.println(motionCount);
  if(motionCount > motionThresh){
    motionDetected();
  }else{
    noMotion();
  }
  motionCount = 0;
  lastUpdate = currentMillis;
 }
}

//////////////////////////////////////////////////////////
/////////////////////Function defenitions/////////////////
//////////////////////////////////////////////////////////

void enableXband(){
    digitalWrite(xPin, LOW);
    delay(20);
    digitalWrite(xPin, HIGH);
  }
void disableXband(){
    digitalWrite(xPin, LOW);
  }

void noMotion(){
    digitalWrite(ledPin, LOW);
  }
void motionDetected(){
    digitalWrite(ledPin, HIGH);
  }

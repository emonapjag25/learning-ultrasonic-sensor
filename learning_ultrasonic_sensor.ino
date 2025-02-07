#define TRIGGERPIN 10 //pin that sends out the pulse
#define ECHOPIN 9 //pin that reads the distance

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //so we can print if we want
  pinMode(TRIGGERPIN, OUTPUT); //sends pulse
  pinMode(ECHOPIN, INPUT); //reads pulse
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TRIGGERPIN, LOW); //turn trigger pin off to give clean starting point
  delayMicroseconds(2);//really fast delay
  digitalWrite(TRIGGERPIN, HIGH); //turn trigger pin on
  delayMicroseconds(10);//10 millisecond delay so that the microsensor can read the pulse before the next one
  //make the ECHHOPIN results a float so that it's more precise
  float duration = pulseIn(ECHOPIN, HIGH); //tells the time from pulse sent to pulse received
  Serial.println(duration); //prints out the duration

  //distance = speed * duration
  float speed = 0.034; //measured in cm/microseconds
  float distance = (speed * duration)/2; //measured in cm, divided by two to account for the sensor pulse forward and back

  Serial.print("distance: "); //prints out the distance
  Serial.print(distance);
  delay(100); //delay for a tenth of a second

  if (distance > 10){
    Serial.println("Good to backup!");
  } else if (distance <=10 && distance > 5){
    Serial.println("Getting close!");
  } else{
    Serial.println("STOP!");
  }
}

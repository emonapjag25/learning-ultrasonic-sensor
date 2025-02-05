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

}

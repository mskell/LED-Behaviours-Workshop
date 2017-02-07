int ledPin = 10;

void setup()

{

pinMode(ledPin, OUTPUT);


}

void loop() {

analogWrite(ledPin, random(80)+35);

delay(random(200));

}

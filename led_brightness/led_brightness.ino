
const int buttonPin = 2;
int buttonState = 0;
int led1 = 3;
int led2 = 5;
int led3 = 6;
int led4 = 9;          // the PWM pins the LEDs are attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 1;    // how many points to fade the LED by

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {

  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    if (brightness >= 447) {
      fadeAmount = 0;
    }
    else fadeAmount = 1;
    if (brightness > 0 && brightness < 256) analogWrite(led1, brightness - 1);
    if (brightness > 63 && brightness < 319)  analogWrite(led2, brightness - 64);   //starts lighting up when led1 is lit 1/4
    if (brightness > 127 && brightness < 383)  analogWrite(led3, brightness - 128); //when led1 is 2/4
    if (brightness > 191)  analogWrite(led4, brightness - 192);   //when led1 is 3/4
    brightness = brightness + fadeAmount;
    delay(20);
  } else {
    if (brightness <= 0) {
      fadeAmount = 0;
    }
    else fadeAmount = -1;

    if (brightness > 0 && brightness < 256) analogWrite(led1, brightness - 1);
    if (brightness > 63 && brightness < 319)  analogWrite(led2, brightness - 64);   //starts lighting up when led1 is lit 1/4
    if (brightness > 127 && brightness < 383)  analogWrite(led3, brightness - 128); //when led1 is 2/4
    if (brightness > 191)  analogWrite(led4, brightness - 192);   //when led1 is 3/4
    brightness = brightness + fadeAmount;
    delay(13);
  }

}

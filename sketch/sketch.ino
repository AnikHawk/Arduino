int sensorPin = 1;
int switchPin = 5;
bool toggle = false;

void setup()
{
  Serial.begin(9600);
  pinMode(switchPin, INPUT_PULLUP);
}

void loop()
{
  int reading = analogRead(sensorPin);

  float tempCel = (reading / 1024.0) * 500 ;
  float tempFahr = (tempCel * 9.0 / 5.0) + 32.0;

  if (digitalRead(switchPin) == false)
  {
    toggle = !toggle;
  }
  if (toggle == true)
  {
    Serial.print(tempCel); Serial.println(" degrees Celsius\n");
  }
  else
  {
    Serial.print(tempFahr); Serial.println(" degrees Fahrenheit\n");
  }
  delay(500);
}

//Motor A

//int enA = 9;
int in1 = 8;
int in2 = 7;

//Motor B

//int enB = 3;
int in3 = 4;
int in4 = 5;

void setup()
{
  //Set all the motor control pins to output
  // pinMode(enA, OUTPUT);
  // pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

}

void demoOne() {
  //Turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  //analogWrite(enA, 200);

  //Turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  //analogWrite(enB, 200);
  delay(2000);


  //Change motor direction
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(2000);


  //Turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

}


void loop() {
  demoOne();
  delay(1000);

}

int pwmPin = 12;
int pot = A0;
int c1 = 0;
int c2 = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(pwmPin, OUTPUT);
pinMode(pot, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
c2=analogRead(pot);
c1= 1024-c2;
digitalWrite(pwmPin,HIGH);
delayMicroseconds(c1);
digitalWrite(pwmPin,LOW);
delayMicroseconds(c2);
}


int motorPin=9;

void setup() {

  // put your setup code here, to run once:
pinMode(motorPin, OUTPUT);
 }
 
void loop() {
  
for (int i=0; i<=255; i++)
{
  analogWrite(motorPin, i);
  delay(10);
}
delay(500);
for (int i=255; i>=0; i--)

{
  analogWrite(motorPin, i);
  delay(10);
}
delay(500);
}
  // put your main code here, to run repeatedly:




const int reverse4 = 3; //motor 4
const int reverse2 = 40; //motor 2
const int reverse1 = 2; //motor 1
const int reverse3 = 12; //Motor3
double x,y;
int VRsignal1 = 5;//front right motor 1
int VRsignal2 = 7;//back right motor 2

double z,v;
int VRsignal3 = 6;//front left motor 3
int VRsignal4 = 8;//back left motor 4

void setup() {

pinMode(reverse1, OUTPUT);
pinMode(reverse3, OUTPUT);
pinMode(reverse2, OUTPUT);
pinMode(reverse4, OUTPUT);
pinMode(46, OUTPUT); // EL 4
pinMode(45, OUTPUT); // EL 3
pinMode(44, OUTPUT); // EL 2
pinMode(43, OUTPUT); // EL 1
Serial.begin(9600);

}

void loop() {
//Right motors
x=pulseIn(11,HIGH);
y=pulseToPWM(x);
analogWrite(VRsignal1, y);
analogWrite(VRsignal2, y);
//Left motors
z=pulseIn(10,HIGH);
v=pulseToPWM2(z);
analogWrite(VRsignal3, v);
analogWrite(VRsignal4, v);
}
//convert rc pulse to Right motors PWM
int pulseToPWM(int pulse1){
  if (pulse1>1500){
    pulse1 = map(pulse1, 1500,2000,-500,500);
    pulse1 = constrain(pulse1,-255,255);
  }else if (pulse1> 900 && pulse1<1400)//failsafe
  {
    digitalWrite(reverse1, LOW);
    digitalWrite(reverse2, LOW);
    pulse1 = map(pulse1, 1400,1000,-500,500);
    pulse1 = constrain(pulse1,-255,255);
  }else{
    pulse1=0;
    digitalWrite(reverse1, HIGH);
    digitalWrite(reverse2, HIGH);
  }
  Serial.println(pulse1);
  Serial.println(x);
  
  return pulse1;
}

//convert rc pulse to left motors PWM
int pulseToPWM2(int pulse2){
  if (pulse2>1500){
    pulse2 = map(pulse2, 1500,2000,-500,500);
    pulse2 = constrain(pulse2,-255,255);
  }else if (pulse2> 900 && pulse2<1400)//failsafe
  {
    digitalWrite(reverse3, HIGH);
    digitalWrite(reverse4, HIGH);
    pulse2 = map(pulse2, 1400,1000,-500,500);
    pulse2 = constrain(pulse2,-255,255);
  }else{
    pulse2=0;
    digitalWrite(reverse3, LOW);
    digitalWrite(reverse4, LOW);
  }
  Serial.println(pulse2);
  Serial.println(z);
  
  return pulse2;
}

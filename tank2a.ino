
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
digitalWrite(46, HIGH); // EL 4
digitalWrite(45, HIGH); // EL 3
digitalWrite(44, HIGH); // EL 2
digitalWrite(43, HIGH); // EL 1 
}

void loop() {
//Turn control
x=pulseIn(11,HIGH);
y=pulseToPWM(x);

//Left motors
z=pulseIn(10,HIGH);
v=pulseToPWM2(z);
analogWrite(VRsignal3, v);
analogWrite(VRsignal4, v);
analogWrite(VRsignal1, v);
analogWrite(VRsignal2, v);
}
//convert rc pulse to Right motors PWM
int pulseToPWM(int pulse1){
  if (pulse1<1450){
    digitalWrite(44, LOW); // EL 2
    digitalWrite(43, LOW); // EL 1
  
  }else{
   digitalWrite(44, HIGH); // EL 2
   digitalWrite(43, HIGH); // EL 1 
  }
 if (pulse1>1550){
    digitalWrite(46, LOW); // EL 4
    digitalWrite(45, LOW); // EL 3
  
  }else{
   digitalWrite(46, HIGH); // EL 4
    digitalWrite(45, HIGH); // EL 3 
  } 
  
  Serial.println(pulse1);
  Serial.println(x);
  
  return pulse1;
}

//convert rc pulse to left motors PWM
int pulseToPWM2(int pulse2){
  if (pulse2>1500){
    pulse2 = map(pulse2, 1550,2000,-500,500);
    pulse2 = constrain(pulse2,-255,255);
  }else if (pulse2> 900 && pulse2<1400)//failsafe
  {
    digitalWrite(reverse3, HIGH);
    digitalWrite(reverse4, HIGH);
    digitalWrite(reverse1, LOW);
    digitalWrite(reverse2, LOW);
    pulse2 = map(pulse2, 1450,1000,-500,500);
    pulse2 = constrain(pulse2,-255,255);
  }else{
    pulse2=0;
    digitalWrite(reverse3, LOW);
    digitalWrite(reverse4, LOW);
    digitalWrite(reverse1, HIGH);
    digitalWrite(reverse2, HIGH);
  }
  
  Serial.println(pulse2);
  Serial.println(z);
 
  return pulse2;
}


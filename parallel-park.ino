  #define INL1 12
  #define INL2 13
  #define PWML 3
  
  //right motor setup
  #define INR1 7
  #define INR2 8
  #define PWMR 9

  //HCSR1 setup
  #define TRIG1 6
  #define ECHO1 4
  #define TRIG2 2 
  #define ECHO2 10
  
void setup() {
  // put your setup code here, to run once:
  
  pinMode(PWML,OUTPUT);
  pinMode(PWMR,OUTPUT);
  pinMode(INL1,OUTPUT);
  pinMode(INL2,OUTPUT);
  pinMode(INR1,OUTPUT);
  pinMode(INR2,OUTPUT);

  //Serial.begin (9600);
  pinMode(TRIG1, OUTPUT);
  pinMode(ECHO1, INPUT);
  pinMode(TRIG2, OUTPUT);
  pinMode(ECHO2, INPUT);
}
long duration, cm, dstcF, dstcR,uzaklik3,sure3;
int a=0;
int p=1;
long threedata[3];
unsigned long interval = 0;
void loop() {
  dstcF = distanceFront();
  dstcR = distanceRight();
  while(p==1){
    dstcF = distanceFront();
    dstcR = distanceRight();
    delay(100);
    fullForward();  
    if(dstcR<=22){
      fullStop();
      delay(1000);
      p+=1;
    }
 }

 while(p==2){
  dstcF = distanceFront();
  dstcR = distanceRight();
  delay(100);
  fullForward();
 
  if(dstcR>=22){
    fullStop();
    delay(1000);
    p+=1;
  }
 }
  while(p==3){
    dstcF = distanceFront();
    dstcR = distanceRight();
    delay(100);
    fullForward();
     
    if(dstcR<=22){
      fullStop();
      delay(1000);
      p+=1;
    }
  }
  
  while(p==4){
    dstcF = distanceFront();
    dstcR = distanceRight();
    delay(100);
    parkEt();
    p=5; 
  } 
}
long distanceFront(){
  long cm1,cm2,cm3;
  digitalWrite(TRIG1, LOW);
  delay(5);
  digitalWrite(TRIG1, HIGH);
  delay(10);
  digitalWrite(TRIG1, LOW);
  duration = pulseIn(ECHO1, HIGH);
  cm1 = (duration/2)/ 29.1;
  cm2 = (duration/2)/ 29.1;
  cm3 = (duration/2)/ 29.1;
  cm = (cm1+cm2+cm3)/3;
  delay(50);
  return cm;
}
long distanceRight(){
  long cm1,cm2,cm3;
  digitalWrite(TRIG2, LOW);
  delay(5);
  digitalWrite(TRIG2, HIGH);
  delay(10);
  digitalWrite(TRIG2, LOW);
  duration = pulseIn(ECHO2, HIGH);
  cm1 = (duration/2)/ 29.1;
  cm2 = (duration/2)/ 29.1;
  cm3 = (duration/2)/ 29.1;
  cm = (cm1+cm2+cm3)/3;
  delay(50);
  return cm;
}
void backward() {
  digitalWrite(INL1, HIGH);
  digitalWrite(INR1, HIGH);
  digitalWrite(INL2, LOW);
  digitalWrite(INR2, LOW);
  analogWrite(PWML,120);
  analogWrite(PWMR,151);
  
}
void fullForward() {
  digitalWrite(INL1, LOW);
  digitalWrite(INR1, LOW);
  digitalWrite(INL2, HIGH);
  digitalWrite(INR2, HIGH);
  analogWrite(PWML,120);
  analogWrite(PWMR,150);  //çizgi 159 çizgisiz 156
}

void forward() {
  digitalWrite(INL1, LOW);
  digitalWrite(INR1, LOW);
  digitalWrite(INL2, HIGH);
  digitalWrite(INR2, HIGH);
  analogWrite(PWML,116);
  analogWrite(PWMR,144); 
}

void fullStop() {
  digitalWrite(INL1, LOW);
  digitalWrite(INR1, LOW);
  digitalWrite(INL2, LOW);
  digitalWrite(INR2, LOW);
  
  analogWrite(PWML,0);
  analogWrite(PWMR,0);
  
}
/*
void turnRight() {
  digitalWrite(INL1, LOW);
  digitalWrite(INR1, LOW);
  digitalWrite(INL2, HIGH);
  digitalWrite(INR2, HIGH);
  analogWrite(PWML,100);
  analogWrite(PWMR,0);
}
void turnRight90() {
  turnRight();
  delay(900);
  fullStop();
}
void turnLeft() {
  digitalWrite(INL1, HIGH);
  digitalWrite(INR1, LOW);
  digitalWrite(INL2, LOW);
  digitalWrite(INR2, HIGH);
  
  analogWrite(PWML,0);
  analogWrite(PWMR,95);
}
void turnLeft90() {
  turnLeft();
  delay(950);
  fullStop();
}
//smart commands
void turnLeft180() {
  turnLeft();
  delay(950);
  fullStop();
}
int turnLeftFor(int leftTime) {
  turnLeft();
  delay(leftTime);
  fullStop();
}
void forwardFor(int forwardTime) {
  fullForward();
  delay(forwardTime);
  fullStop();
}
void backFor(int backTime) {
  backward();
  delay(backTime);
  fullStop();
}
void rotateLeft() {
  digitalWrite(INL1, LOW);
  digitalWrite(INR1, LOW);
  digitalWrite(INL2, HIGH);
  digitalWrite(INR2, HIGH);
  analogWrite(PWML,100);
  analogWrite(PWMR,125);  
}
void rotateRight() {
  digitalWrite(INL1, LOW);
  digitalWrite(INR1, LOW);
  digitalWrite(INL2, HIGH);
  digitalWrite(INR2, HIGH);
  analogWrite(PWML,130);
  analogWrite(PWMR,110);  
}
*/


void solGeri(){

  digitalWrite(INR1, LOW); // Sağ motorun ileri hareketi pasif
  digitalWrite(INR2, HIGH); // Sağ motorun geri hareketi aktif
  analogWrite(PWMR, 0); // Sağ motorun hızı 150

  digitalWrite(INL1, HIGH); // Sol motorun ileri hareketi pasif
  digitalWrite(INL2, LOW); // Sol motorun geri hareketi aktif
  analogWrite(PWML, 140); // Sol motorun hızı 150
  
}

void sagGeri(){

  digitalWrite(INR1, HIGH); // Sağ motorun ileri hareketi pasif
  digitalWrite(INR2, LOW); // Sağ motorun geri hareketi aktif
  analogWrite(PWMR, 170); // Sağ motorun hızı 150

  digitalWrite(INL1, HIGH); // Sol motorun ileri hareketi pasif
  digitalWrite(INL2, LOW); // Sol motorun geri hareketi aktif
  analogWrite(PWML, 0); // Sol motorun hızı 150
  
}

void parkEt(){
  backward();
  delay(700);
  fullStop();
  delay(1000);
  solGeri();
  delay(600);
  fullStop();
  delay(1000);
  backward();
  delay(900);
  fullStop();
  delay(1000);
  sagGeri();
  delay(700);
  fullStop();
  delay(1000);
}

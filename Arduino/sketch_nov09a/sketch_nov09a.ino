const int enA = 6;
const int in1 = 7;
const int in2 = 8;
const int in3 = 9;
const int in4 = 10;
const int enB = 11;
void ForwardLeft()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}
void BackLeft()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}
void BreakLeft()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}
void ForwardRight()
{
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void BackRight()
{
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void BreakRight()
{
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void Forward()
{
  ForwardRight();
  ForwardLeft();
}
void Back()
{
  BackRight();
  BackLeft();
}
void Break()
{
  BreakLeft();
  BreakRight();
}
void SpeedEnA(uint8_t a)
{
  analogWrite(enA,a);
}
void SpeedEnB(uint8_t b)
{
  analogWrite(enB,b);
}
void TurnLeft(){
  BreakLeft();
  ForwardRight();
}
void TurnRight(){
  BreakRight();
  ForwardLeft();
}
void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(2,OUTPUT);
  digitalWrite(2,HIGH);
  Serial.begin(9600);
}
int Black=360,ENA=105+50,ENB=88+50,A,B,C,D,state=0,beforestate=0,turn=530,debounceTime=-300;
bool a=0,b=0,c=0,d=0,e=0;
void loop() {
 A = analogRead(A0); 
 B = analogRead(A1);
 C = analogRead(A2);
 D = analogRead(A3);
 Serial.print(A);
 Serial.print(" ");
 Serial.print(B);
 Serial.print(" ");
 Serial.print(C);
 Serial.print(" ");
 Serial.println(D);
 a = A<Black;
 b = B<Black;
 c = C<Black;
 d = D<Black;
 /*Serial.print(a);
 Serial.print(" ");
 Serial.print(b);
 Serial.print(" ");
 Serial.print(c);
 Serial.print(" ");
 Serial.println(d);
/* Serial.print(ENA);
 Serial.print(" ");
 Serial.print(ENB);
 Serial.print("\n");*/
  if(!b&&c){
  TurnRight();
  }else
  if(b&&!c){
  TurnLeft();
  }else
  Forward();
  SpeedEnA(ENA);
  SpeedEnB(ENB);
 //Serial.println(state);
  if((a||d))
  {
    if(!e)
    {
    state++;
    e=true;
    }  
  }else e=false;
  //Serial.println(state);
  if(state!=beforestate)
  {
    if(state==1) {/*TurnRight();delay(turn+200);*/delay(100);Break();delay(500);ForwardLeft();BackRight();delay(turn/2+150);}
    if(state==4) {Break();delay(500);Back();delay(1500);}
    if(state==5) {delay(175);Break();delay(500);ForwardLeft();BackRight();delay(turn/2+170);}
    if(state==6) {delay(85);Break();delay(500);ForwardRight();BackLeft();delay(turn/2+170);}
    if(state==7) {delay(80);Break();delay(500);ForwardRight();BackLeft();delay(turn/2+210);}
    if(state==8) {delay(150);Break();delay(500);ForwardLeft();BackRight();delay(turn/2+210);Back();delay(1000);Break();delay(500);Forward();delay(1000);}
    if(state==10) {delay(200);ForwardLeft();BackRight();delay(turn/2+120);}
    if(state==11) {delay(1000);Break();while(1){};}
    beforestate=state;
  }
}

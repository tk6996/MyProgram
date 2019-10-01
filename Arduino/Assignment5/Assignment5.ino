const int Switch_L = 13,Switch_R = 12,Red=2,Green=3,buzzer=8,discrepancy=2;
int RSL=1,RSR=1,kR=0,kL=0,status_sound=0,off=1,x,y,z,timer1_counter,d=0,e=1,count=1;
struct posi
{
  int x,y,z;
} pos[65];
void Set_calibrate();
void noise();
void setup() {
  pinMode(Switch_L,INPUT_PULLUP);
  pinMode(Switch_R,INPUT_PULLUP);
  pinMode(Red,OUTPUT);
  pinMode(Green,OUTPUT);
  digitalWrite(Red,1);
  digitalWrite(Green,1);
  Serial.begin(9600);
    // initialize timer1 
  noInterrupts();           // disable all interrupts
  TCCR1A = 0;
  TCCR1B = 0;

  timer1_counter = 3036;   // preload timer 65536-16MHz/256/1Hz
  
  TCNT1 = timer1_counter;   // preload timer
  TCCR1B |= (1 << CS12);    // 256 prescaler 
  TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt
  interrupts();             // enable all interrupts
}
void loop() {
  x=analogRead(0);
  y=analogRead(1);
  z=analogRead(2);
  Serial.print(x);Serial.print(" ");
  Serial.print(y);Serial.print(" ");
  Serial.print(z);Serial.print(" ");
  Serial.print(pos[0].x);Serial.print(" ");
  Serial.print(pos[0].y);Serial.print(" ");
  Serial.println(pos[0].z);
  if(RSL!=digitalRead(Switch_L))if((RSL==0)&&status_sound==0){delay(500);digitalWrite(Green,0);Set_calibrate();off=0;}
  RSL=digitalRead(Switch_L);
  RSR=digitalRead(Switch_R);
  if(RSR==0){off=1;if(RSR-1)noTone(buzzer);status_sound=0;digitalWrite(Red,1);digitalWrite(Green,1);}
  if(off==0)
  {
  if((x>=pos[0].x-discrepancy&&x<=pos[0].x+discrepancy)&&(y>=pos[0].y-discrepancy&&y<=pos[0].y+discrepancy)&&(z>=pos[0].z-discrepancy&&z<=pos[0].z+discrepancy)){Serial.println("DDDDDDDD");}else {Serial.println("NNNNNNNNNNNNNNNNNN ");status_sound=1;}
  if(x>=pos[0].x-discrepancy&&x<=pos[0].x+discrepancy) Serial.println("1"); else Serial.println("2000000000000000000");
  if(y>=pos[0].y-discrepancy&&y<=pos[0].y+discrepancy) Serial.println("3"); else Serial.println("4000000000000000000");
  if(z>=pos[0].z-discrepancy&&z<=pos[0].z+discrepancy) Serial.println("5"); else Serial.println("6000000000000000000");
  if(status_sound==1) {noise();digitalWrite(Green,1);digitalWrite(Red,0);}
  }
}
void Set_calibrate()
{
  pos[0]={0,0,0};
  for(int i=1;i<=64;i++)
  {
    pos[i]={analogRead(0),analogRead(1),analogRead(2)};
    pos[0].x+=pos[i].x;
    pos[0].y+=pos[i].y;
    pos[0].z+=pos[i].z;
  }
  pos[0].x/=64;
  pos[0].y/=64;
  pos[0].z/=64;
}
void noise()
{
  if(d!=e){e=d;
  if(e==0)tone(buzzer,2000,1000);
  if(e==1)tone(buzzer,300,1000);
  }
}
ISR(TIMER1_OVF_vect)        // interrupt service routine 
{
  TCNT1 = timer1_counter;   // preload timer
  if(d==1)d=0;else d=1;
}


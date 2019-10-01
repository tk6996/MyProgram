const uint8_t Led1 = 13,Led2=12,Led3=11,Led4=10,Led5=9,Led6=8,Led7=7,Led8=6,SW1=3,SW2=2;
void setup()
{
    Serial.begin(9600);
    for(int i=13; i>=6; i--)
    pinMode(i,OUTPUT);
    pinMode (2,INPUT_PULLUP);
    pinMode (3,INPUT_PULLUP);
}
bool P1=false,P2=false,Bit[8]={false};
void loop()
{
    P1 =!digitalRead(SW1);
    //Serial.println(P1);
    if(P1)
    {
        Serial.println("Start");
        delay(1000);
        for(int i=3;i<8;i++)
        {
            digitalWrite(13-i,HIGH);
            uint64_t t = millis();
            Serial.print("Bit : ");
            Serial.println(i);
            while(t>millis()-1000)
            {
                P2 = !digitalRead(SW2);
                if(P2) Bit[i]=true; 
            }
            digitalWrite(13-i,LOW);
        }
        for(int i =3; i<8 ; i++)
        {
            Serial.print(Bit[i]);
            Serial.print(" ");
        }
        Serial.println("");
        while(true)
        {
            for(int i=0;i<8;i++)
            {
                digitalWrite(13-i,Bit[i]);
            }
            delay(500);
            bool temp=Bit[0];
            for(int i=0;i<7;i++)
            {
                Bit[i] = Bit[i+1];
            }
            Bit[7]=temp;
        }
    }
}
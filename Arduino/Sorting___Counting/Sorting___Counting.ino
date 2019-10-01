#include <LiquidCrystal_I2C.h>
#include "Adafruit_MCP23017.h"
#include <TimerObject.h>
#include <Wire.h>
#include <EEPROM.h>
#include <stdio.h>
#include <Servo.h>

Servo servo[4];
LiquidCrystal_I2C lcd(0x27, 16, 2);
Adafruit_MCP23017 mcp;
TimerObject *cursorBlink = new TimerObject(500, &cursorActive);
const long debounceDelay = 50L;
int one = 0, two = 0, five = 0, ten = 0, total = 0;
int wd_1 = 0, wd_2 = 0, wd_5 = 0, wd_10 = 0;
int state = 0;
bool cursorTurnOn = false;
bool withdrawMode = false;
bool saving = true;
uint8_t fristone = 0, fristtwo = 0, fristfive = 0, fristten = 0;
uint8_t lastButtonState_0 = 0, lastButtonState_1 = 0, lastButtonState_2 = 0, lastButtonState_3 = 0;
long duringSaveTime = 0;
void setup()
{
  Serial.begin(115200);
  EEPROM.begin(512);
  lcd.begin();
  mcp.begin();
  mcp.pinMode(7, INPUT);
  mcp.pinMode(6, INPUT);
  mcp.pinMode(5, INPUT);
  mcp.pinMode(4, INPUT);
  mcp.pinMode(3, INPUT);
  mcp.pinMode(2, INPUT);
  mcp.pinMode(15, INPUT);
  mcp.pinMode(0, INPUT);
  pinMode(A0, OUTPUT);
  servo[0].attach(D5);
  servo[1].attach(D6);
  servo[2].attach(D7);
  servo[3].attach(D8); 
  resetBank();
  one = EEPROM.read(0);
  two = EEPROM.read(1);
  five = EEPROM.read(2);
  ten = EEPROM.read(3);
  displayStart();
}
void resetBank()
{
  EEPROM.write(0, 0);
  EEPROM.write(1, 0);
  EEPROM.write(2, 0);
  EEPROM.write(3, 0);
  EEPROM.commit();
}
void saveBank()
{
  Serial_println("Saving");
  EEPROM.write(0, (uint8_t)(one));
  EEPROM.write(1, (uint8_t)(two));
  EEPROM.write(2, (uint8_t)(five));
  EEPROM.write(3, (uint8_t)(ten));
  EEPROM.commit();
}
template <typename Arg, typename... Args>
void Serial_println(Arg arg, Args... args)
{
  Serial.print(arg);
  Serial_println(args...);
}
template <typename Arg>
void Serial_println(Arg arg)
{
  Serial.println(arg);
}
void printColumn()
{
  lcd.setCursor(0, 0);
  if (state == 0)
    lcd.print(" 1  2  5 10 Bath");
  else
    lcd.print(" 1  2  5 10 Push");
}
void printAmount()
{
  printOne(one);
  printTwo(two);
  printFive(five);
  printTen(ten);
  printTotal(total);
}
void printOne(int val)
{
  char buf[3];
  lcd.setCursor(0, 1);
  sprintf(buf, "%2d", val);
  lcd.print(buf);
}
void printTwo(int val)
{
  char buf[3];
  lcd.setCursor(3, 1);
  sprintf(buf, "%2d", val);
  lcd.print(buf);
}
void printFive(int val)
{
  char buf[3];
  lcd.setCursor(6, 1);
  sprintf(buf, "%2d", val);
  lcd.print(buf);
}
void printTen(int val)
{
  char buf[3];
  lcd.setCursor(9, 1);
  sprintf(buf, "%2d", val);
  lcd.print(buf);
}
void printTotal(int val)
{
  char buf[4];
  lcd.setCursor(12, 1);
  sprintf(buf, "%4d", val);
  lcd.print(buf);
}
void sensorOneAct()
{
  one++;
  if (state == 0)
    printOne(one);
  //delay(300);
}
void sensorTwoAct()
{
  two++;
  if (state == 0)
    printTwo(two);
  //delay(300);
}
void sensorFiveAct()
{
  five++;
  if (state == 0)
    printFive(five);
  //delay(300);
}
void sensorTenAct()
{
  ten++;
  if (state == 0)
    printTen(ten);
  //delay(300);
}
void totalAct(int bank)
{
  if (bank != total)
  {
    total = bank;
    saving = false;
    duringSaveTime = millis();
  }
  if (state == 0)
    printTotal(total);
}
void displayStart()
{
  lcd.clear();
  printColumn();
  printAmount();
}
void cursorActive()
{
  if (cursorTurnOn = !cursorTurnOn)
    lcd.cursor_on();
  else
    lcd.cursor_off();
  //Serial.println("Hello");
}
void shortPulseSwitch(int pinNum, uint8_t &lastButtonState, uint8_t active, void (*fun)())
{
  uint8_t buttonState = mcp.digitalRead(pinNum);
  if (buttonState != lastButtonState)
  {
    if (buttonState == active)
      fun();
  }
  lastButtonState = buttonState;
}
void func_switch_0()
{
  state++;
  switch (state)
  {
  case 1:
    printColumn();
    wd_1 = wd_2 = wd_5 = wd_10 = 0;
    printOne(wd_1);
    printTwo(wd_2);
    printFive(wd_5);
    printTen(wd_10);
    lcd.setCursor(12, 1);
    lcd.print("  OK");
    lcd.setCursor(1, 1);
    cursorBlink->Start();
    break;
  case 2:
    lcd.setCursor(4, 1);
    break;
  case 3:
    lcd.setCursor(7, 1);
    break;
  case 4:
    lcd.setCursor(10, 1);
    break;
  case 5:
    lcd.setCursor(15, 1);
    break;
  case 6:
    withdrawActive();
    break;
  default:
    break;
  }
}
void func_switch_1()
{
  switch (state)
  {
  case 1:
    wd_1++;
    if (wd_1 > one)
      wd_1 = 0;
    printOne(wd_1);
    lcd.setCursor(1, 1);
    break;
  case 2:
    wd_2++;
    if (wd_2 > two)
      wd_2 = 0;
    printTwo(wd_2);
    lcd.setCursor(4, 1);
    break;
  case 3:
    wd_5++;
    if (wd_5 > five)
      wd_5 = 0;
    printFive(wd_5);
    lcd.setCursor(7, 1);
    break;
  case 4:
    wd_10++;
    if (wd_10 > ten)
      wd_10 = 0;
    printTen(wd_10);
    lcd.setCursor(10, 1);
    break;
  default:
    break;
  }
}
void func_switch_2()
{
  switch (state)
  {
  case 1:
    wd_1--;
    if (wd_1 < 0)
      wd_1 = one;
    printOne(wd_1);
    lcd.setCursor(1, 1);
    break;
  case 2:
    wd_2--;
    if (wd_2 < 0)
      wd_2 = two;
    printTwo(wd_2);
    lcd.setCursor(4, 1);
    break;
  case 3:
    wd_5--;
    if (wd_5 < 0)
      wd_5 = five;
    printFive(wd_5);
    lcd.setCursor(7, 1);
    break;
  case 4:
    wd_10--;
    if (wd_10 < 0)
      wd_10 = ten;
    printTen(wd_10);
    lcd.setCursor(10, 1);
    break;
  default:
    break;
  }
}
void func_switch_3()
{
  state--;
  switch (state)
  {
  case 0:
    displayStart();
    break;
  case 1:
    lcd.setCursor(1, 1);
    break;
  case 2:
    lcd.setCursor(4, 1);
    break;
  case 3:
    lcd.setCursor(7, 1);
    break;
  case 4:
    lcd.setCursor(10, 1);
    break;
  default:
    break;
  }
}
void withdrawActive()
{
  for (int i = 0; i < wd_1; i++)
  {
    servoPush(0);
  }
  servo[0].write(90);
  delay(15);
  one -= wd_1;
  for (int i = 0; i < wd_2; i++)
  {
    servoPush(1);
  }
  servo[1].write(90);
  delay(15);
  two -= wd_2;
  for (int i = 0; i < wd_5; i++)
  {
    servoPush(2);
  }
  servo[2].write(90);
  delay(15);
  five -= wd_5;
  for (int i = 0; i < wd_10; i++)
  {
    servoPush(3);
  }
  servo[3].write(90);
  delay(15);
  //Serial_println("Finish");
  ten -= wd_10;
  total = one + 2 * two + 5 * five + 10 * ten;
  state = 0;
  displayStart();
}
void servoPush(int index)
{
  for (int angle = 90; angle >= 0; angle -= 15)
  {
    servo[index].write(angle);
    delay(15);
  }
  for (int angle = 0; angle <= 90; angle += 15)
  {
    servo[index].write(angle);
    delay(15);
  }
  delay(500);
}
void loop()
{
  Serial_println(mcp.digitalRead(7), " ", mcp.digitalRead(6), " ", mcp.digitalRead(5), " ", mcp.digitalRead(4), " ", analogRead(A0));
  shortPulseSwitch(7, fristone, LOW, sensorOneAct);
  shortPulseSwitch(6, fristtwo, LOW, sensorTwoAct);
  shortPulseSwitch(5, fristfive, LOW, sensorFiveAct);
  shortPulseSwitch(4, fristten, LOW, sensorTenAct);
  totalAct(one + 2 * two + 5 * five + 10 * ten);
  //Serial_println(saving," ",duringSaveTime," ",millis() - duringSaveTime);
  /*if (!saving)
    if (millis() - duringSaveTime > 5000)
    {
      saveBank();
      saving = true;
    }*/
  //Serial_println(mcp.digitalRead(0)," ",mcp.digitalRead(15)," ",mcp.digitalRead(2)," ",mcp.digitalRead(3));
  //Serial.println(state);
  shortPulseSwitch(0, lastButtonState_0, HIGH, func_switch_0);
  if (cursorBlink->isEnabled() || cursorTurnOn)
    cursorBlink->Update();
  if (state > 0)
  {
    shortPulseSwitch(15, lastButtonState_1, HIGH, func_switch_1);
    shortPulseSwitch(2, lastButtonState_2, HIGH, func_switch_2);
    shortPulseSwitch(3, lastButtonState_3, HIGH, func_switch_3);
  } //delay(250);
  if (state == 0)
    cursorBlink->Stop();
}
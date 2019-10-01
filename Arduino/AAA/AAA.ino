#include <Wire.h>
#include "Adafruit_MCP23017.h"
// Instance of MCP23017 library
Adafruit_MCP23017 mcp;
void setup() {
  Serial.begin(9600);
  mcp.begin();
  mcp.pinMode(7, OUTPUT);
  mcp.pinMode(0, INPUT);
  mcp.pullUp(0,LOW);
  pinMode(D0,INPUT);
  pinMode(A0,INPUT);
}
void loop() {
  Serial.println(analogRead(A0));/*mcp.digitalRead(0)*/
  mcp.digitalWrite(7,mcp.digitalRead(0));
}

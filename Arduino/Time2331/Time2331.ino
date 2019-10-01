/*
 * TimeRTC.pde
 * Example code illustrating Time library with Real Time Clock.
 * This example is identical to the example provided with the Time Library,
 * only the #include statement has been changed to include the DS3232RTC library.
 *----------------------------------------------------------------------
 * Display the date and time from a DS3231 or DS3232 RTC every second.  
 * Display the temperature once per minute. (The DS3231 does a          
 * temperature conversion once every 64 seconds. This is also the       
 * default for the DS3232.)                                             
 *                                                                      
 * Set the date and time by entering the following on the Arduino       
 * serial monitor:                                                      
 *    year,month,day,hour,minute,second,                                
 *                                                                      
 * Where                                                                
 *    year can be two or four digits,                                   
 *    month is 1-12,                                                    
 *    day is 1-31,                                                      
 *    hour is 0-23, and                                                 
 *    minute and second are 0-59.                                       
 *                                                                      
 * Entering the final comma delimiter (after "second") will avoid a     
 * one-second timeout and will allow the RTC to be set more accurately. 
 *                                                                      
 * No validity checking is done, invalid values or incomplete syntax    
 * in the input will result in an incorrect RTC setting.                
 *                                                                      
 * Jack Christensen 08Aug2013                                           
 *                                                                      
 * Tested with Arduino 1.0.5, Arduino Uno, DS3231/Chronodot, DS3232.    
 *                                                                      
 * This work is licensed under the Creative Commons Attribution-        
 * ShareAlike 3.0 Unported License. To view a copy of this license,     
 * visit http://creativecommons.org/licenses/by-sa/3.0/ or send a       
 * letter to Creative Commons, 171 Second Street, Suite 300,            
 * San Francisco, California, 94105, USA.                               
 *----------------------------------------------------------------------
 */ 
 
#include <DS3232RTC.h>    //http://github.com/JChristensen/DS3232RTC
#include <Time.h>         //http://www.arduino.cc/playground/Code/Time  
#include <Wire.h>         //http://arduino.cc/en/Reference/Wire (included with Arduino IDE)
//
#include <LiquidCrystal_I2C.h>
//
#include <Streaming.h>     //http://arduiniana.org/libraries/streaming/
//

LiquidCrystal_I2C lcd(0x27,16,2);//LCD address 0x3F 16chars 2line   SCL pin A4, SDA pin A5
                                 //LCD address 0x27

void setup(void)
{
    Serial.begin(9600);
    lcd.init();                    //initialize the lcd 
    lcd.init();
    lcd.backlight();
    //
    //
    setSyncProvider(RTC.get);   // the function to get the time from the RTC
    if(timeStatus() != timeSet)
    { 
        lcd.setCursor(0,0);            
        lcd.print(" RTC SYS ERROR  ");
        lcd.setCursor(0,1);
        lcd.print("                ");
        delay(1000);
        lcd.setCursor(0,0);
        lcd.print("                ");
        lcd.setCursor(0,1);
        lcd.print("                ");
    }   
    else
    {
        lcd.setCursor(0,0);            
        lcd.print("   RTC SYS OK   ");
        lcd.setCursor(0,1);
        lcd.print(" PROGRAM BY JOO ");
        delay(3000);
        lcd.setCursor(0,0);
        lcd.print("                ");
        lcd.setCursor(0,1);
        lcd.print("                ");
     }    
}

void loop(void)
{
   LCD1602();
   clockset();
}
//
//
//
//
//
//
//settime 16,04,04,09,17,00   yy,m,d,h,m,s
void clockset(void)
{
    static time_t tLast;
    time_t t;
    tmElements_t tm;
    Serial.println("input = yy,m,d,h,m,s");
    delay(1000);
    //check for input to set the RTC, minimum length is 12, i.e. yy,m,d,h,m,s
    if (Serial.available() >= 12)
    {
        //note that the tmElements_t Year member is an offset from 1970,
        //but the RTC wants the last two digits of the calendar year.
        //use the convenience macros from Time.h to do the conversions.
        int y = Serial.parseInt();
        if (y >= 100 && y < 1000)
        {
            Serial << F("Error: Year must be two digits or four digits!") << endl;
        }    
        else 
        {
            if (y >= 1000)
            {
                tm.Year = CalendarYrToTm(y);
            }
            else    //(y < 100)
            {
              tm.Year = y2kYearToTm(y);
              tm.Month = Serial.parseInt();
              tm.Day = Serial.parseInt();
              tm.Hour = Serial.parseInt();
              tm.Minute = Serial.parseInt();
              tm.Second = Serial.parseInt();
              t = makeTime(tm);
              RTC.set(t);        //use the time_t value to ensure correct weekday is set
              setTime(t);        
              Serial << F("RTC set to: ");
              Serial << endl;
              //
              lcd.setCursor(0,0);
              lcd.print("  SET CLOCK OK  ");
              lcd.setCursor(0,1);
              lcd.print(" PROGRAM BY JOO ");
              delay(3000);
              lcd.setCursor(0,0);
              lcd.print("                ");
              lcd.setCursor(0,1);
              lcd.print("                ");
            }
          }
        }
} 
//
//
//
//
//
//
//lcd display
void LCD1602(void)
{
    lcd.setCursor(0,0);
    if(hour() < 10)
     {
       lcd.print("0");
     }
    lcd.print(hour());
    //
    lcd.print(":");
    if(minute() < 10)
     {
       lcd.print("0");
     }
    lcd.print(minute());
    //
    lcd.print(":");
    if(second() < 10)
     {
       lcd.print("0");
     }
    lcd.print(second());
    
    //
    //
    //
    lcd.setCursor(9,0);
    lcd.print(RTC.temperature()/4.);
    lcd.print("C");
    //
    //
    //
    lcd.setCursor(3,1);
    if(day() < 10)
     {
       lcd.print("0");
     }
    lcd.print(day());
    lcd.print("/");
    //
    if(month() < 10)
     {
       lcd.print("0");
     }
    lcd.print(month());
    lcd.print("/");
    //
    lcd.print(year());
}

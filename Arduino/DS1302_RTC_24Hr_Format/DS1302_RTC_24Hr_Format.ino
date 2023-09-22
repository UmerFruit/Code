#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
#include <DS1302.h>
DS1302 rtc(6, 7, 8); //RST,DAT,CLK Pins of the DS1302 Module 


void setup()
{
  rtc.halt(false);
  rtc.writeProtect(false);
  lcd.backlight();
  lcd.init();
  lcd.begin(16, 2);
  //comment this section later
  //rtc.setDOW(TUESDAY);      //name of the day of the week
  //rtc.setTime(13, 59, 00);  //Hour, Min, Sec 
  //rtc.setDate(04, 8, 2020); //Day, Month, Year
}

void loop()
{
  lcd.setCursor(0,1);
  lcd.print("Time:");
  lcd.setCursor(5, 1);
  lcd.print(rtc.getTimeStr());
  lcd.setCursor(0, 0);
  lcd.print("Date:");
  lcd.setCursor(5,0);
  lcd.print(rtc.getDateStr(FORMAT_SHORT, FORMAT_LITTLEENDIAN, '/'));
  //lcd.setCursor(13,1);
  //lcd.print(rtc.getDOWStr());
  delay (1000); 
}

#include <LiquidCrystal_I2C.h>
//LiquidCrystal I2C Library by Frank de Brabander

LiquidCrystal_I2C lcd(0x27, 16, 2);
/*Making variabel "lcd" and
setting I2C address 0x27, 16 column and 2 rows */

void setup() {
  lcd.init();               // initialize the lcd
  lcd.backlight();          // open the backlight
}

void loop()
    {
    lcd.setCursor(0, 1); // print on first coloumn on second row (bottom)
    lcd.scrollDisplayLeft(); //text will be scrolling from right to left
    delay(200); //speed of scrolling
    lcd.print("Geser Kiri"); //text that printed and scrolled
    }

    /*
    other command:
    lcd.scrollDisplayRight(); -> to scroll the text from left to right
    lcd.clear(); -> to clear lcd before adding other text
    */

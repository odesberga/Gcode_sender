#include <Wire.h>

#include <LiquidCrystal_I2C.h>

#define I2C_ADDR 0x3f
#define Rs_pin 0
#define Rw_pin 1
#define En_pin 2
#define BACKLIGHT_PIN 3
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7
LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

byte arrow_up[8] = {
  0b00000,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b00100,
  0b00000,
  0b00000
};

byte arrow_right[8] = {
  0b00000,
  0b00000,
  0b01000,
  0b01000,
  0b00100,
  0b11110,
  0b00100,
  0b01000

};

byte arrow_left[8] = {

  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

byte arrow_down[8] = {
    0b00100,
    0b01110,
    0b10101,
    0b00100,
    0b00100,
    0b10101,
    0b01110,
    0b00100

};
int x_plus=0, x_minus=0, y_plus=0, y_minus=0;

void setup() {
      lcd.begin (20,4);
    lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
    lcd.setBacklight(HIGH);
  // create a new character

  // create a new character
  lcd.createChar(1, arrow_up);
  // create a new character
  lcd.createChar(2, arrow_right);
  // create a new character
  lcd.createChar(3, arrow_down);
  // create a new character
  lcd.createChar(4, arrow_left);
lcd.setCursor(4, 1);
lcd.clear();
Print_coord();
}

void loop() {

}


void Print_coord(){
//lcd.setCursor(4, 1);
lcd.write(1);
lcd.setCursor(4, 2);
lcd.write(3);
lcd.setCursor(3, 2);
lcd.write(4);
lcd.setCursor(5, 2);
lcd.write(2);
}

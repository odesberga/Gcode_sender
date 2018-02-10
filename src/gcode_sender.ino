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
  0b00100,
  0b11110,
  0b00100,
  0b01000,
  0b00000

};

byte arrow_left[8] = {

  0b00000,
  0b00000,
  0b00010,
  0b00100,
  0b01111,
  0b00100,
  0b00010,
  0b00000
};

byte arrow_up_down[8] = {
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
int coord_view_pos[] ={2,0};
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
  lcd.createChar(3, arrow_up_down);
  // create a new character
  lcd.createChar(4, arrow_left);
lcd.setCursor(4, 1);
lcd.clear();
Print_coord();
}

void loop() {

    x_plus++;
    x_minus++;
    y_plus++;
    y_minus++;
    Print_coord();
    delay(100);



}


void Print_coord(){

for (int i=coord_view_pos[0]+3;i>coord_view_pos[0]-4;i--){
    for (int j=coord_view_pos[1];j<coord_view_pos[1]+10;j++){
        lcd.setCursor(j,i);
        lcd.print("");
    }

}

lcd.setCursor(coord_view_pos[1]+4, coord_view_pos[0]-1);
lcd.write(3);
lcd.setCursor(coord_view_pos[1]+3, coord_view_pos[0]-1);
lcd.write(4);
lcd.setCursor(coord_view_pos[1]+5, coord_view_pos[0]-1);
lcd.write(2);

lcd.setCursor(coord_view_pos[1]+5-ln_x_int(x_plus), coord_view_pos[0]-2);
lcd.print(x_plus);
lcd.setCursor(coord_view_pos[1]+5-ln_x_int(x_minus), coord_view_pos[0]);
lcd.print(x_minus);
lcd.setCursor(coord_view_pos[1]+6, coord_view_pos[0]-1);
lcd.print(y_plus);
lcd.setCursor(coord_view_pos[1]+4-ln_y_int(y_minus)-1, coord_view_pos[0]-1);
lcd.print(y_minus);

}

int ln_x_int(int val){
    if (val > 99)
    return 2;
    else if (val < 100)
    return 1;

}
int ln_y_int(int val){
    if (val < 100 && val>9)
    return 2;
    else if (val > 99)
    return 3;
    else
    return 1;
}

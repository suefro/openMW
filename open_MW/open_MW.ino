/*
  Digital timer for microwave ver 1.0
  not tested in real
*/
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <Wire.h>
#include "RTClib.h" //for RTC time module

//menu
#include "U8glib.h"
#include "M2tk.h"
#include "utility/m2ghu8g.h"
U8GLIB_PCD8544 u8g(7, 6, 4, 5, 3);    // SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9, Reset = 8
// Software SPI (slower updates, more flexible pin options):
// pin 7 - Serial clock out (CLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);
RTC_DS1307 rtc;

//gloabal variables: (beware on changes!!)
uint8_t up_button = 12;
uint8_t start_stop_button = 10;
uint8_t down_button = 11;
uint8_t BC_display = 13;
uint8_t relay_on_off = 9;
uint8_t relay_power = 8;
uint8_t door_button = 0;
uint8_t buzzer = 1;

long timer_heat;
long timer_power;
long timer_BC_display;
long timer_end;
int timer_set = 0;
int blink_lcd_main = 0;
int power_mode = 1; //5 modes (keep warm, rozmaržení,350W,500W,750W) -after testing change this value
boolean on_off_mode = true;
boolean stop_imm = true;
boolean menu_select = true;
float openMW_ver = 1.0;

// Edit the following long int number
uint32_t number = 1234;

// Definition of the m2tklib menu
M2_U32NUM(el_num, "a1c4", &number);

// M2tk init
M2tk m2(&el_num, m2_es_arduino, m2_eh_2bs, m2_gh_u8g_bfs);

// U8glib draw procedure: Just call the M2tklib draw procedure
void draw(void) {
    m2.draw();
}


void setup()   {
  Serial.begin(9600);
  //buttons:
  pinMode(up_button, INPUT_PULLUP);
  pinMode(start_stop_button, INPUT_PULLUP);
  pinMode(down_button, INPUT_PULLUP);
  pinMode(door_button, INPUT_PULLUP);
  //relays
  pinMode(relay_on_off, OUTPUT);
  pinMode(relay_power, OUTPUT);
  //display backlight
  pinMode(BC_display, OUTPUT);

  //default set relay
  digitalWrite(relay_on_off, HIGH);
  digitalWrite(relay_power, HIGH);

   // Connect u8glib with m2tklib
  m2_SetU8g(u8g.getU8g(), m2_u8g_box_icon);

  // Assign u8g font to index 0
  m2.setFont(0, u8g_font_7x13);

  

  // Setup keys
  m2.setPin(M2_KEY_SELECT, start_stop_button);
  m2.setPin(M2_KEY_PREV, up_button);
  m2.setPin(M2_KEY_NEXT, down_button);
      

  display.begin();// init done
  display.setContrast(60); //set contrast
  digitalWrite(BC_display, HIGH); //turn on backlight
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0, 0);
  display.println(" Open-MW 2016");
  display.println("");
  display.println("Firmware");
  display.print("version:");
  display.print(openMW_ver);
  display.display();
  delay(2000);
  display.clearDisplay();   // clears the screen and buffer
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
  timer_BC_display = rtc.now().unixtime(); //save unixtime to variable

}
void loop() {

  DateTime now = rtc.now();
  display.setTextSize(2);
  display.clearDisplay();
  display.setCursor(10, 0);
  print2digits(now.hour());
  display.print(":");
  print2digits(now.minute());
  //display.print(":");
  //print2digits(now.second());
  display.println();
  display.setCursor(10, 17);
  display.setTextSize(1);
  print2digits(now.day());
  display.print('/');
  print2digits(now.month());
  display.print('/');
  display.println(now.year(), DEC);
  display.setCursor(0, 27);
  //blinking static text

  if (blink_lcd_main < 70) {
    display.println("UP");
    display.print("Start/Stop");
    display.display();
  }
  if (blink_lcd_main > 70 && blink_lcd_main < 140 ) {
    display.println("timer");
    display.print("quick timer");
    display.display();
  }
  blink_lcd_main++;
  if (blink_lcd_main > 140) blink_lcd_main = 0;

  if (digitalRead(up_button) == LOW) {
    delay(500);
    digitalWrite(BC_display, HIGH);
    timer_BC_display = rtc.now().unixtime();
    //add beep 1x
    timer_mode();

  }

  if (digitalRead(down_button) == LOW) {
    //add beep 1x
    delay(1000);
    if (digitalRead(down_button) == HIGH) {
      digitalWrite(BC_display, HIGH);
      timer_BC_display = rtc.now().unixtime();
    }
    if (digitalRead(down_button) == LOW) { //enter to menu
      
      while(menu_select == true){
        m2.checkKey();
  if ( m2.handleKey() ) {
    u8g.firstPage();  
    do {
      draw();
    } while( u8g.nextPage() );
  }
    if(digitalRead(door_button) == LOW) {
      menu_select = false;
    }
      }
      menu_select = true;
      
      /*//add beep 3x
      display.clearDisplay();
      display.setCursor(0, 0);
      display.setTextSize(2);
      display.print("There will be menu");
      display.display();
      digitalWrite(BC_display, HIGH);
      timer_BC_display = rtc.now().unixtime();
      delay(2000);*/
    }

  }
  //in this menu can start quick timing
  if (digitalRead(start_stop_button) == LOW) {
    //add beep 1x
    if (digitalRead(door_button) == LOW) {
      delay(500);
      quick_heating_timer();
    }
    else
    {
      //add beep 2x
      display.clearDisplay();
      display.setCursor(5, 8);
      display.setTextSize(2);
      display.println("Door");
      display.print(" open!");
      display.display();
      digitalWrite(BC_display, HIGH);
      timer_BC_display = rtc.now().unixtime();
      delay(3000);
    }

  }

  //backlight off set time
  if (rtc.now().unixtime() - timer_BC_display > 20)
  {
    digitalWrite(BC_display, LOW);
  }

}

void heating_timer () {
  DateTime now = rtc.now();
  timer_heat = (rtc.now().unixtime() + timer_set);
  timer_power = rtc.now().unixtime();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  boolean pause_time = false;
  boolean pause_time_button = true;
  digitalWrite(relay_on_off, LOW);
  delay(500);
  while (timer_heat - rtc.now().unixtime() > 0 && stop_imm == true) {

    display.clearDisplay();
    display.setCursor(10, 0);
    display.setTextSize(1);
    display.println("Remaining");
    display.setCursor(20, 10);
    display.println("time");
    display.setCursor(10, 23);
    display.setTextSize(2);
    print2minute(timer_heat - rtc.now().unixtime());
    display.display();
    delay(100);
    if (digitalRead(start_stop_button) == LOW) {
      //add beep 1x
      if (pause_time_button == true) //on pause
      {
        pause_time = true;
        timer_set = (timer_heat - rtc.now().unixtime());
        digitalWrite(relay_on_off, HIGH);
        delay(500);
      }

      if (pause_time_button == false) //off pause
      {
        pause_time = false;
        pause_time_button = true;
        delay(500);
      }

      if (digitalRead(start_stop_button) == LOW) {
        stop_imm = false;
        display.clearDisplay();
        display.setCursor(10, 15);
        display.setTextSize(2);
        display.println("END!");
        display.display();
        delay(3000);
      }
    }

    if (digitalRead(up_button) == LOW) {
      if (timer_heat - rtc.now().unixtime() <= 580) {
        timer_heat = timer_heat + 10;
        //add beep 1x
      }
      if ( pause_time == true) {
        if (timer_set <= 580) {
          timer_set = timer_set + 10;

        }
      }
      delay(200);
    }
    if (digitalRead(down_button) == LOW) {
      //add beep 1x
      if (timer_heat - rtc.now().unixtime() >= 11) {
        timer_heat = timer_heat - 10;
      }
      if ( pause_time == true) {
        if (timer_set >= 5) {
          timer_set = timer_set - 10;

        }
      }
      delay(200);
    }

    if (digitalRead(door_button) == HIGH) {
      //add beep 2x
      stop_imm = false;
    }

    if ( pause_time == true) {
      digitalWrite(relay_on_off, HIGH);
      timer_heat = (rtc.now().unixtime() + timer_set);
      pause_time_button = false;
      digitalWrite(relay_power, HIGH);
    }
    if ( pause_time == false) {
      digitalWrite(relay_on_off, LOW);
      //power function:
      power_timer(2, 10, 10); //number of mode,time on , time off
    }


  }
  digitalWrite(relay_on_off, HIGH);
  digitalWrite(relay_power, HIGH);
  if (stop_imm == true)
  {
    end_program();
  }
  display.clearDisplay();
  display.setCursor(0, 0);
  display.display();
  timer_set = 0;
  stop_imm = true;
  on_off_mode = true;
  digitalWrite(BC_display, HIGH);
  timer_BC_display = rtc.now().unixtime();
}

void quick_heating_timer () {
  digitalWrite(BC_display, HIGH);
  DateTime now = rtc.now();
  timer_heat = (rtc.now().unixtime() + 30);
  timer_power = rtc.now().unixtime();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  digitalWrite(relay_on_off, LOW);
  digitalWrite(relay_power, LOW);
  delay(500);
  while (timer_heat - rtc.now().unixtime() > 0 && stop_imm == true) {

    display.clearDisplay();
    display.setCursor(10, 0);
    display.setTextSize(1);
    display.println("Remaining");
    display.setCursor(20, 10);
    display.println("time");
    display.setCursor(10, 23);
    display.setTextSize(2);
    print2minute(timer_heat - rtc.now().unixtime());
    display.display();
    delay(100);
    if (digitalRead(start_stop_button) == LOW) {
      //add beep 1x
      delay(500);

      if (timer_heat - rtc.now().unixtime() <= 580) {
        timer_heat = timer_heat + 30;
      }

    }

    if (digitalRead(up_button) == LOW) {
      //add beep 1x
      stop_imm = false;
      display.clearDisplay();
      display.setCursor(10, 15);
      display.setTextSize(2);
      display.println("END!");
      display.display();
      delay(3000);

    }

    if (digitalRead(down_button) == LOW) {
      //add beep 1x
      if (timer_heat - rtc.now().unixtime() >= 11) {
        timer_heat = timer_heat - 10;
      }
      delay(200);
    }
    if (digitalRead(door_button) == HIGH) {
      //add beep 2x
      stop_imm = false;
    }
    //power function:
    power_timer(power_mode, 10, 10); //number of mode,time on , time off
  }
  digitalWrite(relay_on_off, HIGH);
  digitalWrite(relay_power, HIGH);
  if (stop_imm == true)
  {
    end_program();
  }
  display.clearDisplay();
  display.setCursor(0, 0);
  display.display();
  timer_set = 0;
  on_off_mode = true;
  stop_imm = true;
  digitalWrite(BC_display, HIGH);
  timer_BC_display = rtc.now().unixtime();
}

void timer_mode () {
  DateTime now = rtc.now();
  digitalWrite(BC_display, HIGH);
  boolean in_timer_mode = true;
  timer_set = 10;
  while (in_timer_mode == true) {
    display.setTextSize(1);
    display.clearDisplay();
    display.setCursor(15, 0);
    display.println("Set Timer");
    display.setTextSize(2);
    display.setCursor(10, 15);
    display.setTextSize(2);
    print2minute(timer_set);
    display.display();

    if (digitalRead(up_button) == LOW) {
      if (timer_set <= 60 * 10) { //maximum time 10 min
        timer_set = timer_set + 10;
      }
      timer_BC_display = rtc.now().unixtime();
      //add beep 1x
      delay(200);
    }
    if (digitalRead(down_button) == LOW) {

      if (timer_set >= 11) { //minimum time 10 sec
        timer_set = timer_set - 10;
      }
      timer_BC_display = rtc.now().unixtime();
      //add beep 1x
      delay(200);
    }
    if (digitalRead(start_stop_button) == LOW) {
      //add beep 1x
      delay(1000);
      if (digitalRead(start_stop_button) == HIGH) {
        if (digitalRead(door_button) == LOW) {
          stop_imm = true;
          if (timer_set > 0) heating_timer ();
          in_timer_mode = false;
          timer_BC_display = rtc.now().unixtime();
        }
        else
        {
          //add beep 2x
          display.clearDisplay();
          display.setCursor(5, 8);
          display.setTextSize(2);
          display.println("Door");
          display.print(" open!");
          display.display();
          digitalWrite(BC_display, HIGH);
          timer_BC_display = rtc.now().unixtime();
          delay(3000);
        }

      }
      if (digitalRead(start_stop_button) == LOW) {
        in_timer_mode = false;
      }
    }
    //set timer to zero
    if (digitalRead(up_button) == LOW && (digitalRead(down_button) == LOW))
    {
      //add beep 2x
      timer_set = 0;
      timer_BC_display = rtc.now().unixtime();
      delay(200);
    }

    //delay of timer_mode - set time
    if (rtc.now().unixtime() - timer_BC_display > 20)
    {
      digitalWrite(BC_display, LOW);
      in_timer_mode = false;
    }


  }
  timer_set = 0;
}


void end_program() {  //buzzer dodelat
  DateTime now = rtc.now();
  timer_end = rtc.now().unixtime();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  int blink_lcd = 0;
  delay(200);
  while ((digitalRead(start_stop_button) == HIGH && digitalRead(door_button) == LOW) && stop_imm == true) {

    digitalWrite(BC_display, HIGH);

    if (blink_lcd < 70) {
      display.clearDisplay();
      display.setCursor(0, 15);
      display.setTextSize(3);
      display.print("DONE");
      display.display();
    }
    if (blink_lcd > 70 && blink_lcd < 140 ) {
      display.clearDisplay();
      display.setCursor(0, 15);
      display.setTextSize(3);
      display.print("END!");
      display.display();
    }
    blink_lcd++;
    if (blink_lcd > 140) blink_lcd = 0;

    if (rtc.now().unixtime() - timer_end > 20)//set warning time!
    {
      //here add buzzer function beep
      for (int x = 0; x < 10; x++) {
        digitalWrite(BC_display, LOW);
        display.clearDisplay();
        display.setCursor(0, 15);
        display.setTextSize(2);
        display.print("DONE");
        display.display();
        if (digitalRead(start_stop_button) == LOW) {
          //add beep 2x
          stop_imm = false;
        }
        if (digitalRead(door_button) == HIGH) {
          //add beep 2x
          stop_imm = false;
        }
        delay(500);
        if (digitalRead(start_stop_button) == LOW) {
          //add beep 2x
          stop_imm = false;
        }
        if (digitalRead(door_button) == HIGH) {
          //add beep 2x
          stop_imm = false;
        }
        digitalWrite(BC_display, HIGH);
        display.clearDisplay();
        display.setCursor(0, 15);
        display.setTextSize(2);
        display.print("END!");
        display.display();
        delay(500);
      }
      timer_end = rtc.now().unixtime();
    }

  }
  //add beep 1x
  stop_imm = true;
  display.clearDisplay();
  display.setCursor(10, 15);
  display.setTextSize(2);
  display.println("END!");
  display.display();
  delay(3000);
  timer_set = 0;
  digitalWrite(BC_display, HIGH);
  timer_BC_display = rtc.now().unixtime();
}

void print2minute(int number) {

  int value = number;
  int sekundy = 0;
  int minuty = 0;
  sekundy = value % 60;
  minuty = (value / 60) % 60;
  print2digits(minuty);
  display.print(":");
  print2digits(sekundy);

}
void settings() { //udělat nastavení(menu:čas/datum;vykon trouby(uloženi do EEPROM);displej:kontrast,doba podsviceni)

}
void power_timer(int mode, int time_power_on, int time_power_off) { //časy jako proměnné funkce až bude menu
  DateTime now = rtc.now();

  if (mode == 1) { //mode 1: control power by switching on/off relay in time intervals
    //power on
    if (rtc.now().unixtime() - timer_power < time_power_on && on_off_mode == true) { //...sec on
      digitalWrite(relay_power, LOW);
    }
    else if (on_off_mode == true)
    {
      timer_power = rtc.now().unixtime();
      on_off_mode = false;
    }

    if (rtc.now().unixtime() - timer_power < time_power_off && on_off_mode == false) { //...sec off
      digitalWrite(relay_power, HIGH);
    }
    else if (on_off_mode == false)
    {
      timer_power = rtc.now().unixtime();
      on_off_mode = true;
    }

  }

  if (mode == 2) { //mode 2: No control (full power)
    digitalWrite(relay_power, LOW);
  }

}
void print2digits(int number) {
  if (number >= 0 && number < 10) {
    display.print('0');
  }

  display.print(number);
}


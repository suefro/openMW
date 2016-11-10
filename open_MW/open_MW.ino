/*
  Digital timer for microwave ver 1.0
  not tested in real
*/
//#include <Wire.h>
#include "RTClib.h" //for RTC time module
#include <EEPROM.h>
//menu
#include "U8glib.h"
#include "M2tk.h"
#include "utility/m2ghu8g.h"
U8GLIB_PCD8544 u8g(7, 6, 4, 5, 3);    // SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9, Reset = 8

RTC_DS1307 rtc;

//gloabal variables: (beware on changes!!)
uint8_t up_button = 12;
uint8_t start_stop_button = 10;
uint8_t down_button = 11;
uint8_t BC_display = 9;
uint8_t relay_on_off = 13;
uint8_t relay_power = 8;
uint8_t door_button = 0;
uint8_t buzzer = 1;

unsigned long timer_uni;
unsigned long timer_power;
unsigned long timer_BC_display;
unsigned int timer_set = 0;
unsigned int blink_lcd_main = 0;
uint8_t BC_bright = 128;
uint8_t Disp_contrast = 128;
uint8_t BC_time_on = 10;
uint8_t power_mode = 0; //5 modes (keep warm, rozmaržení,350W,500W,750W) -after testing change this value
boolean on_off_mode = true;
boolean stop_imm = true;
boolean menu_select = true;
char WM_version[5] = "1.1";
boolean q_timer_pause = true;
//=================================================
// Forward declaration of the toplevel element
M2_EXTERN_ALIGN(top_el_x2l_menu);
//=================================================

/*=== Display settings ===*/
void save_value_display(void)
{
  EEPROM.put(0, Disp_contrast);
  EEPROM.put(1, BC_bright);
  EEPROM.put(2, BC_time_on);

  //add beep 2x
  u8g.firstPage();
  do {
    u8g.drawStr( 0, 20, "Changes");
    u8g.drawStr( 0, 32, "saved!");
  }
  while ( u8g.nextPage() );
  delay(3000);
}

M2_LABEL(el_display_label1, NULL, "contrast:");
M2_U8NUM(el_display_1, NULL, 110, 180, &Disp_contrast);
M2_LABEL(el_display_label2, NULL, "brigh:");
M2_U8NUM(el_display_2, NULL, 0, 255, &BC_bright);
M2_LABEL(el_display_label3, NULL, "time BL:");
M2_U8NUM(el_display_3, NULL, 5, 255, &BC_time_on);



M2_ROOT(el_display_menu, "f4", " back ", &top_el_x2l_menu);
M2_BUTTON(el_display_save, "f4", " save ", save_value_display);

M2_LIST(display_list) = {
  &el_display_label1, &el_display_1,
  &el_display_label2, &el_display_2,
  &el_display_label3, &el_display_3,
  &el_display_save, &el_display_menu
};

M2_GRIDLIST(el_display_menu_grid, "c2", display_list);
M2_ALIGN(el_top_display_menu, "-1|1W64H64", &el_display_menu_grid);
//=================================================

/*=== close menu ===*/
void close_menu(void) {
  menu_select = false;
  BC_light(true, true);
}
/*==========================

  /*=== radio button selection--POWER  ===*/
void save_value_power(void)
{
  EEPROM.put(3, power_mode);

  //add beep 2x
  u8g.firstPage();
  do {
    u8g.drawStr( 0, 20, "Changes");
    u8g.drawStr( 0, 32, "saved!");
  }
  while ( u8g.nextPage() );
  delay(3000);
}
M2_LABEL(el_power_label1, NULL, "keep warm");
M2_RADIO(el_power_radio1, "v0", &power_mode);

M2_LABEL(el_power_label2, NULL, "unfreeze");
M2_RADIO(el_power_radio2, "v1", &power_mode);

M2_LABEL(el_power_label3, NULL, "350W");
M2_RADIO(el_power_radio3, "v2", &power_mode);

M2_LABEL(el_power_label4, NULL, "500W");
M2_RADIO(el_power_radio4, "v3", &power_mode);

M2_LABEL(el_power_label5, NULL, "700W");
M2_RADIO(el_power_radio5, "v4", &power_mode);

M2_BUTTON(el_power_save, "f4", " save ", save_value_power);
M2_ROOT(el_power_goto_top, "f4", " back ", &top_el_x2l_menu);

M2_LIST(list_power) = {
  &el_power_label1, &el_power_radio1,
  &el_power_label2, &el_power_radio2,
  &el_power_label3, &el_power_radio3,
  &el_power_label4, &el_power_radio4,
  &el_power_label5, &el_power_radio5,
  &el_power_save, &el_power_goto_top
};
M2_GRIDLIST(el_power_grid, "c2", list_power);
M2_ALIGN(el_top_power, "-1|1W64H64", &el_power_grid);
//=============================================

/*=== Time settings ===*/
uint8_t set_hour = 0;
uint8_t set_min = 0;
uint8_t set_day = 0;
uint8_t set_month = 0;
uint8_t set_year = 0;

void change_time(void)
{
  // January 21, 2014 at 3am you would call:
  rtc.adjust(DateTime(2000 + set_year, set_month, set_day, set_hour, set_min, 0));

  //add beep 2x
  u8g.firstPage();
  do {
    u8g.drawStr( 0, 20, "Time");
    u8g.drawStr( 0, 32, "change!");
  }
  while ( u8g.nextPage() );
  delay(3000);
}

M2_LABEL(el_time_label1, NULL, "Hour:");
M2_U8NUM(el_time_1, "c2", 0, 23, &set_hour);
M2_LABEL(el_time_label2, NULL, "Minute:");
M2_U8NUM(el_time_2, "c2", 0, 59, &set_min);
M2_LABEL(el_time_label3, NULL, "Day:");
M2_U8NUM(el_time_3, "c2", 0, 32, &set_day);
M2_LABEL(el_time_label4, NULL, "Month:");
M2_U8NUM(el_time_4, "c2", 0, 12, &set_month);
M2_LABEL(el_time_label5, NULL, "Year:");
M2_U8NUM(el_time_5, "c2", 16, 99, &set_year);
//M2_U32NUM(el_time_5, "c4", &set_year);

M2_ROOT(el_time_menu, "f4", " back ", &top_el_x2l_menu);
M2_BUTTON(el_time_save, "f4", " save ", change_time);

M2_LIST(time_list) = {
  &el_time_label1, &el_time_1,
  &el_time_label2, &el_time_2,
  &el_time_label3, &el_time_3,
  &el_time_label4, &el_time_4,
  &el_time_label5, &el_time_5,
  &el_time_save, &el_time_menu,
};

M2_GRIDLIST(el_time_menu_grid, "c2", time_list);
M2_ALIGN(el_top_time_menu, "-1|1W64H64", &el_time_menu_grid);
//=================================================



// this is the overall menu structure for the X2L Menu

m2_xmenu_entry xmenu_data[] =
{
  //{ "Settings", NULL, NULL },    /* expandable main menu entry */
  { "Time", &el_top_time_menu, NULL },
  { "Power", &el_top_power, NULL},
  { "Display", &el_top_display_menu, NULL },
  {"Back<", NULL, &close_menu  },
  { NULL, NULL, NULL },
};

//=================================================
// This is the main menu dialog box

// The first visible line and the total number of visible lines.
// Both values are written by M2_X2LMENU and read by M2_VSB
uint8_t el_x2l_first = 0;
uint8_t el_x2l_cnt = 3;

// M2_X2LMENU definition
// Option l4 = four visible lines
// Option e15 = first column has a width of 15 pixel
// Option W43 = second column has a width of 43/64 of the display width
// Option F3 = select font 3 for the extra column (icons)

M2_X2LMENU(el_x2l_strlist, "l4e15W64F3", &el_x2l_first, &el_x2l_cnt, xmenu_data, 65, 102, '\0');
M2_SPACE(el_x2l_space, "W1h1");
M2_VSB(el_x2l_vsb, "l4W2r1", &el_x2l_first, &el_x2l_cnt);
M2_LIST(list_x2l) = { &el_x2l_strlist, &el_x2l_space, &el_x2l_vsb };
M2_HLIST(el_x2l_hlist, NULL, list_x2l);
M2_ALIGN(top_el_x2l_menu, "-1|1W64H64", &el_x2l_hlist);

//=================================================
// m2 object and constructor
M2tk m2(&top_el_x2l_menu, m2_es_arduino, m2_eh_4bs, m2_gh_u8g_bf);

//=================================================

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

  //default set relay
  digitalWrite(relay_on_off, HIGH);
  digitalWrite(relay_power, HIGH);

  // Connect u8glib with m2tklib
  m2_SetU8g(u8g.getU8g(), m2_u8g_box_icon);

  // Assign u8g font to index 0
  //m2.setFont(0, u8g_font_4x6r);
  m2.setFont(0, u8g_font_5x7r);
  // Assign icon font to index 3
  // m2.setFont(3, u8g_font_m2icon_7);

  // Setup keys
  m2.setPin(M2_KEY_SELECT, start_stop_button);
  m2.setPin(M2_KEY_PREV, up_button);
  m2.setPin(M2_KEY_NEXT, down_button);

  //read EEPROM
  EEPROM.get(0, Disp_contrast);
  EEPROM.get(1, BC_bright);
  EEPROM.get(2, BC_time_on);
  EEPROM.get(3, power_mode);


  BC_light(true, true); //turn on backlight
  u8g.firstPage();
  do {
    u8g.setContrast(Disp_contrast);
    u8g.drawStr( 0, 10, "Open-MW 2016");
    u8g.drawStr( 0, 20, "Firmware:");
    u8g.setPrintPos(0, 30);
    u8g.print(WM_version);
  }
  while ( u8g.nextPage() );
  delay(2000);

  if (! rtc.begin()) {

    u8g.firstPage();
    do {

      u8g.drawStr( 0, 20, "RTC ERROR!");

    }
    while ( u8g.nextPage() );
    delay(10000);
    // while (1);
  }

  if (! rtc.isrunning()) {
    u8g.firstPage();
    do {

      u8g.drawStr( 0, 20, "Set Time!");

    }
    while ( u8g.nextPage() );
    delay(10000);
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }



}
void loop() {

  DateTime now = rtc.now();
  u8g.firstPage();
  do {
    u8g.setFont(u8g_font_8x13Br);
    u8g.setPrintPos(12, 12);
    print2digits(now.hour());
    u8g.print(":");
    print2digits(now.minute());
    u8g.print(":");
    print2digits(now.second());
    u8g.setFont(u8g_font_5x7r);
    u8g.setPrintPos(14, 25);
    print2digits(now.day());
    u8g.print('/');
    print2digits(now.month());
    u8g.print('/');
    u8g.print(now.year(), DEC);

    //blinking static text

    if (blink_lcd_main < 500) {
      u8g.drawFrame(0, 30, 26, 18);
      u8g.drawStr( 2, 41, "Menu");
      u8g.drawFrame(28, 30, 26, 18);
      u8g.drawStr( 29, 37, "Quick");
      u8g.drawStr( 29, 45, "Start");
      u8g.drawFrame(57, 30, 26, 18);
      u8g.drawStr( 62, 37, "Set");
      u8g.drawStr( 58, 45, "Timer");
    }
    if (blink_lcd_main > 500 && blink_lcd_main < 1000 ) {
      u8g.drawFrame(0, 30, 26, 18);
      u8g.drawStr( 2, 41, "Light");
      u8g.drawFrame(28, 30, 26, 18);
      u8g.drawStr( 29, 37, "Quick");
      u8g.drawStr( 29, 45, "Start");
      u8g.drawFrame(57, 30, 26, 18);
      u8g.drawStr( 62, 37, "Set");
      u8g.drawStr( 58, 45, "Timer");
    }
    blink_lcd_main++;
    if (blink_lcd_main > 1000) blink_lcd_main = 0;
  }
  while ( u8g.nextPage() );

  if (digitalRead(up_button) == LOW) {
    delay(500);
    BC_light(true, true);
    //add beep 1x

    timer_mode();

  }

  if (digitalRead(down_button) == LOW) {
    //add beep 1x
    delay(500);
    if (digitalRead(down_button) == HIGH) {
      BC_light(true, true);
    }
    if (digitalRead(down_button) == LOW) { //enter to menu

      DateTime now = rtc.now();
      set_hour = now.hour();
      set_min = now.minute();
      set_day = now.day();
      set_month = now.month();
      set_year = 16;

      while (menu_select == true) {
        // menu management

        analogWrite(BC_display, BC_bright);
        u8g.setContrast(Disp_contrast);
        m2.checkKey();
        if ( m2.handleKey() != 0 ) {
          u8g.firstPage();
          do {
            m2.checkKey();
            draw();
          } while ( u8g.nextPage() );
        }

      }
      menu_select = true;


    }

  }
  //in this menu can start quick timing
  if (digitalRead(start_stop_button) == LOW) {
    //add beep 1x
    if (digitalRead(door_button) == LOW) {
      delay(500);
      BC_light(true, true);
      heating_timer (false);
    }
    else
    {
      //add beep 2x
      u8g.firstPage();
      do {
        u8g.setFont(u8g_font_8x13Br);
        u8g.setPrintPos(15, 12);
        u8g.print("DOOR");
        u8g.setPrintPos(15, 28);
        u8g.print("OPEN");
      }
      while ( u8g.nextPage() );
      BC_light(true, true);
      delay(3000);
    }

  }

  //backlight off set time
  if (rtc.now().unixtime() - timer_BC_display > 20)
  {
    digitalWrite(BC_display, LOW);
  }

}


void heating_timer (boolean value) { //if true -- normal heating mode //if false --quick heating mode
  DateTime now = rtc.now();
  if (value == false) timer_uni = (rtc.now().unixtime() + 30);
  if (value == true)timer_uni = (rtc.now().unixtime() + timer_set);
  timer_power = rtc.now().unixtime();
  boolean pause_time = false;
  boolean pause_time_button = true;
  digitalWrite(relay_on_off, LOW);
  digitalWrite(relay_power, LOW);
  delay(500);
  while (timer_uni - rtc.now().unixtime() > 0 && stop_imm == true) {
    u8g.firstPage();
    do {
      u8g.setFont(u8g_font_8x13Br);
      u8g.drawStr( 16, 12, "Timer");
      u8g.setPrintPos(20, 28);
      print2minute(timer_uni - rtc.now().unixtime());
      u8g.setFont(u8g_font_5x7r);
      u8g.drawFrame(0, 30, 26, 18);
      u8g.drawStr( 4, 41, "DOWN");
      u8g.drawFrame(28, 30, 26, 18);
      if (digitalRead(door_button) == HIGH)
      {
        if (value == true) u8g.drawStr( 31, 41, "STOP");
        if (value == false) u8g.drawStr( 35, 41, "UP");
      }
      
      if (digitalRead(door_button) == LOW)
      {
        if (value == true)
        {
          if (pause_time == false) u8g.drawStr( 29, 41, "PAUSE");
          if (pause_time == true) u8g.drawStr( 29, 41, "START");
        }
        if (value == false)
        {
          u8g.drawStr( 35, 41, "UP");
        }
      }
      u8g.drawFrame(57, 30, 26, 18);
      if (value == true)
      {
        u8g.drawStr( 65, 41, "UP");
      }
      if (value == false)
      {
        u8g.drawStr( 59, 41, "STOP");
      }

    }
    while ( u8g.nextPage() );
    delay(100);
    if (value == false)
    {


      if (digitalRead(start_stop_button) == LOW) {
        //add beep 1x
        delay(500);

        if (timer_uni - rtc.now().unixtime() <= 580) {
          timer_uni = timer_uni + 30;
        }
        if ( q_timer_pause == false) {
          if (timer_set <= 580) {
            timer_set = timer_set + 10;

          }
        }

      }
    }

    if (value == true)
    {
      if (digitalRead(door_button) == HIGH)
      {
        if (digitalRead(start_stop_button) == LOW) {
           stop_imm = false;
           delay(1000);
        }
      }
      if (digitalRead(door_button) == LOW)
      {

        if (digitalRead(start_stop_button) == LOW) {
          //add beep 1x
          if (pause_time_button == true) //on pause
          {
            pause_time = true;
            timer_set = (timer_uni - rtc.now().unixtime());
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
            digitalWrite(relay_on_off, HIGH);
            digitalWrite(relay_power, HIGH);
            stop_imm = false;
            u8g.firstPage();
            do {
              u8g.setFont(u8g_font_8x13Br);
              u8g.drawStr( 10, 28, ">END<");
            }
            while ( u8g.nextPage() );
            delay(3000);
          }
        }
      }
    }
    if (value == false)
    {
      if (digitalRead(up_button) == LOW) {
        //add beep 1x
        digitalWrite(relay_on_off, HIGH);
        digitalWrite(relay_power, HIGH);
        stop_imm = false;
        u8g.firstPage();
        do {
          u8g.setFont(u8g_font_8x13Br);
          u8g.drawStr( 10, 28, ">END<");
        }
        while ( u8g.nextPage() );
        delay(3000);

      }
    }

    if (value == true)
    {
      if (digitalRead(up_button) == LOW) {
        if (timer_uni - rtc.now().unixtime() <= 580) {
          timer_uni = timer_uni + 10;
          //add beep 1x
        }
        if ( pause_time == true) {
          if (timer_set <= 580) {
            timer_set = timer_set + 10;

          }
        }
        delay(200);
      }
    }
    if (value == false)
    {
      if (digitalRead(down_button) == LOW) {
        //add beep 1x
        if (timer_uni - rtc.now().unixtime() >= 11) {
          timer_uni = timer_uni - 10;
        }
        if (q_timer_pause == false) {
          if (timer_set >= 5) {
            timer_set = timer_set - 10;

          }
        }
        delay(200);
      }
    }
    if (value == true)
    {
      if (digitalRead(down_button) == LOW) {
        //add beep 1x
        if (timer_uni - rtc.now().unixtime() >= 11) {
          timer_uni = timer_uni - 10;
        }
        if ( pause_time == true) {
          if (timer_set >= 5) {
            timer_set = timer_set - 10;

          }
        }
        delay(200);
      }
    }

    if (digitalRead(door_button) == HIGH) {
      //add beep 2x
      //stop_imm = false;
      if (value == false)
      {
        if (q_timer_pause == true)timer_set = (timer_uni - rtc.now().unixtime());
        q_timer_pause = false;
        if (q_timer_pause == false)timer_uni = (rtc.now().unixtime() + timer_set);
        pause_time = false;
        digitalWrite(relay_on_off, HIGH);
        digitalWrite(relay_power, HIGH);
      }
      if (value == true)
      {
        pause_time = true;
      }

    }
    if (digitalRead(door_button) == LOW) {
      q_timer_pause = true;

    }

    if ( pause_time == true) {
      digitalWrite(relay_on_off, HIGH);
      timer_uni = (rtc.now().unixtime() + timer_set);
      pause_time_button = false;
      digitalWrite(relay_power, HIGH);
    }
    if ( pause_time == false) {
      if (q_timer_pause == true)
      {
        digitalWrite(relay_on_off, LOW);
        //power function:
        power_timer(power_mode); //number of mode,time on , time off
      }

    }


  }
  digitalWrite(relay_on_off, HIGH);
  digitalWrite(relay_power, HIGH);

  tone(buzzer, 3500, 500);
  delay (500);
  noTone(buzzer);
  delay (500);
  if (stop_imm == true)
  {
    end_program();
  }
  timer_set = 0;
  stop_imm = true;
  on_off_mode = true;
  BC_light(true, true);
}

void timer_mode () {
  DateTime now = rtc.now();
  BC_light(true, true);
  boolean in_timer_mode = true;
  timer_set = 10;
  while (in_timer_mode == true) {
    u8g.firstPage();
    do {
      u8g.setFont(u8g_font_8x13Br);
      u8g.drawStr( 10, 14, "SetTimer");
      u8g.setPrintPos(20, 28);
      print2minute(timer_set);
      u8g.setFont(u8g_font_5x7r);
      u8g.drawFrame(0, 30, 26, 18);
      u8g.drawStr( 4, 41, "DOWN");
      u8g.drawFrame(28, 30, 26, 18);
      u8g.drawStr( 29, 41, "START");
      u8g.drawFrame(57, 30, 26, 18);
      u8g.drawStr( 65, 41, "UP");
    }
    while ( u8g.nextPage() );

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
          if (timer_set > 0) heating_timer (true);
          in_timer_mode = false;
          timer_BC_display = rtc.now().unixtime();
        }
        else
        {
          //add beep 2x
          u8g.firstPage();
          do {
            u8g.setFont(u8g_font_8x13Br);
            u8g.drawStr( 15, 12, "DOOR");
            u8g.drawStr( 15, 28, "OPEN");

          }
          while ( u8g.nextPage() );
          BC_light(true, true);
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
    if (rtc.now().unixtime() - timer_BC_display > 5)
    {
      digitalWrite(BC_display, LOW);
      in_timer_mode = false;
    }


  }
  timer_set = 0;
}


void end_program() {  //buzzer dodelat
  DateTime now = rtc.now();
  timer_uni = rtc.now().unixtime();
  int blink_lcd = 0;
  delay(200);
  while ((digitalRead(start_stop_button) == HIGH && digitalRead(door_button) == LOW) && stop_imm == true) {

    BC_light(true, true);
    u8g.firstPage();
    do {

      u8g.setFont(u8g_font_8x13Br);
      u8g.drawStr( 10, 28, "END");
    }

    while ( u8g.nextPage() );

    if (rtc.now().unixtime() - timer_uni > 20)//set warning time!
    {
      //here add buzzer function beep
      for (int x = 0; x < 10; x++) {
        u8g.setFont(u8g_font_8x13Br);
        u8g.setPrintPos(10, 28);
        u8g.print("RING!");

        tone(buzzer, 3500, 500);
        delay (100);
        noTone(buzzer);
        delay (100);
      }
      timer_uni = rtc.now().unixtime();
    }

  }
  //add beep 1x
  stop_imm = true;
  u8g.firstPage();
  do {
    u8g.setFont(u8g_font_8x13Br);
    u8g.drawStr( 10, 28, ">END<");
  }
  while ( u8g.nextPage() );
  delay(3000);
  timer_set = 0;
  BC_light(true, true);
}

void print2minute(int number) {

  int value = number;
  int sekundy = 0;
  int minuty = 0;
  sekundy = value % 60;
  minuty = (value / 60) % 60;
  print2digits(minuty);
  u8g.print(":");
  print2digits(sekundy);

}

void power_timer(int mode) { //časy jako proměnné funkce až bude menu
  DateTime now = rtc.now();

  int time_power_on;
  int time_power_off;
  if (mode == 0) { //mode 0: keepwarm
    time_power_on = 7;
    time_power_off = 25;
  }
  if (mode == 1) { //mode 1: unfreezing
    time_power_on = 10;
    time_power_off = 20;
  }
  if (mode == 2) { //mode 2: 350W
    time_power_on = 17;
    time_power_off = 12;
  }
  if (mode == 3) { //mode 3: 500W
    time_power_on = 25;
    time_power_off = 7;
  }

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



  if (mode == 4) { //mode 4: 750W No control (full power)
    digitalWrite(relay_power, LOW);
  }

}
void print2digits(int number) {
  if (number >= 0 && number < 10) {
    u8g.print('0');
  }

  u8g.print(number);
}
void BC_light(boolean power, boolean timer) {
  if (power == true) {
    analogWrite(BC_display, BC_bright);
  }
  if (power == false) {
    analogWrite(BC_display, 0);
  }
  if (timer == true) {
    timer_BC_display = rtc.now().unixtime();
  }

}



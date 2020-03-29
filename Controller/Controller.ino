/* controller.ino
   shinchokuer: tari

   This, program for controller, ESP32 based.
   This will read input value of buttons and joyeuxsticke, then send
   some commands to Duck Raspberry Pi via UDP connection over Wi-Fi.

   COMMANDS:

   FRONT: 1
   BACK: 2
   LEFT: 3
   RIGHT: 4
   STOP: 0
*/


//#include "network/bluetooth.h"
#include "network/udp.h"
#include "network/wifi_ducks.h"
#include "control/sensor/button.h"
#include "control/sensor/joy_stick.h"
#include "lcd.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  init_lcd();
  init_wifi();
  //init_bt();
  init_udp(8889, "192.168.0.58"); // (port, address)
  init_button(0, 16);
  init_button(1, 0);
  init_button(2, 0);
  init_button(3, 0);
  init_stick(32, 33);
  tft.setRotation(3);
  tft.fillScreen(ST77XX_BLACK);
  disp_nw();
}

/*

   FRONT
   213
   546

*/

void loop() {
  // put your main code here, to run repeatedly:
  static String sendval;
  if (get_status_button(0) == 1) {
    //send_udp("F");
    //delay(50);
  }
  if (get_value_stick_y() > 1024) {
    if (get_value_stick_x() > 1024) {
      send_udp('3');
      disp_direc(3);
    }
    else if (get_value_stick_x() < -1024) {
      send_udp('2');
      disp_direc(2);
    }
    else {
      send_udp('1');
      disp_direc(1);
    }
  }
  else if (get_value_stick_y() < -1024) {
    if (get_value_stick_x() > 1024) {
      send_udp('6');
      disp_direc(6);
    }
    else if (get_value_stick_x() < -1024) {
      send_udp('5');
      disp_direc(5);
    }
    else {
      send_udp('4');
      disp_direc(4);
    }
  }
  else {
    send_udp('0');
    disp_direc(0);
  }
  delay(20);
}

//#include "network/bluetooth.h"
#include "network/udp.h"
#include "network/wifi_ducks.h"
#include "control/sensor/button.h"
#include "control/sensor/joy_stick.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  init_wifi();
  //init_bt();
  ///init_udp(8888, "192.168.0.56");
  init_button(0, 16);
  init_button(1, 0);
  init_button(2, 0);
  init_button(3, 0);
  init_stick(A6, A7);
}

void loop() {
  // put your main code here, to run repeatedly:
  static String sendval;
  if (get_status_button(0) == 1) {
    //send_udp("F");
    //delay(50);
  }
  if (get_value_stick_x() > 1024) {
    //send_udp('R');
  }
  else if (get_value_stick_x() < -1024) {
    //send_udp('L');
  }
  else if (get_value_stick_y() > 1024) {
    //send_udp('F');
  }
  else if (get_value_stick_x() < -1024) {
    //send_udp('B');
  }
  delay(200);
}

#include "main.h"
#include "config.hpp"


//bkue coloursort
void highbluesort() {

      if ((optical.get_hue() > 100 && optical.get_hue() < 225)) {
        high();
      }
      else if ((optical.get_hue() > 5 && optical.get_hue() < 25)) {
        middle();
      }
      else {
        intake.move_voltage(12000); 
        indication_sign.move_voltage(6700); 
      }
}

void middlebluesort() {

      if ((optical.get_hue() > 100 && optical.get_hue() < 225)) {
        middle();
      }
      else if ((optical.get_hue() > 5 && optical.get_hue() < 25)) {
        high();
      }
      else {
        intake.move_voltage(12000);
        indication_sign.move_voltage(6700); 
      }
}


//red colour sort
void highredsort() {

      if ((optical.get_hue() > 5 && optical.get_hue() < 25)) {
        high();
      }
      else if ((optical.get_hue() > 100 && optical.get_hue() < 225)) {
        middle();
      }
      else {
        intake.move_voltage(12000); 
        indication_sign.move_voltage(6700); 
      }
}

void middleredsort() {

      if ((optical.get_hue() > 5 && optical.get_hue() < 25)) {
        middle();
      }
      else if ((optical.get_hue() > 100 && optical.get_hue() < 225)) {
        high();
      }
      else {
        intake.move_voltage(12000);
        indication_sign.move_voltage(6700); 
      }
}
#include "main.h"
#include "config.hpp"
#include "pros/motors.hpp"
#include "autons.hpp"

void initialize() {

  pros::delay(500);  

  // Configure your chassis controls
  chassis.opcontrol_curve_buttons_toggle(true);   // Enables modifying the controller curve with buttons on the joysticks
  chassis.opcontrol_drive_activebrake_set(0.0);   // Sets the active brake kP. We recommend ~2.  0 will disable.
  chassis.opcontrol_curve_default_set(0.0, 0.0);  // Defaults for curve. If using tank, only the first parameter is used. (Comment this line out if you have an SD card!)

  default_constants();

  // Initialize chassis and auton selector
  optical.set_integration_time(10);
  chassis.initialize();
  ez::as::initialize();

}


void high() { // This is for high
  intake.move_voltage(12000); //positive to intake
  indication_sign.move_voltage(12000); //positive for middle goal
  score.move_voltage(12000);
}
void middle() { // This is for middle
  intake.move_voltage(12000); //positive to intake
  indication_sign.move_voltage(12000); //positive for middle goal
  score.move_voltage(-12000);
}
void low() { //for the lowgoal
  intake.move_voltage(-12000);
  indication_sign.move_voltage(-12000);
  score.move_voltage(-12000);
}
void motorstop() { // This is for stophoarding
  intake.move_voltage(0); 
  indication_sign.move_voltage(0); 
  score.move_voltage(0); 
}
void hoarding() { // This is for hoarding
  intake.move_voltage(12000); //positive to intake
  indication_sign.move_voltage(-12000); //negitive to put into hoarding area
  score.move_voltage(0); 
}

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
  chassis.initialize();
  ez::as::initialize();

}
int DRIVE_SPEED = 110;
int TURN_SPEED = 90;

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
  score.move_voltage(12000);
}
void motorstop() { // This is for stophoarding
  intake.move_voltage(0); 
  indication_sign.move_voltage(0); 
  score.move_voltage(0); 
}
void hoarding() { // This is for hoarding
  intake.move_voltage(12000); //positive to intake
  indication_sign.move_voltage(-12000); //negitive to put into hoarding area
  score.move_voltage(12000); 
}

void coloursort() {
  
}

void autonomous() {

    chassis.pid_drive_set(-80_cm, 70, true); //135
    chassis.pid_wait();
    chassis.pid_turn_set(270_deg, TURN_SPEED);
    chassis.pid_wait();
    loader.set_value(1);
    chassis.pid_wait();
    chassis.pid_drive_set(-50_cm, 70, true); //135
    chassis.pid_wait();
    hoarding();
    chassis.pid_wait();
    pros::delay(2000);
    chassis.pid_drive_set(140_cm, 70, true);
    chassis.pid_wait();
    high();
    chassis.pid_wait();
    pros::delay(3000);
    motorstop();
    

}

void opcontrol() {

    bool bunnyStatus = false;
    bool loaderStatus = false;



    while (true) {

        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) { // This is for hoarding
            intake.move_voltage(12000); //positive to intake
            indication_sign.move_voltage(-12000); //negitive to put into hoarding area
            score.move_voltage(12000);  //not sure ask david
        } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) { // this is for middle goal
            intake.move_voltage(12000); //positive to intake
            indication_sign.move_voltage(12000); //positive for middle goal
            score.move_voltage(-12000); 
        } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) { // this is for outaking / low goal
            intake.move_voltage(-12000);
            indication_sign.move_voltage(-12000);
            score.move_voltage(12000);
        } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) { // this is for highgoal
            intake.move_voltage(12000);
            indication_sign.move_voltage(12000);
            score.move_voltage(12000);
        } else {
            intake.move_voltage(0);
            indication_sign.move_voltage(0);
            score.move_voltage(0);
        }

        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)) { //this is for the matchloader
            loaderStatus = !loaderStatus;
            loader.set_value(loaderStatus);
        }

        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) { //this if for the bunny ears
            bunnyStatus = !bunnyStatus;
            bunny.set_value(bunnyStatus);
        }
    
    chassis.drive_brake_set(MOTOR_BRAKE_COAST);

  
    chassis.opcontrol_arcade_standard(::SPLIT);   // Standard split arcade

    pros::delay(ez::util::DELAY_TIME);  // This is used for timer calculations!  
  
    }
}

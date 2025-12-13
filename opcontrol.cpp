#include "main.h"
#include "config.hpp"

void opcontrol() {
    //withsort();
    woutsort();
}
//control stuff
void withsort() {

    std::string alliance_colour = "red";

    bool bunnyStatus = false;
    bool loaderStatus = false;


    while (true) {

        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) { // This is for hoarding
            hoarding();
        } 

        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) { // this is for highgoal
            if (alliance_colour == "blue") {
                highbluesort();
            }
            else if (alliance_colour == "red") {
                highredsort();
            }
        }
        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) { // this is for middle goal
            if (alliance_colour == "blue") {
                middlebluesort();
            }
            else if (alliance_colour == "red") {
                middleredsort();
            }
        } 
        //
        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) { // this is for outaking / low goal
            low();
        } else {
            motorstop();
        }

        //
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)) { //this is for the matchloader
            loaderStatus = !loaderStatus;
            loader.set_value(loaderStatus);
        }

        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) { //this if for the bunny ears
            bunnyStatus = !bunnyStatus;
            bunny.set_value(bunnyStatus);
        }
        //
    
    chassis.drive_brake_set(MOTOR_BRAKE_COAST);

  
    chassis.opcontrol_arcade_standard(::SPLIT);   // Standard split arcade

    pros::delay(ez::util::DELAY_TIME);  // This is used for timer calculations!  
  
    }
}


void woutsort() {

    std::string alliance_colour = "red";

    bool bunnyStatus = false;
    bool loaderStatus = false;


    while (true) {

        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) { // This is for hoarding
            hoarding();
        } 

        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) { // this is for highgoal
            high();
        }
        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) { // this is for middle goal
            middle();
        } 
        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) { // this is for outaking / low goal
            low();
        } 
        else {
            motorstop();
        }

        //
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)) { //this is for the matchloader
            loaderStatus = !loaderStatus;
            loader.set_value(loaderStatus);
        }

        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) { //this if for the bunny ears
            bunnyStatus = !bunnyStatus;
            bunny.set_value(bunnyStatus);
        }
        //
    
    chassis.drive_brake_set(MOTOR_BRAKE_COAST);

  
    chassis.opcontrol_arcade_standard(::SPLIT);   // Standard split arcade

    pros::delay(ez::util::DELAY_TIME);  // This is used for timer calculations!  
  
    }
}

#include "main.h"
#include "config.hpp"

// These are out of 127
const int DRIVE_SPEED = 120;
const int TURN_SPEED = 90;

void default_constants() {
  // P, I, D, and Start I
  chassis.pid_drive_constants_set(20.0, 0.0, 100.0);         // Fwd/rev constants, used for odom and non odom motions
  chassis.pid_heading_constants_set(11.0, 0.0, 20.0);        // Holds the robot straight while going forward without odom
  chassis.pid_turn_constants_set(3.0, 0.05, 20.0, 15.0);     // Turn in place constants
  chassis.pid_swing_constants_set(6.0, 0.0, 65.0);           // Swing constants
  chassis.pid_odom_angular_constants_set(6.5, 0.0, 52.5);    // Angular control for odom motions
  chassis.pid_odom_boomerang_constants_set(5.8, 0.0, 32.5);  // Angular control for boomerang motions

  // Exit conditions
  chassis.pid_turn_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_swing_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms);
  chassis.pid_odom_turn_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 750_ms);
  chassis.pid_odom_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 750_ms);
  chassis.pid_turn_chain_constant_set(3_deg);
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(3_in);

  // Slew constants
  chassis.slew_turn_constants_set(3_deg, 70);
  chassis.slew_drive_constants_set(3_in, 70);
  chassis.slew_swing_constants_set(3_in, 80);

  // The amount that turns are prioritized over driving in odom motions
  // - if you have tracking wheels, you can run this higher.  1.0 is the max
  chassis.odom_turn_bias_set(0.9);

  chassis.odom_look_ahead_set(7_in);           // This is how far ahead in the path the robot looks at
  chassis.odom_boomerang_distance_set(16_in);  // This sets the maximum distance away from the target that the carrot point can be
  chassis.odom_boomerang_dlead_set(0.625);     // This handles how aggressive the end of boomerang motions are

  chassis.pid_angle_behavior_set(ez::shortest);  // Changes the default behaviour for turning, this defaults it to the shortest path there
}


// //once again part the waves please :))
//if this function is used, make the previous function into this function and change this function into the opposite function
void bunnyUp() {
  bool bunnyStatus = false;

  bunnyStatus = !bunnyStatus;
  bunny.set_value(bunnyStatus);
}

void loaderUp() {
  bool loaderStatus = false;

  loaderStatus = !loaderStatus;
  loader.set_value(loaderStatus);
}

//gets the 3 balls and scores 4 balls into middle, then loads 3 and scores 3 into high
void middlefirst() {
  
  chassis.pid_drive_set(-32_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  hoarding();
  chassis.pid_wait();
  chassis.pid_turn_set(320_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-55_cm, 60, true);
  chassis.pid_wait();
  pros::delay(2000);
  chassis.pid_wait();
  motorstop();
  chassis.pid_wait();
  chassis.pid_drive_set(22_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(227_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(45_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  middle();
  pros::delay(1700);
  chassis.pid_wait();
  motorstop();
  chassis.pid_drive_set(-127_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(180_deg, TURN_SPEED);
  chassis.pid_wait();
  loader.set_value(1);
  chassis.pid_drive_set(-45_cm, 60, true);
  hoarding();
  pros::delay(1700);
  chassis.pid_wait();
  chassis.pid_drive_set(110_cm, 67, true);
  chassis.pid_wait();
  highredsort();
  chassis.pid_wait();
  pros::delay(1700);
  chassis.pid_wait();

}

//goes to load and scores 4 balls into the high
//with colour sort cuz loader sometimes grabs a blue ball
void redLeft() {
    chassis.pid_drive_set(-80_cm, 70, true); //135
    chassis.pid_wait();
    chassis.pid_turn_set(90_deg, TURN_SPEED);
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
    highredsort();
    chassis.pid_wait();
    pros::delay(2000);
    motorstop();  
}
void autonomous() {
  //auton left for red or blue
    middlefirst();
    // chassis.pid_drive_set(-80_cm, 70, true); //135
    // chassis.pid_wait();
    // chassis.pid_turn_set(90_deg, TURN_SPEED);
    // chassis.pid_wait();
    // loader.set_value(1);
    // chassis.pid_wait();
    // chassis.pid_drive_set(-50_cm, 70, true); //135
    // chassis.pid_wait();
    // hoarding();
    // chassis.pid_wait();
    // pros::delay(2000);
    // chassis.pid_drive_set(140_cm, 70, true);
    // chassis.pid_wait();
    // high();
    // chassis.pid_wait();
    // pros::delay(3000);
    // motorstop();  

}


// void left() {
//   chassis.pid_drive_set(-80_cm, 70, true); //135
//   chassis.pid_wait();
//   chassis.pid_turn_set(270_deg, TURN_SPEED);
//   chassis.pid_wait();
//   loader.set_value(1);
//   chassis.pid_wait();
//   chassis.pid_drive_set(-50_cm, 70, true); //135
//   chassis.pid_wait();
//   hoarding();
//   chassis.pid_wait();
//   pros::delay(2000);
//   chassis.pid_drive_set(140_cm, 70, true);
//   chassis.pid_wait();
//   high();
//   chassis.pid_wait();
//   pros::delay(3000);
//   motorstop();
// }

// void right(){
//   chassis.pid_drive_set(-80_cm, 70, true); //135
//   chassis.pid_wait();
//   chassis.pid_turn_set(90_deg, TURN_SPEED);
//   chassis.pid_wait();
//   loader.set_value(1);
//   chassis.pid_wait();
//   chassis.pid_drive_set(-50_cm, 70, true); //135
//   chassis.pid_wait();
//   hoarding();
//   chassis.pid_wait();
//   pros::delay(2000);
//   chassis.pid_drive_set(140_cm, 70, true);
//   chassis.pid_wait();
//   high();
//   chassis.pid_wait();
//   pros::delay(3000);
//   motorstop();
// }


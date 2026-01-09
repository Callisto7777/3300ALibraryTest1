#include "main.h"
#include "config.hpp"

// These are out of 127
const int DRIVE_SPEED = 125;
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
  chassis.odom_boomerang_distance_set(16_in);  // This sets the maximum distance away from target that the carrot point can be
  chassis.odom_boomerang_dlead_set(0.625);     // This handles how aggressive the end of boomerang motions are

  chassis.pid_angle_behavior_set(ez::shortest);  // Changes the default behavior for turning, this defaults it to the shortest path there
}

// //once again part the waves please :))

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

//auton code stuff
void soloautonred() {
  chassis.pid_drive_set(31_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(20_in, DRIVE_SPEED); //get to the goal
  chassis.pid_wait();
  high(); //score
  pros::delay(500);
  chassis.pid_drive_set(-20_in, DRIVE_SPEED); //go A6 bottom right corner
  chassis.pid_wait();
  chassis.pid_turn_set(315_deg, TURN_SPEED);//ended here
  chassis.pid_wait();
  hoarding();  //while going to middle goal get the 3 balls in center
  chassis.pid_drive_set(-45_in, DRIVE_SPEED);//go to middle goal (hopefully aline) *mightneedtogo slowerngl
  chassis.pid_wait();
  loader.set_value(1);
  chassis.pid_turn_set(135_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(12_in, DRIVE_SPEED);
  middle();
  pros::delay(100);
  motorstop();
  chassis.pid_drive_set(-12_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_turn_set(194.41_deg, TURN_SPEED); // this works very well
  chassis.pid_wait();
  chassis.pid_drive_set(67_in, 150);
  chassis.pid_wait();
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-25_in, DRIVE_SPEED);
  hoarding();
  pros::delay(1200);
  chassis.pid_drive_set(45_in, 100);//go a lil slower so that the balls dont fly out
  chassis.pid_wait();
  pros::delay(1200);
  chassis.pid_drive_set(-25_in, 130);
  chassis.pid_wait();
  high();
}


void pidtesting() {
  chassis.pid_drive_set(37_in, DRIVE_SPEED);
  chassis.pid_wait();
}


void redLeft() {
  chassis.pid_drive_set(-32_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  hoarding();
  chassis.pid_wait();
  chassis.pid_turn_set(320_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-55_cm, 60, true);
  chassis.pid_wait();
  loader.set_value(1);
  chassis.pid_wait();
  pros::delay(500);
  chassis.pid_wait();
  motorstop();
  chassis.pid_wait();
  chassis.pid_drive_set(22_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(225_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(47_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  middle();
  pros::delay(1500);
  chassis.pid_wait();
  motorstop();
  chassis.pid_drive_set(-127_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(180_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-45_cm, 60, true);
  hoarding();
  pros::delay(1400);
  chassis.pid_wait();
  chassis.pid_drive_set(110_cm, 67, true);
  loader.set_value(0);
  chassis.pid_wait();
  high();
  //highredsort();
  chassis.pid_wait();
  pros::delay(1700);
  chassis.pid_wait();
}

void redRight() {
  chassis.pid_drive_set(-32_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  hoarding();
  chassis.pid_wait();
  chassis.pid_turn_set(40_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-55_cm, 60, true);
  chassis.pid_wait();
  pros::delay(1000);
  chassis.pid_wait();
  chassis.pid_drive_set(22_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(315_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-35_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  low();
  pros::delay(1700);
  chassis.pid_wait();
  motorstop();
  chassis.pid_drive_set(122_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(180_deg, TURN_SPEED);
  chassis.pid_wait();
  loader.set_value(1);
  chassis.pid_drive_set(-45_cm, 60, true);
  hoarding();
  pros::delay(1300);
  chassis.pid_wait();
  chassis.pid_drive_set(110_cm, 67, true);
  //loader.set_value(0);
  chassis.pid_wait();
  high();
  //highredsort();
  chassis.pid_wait();
  pros::delay(1700);
  chassis.pid_wait();
}

void blueLeft() {
  chassis.pid_drive_set(-32_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  hoarding();
  chassis.pid_wait();
  chassis.pid_turn_set(320_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-55_cm, 60, true);
  chassis.pid_wait();
  pros::delay(1000);
  chassis.pid_wait();
  motorstop();
  chassis.pid_wait();
  chassis.pid_drive_set(22_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(225_deg, TURN_SPEED);
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
  loader.set_value(0);
  chassis.pid_wait();
  high();
  //highredsort();
  chassis.pid_wait();
  pros::delay(1700);
  chassis.pid_wait();
  //backward
  //315
  //forward
  //0
  //bunny
  //forward
  //end

}

void blueRight() {
  chassis.pid_drive_set(-32_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  hoarding();
  chassis.pid_wait();
  chassis.pid_turn_set(40_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-55_cm, 60, true);
  chassis.pid_wait();
  pros::delay(1000);
  chassis.pid_wait();
  chassis.pid_drive_set(22_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(315_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-35_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  low();
  pros::delay(1700);
  chassis.pid_wait();
  motorstop();
  chassis.pid_drive_set(122_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(180_deg, TURN_SPEED);
  chassis.pid_wait();
  loader.set_value(1);
  chassis.pid_drive_set(-45_cm, 60, true);
  hoarding();
  pros::delay(1300);
  chassis.pid_wait();
  chassis.pid_drive_set(110_cm, 67, true);
  //loader.set_value(0);
  chassis.pid_wait();
  high();
  //highredsort();
  chassis.pid_wait();
  pros::delay(1700);
  chassis.pid_wait();
}

void stupidonethatdavidwantsbruh() {
  chassis.pid_drive_set(-32_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  hoarding();
  chassis.pid_wait();
  chassis.pid_turn_set(320_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-55_cm, 60, true);
  chassis.pid_wait();
  pros::delay(1000);
  chassis.pid_wait();
  motorstop();
  chassis.pid_wait();
  chassis.pid_drive_set(22_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(225_deg, TURN_SPEED);
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
}

void skills() {
  //plan out skills
  high();
  chassis.pid_wait();
  chassis.pid_drive_set(-50_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_drive_set(300.67_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
}

//sort later
void westmechnov() {
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

void leftnotsort() {
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

void rightnotsort(){
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
  high();
  chassis.pid_wait();
  pros::delay(3000);
  motorstop();
}

void notsort1() { 
  bool loaderStatus = false;
  bool bunnyStatus = false;
  
  //hoarding();
  chassis.pid_drive_set(100_cm, 70, true);
  chassis.pid_wait();
  motorstop();
  chassis.pid_turn_set(310_deg, TURN_SPEED);
  //hoarding();
  chassis.pid_wait();
  motorstop();
  chassis.pid_drive_set(-70_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(5_cm, DRIVE_SPEED, true);
  middle();
  chassis.pid_wait();
  motorstop();
  chassis.pid_drive_set(-90_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(180_deg, TURN_SPEED);
  chassis.pid_wait();
  loader.set_value(1);
  chassis.pid_wait();
  chassis.pid_drive_set(50_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  //hoarding();
  chassis.pid_wait();
  motorstop();
  chassis.pid_drive_set(-65_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(5_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  high();
  chassis.pid_wait();
  motorstop();
  //remember to have a colour sensor thingy incase we had blue balls
  //prep for drive control to start
}

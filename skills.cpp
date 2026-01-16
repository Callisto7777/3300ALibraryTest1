#include "main.h"
#include "config.hpp"

const int DRIVE_SPEED = 135;
const int TURN_SPEED = 100;

void skills15() {
  chassis.pid_drive_set(20_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-300.67_in, DRIVE_SPEED);
  chassis.pid_wait();
}

void skills() {
  chassis.pid_drive_set(-32_in, DRIVE_SPEED);
  chassis.pid_wait(); 
  chassis.pid_turn_set(270_deg, TURN_SPEED);
  chassis.pid_wait();
  hoarding();
  loader.set_value(1); 
  chassis.pid_wait();
  chassis.pid_drive_set(-14_in, DRIVE_SPEED);                                            
  chassis.pid_wait();
  pros::delay(800);//moving back and forth
  chassis.pid_drive_set(5_in, DRIVE_SPEED);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
  chassis.pid_wait();
  chassis.pid_drive_set(7_in, DRIVE_SPEED);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
  chassis.pid_wait();
  pros::delay(800);//robot now hoarding from the tubes top left

  chassis.pid_drive_set(20_in, DRIVE_SPEED); 
  loader.set_value(0); 
  chassis.pid_wait();
  chassis.pid_turn_set(315_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(26.7_in, DRIVE_SPEED); 
  chassis.pid_wait();
  chassis.pid_turn_set(270_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(60_in, 140); //long path infront of the long goal
  chassis.pid_wait();
  chassis.pid_turn_set(180_deg, TURN_SPEED);   //
  chassis.pid_wait();                        //
  chassis.pid_drive_set(15_in, DRIVE_SPEED); //see if you can make this entire part an arc or
  chassis.pid_wait();                        //a curve or something i dunno just make it not so clunky
  chassis.pid_turn_set(90_deg, TURN_SPEED); //
  chassis.pid_wait();                        // 
  chassis.pid_drive_set(30_in, DRIVE_SPEED); // 
  high();
  pros::delay(5678);//scoring top high goal on right side

  motorstop();
  hoarding();
  loader.set_value(1); 
  chassis.pid_wait();
  chassis.pid_drive_set(-60_in, 100);
  chassis.pid_wait();
  pros::delay(1670);//robot now hoarding from the tubes top right
  chassis.pid_drive_set(60_in, 67);
  loader.set_value(0); 
  motorstop();
  chassis.pid_wait();
  high();
  pros::delay(5678);//scoring on top high goal again after top right tube
       
  motorstop();


}

void skills30() {
  //first part
  chassis.pid_drive_set(-30_in, DRIVE_SPEED);
  chassis.pid_wait();
  hoarding(); 
  loader.set_value(1); //bringing the loader down
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-20_in, 67); //
  chassis.pid_wait();                // hoarding the 6 balls from the top left matchloader
  chassis.pid_drive_set(5_in, 100);   // slower to not have the balls jump out of the matchloader
  chassis.pid_wait();                //
  chassis.pid_drive_set(-15_in, 100); //
  chassis.pid_wait();
  pros::delay(2000);
  chassis.pid_drive_set(40_in, DRIVE_SPEED); 
  loader.set_value(0); 
  chassis.pid_wait();
  indication_sign.move_voltage(-10000); 
  pros::delay(100);
  high();             //scoring 6 balls on bottom high goal
  pros::delay(3670);
  motorstop(); //Scoring the 7 balls on top high goal

  //second part
  loader.set_value(0);
  chassis.pid_drive_set(-19_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_turn_set(225_deg, TURN_SPEED);
  chassis.pid_wait();
  hoarding();  //while going to middle goal get the 4 balls in center
  chassis.pid_drive_set(-40_in, 67);//go to middle goal (hopefully aline)
  chassis.pid_wait();
  chassis.pid_drive_set(-1_in, DRIVE_SPEED); //moving back and using trig to calc distance required
  chassis.pid_wait();                        //to travel to the second high goal
  chassis.pid_turn_set(165.59_deg, TURN_SPEED); 
  chassis.pid_wait();
  chassis.pid_drive_set(-68_in, 150);
  chassis.pid_wait();
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(25_in, DRIVE_SPEED); //aline with bottom long goal
  chassis.pid_wait();
  indication_sign.move_voltage(-10000); 
  pros::delay(100);
  high();             //scoring 6 balls on bottom high goal
  pros::delay(3670);
  motorstop();         // scoring the middle balls in bottom long goal

  //third part
  chassis.pid_wait();
  hoarding(); 
  loader.set_value(1); //bring loader down
  chassis.pid_wait();
  chassis.pid_drive_set(-45_in, 67); //go to the matchloader
  chassis.pid_wait();                //collecting balls from matchloader
  pros::delay(2000);                 //so awesome wowowowow (hopefully it alines again)
  chassis.pid_drive_set(50_in, DRIVE_SPEED);
  chassis.pid_wait();
  indication_sign.move_voltage(-10000); 
  pros::delay(100);
  high();             //scoring 6 balls on bottom high goal
  pros::delay(3444670);
  motorstop();
  chassis.pid_wait();
  chassis.pid_drive_set(-10_in, DRIVE_SPEED);
  loader.set_value(0); 
  chassis.pid_wait();
  chassis.pid_turn_set(180, TURN_SPEED); //turning towards park zone
  chassis.pid_wait();
  chassis.pid_drive_set(47_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_turn_set(270, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-20_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(300.67_in, DRIVE_SPEED); //Parking
  chassis.pid_wait();



}

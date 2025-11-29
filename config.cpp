//#include "lemlib/api.hpp" // IWYU pragma: keep
#include "main.h"
#include "config.hpp"
#include "pros/motors.hpp"

//green in 200 blue is 600 and red is 400 (rpm)

//drivetrain motor groups
pros::MotorGroup left_motors({2, -1, -13}, pros::MotorGearset::blue); 
pros::MotorGroup right_motors({-9, 10, 20}, pros::MotorGearset::blue); 

//other motor group
pros::Motor intake(16, pros::MotorGearset::red); // this is the intake first stage so the one that takes balls in
pros::Motor indication_sign(-8, pros::MotorGearset::red); // these are the top two sets of flex wheels which just decide hoarding and outaking / intaking
pros::Motor score(14, pros::MotorGearset::red); //this one decides scoring location
pros::ADIDigitalOut loader('A'); //match loader
pros::ADIDigitalOut bunny('B'); //bunny ears
//pros::Rotation scoreRotationSensor(9);
pros::Controller controller(pros::E_CONTROLLER_MASTER);
pros::Optical optical(12);

ez::Drive chassis(
    {2, -1, -13},
    {-9, 10, 20},
        // Left Chassis Ports  // Right Chassis Ports 

    5,      // IMU Port
    2.75,  // Wheel Diameter 
    450);   // Wheel RPM 



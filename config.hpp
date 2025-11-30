//give me a sec gang
#pragma once
#ifndef CONFIG_HPP
#define CONFIG_HPP
#include "main.h"

// pros libraries
// 3rd party libraries

#include "pros/adi.hpp"
#include "pros/motors.hpp"
#include "pros/rotation.hpp"
#include "EZ-Template/api.hpp"
#include "api.h"
#include "pros/optical.hpp"
//#include "lemlib/api.hpp"
//#include "robodash/api.h"
#include "liblvgl/lvgl.h"

extern Drive chassis;
//extern Drive chassis;

extern pros::MotorGroup left_motors; 
extern pros::MotorGroup right_motors;

extern pros::Controller controller;
extern pros::Motor intake; // this is the intake first stage so the one that takes balls in
extern pros::Motor indication_sign; // these are the top two sets of flex wheels which just decide hoarding and outaking / intaking
extern pros::Motor score; //this one decides scoring location
extern pros::ADIDigitalOut loader; //match loader
extern pros::ADIDigitalOut bunny; //bunny ears
extern pros::Optical optical;
//extern pros::Rotation scoreRotationSensor; //for odom ignore for now

//strings
extern std::string alliance;

/* Functions */
// DT
void arcadeDrive();
void refreshIntake();
void refreshClamp();
void refreshDoinker();
void refreshWallstakes();
void resetWallstakes();

void initializeColourSort();
void driverSkillsMacro();

//colour sort
void highbluesort();
void middlebluesort();
void highredsort();
void middleredsort();

//opcontrol
void high();
void middle();
void low();
void motorstop();
void hoarding();

/* Autons */
void skills();
void redLeft();
void default_constants();

//notsorted
void bunnyUp();

#endif
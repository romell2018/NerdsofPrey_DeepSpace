/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
// FOR PROGRAM TO WORK CTRE-Phoenix LIBRARY MUST BE DOWNLOADED

#include <iostream>
#include <ctre/Phoenix.h> // Library for motor controller
#include <Teleop/ExtraMath.h>
class DriveMode
{
public:
  DriveMode();
  ExtraMath *joystick;
  
  void ArcadeDrive(double moveVal, double rotateVal);
  void TankDrive(double leftValue, double rightValue);

  // Drive Motors
  TalonSRX *frontLeft;
  TalonSRX *frontRight;
  TalonSRX *backLeft;
  TalonSRX *backRight;
};

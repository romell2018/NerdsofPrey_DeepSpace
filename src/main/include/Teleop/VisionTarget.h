/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
// FOR PROGRAM TO WORK CTRE-Phoenix LIBRARY MUST BE DOWNLOADED
#include <iostream>
#include "NetworkTables/NetworkTable.h"
#include <ctre/Phoenix.h> // Library for motor controller
#include <frc/AnalogInput.h>

class VisionTarget
{
public:
  VisionTarget();

  void Drive(float leftValue, float rightValue);
  void LimelightOff();

  void LimelightOn(float forwardSpeed);
 // Drive Motors
  TalonSRX *frontLeft;
  TalonSRX *frontRight;
  TalonSRX *backLeft;
  TalonSRX *backRight;

  frc::AnalogInput *distanceSensor;

  float left_command;
  float right_command;
  float sumErrorAngle;
  float sumErrorDistace;
};

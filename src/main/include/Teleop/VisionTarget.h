/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <iostream>
#include "NetworkTables/NetworkTable.h"
#include <ctre/Phoenix.h>
#include <frc/AnalogInput.h>

class VisionTarget
{
public:
  VisionTarget();

  void Drive(float leftValue, float rightValue);
  void Off();

  void RunScriptScoreLow();
  void RunScriptScoreMed();
  void RunScriptScoreHigh();

  void RunScriptDiskLow(float forwardSpeed);
  void RunScriptDiskMed();
  void RunScriptDiskHigh();

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

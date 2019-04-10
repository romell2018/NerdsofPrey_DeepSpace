/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
// FOR PROGRAM TO WORK CTRE-Phoenix LIBRARY MUST BE DOWNLOADED
#include <ctre/Phoenix.h>
#include <frc/DigitalInput.h>
#include <frc/Counter.h>
#include <iostream>

class Hatch {
 public:
  Hatch();
  TalonSRX *hatch;
  frc::DigitalInput *limitSwitch;
  frc::Counter *hatchCounter;

  int hatchPosition;
  const double SPEED = 0.7;

  void HatchUp();
  void HatchDown();
  void HatchOff();
};

/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <frc/WPILib.h>
#include <frc/Solenoid.h> // Library for pistons (solenoids)

class Pneumatic
{
public:
  Pneumatic();
  void RunScriptForward();
  void RunScriptReverse();
  void RunScriptOff();

  frc::Compressor *compressor;
  frc::DoubleSolenoid *left;
  frc::DoubleSolenoid *right;
};

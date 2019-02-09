/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <frc/WPILib.h>
#include <Teleop/Lift.h>

class ControllerBox
{
public:
  std::shared_ptr<Lift> lift;

  ControllerBox(std::shared_ptr<Lift> lift);
  void RunScript();
  frc::Joystick *Manipulator;
};

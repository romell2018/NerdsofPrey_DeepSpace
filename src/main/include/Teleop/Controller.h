/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <Teleop/DriveMode.h>
#include <Teleop/Hatch.h>
#include <Teleop/IntakeLow.h>
#include <Teleop/Intake.h>
#include <Teleop/Lift.h>
#include <Teleop/Pneumatic.h>
#include <Teleop/VisionTarget.h>
#include <Teleop/Winch.h>
#include <frc/WPILib.h>

class Controller
{
public:
  DriveMode *drivemode;
  Hatch *hatchPanel;
  std::shared_ptr<Lift> lift;
  Pneumatic *pneumatic;
  Intake *intake;
  IntakeLow *intakeLow;
  VisionTarget *visiontarget;
  Winch *winch;
  bool runVision = false;

  Controller();
  void ControllerPeriodic(double deltaTime);

  frc::Joystick *Operator;
  
};

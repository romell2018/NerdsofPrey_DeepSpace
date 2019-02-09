/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <Teleop/DriveMode.h>
#include <Teleop/Flipper.h>
#include <Teleop/FlipperIntake.h>
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
  Flipper *flipper;
  FlipperIntake *flipperIntake;
  std::shared_ptr<Lift> lift;
  Pneumatic *pneumatic;
  Intake *intake;
  VisionTarget *visiontarget;
  Winch *winch;

  Controller();
  void RunScript();
  
  frc::Joystick *Operator;
  //frc::Joystick *right;

};

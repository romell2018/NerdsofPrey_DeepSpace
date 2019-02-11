/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <Teleop/Controller.h>
#include <Teleop/ControllerBox.h>
#include <CameraUSB.h>
#include <TeleOp/BlinkinLED.h>
#include "Teleop/DeltaTime.h"

#include <frc/IterativeRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <memory>
#include <string>

class Robot : public frc::IterativeRobot
{
public:
  Controller *controller;
  ControllerBox *controllerBox;
  CameraUSB *camera;
  BlinkinLED *led;
  DeltaTime *delta;

  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;
};

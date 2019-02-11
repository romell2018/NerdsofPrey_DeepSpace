/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit()
{
  controller = new Controller();
  controllerBox = new ControllerBox(controller->lift);
  camera = new CameraUSB();
  led = new BlinkinLED();
  camera->RunScript(); //runs usbcam(s)
}

void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit()
{
  //team::DeltaTime::InitializeLoop();
  led->RunScriptBlue();
  controller->lift->targetPosition = Positions::manual;
}

void Robot::TeleopPeriodic()
{
  //delta->UpdateElapsed();
  controller->RunScript();
  controllerBox->RunScript();
  //std::cout << "Elapsed Time: " << delta->GetElapsed() << std::endl;
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main()
{
  return frc::StartRobot<Robot>();
}
#endif

/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Teleop/Intake.h"

Intake::Intake()
{
    intake = new TalonSRX(7);
}
void Intake::In()
{
    intake->Set(ControlMode::PercentOutput, -0.57);
}
void Intake::Out()
{
    intake->Set(ControlMode::PercentOutput, 0.57);
}
void Intake::Off()
{
    intake->Set(ControlMode::PercentOutput, 0);
}
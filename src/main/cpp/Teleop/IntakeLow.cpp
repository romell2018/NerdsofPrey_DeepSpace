/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Teleop/IntakeLow.h"

IntakeLow::IntakeLow() {
    intakeLow = new TalonSRX(8);
}
void IntakeLow::In()
{
    intakeLow->Set(ControlMode::PercentOutput, 1);
}
void IntakeLow::Out()
{
    intakeLow->Set(ControlMode::PercentOutput, -1);
}
void IntakeLow::Off()
{
    intakeLow->Set(ControlMode::PercentOutput, 0);
}
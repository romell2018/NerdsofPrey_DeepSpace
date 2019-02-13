/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Teleop/Flipper.h"
//id 09
Flipper::Flipper()
{
    flipper = new TalonSRX(9);
    limitSwitch = new frc::DigitalInput(8);
}
void Flipper::HookUp()
{
    flipper->Set(ControlMode::PercentOutput, -0.6);
}
void Flipper::HookDown()
{
    flipper->Set(ControlMode::PercentOutput, 0.6);
    if (limitSwitch->Get() == true)
    {
        flipper->Set(ControlMode::PercentOutput, 0.0);
    }
}
void Flipper::HookOff()
{
    flipper->Set(ControlMode::PercentOutput, 0.0);
}

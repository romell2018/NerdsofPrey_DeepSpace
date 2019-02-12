/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Teleop/Winch.h"

Winch::Winch()
{
    winchR = new TalonSRX(10);
    winchL = new TalonSRX(11);
}

void Winch::up()
{
    winchL->Set(ControlMode::PercentOutput, -0.9);
    winchR->Set(ControlMode::PercentOutput, 0.9);
}
void Winch::down()
{
    winchL->Set(ControlMode::PercentOutput, 0.9);
    winchR->Set(ControlMode::PercentOutput, -0.9);
}
void Winch::off()
{
    winchL->Set(ControlMode::PercentOutput, 0);
    winchR->Set(ControlMode::PercentOutput, 0);
}
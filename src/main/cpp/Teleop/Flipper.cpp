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
}

void Flipper::up()
{
    flipper->Set(ControlMode::PercentOutput, -0.6);
}
void Flipper::down()
{
    flipper->Set(ControlMode::PercentOutput, 0.6);
}
void Flipper::off()
{
    flipper->Set(ControlMode::PercentOutput, -0.09);
}


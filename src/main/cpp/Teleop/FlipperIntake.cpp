/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Teleop/FlipperIntake.h"

FlipperIntake::FlipperIntake() 
{
    flipperIntake = new TalonSRX(8);
}

void FlipperIntake::In(){
    flipperIntake->Set(ControlMode::PercentOutput, 0.57);
}
void FlipperIntake::Out(){
    flipperIntake->Set(ControlMode::PercentOutput, -0.57);
}
void FlipperIntake::Off(){
    flipperIntake->Set(ControlMode::PercentOutput, 0);
}
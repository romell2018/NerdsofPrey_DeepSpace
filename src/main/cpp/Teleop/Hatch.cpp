/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Hatch.h"

Hatch::Hatch() {
    hatch = new TalonSRX(9);
    limitSwitch = new frc::DigitalInput(0);
}
void Hatch::HatchUp()
{
    hatch->Set(ControlMode::PercentOutput, -SPEED);
}
void Hatch::HatchDown()
{
    hatch->Set(ControlMode::PercentOutput, SPEED);
    if (limitSwitch->Get() == true)
    {
        hatch->Set(ControlMode::PercentOutput, 0.0);
    }
}
void Hatch::HatchOff()
{
    hatch->Set(ControlMode::PercentOutput, 0.0);
}

/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Teleop/Hatch.h"

Hatch::Hatch() {
    hatch = new TalonSRX(9);
    limitSwitch = new frc::DigitalInput(0);
    hatchCounter = new frc::Counter(1);
    hatchCounter->SetUpSource(1);
    hatchCounter->SetDownSource(1);
    hatchCounter->SetUpDownCounterMode();
    hatchPosition = hatchCounter->Get();
}
void Hatch::HatchUp()
{
    hatch->Set(ControlMode::PercentOutput, -SPEED);
    hatchPosition += hatchCounter->Get();
}
void Hatch::HatchDown()
{
    hatch->Set(ControlMode::PercentOutput, SPEED);
    if (limitSwitch->Get() == true)
    {
        hatch->Set(ControlMode::PercentOutput, 0.0);
        hatchPosition = 0;
    }else{
        hatchPosition -= 1;
    }
}
void Hatch::HatchOff()
{
    std::cout <<"Hatch: " << hatchCounter->Get() << std::endl << std::endl;
    hatch->Set(ControlMode::PercentOutput, 0.0);
}

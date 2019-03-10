/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Teleop/Pneumatic.h"

Pneumatic::Pneumatic()
{
    // ---------------------------------------------------------------
    // Define Pneumatics/Compressor
    // Define the Compressor and pneumatics pistons to their variable names and corresponding ports on the robot
    // ---------------------------------------------------------------

    compressor = new frc::Compressor(0);

    left = new frc::DoubleSolenoid(0, 1);
    right = new frc::DoubleSolenoid(2, 3);

    compressor->SetClosedLoopControl(true);
}
void Pneumatic::RunScriptForward()
{
    left->Set(frc::DoubleSolenoid::Value::kForward);
    right->Set(frc::DoubleSolenoid::Value::kForward);
}
void Pneumatic::RunScriptReverse()
{
    left->Set(frc::DoubleSolenoid::Value::kReverse);
    right->Set(frc::DoubleSolenoid::Value::kReverse);
}
void Pneumatic::RunScriptOff()
{
    left->Set(frc::DoubleSolenoid::Value::kOff);
    right->Set(frc::DoubleSolenoid::Value::kOff);
}
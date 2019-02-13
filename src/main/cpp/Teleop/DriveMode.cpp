/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Teleop/DriveMode.h"

DriveMode::DriveMode()
{
    // ---------------------------------------------------------------
    // Define Motors
    // Define the motors to their variable names and corresponding ports on the robot
    // ---------------------------------------------------------------

    frontLeft = new TalonSRX(1);
    frontRight = new TalonSRX(2);
    backLeft = new TalonSRX(3);
    backRight = new TalonSRX(4);

    joystick = new ExtraMath();
}
void DriveMode::ArcadeDrive(double moveVal, double rotateVal)
{
    // Driving variables (Speed of the robot)
    double leftPercent = 0.0;
    double rightPercent = 0.0;

    // Clamp moveVal and rotateVal.
    // Assume a deadzone is already being applied to these values.
    moveVal = joystick->sensitivity(moveVal, 1);
    rotateVal = joystick->sensitivity(rotateVal, 0.4);

    //combine varibles
    leftPercent = moveVal + rotateVal;
    rightPercent = moveVal - rotateVal;

    // Clamp motor percents
    leftPercent = joystick->sensitivity(leftPercent, 0.75);
    rightPercent = joystick->sensitivity(rightPercent, 0.75);

    // Apply speeds to motors
    frontLeft->Set(ControlMode::PercentOutput, leftPercent);
    frontRight->Set(ControlMode::PercentOutput, rightPercent); //if failed add ( * -1)
    backLeft->Set(ControlMode::PercentOutput, leftPercent);
    backRight->Set(ControlMode::PercentOutput, rightPercent); //if failed add ( * -1)
}
void DriveMode::TankDrive(double leftValue, double rightValue)
{

    frontLeft->Set(ControlMode::PercentOutput, leftValue);
    frontRight->Set(ControlMode::PercentOutput, rightValue);
    backLeft->Set(ControlMode::PercentOutput, leftValue);
    backRight->Set(ControlMode::PercentOutput, rightValue);
}

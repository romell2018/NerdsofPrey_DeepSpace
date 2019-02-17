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
}
void DriveMode::ArcadeDrive(double moveVal, double rotateVal, double deltaTime)
{
    // Driving variables (Speed of the robot)
    double leftTarget = 0.0;
    double rightTarget = 0.0;

    // Reshapes moveVal and rotateVal.
    // Assume a deadzone is already being applied to these values.
    moveVal = ExtraMath::sensitivity(moveVal, 1);
    rotateVal = ExtraMath::sensitivity(rotateVal, 0.75);

    //combine varibles
    leftTarget = moveVal + rotateVal;
    rightTarget = moveVal - rotateVal;

    double gain = 0;

    if(std::abs(moveVal) < BREAK_THRESHOLD) gain = BREAK_GAIN;
    else gain = MOVEMENT_GAIN;
    
    if(std::abs(leftOutput - leftTarget) < TARGET_THRESHOLD) leftOutput = leftTarget;
    else if(leftOutput < leftTarget) leftOutput += deltaTime * gain;
    else if(leftOutput > leftTarget) leftOutput -= deltaTime * gain;

    if(std::abs(rightOutput - rightTarget) < TARGET_THRESHOLD) rightOutput = rightTarget;
    else if(rightOutput < rightTarget) rightOutput += deltaTime * gain;
    else if(rightOutput > rightTarget) rightOutput -= deltaTime * gain;

    // Apply speeds to motors
    std::cout << leftTarget << std::endl;
    std::cout << rightTarget << std::endl;
    std::cout << leftOutput << std::endl;
    std::cout << rightOutput << std::endl;
    std::cout << std::endl;

    //frontLeft->Set(ControlMode::PercentOutput, leftTarget);
    //frontRight->Set(ControlMode::PercentOutput, -rightTarget);
    //backLeft->Set(ControlMode::PercentOutput, leftTarget);
    //backRight->Set(ControlMode::PercentOutput, -rightTarget);

    frontLeft->Set(ControlMode::PercentOutput, leftOutput);
    frontRight->Set(ControlMode::PercentOutput, -rightOutput);
    backLeft->Set(ControlMode::PercentOutput, leftOutput);
    backRight->Set(ControlMode::PercentOutput, -rightOutput);
}
void DriveMode::TankDrive(double leftValue, double rightValue)
{

    frontLeft->Set(ControlMode::PercentOutput, leftValue);
    frontRight->Set(ControlMode::PercentOutput, rightValue);
    backLeft->Set(ControlMode::PercentOutput, leftValue);
    backRight->Set(ControlMode::PercentOutput, rightValue);
}

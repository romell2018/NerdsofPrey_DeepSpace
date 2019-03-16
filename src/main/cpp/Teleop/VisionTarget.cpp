/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Teleop/VisionTarget.h"

VisionTarget::VisionTarget()
{
    frontLeft = new TalonSRX(1);
    frontRight = new TalonSRX(2);
    backLeft = new TalonSRX(3);
    backRight = new TalonSRX(4);

    distanceSensor = new frc::AnalogInput(0);

    sumErrorAngle = 0;
    sumErrorDistace = 0;
}

void VisionTarget::Drive(float left, float right)
{

    frontLeft->Set(ControlMode::PercentOutput, left);
    frontRight->Set(ControlMode::PercentOutput, right);
    backLeft->Set(ControlMode::PercentOutput, left);
    backRight->Set(ControlMode::PercentOutput, right);
}
void VisionTarget::LimelightOff()
{
    //std::cout << "Sonic Value: " << distanceSensor->GetValue() << std::endl;
    // Get limelight table for reading tracking data
    std::shared_ptr<NetworkTable> table = NetworkTable::GetTable("limelight");

    //turn the lights off
    table->PutNumber("ledMode", 1); //force off
    table->PutNumber("camMode", 1); //Driver Camera (Increases exposure, disables vision processing)
}

void VisionTarget::LimelightOn(float forwardSpeed)
{

    float Kp = 0.030f;   // Proportional control constant, control how much a mechanism can move.
    float Ki = 0.000055f; //sum of all the past error, increase more and more the longer the motor isn’t where it’s supposed to be.
    float KpDist = 0.001f;
    //float disError = 370 - distanceSensor->GetValue();
    //we calculated the error in heading and multiplied that by a constant,
    //thus making a motor command which is proportional to the error.

    float min_command = 0.05f; //a constant amount of power needed for the robot to actually move

    std::shared_ptr<NetworkTable> table = NetworkTable::GetTable("limelight");
    table->PutNumber("camMode", 0);
    table->PutNumber("ledMode", 0);  //turn the lights on
    table->PutNumber("pipeline", 1); //Sets limelight’s current pipeline

    float tx = table->GetNumber("tx", 0); //Vision processor

    // Aim error and distance error based on calibrated limelight crossahair
    float heading_error = -tx;
    float steering_adjust = 0.0f;

    //Distance Sensor
    //std::cout << "Sonic Value: " << distanceSensor->GetValue() << std::endl;
    //std::cout << disError << std::endl;

    // Distance adjust, drive to the correct distance from the goal
    if (tx > 1.0)
    {
        steering_adjust = heading_error - min_command;
    }
    else if (tx < 1.0)
    {
        steering_adjust = heading_error + min_command;
    }

    sumErrorAngle += steering_adjust;

    //calculate
    left_command = /*(-KpDist * disError) + */ (-Kp * steering_adjust) + (-Ki * sumErrorAngle) + (forwardSpeed);
    right_command = /*(KpDist * disError) + */ (-Kp * steering_adjust) + (-Ki * sumErrorAngle) + (-forwardSpeed);

    //PREVENTS THE ROBOT FROM OSCILLATING the the kp
    if(std::abs(left_command) < 0.1) left_command = 0;
    if(std::abs(right_command) < 0.1) right_command = 0; 

    std::cout << "left_command:" << left_command << " | right_command:" << right_command << std::endl;

    //apply to drive train
    Drive(left_command, right_command);
}

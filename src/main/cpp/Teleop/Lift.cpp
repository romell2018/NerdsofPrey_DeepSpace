/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Teleop/Lift.h"
#include <iostream>

Lift::Lift()
{
    liftL = new TalonSRX(5);
    liftR = new TalonSRX(6);

    liftL->SetSelectedSensorPosition(0, 0, 10); //set encoder
    liftR->SetSelectedSensorPosition(0, 0, 10); //set encoder

    liftL->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0, 10);
    liftR->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0, 10);

    std::cout << "Encoder Position " << LiftPosition() << std::endl;
}

void Lift::LiftUp()
{
    pastError = 0;
    sumError = 0;

    liftR->Set(ControlMode::PercentOutput, 0.57);
    liftL->Set(ControlMode::PercentOutput, -0.57);

    //std::cout << "Encoder Position " << LiftPosition() << std::endl;
}
void Lift::LiftDown()
{
    pastError = 0;
    sumError = 0;

    liftR->Set(ControlMode::PercentOutput, -0.57);
    liftL->Set(ControlMode::PercentOutput, 0.57);
}
void Lift::LiftOff()
{
    pastError = 0;
    sumError = 0;

    liftR->Set(ControlMode::PercentOutput, 0);
    liftL->Set(ControlMode::PercentOutput, 0);
    //std::cout << "Encoder Position " << LiftPosition() << std::endl;


}

float Lift::LiftPosition() { return liftL->GetSelectedSensorPosition(0); }

void Lift::ControlLift(int direction)
{
    //std::cout << "targetPosition: " << targetPosition << std::endl;
    //std::cout << "LiftPosition: " << LiftPosition() << std::endl;

    if (targetPosition >= 0)
    {
        int deltaTargetPosition = targetPosition - LiftPosition();
        if (LiftPosition() < SLOW_ZONE)
        {
            if (deltaTargetPosition > MAX_DELTA)
                deltaTargetPosition = MAX_DELTA;
            else if (deltaTargetPosition < -MAX_SLOW_DELTA)
                deltaTargetPosition = -MAX_SLOW_DELTA;
        }
        else
        {
            if (deltaTargetPosition > MAX_DELTA)
                deltaTargetPosition = MAX_DELTA;
            else if (deltaTargetPosition < -MAX_DELTA)
                deltaTargetPosition = -MAX_DELTA;
        }

        shapedTargetPosition = LiftPosition() + deltaTargetPosition;

        std::cout << "shapedTargetPostion" << shapedTargetPosition << std::endl;

        UpdatePID(shapedTargetPosition);
    }
    else
    {
        if (targetPosition == -1) //assisted manual
        {
            if (direction == 1)
                shapedTargetPosition += 25;
            if (direction == -1)
                shapedTargetPosition -= 25;
            UpdatePID(shapedTargetPosition);
        }
        if (targetPosition == -2) //manual
        {
            if (direction == 1)
                LiftUp();
            if (direction == 0)
                LiftOff();
            if (direction == -1)
                LiftDown();
            shapedTargetPosition = LiftPosition();
        }
    }
}

void Lift::UpdatePower(float power)
{
    liftL->Set(ControlMode::PercentOutput, -power);
    liftR->Set(ControlMode::PercentOutput, power);
}

void Lift::SetTarget(int target)
{
    sumError = 0;
    pastError = 0;
    targetPosition = target;
}

void Lift::UpdatePID(float target)
{
    error = target - LiftPosition();
    sumError += error;
    deltaError = error - pastError;
    //float speedStabilization = 0;
    //if (std::abs(deltaError) > maxSpeed)
    //speedStabilization = deltaError / 1000;
    float output = (kp * error); // + speedStabilization; //+ (ki * sumError) + (kd * deltaError);
    output = (output < -1) ? -1 : (output > 1) ? 1 : output;

/*
if (abs(output) > 0.1) {
    output = 0;
    }
*/
    std::cout << "lift position: " << LiftPosition() << std::endl;
    std::cout << "target: " << target << std::endl;
    std::cout << "sum error: " << sumError << std::endl;
    std::cout << "output: " << output << std::endl << std::endl;
    UpdatePower(output);
    pastError = error;
}
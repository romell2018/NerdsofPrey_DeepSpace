/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Teleop/Lift.h"

Lift::Lift()
{
    liftL = new TalonSRX(5);
    liftR = new TalonSRX(6);
    //limitSwitch = new frc::DigitalInput(0);

    liftL->SetSelectedSensorPosition(0, 0, 10); //set encoder
    liftR->SetSelectedSensorPosition(0, 0, 10); //set encoder

    liftL->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0, 10);
    liftR->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0, 10);
}

void Lift::LiftUp()
{
    pastError = 0;
    sumError = 0;
   // UpdatePower(0.57);
    liftR->Set(ControlMode::PercentOutput, 0.57);
    liftL->Set(ControlMode::PercentOutput, -0.57);
    std::cout << "Encoder Position " << LiftPosition() << std::endl;
}
void Lift::LiftDown()
{
    pastError = 0;
    sumError = 0;
    //UpdatePower(-0.57);
    liftR->Set(ControlMode::PercentOutput, -0.57);
    liftL->Set(ControlMode::PercentOutput, 0.57);
}
void Lift::LiftOff()
{
    pastError = 0;
    sumError = 0;
    //UpdatePower(0);
    liftR->Set(ControlMode::PercentOutput, 0);
    liftL->Set(ControlMode::PercentOutput, 0);
    std::cout << "Encoder Position " << LiftPosition() << std::endl;
}

float Lift::LiftPosition() { return liftL->GetSelectedSensorPosition(0); }

void Lift::ControlLift(int direction)
{
    if (targetPosition >= 0)
    {
        UpdatePID(targetPosition);
        manualTargetPosition = targetPosition;
    }
    else
    {
        if (targetPosition == -1)//assisted manual
        {
            if(direction == 1)
                manualTargetPosition += 50;
            if(direction == -1)
                manualTargetPosition -= 50;
            UpdatePID(manualTargetPosition);
        }
        if(targetPosition == -2)//manual
        {
            if(direction == 1)
                LiftUp();
            if(direction == 0)
                LiftOff();
            if(direction == -1)
                LiftDown();
            manualTargetPosition = LiftPosition();
        }
    }
}

void Lift::UpdatePower(float power)
{
    /*
    if ((limitSwitchBottom->Get() == true && power >= 0) || limitSwitchBottom->Get() != true && limitSwitchTop->Get() != true || limitSwitchTop->Get() == true && power <= 0)
    {
        liftL->Set(ControlMode::PercentOutput, -power);
        liftR->Set(ControlMode::PercentOutput, power);
    }else{
        liftL->Set(ControlMode::PercentOutput, 0);
        liftR->Set(ControlMode::PercentOutput, 0);
    }
*/
   liftL->Set(ControlMode::PercentOutput, -power);
   liftR->Set(ControlMode::PercentOutput, power);
}

void Lift::SetTarget(Positions target)
{
    sumError = 0;
    pastError = 0;
    targetPosition = target;
}

void Lift::UpdatePID(float target)
{
    kp = 0.00055;
    ki = 0;
    kd = 0;
    error = target - LiftPosition();
    sumError += error;
    deltaError = error - pastError;
    //float speedStabilization = 0;
    //if (std::abs(deltaError) > maxSpeed)
        //speedStabilization = deltaError / 1000;
    float output = (kp * error);// + speedStabilization; //+ (ki * sumError) + (kd * deltaError);
    output = (output < -1) ? -1 : (output > 1) ? 1 : output;

    std::cout << "lift position: " << LiftPosition() << std::endl;
    std::cout << "target: " << target << std::endl;
    std::cout << "sum error: " << sumError << std::endl;
    std::cout << "output: " << output << std::endl << std::endl;
    UpdatePower(output);
    pastError = error;
}
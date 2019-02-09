/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Teleop/Controller.h"

Controller::Controller()
{
    drivemode = new DriveMode();
    intake = new Intake();
    lift = std::make_shared<Lift>();
    pneumatic = new Pneumatic();
    visiontarget = new VisionTarget();
    winch = new Winch();
    Operator = new frc::Joystick(0);
    flipperIntake = new FlipperIntake();
    flipper = new Flipper();
    //thing and another and one more
}

void Controller::RunScript()
{
    
    drivemode->ArcadeDrive(Operator->GetRawAxis(4), -Operator->GetRawAxis(1));
   
    if (Operator->GetRawButton(5))
    {
        intake->In();
        flipperIntake->In();
    }
    else if (Operator->GetRawButton(6))
    {
        intake->Out();
        flipperIntake->Out();
    }
    else
    {
        intake->Off();
        flipperIntake->Off();
    }
    if (Operator->GetPOV() == 0)
    {
        flipper->up(); //move down
    }
    else if (Operator->GetPOV() == 180)
    {
        flipper->down(); //move up
    }
    else
    {
        flipper->off(); //off
    }
    if (Operator->GetRawButton(4)) //pressed Y
    {
        lift->ControlLift(1);
    }
    else if (Operator->GetRawButton(1)) //pressed A
    {
        lift->ControlLift(-1);
    }
    else
    {
        lift->ControlLift(0);
    }

    if (Operator->GetRawButton(2)) //pressed X
    {
        visiontarget->RunScriptDiskLow(-0.25 * Operator->GetRawAxis(1));
    }
    else
    {
        visiontarget->Off();
    }
    /*
    if(Operator->GetRawButton(0)){
        winch->up();
    }
    else if(Operator->GetRawButton(0)){
        winch->down();

    }
    else
    {
        winch->off();
    }
  
    if (Operator->GetRawButton(0))
    {
        pneumatic->RunScriptForward();
    }
    else if (Operator->GetRawButton(0))
    {
        pneumatic->RunScriptReverse();
    }
    else
    {
        pneumatic->RunScriptOff();
    }
    */
}

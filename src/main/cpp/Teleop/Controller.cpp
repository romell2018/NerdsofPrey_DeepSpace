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
   // right = new frc::Joystick(1);
    flipperIntake = new FlipperIntake();
    flipper = new Flipper();
}

void Controller::RunScript()
{
    /*Left controls:
        Axis:
        0. 
        1. Move Forward/Backward
        2. Change Drive Mode

        button:
        1. Intake In
        2. Flipper move Down
        3. Flipper move Up
        4.
        5. Vision Tracking
        6.
        7.
        8.
        9.

    Right controls:
        Axis:
        0.
        1.Rotate Bot
        2.
        
        button:
        1. Intake Out
        2. Lift move Down
        3. Lift move Up
        4.
        5. 
        6.
        7.
        8.
        9.
        10. Winch move up
        11. Winch move down
    

    if (left->GetRawAxis(2) > 0) //Select Drive Mode
    {
        drivemode->ArcadeDrive(right->GetRawAxis(0), -left->GetRawAxis(1)); //use ArcadeDrive
    }
    else
    {
        drivemode->TankDrive(-left->GetRawAxis(1), right->GetRawAxis(1)); //use TankDrive
    }

    //Use Intake
    if (left->GetRawButton(1))
    {
        intake->In();
        flipperIntake->In();
    }
    else if (right->GetRawButton(1))
    {
        intake->Out();
        flipperIntake->Out();
    }
    else
    {
        intake->Off();
        flipperIntake->Off();
    }
    //USE LIFT
    if (right->GetRawButton(3))
    {
        lift->ControlLift(1); //move up
    }
    else if (right->GetRawButton(2))
    {
        lift->ControlLift(-1); //move down
    }
    else
    {
        lift->ControlLift(0); //off
    }

    //USE FLIPPER
    if (left->GetRawButton(3))
    {
        flipper->up(); //move down
    }
    else if (left->GetRawButton(2))
    {
        flipper->down(); //move up
    }
    else
    {
        flipper->off(); //off
    }

    //USE TARGETVISION
    if (left->GetRawButton(5))
    {
        visiontarget->RunScriptDiskLow(-0.25 * left->GetRawAxis(1));
    }
    else
    {
        visiontarget->Off();
    }
    if (right->GetRawButton(11))
    {
        winch->up();
    }
    else if (right->GetRawButton(10))
    {
        winch->down();
    }
    else
    {
        winch->off();
    }
    
    /* TODO :
    Winch
    Pnematics
*/

    
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

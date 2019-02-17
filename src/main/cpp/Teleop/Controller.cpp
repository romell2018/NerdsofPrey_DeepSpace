/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Teleop/Controller.h"

Controller::Controller()
{
    // ---------------------------------------------------------------
    // Define Controllers
    // Define which controllers (joysticks) will be the driver or co driver for control
    // ---------------------------------------------------------------

    Operator = new frc::Joystick(0);

    // ---------------------------------------------------------------
    // Define Functions
    // ---------------------------------------------------------------

    drivemode = new DriveMode();
    intake = new Intake();
    lift = std::make_shared<Lift>();
    pneumatic = new Pneumatic();
    visiontarget = new VisionTarget();
    winch = new Winch();

    intakeLow = new IntakeLow();
    hatchPanel = new Hatch();
    //thing and another and one more plus one
}

void Controller::ControllerPeriodic(double deltaTime)
{
    // Drive
    drivemode->ArcadeDrive(-Operator->GetRawAxis(1), Operator->GetRawAxis(4), deltaTime);
    // VISION TRACKING
    if (Operator->GetRawButton(2))
        runVision = true;
    if (Operator->GetRawButton(3))
        runVision = false;

    if (runVision)
        visiontarget->LimelightOn(-0.25 * Operator->GetRawAxis(1)); //pressed X
    else
        visiontarget->LimelightOff();
    // LIFT
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

    // INTAKE
    if (Operator->GetRawButton(5))
    {
        intake->In();
        intakeLow->In();
    }
    else if (Operator->GetRawButton(6))
    {
        intake->Out();
        intakeLow->Out();
    }
    else
    {
        intake->Off();
        intakeLow->Off();
    }
    // HATCH PANEL HOOK
    if (Operator->GetPOV() == 0)
    {
        hatchPanel->HatchUp(); //move down
    }
    else if (Operator->GetPOV() == 180)
    {
        hatchPanel->HatchDown(); //move up
    }
    else
    {
        hatchPanel->HatchOff(); //off
    }
    // PNEUMATICS
    if (Operator->GetPOV() == 90) //in
    {
        pneumatic->RunScriptForward();
    }
    else if (Operator->GetPOV() == 270) //out
    {
        pneumatic->RunScriptReverse();
    }
    else
    {
        pneumatic->RunScriptOff();
    }

    // WINCH
    if (Operator->GetRawButton(7))
    {
        winch->WinchUp();
    }
    else if (Operator->GetRawButton(8))
    {
        winch->WinchDown();
    }
    else
    {
        winch->WinchOff();
    }
}

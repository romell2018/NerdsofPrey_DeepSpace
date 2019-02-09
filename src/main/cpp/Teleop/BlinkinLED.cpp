/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Teleop/BlinkinLED.h"

BlinkinLED::BlinkinLED()
{
    led = new frc::Spark(1);
}

void BlinkinLED::RunScriptBlue()
{
    //Solid Colors Blue
    led->Set(0.87);
}
void BlinkinLED::RunScriptRed()
{
    // Solid Colors Red
    led->Set(0.61);
}
void BlinkinLED::RunScriptIdle()
{
    //Strobe, White
    led->Set(-0.05);
}

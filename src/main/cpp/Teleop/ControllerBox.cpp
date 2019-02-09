/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Teleop/ControllerBox.h"
#include "Teleop/Lift.h"
#include <functional>

ControllerBox::ControllerBox(std::shared_ptr<Lift> lift)
{
     this->lift = lift;
     Manipulator = new frc::Joystick(1);
}
void ControllerBox::RunScript()
{
     if(Manipulator->GetRawButton(1))
     {
          lift->SetTarget(Positions::ballHigh);//ball high
     }
     if(Manipulator->GetRawButton(2))
     {
          lift->SetTarget(Positions::ballMid);//ball mid
     }
     if(Manipulator->GetRawButton(3))
     {
          lift->SetTarget(Positions::ballLow);//ball low     
     }
     if(Manipulator->GetRawButton(4))
     {
          lift->SetTarget(Positions::diskHigh);//disk high
     }
     if(Manipulator->GetRawButton(5))
     {
          lift->SetTarget(Positions::diskMid);//disk med
     }
     if(Manipulator->GetRawButton(6))
     {
          lift->SetTarget(Positions::diskLow);//disk low
     }
     if(Manipulator->GetRawButton(7))//assisted manual
     {
          lift->SetTarget(Positions::assistedManual);
     }
     if(Manipulator->GetRawButton(8))//maunal
     {
          lift->SetTarget(Positions::manual);
     }
     if(Manipulator->GetRawButton(9))
     {
          lift->SetTarget(Positions::floor);
     }
}
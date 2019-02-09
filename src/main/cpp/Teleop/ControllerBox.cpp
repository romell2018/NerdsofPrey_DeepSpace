/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Teleop/ControllerBox.h"
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
          lift->SetTarget(Lift::Positions::ballHigh);//ball high
     }
     if(Manipulator->GetRawButton(2))
     {
          lift->SetTarget(Lift::Positions::ballMid);//ball mid
     }
     if(Manipulator->GetRawButton(3))
     {
          lift->SetTarget(Lift::Positions::ballLow);//ball low     
     }
     if(Manipulator->GetRawButton(4))
     {
          lift->SetTarget(Lift::Positions::diskHigh);//disk high
     }
     if(Manipulator->GetRawButton(5))
     {
          lift->SetTarget(Lift::Positions::diskMid);//disk med
     }
     if(Manipulator->GetRawButton(6))
     {
          lift->SetTarget(Lift::Positions::diskLow);//disk low
     }
     if(Manipulator->GetRawButton(7))//assisted manual
     {
          lift->SetTarget(Lift::Positions::assistedManual);
     }
     if(Manipulator->GetRawButton(8))//maunal
     {
          lift->SetTarget(Lift::Positions::manual);
     }
     if(Manipulator->GetRawButton(9))
     {
          lift->targetPosition = Lift::Positions::floor;
     }
}
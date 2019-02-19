/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------
             ???$$                               ?ZZ?                         
              ~??$$$$.                            ZZZZZZ                        
              ???$$$$$$.                        $ZZZZZZZZZ.                     
              ???$$$$$$$$.                    .ZZZZZZZZZZZZ.                    
              ???$$$$$$$$$.                  ZZZZZZZ??ZZZZZZZ                   
             ???$$$$$$$$$$$$     ???????????ZZZZZZ??????ZZZZZZZ                 
             ???$$$$$??$$$$$$$????????????ZZZZZZZ???   ???ZZZZZZ                
             ???$$$$? :??$$$$$$??       .ZZZZZZ???      ???ZZZZZZZ              
            =??$$$$$.   ??I$$$$$$.     ZZZZZZZ????.       ???ZZZZZZZ            
            ???$$$$$     .??$$$$$$$   ZZZZZZ??? .??         ??IZZZZZZ           
            ???$$$$$      ????$$$$$$ZZZZZZZ???    ?          ??ZZZZZZZ          
            ???$$$$.         ???$$$$??ZZZZZZZ.               .ZZZZZZ??          
           ???$$$$$.         ????$$$$???ZZZZZZ.        ?    ZZZZZZZ??           
           ???$$$$$  ?     ??$$$$$$$$$???ZZZZZZZ.      ?  ,ZZZZZZ???            
           ???$$$$.  ??     .$$$$$$$$$. ???ZZZZZ      ? .ZZZZZZZ??              
          ???$$$$$??????       .$$        ??7.       ???ZZZZZZ???               
          ???$$$$$?$$$$???                        .???ZZZZZZ$??                 
          ???$$$$$$$$$$$????                    =????ZZZZZZ???                  
          ???$$$$$$$$$$7  ??????             ??????ZZZZZZZ??                    
         ???$$$$$$$$.       ???????????????????????ZZZZZ???                     
         ???$$$$..              ?????????????     ???Z$??                       
        .???$                                      ?????                        
                                                     ?                          
                                                                                
                                                              
    DDDDDDDDDDDDDD $DDDDDDD IDDDDDDDDDDDDDDD    .DDDDDDDDDDDZ DDDDDDDDDDDDDDDDD 
   DDDDDDDDDDDDDD  DDDDDDD  DDDDDDDDDDDDDDDDD  DDDDDDDDDDDDD DDDDDDDDDDDDDDDDDD 
   DDDDDDDDDDDDDD  DDDDDDD  DDDDDDDDDDDDDDDDD DDDDDDDDDDNDDD DDDDDDDDDDDDDDDDDI 
   DDDDDDD        DDDDDDDO DDDDDDD    DDDDDDD DDDDDDD             DDDDDDD       
  DDDDDDD+        DDDDDDD  DDDDDDD    DDDDDDD DDDDDDDDDD         +DDDDDDD       
  DDDDDDDDDDDDDD  DDDDDDD .DDDDDDD DDDDDDDDD   DDDDDDDDDDDD      DDDDDDD        
  DDDDDDDDDDDDDD DDDDDDD  DDDDDDDDDDDDDDDDD     IDDDDDDDDDDD     DDDDDDD        
 DDDDDDDDDDDDDD .DDDDDDD  DDDDDDDDDDDDD?           7DDDDDDDD    DDDDDDDZ        
 DDDDDDD        .DDDDDDD  DDDDDDIDDDDDDD     D       DDDDDDD    DDDDDDD         
~DDDDDDD        DDDDDDD  DDDDDDD  DDDDDDD    DDDDDDDDDDDDDD     DDDDDDD         
DDDDDDD         DDDDDDD. DDDDDDD  DDDDDDDD  7DDDDDDDDDDDDD     DDDDDDD   
DDDDDDD        DDDDDDDD DDDDDDD   .DDDDDDDD DDDDDDDDDDDD       DDDDDDD*/

#include "Robot.h"

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h> // Library to connect the code and the driver station

void Robot::RobotInit()
{

  controller = new Controller();
  controllerBox = new ControllerBox(controller->lift);
  camera = new CameraUSB();
  led = new BlinkinLED();
  camera->RunScript(); //runs usbcam(s)
  delta = new team::DeltaTime();
  controller->lift->targetPosition = Positions::manual;
  //controller->lift->targetPosition = Positions::start;
}

void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {
  //controller->lift->targetPosition = Positions::start;
}

void Robot::AutonomousPeriodic() {
  controller->ControllerPeriodic(delta->GetElapsed());
  controllerBox->ControllerPeriodic();
}

void Robot::TeleopInit()
{
  led->RunScriptBlue();
  //controller->lift->targetPosition = Positions::start;
}

void Robot::TeleopPeriodic()
{
  delta->UpdateElapsed();
  controller->ControllerPeriodic(delta->GetElapsed());
  controllerBox->ControllerPeriodic();
  //std::cout << "Elapsed Time: " << delta->GetElapsed() << std::endl;
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main()
{
  return frc::StartRobot<Robot>();
}
#endif

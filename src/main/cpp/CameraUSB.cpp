/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "CameraUSB.h"

CameraUSB::CameraUSB()
{
}
void CameraUSB::RunScript()
{                 
    cam1 = frc::CameraServer::GetInstance()->StartAutomaticCapture(0);
    cam1.SetResolution(640, 480);
    cam1.SetFPS(30);
}
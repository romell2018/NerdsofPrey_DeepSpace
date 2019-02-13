/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
// FOR PROGRAM TO WORK CTRE-Phoenix LIBRARY MUST BE DOWNLOADED
#include <ctre/Phoenix.h> // Library for motor controller
#include <iostream>

class Winch
{
public:
  Winch();
  void WinchUp();
  void WinchDown();
  void WinchOff();
  
  // Manipulator Motors
  TalonSRX *winchL;
  TalonSRX *winchR;
};

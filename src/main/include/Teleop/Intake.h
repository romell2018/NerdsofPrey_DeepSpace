/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
// FOR PROGRAM TO WORK CTRE-Phoenix LIBRARY MUST BE DOWNLOADED
#include <iostream>
#include <ctre/Phoenix.h> // Library for motor controller

class Intake
{
 public:
   Intake();
   void In();
   void Out();
   void Off();
   // Manipulator Motors
   TalonSRX *intake;
};

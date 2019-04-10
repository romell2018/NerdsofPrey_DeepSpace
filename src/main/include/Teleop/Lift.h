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
#include <frc/WPILib.h>
#include <memory>
#include <cmath>

#define MAX_DELTA 150
#define MAX_SLOW_DELTA 75
#define SLOW_ZONE 1000

namespace Positions
{
constexpr int manual = -2,
              assistedManual = -1,
              diskLow = 456,
              diskMid = 2660,
              diskHigh = 4100,
              ballLow = 1900,
              ballMid = 3570,
              ballHigh = 5800,
              floor = 300,
              start = 500;
}

class Lift
{
public:
  // Manipulator Motors
  TalonSRX *liftR;
  TalonSRX *liftL;

  int targetPosition = Positions::manual;
  int shapedTargetPosition = 0; //45.51111...  is one degree of rotation for the large gear

  float error;
  float sumError;
  float pastError;
  float deltaError;
  float kp = 0.0045; //0.00055; //,0045, 007
  float ki = 0;
  float kd = 0;
  //float maxSpeed = 100;

  Lift();

  void LiftUp();
  void LiftDown();
  void LiftOff();

  float LiftPosition();

  void ControlLift(int direction);
  void SetTarget(int target);

private:
  void UpdatePower(float power);
  void UpdatePID(float target);
};

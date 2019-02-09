/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <iostream>
#include <ctre/Phoenix.h>
#include <frc/WPILib.h>
#include <memory>
#include <cmath>

#define MAX_DELTA 50

namespace Positions
{
  constexpr int manual = -2,
  assistedManual = -1,
  diskLow = 235,
  diskMid = 2300,
  diskHigh = 4055,
  ballLow = 2220,
  ballMid = 3560,
  ballHigh = 5900,
  floor = 50;
};

class Lift
{
public:
  TalonSRX *liftR;
  TalonSRX *liftL;
  //frc::DigitalInput* limitSwitchBottom;
  //frc::DigitalInput* limitSwitchTop;

  int targetPosition = Positions::manual;
  int shapedTargetPosition = 0; //45.51111...  is one degree of rotation for the large gear

  float error;
  float sumError;
  float pastError;
  float deltaError;
  float kp;
  float ki;
  float kd;
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

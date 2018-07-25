/****************************************************************************
                                                Jose Jorge Jimenez-Olivas
                                                July 25, 2018

File Name:       L298N.cpp
Description:     Simple L298N dual H-bridge implementation to set the speed
                 and the direction of 2 dc motors.
Sources of Help: https://github.com/pololu/drv8835-motor-shield
****************************************************************************/
#include "L298N.h"

/***************************************************************************
% Routine Name : L298N
% File :         L298N.cpp
% Parameters:    arduino pin values for L298N male pin labled:
%                IN1, In2, IN3, IN4, ENA, ENB, respectively.
% Description :  L298N contructor - initializes arduino pin values.
%                Default motor speed is set to 0.
% IMPORTANT:     For arduino pin mapped to ENA, and ENB, make sure pins are
%                PWM compatible. (~) This is needed because ENA and ENB is
%                what is used for analog speed control for the dual dc motors
***************************************************************************/
L298N :: L298N( int IN1, int IN2, int IN3, int IN4, int ENA, int ENB ) : 
  _IN1( IN1 ), _IN2( IN2 ), _IN3( IN3 ), _IN4( IN4 ), _ENA( ENA ), _ENB( ENB ) {

  _M1Velocity = 0;
  _M2Velocity = 0;

  pinMode( IN1, OUTPUT );
  pinMode( IN2, OUTPUT );
  pinMode( IN3, OUTPUT );
  pinMode( IN4, OUTPUT );
  pinMode( ENA, OUTPUT );
  pinMode( ENB, OUTPUT );
}

/***************************************************************************
% Routine Name : setM1Velocity
% File :         L298N.cpp
% Parameters:    velocity - analog speed and direction 
% Description :  velocity > 0 -- motor rotates forwrd
%                velocity < 0 -- motor ratates in reverse
%                velocity = 0 -- motor is at rest
%                max velocity value -- (400)
%                min velocity value -- (-400)
%                Pins Used:  IN1, IN2, ENA
% Return:        Nothing
***************************************************************************/
void L298N :: setM1Velocity( int velocity ) {
  int speed; /* velocity magnitude */

  if( velocity < 0 ) {
    /* motors in reverse */
    speed = -velocity;
    digitalWrite( _IN1, LOW );
    digitalWrite( _IN2, HIGH );
  }
  else {
    /* motors moving forward */
    speed = velocity;
    digitalWrite( _IN1, HIGH );
    digitalWrite( _IN2, LOW );
  }

  if( speed > 400 ) {
    /* 400 MAX */
    velocity = (velocity / speed) * 400;
    speed = 400;
  }

  /* map speed to ( 0-255 ) */
  analogWrite( _ENA, speed * 255 / 400 ); 
  _M1Velocity = velocity;

}

/***************************************************************************
% Routine Name : setM2Velocity
% File :         L298N.cpp
% Parameters:    velocity - analog speed and direction
% Description :  velocity > 0 -- motor rotates forwrd
%                velocity < 0 -- motor ratates in reverse
%                velocity = 0 -- motor is at rest
%                max velocity value -- (400)
%                min velocity value -- (-400)
%                Pins Used:  IN3, IN4, ENB
% Return:        Nothing
***************************************************************************/
void L298N :: setM2Velocity( int velocity ) {
  int speed; /* velocity magnitude */

  if( velocity < 0 ) {
    /* motors in reverse */
    speed = -velocity;
    digitalWrite( _IN3, LOW );
    digitalWrite( _IN4, HIGH );
  }
  else {
    /* motors moving forward */
    speed = velocity;
    digitalWrite( _IN3, HIGH );
    digitalWrite( _IN4, LOW );
  }

  if( speed > 400 ) {
    /* 400 MAX */
    velocity = (velocity / speed) * 400;
    speed = 400;
  }

  /* map speed to ( 0-255 ) */
  analogWrite( _ENB, speed * 255 / 400 ); 
  _M2Velocity = velocity;

}

/***************************************************************************
% Routine Name : getM1Velocity
% File :         L298N.cpp
% Parameters:    None
% Description :  accessor methos for (-400 to 400) velocity value for motor 1
% Return:        Last set velocity for motor 1. Default - 0.
***************************************************************************/
int L298N :: getM1Velocity() {
  return _M1Velocity;
}

/***************************************************************************
% Routine Name : getM2Velocity 
% File :         L298N.cpp
% Parameters:    None
% Description :  accessor method for (-400 to 400) velocity value for motor 2
% Return:        Last set velocity for motor 2. Default - 0. 
***************************************************************************/
int L298N :: getM2Velocity() {
  return _M2Velocity;
}

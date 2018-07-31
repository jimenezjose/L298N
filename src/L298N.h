#ifndef L298N_H
#define L298N_H

#include <Arduino.h>

class L298N {

  public:
    L298N( int IN1, int IN2, int IN3, int IN4, int ENA, int ENB );

    /* MAX velocity = 400, MIN velocity = -400 */
    void setM1Velocity( int velocity );
    void setM2Velocity( int velocity );
    int getM1Velocity( void );
    int getM2Velocity( void );

  private:
    const unsigned char _IN1;
    const unsigned char _IN2;
    const unsigned char _IN3;
    const unsigned char _IN4;
    const unsigned char _ENA; /* must be PWM pin */
    const unsigned char _ENB; /* must be PWM pin */
    int _M1Velocity;
    int _M2Velocity;

};

#endif

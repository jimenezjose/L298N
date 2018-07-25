#include <L298N.h>

/*
 * This exapmle uses the L298N library to drive two DC motors forwards then 
 * backwards, one motor at a time. PWM pins are needed for ENA and ENB to 
 * control the speed of of the motors.
 * An led will be used to signify a change in direction of the motors.
 *
 * NOTE: if a motor goes in reverse instead of forward, switch the dc motor pins
 */

#define LED_PIN 13

#define IN1 7
#define IN2 6
#define IN3 5
#define IN4 4
#define ENA 11
#define ENB 10

L298N motor( IN1, IN2, IN3, IN4, ENA, ENB );

void setup() {
  pinMode( LED_PIN, OUTPUT );
}

void loop() {

  digitalWrite( LED_PIN, HIGH );

  for( int velocity = 0; velocity < 400; velocity++ ) {
    /* motor 1 moving forward */
    motor.setM1Velocity( velocity );
    delay( 2 );
  }
  
  for( int velocity = 400; velocity >= 0; velocity-- ) {
    /* motor 1 moving forward in decresing speed */
    motor.setM1Velocity( velocity );
  }

  digitalWrite( LED_PIN, LOW );

  for( int velocity = 0; speed > -400; speed++ ) {
    /* motor 1 moving in reverse NOTE NEGATIVE */
    motor.setM1Velocity( - speed );
    delay( 2 );
  }

  for( int velocity = -400; velocity <= 0; speed++ ) {
    /* motor 1 moving in reverse decreasing in speed */
    motor.setM1Velocity( velocity );
    delay( 2 )
  }


}

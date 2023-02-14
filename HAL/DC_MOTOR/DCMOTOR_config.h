/********************************************************************************/
/********************************************************************************/
/*****************       Aathur:Team Member                  ********************/
/*****************       Layer:HAL                           ********************/
/*****************       SWC:DC MOTOR                        ********************/
/*****************       version:1.00                        ********************/
/********************************************************************************/
/********************************************************************************/

#ifndef DCMOTOR_CONFIG_H_
#define DCMOTOR_CONFIG_H_

#define LEFT_CHANNEL  MOTOR_CHANNELA
#define RIGHT_CHANNEL MOTOR_CHANNELB

#define RIGHT_MOTOR_PORT  DIO_PORTG
#define RIGHT_MOTOR_PIN1  DIO_PIN0
#define RIGHT_MOTOR_PIN2  DIO_PIN1

#define LEFT_MOTOR_PORT  DIO_PORTG
#define LEFT_MOTOR_PIN1  DIO_PIN2
#define LEFT_MOTOR_PIN2  DIO_PIN3


#define  Max_COMPARE_MATCH  20000
#define  Min_COMPARE_MATCH  0






#endif /* DCMOTOR_CONFIG_H_ */

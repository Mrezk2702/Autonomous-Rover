/********************************************************************************/
/********************************************************************************/
/*****************       Aathur:Team Member                  ********************/
/*****************       Layer:HAL                           ********************/
/*****************       SWC:DC MOTOR                        ********************/
/*****************       version:1.00                        ********************/
/********************************************************************************/
/********************************************************************************/

#ifndef DCMOTOR_INTERFACE_H_
#define DCMOTOR_INTERFACE_H_

#define LEFT 0
#define RIGHT 1


#define CLOCKWISE               0
#define COUNTERCLOCKWISE        1

u8 DCMOTOR_Dirction(u8 Copy_MotorDirecton,u8 Copy_DCMotor);
u8 DCMOTOR_ON(u8 Copy_DCMOTOR);
u8 DCMOTOR_OFF(u8 Copy_DCMOTOR);
u8 DCMOTOR_SpeedControl(u16 Copy_Speed,u8 Copy_DCMOTOR);


#endif /* DCMOTOR_INTERFACE_H_ */

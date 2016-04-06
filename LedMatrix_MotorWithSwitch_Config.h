/*
 * LedMatrix_MotorWithSwitch_Config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */

#ifndef LEDMATRIX_MOTORWITHSWITCH_CONFIG_H_
#define LEDMATRIX_MOTORWITHSWITCH_CONFIG_H_

/*Comment!: Motor Pins & Swich Pin */
/*Range!  :DIO_u8DIO_u8Pin0 ~ DIO_u8DIO_u8Pin31 */
/*************************************************************/
#define LedMatrix_Motor_u8FirstMotorPin  DIO_u8Pin9
#define LedMatrix_Motor_u8SecondMotorPin DIO_u8Pin8
#define LedMatrix_Motor_u8SwichPin 		 DIO_u8Pin10

/*Comment!: sw ==DIO_u8LOW or sw==DIO_u8HIGH */
/*************************************************************/
#define LedMatrix_Motor_u8SwPressed	    DIO_u8HIGH
#define LedMatrix_Motor_u8SwReleased	DIO_u8LOW

#endif /* LEDMATRIX_MOTORWITHSWITCH_CONFIG_H_ */

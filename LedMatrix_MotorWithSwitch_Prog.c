/*
 * LedMatrix_MotorWithSwitch_Prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */
#include "Types.h"
#include "DIO_Private.h"
#include "DIO_config.h"
#include "DIO_interface.h"
#include "delay.h"
#include "ShiftRegisterLeds_Config.h"
#include "ShiftRegisterLeds_Interface.h"
#include "Debouncing_Interface.h"
#include "LedMatrix_MotorWithSwitch_Config.h"
#include "LedMatrix_MotorWithSwitch_Private.h"
#include "LedMatrix_MotorWithSwitch_Interface.h"


int main(void)
{
	u8 LedMatrix_Motor_u8SwVal,LedMatrix_Motor_u8CurrentMode,LedMatrix_Motor_u8Flag=0;
	DIO_VoidInit();

	while(1)
	{
		LedMatrix_Motor_VoidMotorStop();
		ShiftRegister_VoidTurnOff();
		LedMatrix_Motor_u8CurrentMode=LedMatrix_Motor_u8Nothing;

		DIO_u8ReadPinVal(LedMatrix_Motor_u8SwichPin,&LedMatrix_Motor_u8SwVal );
		if(u8_DebounceSenceHigh(LedMatrix_Motor_u8SwVal,LedMatrix_Motor_u8SwPressed) == LedMatrix_Motor_u8SwPressed)
		{
			LedMatrix_Motor_VoidMotorRight();
			{//lw user das 3la SW w das dosh lmodh a2l mn 3s y5ly current mode = on Contious mode
			 s16 LedMatrix_Motor_u8Count;
				for(LedMatrix_Motor_u8Count=((LedMatrix_Motor_u8Delay3s)/8);LedMatrix_Motor_u8Count>0;LedMatrix_Motor_u8Count--)
				{
					__asm__("NOP");
					LedMatrixAndshiftregister_VoidCharR();
					DIO_u8ReadPinVal(LedMatrix_Motor_u8SwichPin,&LedMatrix_Motor_u8SwVal );
					//lw shlt soba3k mn SW fy a2l mn 3s y5rg
					if(LedMatrix_Motor_u8Count==3)//lw 5ls 3s
					{
						LedMatrix_Motor_u8CurrentMode=LedMatrix_Motor_u8OnClick;
					}
					else;
					if(u8_DebounceSenceHigh(LedMatrix_Motor_u8SwVal,LedMatrix_Motor_u8SwReleased)==LedMatrix_Motor_u8SwReleased)
					{
						LedMatrixAndshiftregister_VoidCharR();
						LedMatrix_Motor_u8CurrentMode=LedMatrix_Motor_u8Contious;
						LedMatrix_Motor_u8Count=0;//hishof el for w y5rg
						//break;
					}
					else;
				}
			}
		}
		else
		{
			//Delay_ms_Max1s(1000);
		}
		switch(LedMatrix_Motor_u8CurrentMode)
		{
			case LedMatrix_Motor_u8Contious:
			do
			{
				LedMatrixAndshiftregister_VoidCharR();
				DIO_u8ReadPinVal(LedMatrix_Motor_u8SwichPin,&LedMatrix_Motor_u8SwVal );
				if(u8_DebounceSenceHigh(LedMatrix_Motor_u8SwVal,LedMatrix_Motor_u8SwPressed)==LedMatrix_Motor_u8SwPressed)
				{
					ShiftRegister_VoidTurnOff();
					LedMatrix_Motor_VoidMotorStop();
					LedMatrix_Motor_u8CurrentMode=LedMatrix_Motor_u8Nothing;
				}
			}while(LedMatrix_Motor_u8CurrentMode==LedMatrix_Motor_u8Contious);//y5rg ama ados 3la sw w mode = nothing
			Delay_ms_Max1s(500);
			break;

			case LedMatrix_Motor_u8OnClick:
			do
			{
				DIO_u8ReadPinVal(LedMatrix_Motor_u8SwichPin,&LedMatrix_Motor_u8SwVal );
				if(LedMatrix_Motor_u8Flag==0&&u8_DebounceSenceHigh(LedMatrix_Motor_u8SwVal,LedMatrix_Motor_u8SwReleased)==LedMatrix_Motor_u8SwReleased)
				{
					ShiftRegister_VoidTurnOff();
					LedMatrix_Motor_VoidMotorStop();
					LedMatrix_Motor_u8Flag++;
				}
				else if(LedMatrix_Motor_u8Flag==0)
				{
					LedMatrixAndshiftregister_VoidCharR();
				}
				///*
				else if(LedMatrix_Motor_u8Flag==1&&u8_DebounceSenceHigh(LedMatrix_Motor_u8SwVal,LedMatrix_Motor_u8SwPressed)==LedMatrix_Motor_u8SwPressed)
				{
					LedMatrix_Motor_VoidMotorLeft();
					LedMatrix_Motor_u8Flag++;
					Delay_ms_Max1s(500);
				}
				else if(LedMatrix_Motor_u8Flag==2&&(u8_DebounceSenceHigh(LedMatrix_Motor_u8SwVal,LedMatrix_Motor_u8SwPressed)==LedMatrix_Motor_u8SwPressed))
				{
					PORTC=LedMatrix_Motor_u8Flag;
					ShiftRegister_VoidTurnOff();
					LedMatrix_Motor_VoidMotorStop();
					LedMatrix_Motor_u8CurrentMode=LedMatrix_Motor_u8Nothing;
					LedMatrix_Motor_u8Flag=0;
					PORTD=0XFF;

				}
				else if(LedMatrix_Motor_u8Flag==2)//
				{
					LedMatrixAndshiftregister_VoidCharL();
				}


				//*/

				//*/
			}while(LedMatrix_Motor_u8CurrentMode==LedMatrix_Motor_u8OnClick);//y5rg ama ados 3la sw w mode = nothing
			Delay_ms_Max1s(500);
			break;
		}
	}
	return 0;
}
/****************************************************************/
void LedMatrix_Motor_VoidMotorRight(void)
{
	DIO_u8WritePinVal(LedMatrix_Motor_u8FirstMotorPin,DIO_u8HIGH );
	DIO_u8WritePinVal(LedMatrix_Motor_u8SecondMotorPin,DIO_u8LOW );
}
/****************************************************************/
void LedMatrix_Motor_VoidMotorLeft(void)
{
	DIO_u8WritePinVal(LedMatrix_Motor_u8FirstMotorPin,DIO_u8LOW );
	DIO_u8WritePinVal(LedMatrix_Motor_u8SecondMotorPin,DIO_u8HIGH );
}
/****************************************************************/
void LedMatrix_Motor_VoidMotorStop(void)
{
	DIO_u8WritePinVal(LedMatrix_Motor_u8FirstMotorPin,DIO_u8LOW );
	DIO_u8WritePinVal(LedMatrix_Motor_u8SecondMotorPin,DIO_u8LOW );
}
/****************************************************************/
void LedMatrixAndshiftregister_VoidCharL(void)
{
	u8 Local_u8Count,Local_u8Val;
	u8 const LMS_u8CharacterL[8]={0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x3f};

	for(Local_u8Count=0;Local_u8Count<8;Local_u8Count++)
	{
			shift_int(DIO_u8Clear_Port, SRL_u8Port);
			//Delay_ms_Max1s(1000);
			shift_int(LMS_u8CharacterL[Local_u8Count],SRL_u8Port);
			Local_u8Val=~(1<<Local_u8Count);
			shift_int(Local_u8Val,SRL_u8Port);

	}
}
/****************************************************************/

void LedMatrixAndshiftregister_VoidCharR(void)
{
	u8 Local_u8Count,Local_u8Val;
	u8 const LMS_u8CharacterR[8]={0xfc,0xc6,0xc2,0xfe,0xf0,0xd8,0xce,0xc6};
	//u8 const LMS_u8CharacterRL[3][8]={{0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x3f}
	///*u8 const LMS_u8CharacterR[8]=*/,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
	//								 ,{0xfc,0xc6,0xc2,0xfe,0xf0,0xd8,0xce,0xc6}};

	for(Local_u8Count=0;Local_u8Count<8;Local_u8Count++)
	{
			shift_int(DIO_u8Clear_Port, SRL_u8Port);
			//Delay_ms_Max1s(1000);
			//shift_int(LMS_u8CharacterRL[(ppp/50)%3][Local_u8Count],SRL_u8Port);
			shift_int(LMS_u8CharacterR[Local_u8Count],SRL_u8Port);
			Local_u8Val=~(1<<Local_u8Count);
			shift_int(Local_u8Val,SRL_u8Port);
    }
}
/****************************************************************/


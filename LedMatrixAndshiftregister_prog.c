/*
 * LedMatrixAndshiftregister_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */

#include "Types.h"
#include "DIO_Private.h"
#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO-utilites.h"
#include "delay.h"
#include "ShiftRegisterLeds_Config.h"
#include "ShiftRegisterLeds_Interface.h"
#include "DIO-utilites.h"


#define	RAWS	DIO_u8Port0
#define	COLUMNS	DIO_u8Port2

//u8 const LMS_u8CharacterRL[2][8]={{0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x3f}
/*u8 const LMS_u8CharacterR[8]=*///,{0xfc,0xc6,0xc2,0xfe,0xf0,0xd8,0xce,0xc6}};


//int main (void)
//{
//	u8 i,val,j=0;

//	DIO_u8WritePortDir(RAWS,DIO_u8OUTPUT_Port);
	//DIO_u8WritePortDir(COLUMNS,DIO_u8OUTPUT_Port);

	//Coulmn ==active high
	//Row	 ==active low
//	while (1)
//	{
//		*/
		/*
		//for(;j<2;j++)
		{
			for(i=0;i<8;i++)
			{
				shift_int(DIO_u8Clear_Port, SRL_u8Port);
				shift_int(LMS_u8CharacterRL[(j/100)%2][i],SRL_u8Port);
				val=~(1<<i);
				shift_int(val,SRL_u8Port);
			}
			j++;
			*/
			//Delay_ms_Max1s(1000);
//		}
       //*/
		//for(j=0;j<2;j++)
//		{
			/*
			for(i=0;i<8;i++)
			{
				shift_int(DIO_u8Clear_Port, SRL_u8Port);
				//Delay_ms_Max1s(1000);
				shift_int(LMS_u8CharacterL[i],SRL_u8Port);
				//Delay_ms_Max1s(1000);
				val=~(1<<i);
				shift_int(val,SRL_u8Port);
				//Delay_ms_Max1s(1);
			}

		*/
//		}
		//shift_int(DIO_u8Clear_Port, SRL_u8Port);
		//Delay_ms_Max1s(1000);
/*
	}
return 0;
}
*/

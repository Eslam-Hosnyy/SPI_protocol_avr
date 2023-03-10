/************************************/
/*	Author	  :	ESLAM_HOSNY			*/
/*	SWC		  : MSPI				*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	December 1, 2022	*/
/*	Last Edit : N/A					*/
/************************************/

#ifndef _MSPI_INTERFACE_
#define _MSPI_INTERFACE_

#define MSPI_MODE_MASTER	1
#define MSPI_MODE_SLAVE		0

#define MSPI_CLOCK_POLPHA_NONINVERTING_LEADING		0
#define MSPI_CLOCK_POLPHA_NONINVERTING_TRAINING		1
#define MSPI_CLOCK_POLPHA_INVERTING_LEADING			2
#define MSPI_CLOCK_POLPHA_INVERTING_TRAINING		3

#define MSPI_PRESCALER_4	0
#define MSPI_PRESCALER_16	1
#define MSPI_PRESCALER_64	2
#define MSPI_PRESCALER_128	3
#define MSPI_PRESCALER_2	4
#define MSPI_PRESCALER_8	5
#define MSPI_PRESCALER_32	6

#define MSPI_DATAORDER_LSB	1
#define MSPI_DATAORDER_MSB	0


void MSPI_voidINT(u8 ARG_u8MS_Mode, u8 ARG_u8ClockPolPha, u8 ARG_u8Prescaler, u8 ARG_u8DataOrder);

void MSPI_voidEnable(void);

void MSPI_voidDisable(void);

void MSPI_voidEnableInterrupt(void);

void MSPI_voidDisableInterrupt(void);

void MSPI_voidSetCallBack(void (*ARD_voidUserFunction)(void));

char MSPI_charTransCeive(char ARG_charSentData);

/*void MSPI_voidFlagPolling(void);

char MSPI_charSlaveReceive(u8 ARG_charData);*/


#endif

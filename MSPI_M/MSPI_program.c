/************************************/
/*	Author	  :	ESLAM_HOSNY			*/
/*	SWC		  : MSPI				*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	December 1, 2022	*/
/*	Last Edit : N/A					*/
/************************************/
#include "LSTD_types.h"
#include "LBIT_math.h"
#include "MSPI_private.h"
#include "MSPI_interface.h"

void(*MSPI_pvoidfuserFunction)(void) = NULL;

void MSPI_voidINT(u8 ARG_u8MS_Mode, u8 ARG_u8ClockPolPha, u8 ARG_u8Prescaler, u8 ARG_u8DataOrder)
{
	/* Clear The SPCR Regisier And Keep The Value Of (SPI Enable & SPI Interrupt Enable) */
	SPCR &= 0b11000000;
	/* Set The Initial Values of The SPI Protocol */
	SPCR |= ((ARG_u8DataOrder << 5) | (ARG_u8MS_Mode << 4) | (ARG_u8ClockPolPha << 2) | (ARG_u8Prescaler & 0b00000011) );
	/* Clear The Third Bit Of The ClockPolPha(SPI2X) in SPSR Rigister (Keep The Other Bits Values ) */
	SPSR &= 0b11111110;
	/* SET The LSB OF The SPSR_Register (SPI2X) */
	SPSR |= ((ARG_u8Prescaler >>2) &1);
}

void MSPI_voidEnable(void)
{
	/* SET The SPI Enable BIT In SPCR_Register */
	SET_BIT(SPCR,SPCR_SPE);
}

void MSPI_voidDisable(void)
{
	/* CLEAR The SPI Enable BIT In SPCR_Register */
	CLEAR_BIT(SPCR,SPCR_SPE);
}

void MSPI_voidEnableInterrupt(void)
{
	/* SET The SPI INTERRUPT Enable BIT In SPCR_Register */
	SET_BIT(SPCR,SPCR_SPIE);
}

void MSPI_voidDisableInterrupt(void)
{
	/* CLEAR The SPI INTERRUPT Enable BIT In SPCR_Register */
	CLEAR_BIT(SPCR,SPCR_SPIE);

}

void MSPI_voidSetCallBack(void (*ARD_voidUserFunction)(void))
{
	/* Passsing The User Function */
	 MSPI_pvoidfuserFunction = ARD_voidUserFunction;
}

/*void MSPI_voidFlagPolling(void)
{
	while((!GET_BIT(SPSR, SPSR_SPIF)));
}

char MSPI_charSlaveReceive(u8 ARG_charData)
{
	char L_SlaveData;
	MSPI_voidFlagPolling();
	L_SlaveData = SPDR;
	SPDR =ARG_charData;
	return L_SlaveData;
}*/

char MSPI_charTransCeive(char ARG_charSentData)
{
	SPDR = ARG_charSentData;
	while((!GET_BIT(SPSR, SPSR_SPIF)));
	return SPDR;
}

void __vector_12(void) __attribute__((signal));
void __vector_12(void)
{
	(*MSPI_pvoidfuserFunction)();
}

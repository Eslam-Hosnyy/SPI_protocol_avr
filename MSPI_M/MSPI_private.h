/************************************/
/*	Author	  :	ESLAM_HOSNY			*/
/*	SWC		  : MSPIs				*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	December 1, 2022	*/
/*	Last Edit : N/A					*/
/************************************/

#ifndef _MSPI_PRIVATE_
#define _MSPI_PRIVATE_

#define SPDR		*((volatile u8*)0x2F)

#define SPSR		*((volatile u8*)0x2E)
#define SPSR_SPIF	7
#define SPSR_WCOL	6
#define SPSR_SPI2X	0

#define SPCR		*((volatile u8*)0x2D)
#define SPCR_SPIE	7
#define SPCR_SPE	6
#define SPCR_DORD	5
#define SPCR_MUSTR	4
#define SPCR_CPOL	3
#define SPCR_CPHA	2
#define SPCR_SPR1	1
#define SPCR_SPR0	0


#endif

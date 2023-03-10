/************************************/
/*	Author		: Eslam_Hosny		*/
/*	SWC			: N/A				*/
/*	Layer		: N/A				*/
/*	Version   	: 0.0				*/
/*	Date	  	: N/A				*/
/*	Last Edit 	: N/A				*/
/************************************/
#define F_CPU		8000000UL
#include <util/delay.h>
#include "LSTD_types.h"
#include "LBIT_math.h"
#include "MDIO_interface.h"
#include "PORT_interface.h"
#include "MSPI_interface.h"

int main (void)
{
	PORT_voidInit();

	MSPI_voidINT(MSPI_MODE_MASTER, MSPI_CLOCK_POLPHA_NONINVERTING_LEADING, MSPI_PRESCALER_16, MSPI_DATAORDER_LSB);
	MSPI_voidEnable();

	while(1)
	{

		MSPI_charTransCeive(1);
		_delay_ms(100);
		MSPI_charTransCeive(2);
		_delay_ms(100);



	}

	return 0;
}

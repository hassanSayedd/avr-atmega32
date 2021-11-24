/*
 * Dio_prog.c
 *
 *  Created on: Aug 17, 2019
 *      Author: express
 */


#include "Std_types.h"
#include "Bit_math.h"
#include "INTR_int.h"
#include "INTR_priv.h"
#include "INTR_cfg.h"

void INTR_vidInit(u8 intr_type)
{
	SET_BIT(SREG,7);   //to enable GIE
	if(intr_type == INTR_u8INT_0)
	{
		CLEAR_BIT(DDRD,2);   //to make int0 pin input
		SET_BIT(PORTD,2);   //to make int0 pin pull up
		SET_BIT(GICR,6);   //to enable PIE

		/*****sense control selection*********/
		#if INTR_u8Int0SenseCont == INTR_u8LowLevel_0
				CLEAR_BIT(MCUCR,0);
				CLEAR_BIT(MCUCR,1);

		#elif INTR_u8Int0SenseCont == INTR_u8AnyLogicalChange_0
				SET_BIT(MCUCR,0);
				CLEAR_BIT(MCUCR,1);

		#elif INTR_u8Int0SenseCont == INTR_u8FallingEdge_0
				CLEAR_BIT(MCUCR,0);
				SET_BIT(MCUCR,1);

		#elif INTR_u8Int0SenseCont == INTR_u8RisingEdge_0
				SET_BIT(MCUCR,0);
				SET_BIT(MCUCR,1);

		#endif

	}
	else if(intr_type == INTR_u8INT_1)
	{
		CLEAR_BIT(DDRD,3);  //to make int1 pin input
		SET_BIT(PORTD,3);  //to make int1 pin pull up
		SET_BIT(GICR,7); //to enable PIE
		/*****sense control selection*********/
		#if INTR_u8Int1SenseCont == INTR_u8LowLevel_1
				CLEAR_BIT(MCUCR,2);
				CLEAR_BIT(MCUCR,3);

		#elif INTR_u8Int1SenseCont == INTR_u8AnyLogicalChange_1
				SET_BIT(MCUCR,2);
				CLEAR_BIT(MCUCR,3);

		#elif INTR_u8Int1SenseCont == INTR_u8FallingEdge_1
				CLEAR_BIT(MCUCR,2);
				SET_BIT(MCUCR,3);

		#elif INTR_u8Int1SenseCont == INTR_u8RisingEdge_1
				SET_BIT(MCUCR,2);
				SET_BIT(MCUCR,3);

		#endif

	}
	else if(intr_type == INTR_u8INT_2)
	{
		CLEAR_BIT(DDRB,2);  //to make int2 pin input
		SET_BIT(PORTB,2);  //to make int2 pin pull up
		SET_BIT(GICR,5);  //to enable PIE

		/*****sense control selection*********/

		#if INTR_u8Int2SenseCont == INTR_u8FallingEdge_2
				CLEAR_BIT(MCUCSR,6);

		#elif INTR_u8Int2SenseCont == INTR_u8RisingEdge_2
				SET_BIT(MCUCSR,6);

		#endif

	}
}

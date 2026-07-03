/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< LED_interface.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Created on: Jul 3, 2026
 *  Author: Ali Osama Ismail
 *  Layer : HAL
 *  SWC   : SSD
 *
 *
 */

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_
#include "../../03_LIB/STD_TYPES.h"
#include "../../03_LIB/BIT_MATH.h"
#include "../../01_MCAL/01_DIO/DIO_interface.h"

typedef enum{
	SSD_COM_CATHODE,
	SSD_COM_ANODE
}SSD_Type;

typedef enum {
	SSD_NOK,
	SSD_OK,
	SSD_NULL_POINTER,
	SSD_INVALID_TYPE,
	SSD_INVALID_NUMBER
}SSD_ErrorStatus;

typedef struct{
	SSD_Type Type;
	DIO_PORT_t DataPort;
	DIO_PORT_t EnablePort;
	DIO_PIN_t EnablePin;
}SSD_t;


SSD_ErrorStatus SSD_enumInit      (const SSD_t* Copy_structSSD);
SSD_ErrorStatus SSD_enumOn        (const SSD_t* Copy_structSSD);
SSD_ErrorStatus SSD_enumOff       (const SSD_t* Copy_structSSD);
SSD_ErrorStatus SSD_enumDisplayNum(const SSD_t* Copy_structSSD,u8 Copy_u8Number);




#endif /* SSD_INTERFACE_H_ */

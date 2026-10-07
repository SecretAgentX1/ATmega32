/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< KPD_interface.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Created on: Oct 7, 2026
 *  Author: Ali Osama Ismail
 *  Layer : HAL
 *  SWC   : KPD
 *
 *
 */

#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_
#include "STD_TYPES.h"

#define NOTPRESSED 0xFF

void KPD_voidInit();
u8 KPD_u8GetPressed();


#endif /* KPD_INTERFACE_H_ */

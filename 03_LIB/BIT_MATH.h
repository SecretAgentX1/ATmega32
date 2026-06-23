/*
 * BIT_MATH.h
 *
 *  Created on: Jun 20, 2026
 *      Author: aliay
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg,bit) ((reg)|=(1U<<(bit)))
#define CLR_BIT(reg,bit) ((reg)&=(~(1U<<(bit))))
#define TOG_BIT(reg,bit) ((reg)^=(1U<<(bit)))
#define GET_BIT(reg,bit) (((reg)&(1U<<(bit)))>>(bit))

#endif /* BIT_MATH_H_ */

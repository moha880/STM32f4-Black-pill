/*
 * RCC_cfg.h
 *
 *  Created on: Aug 16, 2022
 *      Author: mazen
 */

#ifndef MCAL_RCC_RCC_CFG_H_
#define MCAL_RCC_RCC_CFG_H_

#define RCC_HSE_ENABLE		ENABLE
#define RCC_HSI_ENABLE		ENABLE
#define RCC_PLL_ENABLE		ENABLE



#define RCC_CSS_ENABLE		ENABLE

#define	RCC_HSE				1
#define	RCC_HSI				2
#define	RCC_PLL				3


#define	RCC_HSE_CLK_MHZ		25000000
#define	RCC_HSI_CLK_MHZ		16000000


#define RCC_SYS_CLK			RCC_HSI

#define SYSTEM_CLK			RCC_HSI_CLK_MHZ


#endif /* MCAL_RCC_RCC_CFG_H_ */

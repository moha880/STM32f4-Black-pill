/*
 * LEDMTX_cfg.h
 *
 *  Created on: Sep 29, 2022
 *      Author: Ibrahem
 */

#ifndef HAL_LEDMTX_LEDMTX_CFG_H_
#define HAL_LEDMTX_LEDMTX_CFG_H_

#define NO_COLS		8
#define NO_ROWS		8

#define SCAN_TIME		2500   //[# Timer Ticks ]example
#define METHOD			LEDMTX_S2P   //   LEDMTX_S2P/LEDMTX_DIRECT

extern 	MGPIO_Config_t rows[NO_ROWS];
extern 	MGPIO_Config_t cols[NO_COLS];


#endif /* HAL_LEDMTX_LEDMTX_CFG_H_ */

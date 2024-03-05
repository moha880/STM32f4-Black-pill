

#include"LIB/BIT_MATH.h"
#include"LIB/STD_TYPES.h"

#include"MCAL/GPIO/GPIO_int.h"
#include"MCAL/SPI/SPI_prv.h"
#include"MCAL/SPI/SPI_int.h"
#include"MCAL/SPI/SPI_cfg.h"
#include"HAL/TFT/TFT_int.h"
#include "MCAL/RCC/RCC_cfg.h"

#include "MCAL/RCC/RCC_int.h"
#include "MCAL/STK/STK_int.h"
#include"tft_test.h"


int main(void)
{

	TFT_vInit();
//	MRCC_vInit();
//	MSTK_vInit();
//
//	MRCC_vEnableClock(RCC_AHB1, RCC_EN_GPIOA);
//



	MGPIO_Config_t ledpin = {
			.Port=GPIO_PORTA, .Pin=GPIO_PIN2, .Mode=GPIO_MODE_OUTPUT, .OutputSpeed=GPIO_SPEED_MED, .OutputType=GPIO_OTYPE_PUSHPULL,.InputPull=GPIO_INPUT_NO_PULL
	};
	MGPIO_Config_t ledpin3 = {
			.Port=GPIO_PORTA, .Pin=GPIO_PIN3, .Mode=GPIO_MODE_OUTPUT, .OutputSpeed=GPIO_SPEED_MED, .OutputType=GPIO_OTYPE_PUSHPULL,.InputPull=GPIO_INPUT_NO_PULL
	};

	MGPIO_vInit(&ledpin);
	MGPIO_vInit(&ledpin3);





//	MSTK_vSetBusyWait(25000000);





//	Color_t bg;
//
//	bg.pixel.Blu = 0b11111 ;
//	bg.pixel.Grn = 0 ;
//	bg.pixel.Red = 0 ;
//
//	Color_t  rect_color = {
//			.pixel.Blu = 0,
//			.pixel.Grn = 0b111111,
//			.pixel.Red = 0
//	};
//



//	MSPI_vInit(&SPIconfig);
//
//	MSTK_vInit();
//
//


/**
 *   0 0 0 0 0 0 0 0
 *   0 0 0 0 0 0 0 0
 *   0 0 0 0 0 0 0 0
 *   0 0 0 0 1 1 0 0
 *   0 0 0 0 0 1 0 0
 *   0 0 0 0 0 1 0 0
 *   0 0 0 0 0 0 0 0
 *   0 0 0 0 0 0 0 0
 */
//
//	TFT_vFillBackground(bg);
//
//
//	TFT_vSetXPos(20,20+30);
//	TFT_vSetYPos(20,20+60);
//
//	TFT_vFillRectangle(rect_color);
//
//
//
//	u16 c=0;
//	c  =   MSPI_u8Transmit__receive(&SPIconfig,0X11);



	TFT_vShowImage(car , sizeof (car) / sizeof (car [0]));


	while(1)
	{





		MGPIO_vSetPinVal(GPIO_PORTA, 3,0);
		MSTK_vSetDelayMiliSecounds(2000);


		MGPIO_vSetPinVal(GPIO_PORTA, 3,1);
		MSTK_vSetDelayMiliSecounds(2000);






	}
}

#include "LIB/STD_TYPES.h"
#include "MCAL/RCC/RCC_int.h"
#include "MCAL/GPIO/GPIO_int.h"
#include "HAL/SSD/SSD_int.h"




int main()
{
	MRCC_vInit();

	MRCC_vEnableClock(RCC_AHB1, RCC_EN_GPIOA);


  // At this stage the system clock should have already been configured
  // at high speed.

  // Infinite loop

//	MGPIO_Config_t led_pin_cfg[2]={{
//			.Port		 = GPIO_PORTB,
//			.Pin		 = GPIO_PIN9,
//			.Mode		 = GPIO_MODE_OUTPUT,
//			.OutputSpeed = GPIO_SPEED_LOW,
//			.OutputType  = GPIO_OTYPE_PUSHPULL,
//			.InputPull   = GPIO_INPUT_NO_PULL
//	},{
//			.Port		 = GPIO_PORTB,
//			.Pin		 = GPIO_PIN5,
//			.Mode		 = GPIO_MODE_OUTPUT,
//			.OutputSpeed = GPIO_SPEED_LOW,
//			.OutputType  = GPIO_OTYPE_PUSHPULL,
//			.InputPull   = GPIO_INPUT_NO_PULL
//	}};
//	MGPIO_vInit(&led_pin_cfg[0]);
//	MGPIO_vInit(&led_pin_cfg[1]);

	HSSD_vInit();
	HSSD_vDisplayNum(5);


 while (1)
    {
       // Add your code here.
    }
}


// ----------------------------------------------------------------------------

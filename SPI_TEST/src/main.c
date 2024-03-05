#include "LIB/STD_TYPES.h"
#include "MCAL/GPIO/GPIO_int.h"
#include "MCAL/RCC/RCC_int.h"



int main(void)
{
	MRCC_vInit();

	MRCC_vEnableClock(RCC_AHB1, RCC_EN_GPIOA);

	MGPIO_vSetPinMode(GPIO_PORTA, 0, GPIO_MODE_OUTPUT );
	MGPIO_vSetPinOutputSpeed(GPIO_PORTA, 0,GPIO_SPEED_LOW);
	MGPIO_vSetPinOutputType(GPIO_PORTA, 0, GPIO_OTYPE_PUSHPULL);
	MGPIO_vSetPinVal(GPIO_PORTA, 0,GPIO_HIGH);
//	MGPIO_Config_t led_pin_cfg={
//			.Port		 = GPIO_PORTA,
//			.Pin		 = GPIO_PIN0,
//			.Mode		 = GPIO_MODE_OUTPUT,
//			.OutputSpeed = GPIO_SPEED_LOW,
//			.OutputType  = GPIO_OTYPE_PUSHPULL,
//			.InputPull   = GPIO_INPUT_NO_PULL
//	};
//	MGPIO_vInit(&led_pin_cfg);

	while(1)
	{

	}
}

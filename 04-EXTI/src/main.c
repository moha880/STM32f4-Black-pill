
#include"LIB/STD_TYPES.h"
#include"MCAL/RCC/RCC_int.h"
#include"MCAL/GPIO/GPIO_int.h"
#include"MCAL/EXTI/EXTI_int.h"

void EXTI0_IRQHandler(void)
{

}

int main(void)
{
	MRCC_vInit();
	MRCC_vEnableClock(RCC_AHB1,RCC_EN_GPIOA);
	MRCC_vEnableClock(RCC_APB2,RCC_EN_SYSCFGEN);

	MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN1,GPIO_MODE_OUTPUT);
	MGPIO_vSetPinOutputSpeed(GPIO_PORTA,GPIO_PIN1,GPIO_SPEED_LOW);
	MGPIO_vSetPinOutputType(GPIO_PORTA,GPIO_PIN1,GPIO_OTYPE_PUSHPULL);

	MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN1,GPIO_MODE_INPUT);
	MGPIO_vSetPinInputPull(GPIO_PORTA,GPIO_PIN1,GPIO_INPUT_PULL_UP);


	MEXTI_vInit();
	MEXTI_vSoftwareTrigger(EXTI_LINE0);
	while(1)
    {

    }
}

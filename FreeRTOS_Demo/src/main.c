#include "LIB/STD_TYPES.h"
#include "MCAL/GPIO/GPIO_int.h"
#include "MCAL/RCC/RCC_int.h"


//MGPIO_Config_t pins[]={
//		{GPIO_PORTA,GPIO_PIN0,GPIO_MODE_OUTPUT,GPIO_SPEED_LOW,GPIO_OTYPE_PUSHPULL},
//		{GPIO_PORTA,GPIO_PIN1,GPIO_MODE_OUTPUT,GPIO_SPEED_LOW,GPIO_OTYPE_PUSHPULL},
//		{GPIO_PORTA,GPIO_PIN2,GPIO_MODE_OUTPUT,GPIO_SPEED_LOW,GPIO_OTYPE_PUSHPULL}
//
//};
//
//
//void Task1(void* pvParams)
//{
//	while(1){
//		MGPIO_vTogPinValue(pins[0].Port,pins[0].Pin);
//		vTaskDelay(500);
//	}
//}
//
//void Task2(void* pvParams)
//{
//	while(1){
//		MGPIO_vTogPinValue(pins[1].Port,pins[1].Pin);
//		vTaskDelay(250);
//	}
//}
//
//void Task3(void* pvParams)
//{
//	while(1){
//		MGPIO_vTogPinValue(pins[2].Port,pins[2].Pin);
//		vTaskDelay(1000);
//	}
//}
//


int main(void)
{
  // At this stage the sy stem clock should have already been configured
  // at high speed.

  // Infinite loop

	MRCC_vInit();

	MRCC_vEnableClock(RCC_AHB1, RCC_EN_GPIOA);

	MGPIO_vSetPinMode(GPIO_PORTA, 0, GPIO_MODE_OUTPUT );
	MGPIO_vSetPinOutputSpeed(GPIO_PORTA, 0,GPIO_SPEED_LOW);
	MGPIO_vSetPinOutputType(GPIO_PORTA, 0, GPIO_OTYPE_PUSHPULL);
	MGPIO_vSetPinVal(GPIO_PORTA, 0,GPIO_HIGH);

  while (1)
    {
       // Add your code here.
    }
}


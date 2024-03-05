
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/RCC/RCC_int.h"
#include "MCAL/STK/STK_int.h"
#include "MCAL/GPIO/GPIO_int.h"
#include "RTOS/RTOS_interface.h"
#include "HAL/SSD/SSD_int.h"

enum
{
	units, tens
};

volatile u8 SSD_num = 0 ;

void TASK_SSDmux(void)
{
	static u8 SSD_turn = units ;
	static u8 Units_val = 0 ;
	static u8 Tens_val  = 0 ;
	HSSD_vTurnOff();

	Units_val = SSD_num%10 ;
	Tens_val  = SSD_num/10 ;
	switch(SSD_turn)
	{
	case units:

		SSD_turn = tens ;
		MGPIO_vSetPinVal(GPIO_PORTA,GPIO_PIN5 ,1);
		MGPIO_vSetPinVal(GPIO_PORTA,GPIO_PIN0 ,0);
		HSSD_vDisplayNum(Units_val);


		break;

	case tens:
		SSD_turn = units ;
		MGPIO_vSetPinVal(GPIO_PORTA,GPIO_PIN0 ,1);
		MGPIO_vSetPinVal(GPIO_PORTA,GPIO_PIN5 ,0);
		HSSD_vDisplayNum(Tens_val);

		break;
	}
}


void TASK_SSDupdate(void)
{
	SSD_num = (SSD_num+1)%100 ;
}

u8 onORoff = 0;

void toggle(void){
	if(!onORoff){
		MGPIO_vSetPinVal(GPIO_PORTA, GPIO_PIN0, GPIO_HIGH);
		onORoff=1;
	}else{
		MGPIO_vSetPinVal(GPIO_PORTA, GPIO_PIN0, GPIO_LOW);
		onORoff=0;
	}

}


int main(void)
{
	MRCC_vInit();
	MRCC_vEnableClock(RCC_AHB1,RCC_EN_GPIOA);

	MSTK_vInit();
	HSSD_vInit();

	RTOS_u8CreateTask(TASK_SSDmux, 1, 0 , 1);
	RTOS_u8CreateTask(TASK_SSDupdate,134, 1 , 2);




	RTOS_voidStartOS() ;
	while(1)
	{
	}


}

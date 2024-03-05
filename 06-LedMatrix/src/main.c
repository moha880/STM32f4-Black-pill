#include"LIB/STD_TYPES.h"
#include"MCAL/RCC/RCC_int.h"

#include"HAL/LEDMTX/LEDMTX_int.h"

int main()
{
	MRCC_vInit();
	MRCC_vEnableClock(RCC_AHB1,RCC_EN_GPIOA);
	MRCC_vEnableClock(RCC_AHB1,RCC_EN_GPIOB);


	u8 Heart[]={28, 62, 126, 252, 252, 126, 62, 28};

	while (1)
    {
       // Add your code here.
		HLEDMTX_vDisplayFrame(Heart,1000);
    }
}

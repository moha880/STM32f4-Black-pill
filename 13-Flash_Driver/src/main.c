
#include"LIB/STD_TYPES.h"
#include"MCAL/RCC/RCC_int.h"
#include"MCAL/FMI/FMI_int.h"

int main()
{
	MRCC_vInit();
	MRCC_vEnableClock(RCC_AHB1,RCC_EN_FMI);

	u16 data[3]={0x30,0x31,0x32 };

	FMI_vFlashWrite(0x08008000,data,3);
	while (1)
    {
       // Add your code here.
    }
}


// ----------------------------------------------------------------------------

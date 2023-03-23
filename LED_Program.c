#include "../../Libraries/STD_Types.h"
#include "../../Libraries/bit_calc.h"
#include "../../MCAL/Port/Port_interface.h"
#include "../../MCAL/Dio/Dio_interface.h"
#include "../../MCAL/Intctrl/Intctrl_interface.h"
#include "../../MCAL/GpTimer/GpTimer_interface.h"
#include "LED_interface.h"

U32 ON,OFF;

void LED_Control(void){
static U8 state=0;

if(state==0){
Dio_WriteChannel(Dio_Channel_F1,Dio_Channel_HIGH);
state=1;
GpTimer0_init(ON);
}
else if(state==1){
Dio_WriteChannel(Dio_Channel_F1,Dio_Channel_LOW);
state=0;
GpTimer0_init(OFF);
}

}


void LED_ON_OFF(U32 ON_Time,U32 OFF_Time){
NVIC_init();
Port_init();
	
callback_Timer0(LED_Control);

ON=ON_Time;
OFF=OFF_Time;

GpTimer0_init(OFF);

}


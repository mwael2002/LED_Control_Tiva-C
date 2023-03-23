#include "../../Libraries/STD_Types.h"
#include "../../Libraries/bit_calc.h"
#include "../Mcu_Hw.h"
#include "GpTimer_private.h"
#include "GpTimer_config.h"
#include "GpTimer_interface.h"


void (*ptr_Timer0) (void);


void GpTimer0_init(U32 Overflow_Time_us){
	
//Enable Clock on Timer0 and wait until it's ready to be accessed
set_bit(SYSCTL_RCGCTIMER_R,0);
while(SYSCTL_PRTIMER_R==0);

//Ensure that the timer is disabled
clear_bit(TIMER0_CTL_R,0);

//Configure Timer0 to run on 32-bit mode	
TIMER0_CFG_R=0x00000000;

//Choose Timer0 mode one shot or periodic
#if TIMER0_TIMEOUTMODE==Periodic_Mode
set_bit(TIMER0_TAMR_R,1);
#elif TIMER0_TIMEOUTMODE==One_Shot_Mode
set_bit(TIMER0_TAMR_R,2);
#endif	
//Choose counting down
clear_bit(TIMER0_TAMR_R,4);

//Set the preload value
TIMER0_TAILR_R = (16*Overflow_Time_us)-1;
		
//Enable timeout interrupt
set_bit(TIMER0_IMR_R,0);
	
//Enable Timer0
set_bit(TIMER0_CTL_R,0);	
	
}



void callback_Timer0(void(*ptr)(void)){
if(ptr!=NULL){
   ptr_Timer0=ptr;
 }
}


 void TIMER0A_Handler(void){
 ptr_Timer0();
//Clear flag
set_bit(TIMER0_ICR_R,0);	 
 }
#ifndef GPTIMER_INTERFACE_H_
#define GPTIMER_INTERFACE_H_


/******************************************************************************
* \Syntax          : void GpTimer0_init(U32 Overflow_Time_ms)                             
* \Description     : Set the time at which the timer stop counting                              
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non-Reentrant        Over flow time is in micro second
                                          Maximum time is 268435455 microsecond
                                     
* \Parameters (in) : Over flow time                    
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void GpTimer0_init(U32 Overflow_Time_us);


//Callback function
void callback_Timer0(void(*ptr)(void));


#endif
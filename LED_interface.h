#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_


/******************************************************************************
* \Syntax          : void LED_ON_OFF(U32 ON_Time,U32 OFF_Time)                     
* \Description     : Initialize GPIO and interrupts , set the on & off
                     time periods  and call timer0 callbackfunction                               
					 
*                    Time is in micro second
*                     Maximum ON/OFF time is 268435455 microsecond                                                 
        
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non-Reentrant                                             
* \Parameters (in) : ONN_Time & OFF_Time             
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void LED_ON_OFF(U32 ON_Time,U32 OFF_Time);


/******************************************************************************
* \Syntax          : void LED_Control(void                   
* \Description     : Passed to timer0 callback function to control on
                     & off time periods when timer0 interrupt is fired                         
                                                    
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non-Reentrant                                             
* \Parameters (in) : None             
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void LED_Control(void);



#endif
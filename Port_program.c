#include "../../Libraries/STD_Types.h"
#include "../../Libraries/bit_calc.h"
#include "../Mcu_Hw.h"
#include "Port_config.h"
#include "Port_interface.h"

extern Port_ConfigType PortConfigArr[Port_Channel_MaxNum];
void Port_init(void){
    
	  Port_IdType Port_Id;
    Port_ChannelIdType Channel_Id;
    U8 channel_count;
	  volatile GPIO_Register* Port_Address;
    
	  U8 clock_count;
	
	for (channel_count = 0; channel_count<Port_No_Activated_Channels; channel_count++ ){
    	 if(channel_count>=38){ 
		      Port_Id = Port_Id_F;
     		 if(channel_count<=39){ 	 
				 Channel_Id = (channel_count%8)-6;
		     }
				 else{
				 Channel_Id=(channel_count%8)+2;
				 }
	    }				 
		
		
		else{
		    Port_Id = channel_count/ 8;
     		Channel_Id = channel_count % 8;
		}
		
		
        switch (Port_Id){
        case Port_Id_A:
            Port_Address = PORTA;
			set_bit(SYSCTL_RCGCGPIO_R,0);
		    while(get_bit(SYSCTL_PRGPIO_R,0)==0);
            break;
        case Port_Id_B:
            Port_Address = PORTB;
			set_bit(SYSCTL_RCGCGPIO_R,1);
		    while(get_bit(SYSCTL_PRGPIO_R,1)==0);
            break;
		case Port_Id_C:
            Port_Address = PORTC;
            set_bit(SYSCTL_RCGCGPIO_R,2);
		    while(get_bit(SYSCTL_PRGPIO_R,2)==0);
			break;
				 case Port_Id_D:
            Port_Address = PORTD;
            set_bit(SYSCTL_RCGCGPIO_R,3);
		    while(get_bit(SYSCTL_PRGPIO_R,3)==0);
			break;
		case Port_Id_E:
            Port_Address = PORTE;
            set_bit(SYSCTL_RCGCGPIO_R,4);
		    while(get_bit(SYSCTL_PRGPIO_R,4)==0);
			break;
        case Port_Id_F:
            Port_Address = PORTF;
            set_bit(SYSCTL_RCGCGPIO_R,5);
		    while(get_bit(SYSCTL_PRGPIO_R,5)==0);
			break;									 
        }
				
				if((PortConfigArr[channel_count].LockStatus == Port_ChannelUnlocked)&&(get_bit(SYSCTL_RCGCGPIO_R,Port_Id)==1)){ 
				
				Port_Address->GPIO_LOCK_R=0x4C4F434B;
				set_bit(Port_Address->GPIO_CR_R,Channel_Id);
				
				
				
          /* set channel direction */
        if(PortConfigArr[channel_count].Dir == Port_Dir_Output){
            set_bit(Port_Address->GPIO_DIR_R,Channel_Id);
        }
        else if(PortConfigArr[channel_count].Dir == Port_Dir_Input){
            clear_bit(Port_Address->GPIO_DIR_R , Channel_Id);
        }

				
        /* enable Dio */
        if(PortConfigArr[channel_count].Mode == PORT_MODE_PIN_X_DIO){
            clear_bit(Port_Address->GPIO_AFSEL_R ,Channel_Id);
					  set_bit(Port_Address->GPIO_DEN_R ,Channel_Id);
					  
        }
				
				
				/**enable another mode**/
        else{
            set_bit(Port_Address->GPIO_AFSEL_R , Channel_Id);
            Port_Address->GPIO_PCTL_R |= (PortConfigArr[channel_count].Mode << (Channel_Id*4) );
        }
				
				
				/**enable ADC**/
        if(PortConfigArr[channel_count].Mode == Port_Mode_AIN ){
            /* disable digital */
            clear_bit(Port_Address->GPIO_DEN_R,Channel_Id);
            /* enable ADC */
            set_bit(Port_Address->GPIO_ADCCTL_R,Channel_Id);
        }
        
				
				
				
				/* set Interrupt configuration */
        if(PortConfigArr[channel_count].Interrupt == Port_IntDisable){
            clear_bit(Port_Address->GPIO_IM_R,Channel_Id);
        }
				
				
        else{
					clear_bit(Port_Address->GPIO_IM_R,Channel_Id);
					
					
					if(PortConfigArr[channel_count].Interrupt == Port_IntFallingEdge){
						    clear_bit(Port_Address->GPIO_IS_R,Channel_Id);	  
                clear_bit(Port_Address->GPIO_IEV_R,Channel_Id);
            }
            else if(PortConfigArr[channel_count].Interrupt == Port_IntRisingEdge){
                 clear_bit(Port_Address->GPIO_IS_R,Channel_Id);	
							   set_bit(Port_Address->GPIO_IEV_R,Channel_Id);
            }
								
            else if(PortConfigArr[channel_count].Interrupt == Port_IntBothEdges){
                  clear_bit(Port_Address->GPIO_IS_R,Channel_Id);	
							    set_bit(Port_Address->GPIO_IBE_R,Channel_Id);
            }
						
						else if(PortConfigArr[channel_count].Interrupt==Port_IntLowLevel){
						  set_bit(Port_Address->GPIO_IS_R,Channel_Id);
							clear_bit(Port_Address->GPIO_IEV_R,Channel_Id);
						}
						else if(PortConfigArr[channel_count].Interrupt==Port_IntHighLevel){
							set_bit(Port_Address->GPIO_IS_R,Channel_Id);
							set_bit(Port_Address->GPIO_IEV_R,Channel_Id);
						}
						
						
						set_bit(Port_Address->GPIO_IM_R,Channel_Id);
        }

        
				
				
				/* set Internal Attachment configuration */
        if(PortConfigArr[channel_count].Attach == Port_InternalAttach_PullUp){
            set_bit(Port_Address->GPIO_PUR_R,Channel_Id);
        }
				else if(PortConfigArr[channel_count].Attach  == Port_InternalAttach_PullDown){
            set_bit(Port_Address->GPIO_PDR_R,Channel_Id);
        }
				else if(PortConfigArr[channel_count].Attach == Port_InternalAttach_OpenDrain){
            set_bit(Port_Address->GPIO_ODR_R,Channel_Id);
        }

        /*set current strength configuration */
        if(PortConfigArr[channel_count].CurrentDrive  == Port_CurrDrive_2mA){
            set_bit(Port_Address->GPIO_DR2R_R,Channel_Id);
        }
				else if(PortConfigArr[channel_count].CurrentDrive == Port_CurrDrive_4mA){
            set_bit(Port_Address->GPIO_DR4R_R,Channel_Id);
        }
				else if(PortConfigArr[channel_count].CurrentDrive == Port_CurrDrive_8mA){
            set_bit(Port_Address->GPIO_DR8R_R,Channel_Id);
        }

			}
			else if(PortConfigArr[channel_count].LockStatus == Port_ChannelLocked){
				set_bit(SYSCTL_RCGCGPIO_R,Port_Id);
				for(clock_count=0;clock_count<4;clock_count++);
				Port_Address->GPIO_LOCK_R=0x01;
				clear_bit(SYSCTL_RCGCGPIO_R,Port_Id);
			}
	  }
	
}
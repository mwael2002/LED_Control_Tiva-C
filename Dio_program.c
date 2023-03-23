#include "../../Libraries/STD_Types.h"
#include "../../Libraries/bit_calc.h"
#include "../Mcu_Hw.h"
#include "Dio_interface.h"

U32 offset_addresses[8]={0x04,0x08,0x10,0x20,0x40,0x80,0x100,0x200};

void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level){
Dio_PortType portid = ChannelId / 8;
Dio_ChannelType channel = ChannelId % 8;
volatile U32* Address_Data_Channel;
	
	switch(portid){
		case Dio_Port_A:
		Address_Data_Channel= GPIO_PORTA_DATA_BITS_R;	
		break;
		case Dio_Port_B:
		Address_Data_Channel= GPIO_PORTB_DATA_BITS_R;
		break;
		case Dio_Port_C:
		Address_Data_Channel= GPIO_PORTC_DATA_BITS_R;
		break;
		case Dio_Port_D:
		Address_Data_Channel= GPIO_PORTD_DATA_BITS_R;
		break;
		case Dio_Port_E:
        Address_Data_Channel= GPIO_PORTE_DATA_BITS_R;			
		break;
		case Dio_Port_F:
		Address_Data_Channel= GPIO_PORTF_DATA_BITS_R;
		break;
   }
	   //Writing on Channel using bit masking
	   Address_Data_Channel += offset_addresses[channel]/4;
		*Address_Data_Channel= (Level<<channel);	
}

void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level){
    switch(PortId){
			case Dio_Port_A:
				PORTA->GPIO_DATA_R=Level;
			break;
		  case Dio_Port_B:
				PORTB->GPIO_DATA_R=Level;
			break;
			case Dio_Port_C:
				PORTC->GPIO_DATA_R=Level;
			break;
			case Dio_Port_D:
				PORTD->GPIO_DATA_R=Level;
			break;
			case Dio_Port_E:
				PORTE->GPIO_DATA_R=Level;
			break;
			case Dio_Port_F:
				PORTF->GPIO_DATA_R=Level;
			break;
   }
}
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId){
	
Dio_PortType portid = ChannelId / 8;
Dio_ChannelType channel = ChannelId % 8;
volatile U32* Address_Data_Channel;
	
	switch(portid){
		case Dio_Port_A:
		Address_Data_Channel= GPIO_PORTA_DATA_BITS_R;		
		break;
		case Dio_Port_B:
		Address_Data_Channel= GPIO_PORTB_DATA_BITS_R;			
		break;
		case Dio_Port_C:
		Address_Data_Channel= GPIO_PORTC_DATA_BITS_R;			
		break;
		case Dio_Port_D:
		Address_Data_Channel= GPIO_PORTD_DATA_BITS_R;		
		break;
		case Dio_Port_E:
        Address_Data_Channel= GPIO_PORTE_DATA_BITS_R;			
		break;
		case Dio_Port_F:
		Address_Data_Channel= GPIO_PORTF_DATA_BITS_R;
		break;
   }
	//Reading channel using bit masking
	Address_Data_Channel += offset_addresses[channel]/4;
	return (*Address_Data_Channel>>channel); 
}

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId){
    switch(PortId){
			case Dio_Port_A:
				return(PORTA->GPIO_DATA_R);
		    case Dio_Port_B:
				return(PORTB->GPIO_DATA_R);
			case Dio_Port_C:
				return(PORTC->GPIO_DATA_R);
			case Dio_Port_D:
				return(PORTD->GPIO_DATA_R);
			case Dio_Port_E:
				return (PORTE->GPIO_DATA_R);
			case Dio_Port_F:
				return(PORTF->GPIO_DATA_R);
   }
return 256;
}



Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId){
Dio_PortType portid = ChannelId / 8;
Dio_ChannelType channel = ChannelId % 8;
volatile U32* Address_Data_Channel;
	
	switch(portid){
		case Dio_Port_A:
		Address_Data_Channel= GPIO_PORTA_DATA_BITS_R;	
		break;
		case Dio_Port_B:
		Address_Data_Channel= GPIO_PORTB_DATA_BITS_R;
		break;
		case Dio_Port_C:
		Address_Data_Channel= GPIO_PORTC_DATA_BITS_R;
		break;
		case Dio_Port_D:
		Address_Data_Channel= GPIO_PORTD_DATA_BITS_R;	
		break;
		case Dio_Port_E:
    Address_Data_Channel= GPIO_PORTE_DATA_BITS_R;			
		break;
		case Dio_Port_F:
		Address_Data_Channel= GPIO_PORTF_DATA_BITS_R;
		break;
   }
	   Address_Data_Channel += offset_addresses[channel]/4;
		toggle_bit(*Address_Data_Channel,channel);
    return (*Address_Data_Channel>>channel); 
}
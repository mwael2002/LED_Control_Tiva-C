#include "../../Libraries/STD_Types.h"
#include "Intctrl_private.h"
#include "Intctrl_interface.h"

Nvic_ConfigType Nvic_Config[78]={
	
    {NVIC_GPIO_PORT_A		     	,Int_Disable,0,0},
	{NVIC_GPIO_PORT_B     			,Int_Disable,0,0},
	{NVIC_GPIO_PORT_C     			,Int_Disable,0,0},
	{NVIC_GPIO_PORT_D     			,Int_Disable,0,0},
    {NVIC_GPIO_PORT_E               ,Int_Disable,0,0},
    {NVIC_UART_0         			,Int_Disable,0,0},
	{NVIC_UART_1         			,Int_Disable,0,0},
	{NVIC_SSI_0          			,Int_Disable,0,0},
    {NVIC_I2C_0          			,Int_Disable,0,0},
	{NVIC_PWM_0_FAULT    			,Int_Disable,0,0},
    {NVIC_PWM_0_GEN_0    			,Int_Disable,0,0},
    {NVIC_PWM_0_GEN_1    			,Int_Disable,0,0},
    {NVIC_PWM_0_GEN_2    			,Int_Disable,0,0},
	{NVIC_QEI_0          			,Int_Disable,0,0},
	{NVIC_ADC_0_SEQ_0    			,Int_Disable,0,0},
	{NVIC_ADC_0_SEQ_1    			,Int_Disable,0,0},
	{NVIC_ADC_0_SEQ_2    			,Int_Disable,0,0},
	{NVIC_ADC_0_SEQ_3    			,Int_Disable,0,0},
	{NVIC_TIMER_WATCHDOG_0_1    		,Int_Disable,0,0},
	{NVIC_16_32_TIMER_0_A      		,Int_Enable,0,0},
	{NVIC_16_32_TIMER_0_B      		,Int_Disable,0,0},
	{NVIC_16_32_TIMER_1_A      		,Int_Disable,0,0},
	{NVIC_16_32_TIMER_1_B      		,Int_Disable,0,0},
	{NVIC_16_32_TIMER_2_A      		,Int_Disable,0,0},
	{NVIC_16_32_TIMER_2_B      		,Int_Disable,0,0},
	{NVIC_ANALOG_COMPARATOR_0   		,Int_Disable,0,0},
	{NVIC_ANALOG_COMPARATOR_1   		,Int_Disable,0,0},
	{NVIC_SYSTEM_CONTROL   		,Int_Disable,0,0},
	{NVIC_FLASH_EEPROM_MEMORY_CONTROL,Int_Disable,0,0},
	{NVIC_DIO_PORT_F    			 	,Int_Enable,0,0},
	{NVIC_UART_2   				,Int_Disable,0,0},
	{NVIC_SSI_1         				,Int_Disable,0,0},
	{NVIC_16_32_TIMER_3_A     		,Int_Disable,0,0},
    {NVIC_16_32_TIMER_3_B     		,Int_Disable,0,0},
	{NVIC_I2C_1         				,Int_Disable,0,0},
	{NVIC_QEI_1         				,Int_Disable,0,0},
	{NVIC_CAN_0         				,Int_Disable,0,0},
	{NVIC_CAN_1         				,Int_Disable,0,0},
	{NVIC_HIBERNATION 		,Int_Disable,0,0},
	{NVIC_USB           				,Int_Disable,0,0},
    {NVIC_PWM_GEN_3     				,				Int_Disable,0,0},
	{NVIC_UDMA_SOFTWARE 				,Int_Disable,0,0},
	{NVIC_UDMA_ERROR    				,Int_Disable,0,0},				
	{NVIC_ADC_1_SEQ_0   				,Int_Disable,0,0},
	{NVIC_ADC_1_SEQ_1   				,Int_Disable,0,0},
	{NVIC_ADC_1_SEQ_2   				,Int_Disable,0,0},
	{NVIC_ADC_1_SEQ_3   				,Int_Disable,0,0},
	{NVIC_SSI_2 			,Int_Disable,0,0},
	{NVIC_SSI_3         				,Int_Disable,0,0},
	{NVIC_UART_3        				,Int_Disable,0,0},
	{NVIC_UART_4        				,Int_Disable,0,0},
	{NVIC_UART_5        				,Int_Disable,0,0},
	{NVIC_UART_6        				,Int_Disable,0,0},
	{NVIC_UART_7        				,Int_Disable,0,0},
	{NVIC_I2C_2				,Int_Disable,0,0},
	{NVIC_I2C_3         				,Int_Disable,0,0},
	{NVIC_16_32_TIMER_4_A     		,Int_Disable,0,0},
	{NVIC_16_32_TIMER_4_B     		,Int_Disable,0,0},
	{NVIC_16_32_TIMER_5_A		,Int_Disable,0,0},
	{NVIC_16_32_TIMER_5_B     		,Int_Disable,0,0},
	{NVIC_32_64_TIMER_0_A     		,Int_Disable,0,0},
	{NVIC_32_64_TIMER_0_B     		,Int_Disable,0,0},
	{NVIC_32_64_TIMER_1_A     		,Int_Disable,0,0},
	{NVIC_32_64_TIMER_1_B     		,Int_Disable,0,0},
	{NVIC_32_64_TIMER_2_A     		,Int_Disable,0,0},
	{NVIC_32_64_TIMER_2_B     		,Int_Disable,0,0},
	{NVIC_32_64_TIMER_3_A     		,Int_Disable,0,0},
	{NVIC_32_64_TIMER_3_B     		,Int_Disable,0,0},
	{NVIC_32_64_TIMER_4_A     		,Int_Disable,0,0},
	{NVIC_32_64_TIMER_4_B     		,Int_Disable,0,0},
	{NVIC_32_64_TIMER_5_A     		,Int_Disable,0,0},
	{NVIC_32_64_TIMER_5_B     		,Int_Disable,0,0},
	{NVIC_SYSTEM_EXCEPTION    		,Int_Disable,0,0},
	{NVIC_PWM_1_GEN_0   		,Int_Disable,0,0},
	{NVIC_PWM_1_GEN_1         		,Int_Disable,0,0},
	{NVIC_PWM_1_GEN_2         		,Int_Disable,0,0},
	{NVIC_PWM_1_GEN_3         		,Int_Disable,0,0},
	{NVIC_PWM_1_FAULT,               Int_Disable,0,0},
    	
};
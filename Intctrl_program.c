#include "../../Libraries/STD_Types.h"
#include "../../Libraries/bit_calc.h"
#include "../Mcu_Hw.h"
#include "Intctrl_private.h"
#include "Intctrl_config.h"
#include "Intctrl_interface.h"



extern const Nvic_ConfigType Nvic_Config[78];


void NVIC_init(void){
		Nvic_IntType Num;
	U8 locGroup,locSubGroup,i,locGroupingField;
	U32 En_Dis_Regoffset,En_Dis_Bitoffset,priRegOffset,priBitOffset;
	/*Configure Grouping\SubGrouping System in APINT register in SCB*/
	
	APINT = (APINT_VECTKEY<<APINT_VECTKEY_FIELD_OFFSET) |
	        (NVIC_GROUPING_SYSTEM<<PRIGROUP_FIELD_OFFSET);
	
	for(i=0;i<78;i++){
		Num = Nvic_Config[i].interruptNumber;
		locGroup = Nvic_Config[i].groupPriority;
		locSubGroup = Nvic_Config[i].subgroupPriority;
		
		//Enable\Disable based on user configurations in ENx Nvic Registers */
	
		if(Nvic_Config[i].en_dis==Int_Enable){
        En_Dis_Regoffset = (Num/32)*4;
		En_Dis_Bitoffset = Num%32;
		GET_HWREG(NVIC_ENABLE_BASE_ADDRESS,En_Dis_Regoffset) |= (1<<En_Dis_Bitoffset);
		
		}
		
		/* Create Grouping Field */
#if (NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_XXX)
	    locGroupingField = locGroup;
#elif (NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_XXY) 
        locGroupingField = ((locGroup<<1)&0x6) | (locSubGroup&0x1);
#elif (NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_XYY) 
        locGroupingField = ((locGroup<<2)&0x4) | (locSubGroup&0x3);
#elif (NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_YYY) 
        locGroupingField = locSubGroup;
#else
     #error INVALID GROUPING SELECTION
#endif 	/*NVIC_GROUPING_SYSTEM*/
		
		/*Assign Group\Subgroup priority in PRIx Nvic Registers*/
		
	    priRegOffset = (Num / NVIC_REG_NUM_OF_PRI_FIELDS)*4;
		priBitOffset = 5+((Num % NVIC_REG_NUM_OF_PRI_FIELDS) *8 );
	    GET_HWREG(NVIC_PRI_BASE_ADDRESS,priRegOffset) |= (locGroupingField << priBitOffset);
	    
		 
		
	}
	
	
	
}
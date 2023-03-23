#ifndef MCU_HW_H_
#define MCU_HW_H

//GPIO
typedef struct{
U32 GPIO_DATA_R;
U32 GPIO_DIR_R;       
U32 GPIO_IS_R;
U32 GPIO_IBE_R;
U32 GPIO_IEV_R;
U32 GPIO_IM_R;        
U32 GPIO_RIS_R;
U32 GPIO_MIS_R;
U32 GPIO_ICR_R;
U32 GPIO_AFSEL_R;

U8 Reserved_2[0xDC];

U32 GPIO_DR2R_R;      
U32 GPIO_DR4R_R;       
U32 GPIO_DR8R_R;       
U32 GPIO_ODR_R;        
U32 GPIO_PUR_R;        
U32 GPIO_PDR_R;        
U32 GPIO_SLR_R;     
U32 GPIO_DEN_R;        
U32 GPIO_LOCK_R;      
U32 GPIO_CR_R;         
U32 GPIO_AMSEL_R;    
U32 GPIO_PCTL_R;     
U32 GPIO_ADCCTL_R;     
U32 GPIO_DMACTL_R;     
}GPIO_Register;




#define PORTA               ((volatile GPIO_Register*)0x400043FC)    
#define PORTB               ((volatile GPIO_Register*)0x400053FC) 
#define PORTC               ((volatile GPIO_Register*)0x400063FC) 
#define PORTD               ((volatile GPIO_Register*)0x400073FC) 
#define PORTE               ((volatile GPIO_Register*)0x400243FC) 
#define PORTF               ((volatile GPIO_Register*)0x400253FC) 





#define	GPIO_PORTA_DATA_BITS_R  ((volatile U32*)0x40004000)
#define GPIO_PORTB_DATA_BITS_R  ((volatile U32*)0x40005000)
#define GPIO_PORTC_DATA_BITS_R  ((volatile U32*)0x40006000)
#define GPIO_PORTD_DATA_BITS_R  ((volatile U32*)0x40007000)
#define GPIO_PORTE_DATA_BITS_R  ((volatile U32*)0x40024000)
#define GPIO_PORTF_DATA_BITS_R  ((volatile U32*)0x40025000)







// SYSTEM CLOCK
#define SYSCTL_RCGCWD_R         (*((volatile unsigned long *)0x400FE600))
#define SYSCTL_RCGCTIMER_R      (*((volatile unsigned long *)0x400FE604))
#define SYSCTL_RCGCGPIO_R       (*((volatile unsigned long *)0x400FE608))
#define SYSCTL_RCGCDMA_R        (*((volatile unsigned long *)0x400FE60C))
#define SYSCTL_RCGCHIB_R        (*((volatile unsigned long *)0x400FE614))
#define SYSCTL_RCGCUART_R       (*((volatile unsigned long *)0x400FE618))
#define SYSCTL_RCGCSSI_R        (*((volatile unsigned long *)0x400FE61C))
#define SYSCTL_RCGCI2C_R        (*((volatile unsigned long *)0x400FE620))
#define SYSCTL_RCGCUSB_R        (*((volatile unsigned long *)0x400FE628))
#define SYSCTL_RCGCCAN_R        (*((volatile unsigned long *)0x400FE634))
#define SYSCTL_RCGCADC_R        (*((volatile unsigned long *)0x400FE638))
#define SYSCTL_RCGCACMP_R       (*((volatile unsigned long *)0x400FE63C))
#define SYSCTL_RCGCPWM_R        (*((volatile unsigned long *)0x400FE640))
#define SYSCTL_RCGCQEI_R        (*((volatile unsigned long *)0x400FE644))
#define SYSCTL_RCGCEEPROM_R     (*((volatile unsigned long *)0x400FE658))
#define SYSCTL_RCGCWTIMER_R     (*((volatile unsigned long *)0x400FE65C))

#define SYSCTL_PRWD_R           (*((volatile unsigned long *)0x400FEA00))
#define SYSCTL_PRTIMER_R        (*((volatile unsigned long *)0x400FEA04))
#define SYSCTL_PRGPIO_R         (*((volatile unsigned long *)0x400FEA08))
#define SYSCTL_PRDMA_R          (*((volatile unsigned long *)0x400FEA0C))
#define SYSCTL_PRHIB_R          (*((volatile unsigned long *)0x400FEA14))
#define SYSCTL_PRUART_R         (*((volatile unsigned long *)0x400FEA18))
#define SYSCTL_PRSSI_R          (*((volatile unsigned long *)0x400FEA1C))
#define SYSCTL_PRI2C_R          (*((volatile unsigned long *)0x400FEA20))
#define SYSCTL_PRUSB_R          (*((volatile unsigned long *)0x400FEA28))
#define SYSCTL_PRCAN_R          (*((volatile unsigned long *)0x400FEA34))
#define SYSCTL_PRADC_R          (*((volatile unsigned long *)0x400FEA38))
#define SYSCTL_PRACMP_R         (*((volatile unsigned long *)0x400FEA3C))
#define SYSCTL_PRPWM_R          (*((volatile unsigned long *)0x400FEA40))
#define SYSCTL_PRQEI_R          (*((volatile unsigned long *)0x400FEA44))
#define SYSCTL_PREEPROM_R       (*((volatile unsigned long *)0x400FEA58))
#define SYSCTL_PRWTIMER_R       (*((volatile unsigned long *)0x400FEA5C))



//NVIC
#define NVIC_ENABLE_BASE_ADDRESS         0xE000E100
#define NVIC_PRI_BASE_ADDRESS            0xE000E400

#define APINT                            *((volatile U32*)0xE000ED0C)

//TIMER0
#define TIMER0_CFG_R            (*((volatile U32*)0x40030000))
#define TIMER0_TAMR_R           (*((volatile U32*)0x40030004))
#define TIMER0_TBMR_R           (*((volatile U32*)0x40030008))
#define TIMER0_CTL_R            (*((volatile U32*)0x4003000C))
#define TIMER0_SYNC_R           (*((volatile U32*)0x40030010))
#define TIMER0_IMR_R            (*((volatile U32*)0x40030018))
#define TIMER0_RIS_R            (*((volatile U32*)0x4003001C))
#define TIMER0_MIS_R            (*((volatile U32*)0x40030020))
#define TIMER0_ICR_R            (*((volatile U32*)0x40030024))
#define TIMER0_TAILR_R          (*((volatile U32*)0x40030028))
#define TIMER0_TBILR_R          (*((volatile U32*)0x4003002C))
#define TIMER0_TAMATCHR_R       (*((volatile unsigned long *)0x40030030))
#define TIMER0_TBMATCHR_R       (*((volatile U32*)0x40030034))
#define TIMER0_TAPR_R           (*((volatile U32*)0x40030038))
#define TIMER0_TBPR_R           (*((volatile U32*)0x4003003C))
#define TIMER0_TAPMR_R          (*((volatile U32*)0x40030040))
#define TIMER0_TBPMR_R          (*((volatile U32*)0x40030044))
#define TIMER0_TAR_R            (*((volatile U32*)0x40030048))
#define TIMER0_TBR_R            (*((volatile U32*)0x4003004C))
#define TIMER0_TAV_R            (*((volatile U32*)0x40030050))
#define TIMER0_TBV_R            (*((volatile U32*)0x40030054))
#define TIMER0_RTCPD_R          (*((volatile U32*)0x40030058))
#define TIMER0_TAPS_R           (*((volatile U32*)0x4003005C))
#define TIMER0_TBPS_R           (*((volatile U32*)0x40030060))
#define TIMER0_TAPV_R           (*((volatile U32*)0x40030064))
#define TIMER0_TBPV_R           (*((volatile U32*)0x40030068))
#define TIMER0_PP_R             (*((volatile U32*)0x40030FC0))







//Macro Function to get register address after offset
#define GET_HWREG(BaseAddr,RegOffset)      (*((volatile U32*)(BaseAddr+RegOffset)))

#endif
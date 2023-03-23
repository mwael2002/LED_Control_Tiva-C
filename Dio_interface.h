#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

typedef enum
{
    Dio_Channel_A0,
    Dio_Channel_A1,
    Dio_Channel_A2,
    Dio_Channel_A3,
    Dio_Channel_A4,
    Dio_Channel_A5,
    Dio_Channel_A6,
    Dio_Channel_A7,

    Dio_Channel_B0,
    Dio_Channel_B1,
    Dio_Channel_B2,
    Dio_Channel_B3,
    Dio_Channel_B4,
    Dio_Channel_B5,
    Dio_Channel_B6,
    Dio_Channel_B7,


    Dio_Channel_C0,
    Dio_Channel_C1,
    Dio_Channel_C2,
    Dio_Channel_C3,
    Dio_Channel_C4,
    Dio_Channel_C5,
    Dio_Channel_C6,
    Dio_Channel_C7,


    Dio_Channel_D0,
    Dio_Channel_D1,
    Dio_Channel_D2,
    Dio_Channel_D3,
    Dio_Channel_D4,
    Dio_Channel_D5,
    Dio_Channel_D6,
    Dio_Channel_D7,

    Dio_Channel_E0,
    Dio_Channel_E1,
    Dio_Channel_E2,
    Dio_Channel_E3,
    Dio_Channel_E4,
    Dio_Channel_E5,

    Dio_Channel_F0=40,
    Dio_Channel_F1,
    Dio_Channel_F2,
    Dio_Channel_F3,
    Dio_Channel_F4

}Dio_ChannelType;



typedef unsigned char Dio_PortType;

#define Dio_Port_A       0
#define Dio_Port_B       1
#define Dio_Port_C       2
#define Dio_Port_D       3
#define Dio_Port_E       4
#define Dio_Port_F       5



typedef unsigned char Dio_LevelType;

#define Dio_Channel_HIGH 1
#define Dio_Channel_LOW  0



typedef unsigned int Dio_PortLevelType;






/******************************************************************************
* \Syntax          : void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level)                                     
* \Description     : Write high or low on the required pin(channel)                                
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : channel id and channel level                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level);

/******************************************************************************
* \Syntax          : void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level)                                     
* \Description     : Write  the level value on the entire port                              
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Port id and Port level                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level);

/******************************************************************************
* \Syntax          : Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)                                     
* \Description     : Read the value of the required pin(channel) and return it                             
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : channel id                     
* \Parameters (out): channel level                                                      
* \Return value:   : channel level 
*******************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);


/******************************************************************************
* \Syntax          : Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)                                     
* \Description     : Read the value of the entire and return it                             
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Port id                     
* \Parameters (out): Port level                                                      
* \Return value:   : Port level 
*******************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);


/******************************************************************************
* \Syntax          : Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)                                     
* \Description     : change the value of the required pin(channel) from high to
                     low or vice versa and return the value after this change
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non-Reentrant                                             
* \Parameters (in) : channel id                     
* \Parameters (out): channel level                                                      
* \Return value:   : channel level 
*******************************************************************************/
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);







#endif
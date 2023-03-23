#include "../../Libraries/STD_Types.h"
#include "Port_interface.h"
#include "Port_config.h"







Port_ConfigType PortConfigArr[Port_Channel_MaxNum] = {
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*    Channel                   Direction                Mode                          External Interrupt      Attached_Resistor                      Current_Drive_Strength      Lock_Status    */
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

{     Port_Channel_A0,          Port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_PullUp,         Port_CurrDrive_2mA,         Port_ChannelUnlocked     },
{     Port_Channel_A1,          Port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_ChannelUnlocked     },
{     Port_Channel_A2,          Port_Dir_Output,          PORT_MODE_PIN_X_DIO,     Port_IntDisable,        Port_InternalAttach_NoAttach,          Port_CurrDrive_2mA,         Port_ChannelUnlocked     },
{     Port_Channel_A3,          Port_Dir_Output,          PORT_MODE_PIN_X_DIO,     Port_IntDisable,        Port_InternalAttach_NoAttach,          Port_CurrDrive_2mA,         Port_ChannelUnlocked     },
{     Port_Channel_A4,          Port_Dir_Output,          PORT_MODE_PIN_X_DIO,      Port_IntDisable,        Port_InternalAttach_NoAttach,          Port_CurrDrive_2mA,         Port_ChannelUnlocked     },
{     Port_Channel_A5,          Port_Dir_Output,         PORT_MODE_PIN_X_DIO,      Port_IntDisable,        Port_InternalAttach_NoAttach,          Port_CurrDrive_2mA,         Port_ChannelUnlocked     },
{     Port_Channel_A6,          Port_Dir_Input,          PORT_MODE_PIN_A6_I2C1SCL,     Port_IntDisable,        Port_InternalAttach_PullUp,            Port_CurrDrive_2mA,         Port_ChannelUnlocked     },
{     Port_Channel_A7,          Port_Dir_Input,          PORT_MODE_PIN_A7_I2C1SDA,     Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_ChannelUnlocked     },

{     Port_Channel_B0,          Port_Dir_Output,          PORT_MODE_PIN_X_DIO,        Port_IntDisable,        Port_InternalAttach_NoAttach,          Port_CurrDrive_2mA,         Port_ChannelUnlocked     },
{     Port_Channel_B1,          Port_Dir_Output,         PORT_MODE_PIN_X_DIO,        Port_IntDisable,        Port_InternalAttach_NoAttach,          Port_CurrDrive_2mA,         Port_ChannelUnlocked     },
{     Port_Channel_B2,          Port_Dir_Output,          PORT_MODE_PIN_X_DIO,     Port_IntDisable,        Port_InternalAttach_NoAttach,            Port_CurrDrive_2mA,         Port_ChannelUnlocked     },
{     Port_Channel_B3,          Port_Dir_Output,          PORT_MODE_PIN_X_DIO,     Port_IntDisable,        Port_InternalAttach_NoAttach,         Port_CurrDrive_2mA,         Port_ChannelUnlocked     },
{     Port_Channel_B4,          Port_Dir_Output,         PORT_MODE_PIN_X_DIO,     Port_IntDisable,        Port_InternalAttach_NoAttach,            Port_CurrDrive_2mA,         Port_ChannelUnlocked     },
{     Port_Channel_B5,          Port_Dir_Output,         PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_NoAttach,          Port_CurrDrive_2mA,         Port_ChannelUnlocked     },
{     Port_Channel_B6,          Port_Dir_Output,          PORT_MODE_PIN_X_DIO,      Port_IntDisable,        Port_InternalAttach_NoAttach,            Port_CurrDrive_2mA,         Port_ChannelUnlocked     },
{     Port_Channel_B7,          Port_Dir_Output,         PORT_MODE_PIN_X_DIO,      Port_IntDisable,        Port_InternalAttach_NoAttach,            Port_CurrDrive_2mA,         Port_ChannelUnlocked     },

{     Port_Channel_C0,          Port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_ChannelLocked     },
{     Port_Channel_C1,          Port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_ChannelLocked     },
{     Port_Channel_C2,          Port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_ChannelLocked     },
{     Port_Channel_C3,          Port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_ChannelLocked     },
{     Port_Channel_C4,          Port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_ChannelUnlocked     },
{     Port_Channel_C5,          Port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_ChannelUnlocked     },
{     Port_Channel_C6,          Port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_ChannelUnlocked     },
{     Port_Channel_C7,          Port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_ChannelUnlocked     },

{     Port_Channel_D0,          Port_Dir_Input,          PORT_MODE_PIN_D0_SSI3Clk,     Port_IntDisable,        Port_InternalAttach_PullUp,            Port_CurrDrive_2mA,         Port_ChannelUnlocked     },
{     Port_Channel_D1,          Port_Dir_Input,          PORT_MODE_PIN_D1_SSI3Fss,     Port_IntDisable,        Port_InternalAttach_PullDown,          Port_CurrDrive_2mA,         Port_ChannelUnlocked     },
{     Port_Channel_D2,          Port_Dir_Input,          PORT_MODE_PIN_D2_SSI3Rx,      Port_IntDisable,        Port_InternalAttach_PullUp,            Port_CurrDrive_2mA,         Port_ChannelUnlocked     },
{     Port_Channel_D3,          Port_Dir_Output,         PORT_MODE_PIN_D3_SSI3Tx,      Port_IntDisable,        Port_InternalAttach_NoAttach,          Port_CurrDrive_2mA,         Port_ChannelUnlocked     },
{     Port_Channel_D4,          Port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_ChannelUnlocked     },
{     Port_Channel_D5,          Port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_ChannelUnlocked     },
{     Port_Channel_D6,          Port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_ChannelUnlocked     },
{     Port_Channel_D7,          Port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_ChannelUnlocked     },

{     Port_Channel_E0,          Port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_ChannelLocked     },
{     Port_Channel_E1,          Port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_ChannelLocked     },
{     Port_Channel_E2,          Port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_ChannelLocked     },
{     Port_Channel_E3,          Port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_ChannelLocked     },
{     Port_Channel_E4,          Port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_ChannelLocked     },
{     Port_Channel_E5,          Port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_ChannelLocked     },

{     Port_Channel_F0,          Port_Dir_Input,         PORT_MODE_PIN_X_DIO,          Port_IntFallingEdge,     Port_InternalAttach_PullUp,          Port_CurrDrive_2mA,          Port_ChannelUnlocked    },
{     Port_Channel_F1,          Port_Dir_Output,         PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_NoAttach,          Port_CurrDrive_8mA,          Port_ChannelUnlocked    },
{     Port_Channel_F2,          Port_Dir_Output,         PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_NoAttach,          Port_CurrDrive_8mA,          Port_ChannelUnlocked    },
{     Port_Channel_F3,          Port_Dir_Output,         PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_NoAttach,          Port_CurrDrive_8mA,          Port_ChannelUnlocked    },
{     Port_Channel_F4,          Port_Dir_Input,         PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_PullUp,          Port_CurrDrive_2mA,          Port_ChannelUnlocked    }

};
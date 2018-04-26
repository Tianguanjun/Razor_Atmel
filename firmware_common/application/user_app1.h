/**********************************************************************************************************************
File: user_app1.h                                                                

----------------------------------------------------------------------------------------------------------------------
To start a new task using this user_app1 as a template:
1. Follow the instructions at the top of user_app1.c
2. Use ctrl-h to find and replace all instances of "user_app1" with "yournewtaskname"
3. Use ctrl-h to find and replace all instances of "UserApp1" with "YourNewTaskName"
4. Use ctrl-h to find and replace all instances of "USER_APP1" with "YOUR_NEW_TASK_NAME"
5. Add #include yournewtaskname.h" to configuration.h
6. Add/update any special configurations required in configuration.h (e.g. peripheral assignment and setup values)
7. Delete this text (between the dashed lines)
----------------------------------------------------------------------------------------------------------------------

Description:
Header file for user_app1.c

**********************************************************************************************************************/

#ifndef __USER_APP1_H
#define __USER_APP1_H

/**********************************************************************************************************************
Type Definitions
**********************************************************************************************************************/


/**********************************************************************************************************************
Constants / Definitions
**********************************************************************************************************************/

#define ANT_CHANNEL_SLAVE                ANT_CHANNEL_0         
#define ANT_CHANNEL_TYPE_SLAVE           CHANNEL_TYPE_SLAVE    
#define ANT_CHANNEL_MASTER               ANT_CHANNEL_1         
#define ANT_CHANNEL_TYPE_MASTER          CHANNEL_TYPE_MASTER 
#define ANT_DEVICE0ID_LO_USERAPP         (u8)0x35              
#define ANT_DEVICE0ID_HI_USERAPP         (u8)0x25
#define ANT_DEVICE_TYPE_USERAPP          (u8)1        
#define ANT_TRANSMISSION_TYPE_USERAPP    (u8)1             
#define ANT_CHANNEL_PERIOD_LO_USERAPP    (u8)0x00       
#define ANT_CHANNEL_PERIOD_HI_USERAPP    (u8)0x20      
#define ANT_FREQUENCY_USERAPP            (u8)50           
#define ANT_TX_POWER_USERAPP             RADIO_TX_POWER_4DBM
#define TIMEOUT_VALUE                    (u16)3000
#define HIDING_TIME_COUNTER              (u8)10
#define HIDING_TIME_DIS_PLACE            (u8)15
#define ONE_SECOND_TIME                  (u16)1000
#define TOTAL_LEDS_COUNT                 (u8)8
#define MAXIMUM_RSSI                     (s8)-40
#define WAIT_HIDING                      (u8)0
#define IS_SEARCHING                     (u8)1
#define FIND_HIM                         (u8)2
#define KEY_PARAMETER                    (u8)0x12
#define EACH_TONE_TIME                   (u16)400
/**********************************************************************************************************************
Function Declarations
**********************************************************************************************************************/

/*--------------------------------------------------------------------------------------------------------------------*/
/* Public functions                                                                                                   */
/*--------------------------------------------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------------------------------------------*/
/* Protected functions                                                                                                */
/*--------------------------------------------------------------------------------------------------------------------*/
void UserApp1Initialize(void);
void UserApp1RunActiveState(void);


/*--------------------------------------------------------------------------------------------------------------------*/
/* Private functions                                                                                                  */
/*--------------------------------------------------------------------------------------------------------------------*/


/***********************************************************************************************************************
State Machine Declarations
***********************************************************************************************************************/
static void UserApp1SM_Idle(void);

static fnCode_type UserApp1_StateMachine;            /* The state machine function pointer */
static u32 UserApp1_u32Timeout;                      /* Timeout counter used across states */
static AntAssignChannelInfoType sAntSetupData;
static bool bChannelIsMaster = TRUE;


extern u32 G_u32AntApiCurrentDataTimeStamp;                       
extern AntApplicationMessageType G_eAntApiCurrentMessageClass;   
extern u8 G_au8AntApiCurrentMessageBytes[ANT_APPLICATION_MESSAGE_BYTES];
extern AntExtendedDataType G_sAntApiCurrentMessageExtData; 


extern volatile u32 G_u32SystemFlags;                  /* From main.c */
extern volatile u32 G_u32ApplicationFlags;             /* From main.c */

extern volatile u32 G_u32SystemTime1ms;                /* From board-specific source file */

static void UserApp1SM_Error(void);         


#endif /* __USER_APP1_H */


/*--------------------------------------------------------------------------------------------------------------------*/
/* End of File                                                                                                        */
/*--------------------------------------------------------------------------------------------------------------------*/

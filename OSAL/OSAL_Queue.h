/******************************************************************************
* File       : OSAL_Queue.h
* Function   : General queue function.
* description: To be done.          
* Version    : V1.00
* Author     : Ian
* Date       : 10th Jun 2016
* History    :  No.  When           Who           What
*               1    10/Jun/2016    Ian           Create
******************************************************************************/

#ifndef _OSAL_QUEUE_H_
#define _OSAL_QUEUE_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Check if specified option is set for debugging */
#ifndef __DEBUG_MODE_OSAL_QUEUE                    
#define __DEBUG_MODE      __DEBUG_NONE                    /* Default: None debugging info            */
#else
#ifdef __DEBUG_MODE
#undef __DEBUG_MODE
#endif
#define __DEBUG_MODE      __DEBUG_MODE_OSAL_QUEUE         /* According the set from project_config.h */
#endif

#define OSAL_QUEUE_LAST_FREE(p)        ((p)->pu8Addr + (p)->u8End * (p)->u8MaxCnt)
#define OSAL_QUEUE_FIRST_USED(p)       ((p)->pu8Addr + (p)->u8Begin * (p)->u8MaxCnt)


typedef struct _T_QUEUE_INFO
{
    uint8 *pu8Addr;                         /* Address of the queue */
    uint8  u8Begin;
    uint8  u8End;
    uint8  u8Len;
    uint8  u8MaxCnt;
    uint8  u8Cnt;
}T_QUEUE_INFO;


/******************************************************************************
* Name       : uint8 Osal_Queue_Create(uint8 u8Len, uint8 u8Num)
* Function   : Create a queue and return the queue number
* Input      : PF_TIMER_SRC pfSysTm   Funtion which returns system time
* Output:    : None
* Return     : SW_OK   Successful.
*              SW_ERR  Failed.
* description: To be done.
* Version    : V1.00
* Author     : Ian
* Date       : 2nd Jun 2016
******************************************************************************/
T_QUEUE_INFO* Osal_Queue_Create(T_QUEUE_INFO* ptQueueInfo, uint8 u8Len, uint8 u8Cnt);

uint8 Osal_Queue_Inc(T_QUEUE_INFO *ptQueue);

uint8 Osal_Queue_Dec(T_QUEUE_INFO *ptQueue);

uint8 Osal_Queue_Is_Free(T_QUEUE_INFO *ptQueue);

uint8 Osal_Queue_Is_Empty(T_QUEUE_INFO *ptQueue);


/******************************************************************************
* Name       : uint8 Osal_Queue_Delete(T_QUEUE_INFO* ptQueueInfo)
* Function   : Create a queue and return the queue number
* Input      : PF_TIMER_SRC pfSysTm   Funtion which returns system time
* Output:    : None
* Return     : SW_OK   Successful.
*              SW_ERR  Failed.
* description: To be done.
* Version    : V1.00
* Author     : Ian
* Date       : 2nd Jun 2016
******************************************************************************/
uint8 Osal_Queue_Delete(T_QUEUE_INFO* ptQueueInfo);
void Osal_Queue_Test_General();

 
#ifdef __cplusplus
}
#endif

#endif /* _OSAL_QUEUE_H_ */

/* End of file */


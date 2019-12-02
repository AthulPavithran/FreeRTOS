#ifndef FREERTOSTASKS_H
#define FREERTOSTASKS_H
#include "ExamplTaskConfig.h"
#include "queue.h"



#if (QUEUE_TASK)
extern  QueueHandle_t xQueue1;
extern uint8_t auQueue8Data [10];
extern uint8_t u8QueueDataIndex;

#endif

BaseType_t FreeRtosTasks(void);

#endif
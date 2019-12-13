#ifndef FREERTOSTASKS_H
#define FREERTOSTASKS_H
#include "ExamplTaskConfig.h"
#include "queue.h"
#include "semphr.h"



#if (QUEUE_TASK)

extern TaskHandle_t   sQueue1, sQueue2, sQueue3;
extern QueueHandle_t xQueue1;
extern uint8_t auQueue8Data [10];
extern uint8_t u8QueueDataIndex;

#endif

#if (SEMAPHORE_TASK)

extern TaskHandle_t   UartRecTask;
extern uint8_t auQueue8Data [10];
extern QueueHandle_t xQueue1;
extern SemaphoreHandle_t xSemaphore;

#endif

#if (MUTEX_TASK)

extern SemaphoreHandle_t  xMutex;
extern TaskHandle_t   xSerial4;
extern TaskHandle_t   xSerial5;

#endif

BaseType_t FreeRtosTasks(void);

#endif
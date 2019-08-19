//
// Created by john on 19. 8. 19..
//

#ifndef _INTQUEUE_H_
#define _INTQUEUE_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int queue_capacity;
    int queue_count;
    int queue_front_index;
    int queue_rear_index;
    int *queue_pointer_of_first_index;

}IntQueue;

int Queue_Initialize(IntQueue *queue, int queue_capacity);
int Queue_Enqueue(IntQueue *queue, int data_to_enqueue);
int Queue_Dequeue(IntQueue *queue, int *data_to_dequeue);
int Queue_Peek(IntQueue *queue, int *data_to_peek);
void Queue_Clear(IntQueue *queue);
int Queue_Capacity(const IntQueue *queue);
int Queue_Count(const IntQueue *queue);
int Queue_Is_Empty(const IntQueue *queue);
int Queue_Is_Full(const IntQueue *queue);
int Queue_Search(const IntQueue *queue, int data_to_search);
void Queue_Print(const IntQueue *queue);
void Queue_Terminate(IntQueue *queue);

#endif //_INTQUEUE_H_

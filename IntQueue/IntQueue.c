//
// Created by john on 19. 8. 19..
//


#include "IntQueue.h"


int Queue_Initialize(IntQueue *queue, int queue_capacity)
{
    queue->queue_count= queue->queue_front_index= queue->queue_rear_index=0;

    if((queue->queue_pointer_of_first_index=(int*)calloc(queue_capacity, sizeof(int))) == NULL)
    {
        printf("\a Fail To Initialize!");
        queue->queue_capacity=0;
        return -1;
    }

    queue->queue_capacity=queue_capacity;

    return 0;
}


int Queue_Enqueue(IntQueue *queue, int data_to_enqueue)
{
    if(queue->queue_count == queue->queue_capacity)
    {
        printf("\a Queue is full!");
        return -1;
    }

    else
    {
        queue->queue_count++;
        queue->queue_pointer_of_first_index[queue->queue_rear_index++]=data_to_enqueue;

        if(queue->queue_rear_index == queue->queue_capacity)
        {
            queue->queue_rear_index=0;
        }
        return 0;
    }
}

int Queue_Dequeue(IntQueue *queue, int *data_to_dequeue)
{
    if(queue->queue_count <= 0)
    {
        printf("\a Queue us empty!");
        return -1;
    }
    else
    {
        queue->queue_count--;
        *data_to_dequeue=queue->queue_pointer_of_first_index[queue->queue_front_index++];

        if(queue->queue_front_index == queue->queue_count)
        {
            queue->queue_front_index=0;
        }

        return 0;
    }
}


int Queue_Peek(IntQueue *queue, int *data_to_peek)
{
    if(queue->queue_count<=0)
    {
        printf("\a Queue is empty!");
        return -1;
    }

    else
    {
        *data_to_peek=queue->queue_pointer_of_first_index[queue->queue_front_index];
        return 0;
    }

}


void Queue_Clear(IntQueue *queue)
{
    queue->queue_count=queue->queue_front_index=queue->queue_rear_index=0;
}

int Queue_Capacity(const IntQueue *queue)
{
    return queue->queue_capacity;
}

int Queue_Count(const IntQueue *queue)
{
    return queue->queue_count;
}

int Queue_Is_Empty(const IntQueue *queue)
{
    return queue->queue_count<=0;
}

int Queue_Is_Full(const IntQueue *queue)
{
    return queue->queue_count>=queue->queue_capacity;
}

int Queue_Search(const IntQueue *queue, int data_to_search)
{
    int queue_index;

    for(int i=0;i<queue->queue_count;i++)
    {
        if(queue->queue_pointer_of_first_index[queue_index=(i+queue->queue_front_index)%queue->queue_capacity]==data_to_search)
        {
            return queue_index;
        }

    }

    return -1;
}


void Queue_Print(const IntQueue *queue)
{
    for(int i=0;i<queue->queue_count;i++)
    {
        printf("%d\n",queue->queue_pointer_of_first_index[(i+queue->queue_front_index)%queue->queue_capacity]);
    }
}

void Queue_Terminate(IntQueue *queue)
{
    if(queue->queue_pointer_of_first_index!=NULL)
    {
        free(queue->queue_pointer_of_first_index);
    }

    queue->queue_capacity=queue->queue_count=queue->queue_front_index=queue->queue_rear_index=0;

}
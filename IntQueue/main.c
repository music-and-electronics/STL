#include <stdio.h>
#include "IntQueue.h"
int main()
{
    IntQueue queue;
    int queue_capacity;
    char end_the_queue_loop='y';


    printf("Input the capacity of Queue : ");
    scanf("%d", &queue_capacity);


    if(Queue_Initialize(&queue,queue_capacity)==-1)
    {
        printf("\a Fail to initialize queue!\n");
        return 1;
    }

    while(end_the_queue_loop=='y')
    {
        int queue_menu,data_to_input;

        printf("Current Data Size %d/%d\n" ,Queue_Count(&queue), Queue_Capacity(&queue));
        printf("(1)Enqueue (2)Dequeue (3)Peek (4)Print (0)End");
        scanf("%d",&queue_menu);

        if(queue_menu==0)
        {
            break;
        }

        switch(queue_menu)
        {
            default:
            {
                break;
            }

            case 1:
            {
                printf("Data : ");
                scanf("%d",&data_to_input);

                if(Queue_Enqueue(&queue,data_to_input)==-1)
                {
                    printf("\aFail to enqueue \n");
                }
                break;
            }

            case 2:
            {


                if(Queue_Dequeue(&queue,&data_to_input)==-1)
                {
                    printf("\aFail to dequeue \n");
                }
                else
                {
                    printf("Dequeue data is %d\n", data_to_input);
                }
                break;

            }

            case 3:
            {

                if(Queue_Peek(&queue,&data_to_input)==-1)
                {
                    printf("\aFail to dequeue \n");
                }
                else
                {
                    printf("Peeked data is %d\n",data_to_input);
                }
                break;

            }

            case 4:
            {
                Queue_Print(&queue);
                break;
            }

        }

    }

    Queue_Terminate(&queue);
    return 0;


}
#include "STL.h"

int main()
{
    STL::Queue::IntQueue int_queue;
    STL::Queue queue;

    char end_the_queue_loop='y';
    int queue_capacity;

    cout<<"Input the capacity of Queue : ";
    cin>>queue_capacity;


    if(queue.Queue_Initialize(&int_queue,queue_capacity)==-1)
    {
        printf("\a Fail to initialize queue!\n");
        return 1;
    }

    while(end_the_queue_loop=='y')
    {
        int queue_menu,data_to_input;

        cout<<"Current Data Size"<<queue.Queue_Count(&int_queue)<<"/"<<queue.Queue_Capacity(&int_queue)<<endl;
        cout<<"(1)Enqueue (2)Dequeue (3)Peek (4)Print (5)Search (0)End"<<endl;
        cin>>queue_menu;

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
                cout<<"Data : ";
                cin>>data_to_input;

                if(queue.Queue_Enqueue(&int_queue,data_to_input)==-1)
                {
                    cout<<"\a Fail To enqueue"<<endl;
                }
                break;
            }

            case 2:
            {


                if(queue.Queue_Dequeue(&int_queue,&data_to_input)==-1)
                {
                    cout<<"\a Fail To dequeue"<<endl;
                }
                else
                {
                    cout<<"Dequeue data is "<<data_to_input<<endl;
                }
                break;

            }

            case 3:
            {

                if(queue.Queue_Peek(&int_queue,&data_to_input)==-1)
                {
                    cout<<"\a Fail To peek"<<endl;
                }
                else
                {
                    cout<<"Peeked data is "<<data_to_input<<endl;
                }
                break;

            }

            case 4:
            {
                queue.Queue_Print(&int_queue);
                break;
            }

            case 5:
            {
                cout<<"Data : ";
                cin>>data_to_input;


            }

        }

    }

    queue.Queue_Terminate(&int_queue);
    return 0;

}
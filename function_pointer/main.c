#include <stdio.h>

int Sum(int var1, int var2)
{
    return var1+var2;
}

int Multiply(int var1, int var2)
{
    return var1*var2;
}

void Print_Out_All(int(*calc)(int, int))
{
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            printf("%3d",(*calc)(i,j));
        }
        printf("\n");
    }
}

int main (void)
{
    printf("Sum Table\n");
    Print_Out_All (Sum);
    printf("Multiply Table\n");
    Print_Out_All (Multiply);
}
/*

Name: Soumil Ramesh Kulkarni

Description:

This a program to illustrate the working of a Queue using Arrays.
The Basic functions of a stack are :
1) enqueue()-- Places an element in the queue
2) dequeue()-- removes an element from the queue (1st element)
3) top_ele()-- print the first element in the queue
4) print()-- print all the elements in the queue

Note: Consider the implementation of integers.

*/

# include <stdio.h>

int A[50],front=-1 ,back=-1 ;

void enqueue(int x)
{
    if (front==49)
    {
        printf("\n The Queue is Full !!");
    }

    else
    {
        if (back == -1)
        {
            back =0;
        }
        front ++;
        A[front]=x;
        printf("\n The element entered in the queue is : %d ",x);

    }
}

void dequeue ()
{
    if ((back == -1) || (back > front))
    {
        printf("The Queue is Empty !!!");
    }

    else
    {
        printf("\n The element that is dequeued from the queue is : %d",A[back]);
        back ++ ;
    }
}

void print()
{
    int i;
    if ((back == -1) || (back > front))
    {
        printf("\n The  Queue is Empty !!!");
    }
    else
    {
        printf("\n The elements in the queue are: ");
        printf("\n");
        for(i=back ; i<=front ; i++)
        {
            printf(" %d ",A[i]);
        }
    }

}

void top_ele()
{
    printf("\n The element in the front of the queue is : %d ",A[back]);
}


int main()
{
    print();
    enqueue(5);
    enqueue(6);
    top_ele();
    enqueue(7);
    print();
    dequeue();
    print();

    return 0;
}

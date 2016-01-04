/*

Name: Soumil Ramesh Kulkarni

Description:

This a program to illustrate the working of a Stack using Arrays.
The Basic functions of a stack are :
1) push()-- Pushes an element onto the stack
2) pop()-- pop an element from the top of the stack
3) top_ele()-- print the element at the top of the stack
4) print()-- print all the elements of the stack

Note: Consider the implementation of integers.

*/

# include <stdio.h>

int top=-1, A[50];

void push (int x)
{
    if (top==49)
    {
        printf("\nThe Stack is Full");
    }
    else
    {
        top ++ ;
        A[top]=x;
        printf("\nElement pushed on the stack is:  %d ",x);
    }
}

void pop()
{
    if (top==-1)
    {
        printf("\nThe stack is Empty");
    }
    else
    {
        printf("\nThe popped element is: %d",A[top]);
        top --;

    }
}

void top_ele()
{
    printf("\nThe element at the Top of the stack is: %d ",A[top]);
}

void print()
{
    int i;
    printf("\nAll the Elements in the Stack are:");
    printf("\n");
    for (i=0;i<=top;i++)
    {
        printf(" %d ",A[i]);
    }

}



int main()
{
    push(5);
    top_ele();
    push(6);
    print();
    push(7);
    print();
    pop();
    print();

    return 0;
}


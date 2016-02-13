// This program demostrates the working of a Stack using a Singly LinkedList.

# include <stdio.h>
# include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node *head = NULL;

// PUSH function for the Stack

void push(int x)
{
	if (head == NULL)
	{
		struct Node *temp= (struct Node *)malloc(sizeof(struct Node));
		temp->data=x;
		temp->next= NULL;
		head= temp;
		printf("\n PUSH operation SUCCESSFUL !!!!!!");
	}

	else
	{
		struct Node *temp= (struct Node *)malloc(sizeof(struct Node));
		temp->data=x;
		temp->next=head;
		head=temp;
		printf("\n PUSH operation SUCCESSFUL  !!!!!");
	}
}

// POP function for the Stack

void pop()
{
	if (head == NULL)
	{
		printf("\n The Stack is Already Empty !!!!!");
		return;
	}

	else
	{
		struct Node *itr= head;
		itr= itr->next;
		struct Node *del = head;
		head= itr;
		free (del);
		printf("\n POP operation is SUCCESSFUL");
	}
}


//   Function for Top operation

void top()
{
	if (head == NULL)
	{
		printf("\n The Stack is already Empty !!!!!");
	}

	else
	{
		printf("\n The Element at the top of the Stack is : %d",head->data);
	}
}


//   Finction for printing all the elements in the Stakc

void print()
{
	if (head == NULL)
	{
		printf("\n The Stack is Empty !!!!!");
	}

	else
	{
		printf("\n The elements of the stack are : ");
		struct Node * iter= head;
		while (iter != NULL)
		{
			printf(" %d", iter ->data);
			iter=iter->next;
		}
	}
}


int main()
{
	push(3);
	push(4);
	push(5);
	print();
	top();
	pop();
	pop();
	print();
	return 0;


}
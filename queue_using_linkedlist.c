// This program illustrates the working of a Queue usgin LinkedList

# include <stdio.h>
# include <stdlib.h>

struct Node 
{
	int data;
	struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

//  Function for Enqueuing an element 

void enqueue(int x)
{
	if (tail == NULL)
	{
		struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
		temp->data=x;
		temp->next= NULL;
		head= temp;
		tail= temp;
		printf("\n Node successfully enqueued !!!!!");
	}

	else
	{
		struct Node *temp= (struct Node *)malloc(sizeof(struct Node));
		temp->data=x;
		temp->next= NULL;
		tail->next=temp;
		tail=temp;
		printf("\n Node successfully enqueued !!!!!");
	}
}


//  Function for dequeuing an element 

void dequeue()
{
	if (head == NULL)
	{
		printf("\n There is no element in the queue right now !!!!");
	}
	else
	{
		struct Node *iter= head;
		struct Node *iter1= head;
		iter= iter->next;
		head=iter;
		free(iter1);
		printf("\n The element successfully dequeued !!!!");
	}
}


//  Function for printing all the elements in the queue 

void print()
{
	if (head == NULL)
	{
		printf("\n There is no element in the queue right now !!!!");
	}
	else
	{
		struct Node *iter= head;
		printf("\n The elements in the queue starting from the first element in the Queue are: \n");
		while (iter != NULL)
		{
			printf(" %d", iter->data);
			iter= iter->next;
		}

		printf("\n");
	}
}

void front()
{
	if (head ==  NULL)
	{
		printf("\n There are no elemenst in the queue right now !!!!");
	}

	else
	{
		printf("\n The element in the front of the Queue is: %d", head->data);
	}
}


int main()
{
	dequeue();
	enqueue(3);
	enqueue(4);
	enqueue(5);
	print();
	dequeue();
	print();
	front();
	return 0;
}

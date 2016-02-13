// The program implements a Doubly Linked List 
/*
There are some problems in the following functions:

1) void insert_node_at_nth_position(int x, int y)
2) void delete_node_from_nth_position(int x)

*/
# include <stdio.h>
# include <stdlib.h>

struct Node
{
	int data;
	struct Node *prev;
	struct Node *next;
};

struct Node *head= NULL;


// Function for inserting a Node at the start of the doubly Linked List

void insert_node_at_start(int x)
{
	if (head == NULL)
	{
		struct Node *temp= (struct Node*) malloc (sizeof(struct Node));
		temp->data= x;
		temp->next= NULL;
		temp->prev= NULL;
		head=temp;
		printf("\n Node Successfully Inserted at the start of the Doubly LinkedList");
	}

	else
	{
		struct Node *temp= (struct Node *)malloc (sizeof(struct Node));
		temp->data= x;
		temp->prev= NULL;
		temp->next=head;
		head->prev=temp;
		head=temp;
		printf("\n Node Successfully Inserted at the start of the Doubly LinkedList");
	}
}

//  Function for inserting a Node at the end of the doubly Linked List

void insert_node_at_end(int x)
{
	if (head == NULL)
	{
		struct Node *temp= (struct Node *)malloc (sizeof(struct Node));
		temp->data=x;
		temp->next= NULL;
		temp->prev= NULL;
		head=temp;
		printf("\n Node Successfully Inserted at the End of the Doubly LinkedList ");
	}

	else
	{
		struct Node *iter =head;
		while (iter->next != NULL)
		{
			iter=iter->next;
		}

		struct Node *temp= (struct Node *)malloc(sizeof(struct Node));
		temp->data=x;
		temp->next=NULL;
		temp->prev=iter;
		iter->next=temp;
		printf("\n Node Successfully Inserted at the End of the Doubly LinkedList ");
	}
}

//  Function for inserting a node at the nth position

void insert_node_at_nth_position (int x, int y)
{
	int i;
	struct Node *iter = head;
	for (i=0; i<y-2; i++)
	{
		if (iter == NULL)
		{
			printf("\n There is a problem with the entered Position !!!! Exiting !!!");
			return;
		}

		iter = iter->next;
	}

	struct Node *temp= (struct Node *)malloc(sizeof(struct Node));
	temp->data= x;
	temp->next=iter->next;
	temp->prev=iter;
	iter->next=temp;
	iter= (iter->next)->next;
	iter->prev=temp;
	printf("\n Node successfully Inserted at posiiton number: %d", y);

}


// Function for printing all the elements of a Doubly LinkedList

void print()
{
	if (head == NULL)
	{
		printf("\n The Doubly LinkedList is Empty !!!!!");
		return;
	}

	else
	{
		struct Node *iter =head;
		printf("\n The Elements of the Doubly LinkedList are: ");
		while (iter != NULL)
		{
			printf(" %d",iter->data);
			iter=iter->next;
		}
	}
}


//  Function for printing all the elemenst of the Doubly LinkedList in Reverse Order

void print_reverse()
{
	if (head == NULL)
	{
		printf("\n The Doubly LinkedList is Empty !!!!!");
		return;
	}

	else
	{
		struct Node *iter= head;
		while(iter ->next != NULL)
		{
			iter=iter->next;
		}

		printf("\n The Elements in Reverse are : ");
		while (iter != NULL)
		{
			printf(" %d",iter->data);
			iter= iter->prev;
		}
	}
}


//  Function for deleting a node from the front of the Doubly LinkedList

void delete_node_from_start()
{
	if (head == NULL)
	{
		printf("\n The Doubly LinkedList is already Empty !!!!");
		return;
	}

	else
	{
		struct Node *iter = head;
		struct Node *iter1= head;
		iter=iter->next;
		head=iter;
		head -> prev= NULL;
		free(iter1);
		printf("\n  First Node Successfully Deleted !!!!!");
	}
}



//  Function for deleting a node from the end of the LinkedList 

void delete_node_from_end()
{
	if (head == NULL)
	{
		printf("\n The Doubly LinkedList is already Empty !!!!!");
		return;
	}

	else
	{
		struct Node *iter =head;
		struct Node *iter1= head;
		iter = iter ->next;
		while (iter->next != NULL)
		{
			iter= iter->next;
			iter1= iter1->next;
		}

		iter1 -> next = NULL;
		free(iter);

		printf("\n Node Successfully deleted from the end if the Doubly LinkedList");
	}
}


// Function for deleting a node at the nth position

void delete_node_from_nth_position (int x)
{
	int i;
	if (head == NULL)
	{
		printf("\n The Doubly LinkedList is already Empty !!!!");
		return;
	}

	else
	{
		struct Node *iter=head;
		for (i=0; i<x-1; i++)
		{
			if (iter == NULL)
			{
				printf("\n The position given does not exist !!! Exiting !!!!");
				return;
			}

			iter= iter->next;
		}

		struct Node *iter1= iter->prev;
		struct Node *iter2= iter->next;

		iter1->next=iter2;
		iter2->prev=iter1;
		free (iter);
		printf("\n Node Successfully deleted from position number: %d", x);
	}
}


int main()
{
	insert_node_at_start(4);
	insert_node_at_start(3);
	insert_node_at_end(5);
	insert_node_at_nth_position(6,3);
	print();
	print_reverse();
	delete_node_from_start();
	print();
	delete_node_from_end();
	print();
	delete_node_from_nth_position(3);
	print();
	return 0;


}

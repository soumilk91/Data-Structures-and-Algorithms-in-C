/*
The program demonstrates the working of  Singly LinkedList in 'C'
*/

# include <stdio.h>
# include <stdlib.h>

// Node containing 2 elements, data and the next pointer.
struct Node
{
	int data;
	struct Node *next;
} ;

// head pointer for the linkedlist equal to NULL at the start
struct Node *head = NULL;


// Function for inserting a node at the begining of the Linked List.
void insert_node_at_start(int x)
{
	if (head == NULL)
	{
		struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
		temp->data = x;
		temp->next= NULL;
		head=temp;
		printf("\n Node inserted successfully at the begining of the LinkedList");
	}

	else
	{
		struct Node *temp= (struct Node*) malloc(sizeof(struct Node));
		temp->data= x;
		temp->next=head;
		head=temp;
		printf("\n Node inserted successfully at the begining of the LinkedList");
	}
}


// Function for inserting a node at the end of the LinkedList.
void insert_node_at_end(int x)
{
	if (head == NULL)
	{
		struct Node * temp= (struct Node* )malloc(sizeof(struct Node));
		temp->data= x;
		temp->next=NULL;
		head=temp;
		printf("\n Node successfully inserted at the End of the LinkedList");
	}

	else
	{
		// Pointer for iterating through the entire linkedlist and reaching the last node where we can insert the new node
		struct Node *iter = head;
		while (iter -> next != NULL)
		{
			iter= iter->next ;
		}

		struct Node *temp= (struct Node *)malloc(sizeof(struct Node));
		temp->data=x;
		temp->next= NULL;
		iter->next= temp;
		printf("\nNode successfully inserted at the End !!!");
	}
}


// Function for inserting a node at a Specific position in the LinkedList.

void insert_node_at_nth_position(int x, int y)
{
	if (y ==1)
	{
		struct Node * temp= (struct Node *) malloc (sizeof(struct Node));
		temp->data=x;
		temp->next=head;
		head=temp;
		printf("\n Node inserted successfully at %dth position",y);
		return;
	}
	int i;
	// structure pointer to the head node
	struct Node * iter= head;
	for (i=0; i<y-2; i++)
	{
		if (iter == NULL)
		{
			printf("\n Position Not Valid !!!" );
			return;
		}
		iter= iter->next;
	}

	struct Node *temp= (struct Node *)malloc(sizeof(struct Node));
	temp->data=x;
	temp->next = iter->next;
	iter->next = temp;
	printf("\n Node inserted successfully at the %d th Position",y);
}


// Function for printing all the elements in a LinkedList.

void print()
{
	struct Node *temp=head;
	if (temp == NULL)
	{
		printf("\n The LinkedList is Empty !!!!!");
	}
	else
	{
		printf("\n The elements of the LinkedList are: ");
		while (temp != NULL)
		{
			printf("\t%d", temp->data);
			temp=temp->next;
		}
	}
}


// function to delete a Node at the begining of the LinkedList

void delete_node_at_start()
{
	struct Node *temp= head;
	struct Node *temp1= head;
	if (temp == NULL)
	{
		printf("\nLinkedList is empty !!!!");
	}
	else
	{
		temp= temp-> next;
		head=temp;
		free (temp1);
		printf("\n The first node in the LinkedList has been Deleted !!!");
	}
}

// Function to delete a Node at the end of the LinkedList

void delete_node_at_end()
{
	struct Node *temp= head-> next;
	struct Node *temp1= head;

	if (temp == NULL)
	{
		printf("\n LinkedList is empty !!!");
	}

	else
	{
		while(temp -> next != NULL)
		{
			temp= temp-> next;
			temp1= temp1 -> next;
		}
		temp1-> next= NULL;
		free (temp);
		printf("\n Last node has been Deleted !!!");
	}
}

// Function to Delete a node at the Nth Position.

void delete_node_at_nth_poistion(int y)
{
	
	struct Node *temp= head;
	struct Node *temp1= head -> next;
	if (y == 1)
	{
		head=temp1;
		free(temp);
		return;
	}
	if (temp == NULL)
	{
		printf("\n The LinkedList is Empty !!!");
	}

	else
	{
		int i;
		for (i=0; i< y-2; i++)
		{
			if (temp == NULL)
			{
				printf("\n No Node Present at the given position !!!");
			}
			temp= temp->next;
			temp1= temp1->next;
		}

		temp->next = temp1 -> next;
		free (temp1);
	}
}

// Function for Reversing the LinkedList

void reverse_linkedlist()
{
	struct Node *current = head;
	struct Node *prev = NULL;
	struct Node *nex = head;
	if (current == NULL)
	{
		printf("\n The LinkedList is empty !!!");
		return;
	}

	else
	{
		while (current != NULL)
		{
			nex = current -> next;
			current -> next = prev;
			prev = current;
			current = nex;
		}
		head= prev;
	}

}


// Now lets write the driver program

int main()
{
	insert_node_at_end(7);
    insert_node_at_start(5);
    insert_node_at_start(6);
    insert_node_at_end(4);
    insert_node_at_nth_position(10,5);
    print();
    delete_node_at_start();
    print();
    delete_node_at_end();
    print();
    delete_node_at_nth_poistion(1);
    print();
    insert_node_at_end(10);
    insert_node_at_start(5);
    print();
    reverse_linkedlist();
    print();
	return 0;
}


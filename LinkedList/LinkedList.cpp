#include<stdio.h>

struct node
{
	int item;
	struct node *next;
};

void init(struct node **head, int *count);
void insert(struct node **head, int item, int index, int *count);
void del(struct node **head, int index, int *count);
bool isEmpty(struct node **head);
void printList(struct node **head);
void destroyList(struct node **head, int *count);
void removeDuplicate(struct node **head, int *count);
void copyList(struct node *head1, int count1, struct node **head2, int *count2);

int main()
{
	struct node *head1;
	int count1;
	init(&head1, &count1);
	printf("%d",count1);
	
}

void init(struct node **head, int *count)
{
	*head = NULL;
	*count = 1;
}

void insert(struct node **head, int item, int index, int *count)
{
	if(index >= 0 && index<=(*count)){
		struct node *newNode = (struct node *) malloc(sizeof(struct node));	
		newNode->item = item;
		newNode->next = NULL;
		if(index == 0)
		{
			newNode->next = *head;
			*head = newNode;	
		}
		else
		{
			struct node *cur = *head;
			for(int i=0; i<pos; i++) cur = cur->next;
			newNode->next = cur->next;
			cur->next = newNode;
		}
	}
}





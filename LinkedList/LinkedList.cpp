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
	
}





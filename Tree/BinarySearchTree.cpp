#include<iostream>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

void init(struct node **root);
struct node* find(int data, struct node *root);
void insert(int data, struct node **root);
void NoLR(struct node *root);
void del(int data, struct node *root);

int main()
{
	struct node *tree;
	
	init(&tree);
	insert(10, &tree);
	insert(20, &tree);
	insert(5, &tree);
	insert(0, &tree);
	insert(99, &tree);
	insert(4, &tree);
	insert(6, &tree);
	insert(50, &tree);
	insert(100, &tree);
	insert(7, &tree);
	insert(8, &tree);
	
	NoLR(tree);


}



void init(struct node **root)
{
	*root = NULL;
}

struct node* find(int data, struct node *root)
{
	if(root == NULL) return NULL;
	else if(root->data > data) return find(data, root->left);
	else if(root->data < data) return find(data, root->right);
	else if(root->data = data) return root;
}

void insert(int data, struct node **root)
{
	if((*root) == NULL)
	{
		(*root) = (struct node *) malloc (sizeof(struct node));
		(*root)->data = data;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else if((*root)->data > data)
	{
		insert(data, &((*root)->left));	
	}
	else if((*root)->data < data)
	{
		insert(data, &((*root)->right));
	}
	else if((*root)->data = data)
	{
		printf("Data already in tree!\n");
	}
}

void del(int data, struct node *root)
{
		
}

void NoLR(struct node *root)
{
	if(root != NULL)
	{
		printf("%d ", root->data);
		NoLR(root->left);
		NoLR(root->right);
	}
}

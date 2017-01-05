#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *left;
	struct node *right;
};

void init(struct node **root);
struct node* find(int data, struct node *root);
void insert(int data, struct node **root);
void LRNo(struct node *root);
void LNoR(struct node *root);
void NoLR(struct node *root);
void del(int data, struct node **root);

bool findNodePath(struct node *root, int x, stack<struct node*> &st);
struct node * findMax(struct node *root);
struct node * find(int data, struct node *root);
struct node * findParent(int data, struct node *root);

int countNode(struct node *root);
int countLeafNode(struct node *root);
int treeHeight(struct node *root);
void destroyTree(struct node **root);
void printLessThan(struct node *root, int x);
int findNodeLevel(struct node *root, int x, int &level);
int countNodes(struct node *root, int level, int curLevel);
void bft(struct node *root);

int sumOddNode(struct node *root);
int sumOddNode(struct node *root)
{
	if(root != NULL)
	{
		int retVal = 0;
		if(root->data % 2 == 1) retVal = root->data;
		return retVal + sumOddNode(root->left) + sumOddNode(root->right);
	}else return 0;
}

void delOdd(struct node **root)
{
	if(*root != NULL)
	{
		delOdd(&(*root)->left);
		delOdd(&(*root)->right);
		if((*root)->data % 2 == 1 && !(*root)->left && !(*root)->right)
		{
			struct node *tmp = (*root);
			(*root) = NULL;
			free(tmp);
		}
	}
}
int main()
{
	struct node *tree;
	stack<struct node *> path;
	init(&tree);
	insert(10, &tree);
	insert(20, &tree);
	insert(5, &tree);
	insert(0, &tree);
	insert(99, &tree);
	insert(3, &tree);
	insert(6, &tree);
//	insert(50, &tree);
	insert(101, &tree);
	insert(7, &tree);
//	insert(8, &tree);
	insert(-1, &tree);
//	printf("%d", findMax(tree)->data);
//	NoLR(tree);
	delOdd(&tree);
	NoLR(tree);
//	
//	printf("\n");
//	LNoR(tree);
//	printf("\n");
//	LRNo(tree);
//	printf("\n");
//	printf("Tong cac node le: %d \n", sumOddNode(tree));
//	printf("So node trong cay: %d\n", countNode(tree));
//	printf("So node la trong cay: %d\n", countLeafNode(tree));
//	printf("Chieu cao cay: %d\n", treeHeight(tree));
//	
//	printf("Cac node nho hon 100: ");printLessThan(tree, 100);
//	printf("\n");
//	
//	printf("Duong di tu root den node 100:");
//	findNodePath(tree, 50, path);
//	while(!path.empty())
//	{
//		cout<<path.top()->data<<" ";
//		path.pop();
//	}
//	cout<<endl;
//	
//	printf("Chieu cao cua node: ");
//	int nodeHeight = 1;
//	findNodeLevel(tree, 22, nodeHeight);
//	cout<<nodeHeight;
//	
//	cout<<endl;
//	
//	cout<<"So node o level 4: "<<countNodes(tree, 4 , 1);
//	cout<<endl;
//	
//	cout<<"BFS: "<<endl;
//	bft(tree);
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


struct node * findParent(int data, struct node *root)
{
	struct node *par = NULL, *child = root;
	
	if(root == NULL) return NULL;
	
	while(child!=NULL)
	{
		if(child->data > data)
		{
			par = child;
			child = child->left;
		}
		else if(child->data < data)
		{
			par = child;
			child = child->right;
		}
		else if(child->data == data)
		{
			return par;
		}
		else return NULL;
	}
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
	else if((*root)->data == data)
	{
		printf("Data already in tree!\n");
	}
}

void del(int data, struct node **root)
{
	if(*root == NULL) printf("Eo found anything");
	else if((*root)->data > data)
	{
		del(data, &((*root)->left));
	}
	else if((*root)->data < data)
	{
		del(data, &((*root)->right));
	}
	else // found node contain data DATA
	{
		if((*root)->left && (*root)->right)
		{
			struct node *temp;
			temp = findMax((*root)->left);
			(*root)->data = temp->data;
			del(temp->data, &((*root)->left));
		}
		else  //node la' hoac co 1 node con
		{
			struct node *temp = *root;
			if((*root)->left == NULL)
			{
				*root = (*root)->right;
			}
			else if((*root)->right == NULL)
			{
				*root = (*root)->left;
			}
			free(temp);
		}
	}
}

struct node * findMax(struct node *root)
{
	if(root->right != NULL) return findMax(root->right);
	else return root;
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

void LNoR(struct node *root)
{
	if(root != NULL)
	{
		LNoR(root->left);
		printf("%d ", root->data);
		LNoR(root->right);
	}
}

void LRNo(struct node *root)
{
	if(root != NULL)
	{
		LRNo(root->left);
		LRNo(root->right);
		printf("%d ", root->data);
	}
}



int countNode(struct node *root)
{
	if(root != NULL)
	{
		return countNode(root->left)+countNode(root->right)+1;
	}
}


int countLeafNode(struct node *root)
{
	if(root != NULL)
	{
		if(!root->left && !root->right) return 1;
		else return countLeafNode(root->left)+countLeafNode(root->right);	
	}
}

int treeHeight(struct node *root)
{
	if(root!=NULL)
	{
            if(treeHeight(root->left) > treeHeight(root->right)) return 1+treeHeight(root->left);
            else return 1+treeHeight(root->right);
	}
}

void destroyTree(struct node **root)
{
	if(*root != NULL)
	{
		destroyTree(&((*root)->left));
		destroyTree(&((*root)->right));
		free(*root);
	}
}


void printLessThan(struct node *root, int x)
{
	if(root != NULL)
	{
		if(root->data < x) printf("%d ", root->data);
		printLessThan(root->left, x);
		printLessThan(root->right, x);
	}
}

int findNodeLevel(struct node *root, int x, int &level)
{
	if(root != NULL){
		if(root->data == x) return 1;
		level+=1;
		if(root->data > x) findNodeLevel(root->left, x, level);
		else findNodeLevel(root->right, x, level);
	} else return 0;
}


bool findNodePath(struct node *root, int x, stack<struct node*> &st)
{
	if(root != NULL){
		st.push(root);
		if(root->data == x) return true;
		if(findNodePath(root->left, x, st) || findNodePath(root->right, x, st)) return true;
		st.pop();
		return false;
	} else{
		return false;	
	} 
}


int countNodes(struct node *root, int level, int curLevel)
{
	if(root != NULL)
	{
//		cout<<level<<" "<<curLevel<<endl;
		if(level ==  curLevel) return 1;
		else return countNodes(root->left, level, curLevel+1) + countNodes(root->right, level, curLevel +1);
	}
}

void bft(struct node *root)
{
	queue<struct node* > q;
	struct node * cur = NULL;
	
	q.push(root);
	
	while(!q.empty())
	{
		cur = q.front();
		q.pop();
		cout<<cur->data<<" ";
		if(cur->left != NULL) q.push(cur->left);
		if(cur->right != NULL) q.push(cur->right);
	}
}

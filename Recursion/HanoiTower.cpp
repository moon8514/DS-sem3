#include<iostream>

using namespace std;

void move(int n, char A, char B, char C)
{
	if(n>0)
	{
		move(n-1, A, C, B);
		printf("Move %d from %c to %c\n", n, A, C);
		move(n-1, B, C, A);
	}
}

int main()
{
	int n = 3;
	move(n, 'A','B','C');
}

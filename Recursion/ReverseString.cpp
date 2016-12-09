#include<iostream>

using namespace std;

void reverseString(char *st, int n)
{
	if(n>0)
	{
		printf("%c", st[n-1]);
		reverseString(st, n-1);
	}
}

int main()
{
	char st[] = "abcdefghijklmnopqrstuvwxyz";
	reverseString(st, 26);
}

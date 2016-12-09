#include<iostream>

using namespace std;

int sumNumChar(int n)
{
	if(n/10 == 0) return n;
	else return sumNumChar(n/10)+n%10;
}

int main()
{
	int n=1234567;
	printf("%d", sumNumChar(n));
}

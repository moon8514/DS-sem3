#include<iostream>
using namespace std;


int power(int base, int n)
{
	if(n == 0) return 1;
	else return power(base, n-1)*base;
}


int main()
{
	int base = 2;
	int n = 10;
	
	printf("%d", power(2,10));
}

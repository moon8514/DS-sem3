#include<iostream>
using namespace std;

int sumArray(int *a, int n)
{
	if(n==0) return 0;
	else return sumArray(a, n-1)+a[n-1];	
}

int main()
{
	int a[] = {1,2,3,4,5,6};
	int n = 6;
	printf("%d", sumArray(a,n));
}

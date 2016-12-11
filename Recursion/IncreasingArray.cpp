#include<iostream>

using namespace std;

int increasingArr(int *a, int n)
{
	if(n==1) return 1;
	if(a[n]<a[n-1]) return 0;
	else return increasingArr(a,n-1);
}

int main()
{
	int a[] = {1,3,4,5,9,10,11};
	printf("%d", increasingArr(a,4));
}

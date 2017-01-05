#include<iostream>

using namespace std;

int increasingArr(int *a, int n)
{
	if(n==0) return 1;
	if(a[n-1]<a[n-2]) return 0;
	else return increasingArr(a,n-1);
}

int main()
{
	int a[] = {2,3,4,5,9,10,11};
	printf("%d", increasingArr(a,5));
}

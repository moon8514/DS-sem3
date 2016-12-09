#include<iostream>

using namespace std;

int minArrElem(int *a, int n)
{
	if(n==1) return a[0];
	else
	{
		if(a[n-1] < minArrElem(a,n-1)) return a[n-1];
		else return minArrElem(a,n-1);	
	}
	
}


int main()
{
	int a[] = {88,5,10,4,5,7};
	printf("%d", minArrElem(a,6));
}

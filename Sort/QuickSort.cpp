#include<iostream>

using namespace std;

void quickSort(int *a, int l, int r)
{
	int pivot, i ,j;
	pivot = a[(l+r)/2];
	i = l;
	j = r;
	
	while(i<j)
	{
		while(a[i]<pivot) i++;
		while(a[j]>pivot) j--;
		if(i<=j)
		{
			if(i<j){
				a[i]=a[i]^a[j];
				a[j]=a[i]^a[j];
				a[i]=a[i]^a[j];
			}
			i++;
			j--;
		}
	}
	if(i<r) quickSort(a,i,r);
	if(j>l) quickSort(a,l,j);
}

int main()
{
	int a[] = {1,5,3,2,7,9,4};
	quickSort(a, 0, 6);
	for(int i=0; i<7; i++) cout<<a[i]<<" ";

}

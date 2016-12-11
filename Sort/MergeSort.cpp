#include<iostream>

using namespace std;


void merge(int *a, int l, int mid, int r)
{
	int last1, last2;
	int i,j,k;
	int tempArr[r];//
	
	i = l;
	last1 = mid;
	
	j = mid+1;
	last2 = r;
	
	k = l;
	
	while((i<=last1) && (j<=last2))
	{
		if(a[i]<a[j])
		{
			tempArr[k] = a[i];
			i++;
			k++;
		}
		else
		{
			tempArr[k] = a[j];
			j++;
			k++;
		}
	}
	
	while(i<=last1)
	{
		tempArr[k] = a[i];
		i++;
		k++;
	}

	while(j<=last2)
	{
		tempArr[k] = a[j];
		j++;
		k++;
	}
	
	for(k=l;k<=r;k++)
	{
		a[k] = tempArr[k];	
	}
	return;
}


void mergeSort(int *a, int l, int r)
{
	if(l<r)
	{
		int mid = int((l+r)/2);
		mergeSort(a,l,mid);
		mergeSort(a,mid+1,r);	
		merge(a, l, mid, r);
	}	
}

int main()
{
	int a[] = {1,5,3,2,7,9,4};
	mergeSort(a, 0, 6);
	for(int i=0; i<7; i++) cout<<a[i]<<" ";
}

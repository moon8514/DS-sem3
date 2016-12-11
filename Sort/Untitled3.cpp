#include<iostream>

using namespace std;

void merge(int array[], int first, int middle, int last) {
    int temp[last];
    int first1, last1, first2, last2;
    int index = first;
        
    first1 = first;
    last1 = middle;
    first2 = middle+1;
    last2 = last;
        
    while((first1 <= last1) && (first2 <= last2)) {
        if(array[first1] < array[first2]) {
            temp[index] = array[first1];
            index ++;
            first1 ++;                  
        }
        else {
            temp[index] = array[first2];
                index ++;
                first2 ++;
        }
    }
     
//    if(first2 > last2) {
    while(first1 <= last1) {
        temp[index] = array[first1];
            index ++;
            first1 ++;
        }
//    }

//    if(first1 > last1) {
        while(first2 <= last2) {
             temp[index] = array[first2];
             index ++;
             first2 ++;
        }
//    }           
        
    for(index = first; index <= last; index ++) {
        array[index] = temp[index];
    }
        
    return;
}

void mergeSort(int array[], int first, int last) {
    if(first < last) {
        int middle = int((first + last) / 2);
        mergeSort(array, first, middle);
        mergeSort(array, middle + 1, last);
        merge(array, first, middle, last);
    }
}


int main()
{
	int a[] = {1,5,3,2,7,9,4};
	mergeSort(a, 0, 6);
	for(int i=0; i<7; i++) cout<<a[i]<<" ";
}

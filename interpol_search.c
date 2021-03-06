#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 9

int bin_search(int *arr, int lo, int hi, int srch);

int main(int argc, int* argv[]){
	int arr[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int tofind = 8;
	
	int res = bin_search(arr, 0, N, tofind);
	if(res == -1)
		printf("\n Failed to find item \n");
	else
		printf("\n Item found at index %d \n", res);	
}

int bin_search(int *arr, int lo, int hi, int srch){
	int pivot; 
	pivot = round(lo + ((hi-lo) / (arr[hi] - arr[lo])) * (srch - arr[lo])); 
	if((lo == hi || hi == lo + 1) && arr[lo] != srch)
		return -1;
	if(arr[pivot] == srch){
		return pivot;		
	} else if(srch < arr[pivot]){
		bin_search(arr, lo, pivot - 1, srch);
	}else if(srch > arr[pivot]){
		bin_search(arr, pivot + 1, hi, srch);
	}
}

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
		printf("Failed to find item");
	else
		printf("\n Item found at index %d \n", res);	
}

int bin_search(int *arr, int lo, int hi, int srch){
	int pivot = round(lo + (hi - lo)/2);
	if((lo == hi || hi == lo + 1) && arr[lo] != srch)
		return -1;
	if(arr[pivot] == srch){
		return pivot;		
	} else if(srch < arr[pivot]){
		bin_search(arr, lo, pivot, srch);
	}else if(srch > arr[pivot]){
		bin_search(arr, pivot, hi, srch);
	}
}

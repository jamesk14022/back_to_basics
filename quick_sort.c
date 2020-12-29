#include <stdlib.h>
#include <stdio.h>
# include <math.h>

int n = 4;
int in[] = {1, 7, 5, 8};

void quicksort(int arr[], int lo, int hi);
int partition(int arr[], int lo, int hi);

int main(int argc, char *arc[]){
	int k;
	
	quicksort(in, 0, n - 1);
	for(k = 0; k < n; k++){
		printf("%d \n", in[k]);
	}
}

void quicksort(int arr[], int lo, int hi){
	int p;
	if (lo < hi){
		p = partition(arr, lo, hi);
		quicksort(arr, lo, p - 1);
		quicksort(arr, p + 1, hi);
	}
}

int partition(int *arr, int lo, int hi){
	int j, pivot, i;
       	int temp; 	
	pivot = arr[hi];
	i = lo; 

	for(j = lo; j < hi; j++){
		if(arr[j] < pivot){
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
			i++;
		}
	}
	temp = arr[i]; 
	arr[i] = arr[hi];
	arr[hi] = temp;
	return i; 
}


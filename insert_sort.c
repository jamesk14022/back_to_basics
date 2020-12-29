#include <stdlib.h>
#include <stdio.h>

#define N 4

int in[N] = {1, 5, 3, 2};

void insert(int *arr, int len);
void swap(int *arr, int i, int j);

int main(int argc, char *argv[]){
	int y, z;
	for(z = 0; z < N; z++){
		insert(in, N);
	}
	for(y = 0; y < N; y++){
		printf("%d", in[y]);
	}
	
}

void insert(int *arr, int len){
	int i = 1;
	int j;
	while(i < len){
		j = i; 
		while(j > 0 && arr[j-1] > arr[j]){
			swap(arr, j, j-1);
			j--; 
		}	
		i++; 
	}
}

void swap(int *arr, int i, int j){
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

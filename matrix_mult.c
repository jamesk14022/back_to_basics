#include <stdlib.h>
#include <stdio.h>

#define N 3

void product(int arr1[][N], int arr2[][N], int out[][N]);
void print_matrix(int arr[][N], int len);

int main(int argc, char *arv[]){
	int arr1[N][N] = {
		{1, 2, 3},
		{1, 2, 3},
		{1, 2, 3}
	};

	int arr2[N][N] = {
		{4, 5, 6},
		{4, 5, 6},
		{4, 5, 6}
	};
	
	int (*out)[N] = malloc(sizeof(int[N][N]));
	if(out == NULL){
		printf("Bad news, output arr failed to alloc");
		return 0;
	}
	
	product(arr1, arr2, out);
	print_matrix(out, N);
	free(out);
	return 1;
}

void product(int arr1[][N], int arr2[][N], int out[][N]){
	int i, j, k;
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			out[i][j] = 0;
			for(k = 0; k < N; k++){
				out[i][j] += arr1[i][k] * arr2[k][j];
			}		
		}
	}
}

void print_matrix(int arr[][N], int len){
	int i, j;
	printf("\n");
	for(i = 0; i < len; i++){
		for(j = 0; j < len; j++){
			printf("|%d|", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


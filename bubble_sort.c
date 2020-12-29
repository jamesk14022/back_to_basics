# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

int in[] = {0, 2, 1, 6, 15, 3, 1, 2, 11, 2};
int n = 9;

int main(int argc, char *argv[]){
	bool swapped = false;
	bool trig = false;
	int i, j, s, temp;

	for(i = 0; i < n - 1; i++){
		for(j = 0; j < (n - i - 1); j++){
			if(in[j] > in[j+1]){
				temp = in[j];
				in[j] = in[j+1];
				in[j+1] = temp;
			}
		}
	}
	for(s = 0; s < n; s++){
		printf(" %d \n ", in[s]);
	}
}

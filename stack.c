# include <stdio.h>
# include <stdlib.h>


typedef struct node {
	int num;
	struct node *next;
} list_node;



int pop(list_node *root){
	while(root->next->next != NULL)
		root = root->next;
	int val = root->next->num;
	free(root->next);
	root->next = NULL;
	return val;
}

int peak(list_node *root){
	while(root->next != NULL)
		root = root->next;
	return root->num;
}

list_node* createnode(int num){
	list_node* newnode;
	newnode = malloc(sizeof(list_node));
	newnode->num = num;
	newnode->next = NULL;
	return newnode;
}

void push(list_node *root, int num){
	while(root->next != NULL)
		root = root->next;
	root->next = (list_node*)createnode(num);
}

void printstack(list_node *root){
	int i = 1; 
	while(root->next != NULL){
		printf("Stack element %d: %d \n", i, root->num);
		root = root->next;
		i++;
	}
	printf("Stack element %d: %d \n", i, root->num);
}

int main(int argc, int *argv[]){
	int len, i;
	
	list_node *root = (list_node*)createnode(0);
	int vals[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	len = sizeof(vals) / sizeof(vals[0]);
	for(i = 0; i<len; i++){
		push(root, vals[i]);
	}
	
	printf("Add element 0->9 to stack \n");

	printf("Peak at last element: %d \n", peak(root));
	
	printf("Pop last element: %d \n", pop(root));
	printf("Pop last element again: %d \n", pop(root));
	
	printf("Print remaining stack \n");
	printstack(root);
}

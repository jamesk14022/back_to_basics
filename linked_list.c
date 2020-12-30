# include <stdio.h>
# include <stdlib.h>

typedef struct node {
	int ind;
	struct node *next; 
} list_node;

int n = 5;
int data[] = {1, 2, 3, 4, 5};

void insert(list_node *h, int num);

int main(int argc, char *argv[]){
	list_node *root;
	root = malloc(sizeof(list_node));
       	root->ind = 0;
	root->next = NULL;

	for(int i = 0; i < n; i++){
		insert(root, data[i]);
	}

	while(root->next != NULL){
		printf("%d", root->ind);
		root = root->next;
	}
}
void insert(list_node *h, int num){
	list_node *tmp = h;
	while(tmp->next != NULL)
		tmp = tmp->next;
	
	list_node *newnode = malloc(sizeof(list_node));
	newnode->next = NULL;
	newnode->ind = num; 
	tmp->next = newnode;
}







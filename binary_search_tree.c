# include <stdio.h>
# include <stdlib.h>

typedef struct node {
	int ind;
	struct node *left;
	struct node *right;
} list_node;

list_node* createnode();
void insert(list_node *h, int num);
void printtree(list_node *root);

list_node* createnode(){
	list_node *tmp;
	tmp = (list_node*)malloc(sizeof(list_node));
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->ind = 0; 
	return tmp;
}

void printtree(list_node *node){
	if(node == NULL){
		return;
	}
	printtree(node->left);
	printf("| %d ", node->ind);
	printtree(node->right);
}

void insert(list_node *h, int num){
	if(h->ind == 0){
		h->ind = num;
	}else if(num < h->ind){
		if(h->left == 0)
			h->left = createnode();
		insert(h->left, num);
	}else if(num > h->ind){
		if(h->right == 0)
			h->right = createnode();
		insert(h->right, num);
	}else if(num == h->ind){
		printf("Element already inserted into tree");
	}
}

int main(int argc, char *argv[]){
	list_node *root = createnode();
	insert(root, 3);
	insert(root, 6);
	insert(root, 1);

	printtree(root);
}

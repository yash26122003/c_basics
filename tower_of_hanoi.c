#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node* left;
	int value;
	struct node* right;
};

struct node* root = NULL;

struct node* createnode(int v){
	struct node* ptr;
	ptr=(struct node*)malloc(sizeof(struct node*));
	ptr->left=NULL;
	ptr->right=NULL;
	ptr->value=v; 
	return ptr;
}

void preorder(struct node* t){
	if(t!=NULL){
		printf("%d\t",t->value);
		preorder(t->left);
		preorder(t->right);
	}
}
void inorder(struct node* t){
	if(t!=NULL){
		
		inorder(t->left);
		printf("%d\t",t->value);
		inorder(t->right);
	}
}
void postorder(struct node* t){
	if(t!=NULL){
		
		postorder(t->left);
		postorder(t->right);
		printf("%d\t",t->value);
	}
}

void addnode(struct node *t, int x){
	//left check
	if(x%2==0){
		if(t->left==NULL){
			t->left=createnode(x);
		}
		else{
			addnode(t->left,x);
			
		}
	}
	else{
		if(t->right==NULL){
			t->right=createnode(x);
		}
		else{
			addnode(t->right,x);
			
		}
	}
}

int main(){
	int i;
	int a[5]={6,8,9,7,5};
	for(int x=0;x<5;x++){
		if(root==NULL){
			root=createnode(a[i]);
		}
		else{
			addnode(root,a[i]);
		}
	}
	inorder(root);
	printf("\n");
	postorder(root);
	return NULL;
}

#include<stdio.h>

#include<stdlib.h>
struct node{
	int pow;
	int coeff;
	struct node* next;
};

void addnode(int coeff,int pow ,struct node* head){
	struct node* ptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	if(ptr==NULL){
		printf("no allocation");
	}
	
	if(head==NULL){
		ptr->pow = pow;
		ptr->coeff = coeff;
		ptr->next=NULL;
		head=ptr;
		
	}
	else{
		while(head->next!=NULL){
			head=head->next;
		}
		ptr->pow = pow;
		ptr->coeff = coeff;
		ptr->next=NULL;
		head->next = ptr;
		
	}
}

void printlist(struct node* top){
	if (top==NULL){
		printf("nothing");
	}
	else{
		printf("%d%d",top->coeff,top->pow);
		while(top!=NULL){
			top=top->next;
			printf("%d,%d",top->coeff,top->pow);
		}
	}
}

int main(){
	
	struct node * top = NULL;
    struct node * b = NULL;
    
	addnode(5,3,top);
	addnode(4,1,top);
	addnode(2,0,top);
	printlist(top);
	

	addnode(3,4,b);
	addnode(2,2,b);
	addnode(5,1,b);
	printlist(b);
	

	return 0;
}

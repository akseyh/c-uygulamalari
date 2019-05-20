#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct n{
	int data;
	n * next;
};

typedef n node;
node* push(node *r, int x);
node* pop(node *r, int x);
void show(node * r);

int main(){
	node * root;
	root = NULL;
	
	int choise, data;
	start:
	printf("1-Add data.\n2-Delete data.\n3-Show node.\nChoosen: ");
	choise = getch();
	printf("%c\n", choise);
	switch(choise){
		case '1':
			printf("Please enter data: ");
			scanf("%d", &data);
			root = push(root, data);
			break;
		case '2':
			printf("Please enter data: ");
			scanf("%d", &data);
			root = pop(root, data);
			break;
		case '3':
			show(root);
			break;
		default:
			printf("It's not a choise.\n");
			break;
	}
	printf("Please enter for continue.");
	getch();
	system("CLS");
	goto start;
	return 0;
}

node* push(node *r, int x){
	if(r == NULL){
		r = (node *)malloc(sizeof(node));
		r->data = x;
		r->next = NULL;
		printf("%d is pushed to node.\n", x);
		return r;
	}
	if(r->data > x){
		node * temp = (node *)malloc(sizeof(node));
		temp->data = x;
		temp->next = r;	
		r = temp;
		printf("%d is pushed to node.\n", x);
		return r;
	}
	
	node * iter;
	iter = r;
	while(iter->next != NULL && iter->next->data < x){
		iter = iter->next;
	}
	node * temp = (node *)malloc(sizeof(node));
	temp->next = iter->next;
	iter->next = temp;
	temp->data = x;
	printf("%d is pushed to node.\n", x);
	return r;
}

void show(node * r){
	if(r == NULL){
		printf("This node is empty.\n");
		return;
	}
	node * iter = r;
	while(iter != NULL){
		printf("%d\n",iter->data);
		iter = iter->next;
	}
}

node* pop(node *r, int x){
	node * iter = r;
	if(iter == NULL){
		printf("This node is empty.\n");
		return r;
	}
	if(iter->next == NULL){
		node *temp = r;
		r = NULL;
		free(temp);
		printf("%d is deleted.\n", x);
		return r;
	}
	while(iter->next != NULL){
		if(r->data == x){
			node * temp = r;
			r = r->next;
			free(temp);
			printf("%d is deleted.\n", x);
			return r;
		}
		if(iter->next->data == x){
			node* temp = iter->next;
			iter->next = iter->next->next;
			free(temp);
			printf("%d is deleted.\n", x);
			return r;
		} 
		iter = iter->next;
	}
	printf("%d  is haven't in this node.\n", x);
	return r;
}

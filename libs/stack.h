#ifndef __STACK__CUSTOM__
#define __STACK__CUSTOM__
#include"stdio.h"
#include"stdlib.h"

typedef struct __stack{
	int data;
	struct __stack *next;
}Stack;
Stack* new_node(int);
void __free_stack(Stack*);
void push(Stack*,int);
int is_empty(Stack*);	//THIS FUNCTION MUST BE CALLED UPON THE STACK OBJECT 
						//CALLING THE FUNCTION pop and get_top
int pop(Stack*);
int get_top(Stack*);


Stack* new_node(int data){
	Stack *obj=(Stack*)malloc(sizeof(Stack));
	obj->data=data;
	obj->next=NULL;
	return obj;
}
void __free_stack(Stack *obj){
	Stack *cur=obj;
	if(obj->next)
		__free_stack(obj->next);
	free(obj);
}

void push(Stack *obj,int data){
	Stack *_new = new_node(data);
	_new->next=obj->next;
	obj->next=_new;
}

int is_empty(Stack *obj){
	if(obj->next)
		return 0;
	return 1;
}


/*
	THE is_empty FUNCTION MUST BE CALLED UPON THE STACK OBJECT BEFORE
	CALLING THE pop.
*/ 
int pop(Stack *obj){
	if(obj->next){
		Stack *cur=obj->next;
		int data = cur->data;
		obj->next=cur->next;
		free(cur);
		return data;
	}
	printf("The stack is empty\n");
}

/*
	THE is_empty FUNCTION SHOULD BE CALLED UPON THE STACK OBJECT BEFORE 
	CALLING get_top
*/
int get_top(Stack *obj){
	return obj->next->data;
}

void print_stack(Stack *obj){
	Stack *cur=obj->next;
	while(cur){
		printf("%c\n", cur->data);
		cur=cur->next;
	}
}
int len_stack(Stack *obj){
	int len=0;
	Stack *cur=obj->next;
	while(cur &&(len+=1))cur=cur->next;
	return len;
}
#endif
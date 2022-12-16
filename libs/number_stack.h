#ifndef __NUMBER_STACK__
#define __NUMBER_STACK__
#include"stdio.h"
#include"stdlib.h"


typedef struct __number_stack{
	double data;
	struct __number_stack *next;
}NumStack;
NumStack* num_stack_new(double);
void __free_num_stack(NumStack*);
void num_stack_push(NumStack*,double);
double num_stack_pop(NumStack*);

NumStack* num_stack_new(double data){
	NumStack *obj=(NumStack*)malloc(sizeof(NumStack));
	obj->data=data;
	obj->next=NULL;
	return obj;
}

void __free_num_stack(NumStack *obj){
	NumStack *cur=obj;
	if(obj->next)
		__free_num_stack(obj->next);
	free(obj);
}

void num_stack_push(NumStack *obj,double data){
	NumStack *_new = num_stack_new(data);
	_new->next=obj->next;
	obj->next=_new;
}



/*
	THE is_empty FUNCTION from stack.h MUST BE CALLED UPON THE STACK OBJECT BEFORE
	CALLING THE pop.
*/ 
double num_stack_pop(NumStack *obj){
	double data=obj->next->data;
	NumStack *cur=obj->next;
	obj->next = cur->next;
	free(cur);
	return data;
}

void print_num_stack(NumStack* obj){
	NumStack *cur=obj->next;
	while(cur){
		printf("%.3lf\n", cur->data);
		cur=cur->next;
	}
}
/*
	THE is_empty FUNCTION MUST BE CALLED UPON THE STACK OBJECT BEFORE 
	CALLING get_top
*/
#endif
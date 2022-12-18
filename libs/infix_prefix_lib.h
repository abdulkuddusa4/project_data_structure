#ifndef __INFIX_PREFIX_LIB__
#define __INFIX_PREFIX_LIB__
#include"stdio.h"
#include "utils.h"
#include "stack.h"

int get_precedence(char ch){
	switch(ch){
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
	}
}

int is_opcode(char ch){
	switch(ch){
	case '+':
	case '-':
	case '*':
	case '/':
	case '^':
	return 1;
	return 0;
	}
}

int is_valid_token(char ch){
	switch(ch){
	case '+':
	case '-':
	case '*':
	case '/':
	case '^':
	case '(':
	case ')':
	return 1;
	}
	if(ch>='0' && ch<='9')return 1;
	return 0;

}

int is_valid_exp(char *st){
	int brckt=0;
	for(int i=0;st[i]!=0;i++){
		// printf("%d: %d #",st[i],is_valid_token(st[i]));
		if(!is_valid_token(st[i])){
			return 0;
		}
		if(st[i]=='(')brckt++;
		else if(st[i]==')')brckt--;


		if (is_opcode(st[i]))
		{
			if(i==0 || st[i+1]==0){
				return 0;
			}
			else if(st[i-1]=='(' || st[i+1] == ')') {
				return 0;
			}
		}
	}
	if(brckt)return 0;
	return 1;
}

NumsandExp infix_prefix(char *st){
	NumsandExp obj=fetch_numbers_and_exp(st);
	Stack *prefix = new_node(-33424);
	Stack *exp=obj.exp;
	Stack *ops=new_node(-23434);
	// print_stack(exp);
	// print_stack(exp);
	// printf("while loop: \n");
	// while(!is_empty(exp))pop(exp);
	// exit(0);
	// printf("entering\n");
	while(!is_empty(exp)){
		char ch=pop(exp);
		// printf("%c\n",ch);
		if(ch == '$')
			push(prefix,'$');
		else if(ch==')')
			push(ops,')');
		else if(ch=='('){
			// printf("<--\n");
			int tmp = pop(ops);
			while(tmp!=')' ){
				// printf("('sdf')\n");
				push(prefix,tmp);
				// if(is_empty(ops))
				// 	break;
				tmp=pop(ops);
			}
		}
		else{
			if(is_empty(ops))
				push(ops,ch);
			else if(get_precedence(ch)>=get_precedence(get_top(ops)))
				push(ops,ch);
			else{
				while(!is_empty(ops) && get_top(ops) !=')' && get_precedence(ch)<get_precedence(get_top(ops)))
					push(prefix,pop(ops));
				push(ops,ch);
			}
		}
	}
	while(!is_empty(ops))
		push(prefix,pop(ops));

	while(!is_empty(prefix))push(obj.exp,pop(prefix));
	return obj;
}

double eval(char *st){
	NumsandExp obj=infix_prefix(st);
	NumStack *await_numbers=num_stack_new(-2343);
	while(!is_empty(obj.exp)){
		char ch=pop(obj.exp);
		if(ch=='$')
			num_stack_push(await_numbers,num_stack_pop(obj.nums));
		else
			num_stack_push(await_numbers,calc(
				ch,num_stack_pop(await_numbers),num_stack_pop(await_numbers)
				)
			);
	}
	return num_stack_pop(await_numbers);
}

#endif
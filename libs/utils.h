#ifndef __UTILS_FOR_INFIX_PREFIX_CONVERSION__
#define __UTILS_FOR_INFIX_PREFIX_CONVERSION__
#include "stack.h"
#include "number_stack.h"
// #include "infix_prefix_lib.h"
#include "math.h"

typedef struct {
	Stack *exp;
	NumStack *nums;
}NumsandExp;

void func(){
	printf("%lf\n", pow(10,6));
}
double convert_to_num(char *st,int s,int m,int e){
	double number=0.0;
	int p_up =(m>-1?m:e)-s-(m>-1)?1:0;
	int p_low = (m>-1)?m-e:0;
	for(int p=p_up,i=s;p>=p_low;i++){
		if(st[i]=='.')
			continue;
		else{
			number+=(st[i]-48)*pow(10,p);
			p--;
		}
	}
	return number;
}

NumsandExp fetch_numbers_and_exp(char *st){
	NumStack *nums = num_stack_new(-12323);
	Stack *infix = new_node(-2324);
	for(int i=0,start=-1,mid=-1;;i++){
		if(st[i]==0){
			if(start>-1){
				num_stack_push(nums,convert_to_num(st,start,mid,i-1));
				push(infix,'$');
			}
			break;
		}
		if(st[i]>='0'&&st[i]<='9'){
			if(start<0){
				start=i;
				// printf("**->%d  %d\n", start,i);
			}
		}
		else if(st[i]=='.')
			mid=mid<0?i:mid;
		else{
			if(start>-1){
				num_stack_push(nums,convert_to_num(st,start,mid,i-1));
				push(infix,'$');
				start=mid=-1;
			}
			push(infix,st[i]);
		}
	}
	NumsandExp obj;
	obj.exp=infix;
	obj.nums=nums;
	return obj;
}

double calc(char ch,double a,double b){
	switch(ch){
		case '+':return a+b;
		case '-':return b-1;
		case '/':return b/a;
		case '*':return b*a;
		case '^':return pow(b,a);
	}
}

// double eval(char *st){
// 	NumsandExp obj=infix_prefix(st);
// 	// NumStack *await_numbers=num_stack_new(-2343);
// 	// while(!is_empty(obj.exp)){
// 	// 	char ch=pop(obj.exp);
// 	// 	if(ch=='$')
// 	// 		num_stack_push(await_numbers,num_stack_pop(obj.nums));
// 	// 	else
// 	// 		num_stack_push(await_numbers,calc(ch,pop(await_numbers),pop(await_numbers)));
// 	// }
// 	// return
// }
#endif
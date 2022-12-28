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
// "(284.265+7)*(6+234)"

//TAKES A STRING AND START FLOATING POINT AND END POINT OF A NUMBER FROM THAT 
//STRING AND COVERT IT TO A DOUBLE POINT NUMBER.
double convert_to_num(char *st,int s,int m,int e){
	double number=0.0;
	int p_up =(m>-1)?m-s-1:e-s;
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


#endif
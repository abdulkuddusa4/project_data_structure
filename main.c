#include"stdio.h"
#include"libs/infix_prefix_lib.h"
#include"math.h"
#include"string.h"
#include"gtk/gtk.h"
#include"ui/__app__.h"
void parse_cmdl_args(int,char**);

int main(int argc, char **argv){
	parse_cmdl_args(argc, argv);
}

void parse_cmdl_args(int n,char **argv){
	if(n==2 && !strncmp(argv[1],"--runapp",8)){
		run_app(n,argv);
	}
	else if (n==3 && !strncmp(argv[1],"--evl",5)){
		if(!is_valid_exp(argv[2])){printf("INVALID EXPRESSION\n");return;}
		printf("%.3lf\n", eval(argv[2]));
	}
	else printf("INVALID COMMAND\n");
}

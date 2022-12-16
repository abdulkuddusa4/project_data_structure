#include"stdio.h"
// #include"libs/utils.h"
// #include"libs/utils.h"
#include"libs/infix_prefix_lib.h"
#include"math.h"
#include"string.h"
#include"gtk/gtk.h"
void parse_cmdl_args(int,char**);

int main(int argc, char **argv){
	parse_cmdl_args(argc, argv);
//	printf("%.2lf",eval("12+13*(6+2)"));
}

void parse_cmdl_args(int n,char **argv){
	if(n==2 && !strncmp(argv[1],"--runapp",8)){
		printf("application is not available now :( sorry !\n");
	}
	else if (n==3 && !strncmp(argv[1],"--evl",5)){
		printf("%.3lf\n", eval(argv[2]));
	}
	else printf("INVALID COMMAND\n");
}

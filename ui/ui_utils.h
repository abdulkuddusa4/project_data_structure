#ifndef _GU_UTILS_
#define _GU_UTILS_
#include"gtk/gtk.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"../libs/infix_prefix_lib.h"
void close_app(GtkWidget *widget,gpointer data){
	gtk_main_quit();
}
void _evaluate(GtkWidget *widget,GtkWidget *obj){
	const char *exp = gtk_entry_get_text(GTK_ENTRY(obj));
	char *exp_st = strdup(exp);
	char buffer[60] = {0};

	if(!is_valid_exp(exp_st)){
		// printf("sdf");
		gtk_entry_set_text(GTK_ENTRY(obj),"INVALID EXPRESSION");
		return;
	}
	double result = eval(exp_st);
	snprintf(buffer,59,"=%.2lf",result);
	gtk_entry_set_text(GTK_ENTRY(obj),buffer);
}
#endif
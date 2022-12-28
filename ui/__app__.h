#ifndef _APPLICATION_UI_
#define _APPLICATION_UI_

#include"ui_utils.h"
#include"gtk/gtk.h"

int run_app(int argc, char **argv){
	GtkWidget *window,*button, *text_area,*hbox;
	gtk_init(&argc, &argv);

	hbox = gtk_box_new(FALSE ,0);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	button = gtk_button_new_with_label("CALC");
	text_area=gtk_entry_new();

	// ALL THE CALLBACKS ARE CONNECTED HERE
	g_signal_connect(window,"destroy",G_CALLBACK(close_app),NULL);
	g_signal_connect(button,"clicked",G_CALLBACK(_evaluate),text_area);
	//
	gtk_container_add (GTK_CONTAINER (window), hbox);
	gtk_container_set_border_width(GTK_CONTAINER(window),200);
	gtk_entry_set_placeholder_text(GTK_ENTRY(text_area),"expr");
	gtk_box_pack_start(GTK_BOX(hbox),text_area,TRUE,TRUE,0);
	gtk_box_pack_start(GTK_BOX(hbox),button,TRUE,TRUE,0);	

	gtk_widget_show_all(window);
	gtk_main();
}

#endif
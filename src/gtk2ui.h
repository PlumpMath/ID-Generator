#ifndef _GTK2_UI_H
#define _GTK2_UI_H 

#include <gtk/gtk.h>

GtkWidget *cbox_sex; 
GtkWidget *cbox_area;
GtkWidget *lineEdit; 
GtkWidget *label_id; 
GtkWidget *label_sex;
GtkWidget *label_area;
GtkWidget *btn_check;
GtkWidget *btn_gen;  
GtkWidget *vbox;     
GtkWidget *hbox1;    
GtkWidget *hbox2;    
GtkWidget *MainWindow;

// public method
void setupUi(GtkWidget *window);


#endif /* _GTK2_UI_H */


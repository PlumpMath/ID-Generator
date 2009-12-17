#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "gtk2ui.h"


int main( int argc, char **argv )
{
        GtkWidget *window;      /* Main Window */

        gtk_init( &argc, &argv );

        window = gtk_window_new( GTK_WINDOW_TOPLEVEL );        

        setupMainFrame( window );
        
        gtk_widget_show_all( window );

        gtk_main();

        return 0;
}





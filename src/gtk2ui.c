#include "gtk2ui.h"
#include "idgen.h"

/* Global Variables */
static GtkWidget *lineEdit; 
static GtkWidget *label_id; 
static GtkWidget *label_sex;
static GtkWidget *label_area;
static GtkWidget *btn_check;
static GtkWidget *btn_gen;  
static GtkWidget *vbox;     
static GtkWidget *hbox1;    
static GtkWidget *hbox2;    
static GtkWidget *MainWindow;
static GtkWidget *cbox_sex; 
static GtkWidget *cbox_area;

/* Declare Private Method */
static void setup_comboBox( void );
static void setup_signal( void );
static void launch_idgen( GtkWidget *widget );

/** 
 * Create the Main Frame
 * 
 * @param window   A GtkWindow that you want to create
 */
void setupMainFrame( GtkWidget *window )
{
        MainWindow = window;
        
        gtk_window_set_title( GTK_WINDOW( window ), "身份證字號產生器" );
        gtk_window_set_position( GTK_WINDOW( window ), GTK_WIN_POS_CENTER );
        gtk_window_set_default_size( GTK_WINDOW( window ), 325, 100 );
        gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

        gtk_container_set_border_width( GTK_CONTAINER( window ), 15 );

        /* 產生 vbox */
        vbox = gtk_vbox_new( TRUE, 5 );
        gtk_container_add( GTK_CONTAINER( window ), vbox );
        gtk_widget_show (vbox);

        /* 產生 hbox 1 */
        hbox1 = gtk_hbox_new( FALSE, 10 );

        /* 產生 hbox 2 */
        hbox2 = gtk_hbox_new( FALSE, 10 );

        /* 產生所有需要用到的 label */
        label_id = gtk_label_new( "身份證字號" );
        label_sex = gtk_label_new( "性別" );
        label_area = gtk_label_new( "登記地" );

        /* 產生放置身份證字號的 txt行 */
        lineEdit = gtk_entry_new();

        /* 產生所需要的按鈕 */
        btn_gen = gtk_button_new_with_label( "產生" );
        
        /* 產生所有需要用到的combobox */
        cbox_sex = gtk_combo_box_new_text();
        cbox_area = gtk_combo_box_new_text();

        /* 修正大小  */
        gtk_widget_set_size_request( lineEdit, 180, 20 );
        gtk_widget_set_size_request( btn_gen, 50, 30 );

        
        /* 佈局管理 */
        gtk_box_pack_start( GTK_BOX( hbox1 ), label_id, FALSE, FALSE, 0 );
        gtk_box_pack_start( GTK_BOX( hbox1 ), lineEdit, FALSE, FALSE, 0 );
        gtk_box_pack_start( GTK_BOX( hbox1 ), btn_gen, FALSE, FALSE, 0 );

        gtk_box_pack_start( GTK_BOX( vbox ), hbox1, FALSE, FALSE, 0 );
        gtk_box_pack_start( GTK_BOX( vbox ), hbox2, FALSE, FALSE, 0 );

        gtk_box_pack_end( GTK_BOX( hbox2 ), cbox_area, FALSE, FALSE, 0 );
        gtk_box_pack_end( GTK_BOX( hbox2 ), label_area, FALSE, FALSE, 0 );
        gtk_box_pack_end( GTK_BOX( hbox2 ), cbox_sex, FALSE, FALSE, 0 );
        gtk_box_pack_end( GTK_BOX( hbox2 ), label_sex, FALSE, FALSE, 0 );

        setup_comboBox();
        setup_signal();
}

void setup_signal( void )
{
        g_signal_connect( GTK_OBJECT( MainWindow ), "destroy",
                         G_CALLBACK( gtk_main_quit ), NULL );

        g_signal_connect( G_OBJECT( btn_gen ), "clicked",
                         G_CALLBACK( launch_idgen ), NULL );
}

void launch_idgen(GtkWidget *widget)
{
        gchar *ID;
        gint sex, country;
        sex = gtk_combo_box_get_active( GTK_COMBO_BOX( cbox_sex ) );
        country = gtk_combo_box_get_active( GTK_COMBO_BOX( cbox_area ) );
        ID = idgen_for_Taiwan( country, sex );
        gtk_entry_set_text( GTK_ENTRY( lineEdit ), ( gchar * ) ID );
}

void setup_comboBox(void)
{
        /* comboBox sex */
        gtk_combo_box_append_text( GTK_COMBO_BOX( cbox_sex ), "隨機產生" );
        gtk_combo_box_append_text( GTK_COMBO_BOX( cbox_sex ), "男性 (1)" );
        gtk_combo_box_append_text( GTK_COMBO_BOX( cbox_sex ), "女性 (2)" );
        gtk_combo_box_set_active( GTK_COMBO_BOX( cbox_sex ), 0 );

        /* comboBox area */
        gtk_combo_box_append_text( GTK_COMBO_BOX( cbox_area ), "隨機產生" );
        gtk_combo_box_append_text( GTK_COMBO_BOX( cbox_area ), "台北市 (A)" );
        gtk_combo_box_append_text( GTK_COMBO_BOX( cbox_area ), "台中市 (B)" );
        gtk_combo_box_append_text( GTK_COMBO_BOX( cbox_area ), "基隆市 (C)" );
        gtk_combo_box_append_text( GTK_COMBO_BOX( cbox_area ), "台南市 (D)" );
        gtk_combo_box_append_text( GTK_COMBO_BOX( cbox_area ), "高雄市 (E)" );
        gtk_combo_box_append_text( GTK_COMBO_BOX( cbox_area ), "台北縣 (F)" );
        gtk_combo_box_append_text( GTK_COMBO_BOX( cbox_area ), "宜蘭縣 (G)" );
        gtk_combo_box_append_text( GTK_COMBO_BOX( cbox_area ), "桃園縣 (H)" );
        gtk_combo_box_append_text( GTK_COMBO_BOX( cbox_area ), "嘉義市 (I)" );
        gtk_combo_box_append_text( GTK_COMBO_BOX( cbox_area ), "新竹縣 (J)" );
        gtk_combo_box_append_text( GTK_COMBO_BOX( cbox_area ), "苗栗縣 (K)" );
        gtk_combo_box_append_text( GTK_COMBO_BOX( cbox_area ), "台中縣 (L)" );
        gtk_combo_box_append_text( GTK_COMBO_BOX( cbox_area ), "南投縣 (M)" );
        gtk_combo_box_append_text( GTK_COMBO_BOX( cbox_area ), "彰化縣 (N)" );
        gtk_combo_box_append_text( GTK_COMBO_BOX( cbox_area ), "新竹市 (O)" );
        gtk_combo_box_append_text( GTK_COMBO_BOX( cbox_area ), "雲林縣 (P)" );
        gtk_combo_box_append_text( GTK_COMBO_BOX( cbox_area ), "嘉義縣 (Q)" );
        gtk_combo_box_append_text( GTK_COMBO_BOX( cbox_area ), "台南縣 (R)" );
        gtk_combo_box_append_text( GTK_COMBO_BOX( cbox_area ), "高雄縣 (S)" );
        gtk_combo_box_append_text( GTK_COMBO_BOX( cbox_area ), "屏東縣 (T)" );
        gtk_combo_box_append_text( GTK_COMBO_BOX( cbox_area ), "花蓮縣 (U)" );
        gtk_combo_box_append_text( GTK_COMBO_BOX( cbox_area ), "台東縣 (V)" );
        gtk_combo_box_append_text( GTK_COMBO_BOX( cbox_area ), "金門縣 (W)" );
        gtk_combo_box_append_text( GTK_COMBO_BOX( cbox_area ), "澎湖縣 (X)" );
        gtk_combo_box_append_text( GTK_COMBO_BOX( cbox_area ), "陽明山 (Y)" );
        gtk_combo_box_append_text( GTK_COMBO_BOX( cbox_area ), "連江縣 (z)" );
        gtk_combo_box_set_active( GTK_COMBO_BOX( cbox_area ), 0 );
}




#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>


static void open_dialog(GtkWidget *button, gpointer window){
  char *command = "livewall -ov -ni -fs -- mpv -wid WID --keepaspect=no --loop ";
  GtkWidget *dialog;
  dialog = gtk_file_chooser_dialog_new("Choose a GIF",
    GTK_WINDOW(window),
    GTK_FILE_CHOOSER_ACTION_OPEN,
    GTK_STOCK_OK,
    GTK_RESPONSE_OK,
    GTK_STOCK_CANCEL,
    GTK_RESPONSE_CANCEL,
    NULL);

  gtk_widget_show_all(dialog);
  gint resp = gtk_dialog_run(GTK_DIALOG(dialog));
  gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(dialog),g_get_home_dir());
  if(resp==GTK_RESPONSE_OK){
    g_print("%s\n",gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog)));
    char *gif = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
    char gif_command[strlen(command) + strlen(gif)];
    strcpy(gif_command,command);
    strcat(gif_command,gif);
    printf("%s\n",gif_command);
    system(gif_command);
  }
  else
    g_print("You Pressed Cancel\n");

  gtk_widget_destroy(dialog);
}


int main(int argc, char const *argv[])
{
  gtk_init(&argc, &argv);
  GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  GtkWidget *button;

  gtk_window_set_title (GTK_WINDOW (window), "Livewall Yogdaan");

  button = gtk_button_new_with_label("Choose a GIF");

  g_signal_connect(window,"delete-event",G_CALLBACK(gtk_main_quit),NULL);
  g_signal_connect(button,"clicked",G_CALLBACK(open_dialog),NULL);
  
  gtk_container_set_border_width(GTK_CONTAINER(window),100);
  gtk_container_add(GTK_CONTAINER(window),button);

  gtk_widget_set_size_request(GTK_WINDOW(window),300,300);
  gtk_window_set_resizable (GTK_WINDOW(window),0);
  gtk_widget_show_all(window);

  gtk_main();
  return 0;
}

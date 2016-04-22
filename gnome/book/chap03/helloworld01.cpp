/*
 * program: helloworld.cpp
 * 
 * compile: $ g++ -o helloworld helloworld.cpp $(pkg-config gtk+-3.0 --cflags --libs)
 * execute: $ ./helloworld
 *
 * Notes: Original was taken from the book GTK+/Gnome Application Develoopment 
 *        The book was writte for GTK+-2.0 and Gnome-2.0
 *        This was update for GTK+-3.0
 */
#include <gtk/gtk.h>

static gint delete_event_cb(GtkWidget* w, GdkEventAny* e, gpointer data);
static void button_click_cb(GtkWidget* w, gpointer data);

int
main(int argc, char* argv[]) {
  GtkWidget* window;
  GtkWidget* button;
  GtkWidget* label;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  button = gtk_button_new();

  label = gtk_label_new("Hello, World!");

  gtk_container_add(GTK_CONTAINER(button), label);
  gtk_container_add(GTK_CONTAINER(window), button);

  gtk_window_set_title(GTK_WINDOW(window), "Hello");
  gtk_container_set_border_width(GTK_CONTAINER(button), 10);

  g_signal_connect(window, "delete_event",
  		     G_CALLBACK(delete_event_cb), NULL);

  g_signal_connect(button, "clicked", G_CALLBACK(button_click_cb), label);

  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}

static gint
delete_event_cb(GtkWidget* window, GdkEventAny* e, gpointer data) {
  gtk_main_quit();
  return FALSE;
}

static void
button_click_cb(GtkWidget* w, gpointer data) {
  GtkWidget* label;
  const gchar* text;
  gchar* tmp;

  label = GTK_WIDGET(data);

  text = gtk_label_get_text(GTK_LABEL(label));

  tmp = g_strdup(text);

  g_strreverse(tmp);

  gtk_label_set_text(GTK_LABEL(label), tmp);

  g_free(tmp);
}

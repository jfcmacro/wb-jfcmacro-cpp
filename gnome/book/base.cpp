/*
 * fichero: base.C
 * url: https://developer.gnome.org/gtkmm-tutorial/stable/sec-basics-simple-example.html.es
 *
 * compile: $ g++ base.cpp -o base `pkg-config gtkmm-3.0 --cflags --libs`
 * execute: $ ./base
 */

#include <gtkmm.h>

int main(int argc, char *argv[])
{
  Glib::RefPtr<Gtk::Application> app =
    Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");

  Gtk::Window window;
  
  window.set_default_size(400, 400);

  return app->run(window);
}

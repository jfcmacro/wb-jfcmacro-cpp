#include <gtkmm.h>

int main(int argc, char *argv[])
{
  Glib::RefPtr<Gtk::Application> app =
    Gtk::Application::create(argc, argv,
                             "org.gtkmm.examples.base");

  Gtk::Window window;
  window.set_default_size(400, 600);

  return app->run(window);
}

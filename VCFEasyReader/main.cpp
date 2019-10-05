#include "MainWindow.h"

int main ()
{
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create();

  MainWindow mainwindow;
  
  return app->run(mainwindow);
}
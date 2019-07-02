#ifndef GTKMM_MAINWINDOW_H
#define GTKMM_MAINWINDOW_H

#include <gtkmm.h>

class MainWindow : public Gtk::Window
{

public:
  MainWindow();

protected:
  Gtk::Button m_button;
};

#endif
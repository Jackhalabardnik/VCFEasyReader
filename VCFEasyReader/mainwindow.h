#ifndef GTKMM_MAINWINDOW_H
#define GTKMM_MAINWINDOW_H

#include <gtkmm.h>
#include <iostream>

class MainWindow : public Gtk::ApplicationWindow
{

public:
	MainWindow();

private:
	void showAll();
	void setButtons();
	void setLabels();
	void setMenus();
	void setOutputBox();
	void setMainGrid();
	void setWindow();
	
	void openNewFile();
	void exportToTextFile();
	void printFile();
	void changeView(int mode);
protected:
	Gtk::Label pathLabel;
	Gtk::TextView textView;
	Gtk::Box outputBox, mainBox;
	Gtk::Grid outputGrid;
	Glib::RefPtr<Gio::Action> viewToggle;
};

#endif
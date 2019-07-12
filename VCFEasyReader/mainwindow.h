#ifndef GTKMM_MAINWINDOW_H
#define GTKMM_MAINWINDOW_H

#include <gtkmm.h>
#include <iostream>

class MainWindow : public Gtk::Window
{

public:
	MainWindow();

private:
	void showAll();
	void setButtons();
	void setLabels();
	void setMenus();
	void setButtonBox();
	void setOutputBox();
	void setMainGrid();
	void setWindow();
	void openNewFile();
	void changeView(int mode);
protected:
	Gtk::Label pathLabel;
	Gtk::Button openFile_button, print_button, saveToTextFile_button;
	Gtk::TextView textView;
	Gtk::Box outputBox, mainBox;
	Gtk::Grid outputGrid;
	Glib::RefPtr<Gio::SimpleActionGroup> menubarActionGroup, viewAG;
};

#endif
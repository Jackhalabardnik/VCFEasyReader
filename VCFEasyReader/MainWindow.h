#ifndef GTKMM_MAINWINDOW_H
#define GTKMM_MAINWINDOW_H

#include <gtkmm.h>
#include "TreeView.h"
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
	void checkAll();
	void uncheckAll();
	
	std::string askUserForNewFileName();
protected:
	TreeView treeView;

	Gtk::Label pathLabel;
	Gtk::ScrolledWindow scrolledWindow;
	Gtk::Box outputBox, mainBox;
	Gtk::Grid outputGrid;
};

#endif

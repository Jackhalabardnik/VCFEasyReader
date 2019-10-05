#pragma once

#include "TreeView.h"
#include "Parser.h"
#include "Exporter.h"

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
	void checkAll();
	void uncheckAll();
	
	std::string askUserForNewFileName();
protected:
	TreeView treeView;
	Parser parser;
	Exporter exporter;

	Gtk::Label pathLabel;
	Gtk::ScrolledWindow scrolledWindow;
	Gtk::Box outputBox, mainBox;
	Gtk::Grid outputGrid;
};

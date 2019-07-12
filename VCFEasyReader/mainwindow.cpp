#include "mainwindow.h"
#include <iostream>

MainWindow::MainWindow()
{
  setButtons();
  setLabels();
  setMenus();
  setButtonBox();
  setOutputBox();
  setMainGrid();
  setWindow();
  showAll();
}

void MainWindow::setButtons()
{
	openFile_button.set_label("OpenFile");
	print_button.set_label("Print");
	saveToTextFile_button.set_label("saveToTextFile");
}

void MainWindow::setButtonBox()
{
	
}

void MainWindow::setOutputBox()
{
	auto scrolledWindow = Gtk::manage(new Gtk::ScrolledWindow);
	scrolledWindow->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
	scrolledWindow->add(textView);
	scrolledWindow->set_size_request(-1,200);
	outputBox.set_orientation(Gtk::ORIENTATION_VERTICAL);
	outputBox.pack_start(*scrolledWindow, Gtk::PACK_EXPAND_WIDGET);
	outputBox.pack_start(pathLabel, Gtk::PACK_SHRINK);
	mainBox.pack_start(outputBox, Gtk::PACK_EXPAND_WIDGET);
}

void MainWindow::setMainGrid()
{
	mainBox.set_orientation(Gtk::ORIENTATION_VERTICAL);
	add(mainBox);
}

void MainWindow::setWindow()
{
	//set_border_width(10);
}
void MainWindow::showAll()
{
	outputBox.show_all();
	mainBox.show();
}

void MainWindow::setLabels()
{
	pathLabel.set_text("Path to selected file");
}

void MainWindow::setMenus()
{
	menubarActionGroup = Gio::SimpleActionGroup::create();
	menubarActionGroup->add_action("opennew", sigc::mem_fun(*this, &MainWindow::openNewFile));
	menubarActionGroup->add_action("print");
	menubarActionGroup->add_action("export");
	viewAG = Gio::SimpleActionGroup::create();
	viewAG->add_action_radio_integer("minimal", sigc::mem_fun(*this, &MainWindow::changeView), 1);
	viewAG->add_action_radio_integer("list", sigc::mem_fun(*this, &MainWindow::changeView), 2);
	insert_action_group("menu", menubarActionGroup);
	insert_action_group("view", viewAG);
	
	Glib::RefPtr<Gtk::Builder> refBuilder = Gtk::Builder::create();
	
	const char* ui_info =
  "<interface>"
  "  <menu id='menubar'>"
  "    <submenu>"
  "      <attribute name='label' translatable='yes'>File</attribute>"
  "      <section>"
  "        <item>"
  "          <attribute name='label' translatable='yes'>Open</attribute>"
  "          <attribute name='action'>menu.opennew</attribute>"
  "          <attribute name='accel'>&lt;Primary&gt;o</attribute>"
  "        </item>"
  "      </section>"
  "      <section>"
  "        <item>"
  "          <attribute name='label' translatable='yes'>Print</attribute>"
  "          <attribute name='action'>menu.print</attribute>"
  "          <attribute name='accel'>&lt;Primary&gt;p</attribute>"
  "        </item>"
  "      </section>"
  "      <section>"
  "        <item>"
  "          <attribute name='label' translatable='yes'>Export</attribute>"
  "          <attribute name='action'>menu.export</attribute>"
  "          <attribute name='accel'>&lt;Primary&gt;i</attribute>"
  "        </item>"
  "      </section>"
  "    </submenu>"
  "    <submenu>"
  "      <attribute name='label' translatable='yes'>View</attribute>"
  "      <item>"
  "        <attribute name='label' translatable='yes'>Minimal</attribute>"
  "        <attribute name='action'>view.minimal</attribute>"
  "          <attribute name='target'>1</attribute>"
  "      </item>"
  "      <item>"
  "        <attribute name='label' translatable='yes'>List</attribute>"
  "        <attribute name='action'>view.list</attribute>"
  "          <attribute name='target'>2</attribute>"
  "      </item>"
  "    </submenu>"
  "  </menu>"
  "</interface>";
	
	refBuilder->add_from_string(ui_info);
	
	
	Glib::RefPtr<Glib::Object> object = refBuilder->get_object("menubar");
	Glib::RefPtr<Gio::Menu> gmenu = Glib::RefPtr<Gio::Menu>::cast_dynamic(object);
	Gtk::MenuBar* pMenuBar = Gtk::manage(new Gtk::MenuBar(gmenu));
	pMenuBar->show_all();
	mainBox.pack_start(*pMenuBar, Gtk::PACK_SHRINK);
}

void MainWindow::openNewFile()
{
	std::cout << "Works\n";
}

void MainWindow::changeView(int mode)
{
	std::string mess = mode == 1 ? "minimal" : "list";
	std::cout << "Current mode is " << mode << ".\n";
}

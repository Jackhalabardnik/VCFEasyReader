#include "mainwindow.h"
#include <iostream>

MainWindow::MainWindow()
{
  setLabels();
  setMenus();
  setOutputBox();
  setMainGrid();
  setWindow();
  showAll();
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
	set_title("VCF Easy reader");
	set_size_request(300,-1);
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
	add_action("opennew", sigc::mem_fun(*this, &MainWindow::openNewFile));
	add_action("print", sigc::mem_fun(*this, &MainWindow::printFile));
	add_action("export", sigc::mem_fun(*this, &MainWindow::exportToTextFile));
	
	viewToggle = add_action_radio_integer("changeview", sigc::mem_fun(*this, &MainWindow::changeView), 1);
	
	Glib::RefPtr<Gtk::Builder> refBuilder = Gtk::Builder::create();
	
	const char* ui_info =
  "<interface>"
  "  <menu id='menubar'>"
  "    <submenu>"
  "      <attribute name='label' translatable='yes'>File</attribute>"
  "      <section>"
  "        <item>"
  "          <attribute name='label' translatable='yes'>Open</attribute>"
  "          <attribute name='action'>win.opennew</attribute>"
  "          <attribute name='accel'>&lt;Primary&gt;o</attribute>"
  "        </item>"
  "      </section>"
  "      <section>"
  "        <item>"
  "          <attribute name='label' translatable='yes'>Print</attribute>"
  "          <attribute name='action'>win.print</attribute>"
  "          <attribute name='accel'>&lt;Primary&gt;p</attribute>"
  "        </item>"
  "      </section>"
  "      <section>"
  "        <item>"
  "          <attribute name='label' translatable='yes'>Export</attribute>"
  "          <attribute name='action'>win.export</attribute>"
  "          <attribute name='accel'>&lt;Primary&gt;i</attribute>"
  "        </item>"
  "      </section>"
  "    </submenu>"
  "    <submenu>"
  "      <attribute name='label' translatable='yes'>View</attribute>"
  "      <section>"
  "      <item>"
  "        <attribute name='label' translatable='yes'>Minimal</attribute>"
  "        <attribute name='action'>win.changeview</attribute>"
  "        <attribute name='target' type='i'>1</attribute>"
  "      </item>"
  "      </section>"
  "      <section>"
  "      <item>"
  "        <attribute name='label' translatable='yes'>List</attribute>"
  "        <attribute name='action'>win.changeview</attribute>"
  "        <attribute name='target' type='i'>2</attribute>"
  "      </item>"
  "      </section>"
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
	std::cout << "Open new file\n";
}

void MainWindow::changeView(int mode)
{
	viewToggle->change_state(mode);
	std::string message = mode == 1 ? "minimal" : "list";
	std::cout << "Current mode is " << message << ".\n";
}

void MainWindow::exportToTextFile()
{
	std::cout << "Export to text file\n";
}

void MainWindow::printFile()
{
	std::cout << "Print file\n";
}

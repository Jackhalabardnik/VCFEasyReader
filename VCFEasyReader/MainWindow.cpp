#include "MainWindow.h"
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
	outputBox.set_orientation(Gtk::ORIENTATION_VERTICAL);
	scrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
	
	scrolledWindow.add(treeView.returnWidget());
	outputBox.pack_start(scrolledWindow, Gtk::PACK_EXPAND_WIDGET);
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
	add_action("export", sigc::mem_fun(*this, &MainWindow::exportToTextFile));
	add_action("checkAll", sigc::mem_fun(*this, &MainWindow::checkAll));
	add_action("uncheckAll", sigc::mem_fun(*this, &MainWindow::uncheckAll));
	
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
  "          <attribute name='label' translatable='yes'>Export</attribute>"
  "          <attribute name='action'>win.export</attribute>"
  "          <attribute name='accel'>&lt;Primary&gt;i</attribute>"
  "        </item>"
  "      </section>"
  "    </submenu>"
  "    <submenu>"
  "      <attribute name='label' translatable='yes'>Edit</attribute>"
  "      <section>"
  "        <item>"
  "          <attribute name='label' translatable='yes'>Check all</attribute>"
  "          <attribute name='action'>win.checkAll</attribute>"
  "        </item>"
  "      </section>"
  "      <section>"
  "        <item>"
  "          <attribute name='label' translatable='yes'>Uncheck all</attribute>"
  "          <attribute name='action'>win.uncheckAll</attribute>"
  "        </item>"
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
	
//	Gtk::TreeModel::Row row = *(treeModel->append());
	//row[columns.doCheck] = true;
	//row[columns.contactName] = "New";
	//row[columns.contactNumber] = "000000000";
	//row[columns.contactInfo] = "Info";
}

void MainWindow::exportToTextFile()
{
	std::cout << "Export to text file\n";
	//auto rowList = treeModel->children();
	//if(rowList.size()>0)
	//{
	//	treeModel->erase(--rowList.end());
	//}
}

void MainWindow::checkAll()
{
	performChangeChecksState(true);
}

void MainWindow::uncheckAll()
{
	performChangeChecksState(false);
}

void MainWindow::performChangeChecksState(bool state)
{
	//auto rowList = treeModel->children();
	//if(rowList.size()>0)
	//{
	//	for(unsigned int i=0; i< rowList.size(); i++)
	//	{
	//		rowList[i][columns.doCheck] = state;
	//	}
	//}
}
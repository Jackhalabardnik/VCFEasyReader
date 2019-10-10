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
	Gtk::FileChooserDialog dialog("Please choose a vcf file", Gtk::FILE_CHOOSER_ACTION_OPEN);
	dialog.set_transient_for(*this);

	dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
	dialog.add_button("Open", Gtk::RESPONSE_OK);

	auto filter_text = Gtk::FileFilter::create();
	filter_text->set_name(".vcf files");
	filter_text->add_mime_type("text/vcard");
	dialog.add_filter(filter_text);
	
	int result = dialog.run();
	
	std::string uri;
	
	if(result == Gtk::ResponseType::RESPONSE_OK)
	{
		uri = dialog.get_uri();
		uri.erase(uri.begin(),uri.begin()+7);
		treeView.populate(parser.parse(uri));
		pathLabel.set_text(uri);
	}
	
}

void MainWindow::exportToTextFile()
{
	Gtk::FileChooserDialog dialog("Please choose a text file", Gtk::FILE_CHOOSER_ACTION_OPEN);
	dialog.set_transient_for(*this);

	dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
	dialog.add_button("Open", Gtk::RESPONSE_OK);
	dialog.add_button("New File", 1);

	auto filter_text = Gtk::FileFilter::create();
	filter_text->set_name("Text files");
	filter_text->add_mime_type("text/plain");
	dialog.add_filter(filter_text);
	
	int result = dialog.run();
	
	std::string uri;
	
	if(result == Gtk::ResponseType::RESPONSE_OK || result == 1)
	{
		if(result == Gtk::ResponseType::RESPONSE_OK)
		{
			uri = dialog.get_uri();
			uri.erase(uri.begin(),uri.begin()+7);
		}
		else
		{
			uri = dialog.get_current_folder_uri() + "/";
			if(uri.size()>7)
			{
				uri.erase(uri.begin(),uri.begin()+7);
			}
			uri += askUserForNewFileName() + ".txt";
		}
		exporter.exportToTextFile(treeView.getChecked(), uri);
	}
	else
	{
		uri = "No path selected";
	}
}

std::string MainWindow::askUserForNewFileName()
{
	Gtk::MessageDialog dialog(*this, "Type new file name", false, Gtk::MessageType::MESSAGE_OTHER, Gtk::BUTTONS_OK_CANCEL,false);
	
	auto entry = Gtk::manage(new Gtk::Entry);
	entry->show();
	
	dialog.get_content_area()->pack_start(*entry, true, true, 1);
	
	
	int response = dialog.run();
	std::string uri;
	
	if(response == Gtk::RESPONSE_OK)
	{
		uri = entry->get_text();
	}
	
	return uri;
}

void MainWindow::checkAll()
{
	treeView.setAllChecks(true);
}

void MainWindow::uncheckAll()
{
	treeView.setAllChecks(false);
}

#ifndef TREEVIEW
#define TREEVIEW
#include <gtkmm-3.0/gtkmm.h>
  
  class ModelColumns : public Gtk::TreeModel::ColumnRecord
  {
  public:

    ModelColumns();
	
	Gtk::TreeModelColumn<bool> doCheck;
    Gtk::TreeModelColumn<Glib::ustring> contactName;
    Gtk::TreeModelColumn<Glib::ustring> contactNumber;
	Gtk::TreeModelColumn<Glib::ustring> contactInfo;
  };
  
#endif
#ifndef TREEVIEW_H
#define TREEVIEW_H

#include <gtkmm-3.0/gtkmm.h>

class TreeView
{
public:
	
	TreeView();
	
	Gtk::TreeView& returnWidget();
	
	
private:
	class ModelColumns : public Gtk::TreeModel::ColumnRecord
	{
		public:

		ModelColumns()
		{ 
			add(doCheck); 
			add(contactName); 
			add(contactNumber); 
			add(contactInfo);
		}
		
		Gtk::TreeModelColumn<bool> doCheck;
		Gtk::TreeModelColumn<Glib::ustring> contactName;
		Gtk::TreeModelColumn<Glib::ustring> contactNumber;
		Gtk::TreeModelColumn<Glib::ustring> contactInfo;
	};
  
	ModelColumns columns;
	Gtk::TreeView treeView;
	Glib::RefPtr<Gtk::ListStore> treeModel;
  
};

#endif
#pragma once

#include "Contact.h"

#include <gtkmm-3.0/gtkmm.h>
#include <vector>

class TreeView
{
public:
	
	TreeView();
	
	Gtk::TreeView& returnWidget();
	
	void populate(std::vector<Contact> contacts);
	
	
private:
	class ModelColumns : public Gtk::TreeModel::ColumnRecord
	{
		public:

		ModelColumns()
		{ 
			add(doCheck); 
			add(contactName); 
			add(contactNumber); 
			add(contactId);
		}
		
		Gtk::TreeModelColumn<bool> doCheck;
		Gtk::TreeModelColumn<Glib::ustring> contactName;
		Gtk::TreeModelColumn<Glib::ustring> contactNumber;
		Gtk::TreeModelColumn<int> contactId;
	};
  
	ModelColumns columns;
	Gtk::TreeView treeView;
	Glib::RefPtr<Gtk::ListStore> treeModel;
  
};
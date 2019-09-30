#include "TreeView.h"

TreeView::TreeView()
{
	treeModel = Gtk::ListStore::create(columns);
	
	treeView.set_model(treeModel);
	
	treeView.append_column_editable("Check", columns.doCheck);
	treeView.append_column("Name", columns.contactName);
	treeView.append_column("Call number", columns.contactNumber);
}

Gtk::TreeView& TreeView::returnWidget()
{
	return treeView;
}

void TreeView::populate(std::vector<Contact> contacts)
{
	Gtk::TreeModel::Row row; 
	
	std::string to;
	
	for(Contact contact : contacts)
	{
		row = *(treeModel->append()); 
		row[columns.doCheck] = true;
		row[columns.contactName] = contact.name;
		row[columns.contactNumber] = contact.number;
		row[columns.contactId] = contact.id;
	}
}

std::vector<Contact> TreeView::getChecked()
{
	std::vector<Contact> contactList;
	
	auto childern = treeModel->children();
	
	for(auto row : childern)
	{
		if(row[columns.doCheck])
		{
			Glib::ustring name = row[columns.contactName];
			Glib::ustring number = row[columns.contactNumber];
			contactList.emplace_back(Contact(name, number, 0));
		}
	}
	
	return contactList;
}

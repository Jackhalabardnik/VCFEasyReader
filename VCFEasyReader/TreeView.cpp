#include "TreeView.h"

TreeView::TreeView()
{
	treeModel = Gtk::ListStore::create(columns);
	
	treeView.set_model(treeModel);
	
	treeView.append_column_editable("Check", columns.doCheck);
	treeView.append_column("Name", columns.contactName);
	treeView.append_column("Call number", columns.contactNumber);
	
	auto column = treeView.get_column(1);
	if(column) {
		column->set_sort_column(columns.contactName);
	}
	
	column = treeView.get_column(2);
	if(column) {
		column->set_sort_column(columns.contactNumber);
	}
}

Gtk::TreeView& TreeView::returnWidget()
{
	return treeView;
}

void TreeView::populate(std::vector<Contact> contacts)
{
	Gtk::TreeModel::Row row; 
	
	treeModel->clear();
	
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
	
	auto children = treeModel->children();
	
	for(auto row : children)
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

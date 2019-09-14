#include "TreeView.h"

TreeView::TreeView()
{
	treeModel = Gtk::ListStore::create(columns);
	
	treeView.set_model(treeModel);
	
	treeView.append_column_editable("Check", columns.doCheck);
	treeView.append_column("Name", columns.contactName);
	treeView.append_column("Call number", columns.contactNumber);
	treeView.append_column("Additional info", columns.contactInfo);
}

Gtk::TreeView& TreeView::returnWidget()
{
	return treeView;
}

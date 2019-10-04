#include <catch.hpp>
#include "TreeView.cpp"

auto have_to_be_here = Gtk::Application::create();

class MockTreeView : public TreeView
{
	public:
	void uncheckFirstRow()
	{
		auto children = treeModel->children();

		children[0][columns.doCheck] = false;
	}
};

bool match(std::vector<Contact> v1, std::vector<Contact> v2)
{
	if(v1.size() != v2.size())
	{
		return false;
	}
	for(unsigned int i=0;i<v1.size();i++)
	{
		if(v1[i] != v2[i])
		{
			return false;
		}
	}
	return true;
}



TEST_CASE("Return populated contacts", "[TreeView]")
{
	std::vector<Contact> v = {Contact("Jon", "123-123-123", 0), Contact("Mel", "567-345-345", 1) };
	MockTreeView view;
	view.populate(v);
	
	std::vector<Contact> result = view.getChecked(); 
	
	CHECK(match(v,result));
}

TEST_CASE("Return populated contacts without unchecked", "[TreeView]")
{
	std::vector<Contact> v = {Contact("Jon", "123-123-123", 0), Contact("Mel", "567-345-345", 1) };
	std::vector<Contact> checked = {Contact("Mel", "567-345-345", 1) };
	MockTreeView view;
	view.populate(v);
	
	view.uncheckFirstRow();
	
	CHECK(match(checked,view.getChecked()));
}

TEST_CASE("Deletes previous contacts before populating", "[TreeView]")
{
	std::vector<Contact> first = {Contact("Jon", "123-123-123", 0), Contact("Mel", "567-345-345", 1) };
	std::vector<Contact> result = {Contact("Mel", "567-345-345", 0), Contact("Cel", "123-345-345", 1), Contact("Nel", "568-345-345", 2) };
	MockTreeView view;
	
	view.populate(first);
	view.populate(result);
	
	CHECK(match(view.getChecked(),result));
}
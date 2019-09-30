#include <catch.hpp>
#include "TreeView.cpp"

auto have_to_be_here = Gtk::Application::create();

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
	TreeView view;
	view.populate(v);
	
	std::vector<Contact> result = view.getChecked(); 
	
	CHECK(match(v,result));
}
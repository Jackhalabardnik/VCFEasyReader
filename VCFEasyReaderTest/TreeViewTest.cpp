#include <catch.hpp>
#include "TreeView.cpp"

auto have_to_be_here = Gtk::Application::create();

TEST_CASE("Can add stuff to list", "[TreeView]")
{
	TreeView tw;
	CHECK(true);
}
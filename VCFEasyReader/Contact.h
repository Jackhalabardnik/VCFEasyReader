#pragma once

#include <gtkmm-3.0/gtkmm.h>

#include <iostream>

class Contact
{
public:
	Contact(Glib::ustring Name, Glib::ustring Number);
	
	Glib::ustring getName();
	Glib::ustring getNumber();
	
	bool operator!=(const Contact & c);
		
private:
	Glib::ustring name;
	Glib::ustring number;

};


#pragma once

#include "Contact.h"

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

class Parser
{
public:
	Parser();
	
	std::vector<Contact> parse(Glib::ustring s);
private:
	Glib::ustring decode(Glib::ustring s);
	int sixToDec(Glib::ustring s);
	int stringToInt(char s);
};


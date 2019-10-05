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
	
	std::vector<Contact> parse(std::string s);
private:
	std::string decode(std::string s);
	int sixToDec(std::string s);
	int stringToInt(char s);
};


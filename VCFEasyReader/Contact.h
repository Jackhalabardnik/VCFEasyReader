#pragma once

#include <iostream>

class Contact
{
public:
	Contact(std::string Name, std::string Number, int Id);
	
	std::string name;
	std::string number;
	int id;

};


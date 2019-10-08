#pragma once

#include <iostream>

class Contact
{
public:
	Contact(std::string Name, std::string Number);
	
	std::string getName();
	std::string getNumber();

	int getNameTrueSize();

	bool operator==(const Contact & c);
	
	bool operator!=(const Contact & c);
		
private:
	std::string name;
	std::string number;

};


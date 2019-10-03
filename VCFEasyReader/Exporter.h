#include "Contact.h"

#include <vector>

class Exporter
{
private:
	int getLongestNameSize(std::vector<Contact> contacts);
	std::string returnCharacters(std::string character, int times);
	
	const int minimalSize = 4;
	const std::string minimalSpacing = "    ";
	
protected:
	std::string formatToText(std::vector<Contact> contacts);
	
};
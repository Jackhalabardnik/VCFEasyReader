#include "Contact.h"

#include <fstream>
#include <vector>

class Exporter
{
private:
	int getLongestNameSize(std::vector<Contact> contacts);
	std::string returnCharacters(std::string character, int times);
	void saveToFile(std::string path, std::string text);
	
	const int minimalSize = 4;
	const std::string minimalSpacing = "    ";
	
protected:
	std::string formatToText(std::vector<Contact> contacts);
	
public:
	void exportToTextFile(std::vector<Contact> contacts, std::string path);
};
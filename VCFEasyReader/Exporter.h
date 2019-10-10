#include "Contact.h"

#include <fstream>
#include <vector>

class Exporter
{
private:
	int getLongestNameSize(std::vector<Contact> contacts);
	Glib::ustring returnCharacters(Glib::ustring character, int times);
	void saveToFile(Glib::ustring path, Glib::ustring text);
	
	const int minimalSize = 4;
	const Glib::ustring minimalSpacing = "    ";
	
protected:
	Glib::ustring formatToText(std::vector<Contact> contacts);
	
public:
	void exportToTextFile(std::vector<Contact> contacts, Glib::ustring path);
};
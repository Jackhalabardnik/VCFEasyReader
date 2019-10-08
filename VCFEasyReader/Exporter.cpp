#include "Exporter.h"

void Exporter::exportToTextFile(std::vector<Contact> contacts, std::string path)
{
	saveToFile(path, formatToText(contacts));
}

std::string Exporter::formatToText(std::vector<Contact> contacts)
{
	std::string result;
	
	int longestNameSize = getLongestNameSize(contacts);
	
	result += "name" + returnCharacters(" ", longestNameSize - 4) + minimalSpacing + "call number\n" + returnCharacters("-", longestNameSize + 15) + "\n";
	
	for (Contact contact : contacts)
	{
		result += contact.getName() + returnCharacters(" ", longestNameSize - contact.getName().size()) + minimalSpacing + contact.getNumber() + "\n";
	}
	
	return result;
}

int Exporter::getLongestNameSize(std::vector<Contact> contacts)
{
	unsigned int size = minimalSize;
	
	for(auto contact : contacts)
	{
		if(contact.getName().size() > size)
		{
			size = contact.getName().size();
		}
	}
	
	return size;
}

std::string Exporter::returnCharacters(std::string character, int times)
{
	std::string s;
	
	for(int i=0;i<times;i++)
	{
		s += character;
	}
	
	return s;
}

void Exporter::saveToFile(std::string path, std::string text)
{
	std::fstream file;
	file.open(path, std::fstream::out | std::fstream::trunc);
	file << text;
	file.close();
}
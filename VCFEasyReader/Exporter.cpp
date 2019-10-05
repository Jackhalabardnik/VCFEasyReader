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
		result += contact.name + returnCharacters(" ", longestNameSize - contact.name.size()) + minimalSpacing + contact.number + "\n";
	}
	
	return result;
}

int Exporter::getLongestNameSize(std::vector<Contact> contacts)
{
	unsigned int size = minimalSize;
	
	for(auto contact : contacts)
	{
		if(contact.name.size() > size)
		{
			size = contact.name.size();
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
#include "Parser.h"



Parser::Parser() {}

std::vector<Contact> Parser::parse(std::string s)
{
	std::fstream file;
	std::vector<Contact> vector;
	std::string name, number, line;
	int id = 0;
	file.open(s);
	while(std::getline(file,line))
	{
		if(line.substr(0,3) == "FN:")
		{
			name = line.substr(3);
		}	

		else if(line.substr(0,3) == "FN;")
		{
			name = decode(line.substr(43));
		}
	
		else if(line.substr(0,4) == "TEL;")
		{
			if(line.substr(4,6) == "VOICE;")
			{
				number = line.substr(15);
			}
			else
			{
				number = line.substr(9);
			}
		}
		else if(line.substr(0,9) == "END:VCARD")
		{
			vector.emplace_back(Contact(name, number, id++));
		}
	}
	
	return vector;
}

std::string Parser::decode(std::string s)
{
	std::string result;
	
	for(unsigned int i=0, j=0 ; j<s.size()/3 ; i+=3, j++)
	{
		result += char(sixToDec(s.substr(i+1,2)));
	}
	
	return result;
}

int Parser::sixToDec(std::string s)
{
	return (16 * stringToInt(s[0])) + stringToInt(s[1]);
} 



int Parser::stringToInt(char s)
{
	int result;
	switch(s)
	{
		case 'A':
			result = 10;
			break;
		case 'B':
			result = 11;
			break;
		case 'C':
			result = 12;
			break;
		case 'D':
			result = 13;
			break;
		case 'E':
			result = 14;
			break;
		case 'F':
			result = 15;
			break;
		default:
			std::stringstream ss;
			ss << s;
			ss >> result;
	}
	return result;
}
#include <catch.hpp>
#include <sstream>
#include "Contact.cpp"

int stringToInt(char s)
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

int sixToDec(std::string s)
{
	return (16 * stringToInt(s[0])) + stringToInt(s[1]);
} 

std::string doublefold(std::string one, std::string two)
{
	std::string s = "";
	s += char(sixToDec(one)) + char(sixToDec(two));
	return s;
}





TEST_CASE("Contact name with double folds DO NOT return its size counting them twice", "[ContactTest]")
{
	std::string bad_guy = "K";
	bad_guy += doublefold("C4","85") + doublefold("C4","85") + doublefold("C4","87") + doublefold("C4","89") + doublefold("C5","82") + doublefold("C3","B3") + doublefold("C5","9B") + doublefold("C5","BA") + doublefold("C5","BC");
	Contact c(bad_guy, "000-000-000");
	CHECK(10 == c.getNameTrueSize());
	
}
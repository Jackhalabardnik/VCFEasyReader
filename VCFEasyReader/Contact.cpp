#include "Contact.h"

Contact::Contact(std::string Name = "", std::string Number = "") : name(Name), number(Number)
{
}

bool Contact::operator==(const Contact & c)
{
	return (name == c.name && number == c.number);
}

bool Contact::operator!=(const Contact & c)
{
	return !(*this == c);
}

std::string Contact::getName()
{
	return name;
}

std::string Contact::getNumber()
{
	return number;
}

int Contact::getNameTrueSize()
{
	return name.size();
}

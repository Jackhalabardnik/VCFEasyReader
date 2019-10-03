#include "Contact.h"

Contact::Contact(std::string Name = "", std::string Number = "", int Id = 0) : name(Name), number(Number), id(Id)
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
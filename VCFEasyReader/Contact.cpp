#include "Contact.h"

Contact::Contact(Glib::ustring Name = "", Glib::ustring Number = "") : name(Name), number(Number)
{
}


bool Contact::operator!=(const Contact & c)
{
	return (name != c.name || number != c.number);
}

Glib::ustring Contact::getName()
{
	return name;
}

Glib::ustring Contact::getNumber()
{
	return number;
}

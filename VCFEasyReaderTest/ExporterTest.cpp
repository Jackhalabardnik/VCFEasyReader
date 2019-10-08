#include <catch.hpp>

#include "Exporter.cpp"

class MockExporter : public Exporter
{
	public:
	std::string formatToText(std::vector<Contact> contacts)
	{
		return Exporter::formatToText(contacts);
	}
};



TEST_CASE("Exporter exports contacts to text file format","[ExporterTests]")
{
	std::string result = 
	"name    call number\n"
	"-------------------\n"
	"Mike    123-123-123\n"
	"John    321-321-321\n";
	
	
	std::vector<Contact> contacts = {Contact("Mike", "123-123-123"), Contact("John", "321-321-321")};
	
	MockExporter exporter;
	
	CHECK(exporter.formatToText(contacts) == result);
	
}

TEST_CASE("Exporter adjusts width of name column to longest name","[ExporterTests]")
{
	std::string result = 
	"name                    call number\n"
	"-----------------------------------\n"
	"Mike_CourtYardStreet    123-123-123\n"
	"John                    321-321-321\n";
	
	
	std::vector<Contact> contacts = {Contact("Mike_CourtYardStreet", "123-123-123"), Contact("John", "321-321-321")};
	
	MockExporter exporter;
	
	CHECK(exporter.formatToText(contacts) == result);
	
}

TEST_CASE("Exporter keep minimal width of name column","[ExporterTests]")
{
	std::string result = 
	"name    call number\n"
	"-------------------\n"
	"Me      123-123-123\n"
	"She     321-321-321\n";
	
	
	std::vector<Contact> contacts = {Contact("Me", "123-123-123"), Contact("She", "321-321-321")};
	
	MockExporter exporter;
	
	CHECK(exporter.formatToText(contacts) == result);
	
}
#include <catch.hpp>

#include "Parser.cpp"
#include "Contact.cpp"

TEST_CASE("Parsing 1 contact", "[ParserTest]")
{
	Parser parser;
	std::string s = "/home/jacek/CLP/VCFEasyReader/VCFEasyReaderTest/test1.vcf";
	
	std::vector<Contact> vector = parser.parse(s);
	
	CHECK(vector[0].name == "Test");
	CHECK(vector[0].number == "333-222-111");
	CHECK(vector[0].id == 0);
}

TEST_CASE("Parsing multiple contacts", "[ParserTest]")
{
	Parser parser;
	std::string s = "/home/jacek/CLP/VCFEasyReader/VCFEasyReaderTest/test_multiple.vcf";
	
	std::vector<Contact> vector = parser.parse(s);
	
	CHECK(vector[0].name == "Adam");
	CHECK(vector[0].number == "000-000-000");
	CHECK(vector[0].id == 0);
	
	CHECK(vector[1].name == "John Mick");
	CHECK(vector[1].number == "111-000-111");
	CHECK(vector[1].id == 1);
}

TEST_CASE("Parsing contact with many things before number", "[ParserTest]")
{
	Parser parser;
	std::string s = "/home/jacek/CLP/VCFEasyReader/VCFEasyReaderTest/test_long_prenumber.vcf";
	
	std::vector<Contact> vector = parser.parse(s);
	
	CHECK(vector[0].number == "333-222-111");
}

TEST_CASE("Parsing contact with encoded name", "[ParserTest]")
{
	Parser parser;
	std::string s = "/home/jacek/CLP/VCFEasyReader/VCFEasyReaderTest/test_encoded.vcf";
	
	std::vector<Contact> vector = parser.parse(s);
	
	CHECK(vector[0].name == "Jonh Gorbe");
}

TEST_CASE("Parsing contact with carrige return on the end", "[ParserTest]")
{
	Parser parser;
	std::string s = "/home/jacek/CLP/VCFEasyReader/VCFEasyReaderTest/smartphone.vcf";
	
	std::vector<Contact> vector = parser.parse(s);
	
	CHECK(vector[0].name == "AMa");
}
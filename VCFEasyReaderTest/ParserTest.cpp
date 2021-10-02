#include <catch.hpp>

#include "../VCFEasyReader/Parser.cpp"

TEST_CASE("Parsing 1 contact", "[ParserTest]")
{
	Parser parser;
	std::string s = "../test1.vcf";
	
	std::vector<Contact> vector = parser.parse(s);
	
	CHECK(vector[0].getName() == "Test");
	CHECK(vector[0].getNumber() == "333-222-111");
}

TEST_CASE("Parsing multiple contacts", "[ParserTest]")
{
	Parser parser;
	std::string s = "../test_multiple.vcf";
	
	std::vector<Contact> vector = parser.parse(s);
	
	CHECK(vector[0].getName() == "Adam");
	CHECK(vector[0].getNumber() == "000-000-000");
	
	CHECK(vector[1].getName() == "John Mick");
	CHECK(vector[1].getNumber() == "111-000-111");
}

TEST_CASE("Parsing contact with many things before number", "[ParserTest]")
{
	Parser parser;
	std::string s = "../test_long_prenumber.vcf";
	
	std::vector<Contact> vector = parser.parse(s);
	
	CHECK(vector[0].getNumber() == "333-222-111");
}

TEST_CASE("Parsing contact with encoded name", "[ParserTest]")
{
	Parser parser;
	std::string s = "../test_encoded.vcf";
	
	std::vector<Contact> vector = parser.parse(s);
	
	CHECK(vector[0].getName() == "Jonh Gorbe");
}

TEST_CASE("Parsing contact with carrige return on the end", "[ParserTest]")
{
	Parser parser;
	std::string s = "../smartphone.vcf";
	
	std::vector<Contact> vector = parser.parse(s);
	
	CHECK(vector[0].getName() == "AMa");
}
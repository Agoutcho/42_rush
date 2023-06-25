#include "Parser.h"

Parser::Parser(std::ifstream	&&ifFile) : file(std::move(ifFile))
{
	regexLowCase.assign(std::regex("([a-z]+)"));
	wordSize = 0;
}

bool	Parser::manageLineError(std::string line)
{
	if (line.empty())
	{
		std::cerr << "Error: Line " << lineCounter << " is empty." << std::endl;
		return (false);
	}
	if (!std::regex_match(line, regexLowCase))
	{
		std::cerr << "Error: Line " << lineCounter;
		std::cerr << " '" << line << "' has to be a lowercase word." << std::endl;
		return (false);
	}
	if (wordSize && line.size() != wordSize)
	{
		std::cerr << "Error: Line " << lineCounter;
		std::cerr << " '" << line << "' doesn't match the size of " ;
		std::cerr << wordSize << "." << std::endl;
		return (false);
	}
	return (true);
}

Parser::~Parser()
{
	file.close();
}

bool	Parser::setWordOfDay()
{
	if (words.size() == 0)
	{
		std::cerr << "Error: no words to set Word of day" << std::endl;
		return (false);
	}
	wordOfDay = words[(time(0) / 84600) % words.size()];
	return (true);
}

bool Parser::parseWords()
{
	std::string	line;

	std::getline(file, line);
	lineCounter = 1;
	if (!manageLineError(line))
		return (false);
	wordSize = line.size();
	words.push_back(line);
	line.clear();
	while(std::getline(file, line))
	{
		lineCounter++;
		if (!manageLineError(line))
			return (false);
		words.push_back(line);
		line.clear();
	}
	return (true);
}

size_t	Parser::getSize()
{
	return (words.size());
}
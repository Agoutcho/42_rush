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

bool	Parser::manageWordError(std::string line)
{
	if (line.empty())
	{
		std::cout << "Empty word." << std::endl;
		return (false);
	}
	if (!std::regex_match(line, regexLowCase))
	{
		std::cerr << "Your word has to contain only lowercase letters." << std::endl;
		return (false);
	}
	if (wordSize && line.size() != wordSize)
	{
		std::cerr << "The word to find is " << wordSize << " lenght." << std::endl;
		return (false);
	}
	if (!isValidWord(line))
	{
		std::cerr << "Invalid word." << std::endl;
		return (false);
	}
	return (true);
}

bool	Parser::isValidWord(std::string line)
{
	for (std::string	c : words)
	{
		if (!c.compare(line))
			return (true);
	}
	return (false);
}

void	Parser::computeWord(std::string line)
{
	size_t										temp = 0;
	std::vector<std::map<char, std::string>>	finalWord(wordSize);
	std::string									tempWord = wordOfDay;

	std::cout << "\033M\033[2K\r";
	for (size_t i = 0; i < wordSize; i++)
	{
		temp = tempWord.find(line[i]);
		if (temp == std::string::npos)
		{
			finalWord[i].insert(std::pair<char , std::string>(line[i], "\033[0m"));
			line[i] = 1;
		}
		else if (temp == i)
		{
			finalWord[i].insert(std::pair<char , std::string>(line[i], "\033[1;32m"));
			line[i] = 1;
			tempWord[temp] = 2; 
		}
	}
	for (size_t i = 0; i < wordSize; i++)
	{
		if (line[i] == 1)
			continue ;
		temp = tempWord.find(line[i]);
		if (temp == std::string::npos)
		{
			finalWord[i].insert(std::pair<char , std::string>(line[i], "\033[0m"));
			line[i] = 1;
		}
		if (temp != std::string::npos)
		{
			finalWord[i].insert(std::pair<char , std::string>(line[i], "\033[1;33m"));
			line[i] = 1;
			tempWord[temp] = 2;
		}
	}
	std::cout << "\t\t";
	for (size_t i = 0; i < wordSize ; i++)
	{
		std::map<char, std::string>::iterator it;
		it = finalWord[i].begin();
		std::cout << it->second << it->first;
	}
	std::cout << "\033[0m" << std::endl;
}
#ifndef PARSER_H
#define PARSER_H

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <regex>

class Parser
{
private:
	std::ifstream				file;
	uint64_t					lineCounter;
	uint64_t					wordSize;
	std::regex					regexLowCase;
public:
	std::vector<std::string>	words;
	std::string		wordOfDay;
	Parser(std::ifstream	&&ifFile);
	~Parser();
	bool			manageLineError(std::string	line);
	bool			setWordOfDay();
	bool			parseWords();
	size_t			getSize();
};


#endif /* PARSER_H */

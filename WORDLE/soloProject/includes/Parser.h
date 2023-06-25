#ifndef PARSER_H
#define PARSER_H

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <regex>
#include <map>

class Parser
{
private:
	std::ifstream				file;
	uint64_t					lineCounter;
	uint64_t					wordSize;
	std::regex					regexLowCase;
	bool			isValidWord(std::string line);
public:
	std::vector<std::string>	words;
	std::string		wordOfDay;
	Parser(std::ifstream	&&ifFile);
	~Parser();
	bool			manageLineError(std::string	line);
	bool			setWordOfDay();
	bool			parseWords();
	size_t			getSize();
	bool			manageWordError(std::string line);
	void			computeWord(std::string line);
};


#endif /* PARSER_H */

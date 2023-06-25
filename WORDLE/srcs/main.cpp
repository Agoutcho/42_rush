#include "Parser.h"

#define FILENAME "words.txt"

using namespace std;

bool	is_line_in_words(vector<string>	all_words, std::string line)
{
	for (std::string	c : all_words)
	{
		if (!c.compare(line))
			return (true);
	}
	return (false);
}

int main (int argc, char **argv) {
	ifstream					file(FILENAME);
	string						line;

	(void)argv;
	if (argc != 1)
	{
		std::cerr << "Usage: ./wordle" << std::endl;
		return (EXIT_FAILURE);
	}
	if (file.fail() || !file.is_open())
	{
		std::cerr << "Error: can't open : " << FILENAME <<  std::endl;
		return (EXIT_FAILURE);
	}
	Parser	fs(std::move(file));
	if (!fs.parseWords() || !fs.setWordOfDay())
		return (EXIT_FAILURE);
	cout << "Total words available: " << fs.getSize() << endl;
	cout << "You are looking for: " << fs.wordOfDay << endl;
	line.clear();
	// cout << "Enter your word :" << endl;
	// cin >> line;
	// if (line.size() != 5)
	// {
	// 	cout << "WTF ?!!" << endl;
	// 	return (0);
	// }
	// if (is_line_in_words(fs.words, line) && !fs.wordOfDay.compare(line))
	// 	cout << "Nice !" << endl;
	return 0;
}
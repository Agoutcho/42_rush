#include "Parser.h"

#define FILENAME "words.txt"
#define	LIVES	6

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
	ifstream	file(FILENAME);
	string		line;
	int			playerLives = LIVES;

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
	while (playerLives > 0)
	{
		// print the keyboard
		line.clear();
		cout << "Live left : \033[1;31m" << playerLives << "\033[0m" << std::endl;
		cout << "Enter your word :" << endl;
		cin >> line;
		if (line.empty())
			return (0);
		std::cout << "\033M\033[2K\r";
		std::cout << "\033M\033[2K\r";
		if (!fs.manageWordError(line))
			continue ;
		fs.computeWord(line);
		if (!fs.wordOfDay.compare(line))
		{
			std::cout << "Congrats you find the word !" << std::endl;
			return (0);
		}
		playerLives--;
	}
	std::cout << "Loser." << std::endl;
	return (0);
}
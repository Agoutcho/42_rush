#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <ctime>

using namespace std;

std::string word_of_day(vector<string>	all_words)
{
	return (all_words[(time(0) / 84600) % all_words.size()]);
}

bool	is_line_in_words(vector<string>	all_words, std::string line)
{
	for (std::string	c : all_words)
	{
		if (!c.compare(line))
			return (true);
	}
}

int main () {
	ifstream					file("words.txt");
	vector<string>				all_words;
	vector<string>::iterator	it;
	string						line;
	string						w_of_day;
	
	
	// check si fail
	it = all_words.end();
	getline(file, line);
	all_words.insert(it, line);
	while(!file.eof())
	{
		line.clear();
		it = all_words.end();
		getline(file, line);
		all_words.insert(it, line);
	}
	cout << "Total words available: " << all_words.size() << endl;
	w_of_day = word_of_day(all_words);
	cout << "You are looking for: " << word_of_day(all_words) << endl;
	line.clear();
	cout << "Enter your word :" << endl;
	cin >> line;
	if (line.size() != 5)
	{
		cout << "WTF ?!!" << endl;
		return (0);
	}
	if (is_line_in_words(all_words, line) && !w_of_day.compare(line))
		cout << "Nice !" << endl;
	return 0;
}
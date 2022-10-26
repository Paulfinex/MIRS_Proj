#include <iostream>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <cctype>
#include <fstream>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <sstream>
#include <sstream>
#include <fstream>
#include <codecvt>

#include "../headers/olestem/stemming/english_stem.h"

std::vector<std::string> tokenize_text(std::string body)
{
	
	std::stringstream ss(body);
	std::istream_iterator<std::string> begin(ss);
	std::istream_iterator<std::string> end;
	std::vector<std::string> vstrings(begin, end);
	std::copy(vstrings.begin(), vstrings.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
	return vstrings;

}

std::string vector_to_string(std::vector <std::string> vec)
{
	std::string string_builder;
		for (std::vector<std::string>::const_iterator i = vec.begin(); i != vec.end(); ++i)
		{
			string_builder += *i + " ";
		}
	return string_builder;
}

std::string remove_stopwords(std::string body)
{
	//Setup file variable ( TODO use ARGV )

	std::string line;
	std::ifstream file_stopword("C:\\Users\\Papera\\Desktop\\MIRS Project\\stopwords.txt");

	std::vector<std::string> words = tokenize_text(body);
	//Iterate lines in file
	if (file_stopword.is_open())
	{
		while (getline(file_stopword, line))
		{

			//Remove the stopword from the vector
			if (find(words.begin(), words.end(), line) != words.end())
			{
				words.erase(std::remove(words.begin(), words.end(), line), words.end());
			}

		}
	}
	return vector_to_string(words);
}



std::string remove_punctuation(std::string body)
{

	std::string str_to_process = body;
	std::regex regexp("[A-Za-z0-9]{1,}");
	std::smatch match;
	//Search in the query for a match
	regex_search(str_to_process, match, regexp);
	//Create an iterator to loop the matches
	std::sregex_iterator currentMatch(str_to_process.begin(), str_to_process.end(), regexp);
	std::sregex_iterator lastMatch;

	std::vector<std::string> words{};

	//Iterate over all the regex matches
	while (currentMatch != lastMatch)
	{

		std::smatch m = *currentMatch;
		std::string lower_match = m.str();

		for (int i = 0; i < lower_match.length(); i++)
		{
			lower_match[i] = tolower(lower_match[i]);
		}

		//Push current match in the string vector
		words.push_back(lower_match);

		currentMatch++;

	}

	return vector_to_string(words);

}










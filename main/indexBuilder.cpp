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
using namespace std;



int main(int argc, char const *argv[]){
  /**
   * @todo reading file line-by-line and foreach line{
   *    tolowercase
   *    punctuation and extra characters removal
   *    space normalization(removing extra spaces and trim)
   *    stopwords removal
   *    stemming
   * } 
   */
  return 0;
}



vector<string> tokenize_text(string body)
{
	
	std::stringstream ss(body);
	std::istream_iterator<std::string> begin(ss);
	std::istream_iterator<std::string> end;
	std::vector<std::string> vstrings(begin, end);
	std::copy(vstrings.begin(), vstrings.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
	return vstrings;

}

string vector_to_string(vector <string> vec)
{

	string string_builder;
		for (vector<string>::const_iterator i = vec.begin(); i != vec.end(); ++i)
		{
			string_builder += *i + " ";
		}
	return string_builder;
}

string remove_stopwords(string body)
{
	//Setup file variable ( TODO use ARGV )

	string line;
	ifstream file_stopword("C:\\Users\\Papera\\Desktop\\MIRS Project\\stopwords.txt");

	vector<string> words = tokenize_text(body);
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



string remove_punctuation(string body)
{

	string str_to_process = body;
	regex regexp("[A-Za-z0-9]{1,}");
	smatch match;
	//Search in the query for a match
	regex_search(str_to_process, match, regexp);
	//Create an iterator to loop the matches
	sregex_iterator currentMatch(str_to_process.begin(), str_to_process.end(), regexp);
	sregex_iterator lastMatch;

	vector<string> words{};

	//Iterate over all the regex matches
	while (currentMatch != lastMatch)
	{

		smatch m = *currentMatch;
		string lower_match = m.str();

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










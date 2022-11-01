#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>
#include <sstream>
#include <codecvt>
#include "../headers/olestem/stemming/english_stem.h"

/**
 * @brief function converting a string into its tokens
 * 
 * @param body the string to be tokenized
 * @return the vector of the tokens
 */
std::vector<std::string> tokenize_text(std::string body)
{
	std::stringstream ss(body);
	std::vector<std::string> vstrings;
	while(!ss.eof())
		{
			std::string word;
			ss >> word;
			if (!word.empty() && word.length()>1)
			{
				vstrings.push_back(word);
			}
		}
	return vstrings;
}

/**
 * @brief function to convert a vector of tokens into a space-separated string
 * 
 * @param vec the vector to be converted
 * @return a space-separated string with all the elements of the passed vector
 */
std::string vector_to_string(std::vector <std::string> vec)
{
	std::string string_builder;
		for (const auto& item : vec) {
			string_builder += item + " ";
		}
	return string_builder;
}

/**
 * @brief function removing the stopwords from a string, the function will read from a file
 * the list of stopwords line-by-line and will erase iteratively from the body parameter the found stopwords
 * 
 * @param body the string from where to remove stopwords
 * @return modified string without stopwords
 */
std::vector<std::string> remove_stopwords(std::vector<std::string> words)
{
	std::string line;
	std::ifstream file_stopword("../data/input/stopwords.txt");
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
	return words;
}

void debug(std::string s){
	std::cout << s << std::endl;
	std::system("pause");
}

/**
 * @brief function to trim a given string
 * 
 * @param s the string to trim 
 * @return the trimmed string
 */
std::string trim(std::string s){
	std::regex ltrim("^\\s+");
	std::regex rtrim("$\\s+");
	return regex_replace(regex_replace(s, ltrim, ""),rtrim,"");
}

/**
 * @brief function normalizing the passed string
 * 
 * @param body the string to be normalized
 * @return normalized string
 */
std::string normalize_text(std::string body)
{
	std::string text = body;
	// regex for extra characters removal
	std::regex extraChar("[^\\w\\s]+");
	// regex for extra spaces removal
	std::regex extraSpace("\\s+");
	// lowercasing
	transform(text.begin(), text.end(), text.begin(), tolower);
	// replacing and trimming of the text string
	text = trim(regex_replace(regex_replace(text, extraChar, ""), extraSpace, " "));
	return text;
}

/**
 * @brief function that converts a string to it's utf-8 representation
 * 
 * @param s the string to be converted
 * @return the utf-8 representation of the string
 */
std::wstring convert_to_wstring(std::string s){
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
	return converter.from_bytes(s);
}

/**
 * @brief function that converts an utf-8 representation string to a standard string of bytes
 * 
 * @param s the utf-8 string to be converted
 * @return bytes representation of the utf-8 string
 */
std::string convert_to_string(std::wstring s){
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
	return converter.to_bytes(s);
}


/**
 * @brief function that splits a string to its stemmed tokens using Porter's Stemming
 * 
 * @param text string to be stemmed and tokenized
 * @return vector of stemmed tokens
 */
std::vector<std::string> stemmer(std::vector<std::string> docsTokens) {

	std::vector<std::string> resultToken;
	stemming::english_stem<> EngStemmer;
	for (std::string s : docsTokens) {
		std::wstring tmp = convert_to_wstring(s);
		EngStemmer(tmp);
		s = convert_to_string(tmp);
		resultToken.push_back(s);
	}
	return resultToken;

}
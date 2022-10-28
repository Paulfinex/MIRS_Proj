#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>
#include <sstream>
#include <locale>
#include <codecvt>
#include <chrono>
#include <map>
#include "../headers/olestem/stemming/english_stem.h"



//Return a vector composed by each separate token in a string
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

//Return a string with all the vector elements separated by space
std::string vector_to_string(std::vector <std::string> vec)
{
	std::string string_builder;
		for (const auto& item : vec) {
			string_builder += item + " ";
		}
	return string_builder;
}

std::string remove_stopwords(std::string body)
{
	std::string line;
	std::ifstream file_stopword("../data/input/stopwords.txt");

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
	std::string text = body;
	std::regex regexp("[A-Za-z0-9]{1,}");
	std::smatch match;
	//Search in the query for a match
	std::regex_search(text, match, regexp);
	//Create an iterator to loop the matches
	std::sregex_iterator currentMatch(text.begin(), text.end(), regexp);
	std::sregex_iterator lastMatch;

	std::vector<std::string> words{};

	//Iterate over all the regex matches
	while (currentMatch != lastMatch)
	{

		std::smatch m = *currentMatch;
		std::string lower_match = m.str();

		//Lowercase string
		std::transform(lower_match.begin(), lower_match.end(), lower_match.begin(), ::tolower);

		//Push current match in the string vector
		words.push_back(lower_match);

		currentMatch++;

	}
	
	return vector_to_string(words);

}

//Convert from sting to wstring
std::wstring convert_to_wstring(std::string s){
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
	return converter.from_bytes(s);
}

//Convert from wstring to string
std::string convert_to_string(std::wstring s){
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
	return converter.to_bytes(s);
}


// Stemming
std::vector<std::string> text_stemming(std::string text) 
{

	std::vector<std::string> docsToken = tokenize_text(text);
	std::vector<std::string> resultToken;
	stemming::english_stem<> EngStemmer;
	for (std::string s : docsToken) {
		std::wstring tmp = convert_to_wstring(s);
		EngStemmer(tmp);
		s = convert_to_string(tmp);
		resultToken.push_back(s);
	}
	return resultToken;

}

void doc_index(std::string docno, std::string docbody, int docid)
{
	std::cout << docno + "," <<docid<<","<< docbody.length() << std::endl;
	int len = docbody.length();
	//Todo write to file (docno,docid,len)
}

void inverted_index(int docid,std::vector<std::string> stem_words,std::map<std::string, std::vector<std::tuple<int,int>>> invIndex)
{
	std::vector<std::string> unique_words = stem_words;
	unique_words.erase(unique(unique_words.begin(), unique_words.end()), unique_words.end());

	std::map<std::string, std::vector<std::tuple<int, int>>>tmpIndex = invIndex;
	std::tuple <int, int> docid_freq;
	for (std::string s : unique_words)
	{
		int word_count = count(stem_words.begin(), stem_words.end(), s);
		docid_freq = std::make_tuple(docid, word_count);
		
		std::cout << s << " " << docid << "," << word_count << std::endl;
		//TODO insert in map
		//tmpIndex.insert({ s,docid_freq });
	}


}
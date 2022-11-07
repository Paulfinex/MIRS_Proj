#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
/**
 *@brief Function to write a vector of stings to a file
 *
 *@param path the path of the output file
 * @param text the string to be written on the file
 *
 */

void write_vec_to_file(std::string path, std::vector<std::string> vec)
{
	std::ofstream ofile;
	ofile.open(path, std::ios_base::app);
	for (std::string s : vec)
	{
		ofile << s;
	}
	ofile.close();
}

/**
 * @brief function to create a docindex entry
 *
 * @param docno the docid taken from the input file
 * @param docSize possiamo passare solo la length del docbody?
 * @param docid the mapped docid for the docno
 */
std::string doc_index(std::string docno, int docSize, int docid)
{
	std::string doc_entry = std::to_string(docid) + "," + docno + "," + std::to_string(docSize) + '\n';
	// std::cout << doc_enty<<endl;
	return doc_entry;
}

void test_map(std::map<std::string, std::vector<std::string>> invIndexMap)
{
	std::map<std::string, std::vector<std::string>>::iterator it;

	for (it = invIndexMap.begin(); it != invIndexMap.end(); it++)
	{
		std::cout << it->first << ':';
		for (std::string s : it->second)
		{
			std::cout << s;
		}
		std::cout << '\n';
	}
}

std::map<std::string, std::vector<std::string>> inverted_index(int docid, std::vector<std::string> stem_words, std::map<std::string, std::vector<std::string>> invIndexMap)
{
	std::map<std::string, std::vector<std::string>> tmpMap = invIndexMap;
	std::vector<std::string> unique_words = stem_words;
	std::vector<std::string> invInd;
	std::sort(unique_words.begin(), unique_words.end());
	unique_words.erase(unique(unique_words.begin(), unique_words.end()), unique_words.end());
	for (std::string s : unique_words)
	{

		
		if (s == "")
		{
			continue;
		}
		int word_count = count(stem_words.begin(), stem_words.end(), s);
		if (tmpMap.find(s) == tmpMap.end())
		{
			// not found
			std::vector<std::string> tmpVec;
			tmpVec.push_back("[" + std::to_string(docid) + "," + std::to_string(word_count) + "]");
			tmpMap[s] = tmpVec;
			// std::cout << s << " not found" << std::endl;
		}
		else
		{
			// found
			std::vector<std::string> tmpVec;
			auto it = tmpMap.find(s);
			tmpVec = it->second;
			tmpVec.push_back("[" + std::to_string(docid) + "," + std::to_string(word_count) + "]");
			tmpMap.at(s) = tmpVec;
			// std::cout << s << " found" << std::endl;
		}
	}
	return tmpMap;
}

std::vector<std::string> vocabulary(std::map<std::string, std::vector<std::string>> invIndexMap)
{
	std::vector<std::string> vocabulary_vec;
	int t_count = 0;
	std::string str_builder;

	for (std::map<std::string, std::vector<std::string>>::iterator iter = invIndexMap.begin(); iter != invIndexMap.end(); ++iter)
	{
		std::string s = iter->first;
		str_builder = s + "," + std::to_string(t_count) + "," + std::to_string(iter->second.size()) + '\n';
		vocabulary_vec.push_back(str_builder);
		t_count++;
	}
	return vocabulary_vec;
}
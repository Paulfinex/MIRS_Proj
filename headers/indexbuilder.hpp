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



std::vector<std::string> inverted_index(int docid, std::vector<std::string> stem_words)
{
	std::vector<std::string> unique_words = stem_words;
	std::vector<std::string> invInd;
	std::sort(unique_words.begin(), unique_words.end());
	unique_words.erase(unique(unique_words.begin(), unique_words.end()), unique_words.end());
	for (std::string s : unique_words)
	{

		std::string str_builder = "";
		int word_count = count(stem_words.begin(), stem_words.end(), s);
		str_builder+=s+":["+std::to_string(docid)+","+ std::to_string(word_count)+"]\n";
		invInd.push_back(str_builder);
	}
	return invInd;
}

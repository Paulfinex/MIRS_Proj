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
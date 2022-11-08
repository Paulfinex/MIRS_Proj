#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

/**
 * @brief function appending the document to the doc_index file @ "../data/output/doc_index.out" in binary
 * 
 * @param docno the docid taken from the input file
 * @param docbody possiamo passare solo la length del docbody?
 * @param docid the mapped docid for the docno
 */
void doc_index(std::string docno, std::string docbody, int docid)
{
	std::cout << docno + "," <<docid<<","<< docbody.length() << std::endl;
	int len = docbody.length();
	//Todo write to file (docno,docid,len)
}

/**
 * @deprecated se dobbiamo analizzare documento per documento avremmo tutti i token, 
 * le frequenze e quant'altro per quel documento quindi basterebbe solamente fare l'append nel file
 * @ "../data/output/inv_index.out" inserendo il nuovo elemento della postings list in tutti i termini che appaiono
 * nel documento
 */
void inverted_index(int docid, std::vector<std::string> stem_words,std::map<std::string, std::vector<std::tuple<int,int>>> invIndex)
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


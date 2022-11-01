#include "../headers/olestem/stemming/english_stem.h"
#include "../headers/text_normalization.hpp"
#include "../headers/indexbuilder.hpp"
using namespace std;

int main(int argc, char const *argv[])
{


  /**
   * @todo reading file line-by-line and foreach line{
   *    punctuation and extra characters removal
   *    space normalization(removing extra spaces and trim)
   *    tolowercase of the single tokens2
   *    stopwords removal by simply not inserting the token if it is in the stopwords
   *    stemming
   *    saving of the token into vocabulary where we save for each termid the length of the posting list
   *    saving the posting list data structure as a sorted skipping list for each token
   * }
   */


  
  map<std::string, vector<tuple<int, int>>> invIndex;
 
  
  size_t docCount = 0;
  unsigned int chunkCount = 0;
  ifstream infile;

  vector<string> docIndexChunk;
  try
  {
    infile.open("../data/input/collection.tsv");
    if (!infile.is_open())
    {
      throw new ifstream::failure("Invalid input file for index building");
    }
    while (!infile.eof())
    {
      string docno;
      string docbody;

      // document-by-document reading of the documents
      getline(infile, docno, '\t');
      getline(infile, docbody, '\n');

      // Skip empty docs
      if (docbody == "")
      {
        continue;
      }

      // text processing of the document
      docbody = normalize_text(docbody);
      vector<string> tokens = tokenize_text(docbody);
      tokens = remove_stopwords(tokens);
      vector<string> stem_tokens = stemmer(tokens);

      docCount++;
      chunkCount++;
            
      //inverted_index(docCount, stem_tokens, invIndex);
      int docLen = vector_to_string(tokens).length();
      string curr_doc_ind = doc_index(docno, docLen, docCount);
      docIndexChunk.push_back(curr_doc_ind);
      if (chunkCount == 5000) 
      {
        cout<<"Writing docIndex chunk to file. Last docNo processed:" << to_string(docCount)<<endl;
        write_vec_to_file("../data/output/docindex.txt",docIndexChunk);
        docIndexChunk.clear();
        chunkCount=0;
      }

 
    }
  }
  catch (ifstream::failure &e)
  {
    cout << e.what() << endl;
    exit(EXIT_FAILURE);
  }

  //Last chunk
  write_vec_to_file("../data/output/docindex.txt",docIndexChunk);
  docIndexChunk.clear();


  return 0;
}

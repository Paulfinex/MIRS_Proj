#include "../headers/olestem/stemming/english_stem.h"
#include "../headers/body_normalization.hpp"
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
  std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
  int count = 0;
  ifstream infile;

  vector<string> docIndexChunk;
  try
  {
    infile.open("../data/input/sample_dataframe_5000.tsv");
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
      count++;
      inverted_index(count, stem_tokens, invIndex);
      string curr_doc_ind = doc_index(docno, docbody, count);
      docIndexChunk.push_back(curr_doc_ind);
      if ((count % 500) == 0)
      {
        write_vec_to_file("../data/output/docindex.txt",docIndexChunk);
        docIndexChunk.clear();
      }
      /**
       * @todo implementing document table:
       *    docno to docid mapping
       *    each docno must be mapped to a docid and a body length
       *    body length must be calculated over the modified body to better assess the doc_score in ranking
       */
    }
  }
  catch (ifstream::failure &e)
  {
    cout << e.what() << endl;
    exit(EXIT_FAILURE);
  }
  write_vec_to_file("../data/output/docindex.txt",docIndexChunk);
  docIndexChunk.clear();
  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

  std::cout << "Time elapsed = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
  
  return 0;
}

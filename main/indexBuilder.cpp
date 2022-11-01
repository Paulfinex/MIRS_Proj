#include "../headers/olestem/stemming/english_stem.h"
#include "../headers/text_normalization.hpp"
#include "../headers/index_build.hpp"
#include "../headers/unicode/utf8.h"
#include <chrono>
using namespace std;


int main(int argc, char const *argv[]){
  
  map<std::string, vector<tuple<int, int>>> invIndex;
  std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
  int count = 0;
  ifstream infile;
  try{
    infile.open("../data/input/collection.tsv");
    if(!infile.is_open()){
      throw new ifstream::failure("Invalid input file for index building");
    }
    while(!infile.eof())
    {
      string docno;
      string docbody;

      // document-by-document reading of the documents
      getline(infile, docno, '\t');
      getline(infile, docbody, '\n');
      if(docbody.size() == 0) continue;

      // text processing of the document
      docbody = normalize_text(docbody);
      vector<string> tokens = tokenize_text(docbody);
      tokens = remove_stopwords(tokens);      
      vector<string> stem_tokens = stemmer(tokens);
      count++;
      inverted_index(count, stem_tokens, invIndex);
      cout << "_______" << endl << "Doc Index:";
      doc_index(docno, docbody, count);
      cout << endl;
    }
  }catch(ifstream::failure& e){
    cout << e.what() << endl;
    exit(EXIT_FAILURE);
  }

  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

  std::cout << "Time elapsed = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ms]" << std::endl;
  // std::system("pause");
  return 0;
}

#include "../headers/olestem/stemming/english_stem.h"
#include "../headers/text_normalization.hpp"
#include "../headers/index_build.hpp"
#include "../headers/u8lib/u8.hpp"
#include <chrono>
using namespace std;


int main(int argc, char const *argv[]){
  
  map<std::string, vector<tuple<int, int>>> invIndex;
  std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
  int count = 0;
  ifstream infile;
  try{
    infile.open("../data/input/sample_dataframe_5000.tsv");
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
      docbody=u8lib::to_cppstring(u8lib::to_u8string(docbody));
      // text processing of the document
      docbody = normalize_text(docbody);
      vector<string> tokens = tokenize_text(docbody);
      tokens = remove_stopwords(tokens);
      string tmp = "";
      //tmp= vector_to_string(tokens);
      //cout << tmp << endl;      
      vector<string> stem_tokens = stemmer(tokens);
      count++;
      //inverted_index(count, stem_tokens, invIndex);
      //cout << "_______" << endl << "Doc Index:";
      //doc_index(docno, docbody, count);
      
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

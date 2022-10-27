#include "../headers/olestem/stemming/english_stem.h"
#include "../headers/body_normalization.hpp"
using namespace std;

int main(int argc, char const *argv[]){
  /**
   * @todo reading file line-by-line and foreach line{
   *    punctuation and extra characters removal
   *    space normalization(removing extra spaces and trim)
   *    tolowercase of the single tokens
   *    stopwords removal by simply not inserting the token if it is in the stopwords
   *    stemming
   *    saving of the token into vocabulary where we save for each termid the length of the posting list
   *    saving the posting list data structure as a sorted skipping list for each token
   * } 
   */
  try{
    ifstream infile("../data/input/sample_dataframe.tsv");
    while(!infile.eof()){
      string docno;
      string docbody;
      // document-by-document reading of the documents
      getline(infile, docno, '\t');
      getline(infile, docbody, '\n');
      // text processing of the document
      docbody = remove_punctuation(docbody);
      docbody = remove_stopwords(docbody);
      vector<string> docsToken = tokenize_text(docbody);
      // stemming
      stemming::english_stem<> EngStemmer;
      for(string s: docsToken){
        wstring tmp = convert_to_wstring(s);
        EngStemmer(tmp);
        s = convert_to_string(tmp);
        cout << s << endl;
      }
      system("pause");

      /**
       * @todo implementing document table:
       *    docno to docid mapping
       *    each docno must be mapped to a docid and a body length
       *    body length must be calculated over the modified body to better assess the doc_score in ranking
       */
      
    }
  }catch(ifstream::failure& e){
    cout << e.what() << endl;
    exit(EXIT_FAILURE);
  }
  
  return 0;
}

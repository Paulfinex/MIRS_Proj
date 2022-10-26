#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <locale>
#include <codecvt>
#include "../headers/olestem/stemming/english_stem.h"
using namespace std;

int main(int argc, char const *argv[]){
  filesystem::path infilePath("../data/input/sample_dataframe.tsv");
  try{
    wifstream infile(infilePath, ios::in);
    while(!infile.eof()){
      wstring docbody;
      wstring docno;
      getline(infile, docno, L'\t');
      getline(infile, docbody, L'\n');
      wstring_convert<std::codecvt<char16_t, wchar_t, mbstate_t>, char16_t> converter;
      u16string _docno = converter.from_bytes(docno);
      if(docno == L"5997279"){
        wcout << docno << L">> " << docbody << L"\n";
        system("pause");
      }else{
        wcout << docno << L">> " << docbody << L"\n";
      }
    }
  }
  catch(const wifstream::failure& e)
  {
    std::cerr << e.what() << '\n';
  }
  
  return 0;
}

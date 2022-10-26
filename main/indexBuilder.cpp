#include <iostream>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <cctype>
#include <fstream>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <sstream>
#include <sstream>
#include <fstream>
#include <codecvt>

#include "../headers/olestem/stemming/english_stem.h"
#include "../headers/body_normalization.hpp"
using namespace std;

vector<string> tokenize_text();
string vector_to_string();
string remove_stopwords();
string remove_punctuation();

int main(int argc, char const *argv[]){
  /**
   * @todo reading file line-by-line and foreach line{
   *    tolowercase
   *    punctuation and extra characters removal
   *    space normalization(removing extra spaces and trim)
   *    stopwords removal
   *    stemming
   * } 
   */
  return 0;
}

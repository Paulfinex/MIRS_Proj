#pragma once
#include <fstream>
#include <vector>

struct u8char{
  std::vector<char> bytes;
  unsigned int nbytes;
  size_t decimal;
};

struct u8string{
  std::vector<u8char> characters;
  size_t length;
};

/**
 * @brief counts the number of consecutive 1s from the most significant bit for a first utf8-string byte hence
 * counting the total bytes that are necessary to read to represent the utf8 character
 * 
 * @param c the byte
 * @return the number of consecutive 1s starting from the most significant bit
 */
unsigned int count_nbytes(char c){
  for (int i = 0; i < 7; i++, c=c<<1){
    if ((c & 128) == 0) return i == 0 ? 1 : i;
  }
  return 6; // maximum number of consecutive 1s in the first byte of utf-8 chars
}

int calcDec(char c, bool isFirst, int nbytes){
  if(isFirst){
    char mask = (char)255 << (8 - nbytes);
    return c ^ mask;
  }else{
    return c ^ (char)128;
  }
}

/**
 * @brief creates a u8string representation for the given string
 * 
 * @param s string to be represented in utf8
 * @return u8string representation of the string s
 */
u8string to_u8string(std::string s){
  std::vector<char> bytes(s.begin(), s.end());
  u8string result;
  result.length = 0;
  for (int i = 0; i < bytes.size();){
    int nbytes = count_nbytes(bytes[i]);
    result.length+=1;
    u8char tmp;
    tmp.nbytes = nbytes;
    tmp.decimal = 0;
    if(nbytes > 1){
      tmp.decimal += calcDec(bytes[i], true, nbytes);
    }else{
      tmp.decimal += bytes[i];
    }
    for (int j = 1; j < nbytes; j++){
      tmp.bytes.push_back(bytes[i]);
      tmp.decimal += calcDec(bytes[i + j], false, nbytes);
    }
    result.characters.push_back(tmp);
    i += nbytes;
  }
  return result;
}
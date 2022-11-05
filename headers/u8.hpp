#pragma once
#include <fstream>
#include <vector>
#include <cmath>

struct u8char{
  char* bytes;
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
  u8string result;
  result.length = 0;
  for (int i = 0; i < s.size();){
    int nbytes = count_nbytes(s[i]);
    result.length+=1;
    u8char tmp;
    tmp.nbytes = nbytes;
    tmp.bytes = (char*)malloc((nbytes + 1) * sizeof(char));
    tmp.bytes[0] = s[i];
    tmp.decimal = 0;
    if(nbytes > 1){
      tmp.decimal += (calcDec(s[i], true, nbytes)*pow(64,nbytes-1));
    }else{
      tmp.decimal += s[i];
      tmp.bytes[1] = '\0';
    }
    for (int j = 1; j < nbytes; j++){
      tmp.bytes[j] = s[i + j];
      tmp.decimal += (calcDec(s[i + j], false, nbytes)*pow(64,nbytes-j-1));
      if(j == nbytes-1){
        tmp.bytes[j + 1] = '\0';
      }
    }
    result.characters.push_back(tmp);
    i += nbytes;
  }
  return result;
}
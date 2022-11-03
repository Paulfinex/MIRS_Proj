#pragma once
#include <fstream>
#include <vector>

struct u8char{
  char* bytes;
  unsigned int nbytes;
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

/**
 * @brief will read the next unicode character
 * 
 * @param infile file to read from
 * @return u8char* the sequence of bytes composing the unicode character
 */
u8char readUnicode(std::ifstream& infile){
  char byte;
  infile.read(&byte, 1);
  size_t const nbytes = count_nbytes(byte); // this will return the number of 1s corresponding to the number of total bytes
  u8char res;
  res.nbytes = nbytes;
  res.bytes = (char*)malloc(nbytes * sizeof(char)); // this will initialize an array of
  res.bytes[0] = byte;
  for (int i = 1; i < nbytes; i++){
    char tmp;
    infile.read(&tmp, 1);
    res.bytes[i] = tmp;
  }
  return res;
}

/**
 * @brief creates a u8string representation for the given string
 * 
 * @param s string to be represented in utf8
 * @return u8string representation of the string s
 */
u8string to_u8string(std::string s){
  u8string result;
  unsigned int len = 0;
  for (size_t i = 0; i < s.length();){
    size_t nbytes = count_nbytes(s[i]);
    u8char codepoint;
    codepoint.nbytes = nbytes;
    codepoint.bytes = (char*)malloc((nbytes+1) * sizeof(char));
    for (int j = 0; j < nbytes; j++){
      codepoint.bytes[j] = s[i+j];
      if(j == nbytes-1){
        codepoint.bytes[j + 1] = '\0';
      }
    }
    i += nbytes;
    result.characters.push_back(codepoint);
  }
  result.length = result.characters.size();
  return result;
}


/**
 * @brief read-write example
 */
// void mainExample(){
//   ifstream infile("file.txt", ios::binary);
//   ofstream outfile("out.txt", ios::binary | ios::trunc);
//   do{
//     u8char nextUTF8 = readUnicode(infile);
//     outfile.write(nextUTF8.c, nextUTF8.nbytes);
//   } while (!infile.eof());
// }
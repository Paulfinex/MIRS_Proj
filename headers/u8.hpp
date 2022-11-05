#pragma once
#include <vector>
#include <sstream>
#include <cmath>
/**
 * @brief struct representing a single utf8 character composed by nbytes, including its decimal representation
 */
struct u8char{
  char* bytes;
  unsigned int nbytes;
  size_t decimal;
};

/**
 * @brief struct representing an utf8 string using a vector of u8char and a length parameter to help iterating over it
 */
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
  // i<7 because at most we can count 6 bytes in a utf8 encoding
  for (int i = 0; i < 7; i++, c=c<<1){
    // checking if the current most significant bit is a 1 using a bitwise and
    if ((c & 128) == 0) return i == 0 ? 1 : i;
  }
  return 6; // maximum number of consecutive 1s in the first byte of utf-8 chars
}

/**
 * @brief function getting the decimal representation of a codepoint's byte
 * 
 * @param c the byte of the codepoint
 * @param isFirst if it is the first byte of the codepoint
 * @param nbytes the total number of bytes in the codepoint
 * @return the decimal representation of the codepoint's byte
 */
int calcDec(char c, bool isFirst, int nbytes){
  if(isFirst){
    // to get the mask for the 1st byte we left shift 11111111 of 8-nbytes so we get nbytes-1 bits to 1 on the most significant ones
    char mask = (char)255 << (8 - nbytes);
    // then we return the bitwise or between the byte c and the mask obtained to get the real binary of the byte without control bits
    return c ^ mask;
  }else{
    // if it is not the first byte we just use 10000000 as mask and we compute the bitwise or
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
    // we alternate a count_nbytes for the i-th byte and nbytes-1 iterations over the sequent bytes finally jumping of i+nbytes
    int nbytes = count_nbytes(s[i]);

    // we count the number of u8chars as length, instead of the number of total bytes
    result.length+=1;

    // u8char initialization
    u8char tmp;
    tmp.nbytes = nbytes;
    tmp.bytes = (char*)malloc((nbytes + 1) * sizeof(char)); // allocating the number of characters needed for the current u8char
    tmp.bytes[0] = s[i];
    tmp.decimal = 0; // to make the decimal count start to 0 otherwise we get what's in the actual memory cell dedicated to decimal
    
    if(nbytes > 1){
      tmp.decimal += (calcDec(s[i], true, nbytes)*pow(64,nbytes-1));
    }else{
      // simple ascii character
      tmp.decimal += s[i];
      tmp.bytes[1] = '\0'; // to make cpp iterator-based loops over char* stop correctly
    }

    // starting from 1 because we already computed the first byte, ending to nbytes-1 nbytes is the length counting from 1
    // but we instead start indexing from 0
    for (int j = 1; j < nbytes; j++){
      tmp.bytes[j] = s[i + j];
      tmp.decimal += (calcDec(s[i + j], false, nbytes)*pow(64,nbytes-j-1));
      if(j == nbytes-1){
        tmp.bytes[j + 1] = '\0'; // to make cpp iterator-based loops over char* stop correctly
      }
    }
    result.characters.push_back(tmp);
    i += nbytes;
  }
  return result;
}

/**
 * @brief function converting an u8string to a classical cpp string made of bytes
 * 
 * @param s the utf8-encoded string
 * @return the classic c++'s byte-based representation of a string 
 */
std::string to_cppstring(u8string s){
  std::string result;
  std::stringstream ss;

  // we first write all the bytes into a stream of char
  for (int i = 0; i < s.length; i++){
    ss.write(s.characters[i].bytes, s.characters[i].nbytes);
  }
  // then append string-representation of the stream into result
  result.append(ss.str());

  // finally we clear the string stream (just a security measure like filestream.close())
  ss.clear();
  ss.str("");
  return result;
}
#include <fstream>

struct u8char{
  char* c;
  size_t nbytes;
};

/**
 * @param c byte to check
 * @return the count of consecutive most significant 1s present in c
 */
int count_lones(char c){
  for (int i = 0; i < 8; i++,c=c<<1){
    if ((c & 128) == 0) return i == 0 ? i+1 : i;
  }
  return 8;
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
  size_t const nbytes = count_lones(byte); // this will return the number of 1s corresponding to the number of total bytes
  u8char res;
  res.nbytes = nbytes;
  res.c = (char*)malloc(nbytes * sizeof(char)); // this will initialize an array of
  res.c[0] = byte;
  for (int i = 1; i < nbytes; i++){
    char tmp;
    infile.read(&tmp, 1);
    res.c[i] = tmp;
  }
  return res;
}

/**
 * @brief usage example
 */
// void mainExample(){
//   ifstream infile("file.txt", ios::binary);
//   ofstream outfile("out.txt", ios::binary | ios::trunc);
//   do{
//     u8char nextUTF8 = readUnicode(infile);
//     outfile.write(nextUTF8.c, nextUTF8.nbytes);
//   } while (!infile.eof());
// }
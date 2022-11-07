#include <iostream>
#include <fstream>
#include <string>
#include "../headers/u8lib/u8.hpp"
#include <chrono>
using namespace std;

int main(int argc, char const *argv[]){
  ifstream infile("file.txt");
  ofstream outfile("out.txt", ios::trunc);
  std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
  while(!infile.eof()){
    string line;
    getline(infile, line, '\n');
    u8lib::u8string u8s = u8lib::to_u8string(line);
    line = u8lib::to_cppstring(u8s);
    outfile.write((line + "\n").c_str(), line.length() + 1);
  }
  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
  std::cout << "Time elapsed = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ms]" << std::endl;
  return 0;
}

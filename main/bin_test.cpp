#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>
#include <sstream>
#include <locale>
#include <codecvt>
#include <chrono>
#include <algorithm>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
    ifstream input("../data/input/file.txt", std::ios::binary);
    char a;
    while (!input.eof())
    {
        input.read((char *)&a, 1);
        string str_build = "";
        for (int i = 7; i > -1; --i)
        {
            bool is_set = a & (1 << i);
            if(is_set)
            {
                str_build+='1';
            }
            else
            {
                str_build+='0';
            }
        }
        cout << str_build<< " ";
    }

    input.close();
    return EXIT_SUCCESS;
}
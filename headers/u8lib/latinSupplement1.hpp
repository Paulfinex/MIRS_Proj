#pragma once
#include <iostream>
#include <map>

namespace u8lib{
  class LatinSupplement1{
    private:
      bool A_RANGE(size_t d){
        return (d == 170 || (d>=192 && d<=197) || (d>=224 && d<=230) );
      }
      bool C_RANGE(size_t d){
        return (d == 200 || d == 231);
      }
      bool D_RANGE(size_t d){
        return (d == 208);
      }
      bool E_RANGE(size_t d){
        return ( (d>=200 && d<=203) || (d>=232 && d<=235) );
      }
      bool I_RANGE(size_t d){
        return ( (d>=204 && d<=207) || (d>=236 && d<=239) );
      }
      bool O_RANGE(size_t d){
        return ( (d>=210 && d<=214) || d == 216 || (d>=242 && d<=246) || d == 248);
      }
      bool N_RANGE(size_t d){
        return (d == 209 || d == 241);
      }
      bool U_RANGE(size_t d){
        return ( (d>=217 && d<=220) || (d>=249 && d<=254) );
      }
      bool X_RANGE(size_t d){
        return (d == 215);
      }
      bool Y_RANGE(size_t d){
        return (d == 221 || d==253 || d == 255);
      }
    public:
      std::map<int, std::string> toWord;
      int rangeTranslate(size_t d){
        if(A_RANGE(d)){
          return 'a';
        }else if(C_RANGE(d)){
          return 'c';
        }else if(D_RANGE(d)){
          return 'd';
        }else if(E_RANGE(d)){
          return 'e';
        }else if(I_RANGE(d)){
          return 'i';
        }else if(O_RANGE(d)){
          return 'o';
        }else if(N_RANGE(d)){
          return 'n';
        }else if(U_RANGE(d)){
          return 'u';
        }else if(X_RANGE(d)){
          return 'x';
        }else if(Y_RANGE(d)){
          return 'y';
        }else{
          return -1; // not found means we have to substitute with empty string
        }
      }
      LatinSupplement1(){
        toWord[97] = 'a';
        toWord[98] = 'b';
        toWord[99] = 'c';
        toWord[100] = 'd';
        toWord[101] = 'e';
        toWord[102] = 'f';
        toWord[103] = 'g';
        toWord[104] = 'h';
        toWord[105] = 'i';
        toWord[106] = 'j';
        toWord[107] = 'k';
        toWord[108] = 'l';
        toWord[109] = 'm';
        toWord[110] = 'n';
        toWord[111] = 'o';
        toWord[112] = 'p';
        toWord[113] = 'q';
        toWord[114] = 'r';
        toWord[115] = 's';
        toWord[116] = 't';
        toWord[117] = 'u';
        toWord[118] = 'v';
        toWord[119] = 'w';
        toWord[120] = 'x';
        toWord[121] = 'y';
        toWord[122] = 'z';
        toWord[162] = "cent";
        toWord[163] = "pound";
        toWord[165] = "yen";
        toWord[169] = "copyright";
        toWord[174] = "registered";
        toWord[181] = "micro";
        toWord[188] = "1 / 4";
        toWord[189] = "1 / 2";
        toWord[190] = "3 / 4";
        toWord[198] = "ae";
      }
  };

  
};  // namespace u8lib
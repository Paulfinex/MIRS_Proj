#pragma once
#include <iostream>
#include <map>

namespace u8lib{
  class LatinA{
    private:
      bool A_RANGE(size_t d){
        return ( (d>=256 && d<=261) );
      }
      bool C_RANGE(size_t d){
        return ( (d>=262 && d<=269) );
      }
      bool D_RANGE(size_t d){
        return ( (d>=270 && d<=273) );
      }
      bool E_RANGE(size_t d){
        return ( (d>=274 && d<=283) );
      }
      bool G_RANGE(size_t d){
        return ((d >= 284 && d <= 291));
      }
      bool H_RANGE(size_t d){
        return ((d >= 292 && d <= 295));
      }
      bool I_RANGE(size_t d){
        return ((d >= 296 && d <= 305));
      }
      bool J_RANGE(size_t d){
        return ((d >= 308 && d <= 309));
      }
      bool K_RANGE(size_t d){
        return ((d >= 310 && d <= 312));
      }
      bool L_RANGE(size_t d){
        return ((d >= 313 && d <= 322));
      }
      bool N_RANGE(size_t d){
        return ((d>=323 && d<=331));
      }
      bool O_RANGE(size_t d){
        return ((d>=332 && d<=337));
      }
      bool R_RANGE(size_t d){
        return ((d>=340 && d<=345));
      }
      bool S_RANGE(size_t d){
        return ((d>=346 && d<=353) || d == 383);
      }
      bool T_RANGE(size_t d){
        return ((d>=354 && d<=359));
      }
      bool U_RANGE(size_t d){
        return ((d>=360 && d<=371));
      }
      bool W_RANGE(size_t d){
        return ((d>=372 && d<=373));
      }
      bool Y_RANGE(size_t d){
        return ((d>=374 && d<=376));
      }
      bool Z_RANGE(size_t d){
        return ((d>=377 && d<=382));
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
        }else if(G_RANGE(d)){
          return 'g';
        }else if(H_RANGE(d)){
          return 'h';
        }else if(I_RANGE(d)){
          return 'i';
        }else if(J_RANGE(d)){
          return 'j';
        }else if(K_RANGE(d)){
          return 'k';
        }else if(L_RANGE(d)){
          return 'l';
        }else if(N_RANGE(d)){
          return 'n';
        }else if(O_RANGE(d)){
          return 'o';
        }else if(R_RANGE(d)){
          return 'r';
        }else if(S_RANGE(d)){
          return 's';
        }else if(T_RANGE(d)){
          return 't';
        }else if(U_RANGE(d)){
          return 'u';
        }else if(W_RANGE(d)){
          return 'w';
        }else if(Y_RANGE(d)){
          return 'y';
        }else if(Z_RANGE(d)){
          return 'z';
        }else{
          return -1; // not found means we have to substitute with empty string
        }
      }
      LatinA(){
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
        toWord[306] = "ij";
        toWord[307] = "ij";
        toWord[338] = "oe";
        toWord[339] = "oe";
      }
  };

  
};  // namespace u8lib
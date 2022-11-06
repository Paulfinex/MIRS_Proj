#pragma once
#include <iostream>
#include <map>

namespace u8lib{
  class RangeName{
    private:
      bool A_RANGE(size_t d){
        return false;
      }
      bool B_RANGE(size_t d){
        return false;
      }
      bool C_RANGE(size_t d){
        return false;
      }
      bool D_RANGE(size_t d){
        return false;
      }
      bool E_RANGE(size_t d){
        return false;
      }
      bool F_RANGE(size_t d){
        return false;
      }
      bool G_RANGE(size_t d){
        return false;
      }
      bool H_RANGE(size_t d){
        return false;
      }
      bool I_RANGE(size_t d){
        return false;
      }
      bool J_RANGE(size_t d){
        return false;
      }
      bool K_RANGE(size_t d){
        return false;
      }
      bool L_RANGE(size_t d){
        return false;
      }
      bool M_RANGE(size_t d){
        return false;
      }
      bool N_RANGE(size_t d){
        return false;
      }
      bool O_RANGE(size_t d){
        return false;
      }
      bool P_RANGE(size_t d){
        return false;
      }
      bool Q_RANGE(size_t d){
        return false;
      }
      bool R_RANGE(size_t d){
        return false;
      }
      bool S_RANGE(size_t d){
        return false;
      }
      bool T_RANGE(size_t d){
        return false;
      }
      bool U_RANGE(size_t d){
        return false;
      }
      bool V_RANGE(size_t d){
        return false;
      }
      bool W_RANGE(size_t d){
        return false;
      }
      bool X_RANGE(size_t d){
        return false;
      }
      bool Y_RANGE(size_t d){
        return false;
      }
      bool Z_RANGE(size_t d){
        return false;
      }
    public:
      std::map<int, std::string> toWord;
      int rangeTranslate(size_t d){
        if(A_RANGE(d)){
          return 'a';
        }else if(B_RANGE(d)){
          return 'b';
        }else if(C_RANGE(d)){
          return 'c';
        }else if(D_RANGE(d)){
          return 'd';
        }else if(E_RANGE(d)){
          return 'e';
        }else if(F_RANGE(d)){
          return 'f';
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
        }else if(M_RANGE(d)){
          return 'm';
        }else if(N_RANGE(d)){
          return 'n';
        }else if(O_RANGE(d)){
          return 'o';
        }else if(P_RANGE(d)){
          return 'p';
        }else if(Q_RANGE(d)){
          return 'q';
        }else if(R_RANGE(d)){
          return 'r';
        }else if(S_RANGE(d)){
          return 's';
        }else if(T_RANGE(d)){
          return 't';
        }else if(U_RANGE(d)){
          return 'u';
        }else if(V_RANGE(d)){
          return 'v';
        }else if(W_RANGE(d)){
          return 'w';
        }else if(X_RANGE(d)){
          return 'x';
        }else if(Y_RANGE(d)){
          return 'y';
        }else if(Z_RANGE(d)){
          return 'z';
        }else{
          return -1; // not found means we have to substitute with empty string
        }
      }
      RangeName(){
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
      }
  };

  
};  // namespace u8lib
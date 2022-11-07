#pragma once
#include <iostream>

namespace u8lib{
  class RangeName{
    private:
      static bool A_RANGE(size_t d){
        return false;
      }
      static bool B_RANGE(size_t d){
        return false;
      }
      static bool C_RANGE(size_t d){
        return false;
      }
      static bool D_RANGE(size_t d){
        return false;
      }
      static bool E_RANGE(size_t d){
        return false;
      }
      static bool F_RANGE(size_t d){
        return false;
      }
      static bool G_RANGE(size_t d){
        return false;
      }
      static bool H_RANGE(size_t d){
        return false;
      }
      static bool I_RANGE(size_t d){
        return false;
      }
      static bool J_RANGE(size_t d){
        return false;
      }
      static bool K_RANGE(size_t d){
        return false;
      }
      static bool L_RANGE(size_t d){
        return false;
      }
      static bool M_RANGE(size_t d){
        return false;
      }
      static bool N_RANGE(size_t d){
        return false;
      }
      static bool O_RANGE(size_t d){
        return false;
      }
      static bool P_RANGE(size_t d){
        return false;
      }
      static bool Q_RANGE(size_t d){
        return false;
      }
      static bool R_RANGE(size_t d){
        return false;
      }
      static bool S_RANGE(size_t d){
        return false;
      }
      static bool T_RANGE(size_t d){
        return false;
      }
      static bool U_RANGE(size_t d){
        return false;
      }
      static bool V_RANGE(size_t d){
        return false;
      }
      static bool W_RANGE(size_t d){
        return false;
      }
      static bool X_RANGE(size_t d){
        return false;
      }
      static bool Y_RANGE(size_t d){
        return false;
      }
      static bool Z_RANGE(size_t d){
        return false;
      }
    public:
      static std::string rangeTranslate(size_t d){
        if(A_RANGE(d)){
          return "a";
        }else if(B_RANGE(d)){
          return "b";
        }else if(C_RANGE(d)){
          return "c";
        }else if(D_RANGE(d)){
          return "d";
        }else if(E_RANGE(d)){
          return "e";
        }else if(F_RANGE(d)){
          return "f";
        }else if(G_RANGE(d)){
          return "g";
        }else if(H_RANGE(d)){
          return "h";
        }else if(I_RANGE(d)){
          return "i";
        }else if(J_RANGE(d)){
          return "j";
        }else if(K_RANGE(d)){
          return "k";
        }else if(L_RANGE(d)){
          return "l";
        }else if(M_RANGE(d)){
          return "m";
        }else if(N_RANGE(d)){
          return "n";
        }else if(O_RANGE(d)){
          return "o";
        }else if(P_RANGE(d)){
          return "p";
        }else if(Q_RANGE(d)){
          return "q";
        }else if(R_RANGE(d)){
          return "r";
        }else if(S_RANGE(d)){
          return "s";
        }else if(T_RANGE(d)){
          return "t";
        }else if(U_RANGE(d)){
          return "u";
        }else if(V_RANGE(d)){
          return "v";
        }else if(W_RANGE(d)){
          return "w";
        }else if(X_RANGE(d)){
          return "x";
        }else if(Y_RANGE(d)){
          return "y";
        }else if(Z_RANGE(d)){
          return "z";
        }else{
          return ""; // not found means we have to substitute with empty string
        }
      }
  };
};  // namespace u8lib
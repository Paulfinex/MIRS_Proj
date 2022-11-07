#pragma once
#include <iostream>
#include <map>

namespace u8lib{
  class LatinA{
    private:
      static bool A_RANGE(size_t d){
        return ( (d>=256 && d<=261) );
      }
      static bool C_RANGE(size_t d){
        return ( (d>=262 && d<=269) );
      }
      static bool D_RANGE(size_t d){
        return ( (d>=270 && d<=273) );
      }
      static bool E_RANGE(size_t d){
        return ( (d>=274 && d<=283) );
      }
      static bool G_RANGE(size_t d){
        return ((d >= 284 && d <= 291));
      }
      static bool H_RANGE(size_t d){
        return ((d >= 292 && d <= 295));
      }
      static bool I_RANGE(size_t d){
        return ((d >= 296 && d <= 305));
      }
      static bool J_RANGE(size_t d){
        return ((d >= 308 && d <= 309));
      }
      static bool K_RANGE(size_t d){
        return ((d >= 310 && d <= 312));
      }
      static bool L_RANGE(size_t d){
        return ((d >= 313 && d <= 322));
      }
      static bool N_RANGE(size_t d){
        return ((d>=323 && d<=331));
      }
      static bool O_RANGE(size_t d){
        return ((d>=332 && d<=337));
      }
      static bool R_RANGE(size_t d){
        return ((d>=340 && d<=345));
      }
      static bool S_RANGE(size_t d){
        return ((d>=346 && d<=353) || d == 383);
      }
      static bool T_RANGE(size_t d){
        return ((d>=354 && d<=359));
      }
      static bool U_RANGE(size_t d){
        return ((d>=360 && d<=371));
      }
      static bool W_RANGE(size_t d){
        return ((d>=372 && d<=373));
      }
      static bool Y_RANGE(size_t d){
        return ((d>=374 && d<=376));
      }
      static bool Z_RANGE(size_t d){
        return ((d>=377 && d<=382));
      }
    public:
      static std::string rangeTranslate(size_t d){
        if(A_RANGE(d)){
          return "a";
        }else if(C_RANGE(d)){
          return "c";
        }else if(D_RANGE(d)){
          return "d";
        }else if(E_RANGE(d)){
          return "e";
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
        }else if(N_RANGE(d)){
          return "n";
        }else if(O_RANGE(d)){
          return "o";
        }else if(R_RANGE(d)){
          return "r";
        }else if(S_RANGE(d)){
          return "s";
        }else if(T_RANGE(d)){
          return "t";
        }else if(U_RANGE(d)){
          return "u";
        }else if(W_RANGE(d)){
          return "w";
        }else if(Y_RANGE(d)){
          return "y";
        }else if(Z_RANGE(d)){
          return "z";
        }else if(d>=306 && d<=307){
          return "ij";
        }else if(d >= 338 && d<=339){
          return "oe";
        }else{
          return ""; // not found means we have to substitute with empty string
        }
      }
  };

  
};  // namespace u8lib
#pragma once
#include <iostream>

namespace u8lib{
  /** 
   * Latin Supplement 1  
   * @cite https://www.compart.com/en/unicode/block/U+0080
   * Range Unicode 128-255 
  */
  class LatinSupplement1{
    private:
      static bool A_RANGE(size_t d){
        return (d == 170 || (d>=192 && d<=197) || (d>=224 && d<=230));
      }
      static bool C_RANGE(size_t d){
        return (d == 200 || d == 231);
      }
      static bool D_RANGE(size_t d){
        return (d == 208);
      }
      static bool E_RANGE(size_t d){
        return ( (d>=200 && d<=203) || (d>=232 && d<=235) );
      }
      static bool I_RANGE(size_t d){
        return ( (d>=204 && d<=207) || (d>=236 && d<=239) );
      }
      static bool O_RANGE(size_t d){
        return ( (d>=210 && d<=214) || d == 216 || (d>=242 && d<=246) || d == 248);
      }
      static bool N_RANGE(size_t d){
        return (d == 209 || d == 241);
      }
      static bool U_RANGE(size_t d){
        return ( (d>=217 && d<=220) || (d>=249 && d<=254) );
      }
      static bool X_RANGE(size_t d){
        return (d == 215);
      }
      static bool Y_RANGE(size_t d){
        return (d == 221 || d==253 || d == 255);
      }
    public:
      static bool IS_CONTROL(size_t d){
          return ((d >= 128 && d <= 160));
      }
      static std::string rangeTranslate(size_t d){
        if(A_RANGE(d)){
          return "a";
        }else if(C_RANGE(d)){
          return "c";
        }else if(D_RANGE(d)){
          return "d";
        }else if(E_RANGE(d)){
          return "e";
        }else if(I_RANGE(d)){
          return "i";
        }else if(O_RANGE(d)){
          return "o";
        }else if(N_RANGE(d)){
          return "n";
        }else if(U_RANGE(d)){
          return "u";
        }else if(X_RANGE(d)){
          return "x";
        }else if(Y_RANGE(d)){
          return "y";
        }else if(d == 128){
          return "ae";
        }else{
          return ""; // not found means we have to substitute with empty string
        }
      }
  };

  
};  // namespace u8lib
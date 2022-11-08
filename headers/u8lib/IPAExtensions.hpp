#pragma once
#include <iostream>

namespace u8lib{
  /** 
   * IPA  
   * @cite https://www.compart.com/en/unicode/block/U+0250
   * Range Unicode 592-687 
  */
  class IPA{
    private:
      static bool A_RANGE(size_t d){
        return ((d>=592 && d<=594));
      }
      static bool B_RANGE(size_t d){
        return (d==595 || d == 665);
      }
      static bool C_RANGE(size_t d){
        return (d==597 || d==663);
      }
      static bool D_RANGE(size_t d){
        return ((d>=598 && d<=599));
      }
      static bool E_RANGE(size_t d){
        return ((d>=600 && d<=606) || d == 666);
      }
      static bool G_RANGE(size_t d){
        return ((d>=608 && d<=612) || d==667);
      }
      static bool H_RANGE(size_t d){
        return ((d>=613 && d<=615) || d==668 || (d>=686 && d<=687));
      }
      static bool I_RANGE(size_t d){
        return ((d>=616 && d<=618));
      }
      static bool J_RANGE(size_t d){
        return (d==607 || d == 669);
      }
      static bool K_RANGE(size_t d){
        return (d==670);
      }
      static bool L_RANGE(size_t d){
        return ((d>=619 && d<=621) || d==671);
      }
      static bool M_RANGE(size_t d){
        return ((d>=623 && d<=625));
      }
      static bool N_RANGE(size_t d){
        return ((d>=626 && d<=628));
      }
      static bool O_RANGE(size_t d){
        return (d==596 || d == 629 || d==631 || d==664);
      }
      static bool P_RANGE(size_t d){
        return (d == 632);
      }
      static bool Q_RANGE(size_t d){
        return (d==672);
      }
      static bool R_RANGE(size_t d){
        return ((d>=633 && d<=641));
      }
      static bool S_RANGE(size_t d){
        return (d == 642);
      }
      static bool T_RANGE(size_t d){
        return (d>=647 && d<=648);
      }
      static bool U_RANGE(size_t d){
        return (d==649);
      }
      static bool V_RANGE(size_t d){
        return (d >= 651 && d<=652);
      }
      static bool W_RANGE(size_t d){
        return (d==653);
      }
      static bool Y_RANGE(size_t d){
        return ((d>=654 && d<=655) || d == 650);
      }
      static bool Z_RANGE(size_t d){
        return (d>=656 && d<=657);
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
        }else if(Y_RANGE(d)){
          return "y";
        }else if(Z_RANGE(d)){
          return "z";
        }else if(d==630){
          return "oe";
        }else if(d==675 || d==677){
          return "dz";
        }else if(d==678){
          return "ts";
        }else if(d==680){
          return "tc";
        }else if(d==682){
          return "ls";
        }else if(d==683){
          return "lz";
        }else{
          return ""; // not found means we have to substitute with empty string
        }
      }
  };
};  // namespace u8lib
#pragma once
#include <iostream>

namespace u8lib{
  /** 
   * Greek  
   * @cite https://www.compart.com/en/unicode/block/U+0370 
   * Range Unicode 880-1023 
  */
  class Greek{
    private:
      static bool A_RANGE(size_t d){
        return (d==902 || d==913 || d==940 || d==945);
      }
      static bool B_RANGE(size_t d){
        return (d==914 || d==946 || d==976);
      }
      static bool D_RANGE(size_t d){
        return (d==916 || d==948);
      }
      static bool E_RANGE(size_t d){
        return (d==904 || d == 917 || d==941 || d==949 || d==1013);
      }
      static bool F_RANGE(size_t d){
        return (d>=988 && d<=989);
      }
      static bool G_RANGE(size_t d){
        return (d==911 || d==915 || d==947);
      }
      static bool H_RANGE(size_t d){
        return ((d>=880 && d<=881) || d==905);
      }
      static bool I_RANGE(size_t d){
        return (d==906 || d==921 || d==938 || d==943 || d==953 || d==970);
      }
      static bool J_RANGE(size_t d){
        return (d==895 || d==912 || d==1011);
      }
      static bool K_RANGE(size_t d){
        return (d==922 || d==954 || d==975 || (d>=983 && d<=985) || (d>=990 && d<=991) || d==1008);
      }
      static bool L_RANGE(size_t d){
        return (d==923 || d==955);
      }
      static bool M_RANGE(size_t d){
        return (d==924 || d==956 || (d>=1018 && d<=1019));
      }
      static bool N_RANGE(size_t d){
        return (d==925 || d==942 || d==951 || d==957);
      }
      static bool O_RANGE(size_t d){
        return (d==908 || d==927 || d==937 || d==911 || d==959 || d==969 || d==972 || d==974);
      }
      static bool P_RANGE(size_t d){
        return (d==934 || d==936 || d==966 || d==968 || d==981 || d==982);
      }
      static bool R_RANGE(size_t d){
        return (d==929 || d==961);
      }
      static bool S_RANGE(size_t d){
        return (d==931 || d==962 || d==963 || (d>=986 && d<=987) || (d>=1015 && d<=1016));
      }
      static bool T_RANGE(size_t d){
        return ((d>=882 && d<=883) || d==920 || d==932 || d==952 || d==964 || d==977 || d==1012);
      }
      static bool X_RANGE(size_t d){
        return (d==926 || d==935 || d==958 || d==967);
      }
      static bool Y_RANGE(size_t d){
        return (d==910 || d==933 || d==939 || d==944 || d==965 || d==971 || d==973 || (d>=978 && d<=980));
      }
      static bool Z_RANGE(size_t d){
        return (d==918 || d==950);
      }
    public:
      static std::string rangeTranslate(size_t d){
        if(A_RANGE(d)){
          return "a";
        }else if(B_RANGE(d)){
          return "b";
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
        }else if(R_RANGE(d)){
          return "r";
        }else if(S_RANGE(d)){
          return "s";
        }else if(T_RANGE(d)){
          return "t";
        }else if(X_RANGE(d)){
          return "x";
        }else if(Y_RANGE(d)){
          return "y";
        }else if(Z_RANGE(d)){
          return "z";
        }else if(d==928 || d==960){
          return "pi";
        }else{
          return ""; // not found means we have to substitute with empty string
        }
      }
  };
};  // namespace u8lib
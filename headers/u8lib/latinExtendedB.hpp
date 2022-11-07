#pragma once
#include <iostream>
#include <map>

namespace u8lib{
  //Lating Extended - A https://www.compart.com/en/unicode/block/U+0100
  class LatinA{
    private:
      static bool A_RANGE(size_t d){
        return ( (d>=461 && d<=462) || (d>=478 && d<=481) ||(d>=506 && d<=507) ||(d>=512 && d<=515)||(d>=550 && d<=551) ||(d==570));
      } 
      static bool Ae_RANGE(size_t d){
        return ((d>=482 && d<=483)||(d>=508 && d<=509)||(d>=571 && d<=572));
      } 
      static bool B_RANGE(size_t d){
        return ( (d>=384 && d<=389) ||(d==579));
      }
      static bool C_RANGE(size_t d){
        return ( (d>=390 && d<=392));
      }
      static bool D_RANGE(size_t d){
        return ( (d>=393 && d<=397) || (d==545));
      }
      static bool Db_RANGE(size_t d){
        return ( (d==568));
      }
      static bool Dz_RANGE(size_t d){
        return ( (d>=452 && d<=454)|| (d>=497 && d<=499));
      }
      static bool E_RANGE(size_t d){
        return ( (d>=398 && d<=400) || (d==477)||(d>=516&&d<=519)||(d>=552&&d<=553)||(d>=582&&d<=583)||(d>=439&&d<=442));
      }
      static bool F_RANGE(size_t d){
        return ((d >= 401 && d <= 402));
      }
      static bool G_RANGE(size_t d){
        return ((d >= 403 && d <= 404)||(d >= 484 && d <= 487)||(d >= 500 && d <= 501));
      }
      static bool H_RANGE(size_t d){
        return ((d >= 542 && d <= 543)||(d == 405));
      }
      static bool I_RANGE(size_t d){
        return ((d >= 406 && d <= 407)||(d >= 463 && d <= 464)||(d >= 520 && d <= 523));
      }
      static bool J_RANGE(size_t d){
        return ((d >= 584 && d <= 585)||(d ==567));
      }
      static bool K_RANGE(size_t d){
        return ((d >= 408 && d <= 409)||(d >= 488 && d <= 489));
      }
      static bool L_RANGE(size_t d){
        return ((d >= 410 && d <= 411)||(d==564)&&(d==573));
      }
      static bool Lj_RANGE(size_t d){
        return ((d >= 455 && d <= 457));
      }
      static bool M_RANGE(size_t d){
        return ((d==412));
      }
      static bool N_RANGE(size_t d){
        return ((d>=413 && d<=414)||(d>=504 && d<=505)||(d==544)&&(d==565));
      }
      static bool Nj_RANGE(size_t d){
        return ((d>=458 && d<=460));
      }
      static bool O_RANGE(size_t d){
        return ((d>=415 && d<=417)||(d >= 465 && d <= 466)||(d >= 490 && d <= 493)||(d >= 510 && d <= 511)||(d >= 524 && d <= 527)||(d >= 554 && d <= 561));
      }
      static bool Oi_RANGE(size_t d){
        return ((d>=418 && d<=419));
      }
      static bool Ou_RANGE(size_t d){
        return ((d>=546 && d<=547));
      }
      static bool P_RANGE(size_t d){
        return ((d>=420 && d<=421));
      }
      static bool Q_RANGE(size_t d){
        return ((d>=586 && d<=587));
      }
      static bool Qp_RANGE(size_t d){
        return ((d==569));
      }      
      static bool R_RANGE(size_t d){
        return ((d>=528 && d<=530)||(d>=588 && d<=589)||(d==422));
      }
      static bool S_RANGE(size_t d){
        return ((d>=423 && d<=425)||(d>=536 && d<=537)||(d==575));
      }
      static bool T_RANGE(size_t d){
        return ((d>=426 && d<=430)||(d>=538 && d<=539)||(d==566)||(d==574));
      }
      static bool U_RANGE(size_t d){
        return ((d>=431 && d<=433)||(d>=467 && d<=476)||(d>=532 && d<=535)||(d==580));
      }
      static bool V_RANGE(size_t d){
        return ((d==434)||(d==581));
      }
      static bool Y_RANGE(size_t d){
        return ((d>=435 && d<=436)||(d>=562 && d<=563)||(d>=590 && d<=591));
      }
      static bool Z_RANGE(size_t d){
        return ((d>=437 && d<=439)||(d>=548 && d<=549)||(d==576));
      }
    public:
      std::map<int, std::string> toWord;
      std::string rangeTranslate(size_t d){
        if(A_RANGE(d)){
          return "a";
        }else if(Ae_RANGE(d)){
          return "ae";
        }else if(B_RANGE(d)){
          return "b";
        }else if(C_RANGE(d)){
          return "c";
        }else if(D_RANGE(d)){
          return "d";
        }else if(Db_RANGE(d)){
          return "db";
        }else if(Dz_RANGE(d)){
          return "dz";
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
        }else if(Lj_RANGE(d)){
          return "lj";
        }else if(M_RANGE(d)){
          return "m";
        }else if(N_RANGE(d)){
          return "n";
        }else if(Nj_RANGE(d)){
          return "nj";
        }else if(O_RANGE(d)){
          return "o";
        }else if(Oi_RANGE(d)){
          return "oi";
        }else if(Ou_RANGE(d)){
          return "ou";
        }else if(R_RANGE(d)){
          return "r";
        }else if(P_RANGE(d)){
          return "p";
        }else if(Q_RANGE(d)){
          return "q";
        }else if(Qp_RANGE(d)){
          return "qp";
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
        }else if(Y_RANGE(d)){
          return "y";
        }else if(Z_RANGE(d)){
          return "z";
        }else{
          return ""; // not found means we have to substitute with empty string
        }
      }
  };


 
};  
#pragma once
#include <iostream>
#include "latinSupplement1.hpp"
#include "latinExtendedA.hpp"
#include "latinExtendedB.hpp"
#include "IPAExtensions.hpp"
#include "Greek.hpp"

namespace u8lib{
  bool checkControl(size_t d){
    if(d>=128 && d<=255){
      return LatinSupplement1::IS_CONTROL(d);
    }
    /**
     * @brief else if other ranges
     */
    return false;
  }
  std::string translateRange(size_t d, bool isControl = false){
    if(d>=0 && d<=127){
      char c = static_cast<char>(d);
      std::string tmp = "";
      tmp.push_back(c);
      return tmp;
    }
    if (isControl) return " ";
    if(d>=128 && d<=255) return LatinSupplement1::rangeTranslate(d);
    if(d>=256 && d<=383) return LatinA::rangeTranslate(d);
    if(d>=384 && d<=591) return LatinB::rangeTranslate(d);
    if(d>=592 && d<=687) return IPA::rangeTranslate(d);
    if(d>=880 && d<=1023) return Greek::rangeTranslate(d);
    return "";
  }
};  // namespace u8lib
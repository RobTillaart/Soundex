#pragma once
//
//    FILE: Soundex.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.2
//    DATE: 2022-02-05
// PURPOSE: Arduino Library for calculating Soundex hash
//     URL: https://github.com/RobTillaart/Soundex
//
//  HISTORY
//  0.1.0   2011-05-20   stand alone application 
//  0.1.1   2022-02-05   initial library version
//  0.1.2   2022-02-06   added soundex16(), soundex32()


#include "Arduino.h"


#define SOUNDEX_LIB_VERSION              (F("0.1.2"))


#define SOUNDEX_MIN_LENGTH               4
#define SOUNDEX_MAX_LENGTH               12



class Soundex
{
public:
  Soundex();

  void     setLength(uint8_t length = 4);
  uint8_t  getLength() { return _length; };

  char *   soundex(const char * str);     //  Russel and Odell
  uint16_t soundex16(const char * str);   //  Russel and Odell  len=5
  uint32_t soundex32(const char * str);   //  Russel and Odell  len=10


private:
  char     _buffer[SOUNDEX_MAX_LENGTH];
  uint8_t  _length;

  // This array can be made smaller (less RAM) 
  // - encode in nibbles. (13 bytes instead of 26) => more code, performance?
  //   0x01, 0x23, 0x01 etc.
  uint8_t sdx[26] = {0,1,2,3,0,1,2,0,0,2,2,4,5,5,0,1,2,6,2,3,0,1,0,2,0,2 };
};


// -- END OF FILE -- 


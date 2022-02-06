//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2022-02-05
// PURPOSE: unit tests for the Soundex library
//          https://github.com/RobTillaart/Soundex
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// https://github.com/Arduino-CI/arduino_ci/blob/master/cpp/unittest/Assertion.h#L33-L42
// ----------------------------
// assertEqual(expected, actual)
// assertNotEqual(expected, actual)
// assertLess(expected, actual)
// assertMore(expected, actual)
// assertLessOrEqual(expected, actual)
// assertMoreOrEqual(expected, actual)
// assertTrue(actual)
// assertFalse(actual)
// assertNull(actual)
// assertNotNull(actual)

#include <ArduinoUnitTests.h>


#include "Arduino.h"
#include "Soundex.h"



unittest_setup()
{
  fprintf(stderr, "SOUNDEX_LIB_VERSION: %s\n", (char *) SOUNDEX_LIB_VERSION);
}

unittest_teardown()
{
}


unittest(test_soundex_3)
{
  Soundex SDX;
  // examples from Wikipedia
  AssertEqual("R163", SDX.soundex("Robert"));
  AssertEqual("R163", SDX.soundex("Rupert"));
  AssertEqual("R150", SDX.soundex("Rubin"));
  AssertEqual("T522", SDX.soundex("Tymczak"));
  AssertEqual("P236", SDX.soundex("Pfister"));
  AssertEqual("H555", SDX.soundex("Honeyman"));
}


unittest(test_soundex_chemicals)
{
  Soundex SDX;

  SDX.setLength(10);
  // e.g. for long chemical names
  AssertEqual("T624634500", SDX.soundex("Trichloroethylene"));
  AssertEqual("P532615323", SDX.soundex("pentacarbon decahydrate"));
  AssertEqual("D261524223", SDX.soundex("deoxyribonucleic acid"));
}


unittest_main()

// --------

#ifndef SETTINGS_h
#define SETTINGS_h

#include <iostream>


// Event selections
//
// Author: Domninic Smith, University of Bristol/ VUB
//         dominic.smith@bristol.ac.uk
//         October 2013

class Settings{

 public:

  static float GetEntries() { return 1000; }
  static float NJets() { return 1; }
  static float NWbosons() { return 4; }
  static float Nbottoms() { return 4; }
   
};


#endif 

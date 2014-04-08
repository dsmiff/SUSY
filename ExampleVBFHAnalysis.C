#define ExampleVBFHAnalysis_cxx
#include "ExampleVBFHAnalysis.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>

using namespace std;

void ExampleVBFHAnalysis::processEvents()
{

  Bool_t printout = 0;

   _nEvt = fChain->GetEntriesFast();
   Long64_t nbytes =0 , nb = 0;

   for (Long64_t entry=0; entry<_nEvt;entry++) {
      Long64_t ientry = LoadTree(entry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(entry);   nbytes += nb;

      if ( printout ) continue;

      // Declare the functions you want to run

      JetAnalysis();

   }
}

Int_t ExampleVBFHAnalysis::JetAnalysis()
{
  
  // Jet analysis goes here

  cout << " HI " << endl;

  return 0;
}

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

  TH1::SetDefaultSumw2();

  _fNJets = new TH1D("NJets", "NJets" , 100, 0, 20);

  //  _nEvt = fChain->GetEntriesFast();       // Get total number of entries
  _nEvt = 1000;
  Long64_t nbytes =0 , nb = 0;

   for (Long64_t entry=0; entry<_nEvt;entry++) {            //  Loop over each entry
      Long64_t ientry = LoadTree(entry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(entry);   nbytes += nb;

      if ( printout ) continue;

      // Declare the functions you want to run

      JetAnalysis();
      MET();
      end();
   }
}

Int_t ExampleVBFHAnalysis::JetAnalysis()
{

  Int_t _nJets = sizeof(Jet_PT)/sizeof(Jet_PT[0]);

  for(Int_t i=0; i < _nJets; i++){
    //  Looping over jets per event. Apply cuts here
    if(Jet_PT[i] < 0 ) continue;
    _fNJets->Fill(Jet_size);
    

  }
  

  

  return 0;
}

Int_t ExampleVBFHAnalysis::MET()
{

  // MET analysis goes here

  return 0;

}

Int_t ExampleVBFHAnalysis::MHT()
{

  // MHT analysis goes here

  return 0;
}

void ExampleVBFHAnalysis::end()
{

  TFile *_rootFile = new TFile("VBF_invH_8000_output.root","RECREATE");

  _fNJets->Write();
  _rootFile->Write();
  _rootFile->Close();


}

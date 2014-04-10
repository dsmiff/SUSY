#define ExampleVBFHAnalysis_cxx
#include "ExampleVBFHAnalysis.h"
#include <TH2.h>
#include <TH1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

void ExampleVBFHAnalysis::processEvents()
{

  Bool_t printout = 0;

  TH1::SetDefaultSumw2();



  _fNJets = new TH1D("NJets", "NJets" , 100, 0, 20);
  _f1stJet = new TH1D("1stJet","1stJetPT", 100, 0, 300);
  _f2ndJet = new TH1D("2ndJet","2ndJetPT",100, 0, 300);




  //  _nEvt = fChain->GetEntriesFast();       // Get total number of entries
  _nEvt = 1000;
  Long64_t nbytes =0 , nb = 0;

   for (Long64_t entry=0; entry<_nEvt;entry++) {            //  Looping over each entry
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
  
    njets.push_back(Jet_size);                   // Transfering array information to vectors
      if(Jet_PT[i] < 0 ) continue;
    _fNJets->Fill(njets.at(i));

    jetpts.push_back(Jet_PT[i]);
    _f1stJet->Fill(jetpts.at(0));
  
    if(jetpts.at(1) < 0) continue;
    _f2ndJet->Fill(jetpts.at(1));      // This needs to be redone (produces out-of-range error)
    
 }

  njets.clear();
  jetpts.clear();



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

  _f1stJet->Write();
  _f2ndJet->Write();
  _fNJets->Write();
  _rootFile->Write();
  _rootFile->Close();


}

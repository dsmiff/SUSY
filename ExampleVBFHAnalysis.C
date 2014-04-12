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

  // Declare histos

  _fNJets = new TH1D("NJets", "NJets" , 100, 0, 20);
  _f1stJetPT = new TH1D("1stJetPT","1stJetPT", 100, 0, 300);
  _f2ndJetPT = new TH1D("2ndJetPT","2ndJetPT",100, 0, 300);
  _fJetEta = new TH1D("JetEta","JetEta", 100, -5, 5);
  _fJetPhi = new TH1D("JetPhi","JetPhi", 100, 0, 300);
  _fHT = new TH1D("HT","HT",100, 0, 1500);
  _f1stJetMass = new TH1D("1stJetMass","1stJetMass", 100, 0, 300);
  _f2ndJetMass = new TH1D("2ndJetMass","2ndJetMass", 100, 0, 300);



  //  _nEvt = fChain->GetEntriesFast();       // Get total number of entries
  _nEvt = 1000;     
  Long64_t nbytes =0 , nb = 0;

   for (Long64_t entry=0; entry<_nEvt;entry++) {            //  Loop over each entry
      Long64_t ientry = LoadTree(entry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(entry);   nbytes += nb;

      if ( printout ) continue;

      // Run functions

      JetAnalysis();
      MET();
      Output();
   }
}

Int_t ExampleVBFHAnalysis::JetAnalysis()
{

  Int_t _nJets = sizeof(Jet_PT)/sizeof(Jet_PT[0]);
  Int_t Jet_PTcut = 0;
  Float_t JetEta_cut = 0;
  Long64_t HT = 0;

  for(Int_t i=0; i < _nJets; i++){
    //  Loop over jets per event. Apply cuts here
  
    njets.push_back(Jet_size);                   // Transfering array information to vectors
      if(Jet_PT[i] < Jet_PTcut ) continue;
    _fNJets->Fill(njets.at(i));

    jetpts.push_back(Jet_PT[i]);
    jeteta.push_back(Jet_Eta[i]);
    jetphi.push_back(Jet_Phi[i]);
    jetmass.push_back(Jet_Mass[i]);
    _f1stJetPT->Fill(jetpts.at(0));
    _f1stJetMass->Fill(jetmass.at(0));
    _fJetEta->Fill(jeteta.at(i));
    _fJetPhi->Fill(jetphi.at(i));
    
    HT += jetpts.at(i);                          // Note this the conventional definition of HT, a Delphes equivalent exists 
    _fHT->Fill(HT);

    if(njets.size() > 1) {
    _f2ndJetPT->Fill(jetpts.at(1));  
    _f2ndJetMass->Fill(jetmass.at(1));
    }
 }

  njets.clear();
  jetpts.clear();
  jeteta.clear();
  jetphi.clear();
  jetmass.clear();

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

void ExampleVBFHAnalysis::Output()
{

  TFile *_rootFile = new TFile("VBF_invH_8000_output.root","RECREATE");

  _f1stJetPT->Write();
  _f2ndJetPT->Write();
  _fJetEta->Write();
  _fJetPhi->Write();
  _fHT->Write();
  _f1stJetMass->Write();
  _f2ndJetMass->Write();
  _fNJets->Write();
  _rootFile->Write();
  _rootFile->Close();


}

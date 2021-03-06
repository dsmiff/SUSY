// Author: Dominic Smith, University of Bristol/ VUB
//         dominic.smith@bristol.ac.uk
//         October 2013
// Description:
// Analysis code for the T1t1t SUSY model.
// The code utilises the TSelector function of ROOT & has the required header file
// The histo analysis can be found as T1t1t_analysis in another subdirectory

#define ExampleT1t1tAnalysis_cxx
#include "ExampleT1t1tAnalysis.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TH1.h>
#include <TH2.h>
#include <TRef.h>
#include <TClonesArray.h>
#include <TLorentzVector.h>
#include <vector>
#include <iterator>
#include <iostream>

#include "Settings.h"

using namespace std;

class ExRootTreeReader;
class ExRootResult;

Int_t _nEvt = Settings::GetEntries();

void ExampleT1t1tAnalysis::processEvents()
{

  Bool_t printout = 0;

  TH1::SetDefaultSumw2();

  // Book histograms

  _fJetPT = new TH1D("JetPT","JetPT",100, 0.0, 1500);
  _fGenJetPT = new TH1D("GenJetPT","GenJetPT",100, 0.0, 1500);
  _fDeltaJetPTs = new TH1D("DeltaJetPTS","DeltaJetPTs",100, -5, 5);
  _fNJets = new TH1D("NJets", "NJets" , 20, 0, 20);
   _fHT = new TH1D("HT","HT", 100, 0, 3000);
  _fScalarHT = new TH1D("ScalarHT","ScalarHT",100, 0, 3000);
  _f1stJetPT = new TH1D("1stJetPT","1stJetPT", 100, 0, 1500);
  _f2ndJetPT = new TH1D("2ndJetPT","2ndJetPT",100, 0, 1500);
  _fJetEta = new TH1D("JetEta", "JetEta", 100, -5, 5);
  _fJetPhi = new TH1D("JetPhi", "JetPhi", 100, 0, 300);
  _f1stJetMass = new TH1D("1stJetMass","1stJetMass", 100, 0, 300);
  _f2ndJetMass = new TH1D("2ndJetMass","2ndJetMass", 100, 0, 300);
  _fTopPT = new TH1D("TopPT", "TopPT", 100, 0, 1000);
  _fTopStopPT = new TH1D("TopStopPT","TopStopPT",100, 0, 1000);
  _fTopGluinoPT = new TH1D("TopGluinoPT","TopGluinoPT",100, 0, 1000);
  _fStopPT = new TH1D("StopPT","StopPT",100, 0, 1000);
  _fGluinoPT = new TH1D("GluinoPT","GluinoPT",100, 0, 1000);
  _fLSPPT = new TH1D("LSPPT","LSPPT",100, 0, 600);
  _fMET = new TH1D("MET","MET",100, 0, 1000);
  _fDeltaR1 = new TH2F("DeltaR1","DeltaR1",200,0., 1200, 50,0.,6);
  _fDeltaR2 = new TH2F("DeltaR2","DeltaR2",200,0., 1200, 50,0.,6);
  _fDeltaR3 = new TH2F("DeltaR3","DeltaR3",200,0., 1200, 50,0.,6);
  _fDeltaR4 = new TH2F("DeltaR4","DeltaR4",200,0., 1200, 50,0.,6);
  _fNmerged = new TH2F("Nmerged","Nmerged",200,0., 1200, 50, 0.,5);

  //Int_t _nEvt = fChain->GetEntriesFast();

  Long64_t nbytes =0 , nb = 0;

   for (Long64_t entry=0; entry< _nEvt;entry++) {            //  Looping over each entry
     //      Long64_t ientry = LoadTree(entry);
     //  if (ientry < 0) break;
     nb = fChain->GetEntry(entry);  nbytes += nb;

         std::cout << "******* NEW ENTRY["<< entry <<"]" << std::endl;

       if ( printout ) continue;

     this->JetAnalysis();
     this->ParticleAnalysis();
     this->Output();
   }
}

 Int_t ExampleT1t1tAnalysis::JetAnalysis()
{
   Int_t _nJets = sizeof(Jet_PT)/sizeof(Jet_PT[0]);
   Int_t JetPT_cut = 0; // All good up to here
   Long64_t HT = 0;
     
   for(Int_t i=0; i < _nJets; i++){
     //  Looping over jets per event. Apply cuts here
     
     njets.push_back(Jet_size);                   // Transfering array information to vectors
     _fNJets->Fill(njets.at(i));
     
     jetpts.push_back(Jet_PT[i]);
     jetmass.push_back(Jet_Mass[i]);
     jeteta.push_back(Jet_Eta[i]);
     jetphi.push_back(Jet_Phi[i]);
     if(jetpts.at(i) > JetPT_cut){ 
       _fJetPT->Fill(jetpts.at(i));
       _f1stJetPT->Fill(jetpts.at(0));
       _f1stJetMass->Fill(jetmass.at(0));
       _fJetEta->Fill(jeteta.at(i));
       _fJetPhi->Fill(jetphi.at(i));
       
       HT += jetpts.at(i);                        // HT as defined manually (can call Delphes equivalent)
       _fHT->Fill(HT);
     }
     _fMET->Fill(MissingET_MET[0]);
          
     if(jetpts.size() > Settings::NJets()) {
       _f2ndJetPT->Fill(jetpts.at(1));  
       _f2ndJetMass->Fill(jetmass.at(1));
     }
   }    
   
   _fScalarHT->Fill(ScalarHT_HT[0]);
   
   Int_t _nGenJets = sizeof(GenJet_PT)/sizeof(GenJet_PT[0]);
   
   for(Int_t j=0; j < _nGenJets; j++){
     ngenjets.push_back(GenJet_size);
     genjetpts.push_back(GenJet_PT[j]);
     _fGenJetPT->Fill(genjetpts.at(j));
     _fDeltaJetPTs->Fill((genjetpts.at(j) - jetpts.at(j))/genjetpts.at(j));
     }

   njets.clear();
   ngenjets.clear();
   jetpts.clear();
   genjetpts.clear();
   jeteta.clear();
   jetphi.clear();
   jetmass.clear();

   return 0;

}

 Int_t ExampleT1t1tAnalysis::ParticleAnalysis(){

   Int_t _nParticles = sizeof(Particle_PID)/sizeof(Particle_PID[0]);
   Int_t ntops=0, nstops=0, nglu=0, nlsps=0, nws=0;

   for(Int_t i=0; i<_nParticles; i++){
     particles.push_back(Particle_PID[i]);
     particlestatus.push_back(Particle_Status[i]);
     mothers.push_back(Particle_M1[i]);
     particlepts.push_back(Particle_PT[i]);

     Int_t pdgCode = abs(particles.at(i));
     
     if(pdgCode == 6){
       Top.SetPxPyPzE(Particle_Px[i],Particle_Py[i],Particle_Pz[i],Particle_E[i]);
       tops.push_back(Top);
       _fTopPT->Fill(particlepts.at(i));
       ntops++;
       if(abs(particles.at(mothers.at(i))) == 1000006){ _fTopStopPT->Fill(particlepts.at(i)); }
       if(abs(particles.at(mothers.at(i))) == 1000021){ _fTopGluinoPT->Fill(particlepts.at(i)); }
     }	
     else if(pdgCode == 1000006){
       _fStopPT->Fill(particlepts.at(i));
       Stop.SetPxPyPzE(Particle_Px[i],Particle_Py[i],Particle_Pz[i],Particle_E[i]);
       nstops++;
     }
     else if(pdgCode == 1000022){
       _fLSPPT->Fill(particlepts.at(i));
       Lsp.SetPxPyPzE(Particle_Px[i],Particle_Py[i],Particle_Pz[i],Particle_E[i]);
       nlsps++;
     }
     else if(pdgCode == 1000021){
       _fGluinoPT->Fill(particlepts.at(i));
       Gluino.SetPxPyPzE(Particle_Px[i],Particle_Py[i],Particle_Pz[i],Particle_E[i]);
       nglu++;
     }
     else if(pdgCode == 24){ nws++; }
   }
   
   for(Int_t n=0; n < _nParticles; n++){
     if(particlestatus.at(n) == -1) continue; 			// Avoiding any initial state partons that could be bottom quarks
     if(abs(particles.at(n)) == 24){
       if(abs(particles.at(mothers.at(n))) == 6){
	 Wtopindex.push_back(mothers.at(n));
	 WBoson.SetPxPyPzE(Particle_Px[n],Particle_Py[n],Particle_Pz[n],Particle_E[n]);
	 wbosons.push_back(WBoson);
       }
     }
     else if(abs(particles.at(n)) == 5 || abs(particles.at(n)) == 3){
       if(abs(particles.at(mothers.at(n))) == 6){                                                     // Check if parent particle is a top quark 
	 Btopindex.push_back(mothers.at(n));                                                          // Storing the indices of the top quarks into a vector. Same method applied to Ws
	 Bottom.SetPxPyPzE(Particle_Px[n],Particle_Py[n],Particle_Pz[n],Particle_E[n]);                 // Creating a TLorentzVector of bottom quarks 
	 bottoms.push_back(Bottom);                                                                     // Here we store the TLorentzVectors into a vector
       }
     }
   }
      
   // Note that the top quarks are stored above in order of discovery. 
   // In other words, the first top quark in the vector is that which was first seen in analysis code. 
   
   
   Int_t bsize = Btopindex.size();
   Int_t Nmerged = 0;
   Float_t DeltaR1, DeltaR2, DeltaR3, DeltaR4, Frac = 0.0;
   
   
    for(Int_t nn = 0; nn < bsize; nn++){                              
     // Now looping through each entry of the top quark indices to check for matches
      // Assumes W and b/s share same top quark index
      try
	{
	  if(Btopindex.at(nn) == Wtopindex.at(0)){
	    DeltaR1 = sqrt(pow((bottoms.at(nn).Eta() - wbosons.at(0).Eta()),2) + pow((bottoms.at(nn).Phi() - wbosons.at(0).Phi()),2));
	    if(DeltaR1 > 3.14){  DeltaR1 = 2*3.14 - DeltaR1; }
	    DeltaRs.push_back(DeltaR1);
	    if(DeltaR1 < 1) {  Nmerged++;  }
	    _fDeltaR1->Fill(tops.at(0).Pt(),DeltaR1);
	  }
	  else if(Btopindex.at(nn) == Wtopindex.at(1)){
	    DeltaR2 = sqrt(pow((bottoms.at(nn).Eta() - wbosons.at(1).Eta()),2) +pow((bottoms.at(nn).Phi() - wbosons.at(1).Phi()),2));
	    if(DeltaR2 > 3.14){ DeltaR2 = 2*3.14 - DeltaR2; }
	    DeltaRs.push_back(DeltaR2);
	    if(DeltaR2 < 1) {  Nmerged++; }	   
	    _fDeltaR2->Fill(tops.at(1).Pt(),DeltaR2);
	  }
	  else if(Btopindex.at(nn) == Wtopindex.at(2)){
	    DeltaR3 = sqrt(pow((bottoms.at(nn).Eta() - wbosons.at(2).Eta()),2) +pow((bottoms.at(nn).Phi() - wbosons.at(2).Phi()),2));
	    if(DeltaR3 > 3.14){ DeltaR3 = 2*3.14 - DeltaR3; }
	    DeltaRs.push_back(DeltaR3);
	    if(DeltaR3 < 1){ Nmerged++; } 
	    _fDeltaR3->Fill(tops.at(2).Pt(),DeltaR3);
	  }
	  else if(Btopindex.at(nn) == Wtopindex.at(3)){
	    DeltaR4 = sqrt(pow((bottoms.at(nn).Eta() - wbosons.at(3).Eta()),2) +pow((bottoms.at(nn).Phi() - wbosons.at(3).Phi()),2));
	    if(DeltaR4 > 3.14){ DeltaR4 = 2*3.14 - DeltaR4; }
	    DeltaRs.push_back(DeltaR4);
	    if(DeltaR4 < 1){ Nmerged++; }
	    _fDeltaR4->Fill(tops.at(3).Pt(),DeltaR4);
	  }
	  if(bottoms.size() != Settings::Nbottoms())
	    throw "Bottom quark size error ";
	}
      catch(char const* ERROR)
	{ cerr << ERROR << bottoms.size() <<  endl; }
    }
    try
      {
	if(ntops>=5 || ntops!= nws) 
	  throw "too many top quarks or not an equal amount of tops and W bosons";
      }
    catch(char const* err_code)
      {	cerr << "ERROR CODE : " << err_code << endl; }
    try
      {
	if(nlsps >= 3 || nlsps!=nglu || nstops!=nlsps)
	  throw "too many lsps or not an equal amount of gluinos and lsps or of stops and lsps";
      }
    catch(char const* err_code1)
      { cerr << "ERROR CODE : " << err_code1 << endl;  }
    try
      {
	if(  wbosons.size() != Settings::NWbosons() || bottoms.size() != Settings::Nbottoms() )
	  throw "too many W bosons or bottom quarks";
      }
    catch(char const* err_code2){ cerr << "ERROR CODE : " << err_code2 << endl;  }
    
    cout << "Nmerged: " << Nmerged << endl;

    particles.clear();
    mothers.clear();
    particlepts.clear();
    tops.clear();
    bottoms.clear();
    wbosons.clear();
    Btopindex.clear();
    Wtopindex.clear();
    DeltaRs.clear();
    
    return 0;
    
    
 }


Int_t ExampleT1t1tAnalysis::Output()
{
  
  TFile *_rootFile = new TFile("T1t1t_8TeV_1000_500_100_histos.root","RECREATE");
  
  _fJetPT->Write();
  _fGenJetPT->Write();
  _fDeltaJetPTs->Write();
  _f1stJetPT->Write();
  _f2ndJetPT->Write();
  _fJetEta->Write();
  _fJetPhi->Write();
  _f1stJetMass->Write();
  _f2ndJetMass->Write();
  _fHT->Write();
  _fMET->Write();
  _fScalarHT->Write();
  _fNJets->Write();
  _fTopPT->Write();
  _fTopStopPT->Write();
  _fTopGluinoPT->Write();
  _fStopPT->Write();
  _fGluinoPT->Write();
  _fLSPPT->Write();
  _fDeltaR1->Write();
  _fDeltaR2->Write();
  _fDeltaR3->Write();
  _fDeltaR4->Write();
  _rootFile->Write();
  _rootFile->Close();

return 0;
}


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

using namespace std;

class ExRootTreeReader;
class ExRootResult;

void ExampleT1t1tAnalysis::processEvents()
{

  Bool_t printout = 0;

  TH1::SetDefaultSumw2();

  // Book histograms

  _fJetPT = new TH1D("JetPT","JetPT",100, 0.0, 1500);
  _fNJets = new TH1D("NJets", "NJets" , 100, 0, 20);
  _fHT = new TH1D("HT","HT", 100, 0, 3000);
  _f1stJetPT = new TH1D("1stJetPT","1stJetPT", 100, 0, 1500);
  _f2ndJetPT = new TH1D("2ndJetPT","2ndJetPT",100, 0, 1500);
  _fJetEta = new TH1D("JetEta", "JetEta", 100, -5, 5);
  _fJetPhi = new TH1D("JetPhi", "JetPhi", 100, 0, 300);
  _f1stJetMass = new TH1D("1stJetMass","1stJetMass", 100, 0, 300);
  _f2ndJetMass = new TH1D("2ndJetMass","2ndJetMass", 100, 0, 300);
  _fTopPT = new TH1D("TopPT", "TopPT", 100, 0, 1000);
  _fStopPT = new TH1D("StopPT","StopPT",100, 0, 1000);
  _fLSPPT = new TH1D("LSPPT","LSPPT",100, 0, 600);
  _fDeltaR1 = new TH2F("DeltaR1","DeltaR1",200,0., 1200, 50,0.,6);
  _fDeltaR2 = new TH2F("DeltaR2","DeltaR2",200,0., 1200, 50,0.,6);
  _fDeltaR3 = new TH2F("DeltaR3","DeltaR3",200,0., 1200, 50,0.,6);
  _fDeltaR4 = new TH2F("DeltaR4","DeltaR4",200,0., 1200, 50,0.,6);
  


  //  Int_t _nEvt = fChain->GetEntriesFast();
  Int_t  _nEvt = 1000;
  Long64_t nbytes =0 , nb = 0;

   for (Long64_t entry=0; entry<_nEvt;entry++) {            //  Looping over each entry
      Long64_t ientry = LoadTree(entry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(entry);   nbytes += nb;

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
   Int_t JetPT_cut = 0;
   Long64_t HT = 0;

   for(Int_t i=0; i < _nJets; i++){
     //  Looping over jets per event. Apply cuts here

     njets.push_back(Jet_size);                   // Transfering array information to vectors
       if(Jet_PT[i] < JetPT_cut ) continue;
     _fNJets->Fill(njets.at(i));

     jetpts.push_back(Jet_PT[i]);
     jetmass.push_back(Jet_Mass[i]);
     jeteta.push_back(Jet_Eta[i]);
     jetphi.push_back(Jet_Phi[i]);
     _fJetPT->Fill(jetpts.at(i));
     _f1stJetPT->Fill(jetpts.at(0));
     _f1stJetMass->Fill(jetmass.at(0));
     _fJetEta->Fill(jeteta.at(i));
     _fJetPhi->Fill(jetphi.at(i));

     HT += jetpts.at(i);                        // HT as defined manually (can call Delphes equivalent)
     _fHT->Fill(HT);

     if(jetpts.size() > 1) {
     _f2ndJetPT->Fill(jetpts.at(1));  
     _f2ndJetMass->Fill(jetmass.at(1));
     }


       }    

   njets.clear();
   jetpts.clear();
   jeteta.clear();
   jetmass.clear();


   return 0;
 }

 Int_t ExampleT1t1tAnalysis::ParticleAnalysis(){

	 Int_t _nParticles = sizeof(Particle_PID)/sizeof(Particle_PID[0]);
	 Int_t ntops=0, nstops=0, nglu=0, nlsps=0, nws=0;

	 for(Int_t i=0; i<_nParticles; i++){
		 particles.push_back(Particle_PID[i]);
		 mothers.push_back(Particle_M1[i]);
		 particlepts.push_back(Particle_PT[i]);

		 if(abs(particles.at(i)) == 6){
		 _fTopPT->Fill(particlepts.at(i));
		 Top.SetPxPyPzE(Particle_Px[i],Particle_Py[i],Particle_Pz[i],Particle_E[i]);
		 tops.push_back(Top);                                                          // Storing the top quark TLorentzVectors into another vector
		 ntops++;
		 }	
		 else if(abs(particles.at(i)) == 1000006){
		   _fStopPT->Fill(particlepts.at(i));
		   Stop.SetPxPyPzE(Particle_Px[i],Particle_Py[i],Particle_Pz[i],Particle_E[i]);
		   nstops++;
		 }
		 else if(abs(particles.at(i)) == 1000022){
		   _fLSPPT->Fill(particlepts.at(i));
		   Lsp.SetPxPyPzE(Particle_Px[i],Particle_Py[i],Particle_Pz[i],Particle_E[i]);
		   nlsps++;
		 }
		 else if(abs(particles.at(i)) == 1000021){
		   Gluino.SetPxPyPzE(Particle_Px[i],Particle_Py[i],Particle_Pz[i],Particle_E[i]);
		   nglu++;
		 }
		 else if(abs(particles.at(i)) == 24){
		   nws++;
		 }
      	 }
	
	 // Analyse the effect of top quark boost on decay products 
	 
	 for(Int_t n=0; n< _nParticles; n++){
	   if(abs(particles.at(n)) == 5){
     	     Bottom.SetPxPyPzE(Particle_Px[n],Particle_Py[n],Particle_Pz[n],Particle_E[n]);                 // Creating a TLorentzVector of bottom quarks 
	     bottoms.push_back(Bottom);                                                                     // Here we store the TLorentzVectors into a vector
	     if(abs(particles.at(mothers.at(n))) == 6){                                                     // Check if parent particle is a top quark 
	       Btopindex.push_back(mothers.at(n));                                                          // Storing the indices of the top quarks into a vector. Same method applied to Ws
	     }
	   }
	   else if(abs(particles.at(n)) == 24){
	     WBoson.SetPxPyPzE(Particle_Px[n],Particle_Py[n],Particle_Pz[n],Particle_E[n]);
	     wbosons.push_back(WBoson);
	     if(abs(particles.at(mothers.at(n))) == 6){
	       Wtopindex.push_back(mothers.at(n));
	     }
	   }
	 }
	 
	 // Note that the top quarks are stored above in order of discovery. In other words, the first top quark in the vector is that which was first seen in analysis code. 

	 Int_t bsize = Btopindex.size();
	 Float_t DeltaR1, DeltaR2, DeltaR3, DeltaR4;
	 for(Int_t nn = 0; nn < bsize; nn++){                                 // Now looping through each entry of the top quark indices to check for matches
	   if(Btopindex.at(nn) == Wtopindex.at(0)){
	     DeltaR1 = sqrt(pow((bottoms.at(nn).Eta() - wbosons.at(0).Eta()),2) + pow((bottoms.at(nn).Phi() - wbosons.at(0).Phi()),2));
	     if(DeltaR1 > 3.14){
	       DeltaR1 = 2*3.14 - DeltaR1;
	     }
	     _fDeltaR1->Fill(tops.at(0).Pt(),DeltaR1);
      	   }
	   else if(Btopindex.at(nn) == Wtopindex.at(1)){
	     DeltaR2 = sqrt(pow((bottoms.at(nn).Eta() - wbosons.at(1).Eta()),2) +pow((bottoms.at(nn).Phi() - wbosons.at(1).Phi()),2));
	     if(DeltaR2 > 3.14){
	       DeltaR2 = 2*3.14 - DeltaR2;
	     }
	     _fDeltaR2->Fill(tops.at(1).Pt(),DeltaR2);
	   }
	   else if(Btopindex.at(nn) == Wtopindex.at(2)){
	     DeltaR3 = sqrt(pow((bottoms.at(nn).Eta() - wbosons.at(2).Eta()),2) +pow((bottoms.at(nn).Phi() - wbosons.at(2).Phi()),2));
	     if(DeltaR3 > 3.14){
	       DeltaR3 = 2*3.14 - DeltaR3;
	     }
	     _fDeltaR3->Fill(tops.at(2).Pt(),DeltaR3);
	   }
	   else if(Btopindex.at(nn) == Wtopindex.at(3)){
	     DeltaR4 = sqrt(pow((bottoms.at(nn).Eta() - wbosons.at(3).Eta()),2) +pow((bottoms.at(nn).Phi() - wbosons.at(3).Phi()),2));
	     if(DeltaR4 > 3.14){
	       DeltaR4 = 2*3.14 - DeltaR4;
	     }
	     _fDeltaR4->Fill(tops.at(3).Pt(),DeltaR4);
	   }
	   
	 }


	// Sanity check on final state per event
	 try
	  {
	if(ntops>=5 || ntops!= nws)
	  throw "too many top quarks or not an equal amount of tops and W bosons";
	  }
	catch(char const* err_code)
	  {
	    std::cout << "ERROR CODE : " << err_code << std::endl;
	  }
	try
	  {
	    if(nlsps >= 3 || nlsps!=nglu || nstops!=nlsps)
	      throw "too many lsps or not an equal amount of gluinos and lsps or of stops and lsps";
		}
	catch(char const* err_code1)
	  {
	    std::cout << "ERROR CODE : " << err_code1 << std::endl;
	  }
	
	particles.clear();
	mothers.clear();
  	particlepts.clear();
	tops.clear();
	bottoms.clear();
	wbosons.clear();
	Btopindex.clear();
	Wtopindex.clear();

	return 0;
	


 }


Int_t ExampleT1t1tAnalysis::Output()
{

  TFile *_rootFile = new TFile("T1t1t_output.root","RECREATE");

  _fJetPT->Write();
  _f1stJetPT->Write();
  _f2ndJetPT->Write();
  _fJetEta->Write();
  _fJetPhi->Write();
  _f1stJetMass->Write();
  _f2ndJetMass->Write();
  _fHT->Write();
  _fNJets->Write();
  _fTopPT->Write();
  _fStopPT->Write();
  _fLSPPT->Write();
  _fDeltaR1->Write();
  _fDeltaR2->Write();
  _fDeltaR3->Write();
  _fDeltaR4->Write();
  _rootFile->Write();
  _rootFile->Close();

return 0;
}


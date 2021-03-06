#include "TLorentzVector.h"
#include <vector>
#include <algorithm>

struct TestPlots
{
  TH1 *_JetPT;
  TH1 *_TowerMomenta;
  TH1 *_TrackMomenta;
  TH1 *_MuonMomenta;
  TH1 *_JetConsts;
  TH1 *_Constituents;
  TH1 *_Efficiency;
};




//------------------------------------------------------------------------------

class ExRootResult;
class ExRootTreeReader;

//------------------------------------------------------------------------------

void BookHistograms(ExRootResult *result, TestPlots *plots)
{
  TLegend *legend;
  TPaveText *comment;


  plots->_JetPT = result->AddHist1D("_JetPT", "Jet P_{T}","Jet P_{T}", "Events", 100, 0.0, 1000);

  
  plots->_TowerMomenta = result->AddHist1D("tower_momenta", "tower momenta", "P_{T}", "Events", 100, 0.0, 1000);
  plots->_TracKMomenta = result->AddHist1D("track_momenta", "track momenta", "P_{T}", "Events", 100, 0.0, 1000);
  plots->_MuonMomenta = result->AddHist1D("muon_momenta", "muon momenta" , "P_{T}", "Events", 100, 0.0, 1000);
  plots->_JetConsts = result->AddHist1D("Constituents","Constituents", "P_{T}", "Events", 100, 0.0, 1000);
  plots->_Constituents = result->AddHist1D("_Consts", "# constituents","# constituents","Events", 10, 0.0, 10);
  plots->_Efficiency = result->AddHist1D("Jet_constituents", "Efficiency", "P_{T}", "P_T}^{constituents} - P_{T}^{jet} / P_{T}^{jet}", 100, 0.0, 1000); 

}

//------------------------------------------------------------------------------

void AnalyseEvents(ExRootTreeReader *treeReader, TestPlots *plots)
{

  TClonesArray *branchParticle = treeReader->UseBranch("Particle");
  TClonesArray *branchElectron = treeReader->UseBranch("Electron");
  TClonesArray *branchPhoton = treeReader->UseBranch("Photon");
  TClonesArray *branchMuon = treeReader->UseBranch("Muon");

  TClonesArray *branchEFlowTrack = treeReader->UseBranch("EFlowTrack");  // These 3 are used in finding reco jets
  TClonesArray *branchEFlowTower = treeReader->UseBranch("EFlowTower");  // 
  TClonesArray *branchEFlowMuon = treeReader->UseBranch("EFlowMuon");    // 
  TClonesArray *branchJet = treeReader->UseBranch("Jet");

  Long64_t allEntries = treeReader->GetEntries();
  //    Long64_t allEntries = 1000;


  cout << "** Chain contains " << allEntries << " events" << endl;

  GenParticle *particle;
  Electron *electron;
  Photon *photon;
  Muon *muon;

  Track *track;
  Tower *tower;

  Jet *jet;
  Jet *subjet[2];
  TObject *object;
  TObjArray *objects[2];

  TLorentzVector genparticles;
  TLorentzVector towers;
  TLorentzVector tracks;
  TLorentzVector muons;

  TLorentzVector momentum;
  //  TLorentzVector momentum2;
  //  std::vector<TLorentzVector> Subjets;
  std::vector<TLorentzVector> GenParticleMomenta;
  std::vector<TLorentzVector> TowerMomenta;
  std::vector<TLorentzVector> TrackMomenta;
  std::vector<TLorentzVector> MuonMomenta;
  

  // Loop over all events
  for(Long64_t entry = 0; entry < allEntries; ++entry)
  {
    // Load selected branches with data from specified event
    treeReader->ReadEntry(entry);

    std::cout << "\n ** NEW ENTRY ** : " << entry << std::endl;

    // Loop over all jets in event. Up to here successfully returns the PT of ecah jet per event 
    for(i = 0; i < branchJet->GetEntriesFast(); ++i)
    {
      
      std::cout << "\nNew jet" << std::endl;

      jet = (Jet*) branchJet->At(i);

      // This is the source for jet finding 

      genparticles.SetPxPyPzE(0.0,0.0,0.0,0.0);
      towers.SetPxPyPzE(0.0,0.0,0.0,0.0);
      tracks.SetPxPyPzE(0.0,0.0,0.0,0.0);
      muons.SetPxPyPzE(0.0,0.0,0.0,0.0);


      std::cout << "Jet Constituents: " << jet->Constituents.GetEntriesFast() << std::endl;

      plots->_JetPT->Fill(jet->PT);
      plots->_Constituents->Fill(jet->Constituents.GetEntriesFast());
      


      // Loop over all jet's constituents
      for(j = 0; j < jet->Constituents.GetEntriesFast(); ++j)
      {
        object = jet->Constituents.At(j);

	

        // Check if the constituent is accessible, if object exists then continue
	// Would want to push the different momentum TLorentzVectors into a vector


        if(object == 0) continue;
	

        if(object->IsA() == GenParticle::Class())
        {
          genparticles = ((GenParticle*) object)->P4();
	  std::cout << "gen particles momentum:" << genparticles.Pt() << std::endl;
	  std::cout << "gen particles mass: " << genparticles.M() << std::endl;
	  plots->_JetConsts->Fill(genparticles.Pt());
	}
        else if(object->IsA() == Track::Class())
        {
          tracks = ((Track*) object)->P4();
	  //	  std::cout << "track momentum: " << tracks.Pt() << std::endl;
	  // std::cout << "track mass: " << tracks.M() << std::endl;
	  plots->_JetConsts->Fill(tracks.Pt());
        }
        else if(object->IsA() == Tower::Class())
        {
          towers = ((Tower*) object)->P4();
	  //	  std::cout << "tower momentum :" << towers.Pt() << std::endl;	
	  //	  std::cout << "tower mass: " << towers.M() << std::endl;
	  plots->_JetConsts->Fill(towers.Pt());
	}
        else if(object->IsA() == Muon::Class())
        {
          muons = ((Muon*) object)->P4();
	  //	  std::cout << "muon momentum: " << muons.Pt() << std::endl;
	  //	  std::cout << "muon mass: " << muons.M() << std::endl;
	  plots->_JetConsts->Fill(muons.Pt());
        }
	

	Double_t momenta = (genparticles.Pt() + tracks.Pt() + towers.Pt() + muons.Pt())*1.08;
	
	Double_t efficiency = (momenta - jet->PT)/jet->PT;
	
	plots->_Efficiency->Fill(efficiency);

	//	cout << "Total momenta: " << momenta << endl;

	GenParticleMomenta.push_back(genparticles);
	TrackMomenta.push_back(tracks);
	TowerMomenta.push_back(towers);
	MuonMomenta.push_back(muons);
	 


      }
     
      //        std::cout << "Tower momenta: " << TowerMomenta.at(0).Pt() << std::endl;
      //	std::cout << "Jet PT : " << jet->PT << std::endl;
      //	std::cout << "Jet Mass : " << jet->Mass << std::endl;
	/*
	if(TowerMomenta.at(1).Pt() > 0){ 
	std::cout << "Tower 2 momentum: " << TowerMomenta.at(1).Pt() << std::endl;
	}
	*/
	
	
	
	TowerMomenta.clear();
	TrackMomenta.clear();
	MuonMomenta.clear();
	GenParticleMomenta.clear();





    }
  


  }
}

//------------------------------------------------------------------------------

void PrintHistograms(ExRootResult *result, TestPlots *plots)
{
  result->Print("png");
  std::cout << "JetPT entries: " << plots->_JetPT->GetEntries() << std::endl;
  std::cout << "Jet constituents entries: " << plots->_JetConsts->GetEntries() << std::endl;

}

//------------------------------------------------------------------------------

void JetConstituents(const char *inputFile)
{
  gSystem->Load("libDelphes");

  TChain *chain = new TChain("Delphes");
  chain->Add(inputFile);

  ExRootTreeReader *treeReader = new ExRootTreeReader(chain);
  ExRootResult *result = new ExRootResult();

  TestPlots *plots = new TestPlots;

  BookHistograms(result, plots);

  AnalyseEvents(treeReader, plots);

  PrintHistograms(result, plots);

  result->Write("results.root");

  cout << "** Exiting..." << endl;

  delete plots;
  delete result;
  delete treeReader;
  delete chain;



}

//------------------------------------------------------------------------------

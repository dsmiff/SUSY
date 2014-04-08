#ifndef ExampleVBFHAnalysis_h
#define ExampleVBFHAnalysis_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TRef.h>
#include <TClonesArray.h>
#include <TObject.h>
#include <TRefArray.h>

using namespace std;

// Fixed size dimensions of array or collections stored in the TTree if any.
const Int_t kMaxEvent = 1;
const Int_t kMaxRwgt = 1;
const Int_t kMaxParticle = 5;
const Int_t kMaxTrack = 820;
const Int_t kMaxTower = 2753;
const Int_t kMaxEFlowTrack = 820;
const Int_t kMaxEFlowTower = 2574;
const Int_t kMaxGenJet = 2;
const Int_t kMaxJet = 6;
const Int_t kMaxElectron = 1;
const Int_t kMaxPhoton = 3;
const Int_t kMaxMuon = 1;
const Int_t kMaxMissingET = 1;
const Int_t kMaxScalarHT = 1;
const Int_t kMaxRho = 2;
const Int_t kMaxVertex = 27;

class ExampleVBFHAnalysis {
public :
   TTree          *fChain;
   Int_t           fCurrent;
   Int_t           _nEvt;

   // Declaration of leaf types
   Int_t           Event_;
   UInt_t          Event_fUniqueID[kMaxEvent];    
   UInt_t          Event_fBits[kMaxEvent];    
   Long64_t        Event_Number[kMaxEvent];    
   Float_t         Event_ReadTime[kMaxEvent];    
   Float_t         Event_ProcTime[kMaxEvent];    
   Int_t           Event_ProcessID[kMaxEvent];    
   Float_t         Event_Weight[kMaxEvent];    
   Float_t         Event_ScalePDF[kMaxEvent];    
   Float_t         Event_AlphaQED[kMaxEvent];    
   Float_t         Event_AlphaQCD[kMaxEvent];    
   Int_t           Event_size;
   Int_t           Rwgt_;
   UInt_t          Rwgt_fUniqueID[kMaxRwgt];   
   UInt_t          Rwgt_fBits[kMaxRwgt];  
   Float_t         Rwgt_Weight[kMaxRwgt]; 
   Int_t           Rwgt_size;
   Int_t           Particle_;
   UInt_t          Particle_fUniqueID[kMaxParticle];    
   UInt_t          Particle_fBits[kMaxParticle];    
   Int_t           Particle_PID[kMaxParticle];    
   Int_t           Particle_Status[kMaxParticle];    
   Int_t           Particle_IsPU[kMaxParticle];    
   Int_t           Particle_M1[kMaxParticle];    
   Int_t           Particle_M2[kMaxParticle];    
   Int_t           Particle_D1[kMaxParticle];  
   Int_t           Particle_D2[kMaxParticle];  
   Int_t           Particle_Charge[kMaxParticle];
   Float_t         Particle_Mass[kMaxParticle];
   Float_t         Particle_E[kMaxParticle];   
   Float_t         Particle_Px[kMaxParticle];  
   Float_t         Particle_Py[kMaxParticle];  
   Float_t         Particle_Pz[kMaxParticle];  
   Float_t         Particle_PT[kMaxParticle];  
   Float_t         Particle_Eta[kMaxParticle]; 
   Float_t         Particle_Phi[kMaxParticle]; 
   Float_t         Particle_Rapidity[kMaxParticle];
   Float_t         Particle_T[kMaxParticle];
   Float_t         Particle_X[kMaxParticle];
   Float_t         Particle_Y[kMaxParticle];
   Float_t         Particle_Z[kMaxParticle];
   Int_t           Particle_size;
   Int_t           Track_;
   UInt_t          Track_fUniqueID[kMaxTrack];    
   UInt_t          Track_fBits[kMaxTrack];    
   Int_t           Track_PID[kMaxTrack];    
   Int_t           Track_Charge[kMaxTrack];    
   Float_t         Track_PT[kMaxTrack];    
   Float_t         Track_Eta[kMaxTrack];    
   Float_t         Track_Phi[kMaxTrack];    
   Float_t         Track_EtaOuter[kMaxTrack];    
   Float_t         Track_PhiOuter[kMaxTrack];    
   Float_t         Track_X[kMaxTrack];    
   Float_t         Track_Y[kMaxTrack];    
   Float_t         Track_Z[kMaxTrack];    
   Float_t         Track_T[kMaxTrack];    
   Float_t         Track_XOuter[kMaxTrack];    
   Float_t         Track_YOuter[kMaxTrack];    
   Float_t         Track_ZOuter[kMaxTrack];    
   Float_t         Track_TOuter[kMaxTrack];    
   TRef            Track_Particle[kMaxTrack];
   Int_t           Track_size;
   Int_t           Tower_;
   UInt_t          Tower_fUniqueID[kMaxTower];    
   UInt_t          Tower_fBits[kMaxTower];    
   Float_t         Tower_ET[kMaxTower];    
   Float_t         Tower_Eta[kMaxTower];    
   Float_t         Tower_Phi[kMaxTower];    
   Float_t         Tower_E[kMaxTower];    
   Float_t         Tower_T[kMaxTower];    
   Float_t         Tower_Eem[kMaxTower];    
   Float_t         Tower_Ehad[kMaxTower];    
   Float_t         Tower_Edges[kMaxTower][4];    
   TRefArray       Tower_Particles[kMaxTower];
   Int_t           Tower_size;
   Int_t           EFlowTrack_;
   UInt_t          EFlowTrack_fUniqueID[kMaxEFlowTrack];    
   UInt_t          EFlowTrack_fBits[kMaxEFlowTrack];    
   Int_t           EFlowTrack_PID[kMaxEFlowTrack];    
   Int_t           EFlowTrack_Charge[kMaxEFlowTrack];    
   Float_t         EFlowTrack_PT[kMaxEFlowTrack];    
   Float_t         EFlowTrack_Eta[kMaxEFlowTrack];    
   Float_t         EFlowTrack_Phi[kMaxEFlowTrack];    
   Float_t         EFlowTrack_EtaOuter[kMaxEFlowTrack];    
   Float_t         EFlowTrack_PhiOuter[kMaxEFlowTrack];    
   Float_t         EFlowTrack_X[kMaxEFlowTrack];    
   Float_t         EFlowTrack_Y[kMaxEFlowTrack];    
   Float_t         EFlowTrack_Z[kMaxEFlowTrack];    
   Float_t         EFlowTrack_T[kMaxEFlowTrack];    
   Float_t         EFlowTrack_XOuter[kMaxEFlowTrack];    
   Float_t         EFlowTrack_YOuter[kMaxEFlowTrack];    
   Float_t         EFlowTrack_ZOuter[kMaxEFlowTrack];    
   Float_t         EFlowTrack_TOuter[kMaxEFlowTrack];    
   TRef            EFlowTrack_Particle[kMaxEFlowTrack];
   Int_t           EFlowTrack_size;
   Int_t           EFlowTower_;
   UInt_t          EFlowTower_fUniqueID[kMaxEFlowTower];    
   UInt_t          EFlowTower_fBits[kMaxEFlowTower];    
   Float_t         EFlowTower_ET[kMaxEFlowTower];    
   Float_t         EFlowTower_Eta[kMaxEFlowTower];    
   Float_t         EFlowTower_Phi[kMaxEFlowTower];    
   Float_t         EFlowTower_E[kMaxEFlowTower];    
   Float_t         EFlowTower_T[kMaxEFlowTower];    
   Float_t         EFlowTower_Eem[kMaxEFlowTower];    
   Float_t         EFlowTower_Ehad[kMaxEFlowTower];    
   Float_t         EFlowTower_Edges[kMaxEFlowTower][4];    
   TRefArray       EFlowTower_Particles[kMaxEFlowTower];
   Int_t           EFlowTower_size;
   Int_t           GenJet_;
   UInt_t          GenJet_fUniqueID[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_fBits[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_PT[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_Eta[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_Phi[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_T[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_Mass[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_DeltaEta[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_DeltaPhi[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_BTag[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_TauTag[kMaxGenJet];   //[GenJet_]
   Int_t           GenJet_Charge[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_EhadOverEem[kMaxGenJet];   //[GenJet_]
   TRefArray       GenJet_Constituents[kMaxGenJet];
   TRefArray       GenJet_Particles[kMaxGenJet];
   Int_t           GenJet_NCharged[kMaxGenJet];   //[GenJet_]
   Int_t           GenJet_NNeutrals[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_Beta[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_BetaStar[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_MeanSqDeltaR[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_PTD[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_FracPt[kMaxGenJet][5];   //[GenJet_]
   Int_t           GenJet_size;
   Int_t           Jet_;
   UInt_t          Jet_fUniqueID[kMaxJet];   //[Jet_]
   UInt_t          Jet_fBits[kMaxJet];   //[Jet_]
   Float_t         Jet_PT[kMaxJet];   //[Jet_]
   Float_t         Jet_Eta[kMaxJet];   //[Jet_]
   Float_t         Jet_Phi[kMaxJet];   //[Jet_]
   Float_t         Jet_T[kMaxJet];   //[Jet_]
   Float_t         Jet_Mass[kMaxJet];   //[Jet_]
   Float_t         Jet_DeltaEta[kMaxJet];   //[Jet_]
   Float_t         Jet_DeltaPhi[kMaxJet];   //[Jet_]
   UInt_t          Jet_BTag[kMaxJet];   //[Jet_]
   UInt_t          Jet_TauTag[kMaxJet];   //[Jet_]
   Int_t           Jet_Charge[kMaxJet];   //[Jet_]
   Float_t         Jet_EhadOverEem[kMaxJet];   //[Jet_]
   TRefArray       Jet_Constituents[kMaxJet];
   TRefArray       Jet_Particles[kMaxJet];
   Int_t           Jet_NCharged[kMaxJet];   //[Jet_]
   Int_t           Jet_NNeutrals[kMaxJet];   //[Jet_]
   Float_t         Jet_Beta[kMaxJet];   //[Jet_]
   Float_t         Jet_BetaStar[kMaxJet];   //[Jet_]
   Float_t         Jet_MeanSqDeltaR[kMaxJet];   //[Jet_]
   Float_t         Jet_PTD[kMaxJet];   //[Jet_]
   Float_t         Jet_FracPt[kMaxJet][5];   //[Jet_]
   Int_t           Jet_size;
   Int_t           Electron_;
   UInt_t          Electron_fUniqueID[kMaxElectron];   //[Electron_]
   UInt_t          Electron_fBits[kMaxElectron];   //[Electron_]
   Float_t         Electron_PT[kMaxElectron];   //[Electron_]
   Float_t         Electron_Eta[kMaxElectron];   //[Electron_]
   Float_t         Electron_Phi[kMaxElectron];   //[Electron_]
   Float_t         Electron_T[kMaxElectron];   //[Electron_]
   Int_t           Electron_Charge[kMaxElectron];   //[Electron_]
   Float_t         Electron_EhadOverEem[kMaxElectron];   //[Electron_]
   TRef            Electron_Particle[kMaxElectron];
   Int_t           Electron_size;
   Int_t           Photon_;
   UInt_t          Photon_fUniqueID[kMaxPhoton];   //[Photon_]
   UInt_t          Photon_fBits[kMaxPhoton];   //[Photon_]
   Float_t         Photon_PT[kMaxPhoton];   //[Photon_]
   Float_t         Photon_Eta[kMaxPhoton];   //[Photon_]
   Float_t         Photon_Phi[kMaxPhoton];   //[Photon_]
   Float_t         Photon_E[kMaxPhoton];   //[Photon_]
   Float_t         Photon_T[kMaxPhoton];   //[Photon_]
   Float_t         Photon_EhadOverEem[kMaxPhoton];   //[Photon_]
   TRefArray       Photon_Particles[kMaxPhoton];
   Int_t           Photon_size;
   Int_t           Muon_;
   UInt_t          Muon_fUniqueID[kMaxMuon];   //[Muon_]
   UInt_t          Muon_fBits[kMaxMuon];   //[Muon_]
   Float_t         Muon_PT[kMaxMuon];   //[Muon_]
   Float_t         Muon_Eta[kMaxMuon];   //[Muon_]
   Float_t         Muon_Phi[kMaxMuon];   //[Muon_]
   Float_t         Muon_T[kMaxMuon];   //[Muon_]
   Int_t           Muon_Charge[kMaxMuon];   //[Muon_]
   TRef            Muon_Particle[kMaxMuon];
   Int_t           Muon_size;
   Int_t           MissingET_;
   UInt_t          MissingET_fUniqueID[kMaxMissingET];   //[MissingET_]
   UInt_t          MissingET_fBits[kMaxMissingET];   //[MissingET_]
   Float_t         MissingET_MET[kMaxMissingET];   //[MissingET_]
   Float_t         MissingET_Eta[kMaxMissingET];   //[MissingET_]
   Float_t         MissingET_Phi[kMaxMissingET];   //[MissingET_]
   Int_t           MissingET_size;
   Int_t           ScalarHT_;
   UInt_t          ScalarHT_fUniqueID[kMaxScalarHT];   //[ScalarHT_]
   UInt_t          ScalarHT_fBits[kMaxScalarHT];   //[ScalarHT_]
   Float_t         ScalarHT_HT[kMaxScalarHT];   //[ScalarHT_]
   Int_t           ScalarHT_size;
   Int_t           Rho_;
   UInt_t          Rho_fUniqueID[kMaxRho];   //[Rho_]
   UInt_t          Rho_fBits[kMaxRho];   //[Rho_]
   Float_t         Rho_Rho[kMaxRho];   //[Rho_]
   Float_t         Rho_Edges[kMaxRho][2];   //[Rho_]
   Int_t           Rho_size;
   Int_t           Vertex_;
   UInt_t          Vertex_fUniqueID[kMaxVertex];   //[Vertex_]
   UInt_t          Vertex_fBits[kMaxVertex];   //[Vertex_]
   Float_t         Vertex_T[kMaxVertex];   //[Vertex_]
   Float_t         Vertex_X[kMaxVertex];   //[Vertex_]
   Float_t         Vertex_Y[kMaxVertex];   //[Vertex_]
   Float_t         Vertex_Z[kMaxVertex];   //[Vertex_]
   Int_t           Vertex_size;

   // List of branches
   TBranch        *b_Event_;    
   TBranch        *b_Event_fUniqueID;    
   TBranch        *b_Event_fBits;    
   TBranch        *b_Event_Number;    
   TBranch        *b_Event_ReadTime;    
   TBranch        *b_Event_ProcTime;    
   TBranch        *b_Event_ProcessID;    
   TBranch        *b_Event_Weight;    
   TBranch        *b_Event_ScalePDF;    
   TBranch        *b_Event_AlphaQED;    
   TBranch        *b_Event_AlphaQCD;    
   TBranch        *b_Event_size;    
   TBranch        *b_Rwgt_;    
   TBranch        *b_Rwgt_fUniqueID;    
   TBranch        *b_Rwgt_fBits;    
   TBranch        *b_Rwgt_Weight;    
   TBranch        *b_Rwgt_size;    
   TBranch        *b_Particle_;    
   TBranch        *b_Particle_fUniqueID;    
   TBranch        *b_Particle_fBits;    
   TBranch        *b_Particle_PID;    
   TBranch        *b_Particle_Status;    
   TBranch        *b_Particle_IsPU;    
   TBranch        *b_Particle_M1;    
   TBranch        *b_Particle_M2;    
   TBranch        *b_Particle_D1;    
   TBranch        *b_Particle_D2;    
   TBranch        *b_Particle_Charge;    
   TBranch        *b_Particle_Mass;    
   TBranch        *b_Particle_E;    
   TBranch        *b_Particle_Px;    
   TBranch        *b_Particle_Py;    
   TBranch        *b_Particle_Pz;    
   TBranch        *b_Particle_PT;    
   TBranch        *b_Particle_Eta;    
   TBranch        *b_Particle_Phi;    
   TBranch        *b_Particle_Rapidity;    
   TBranch        *b_Particle_T;    
   TBranch        *b_Particle_X;    
   TBranch        *b_Particle_Y;    
   TBranch        *b_Particle_Z;    
   TBranch        *b_Particle_size;    
   TBranch        *b_Track_;    
   TBranch        *b_Track_fUniqueID;    
   TBranch        *b_Track_fBits;    
   TBranch        *b_Track_PID;    
   TBranch        *b_Track_Charge;    
   TBranch        *b_Track_PT;    
   TBranch        *b_Track_Eta;    
   TBranch        *b_Track_Phi;    
   TBranch        *b_Track_EtaOuter;    
   TBranch        *b_Track_PhiOuter;    
   TBranch        *b_Track_X;    
   TBranch        *b_Track_Y;    
   TBranch        *b_Track_Z;    
   TBranch        *b_Track_T;    
   TBranch        *b_Track_XOuter;    
   TBranch        *b_Track_YOuter;    
   TBranch        *b_Track_ZOuter;    
   TBranch        *b_Track_TOuter;    
   TBranch        *b_Track_Particle;    
   TBranch        *b_Track_size;    
   TBranch        *b_Tower_;    
   TBranch        *b_Tower_fUniqueID;    
   TBranch        *b_Tower_fBits;    
   TBranch        *b_Tower_ET;    
   TBranch        *b_Tower_Eta;    
   TBranch        *b_Tower_Phi;    
   TBranch        *b_Tower_E;    
   TBranch        *b_Tower_T;    
   TBranch        *b_Tower_Eem;    
   TBranch        *b_Tower_Ehad;    
   TBranch        *b_Tower_Edges;    
   TBranch        *b_Tower_Particles;    
   TBranch        *b_Tower_size;    
   TBranch        *b_EFlowTrack_;    
   TBranch        *b_EFlowTrack_fUniqueID;    
   TBranch        *b_EFlowTrack_fBits;    
   TBranch        *b_EFlowTrack_PID;    
   TBranch        *b_EFlowTrack_Charge;    
   TBranch        *b_EFlowTrack_PT;    
   TBranch        *b_EFlowTrack_Eta;    
   TBranch        *b_EFlowTrack_Phi;    
   TBranch        *b_EFlowTrack_EtaOuter;    
   TBranch        *b_EFlowTrack_PhiOuter;    
   TBranch        *b_EFlowTrack_X;    
   TBranch        *b_EFlowTrack_Y;    
   TBranch        *b_EFlowTrack_Z;    
   TBranch        *b_EFlowTrack_T;    
   TBranch        *b_EFlowTrack_XOuter;    
   TBranch        *b_EFlowTrack_YOuter;    
   TBranch        *b_EFlowTrack_ZOuter;    
   TBranch        *b_EFlowTrack_TOuter;    
   TBranch        *b_EFlowTrack_Particle;    
   TBranch        *b_EFlowTrack_size;    
   TBranch        *b_EFlowTower_;    
   TBranch        *b_EFlowTower_fUniqueID;    
   TBranch        *b_EFlowTower_fBits;    
   TBranch        *b_EFlowTower_ET;    
   TBranch        *b_EFlowTower_Eta;    
   TBranch        *b_EFlowTower_Phi;    
   TBranch        *b_EFlowTower_E;    
   TBranch        *b_EFlowTower_T;    
   TBranch        *b_EFlowTower_Eem;    
   TBranch        *b_EFlowTower_Ehad;    
   TBranch        *b_EFlowTower_Edges;    
   TBranch        *b_EFlowTower_Particles;    
   TBranch        *b_EFlowTower_size;    
   TBranch        *b_GenJet_;    
   TBranch        *b_GenJet_fUniqueID;    
   TBranch        *b_GenJet_fBits;    
   TBranch        *b_GenJet_PT;    
   TBranch        *b_GenJet_Eta;    
   TBranch        *b_GenJet_Phi;    
   TBranch        *b_GenJet_T;    
   TBranch        *b_GenJet_Mass;    
   TBranch        *b_GenJet_DeltaEta;    
   TBranch        *b_GenJet_DeltaPhi;    
   TBranch        *b_GenJet_BTag;    
   TBranch        *b_GenJet_TauTag;    
   TBranch        *b_GenJet_Charge;    
   TBranch        *b_GenJet_EhadOverEem;    
   TBranch        *b_GenJet_Constituents;    
   TBranch        *b_GenJet_Particles;    
   TBranch        *b_GenJet_NCharged;    
   TBranch        *b_GenJet_NNeutrals;    
   TBranch        *b_GenJet_Beta;    
   TBranch        *b_GenJet_BetaStar;    
   TBranch        *b_GenJet_MeanSqDeltaR;    
   TBranch        *b_GenJet_PTD;    
   TBranch        *b_GenJet_FracPt;    
   TBranch        *b_GenJet_size;    
   TBranch        *b_Jet_;    
   TBranch        *b_Jet_fUniqueID;    
   TBranch        *b_Jet_fBits;    
   TBranch        *b_Jet_PT;    
   TBranch        *b_Jet_Eta;    
   TBranch        *b_Jet_Phi;    
   TBranch        *b_Jet_T;    
   TBranch        *b_Jet_Mass;    
   TBranch        *b_Jet_DeltaEta;    
   TBranch        *b_Jet_DeltaPhi;    
   TBranch        *b_Jet_BTag;    
   TBranch        *b_Jet_TauTag;    
   TBranch        *b_Jet_Charge;    
   TBranch        *b_Jet_EhadOverEem;    
   TBranch        *b_Jet_Constituents;    
   TBranch        *b_Jet_Particles;    
   TBranch        *b_Jet_NCharged;    
   TBranch        *b_Jet_NNeutrals;    
   TBranch        *b_Jet_Beta;    
   TBranch        *b_Jet_BetaStar;    
   TBranch        *b_Jet_MeanSqDeltaR;    
   TBranch        *b_Jet_PTD;    
   TBranch        *b_Jet_FracPt;    
   TBranch        *b_Jet_size;    
   TBranch        *b_Electron_;    
   TBranch        *b_Electron_fUniqueID;    
   TBranch        *b_Electron_fBits;    
   TBranch        *b_Electron_PT;    
   TBranch        *b_Electron_Eta;    
   TBranch        *b_Electron_Phi;    
   TBranch        *b_Electron_T;    
   TBranch        *b_Electron_Charge;    
   TBranch        *b_Electron_EhadOverEem;    
   TBranch        *b_Electron_Particle;    
   TBranch        *b_Electron_size;    
   TBranch        *b_Photon_;    
   TBranch        *b_Photon_fUniqueID;    
   TBranch        *b_Photon_fBits;    
   TBranch        *b_Photon_PT;    
   TBranch        *b_Photon_Eta;    
   TBranch        *b_Photon_Phi;    
   TBranch        *b_Photon_E;    
   TBranch        *b_Photon_T;    
   TBranch        *b_Photon_EhadOverEem;    
   TBranch        *b_Photon_Particles;    
   TBranch        *b_Photon_size;    
   TBranch        *b_Muon_;    
   TBranch        *b_Muon_fUniqueID;    
   TBranch        *b_Muon_fBits;    
   TBranch        *b_Muon_PT;    
   TBranch        *b_Muon_Eta;    
   TBranch        *b_Muon_Phi;    
   TBranch        *b_Muon_T;    
   TBranch        *b_Muon_Charge;    
   TBranch        *b_Muon_Particle;    
   TBranch        *b_Muon_size;    
   TBranch        *b_MissingET_;    
   TBranch        *b_MissingET_fUniqueID;    
   TBranch        *b_MissingET_fBits;    
   TBranch        *b_MissingET_MET;    
   TBranch        *b_MissingET_Eta;    
   TBranch        *b_MissingET_Phi;    
   TBranch        *b_MissingET_size;    
   TBranch        *b_ScalarHT_;    
   TBranch        *b_ScalarHT_fUniqueID;    
   TBranch        *b_ScalarHT_fBits;    
   TBranch        *b_ScalarHT_HT;    
   TBranch        *b_ScalarHT_size;    
   TBranch        *b_Rho_;    
   TBranch        *b_Rho_fUniqueID;    
   TBranch        *b_Rho_fBits;    
   TBranch        *b_Rho_Rho;    
   TBranch        *b_Rho_Edges;    
   TBranch        *b_Rho_size;    
   TBranch        *b_Vertex_;    
   TBranch        *b_Vertex_fUniqueID;    
   TBranch        *b_Vertex_fBits;    
   TBranch        *b_Vertex_T;    
   TBranch        *b_Vertex_X;    
   TBranch        *b_Vertex_Y;    
   TBranch        *b_Vertex_Z;    
   TBranch        *b_Vertex_size;    

   ExampleVBFHAnalysis(TTree *tree=0);
   virtual ~ExampleVBFHAnalysis();
   virtual Int_t    Cut();
   Int_t    GetEntry(Long64_t entry);
   Long64_t LoadTree(Long64_t entry);
   void     Init(TTree *tree);
   void     processEvents();
   Int_t    JetAnalysis();
   Int_t    MET();
   Int_t    MHT();
   void     end();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef ExampleVBFHAnalysis_cxx
ExampleVBFHAnalysis::ExampleVBFHAnalysis(TTree *tree) : fChain(0) 
{

   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("event_vbf_inv_8000_output.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("event_vbf_inv_8000_output.root");
      }
      f->GetObject("Delphes",tree);

   }
   Init(tree);
}

ExampleVBFHAnalysis::~ExampleVBFHAnalysis()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t ExampleVBFHAnalysis::GetEntry(Long64_t entry)
{

   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t ExampleVBFHAnalysis::LoadTree(Long64_t entry)
{

   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void ExampleVBFHAnalysis::Init(TTree *tree)
{

   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Event", &Event_, &b_Event_);
   fChain->SetBranchAddress("Event.fUniqueID", Event_fUniqueID, &b_Event_fUniqueID);
   fChain->SetBranchAddress("Event.fBits", Event_fBits, &b_Event_fBits);
   fChain->SetBranchAddress("Event.Number", Event_Number, &b_Event_Number);
   fChain->SetBranchAddress("Event.ReadTime", Event_ReadTime, &b_Event_ReadTime);
   fChain->SetBranchAddress("Event.ProcTime", Event_ProcTime, &b_Event_ProcTime);
   fChain->SetBranchAddress("Event.ProcessID", Event_ProcessID, &b_Event_ProcessID);
   fChain->SetBranchAddress("Event.Weight", Event_Weight, &b_Event_Weight);
   fChain->SetBranchAddress("Event.ScalePDF", Event_ScalePDF, &b_Event_ScalePDF);
   fChain->SetBranchAddress("Event.AlphaQED", Event_AlphaQED, &b_Event_AlphaQED);
   fChain->SetBranchAddress("Event.AlphaQCD", Event_AlphaQCD, &b_Event_AlphaQCD);
   fChain->SetBranchAddress("Event_size", &Event_size, &b_Event_size);
   fChain->SetBranchAddress("Rwgt", &Rwgt_, &b_Rwgt_);
   fChain->SetBranchAddress("Rwgt.fUniqueID", &Rwgt_fUniqueID, &b_Rwgt_fUniqueID);
   fChain->SetBranchAddress("Rwgt.fBits", &Rwgt_fBits, &b_Rwgt_fBits);
   fChain->SetBranchAddress("Rwgt.Weight", &Rwgt_Weight, &b_Rwgt_Weight);
   fChain->SetBranchAddress("Rwgt_size", &Rwgt_size, &b_Rwgt_size);
   fChain->SetBranchAddress("Particle", &Particle_, &b_Particle_);
   fChain->SetBranchAddress("Particle.fUniqueID", Particle_fUniqueID, &b_Particle_fUniqueID);
   fChain->SetBranchAddress("Particle.fBits", Particle_fBits, &b_Particle_fBits);
   fChain->SetBranchAddress("Particle.PID", Particle_PID, &b_Particle_PID);
   fChain->SetBranchAddress("Particle.Status", Particle_Status, &b_Particle_Status);
   fChain->SetBranchAddress("Particle.IsPU", Particle_IsPU, &b_Particle_IsPU);
   fChain->SetBranchAddress("Particle.M1", Particle_M1, &b_Particle_M1);
   fChain->SetBranchAddress("Particle.M2", Particle_M2, &b_Particle_M2);
   fChain->SetBranchAddress("Particle.D1", Particle_D1, &b_Particle_D1);
   fChain->SetBranchAddress("Particle.D2", Particle_D2, &b_Particle_D2);
   fChain->SetBranchAddress("Particle.Charge", Particle_Charge, &b_Particle_Charge);
   fChain->SetBranchAddress("Particle.Mass", Particle_Mass, &b_Particle_Mass);
   fChain->SetBranchAddress("Particle.E", Particle_E, &b_Particle_E);
   fChain->SetBranchAddress("Particle.Px", Particle_Px, &b_Particle_Px);
   fChain->SetBranchAddress("Particle.Py", Particle_Py, &b_Particle_Py);
   fChain->SetBranchAddress("Particle.Pz", Particle_Pz, &b_Particle_Pz);
   fChain->SetBranchAddress("Particle.PT", Particle_PT, &b_Particle_PT);
   fChain->SetBranchAddress("Particle.Eta", Particle_Eta, &b_Particle_Eta);
   fChain->SetBranchAddress("Particle.Phi", Particle_Phi, &b_Particle_Phi);
   fChain->SetBranchAddress("Particle.Rapidity", Particle_Rapidity, &b_Particle_Rapidity);
   fChain->SetBranchAddress("Particle.T", Particle_T, &b_Particle_T);
   fChain->SetBranchAddress("Particle.X", Particle_X, &b_Particle_X);
   fChain->SetBranchAddress("Particle.Y", Particle_Y, &b_Particle_Y);
   fChain->SetBranchAddress("Particle.Z", Particle_Z, &b_Particle_Z);
   fChain->SetBranchAddress("Particle_size", &Particle_size, &b_Particle_size);
   fChain->SetBranchAddress("Track", &Track_, &b_Track_);
   fChain->SetBranchAddress("Track.fUniqueID", Track_fUniqueID, &b_Track_fUniqueID);
   fChain->SetBranchAddress("Track.fBits", Track_fBits, &b_Track_fBits);
   fChain->SetBranchAddress("Track.PID", Track_PID, &b_Track_PID);
   fChain->SetBranchAddress("Track.Charge", Track_Charge, &b_Track_Charge);
   fChain->SetBranchAddress("Track.PT", Track_PT, &b_Track_PT);
   fChain->SetBranchAddress("Track.Eta", Track_Eta, &b_Track_Eta);
   fChain->SetBranchAddress("Track.Phi", Track_Phi, &b_Track_Phi);
   fChain->SetBranchAddress("Track.EtaOuter", Track_EtaOuter, &b_Track_EtaOuter);
   fChain->SetBranchAddress("Track.PhiOuter", Track_PhiOuter, &b_Track_PhiOuter);
   fChain->SetBranchAddress("Track.X", Track_X, &b_Track_X);
   fChain->SetBranchAddress("Track.Y", Track_Y, &b_Track_Y);
   fChain->SetBranchAddress("Track.Z", Track_Z, &b_Track_Z);
   fChain->SetBranchAddress("Track.T", Track_T, &b_Track_T);
   fChain->SetBranchAddress("Track.XOuter", Track_XOuter, &b_Track_XOuter);
   fChain->SetBranchAddress("Track.YOuter", Track_YOuter, &b_Track_YOuter);
   fChain->SetBranchAddress("Track.ZOuter", Track_ZOuter, &b_Track_ZOuter);
   fChain->SetBranchAddress("Track.TOuter", Track_TOuter, &b_Track_TOuter);
   fChain->SetBranchAddress("Track.Particle", Track_Particle, &b_Track_Particle);
   fChain->SetBranchAddress("Track_size", &Track_size, &b_Track_size);
   fChain->SetBranchAddress("Tower", &Tower_, &b_Tower_);
   fChain->SetBranchAddress("Tower.fUniqueID", Tower_fUniqueID, &b_Tower_fUniqueID);
   fChain->SetBranchAddress("Tower.fBits", Tower_fBits, &b_Tower_fBits);
   fChain->SetBranchAddress("Tower.ET", Tower_ET, &b_Tower_ET);
   fChain->SetBranchAddress("Tower.Eta", Tower_Eta, &b_Tower_Eta);
   fChain->SetBranchAddress("Tower.Phi", Tower_Phi, &b_Tower_Phi);
   fChain->SetBranchAddress("Tower.E", Tower_E, &b_Tower_E);
   fChain->SetBranchAddress("Tower.T", Tower_T, &b_Tower_T);
   fChain->SetBranchAddress("Tower.Eem", Tower_Eem, &b_Tower_Eem);
   fChain->SetBranchAddress("Tower.Ehad", Tower_Ehad, &b_Tower_Ehad);
   fChain->SetBranchAddress("Tower.Edges[4]", Tower_Edges, &b_Tower_Edges);
   fChain->SetBranchAddress("Tower.Particles", Tower_Particles, &b_Tower_Particles);
   fChain->SetBranchAddress("Tower_size", &Tower_size, &b_Tower_size);
   fChain->SetBranchAddress("EFlowTrack", &EFlowTrack_, &b_EFlowTrack_);
   fChain->SetBranchAddress("EFlowTrack.fUniqueID", EFlowTrack_fUniqueID, &b_EFlowTrack_fUniqueID);
   fChain->SetBranchAddress("EFlowTrack.fBits", EFlowTrack_fBits, &b_EFlowTrack_fBits);
   fChain->SetBranchAddress("EFlowTrack.PID", EFlowTrack_PID, &b_EFlowTrack_PID);
   fChain->SetBranchAddress("EFlowTrack.Charge", EFlowTrack_Charge, &b_EFlowTrack_Charge);
   fChain->SetBranchAddress("EFlowTrack.PT", EFlowTrack_PT, &b_EFlowTrack_PT);
   fChain->SetBranchAddress("EFlowTrack.Eta", EFlowTrack_Eta, &b_EFlowTrack_Eta);
   fChain->SetBranchAddress("EFlowTrack.Phi", EFlowTrack_Phi, &b_EFlowTrack_Phi);
   fChain->SetBranchAddress("EFlowTrack.EtaOuter", EFlowTrack_EtaOuter, &b_EFlowTrack_EtaOuter);
   fChain->SetBranchAddress("EFlowTrack.PhiOuter", EFlowTrack_PhiOuter, &b_EFlowTrack_PhiOuter);
   fChain->SetBranchAddress("EFlowTrack.X", EFlowTrack_X, &b_EFlowTrack_X);
   fChain->SetBranchAddress("EFlowTrack.Y", EFlowTrack_Y, &b_EFlowTrack_Y);
   fChain->SetBranchAddress("EFlowTrack.Z", EFlowTrack_Z, &b_EFlowTrack_Z);
   fChain->SetBranchAddress("EFlowTrack.T", EFlowTrack_T, &b_EFlowTrack_T);
   fChain->SetBranchAddress("EFlowTrack.XOuter", EFlowTrack_XOuter, &b_EFlowTrack_XOuter);
   fChain->SetBranchAddress("EFlowTrack.YOuter", EFlowTrack_YOuter, &b_EFlowTrack_YOuter);
   fChain->SetBranchAddress("EFlowTrack.ZOuter", EFlowTrack_ZOuter, &b_EFlowTrack_ZOuter);
   fChain->SetBranchAddress("EFlowTrack.TOuter", EFlowTrack_TOuter, &b_EFlowTrack_TOuter);
   fChain->SetBranchAddress("EFlowTrack.Particle", EFlowTrack_Particle, &b_EFlowTrack_Particle);
   fChain->SetBranchAddress("EFlowTrack_size", &EFlowTrack_size, &b_EFlowTrack_size);
   fChain->SetBranchAddress("EFlowTower", &EFlowTower_, &b_EFlowTower_);
   fChain->SetBranchAddress("EFlowTower.fUniqueID", EFlowTower_fUniqueID, &b_EFlowTower_fUniqueID);
   fChain->SetBranchAddress("EFlowTower.fBits", EFlowTower_fBits, &b_EFlowTower_fBits);
   fChain->SetBranchAddress("EFlowTower.ET", EFlowTower_ET, &b_EFlowTower_ET);
   fChain->SetBranchAddress("EFlowTower.Eta", EFlowTower_Eta, &b_EFlowTower_Eta);
   fChain->SetBranchAddress("EFlowTower.Phi", EFlowTower_Phi, &b_EFlowTower_Phi);
   fChain->SetBranchAddress("EFlowTower.E", EFlowTower_E, &b_EFlowTower_E);
   fChain->SetBranchAddress("EFlowTower.T", EFlowTower_T, &b_EFlowTower_T);
   fChain->SetBranchAddress("EFlowTower.Eem", EFlowTower_Eem, &b_EFlowTower_Eem);
   fChain->SetBranchAddress("EFlowTower.Ehad", EFlowTower_Ehad, &b_EFlowTower_Ehad);
   fChain->SetBranchAddress("EFlowTower.Edges[4]", EFlowTower_Edges, &b_EFlowTower_Edges);
   fChain->SetBranchAddress("EFlowTower.Particles", EFlowTower_Particles, &b_EFlowTower_Particles);
   fChain->SetBranchAddress("EFlowTower_size", &EFlowTower_size, &b_EFlowTower_size);
   fChain->SetBranchAddress("GenJet", &GenJet_, &b_GenJet_);
   fChain->SetBranchAddress("GenJet.fUniqueID", GenJet_fUniqueID, &b_GenJet_fUniqueID);
   fChain->SetBranchAddress("GenJet.fBits", GenJet_fBits, &b_GenJet_fBits);
   fChain->SetBranchAddress("GenJet.PT", GenJet_PT, &b_GenJet_PT);
   fChain->SetBranchAddress("GenJet.Eta", GenJet_Eta, &b_GenJet_Eta);
   fChain->SetBranchAddress("GenJet.Phi", GenJet_Phi, &b_GenJet_Phi);
   fChain->SetBranchAddress("GenJet.T", GenJet_T, &b_GenJet_T);
   fChain->SetBranchAddress("GenJet.Mass", GenJet_Mass, &b_GenJet_Mass);
   fChain->SetBranchAddress("GenJet.DeltaEta", GenJet_DeltaEta, &b_GenJet_DeltaEta);
   fChain->SetBranchAddress("GenJet.DeltaPhi", GenJet_DeltaPhi, &b_GenJet_DeltaPhi);
   fChain->SetBranchAddress("GenJet.BTag", GenJet_BTag, &b_GenJet_BTag);
   fChain->SetBranchAddress("GenJet.TauTag", GenJet_TauTag, &b_GenJet_TauTag);
   fChain->SetBranchAddress("GenJet.Charge", GenJet_Charge, &b_GenJet_Charge);
   fChain->SetBranchAddress("GenJet.EhadOverEem", GenJet_EhadOverEem, &b_GenJet_EhadOverEem);
   fChain->SetBranchAddress("GenJet.Constituents", GenJet_Constituents, &b_GenJet_Constituents);
   fChain->SetBranchAddress("GenJet.Particles", GenJet_Particles, &b_GenJet_Particles);
   fChain->SetBranchAddress("GenJet.NCharged", GenJet_NCharged, &b_GenJet_NCharged);
   fChain->SetBranchAddress("GenJet.NNeutrals", GenJet_NNeutrals, &b_GenJet_NNeutrals);
   fChain->SetBranchAddress("GenJet.Beta", GenJet_Beta, &b_GenJet_Beta);
   fChain->SetBranchAddress("GenJet.BetaStar", GenJet_BetaStar, &b_GenJet_BetaStar);
   fChain->SetBranchAddress("GenJet.MeanSqDeltaR", GenJet_MeanSqDeltaR, &b_GenJet_MeanSqDeltaR);
   fChain->SetBranchAddress("GenJet.PTD", GenJet_PTD, &b_GenJet_PTD);
   fChain->SetBranchAddress("GenJet.FracPt[5]", GenJet_FracPt, &b_GenJet_FracPt);
   fChain->SetBranchAddress("GenJet_size", &GenJet_size, &b_GenJet_size);
   fChain->SetBranchAddress("Jet", &Jet_, &b_Jet_);
   fChain->SetBranchAddress("Jet.fUniqueID", Jet_fUniqueID, &b_Jet_fUniqueID);
   fChain->SetBranchAddress("Jet.fBits", Jet_fBits, &b_Jet_fBits);
   fChain->SetBranchAddress("Jet.PT", Jet_PT, &b_Jet_PT);
   fChain->SetBranchAddress("Jet.Eta", Jet_Eta, &b_Jet_Eta);
   fChain->SetBranchAddress("Jet.Phi", Jet_Phi, &b_Jet_Phi);
   fChain->SetBranchAddress("Jet.T", Jet_T, &b_Jet_T);
   fChain->SetBranchAddress("Jet.Mass", Jet_Mass, &b_Jet_Mass);
   fChain->SetBranchAddress("Jet.DeltaEta", Jet_DeltaEta, &b_Jet_DeltaEta);
   fChain->SetBranchAddress("Jet.DeltaPhi", Jet_DeltaPhi, &b_Jet_DeltaPhi);
   fChain->SetBranchAddress("Jet.BTag", Jet_BTag, &b_Jet_BTag);
   fChain->SetBranchAddress("Jet.TauTag", Jet_TauTag, &b_Jet_TauTag);
   fChain->SetBranchAddress("Jet.Charge", Jet_Charge, &b_Jet_Charge);
   fChain->SetBranchAddress("Jet.EhadOverEem", Jet_EhadOverEem, &b_Jet_EhadOverEem);
   fChain->SetBranchAddress("Jet.Constituents", Jet_Constituents, &b_Jet_Constituents);
   fChain->SetBranchAddress("Jet.Particles", Jet_Particles, &b_Jet_Particles);
   fChain->SetBranchAddress("Jet.NCharged", Jet_NCharged, &b_Jet_NCharged);
   fChain->SetBranchAddress("Jet.NNeutrals", Jet_NNeutrals, &b_Jet_NNeutrals);
   fChain->SetBranchAddress("Jet.Beta", Jet_Beta, &b_Jet_Beta);
   fChain->SetBranchAddress("Jet.BetaStar", Jet_BetaStar, &b_Jet_BetaStar);
   fChain->SetBranchAddress("Jet.MeanSqDeltaR", Jet_MeanSqDeltaR, &b_Jet_MeanSqDeltaR);
   fChain->SetBranchAddress("Jet.PTD", Jet_PTD, &b_Jet_PTD);
   fChain->SetBranchAddress("Jet.FracPt[5]", Jet_FracPt, &b_Jet_FracPt);
   fChain->SetBranchAddress("Jet_size", &Jet_size, &b_Jet_size);
   fChain->SetBranchAddress("Electron", &Electron_, &b_Electron_);
   fChain->SetBranchAddress("Electron.fUniqueID", &Electron_fUniqueID, &b_Electron_fUniqueID);
   fChain->SetBranchAddress("Electron.fBits", &Electron_fBits, &b_Electron_fBits);
   fChain->SetBranchAddress("Electron.PT", &Electron_PT, &b_Electron_PT);
   fChain->SetBranchAddress("Electron.Eta", &Electron_Eta, &b_Electron_Eta);
   fChain->SetBranchAddress("Electron.Phi", &Electron_Phi, &b_Electron_Phi);
   fChain->SetBranchAddress("Electron.T", &Electron_T, &b_Electron_T);
   fChain->SetBranchAddress("Electron.Charge", &Electron_Charge, &b_Electron_Charge);
   fChain->SetBranchAddress("Electron.EhadOverEem", &Electron_EhadOverEem, &b_Electron_EhadOverEem);
   fChain->SetBranchAddress("Electron.Particle", &Electron_Particle, &b_Electron_Particle);
   fChain->SetBranchAddress("Electron_size", &Electron_size, &b_Electron_size);
   fChain->SetBranchAddress("Photon", &Photon_, &b_Photon_);
   fChain->SetBranchAddress("Photon.fUniqueID", Photon_fUniqueID, &b_Photon_fUniqueID);
   fChain->SetBranchAddress("Photon.fBits", Photon_fBits, &b_Photon_fBits);
   fChain->SetBranchAddress("Photon.PT", Photon_PT, &b_Photon_PT);
   fChain->SetBranchAddress("Photon.Eta", Photon_Eta, &b_Photon_Eta);
   fChain->SetBranchAddress("Photon.Phi", Photon_Phi, &b_Photon_Phi);
   fChain->SetBranchAddress("Photon.E", Photon_E, &b_Photon_E);
   fChain->SetBranchAddress("Photon.T", Photon_T, &b_Photon_T);
   fChain->SetBranchAddress("Photon.EhadOverEem", Photon_EhadOverEem, &b_Photon_EhadOverEem);
   fChain->SetBranchAddress("Photon.Particles", Photon_Particles, &b_Photon_Particles);
   fChain->SetBranchAddress("Photon_size", &Photon_size, &b_Photon_size);
   fChain->SetBranchAddress("Muon", &Muon_, &b_Muon_);
   fChain->SetBranchAddress("Muon.fUniqueID", &Muon_fUniqueID, &b_Muon_fUniqueID);
   fChain->SetBranchAddress("Muon.fBits", &Muon_fBits, &b_Muon_fBits);
   fChain->SetBranchAddress("Muon.PT", &Muon_PT, &b_Muon_PT);
   fChain->SetBranchAddress("Muon.Eta", &Muon_Eta, &b_Muon_Eta);
   fChain->SetBranchAddress("Muon.Phi", &Muon_Phi, &b_Muon_Phi);
   fChain->SetBranchAddress("Muon.T", &Muon_T, &b_Muon_T);
   fChain->SetBranchAddress("Muon.Charge", &Muon_Charge, &b_Muon_Charge);
   fChain->SetBranchAddress("Muon.Particle", &Muon_Particle, &b_Muon_Particle);
   fChain->SetBranchAddress("Muon_size", &Muon_size, &b_Muon_size);
   fChain->SetBranchAddress("MissingET", &MissingET_, &b_MissingET_);
   fChain->SetBranchAddress("MissingET.fUniqueID", MissingET_fUniqueID, &b_MissingET_fUniqueID);
   fChain->SetBranchAddress("MissingET.fBits", MissingET_fBits, &b_MissingET_fBits);
   fChain->SetBranchAddress("MissingET.MET", MissingET_MET, &b_MissingET_MET);
   fChain->SetBranchAddress("MissingET.Eta", MissingET_Eta, &b_MissingET_Eta);
   fChain->SetBranchAddress("MissingET.Phi", MissingET_Phi, &b_MissingET_Phi);
   fChain->SetBranchAddress("MissingET_size", &MissingET_size, &b_MissingET_size);
   fChain->SetBranchAddress("ScalarHT", &ScalarHT_, &b_ScalarHT_);
   fChain->SetBranchAddress("ScalarHT.fUniqueID", ScalarHT_fUniqueID, &b_ScalarHT_fUniqueID);
   fChain->SetBranchAddress("ScalarHT.fBits", ScalarHT_fBits, &b_ScalarHT_fBits);
   fChain->SetBranchAddress("ScalarHT.HT", ScalarHT_HT, &b_ScalarHT_HT);
   fChain->SetBranchAddress("ScalarHT_size", &ScalarHT_size, &b_ScalarHT_size);
   fChain->SetBranchAddress("Rho", &Rho_, &b_Rho_);
   fChain->SetBranchAddress("Rho.fUniqueID", Rho_fUniqueID, &b_Rho_fUniqueID);
   fChain->SetBranchAddress("Rho.fBits", Rho_fBits, &b_Rho_fBits);
   fChain->SetBranchAddress("Rho.Rho", Rho_Rho, &b_Rho_Rho);
   fChain->SetBranchAddress("Rho.Edges[2]", Rho_Edges, &b_Rho_Edges);
   fChain->SetBranchAddress("Rho_size", &Rho_size, &b_Rho_size);
   fChain->SetBranchAddress("Vertex", &Vertex_, &b_Vertex_);
   fChain->SetBranchAddress("Vertex.fUniqueID", Vertex_fUniqueID, &b_Vertex_fUniqueID);
   fChain->SetBranchAddress("Vertex.fBits", Vertex_fBits, &b_Vertex_fBits);
   fChain->SetBranchAddress("Vertex.T", Vertex_T, &b_Vertex_T);
   fChain->SetBranchAddress("Vertex.X", Vertex_X, &b_Vertex_X);
   fChain->SetBranchAddress("Vertex.Y", Vertex_Y, &b_Vertex_Y);
   fChain->SetBranchAddress("Vertex.Z", Vertex_Z, &b_Vertex_Z);
   fChain->SetBranchAddress("Vertex_size", &Vertex_size, &b_Vertex_size);
   Notify();
}

Bool_t ExampleVBFHAnalysis::Notify()
{
   return kTRUE;
}

void ExampleVBFHAnalysis::Show(Long64_t entry)
{
   if (!fChain) return;
   fChain->Show(entry);
   }
Int_t ExampleVBFHAnalysis::Cut()
{
   return 1;
}
#endif

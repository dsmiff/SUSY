void VBF_invH_analysis()
{

  gROOT->Reset();
  
  TString dirname = ".";
  TString rootname = "VBF_invH_8000_output.root";
  
  rootname = dirname + "/" + rootname;
  
  TFile *rootfile = new TFile(rootname);
  std::cout << "Rootfile : " << rootname << std::endl;

  TString styles = "1stJetPT,2ndJetPT,JetEta,JetPhi,HT,1stJetMass,2ndJetMass,NJets";
  TObjArray* tokens = styles.Tokenize(",");
  int n = tokens->GetEntries();
  TCanvas c1("c1","draw styles",0,0,1000, 800);
  TCanvas ci_1("ci_1","draw shit",0,0,1000, 800);
  c1.Divide( 4, TMath::Nint(n/4.));
 
  for(int i=0; i<n; i++)
    {
  TString style = ((TObjString*) tokens->At(i))->String();
  std::cout << "Style " << style << std::endl;
  TH1F *hi = (TH1F*)rootfile->Get(style);


  ci_1.cd();
  hi->Draw();
  ci_1.SaveAs((const Char_t*) (style + ".pdf"));

  c1.cd(i+1);
  hi->Draw();
    }	   
  
  c1.cd();
  c1.SaveAs("histDraws.pdf");


      

  

}

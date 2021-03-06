// Author: Dominic Smith 
// Date: April 2014
// University of Bristol/ Vrije Universitait Brussel
// 
// Description: 
// ROOT script to plot several histograms on a single and multiple pdfs/ps.
// Requires a ROOT TFile with the correct histo titles.
// User can choose what style to plot histos with



void T1t1t_analysis()
{

  gROOT->Reset();
  
  TString dirname = ".";
  TString rootname = "../T1t1t_output.root";
  
  rootname = dirname + "/" + rootname;
  
  TFile *rootfile = new TFile(rootname);
  std::cout << "Rootfile : " << rootname << std::endl;

  // For TH2D histograms
  TString plots2 = "DeltaR1,DeltaR2,DeltaR3,DeltaR4";
  TObjArray* tokens1 = plots2.Tokenize(",");
  int n1 = tokens1->GetEntries();
  
  // For TH1D histograms
  TString plots = "JetPT,1stJetPT,2ndJetPT,JetEta,1stJetMass,2ndJetMass,HT,NJets,TopPT,StopPT,LSPPT";
  TObjArray* tokens = plots.Tokenize(",");
  int n = tokens->GetEntries();

  // Canvas initialising 
  TCanvas c1("c1","draw plots",0,0,1000, 800);
  TCanvas ci_1("ci_1","draw separately",0,0,1000, 800);
  TCanvas c2("c2","draw together", 0, 0, 1000, 800);
  c1.Divide( 4, TMath::Nint(n/3.));

  // Histo style initialising 
  TString styles = "hist,E,l,CONTZ";
  TObjArray* styletokens = styles.Tokenize(",");
  int m = styletokens->GetEntries();
  //  TString style = ((TObjString*) styletokens->At(0))->String();

  // Plot TH2D histos

  for(int i=0; i<n1; i++)
    {
      TString style = ((TObjString*) styletokens->At(3))->String();
      TString plot1 = ((TObjString*) tokens1->At(i))->String();

      std::cout << "Plot " << plot1 << std::endl;
      TH2F *h2i = (TH2F*)rootfile->Get(plot1);

      ci_1.cd();
      h2i->Draw(style);
      h2i->GetXaxis()->SetTitle((const Char_t*) (plot1));
      h2i->GetYaxis()->SetTitle("Events");
      ci_1.SaveAs((const Char_t*) (plot1 + ".pdf"));

      c1.cd(i+1);
      h2i->Draw(style);
      
      c2.cd();
      h2i->Draw(style);
      c2.Print("histos.pdf(");

    }
  

  c1.cd();
  c1.SaveAs("histDraws.ps");

  // Plot TH1D histos

  for(int i=0; i<n; i++)
    {

      TString style = ((TObjString*) styletokens->At(0))->String();
      TString plot = ((TObjString*) tokens->At(i))->String();

      std::cout << "Plot " << plot << std::endl;
      TH1F *hi = (TH1F*)rootfile->Get(plot);

      ci_1.cd();
      hi->Draw(style);
      hi->Scale(1/hi->GetEntries());
      hi->GetXaxis()->SetTitle((const Char_t*) (plot));
      hi->GetYaxis()->SetTitle("Events");
      ci_1.SaveAs((const Char_t*) (plot + ".pdf"));

      c1.cd(i+1);
      hi->Draw(style);


      c2.cd();
      hi->Draw(style);
      c2.Print("histos.pdf(");

    }	   

  c2.Print("histos.pdf)");
  c1.cd();
  c1.SaveAs("histDraws.ps");

}

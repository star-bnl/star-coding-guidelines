#include <iostream>
#include <memory>
#include "TH1F.h"
#include "TFile.h"

using namespace std;

int main()
{
  TFile f("out.root","recreate");
  f.cd();
  unique_ptr<TH1F> h {new TH1F("h","h",100,-5,5)};
  h->FillRandom("gaus",10000);
  h->Write();
  f.Close();
  
  return 0;
}

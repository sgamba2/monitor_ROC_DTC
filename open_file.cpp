#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include<bits/stdc++.h>
using namespace std;

void open_file(){
   ifstream in("mu2edaq09_dtc1_run_066.dat", std::ios::binary );
    if(!in) {
      cout << "Cannot open file!" << endl;
      return;
   }
    // Verifica se il file è stato aperto correttamente
    if (!in.is_open()) {
        cerr << "impossible to open the file!" << endl;
        return;
    }
 
    TH1F* Hist_dtc_event_size = new TH1F("Hist_dtc_event_size","Hist_dtc_event_size", 70, 0.,70.);
    TH1F* Hist_line_number_dtc = new TH1F("Hist_line_number_dtc","Hist_line_number_dtc", 2000, 0.,2000.);
    TH1F* Hist_num_events = new TH1F("num_events","num_events", 70, 0.,70.);
    TH2F* Hist_dtc_event_size_vs_line_number_dtc = new TH2F("Hist_dtc_event_size_vs_line_number_dtc","Hist_dtc_event_size_vs_line_number_dtc", 70, 0.,70.,2000, 0.,2000.);
    TH1F* Hist_line_number_roc = new TH1F("Hist_line_number_roc","Hist_line_number_roc", 2000, 0.,2000.);
    TH1F* Hist_roc_size = new TH1F("Hist_roc_size","Hist_roc_size", 70, 0.,70.);
    TH1F* Hist_NUM_ROCS = new TH1F("Hist_NUM_ROCS","Hist_NUM_ROCS", 70, 0.,70.);
    TH2F* Hist_roc_size_vs_line_number_roc = new TH2F("Hist_roc_size_vs_line_number_roc","Hist_roc_size_vs_line_number_roc", 70, 0.,70.,2000, 0.,2000.);
    TH2F* Hist_dtc_size_vs_roc_size = new TH2F("Hist_dtc_size_vs_roc_size","Hist_dtc_size_vs_roc_size",70, 0.,70.,70, 0.,70.);

int k=0;
unsigned char lo;
int loc     = 0;
unsigned char hi;
int num_events=0;
int dtc_size=-1;
int lines_count=0;
int line_number_dtc=0;
int roc_size=-1;
int line_number_roc=0;
int num_roc=0;
int NUM_ROC=0;
while(!in.eof()){
    //for (int i=0; i<2016; i++) {
    if (loc == 0){
       printf(" 0x%08x: ",k*2);
       lines_count++;
    }
    in.read(reinterpret_cast<char*>(&lo), 1); 
    in.read(reinterpret_cast<char*>(&hi), 1);
    int size = (hi << 8) | lo;
    printf("0x%04x ",size);

    if(loc==0 & dtc_size==-1){
        dtc_size=size>>4;
        line_number_dtc=lines_count;
        num_events++;
        Hist_dtc_event_size->Fill(dtc_size);
        Hist_line_number_dtc->Fill(line_number_dtc);
        Hist_dtc_event_size_vs_line_number_dtc->Fill(dtc_size,line_number_dtc);
    }
    if(loc==0 & roc_size==-1 & lines_count>line_number_dtc+2){
        roc_size=size>>4;
        line_number_roc=lines_count;
        num_roc++;
        NUM_ROC++;
        Hist_roc_size->Fill(roc_size);
        Hist_line_number_roc->Fill(line_number_roc);
        Hist_roc_size_vs_line_number_roc->Fill(roc_size,line_number_roc);
        Hist_dtc_size_vs_roc_size->Fill(dtc_size,roc_size);

    }
    loc += 1;
    if (loc == 8) {
        printf("\n");
        loc  = 0;
    }
    if((line_number_dtc+dtc_size-1)==lines_count){
        dtc_size=-1;
        Hist_NUM_ROCS->Fill(NUM_ROC);
        NUM_ROC=0;
    }
    if((line_number_roc+roc_size-1)==lines_count){
        roc_size=-1;
    }
    k++;

}
printf("\n");
printf("TOTAL NUMBER OF LINES %d\n",lines_count);
printf("TOTAL NUMBER OF EVENTS %d\n",num_events);
printf("TOTAL NUMBER OF ROCS %d\n",num_roc);

TCanvas * c3 = new TCanvas("c3", "c3");
Hist_num_events->Fill((double)num_events);
Hist_num_events->Draw();
TCanvas * c1 = new TCanvas("c1", "c1");
Hist_dtc_event_size->Draw();
TCanvas * c2 = new TCanvas("c2", "c2");
Hist_line_number_dtc->Draw();
//}
TCanvas * c4 = new TCanvas("c4", "c4");
Hist_dtc_event_size_vs_line_number_dtc->Draw("P");
TCanvas * c5 = new TCanvas("c5", "c5");
Hist_roc_size->Draw();
TCanvas * c6 = new TCanvas("c6", "c6");
Hist_line_number_roc->Draw();
TCanvas * c7 = new TCanvas("c7", "c7");
Hist_NUM_ROCS->Draw();
TCanvas * c8 = new TCanvas("c8", "c8");
Hist_roc_size_vs_line_number_roc->Draw();
TCanvas * c9 = new TCanvas("c9", "c9");
Hist_dtc_size_vs_roc_size->Draw();
  // Check for errors during reading
  if (in.bad()) {
    std::cerr << "Error reading from file" << std::endl;
  }
  in.close(); // Close the file

    return;
}



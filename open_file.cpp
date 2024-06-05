#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include<bits/stdc++.h>
using namespace std;


void process_files(string filename,int daq){
   ifstream in(filename, std::ios::binary );
    if(!in) {
      cout << "Cannot open file!" << endl;
      return;
   }
    // Verifica se il file è stato aperto correttamente
    if (!in.is_open()) {
        cerr << "impossible to open the file!" << endl;
        return;
    }
    
    TH1F* Hist_dtc_event_size = new TH1F(Form("Hist_dtc_event_size_%d",daq),Form("Hist_dtc_event_size_%d",daq), 70, 0.,70.);
    TH1F* Hist_dtc_tag = new TH1F(Form("Hist_dtc_tag_%d",daq),Form("Hist_dtc_tag_%d",daq), 70, 0.,70.);
    TH1F* Hist_residual_dtc_size = new TH1F(Form("Hist_residual_dtc_size_%d",daq),Form("Hist_residual_dtc_size_%d",daq), 70, 0.,70.);
    TH2F* Hist_event_vs_dtc_size = new TH2F(Form("Hist_event_vs_dtc_size_%d",daq),Form("Hist_event_vs_dtc_size_%d",daq), 70, 0.,70.,70, 0.,70.);
    TH2F* Hist_event_vs_dtc_tag = new TH2F(Form("Hist_event_vs_dtc_tag_%d",daq),Form("Hist_event_vs_dtc_tag_%d",daq), 70, 0.,70.,70, 0.,70.);
    TH2F* Hist_event_vs_roc_size = new TH2F(Form("Hist_event_vs_roc_size_%d",daq),Form("Hist_event_vs_roc_size_%d",daq), 500, 0.,500.,70, 0.,70.);
    TH2F* Hist_event_vs_roc_status = new TH2F(Form("Hist_event_vs_roc_status_%d",daq),Form("Hist_event_vs_roc_status_%d",daq), 500, 0.,500.,400, 0.,400.);
    TH2F* Hist_roc_size_vs_roc_status = new TH2F(Form("Hist_roc_size_vs_roc_status_%d",daq),Form("Hist_roc_size_vs_roc_status_%d",daq), 70, 0.,70.,400, 0.,400.);
    TH1F* Hist_line_number_dtc = new TH1F(Form("Hist_line_number_dtc_%d",daq),Form("Hist_line_number_dtc_%d",daq), 2000, 0.,2000.);
    TH1F* Hist_num_events = new TH1F(Form("Hist_num_events_%d",daq),Form("Hist_num_events_%d",daq), 70, 0.,70.);
    TH2F* Hist_dtc_event_size_vs_line_number_dtc = new TH2F(Form("Hist_dtc_event_size_vs_line_number_dtc_%d",daq),Form("Hist_dtc_event_size_vs_line_number_dtc_%d",daq), 70, 0.,70.,2000, 0.,2000.);
    TH1F* Hist_line_number_roc = new TH1F(Form("Hist_line_number_roc_%d",daq),Form("Hist_line_number_roc_%d",daq), 2000, 0.,2000.);
    TH1F* Hist_roc_size = new TH1F(Form("Hist_roc_size_%d",daq),Form("Hist_roc_size_%d",daq), 70, 0.,70.);
    TH1F* Hist_NUM_ROCS = new TH1F(Form("Hist_NUM_ROCS_%d",daq),Form("Hist_NUM_ROCS_%d",daq), 70, 0.,70.);
    TH2F* Hist_roc_size_vs_line_number_roc = new TH2F(Form("Hist_roc_size_vs_line_number_roc_%d",daq),Form("Hist_roc_size_vs_line_number_roc_%d",daq), 70, 0.,70.,2000, 0.,2000.);
    TH2F* Hist_dtc_size_vs_roc_size = new TH2F(Form("Hist_dtc_size_vs_roc_size_%d",daq),Form("Hist_dtc_size_vs_roc_size_%d",daq),70, 0.,70.,70, 0.,70.);

int k=0;
unsigned char lo;
int loc = 0;
unsigned char hi;
int num_events=0;
int dtc_size=-1;
vector<int> dtc_size_vec;
vector<int> dtc_tag_vec;
vector<int> roc_size_vec;
vector<float> roc_status_vec;

int lines_count=0;
int line_number_dtc=0;
int roc_size=-1;
int line_number_roc=0;
int num_roc=0;
int NUM_ROC=0;
int val=0;
int tot_dtc_size=0;
int tot_roc_size=0;
int val_status=0;
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
        dtc_size_vec.push_back(dtc_size);
        tot_dtc_size+=dtc_size;
        line_number_dtc=lines_count;
        num_events++;
        Hist_dtc_event_size->Fill(dtc_size);
        Hist_line_number_dtc->Fill(line_number_dtc);
        Hist_dtc_event_size_vs_line_number_dtc->Fill(dtc_size,line_number_dtc);
        val=1;
    }
    if(loc==2 and val==1){
        dtc_tag_vec.push_back(size);
        Hist_dtc_tag->Fill(size);
        val=0;
    }
    if(loc==0 & roc_size==-1 & lines_count>line_number_dtc+2){
        roc_size=size>>4;
        val_status=1;
        tot_roc_size+=roc_size;
        roc_size_vec.push_back(roc_size);
        line_number_roc=lines_count;
        num_roc++;
        NUM_ROC++;
        Hist_roc_size->Fill(roc_size);
        Hist_line_number_roc->Fill(line_number_roc);
        Hist_roc_size_vs_line_number_roc->Fill(roc_size,line_number_roc);
        Hist_dtc_size_vs_roc_size->Fill(dtc_size,roc_size);
    }
    if(loc==6 & val_status==1){
        roc_status_vec.push_back(size/4.);
        val_status=0;
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
 
  //  if(dtc_size==){
    //    Hist_line_number_vs_error_code->Fill(line_number_dtc,error_code_dtc);
    //}
    k++;
}
printf("\n");
printf("TOTAL NUMBER OF LINES %d\n",lines_count);
printf("TOTAL NUMBER OF EVENTS %d\n",num_events);
printf("TOTAL NUMBER OF ROCS %d\n",num_roc);

TCanvas * c3 = new TCanvas(Form("c3_%d",daq), Form("c3_%d",daq));
Hist_num_events->Fill((double)num_events);
Hist_num_events->Draw();
TCanvas * c1 = new TCanvas(Form("c1_%d",daq), Form("c1_%d",daq));
Hist_dtc_event_size->Draw();
TCanvas * c2 = new TCanvas(Form("c2_%d",daq), Form("c2_%d",daq));
Hist_line_number_dtc->Draw();
//}
TCanvas * c4 = new TCanvas(Form("c4_%d",daq), Form("c4_%d",daq));
Hist_dtc_event_size_vs_line_number_dtc->Draw("BOX");
TCanvas * c5 = new TCanvas(Form("c5_%d",daq), Form("c5_%d",daq));
Hist_roc_size->Draw();
TCanvas * c6 = new TCanvas(Form("c6_%d",daq), Form("c6_%d",daq));
Hist_line_number_roc->Draw();
TCanvas * c7 = new TCanvas(Form("c7_%d",daq), Form("c7_%d",daq));
Hist_NUM_ROCS->Draw();
TCanvas * c8 = new TCanvas(Form("c8_%d",daq), Form("c8_%d",daq));
Hist_roc_size_vs_line_number_roc->Draw("BOX");
TCanvas * c9 = new TCanvas(Form("c9_%d",daq), Form("c9_%d",daq));
Hist_dtc_size_vs_roc_size->Draw("BOX");
TCanvas * c10 = new TCanvas(Form("c10_%d",daq), Form("c10_%d",daq));
Hist_dtc_tag->Draw();
TCanvas * c11 = new TCanvas(Form("c11_%d",daq), Form("c11_%d",daq));
tot_dtc_size/=66;
tot_roc_size/=(66*6);

for(int i=0;i<66;i++){
    Hist_residual_dtc_size->Fill(dtc_size_vec.at(i)-tot_dtc_size);
    Hist_event_vs_dtc_size->Fill(i,dtc_size_vec.at(i)-tot_dtc_size);
    Hist_event_vs_dtc_tag->Fill(i,dtc_tag_vec.at(i));
}
for(int i=0;i<66*6;i++){
   Hist_event_vs_roc_size->Fill(i,roc_size_vec.at(i));
   Hist_event_vs_roc_status->Fill(i,roc_status_vec.at(i));
   Hist_roc_size_vs_roc_status->Fill(roc_size_vec.at(i),roc_status_vec.at(i));
}
Hist_residual_dtc_size->Draw();
  TCanvas * c12 = new TCanvas(Form("c12_%d",daq),Form("c12_%d",daq));
   Hist_event_vs_dtc_size->Draw("BOX");
     TCanvas * c13 = new TCanvas(Form("c13_%d",daq),Form("c13_%d",daq));
   Hist_event_vs_dtc_tag->Draw("BOX");
     TCanvas * c14 = new TCanvas(Form("c14_%d",daq),Form("c14_%d",daq));
   Hist_event_vs_roc_size->Draw("BOX");
        TCanvas * c15 = new TCanvas(Form("c15_%d",daq),Form("c15_%d",daq));
   Hist_event_vs_roc_status->Draw("BOX");
        TCanvas * c16 = new TCanvas(Form("c16_%d",daq),Form("c16_%d",daq));
   Hist_roc_size_vs_roc_status->Draw("BOX");
 //TProfile* p0=Hist_event_vs_dtc_size->ProfileX();
 //p0->Draw("");
  // Check for errors during reading
  if (in.bad()) {
    std::cerr << "Error reading from file" << std::endl;
  }
  in.close(); // Close the file

    return;
}


void open_file(){
    process_files("mu2edaq09_dtc1_run_066.dat",9);
    process_files("mu2edaq07_dtc1_run_066.dat",7);

}
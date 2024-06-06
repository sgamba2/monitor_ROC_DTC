#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include<bits/stdc++.h>
using namespace std;


void open1file(){
    ifstream in9("/exp/mu2e/data/projects/tracker/vst/datasets/val/emulated_cf0_10000_mu2edaq09_0002.dat", std::ios::binary );

 
    if(!in9) {
      cout << "Cannot open file!" << endl;
      return;
   }
    // Verifica se il file è stato aperto correttamente
    if (!in9.is_open()) {
        cerr << "impossible to open the file!" << endl;
        return;
    }
    TH1F* Hist_dtc_event_size_9 = new TH1F(Form("Hist_dtc_event_size_%d",9),Form("Hist_dtc_event_size_%d",9), 100, 0.,100.);
    TH1F* Hist_dtc_tag_9 = new TH1F(Form("Hist_dtc_tag_%d",9),Form("Hist_dtc_tag_%d",9), 70, 0.,70.);
    TH1F* Hist_residual_dtc_size_9 = new TH1F(Form("Hist_residual_dtc_size_%d",9),Form("Hist_residual_dtc_size_%d",9), 70, 0.,70.);
    TH2F* Hist_event_vs_dtc_size_9 = new TH2F(Form("Hist_event_vs_dtc_size_%d",9),Form("Hist_event_vs_dtc_size_%d",9), 70, 0.,70.,70, 0.,70.);
    TH2F* Hist_event_vs_dtc_tag_9 = new TH2F(Form("Hist_event_vs_dtc_tag_%d",9),Form("Hist_event_vs_dtc_tag_%d",9), 70, 0.,70.,70, 0.,70.);
    TH2F* Hist_event_vs_roc_size_9 = new TH2F(Form("Hist_event_vs_roc_size_%d",9),Form("Hist_event_vs_roc_size_%d",9), 500, 0.,500.,70, 0.,70.);
    TH2F* Hist_event_vs_roc_status_9 = new TH2F(Form("Hist_event_vs_roc_status_%d",9),Form("Hist_event_vs_roc_status_%d",9), 500, 0.,500.,400, 0.,400.);
    TH2F* Hist_roc_size_vs_roc_status_9 = new TH2F(Form("Hist_roc_size_vs_roc_status_%d",9),Form("Hist_roc_size_vs_roc_status_%d",9), 70, 0.,70.,400, 0.,400.);
    TH1F* Hist_line_number_dtc_9 = new TH1F(Form("Hist_line_number_dtc_%d",9),Form("Hist_line_number_dtc_%d",9), 2000, 0.,2000.);
    TH1F* Hist_num_events_9 = new TH1F(Form("Hist_num_events_%d",9),Form("Hist_num_events_%d",9), 70, 0.,70.);
    TH2F* Hist_dtc_event_size_vs_line_number_dtc_9 = new TH2F(Form("Hist_dtc_event_size_vs_line_number_dtc_%d",9),Form("Hist_dtc_event_size_vs_line_number_dtc_%d",9), 70, 0.,70.,2000, 0.,2000.);
    TH1F* Hist_line_number_roc_9 = new TH1F(Form("Hist_line_number_roc_%d",9),Form("Hist_line_number_roc_%d",9), 2000, 0.,2000.);
    TH1F* Hist_roc_size_9 = new TH1F(Form("Hist_roc_size_%d",9),Form("Hist_roc_size_%d",9), 70, 0.,70.);
    TH1F* Hist_NUM_ROCS_9 = new TH1F(Form("Hist_NUM_ROCS_%d",9),Form("Hist_NUM_ROCS_%d",9), 70, 0.,70.);
    TH2F* Hist_roc_size_vs_line_number_roc_9 = new TH2F(Form("Hist_roc_size_vs_line_number_roc_%d",9),Form("Hist_roc_size_vs_line_number_roc_%d",9), 70, 0.,70.,2000, 0.,2000.);
    TH2F* Hist_dtc_size_vs_roc_size_9 = new TH2F(Form("Hist_dtc_size_vs_roc_size_%d",9),Form("Hist_dtc_size_vs_roc_size_%d",9),70, 0.,70.,70, 0.,70.);
    TH1F* Hist_roc_status_9 = new TH1F(Form("Hist_roc_status_%d",9),Form("Hist_roc_status_%d",9), 1000, 0.,1000.);



int k_9=0;
unsigned char lo_9;
int loc_9 = 0;
unsigned char hi_9;
int num_events_9=0;
int dtc_size_9=-1;
vector<int> dtc_size_vec_9;
vector<int> dtc_tag_vec_9;
vector<int> roc_size_vec_9;
vector<float> roc_status_vec_9;
vector<float> line_number_roc_vec_9;
int lines_count_9=0;
int line_number_dtc_9=0;
int roc_size_9=-1;
int line_number_roc_9=0;
int num_roc_9=0;
int NUM_ROC_9=0;
int val_9=0;
int tot_dtc_size_9=0;
int tot_roc_size_9=0;
int val_status_9=0;
int roc_not_empty_9=0;

while(!in9.eof() and k_9<=100 ){
    if (loc_9 == 0){
       printf(" 0x%08x: ",k_9*2);
       lines_count_9++;
    }
    in9.read(reinterpret_cast<char*>(&lo_9), 1); 
    in9.read(reinterpret_cast<char*>(&hi_9), 1);
    int size_9 = (hi_9 << 8) | lo_9;
    printf("0x%04x ",size_9);

    if(loc_9==0 & dtc_size_9==-1){
        dtc_size_9=size_9>>4;
        dtc_size_vec_9.push_back(dtc_size_9);
        tot_dtc_size_9+=dtc_size_9;
        line_number_dtc_9=lines_count_9;
        num_events_9++;
        Hist_line_number_dtc_9->Fill(line_number_dtc_9);
        Hist_dtc_event_size_vs_line_number_dtc_9->Fill(dtc_size_9,line_number_dtc_9);
        val_9=1;
    }

    if(loc_9==2 and val_9==1){
        dtc_tag_vec_9.push_back(size_9);
        Hist_dtc_tag_9->Fill(size_9);
        val_9=0;
    }
    if(loc_9==0 & roc_size_9==-1 & lines_count_9>line_number_dtc_9+2){
        roc_size_9=size_9>>4;
        val_status_9=1;
        tot_roc_size_9+=roc_size_9;
        roc_size_vec_9.push_back(roc_size_9);
        line_number_roc_9=lines_count_9;
        num_roc_9++;
        NUM_ROC_9++;

    }

 
    if(loc_9==1 and val_status_9==1 and (hi_9%16)==1){
        line_number_roc_vec_9.push_back(line_number_roc_9);
        Hist_dtc_size_vs_roc_size_9->Fill(dtc_size_9,roc_size_9);
        roc_size_vec_9.push_back(roc_size_9);
        roc_not_empty_9=1;
    }
    if(loc_9==6 & val_status_9==1 & roc_not_empty_9==1){
        roc_status_vec_9.push_back(size_9/4.);
        val_status_9=0;
    }
    loc_9 += 1;
    if (loc_9 == 8) {
        printf("\n");
        loc_9  = 0;
    }
    if((line_number_dtc_9+dtc_size_9-1)==lines_count_9){
        dtc_size_9=-1;
        Hist_NUM_ROCS_9->Fill(NUM_ROC_9);
        NUM_ROC_9=0;
    }
    if((line_number_roc_9+roc_size_9-1)==lines_count_9){
        roc_size_9=-1;
        roc_not_empty_9=0;

    }
 
    k_9++;
}
printf("\n");
printf("TOTAL NUMBER OF LINES %d\n",lines_count_9);
printf("TOTAL NUMBER OF EVENTS %d\n",num_events_9);
printf("TOTAL NUMBER OF ROCS %d\n",num_roc_9);




tot_dtc_size_9/=66;
tot_roc_size_9/=(66*6);



for(int i=0;i<66;i++){
    Hist_dtc_event_size_9->Fill(dtc_size_vec_9.at(i));
    Hist_residual_dtc_size_9->Fill(dtc_size_vec_9.at(i)-tot_dtc_size_9);
    Hist_event_vs_dtc_size_9->Fill(i,dtc_size_vec_9.at(i)-tot_dtc_size_9);
    Hist_event_vs_dtc_tag_9->Fill(i,dtc_tag_vec_9.at(i));
   
}
for(int i=0;i<66;i++){
   Hist_roc_size_vs_line_number_roc_9->Fill(roc_size_vec_9.at(i),line_number_roc_vec_9.at(i));
   Hist_line_number_roc_9->Fill(line_number_roc_vec_9.at(i));
   Hist_roc_size_9->Fill(roc_size_vec_9.at(i));
   Hist_event_vs_roc_size_9->Fill(i,roc_size_vec_9.at(i));
   Hist_roc_status_9->Fill(roc_status_vec_9.at(i));
   Hist_event_vs_roc_status_9->Fill(i,roc_status_vec_9.at(i));
   Hist_roc_size_vs_roc_status_9->Fill(roc_size_vec_9.at(i),roc_status_vec_9.at(i));
  
}


TCanvas * c3 = new TCanvas("c3", "c3");
Hist_num_events_9->Fill((double)num_events_9);
Hist_num_events_9->SetLineColor(2);
Hist_num_events_9->SetFillStyle(3005);
Hist_num_events_9->SetFillColor(2);
Hist_num_events_9->Draw("");
c3->SaveAs("Hist_num_events.pdf");

TCanvas * c1 = new TCanvas("c1", "c1");
Hist_dtc_event_size_9->SetLineColor(2);
Hist_dtc_event_size_9->SetFillStyle(3005);
Hist_dtc_event_size_9->SetFillColor(2);
Hist_dtc_event_size_9->Draw();

c1->SaveAs("Hist_dtc_event_size.pdf");

TCanvas * c2 = new TCanvas("c2", "c2");
Hist_line_number_dtc_9->SetLineColor(2);
Hist_line_number_dtc_9->SetFillStyle(3005);
Hist_line_number_dtc_9->SetFillColor(2);
Hist_line_number_dtc_9->Draw();

TCanvas * c4 = new TCanvas("c4", "c4");
Hist_dtc_event_size_vs_line_number_dtc_9->SetLineColor(2);
Hist_dtc_event_size_vs_line_number_dtc_9->Draw("BOX");

TCanvas * c5 = new TCanvas("c5", "c5");
Hist_roc_size_9->SetLineColor(2);
Hist_roc_size_9->SetFillStyle(3005);
Hist_roc_size_9->SetFillColor(2);
Hist_roc_size_9->GetXaxis()->SetRangeUser(1,70);
Hist_roc_size_9->Draw();


TCanvas * c6 = new TCanvas("c6", "c6");
Hist_line_number_roc_9->SetLineColor(2);
Hist_line_number_roc_9->SetFillStyle(3005);
Hist_line_number_roc_9->SetFillColor(2);
Hist_line_number_roc_9->Draw();



c2->SaveAs("Hist_dtc_event_size.pdf");
c4->SaveAs("Hist_dtc_event_size_vs_line_number_dtc.pdf");
c5->SaveAs("Hist_roc_size.pdf");
c6->SaveAs("Hist_line_number_roc.pdf");


TCanvas * c7 = new TCanvas("c7", "c7");
Hist_NUM_ROCS_9->SetLineColor(2);
Hist_NUM_ROCS_9->SetFillStyle(3005);
Hist_NUM_ROCS_9->SetFillColor(2);
Hist_NUM_ROCS_9->Draw();

TCanvas * c8 = new TCanvas("c8", "c8");
Hist_roc_size_vs_line_number_roc_9->SetLineColor(2);
Hist_roc_size_vs_line_number_roc_9->Draw("BOX");

TCanvas * c9 = new TCanvas("c9", "c9");
Hist_dtc_size_vs_roc_size_9->SetLineColor(2);
Hist_dtc_size_vs_roc_size_9->Draw("BOX");

TCanvas * c10 = new TCanvas("c10", "c10");
Hist_dtc_tag_9->SetLineColor(2);
Hist_dtc_tag_9->SetFillStyle(3005);
Hist_dtc_tag_9->SetFillColor(2);
Hist_dtc_tag_9->Draw();


c7->SaveAs("Hist_NUM_ROCS.pdf");
c8->SaveAs("Hist_roc_size_vs_line_number_roc.pdf");
c9->SaveAs("Hist_dtc_size_vs_roc_size.pdf");
c10->SaveAs("Hist_dtc_tag.pdf");

TCanvas * c11 = new TCanvas("c11", "c11");
Hist_residual_dtc_size_9->SetLineColor(2);
Hist_residual_dtc_size_9->Draw();


TCanvas * c12 = new TCanvas("c12","c12");
Hist_event_vs_dtc_size_9->SetLineColor(2);
Hist_event_vs_dtc_size_9->Draw("BOX");



c11->SaveAs("Hist_residual_dtc_size.pdf");
c12->SaveAs("Hist_event_vs_dtc_size.pdf");


TCanvas * c13 = new TCanvas("c13","c13");
Hist_event_vs_dtc_tag_9->SetLineColor(2);
Hist_event_vs_dtc_tag_9->Draw("BOX");

TCanvas * c14 = new TCanvas("c14","c14");
Hist_event_vs_roc_size_9->SetLineColor(2);
Hist_event_vs_roc_size_9->Draw("BOX");

TCanvas * c15 = new TCanvas("c15","c15");
Hist_event_vs_roc_status_9->SetLineColor(2);
Hist_event_vs_roc_status_9->Draw("BOX");

TCanvas * c16 = new TCanvas("c16","c16");
Hist_roc_size_vs_roc_status_9->SetLineColor(2);
Hist_roc_size_vs_roc_status_9->Draw("BOX");

TCanvas * c17 = new TCanvas("c17","c17");
TProfile* p_9=Hist_event_vs_dtc_size_9->ProfileX();
p_9->SetFillStyle(3005);
p_9->SetFillColor(2);
p_9->SetLineColor(2);
p_9->Draw("");


TCanvas * c18 = new TCanvas("c18", "c18");
Hist_roc_status_9->SetLineColor(2);
Hist_roc_status_9->Draw();

c13->SaveAs("Hist_event_vs_dtc_tag.pdf");
c14->SaveAs("Hist_event_vs_roc_size.pdf");
c15->SaveAs("Hist_event_vs_roc_status.pdf");
c16->SaveAs("Hist_roc_size_vs_roc_status.pdf");
c17->SaveAs("Hist_event_vs_dtc.pdf");
c18->SaveAs("Hist_roc_status.pdf");




  if (in9.bad()) {
    std::cerr << "Error reading from file" << std::endl;
  }
  in9.close(); 
    return;
}


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include<bits/stdc++.h>
using namespace std;


void compare_different_ROCs(){
  string file("/exp/mu2e/data/projects/tracker/vst/datasets/val/emulated_cf0_10000_mu2edaq09_0002.dat"); //"/exp/mu2e/data/projects/tracker/vst/datasets/val/emulated_cf0_10000_mu2edaq09_0002.dat"
    ifstream in(file, std::ios::binary );

 
    if(!in) {
      cout << "Cannot open file!" << endl;
      return;
   }
    // Verifica se il file è stato aperto correttamente
    if (!in.is_open()) {
        cerr << "impossible to open the file!" << endl;
        return;
    }
    TH1F* Hist_dtc_event_size = new TH1F("Hist_dtc_event_size","Hist_dtc_event_size", 100, 0.,100.);
    TH1F* Hist_dtc_tag = new TH1F("Hist_dtc_tag","Hist_dtc_tag", 70, 0.,70.);
    TH1F* Hist_residual_dtc_size = new TH1F("Hist_residual_dtc_size","Hist_residual_dtc_size", 70, 0.,70.);
    TH2F* Hist_event_vs_dtc_size = new TH2F("Hist_event_vs_dtc_size","Hist_event_vs_dtc_size", 70, 0.,70.,70, 0.,70.);
    TH2F* Hist_event_vs_dtc_tag = new TH2F("Hist_event_vs_dtc_tag","Hist_event_vs_dtc_tag", 70, 0.,70.,70, 0.,70.);
    TH1F* Hist_line_number_dtc = new TH1F("Hist_line_number_dtc","Hist_line_number_dtc", 2000, 0.,2000.);
    TH1F* Hist_num_events = new TH1F("Hist_num_events","Hist_num_events", 70, 0.,70.);
    TH2F* Hist_dtc_event_size_vs_line_number_dtc = new TH2F("Hist_dtc_event_size_vs_line_number_dtc","Hist_dtc_event_size_vs_line_number_dtc", 70, 0.,70.,2000, 0.,2000.);

    TH2F* Hist_event_vs_roc_size_1 = new TH2F(Form("Hist_event_vs_roc_size_%d",1),Form("Hist_event_vs_roc_size_%d",1), 500, 0.,500.,70, 0.,70.);
    TH2F* Hist_event_vs_roc_status_1 = new TH2F(Form("Hist_event_vs_roc_status_%d",1),Form("Hist_event_vs_roc_status_%d",1), 500, 0.,500.,400, 0.,400.);
    TH2F* Hist_roc_size_vs_roc_status_1 = new TH2F(Form("Hist_roc_size_vs_roc_status_%d",1),Form("Hist_roc_size_vs_roc_status_%d",1), 70, 0.,70.,400, 0.,400.);
    TH1F* Hist_line_number_roc_1 = new TH1F(Form("Hist_line_number_roc_%d",1),Form("Hist_line_number_roc_%d",1), 2000, 0.,2000.);
    TH1F* Hist_roc_size_1 = new TH1F(Form("Hist_roc_size_%d",1),Form("Hist_roc_size_%d",1), 70, 0.,70.);
   
    TH2F* Hist_roc_size_vs_line_number_roc_1 = new TH2F(Form("Hist_roc_size_vs_line_number_roc_%d",1),Form("Hist_roc_size_vs_line_number_roc_%d",1), 70, 0.,70.,2000, 0.,2000.);
    TH2F* Hist_dtc_size_vs_roc_size_1 = new TH2F(Form("Hist_dtc_size_vs_roc_size_%d",1),Form("Hist_dtc_size_vs_roc_size_%d",1),70, 0.,70.,70, 0.,70.);
    TH1F* Hist_roc_status_1 = new TH1F(Form("Hist_roc_status_%d",1),Form("Hist_roc_status_%d",1), 1000, 0.,1000.);

   
    TH2F* Hist_event_vs_roc_size_2 = new TH2F(Form("Hist_event_vs_roc_size_%d",2),Form("Hist_event_vs_roc_size_%d",2), 500, 0.,500.,70, 0.,70.);
    TH2F* Hist_event_vs_roc_status_2 = new TH2F(Form("Hist_event_vs_roc_status_%d",2),Form("Hist_event_vs_roc_status_%d",2), 500, 0.,500.,400, 0.,400.);
    TH2F* Hist_roc_size_vs_roc_status_2 = new TH2F(Form("Hist_roc_size_vs_roc_status_%d",2),Form("Hist_roc_size_vs_roc_status_%d",2), 70, 0.,70.,400, 0.,400.);
    TH1F* Hist_line_number_dtc_2 = new TH1F(Form("Hist_line_number_dtc_%d",2),Form("Hist_line_number_dtc_%d",2), 2000, 0.,2000.);
    TH1F* Hist_num_events_2 = new TH1F(Form("Hist_num_events_%d",2),Form("Hist_num_events_%d",2), 70, 0.,70.);
    TH1F* Hist_line_number_roc_2 = new TH1F(Form("Hist_line_number_roc_%d",2),Form("Hist_line_number_roc_%d",2), 2000, 0.,2000.);
    TH1F* Hist_roc_size_2 = new TH1F(Form("Hist_roc_size_%d",2),Form("Hist_roc_size_%d",2), 70, 0.,70.);

    TH2F* Hist_roc_size_vs_line_number_roc_2 = new TH2F(Form("Hist_roc_size_vs_line_number_roc_%d",2),Form("Hist_roc_size_vs_line_number_roc_%d",2), 70, 0.,70.,2000, 0.,2000.);
    TH2F* Hist_dtc_size_vs_roc_size_2 = new TH2F(Form("Hist_dtc_size_vs_roc_size_%d",2),Form("Hist_dtc_size_vs_roc_size_%d",2),70, 0.,70.,70, 0.,70.);
    TH1F* Hist_roc_status_2 = new TH1F(Form("Hist_roc_status_%d",2),Form("Hist_roc_status_%d",2), 1000, 0.,1000.);



int k_1=0;
unsigned char lo_1;
int loc_1 = 0;
unsigned char hi_1;
int num_events_1=0;
int dtc_size_1=-1;
vector<int> dtc_size_vec_1;
vector<int> dtc_tag_vec_1;
vector<int> roc_size_vec_1;
vector<float> roc_status_vec_1;
vector<float> line_number_roc_vec_1;
int lines_count_1=0;
int line_number_dtc_1=0;
int roc_size_1=-1;
int line_number_roc_1=0;
int num_roc_1=0;
int NUM_ROC_1=0;
int val_1=0;
int tot_dtc_size_1=0;
int tot_roc_size_1=0;
int val_status_1=0;
int roc_not_empty_1=0;
 int AAAAA=-1;
while(!in.eof()){
    if (loc_1 == 0){
       printf(" 0x%08x: ",k_1*2);
       lines_count_1++;
    }
    in.read(reinterpret_cast<char*>(&lo_1), 1); 
    in.read(reinterpret_cast<char*>(&hi_1), 1);
    int size_1 = (hi_1 << 8) | lo_1;
    printf("0x%04x ",size_1);

    if(loc_1==0 & dtc_size_1==-1){
        dtc_size_1=size_1>>4;
        dtc_size_vec_1.push_back(dtc_size_1);
        tot_dtc_size_1+=dtc_size_1;
        line_number_dtc_1=lines_count_1;
        num_events_1++;
        Hist_line_number_dtc_1->Fill(line_number_dtc_1);
        Hist_dtc_event_size_vs_line_number_dtc_1->Fill(dtc_size_1,line_number_dtc_1);
        val_1=1;
    printf("DTC ");

    }

    if(loc_1==2 and val_1==1){
        dtc_tag_vec_1.push_back(size_1);
        Hist_dtc_tag_1->Fill(size_1);
        val_1=0;
    }
    if(loc_1==0 & roc_size_1==-1 & lines_count_1>line_number_dtc_1+2){
        roc_size_1=size_1>>4;
        val_status_1=1;
        tot_roc_size_1+=roc_size_1;
        line_number_roc_1=lines_count_1;
        num_roc_1++;
        NUM_ROC_1++;

    }

 
    if(loc_1==1 and val_status_1==1 and (hi_1%16)==0 and val_1==0 and lines_count_1>line_number_dtc_1+2){
        line_number_roc_vec_1.push_back(line_number_roc_1);
        Hist_dtc_size_vs_roc_size_1->Fill(dtc_size_1,roc_size_1);
        roc_size_vec_1.push_back(roc_size_1);
        roc_not_empty_1=1;
        val_status_1=0;

    printf("ROC ");

    }
    if(loc_1==6  &  roc_not_empty_1==1  & lines_count_1>line_number_dtc_1+2 ){
        roc_status_vec_1.push_back(size_1/4.);
        roc_not_empty_1=0;

    printf("ROC STATUS");

    }
    loc_1 += 1;
    if (loc_1 == 8) {
        printf("\n");
        loc_1  = 0;
    }
    if((line_number_dtc_1+dtc_size_1-1)==lines_count_1){
        dtc_size_1=-1;
        Hist_NUM_ROCS_1->Fill(NUM_ROC_1);
        NUM_ROC_1=0;
    }
    if((line_number_roc_1+roc_size_1-1)==lines_count_1){
        roc_size_1=-1;

    }
 
    k_1++;
}

        printf("\n");

  if (in.bad()) {
    std::cerr << "Error reading from file" << std::endl;
  }
  in.close(); 
    ifstream in2(file, std::ios::binary );

int k_2=0;
unsigned char lo_2;
int loc_2 = 0;
unsigned char hi_2;
int num_events_2=0;
int dtc_size_2=-1;
vector<int> dtc_size_vec_2;
vector<int> dtc_tag_vec_2;
vector<int> roc_size_vec_2;
vector<float> roc_status_vec_2;
vector<float> line_number_roc_vec_2;
int lines_count_2=0;
int line_number_dtc_2=0;
int roc_size_2=-1;
int line_number_roc_2=0;
int num_roc_2=0;
int NUM_ROC_2=0;
int val_2=0;
int tot_dtc_size_2=0;
int tot_roc_size_2=0;
int val_status_2=0;
int roc_not_empty_2=0;
 int AAAAA=-1;
while(!in2.eof()){
    if (loc_2 == 0){
       printf(" 0x%08x: ",k_2*2);
       lines_count_2++;
    }
    in2.read(reinterpret_cast<char*>(&lo_2), 1); 
    in2.read(reinterpret_cast<char*>(&hi_2), 1);
    int size_2 = (hi_2 << 8) | lo_2;
    printf("0x%04x ",size_2);

    if(loc_2==0 & dtc_size_2==-1){
        dtc_size_2=size_2>>4;
        dtc_size_vec_2.push_back(dtc_size_2);
        tot_dtc_size_2+=dtc_size_2;
        line_number_dtc_2=lines_count_2;
        num_events_2++;
        Hist_line_number_dtc_2->Fill(line_number_dtc_2);
        Hist_dtc_event_size_vs_line_number_dtc_2->Fill(dtc_size_2,line_number_dtc_2);
        val_2=1;
    printf("DTC ");

    }

    if(loc_2==2 and val_2==1){
        dtc_tag_vec_2.push_back(size_2);
        Hist_dtc_tag_2->Fill(size_2);
        val_2=0;
    }
    if(loc_2==0 & roc_size_2==-1 & lines_count_2>line_number_dtc_2+2){
        roc_size_2=size_2>>4;
        val_status_2=1;
        tot_roc_size_2+=roc_size_2;
        line_number_roc_2=lines_count_2;
        num_roc_2++;
        NUM_ROC_2++;

    }

 
    if(loc_2==1 and val_status_2==1 and (hi_2%16)==0 and val_2==0 and lines_count_2>line_number_dtc_2+2){
        line_number_roc_vec_2.push_back(line_number_roc_2);
        Hist_dtc_size_vs_roc_size_2->Fill(dtc_size_2,roc_size_2);
        roc_size_vec_2.push_back(roc_size_2);
        roc_not_empty_2=1;
        val_status_2=0;

    printf("ROC ");

    }
    if(loc_2==6  &  roc_not_empty_2==1  & lines_count_2>line_number_dtc_2+2 ){
        roc_status_vec_2.push_back(size_2/4.);
        roc_not_empty_2=0;

    printf("ROC STATUS");

    }
    loc_2 += 1;
    if (loc_2 == 8) {
        printf("\n");
        loc_2  = 0;
    }
    if((line_number_dtc_2+dtc_size_2-1)==lines_count_2){
        dtc_size_2=-1;
        Hist_NUM_ROCS_2->Fill(NUM_ROC_2);
        NUM_ROC_2=0;
    }
    if((line_number_roc_2+roc_size_2-1)==lines_count_2){
        roc_size_2=-1;

    }
 
    k_2++;
}




printf("\n");
printf("TOTAL NUMBER OF LINES %d\n",lines_count);
printf("TOTAL NUMBER OF EVENTS %d\n",num_events);
printf("TOTAL NUMBER OF ROCS2 %d\n",num_roc_2);
printf("TOTAL NUMBER OF ROCS1 %d\n",num_roc_1);

 printf("TOTAL NUMBER OF size roc1  %lu\n",size(roc_size_vec_1));
 printf("TOTAL NUMBER OF line roc1  %lu\n",size(line_number_roc_vec_1));
 printf("TOTAL NUMBER OF status roc1  %lu\n",size(roc_status_vec_1));

 printf("TOTAL NUMBER OF size roc2  %lu\n",size(roc_size_vec_2));
 printf("TOTAL NUMBER OF line roc2  %lu\n",size(line_number_roc_vec_2));
 printf("TOTAL NUMBER OF status roc2  %lu\n",size(roc_status_vec_2));

 printf("TOTAL NUMBER OF tag dtc   %lu\n",size(dtc_tag_vec));
 printf("TOTAL NUMBER OF size dtc   %lu\n",size(dtc_size_vec));

        


tot_dtc_size/=(num_events-1);
tot_roc_size_1/=(size(roc_size_vec_1));
tot_roc_size_2/=(size(roc_size_vec_2));


 for(int i=0;i<size(dtc_size_vec)-1;i++){
    Hist_dtc_event_size->Fill(dtc_size_vec.at(i));
    Hist_residual_dtc_size->Fill(dtc_size_vec.at(i)-tot_dtc_size);
    Hist_event_vs_dtc_size->Fill(i,dtc_size_vec.at(i)-tot_dtc_size);
    Hist_event_vs_dtc_tag->Fill(i,dtc_tag_vec.at(i));
  
}
for(int i=0;i<size(roc_size_vec_1);i++){

   Hist_roc_size_vs_line_number_roc_1->Fill(roc_size_vec_1.at(i),line_number_roc_vec_1.at(i));
   Hist_line_number_roc_1->Fill(line_number_roc_vec_1.at(i));
   Hist_roc_size_1->Fill(roc_size_vec_1.at(i));
   Hist_event_vs_roc_size_1->Fill(i,roc_size_vec_1.at(i));
   Hist_roc_status_1->Fill(roc_status_vec_1.at(i));
   Hist_event_vs_roc_status_1->Fill(i,roc_status_vec_1.at(i));
   Hist_roc_size_vs_roc_status_1->Fill(roc_size_vec_1.at(i),roc_status_vec_1.at(i));
 
}

for(int i=0;i<size(roc_size_vec_2);i++){

   Hist_roc_size_vs_line_number_roc_2->Fill(roc_size_vec_2.at(i),line_number_roc_vec_2.at(i));
   Hist_line_number_roc_2->Fill(line_number_roc_vec_2.at(i));
   Hist_roc_status_2->Fill(roc_status_vec_2.at(i));
  Hist_roc_size_2->Fill(roc_size_vec_2.at(i));
   Hist_event_vs_roc_size_2->Fill(i,roc_size_vec_2.at(i));
   Hist_event_vs_roc_status_2->Fill(i,roc_status_vec_2.at(i));
   Hist_roc_size_vs_roc_status_2->Fill(roc_size_vec_2.at(i),roc_status_vec_2.at(i));
 }
TCanvas * c3 = new TCanvas("c3", "c3");
Hist_num_events->Fill((double)num_events);
Hist_num_events->SetLineColor(2);
Hist_num_events->SetFillStyle(3005);
Hist_num_events->SetFillColor(2);
Hist_num_events->Draw("");
c3->SaveAs("Hist_num_events.pdf");

TCanvas * c1 = new TCanvas("c1", "c1");
Hist_dtc_event_size->SetLineColor(2);
Hist_dtc_event_size->SetFillStyle(3005);
Hist_dtc_event_size->SetFillColor(2);
Hist_dtc_event_size->Draw();

c1->SaveAs("Hist_dtc_event_size.pdf");

TCanvas * c2 = new TCanvas("c2", "c2");
Hist_line_number_dtc->SetLineColor(2);
Hist_line_number_dtc->SetFillStyle(3005);
Hist_line_number_dtc->SetFillColor(2);
Hist_line_number_dtc->Draw();

TCanvas * c4 = new TCanvas("c4", "c4");
Hist_dtc_event_size_vs_line_number_dtc->SetLineColor(2);
Hist_dtc_event_size_vs_line_number_dtc->Draw("BOX");

TCanvas * c5 = new TCanvas("c5", "c5");
Hist_roc_size_1->SetLineColor(2);
Hist_roc_size_2->SetLineColor(4);
Hist_roc_size_1->SetFillStyle(3005);
Hist_roc_size_2->SetFillStyle(3004);
Hist_roc_size_1->SetFillColor(2);
Hist_roc_size_2->SetFillColor(4);
Hist_roc_size_1->GetXaxis()->SetRangeUser(1,70);
Hist_roc_size_2->GetXaxis()->SetRangeUser(1,70);
Hist_roc_size_1->Draw();
Hist_roc_size_2->Draw("SAMES");


TCanvas * c6 = new TCanvas("c6", "c6");
Hist_line_number_roc_1->SetLineColor(2);
Hist_line_number_roc_2->SetLineColor(4);
Hist_line_number_roc_1->SetFillStyle(3005);
Hist_line_number_roc_2->SetFillStyle(3004);
Hist_line_number_roc_1->SetFillColor(2);
Hist_line_number_roc_2->SetFillColor(4);
Hist_line_number_roc_1->Draw();
Hist_line_number_roc_2->Draw("SAMES");



c2->SaveAs("Hist_dtc_event_size.pdf");
c4->SaveAs("Hist_dtc_event_size_vs_line_number_dtc.pdf");
c5->SaveAs("Hist_roc_size.pdf");
c6->SaveAs("Hist_line_number_roc.pdf");



TCanvas * c8 = new TCanvas("c8", "c8");
Hist_roc_size_vs_line_number_roc_1->SetLineColor(2);
Hist_roc_size_vs_line_number_roc_2->SetLineColor(4);
Hist_roc_size_vs_line_number_roc_1->Draw("BOX");
Hist_roc_size_vs_line_number_roc_2->Draw("BOXSAMES");

TCanvas * c9 = new TCanvas("c9", "c9");
Hist_dtc_size_vs_roc_size_1->SetLineColor(2);
Hist_dtc_size_vs_roc_size_2->SetLineColor(4);
Hist_dtc_size_vs_roc_size_1->Draw("BOX");
Hist_dtc_size_vs_roc_size_2->Draw("BOXSAMES");

TCanvas * c10 = new TCanvas("c10", "c10");
Hist_dtc_tag->SetLineColor(2);
Hist_dtc_tag->SetFillStyle(3005);
Hist_dtc_tag->SetFillColor(2);
Hist_dtc_tag->Draw();


c8->SaveAs("Hist_roc_size_vs_line_number_roc.pdf");
c9->SaveAs("Hist_dtc_size_vs_roc_size.pdf");
c10->SaveAs("Hist_dtc_tag.pdf");

TCanvas * c11 = new TCanvas("c11", "c11");
Hist_residual_dtc_size->SetLineColor(2);
Hist_residual_dtc_size->Draw();


TCanvas * c12 = new TCanvas("c12","c12");
Hist_event_vs_dtc_size->SetLineColor(2);
Hist_event_vs_dtc_size->Draw("BOX");



c11->SaveAs("Hist_residual_dtc_size.pdf");
c12->SaveAs("Hist_event_vs_dtc_size.pdf");


TCanvas * c13 = new TCanvas("c13","c13");
Hist_event_vs_dtc_tag->SetLineColor(2);
Hist_event_vs_dtc_tag->Draw("BOX");

TCanvas * c14 = new TCanvas("c14","c14");
Hist_event_vs_roc_size_1->SetLineColor(2);
Hist_event_vs_roc_size_2->SetLineColor(4);
Hist_event_vs_roc_size_1->Draw("BOX");
Hist_event_vs_roc_size_2->Draw("BOXSAMES");

TCanvas * c15 = new TCanvas("c15","c15");
Hist_event_vs_roc_status_1->SetLineColor(2);
Hist_event_vs_roc_status_2->SetLineColor(4);
Hist_event_vs_roc_status_1->Draw("BOX");
Hist_event_vs_roc_status_2->Draw("BOXSAMES");

TCanvas * c16 = new TCanvas("c16","c16");
Hist_roc_size_vs_roc_status_1->SetLineColor(2);
Hist_roc_size_vs_roc_status_2->SetLineColor(4);
Hist_roc_size_vs_roc_status_1->Draw("BOX");
Hist_roc_size_vs_roc_status_2->Draw("BOXSAMES");

TCanvas * c17 = new TCanvas("c17","c17");
TProfile* p_1=Hist_event_vs_dtc_size->ProfileX();
p_1->SetFillStyle(3005);
p_1->SetFillColor(2);
p_1->SetLineColor(2);
p_1->Draw("");


TCanvas * c18 = new TCanvas("c18", "c18");
Hist_roc_status_1->SetLineColor(2);
Hist_roc_status_2->SetLineColor(4);
Hist_roc_status_1->Draw();
Hist_roc_status_2->Draw("SAMES");

c13->SaveAs("Hist_event_vs_dtc_tag.pdf");
c14->SaveAs("Hist_event_vs_roc_size.pdf");
c15->SaveAs("Hist_event_vs_roc_status.pdf");
c16->SaveAs("Hist_roc_size_vs_roc_status.pdf");
c17->SaveAs("Hist_event_vs_dtc.pdf");
c18->SaveAs("Hist_roc_status.pdf");




  if (in2.bad()) {
    std::cerr << "Error reading from file" << std::endl;
  }
  in2.close(); 
    return;
}

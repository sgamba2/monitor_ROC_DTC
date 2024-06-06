#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include<bits/stdc++.h>
using namespace std;


void compare_different_ROCs(){
    ifstream in("/exp/mu2e/data/projects/tracker/vst/datasets/val/emulated_cf0_10000_mu2edaq09_0002.dat", std::ios::binary );

 
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
    TH1F* Hist_NUM_ROCS_1 = new TH1F(Form("Hist_NUM_ROCS_%d",1),Form("Hist_NUM_ROCS_%d",1), 70, 0.,70.);
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
    TH1F* Hist_NUM_ROCS_2 = new TH1F(Form("Hist_NUM_ROCS_%d",2),Form("Hist_NUM_ROCS_%d",2), 70, 0.,70.);
    TH2F* Hist_roc_size_vs_line_number_roc_2 = new TH2F(Form("Hist_roc_size_vs_line_number_roc_%d",2),Form("Hist_roc_size_vs_line_number_roc_%d",2), 70, 0.,70.,2000, 0.,2000.);
    TH2F* Hist_dtc_size_vs_roc_size_2 = new TH2F(Form("Hist_dtc_size_vs_roc_size_%d",2),Form("Hist_dtc_size_vs_roc_size_%d",2),70, 0.,70.,70, 0.,70.);
    TH1F* Hist_roc_status_2 = new TH1F(Form("Hist_roc_status_%d",2),Form("Hist_roc_status_%d",2), 1000, 0.,1000.);


int k=0;
unsigned char lo;
int loc = 0;
unsigned char hi;
int num_events=0;
int dtc_size=-1;
int tot_dtc_size=0;
int val_status=0;
vector<int> dtc_size_vec;
vector<int> dtc_tag_vec;
int lines_count=0;
int line_number_dtc=0;
int val_dtc=0;

int which_roc=0;
int tot_roc_size_1=0;
int tot_roc_size_2=0;
int line_number_roc_1=0;
int line_number_roc_2=0;
vector<int> roc_size_vec_1;
vector<float> roc_status_vec_1;
vector<float> line_number_roc_vec_1;
vector<int> roc_size_vec_2;
vector<float> roc_status_vec_2;
vector<float> line_number_roc_vec_2;

int roc_size=-1;
int NUM_ROC_1=0;
int NUM_ROC_2=0;

while(!in.eof()  ){
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
        Hist_line_number_dtc->Fill(line_number_dtc);
        Hist_dtc_event_size_vs_line_number_dtc->Fill(dtc_size,line_number_dtc);
        val_dtc=1;
    }

    if(loc==2 and val_dtc==1){
        dtc_tag_vec.push_back(size);
        Hist_dtc_tag->Fill(size);
        val_dtc=0;
    }
    if(loc==0 & roc_size==-1 & lines_count>line_number_dtc+2){
        roc_size=size>>4;
        val_status=1;
    }

    if(loc==1 and val_status==1 and (hi%16)==1){
        line_number_roc_1=lines_count;
        line_number_roc_vec_1.push_back(line_number_roc_1);
        Hist_dtc_size_vs_roc_size_1->Fill(dtc_size,roc_size);
        tot_roc_size_1+=roc_size;
        roc_size_vec_1.push_back(roc_size);
	    which_roc=1;
        NUM_ROC_1++;
	printf("sono qui1s");

    }
    if(loc==1 and val_status==1 and (hi%16)==0 ){
        line_number_roc_2=lines_count;
        tot_roc_size_2+=roc_size;
        line_number_roc_vec_2.push_back(line_number_roc_2);
        Hist_dtc_size_vs_roc_size_2->Fill(dtc_size,roc_size);
        roc_size_vec_2.push_back(roc_size);
	    which_roc=2;
        NUM_ROC_2++;
	printf("sono qui2s");
    }
    if(loc==6 & val_status==1 &  which_roc==1){
        roc_status_vec_1.push_back(size/4.);
        val_status=0;
    }
    if(loc==6 & val_status==1 &  which_roc==2){
        roc_status_vec_2.push_back(size/4.);
        val_status=0;
    }
    loc += 1;
    if (loc == 8) {
        printf("\n");
        loc  = 0;
    }
    if((line_number_dtc+dtc_size-1)==lines_count){
        dtc_size=-1;
        if(which_roc==1){
            Hist_NUM_ROCS_1->Fill(NUM_ROC_1);
        }
        if(which_roc==2){
            Hist_NUM_ROCS_2->Fill(NUM_ROC_2);
        }
        NUM_ROC_1=0;
        NUM_ROC_2=0;
    }
    if((line_number_roc_1+roc_size-1)==lines_count){
        roc_size=-1;
        which_roc=0;
    }
     if((line_number_roc_2+roc_size-1)==lines_count){
        roc_size=-1;
        which_roc=0;
    }
    k++;
}
printf("\n");
printf("TOTAL NUMBER OF LINES %d\n",lines_count);
printf("TOTAL NUMBER OF EVENTS %d\n",num_events);
printf("TOTAL NUMBER OF ROCS2 %d\n",NUM_ROC_2);
printf("TOTAL NUMBER OF ROCS1 %d\n",NUM_ROC_1);




tot_dtc_size/=(num_events-1);
tot_roc_size_1/=((num_events-1)*6);
tot_roc_size_2/=((num_events-1)*6);


for(int i=0;i<num_events;i++){
    Hist_dtc_event_size->Fill(dtc_size_vec.at(i));
    Hist_residual_dtc_size->Fill(dtc_size_vec.at(i)-tot_dtc_size);
    Hist_event_vs_dtc_size->Fill(i,dtc_size_vec.at(i)-tot_dtc_size);
    Hist_event_vs_dtc_tag->Fill(i,dtc_tag_vec.at(i));
  
}
for(int i=0;i<num_events;i++){
   Hist_roc_size_vs_line_number_roc_1->Fill(roc_size_vec_1.at(i),line_number_roc_vec_1.at(i));
   Hist_roc_size_vs_line_number_roc_2->Fill(roc_size_vec_2.at(i),line_number_roc_vec_2.at(i));
   Hist_line_number_roc_1->Fill(line_number_roc_vec_1.at(i));
   Hist_line_number_roc_2->Fill(line_number_roc_vec_2.at(i));
   Hist_roc_size_1->Fill(roc_size_vec_1.at(i));
   Hist_event_vs_roc_size_1->Fill(i,roc_size_vec_1.at(i));
   Hist_roc_status_1->Fill(roc_status_vec_1.at(i));
   Hist_roc_status_2->Fill(roc_status_vec_2.at(i));
   Hist_event_vs_roc_status_1->Fill(i,roc_status_vec_1.at(i));
   Hist_roc_size_vs_roc_status_1->Fill(roc_size_vec_1.at(i),roc_status_vec_1.at(i));
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


TCanvas * c7 = new TCanvas("c7", "c7");
Hist_NUM_ROCS_1->SetLineColor(2);
Hist_NUM_ROCS_2->SetLineColor(4);
Hist_NUM_ROCS_1->SetFillStyle(3005);
Hist_NUM_ROCS_2->SetFillStyle(3004);
Hist_NUM_ROCS_1->SetFillColor(2);
Hist_NUM_ROCS_2->SetFillColor(4);
Hist_NUM_ROCS_1->Draw();
Hist_NUM_ROCS_2->Draw("SAMES");

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


c7->SaveAs("Hist_NUM_ROCS.pdf");
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




  if (in.bad()) {
    std::cerr << "Error reading from file" << std::endl;
  }
  in.close(); 
    return;
}

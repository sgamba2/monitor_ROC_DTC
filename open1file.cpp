#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include<bits/stdc++.h>
#include "TGraph.h"
using namespace std;

struct results{
  int number_of_events=0;
  int number_of_100=0;
  int number_of_101=0;
  int number_of_180=0;
  int number_of_108=0;
  int number_of_508=0;
  int number_of_other_errors=0;
  int number_of_start=0;

};

results process(string filename){
    ifstream in9(filename, std::ios::binary );

    gStyle->SetOptStat(1111111);
    if(!in9) {
      cout << "Cannot open file!" << endl;
   }
    // Verifica se il file è stato aperto correttamente
    if (!in9.is_open()) {
        cerr << "impossible to open the file!" << endl;
    }
    TH1F* Hist_dtc_event_size_9 = new TH1F(Form("Hist_dtc_event_size_%d",9),Form("Hist_dtc_event_size_%d",9), 100, 0.,100.);
    TH1F* Hist_dtc_tag_9 = new TH1F(Form("Hist_dtc_tag_%d",9),Form("Hist_dtc_tag_%d",9), 10000, 0.,10000.);
    TH1F* Hist_residual_dtc_size_9 = new TH1F(Form("Hist_residual_dtc_size_%d",9),Form("Hist_residual_dtc_size_%d",9), 100, 0.,100.);
    TH2F* Hist_event_vs_dtc_size_9 = new TH2F(Form("Hist_event_vs_dtc_size_%d",9),Form("Hist_event_vs_dtc_size_%d",9), 10000, 0.,10000.,100, 0.,100.);
    TH2F* Hist_event_vs_dtc_tag_9 = new TH2F(Form("Hist_event_vs_dtc_tag_%d",9),Form("Hist_event_vs_dtc_tag_%d",9), 10000, 0.,10000.,10000, 0.,10000.);
    TH2F* Hist_event_vs_roc_size_9 = new TH2F(Form("Hist_event_vs_roc_size_%d",9),Form("Hist_event_vs_roc_size_%d",9), 60000, 0.,60000.,100, 0.,100.);
    TH2F* Hist_event_vs_roc_status_9 = new TH2F(Form("Hist_event_vs_roc_status_%d",9),Form("Hist_event_vs_roc_status_%d",9), 10000, 0.,10000.,20, 0.,20.);
    TH2F* Hist_roc_size_vs_roc_status_9 = new TH2F(Form("Hist_roc_status_vs_roc_size_%d",9),Form("Hist_roc_status_vs_roc_size_%d",9),20, 0.,20.,100, 0.,100.);
    TH1F* Hist_line_number_dtc_9 = new TH1F(Form("Hist_line_number_dtc_%d",9),Form("Hist_line_number_dtc_%d",9), 60000, 0.,60000.);
    TH1F* Hist_num_events_9 = new TH1F(Form("Hist_num_events_%d",9),Form("Hist_num_events_%d",9), 10500, 0.,10500.);
    TH2F* Hist_dtc_event_size_vs_line_number_dtc_9 = new TH2F(Form("Hist_dtc_event_size_vs_line_number_dtc_%d",9),Form("Hist_dtc_event_size_vs_line_number_dtc_%d",9), 100, 0.,100.,10000, 0.,10000.);
    TH1F* Hist_line_number_roc_9 = new TH1F(Form("Hist_line_number_roc_%d",9),Form("Hist_line_number_roc_%d",9), 60000, 0.,60000.);
    TH1F* Hist_roc_size_9 = new TH1F(Form("Hist_roc_size_%d",9),Form("Hist_roc_size_%d",9), 100, 0.,100.);
    TH1F* Hist_NUM_ROCS_9 = new TH1F(Form("Hist_NUM_ROCS_%d",9),Form("Hist_NUM_ROCS_%d",9), 1000, 0.,1000.);
    TH2F* Hist_roc_size_vs_line_number_roc_9 = new TH2F(Form("Hist_roc_size_vs_line_number_roc_%d",9),Form("Hist_roc_size_vs_line_number_roc_%d",9), 100, 0.,100.,60000, 0.,60000.);
    TH2F* Hist_dtc_size_vs_roc_size_9 = new TH2F(Form("Hist_dtc_size_vs_roc_size_%d",9),Form("Hist_dtc_size_vs_roc_size_%d",9),100, 0.,100.,100, 0.,100.);
    TH1F* Hist_roc_status_9 = new TH1F(Form("Hist_roc_status_%d",9),Form("Hist_roc_status_%d",9), 20, 0.,20.);
    TH1F* Hist_dtc_tag_vs_event_number_9 = new TH1F(Form("Hist_delta_dtc_tag_event_number_%d",9),Form("Hist_delta_dtc_tag_event_number_%d",9), 800, -400.,400.);
    TH2F* Hist_event_vs_roc_size_64 = new TH2F(Form(" Hist_event_vs_roc_size_64_%d",9),Form(" Hist_event_vs_roc_size_64_%d",9), 10000, 0.,10000.,20000, -100.,100.);
    TH1F* Hist_roc_size_64 = new TH1F(Form(" Hist_roc_size_64_%d",9),Form(" Hist_roc_size_64_%d",9), 20000, -100.,100.);
 TH1F* Hist_dtc_tag_vs_dtc_tag_minus_1_9= new TH1F(Form("Hist_dtc_tag_vs_dtc_tag_minus_1_%d",9),Form("Hist_dtc_tag_vs_dtc_tag_minus_1_%d",9), 800, -400.,400.);
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
int       roc_status_passed_9=0;
 int error_dtc_tag=0;
 int event_number=0;
 int start_number=-1;
 vector<int> ew_tag_wrong;
 while(!in9.eof() ){
    if (loc_9 == 0){
      printf(" 0x%08x: ",k_9*2);
       lines_count_9++;
    }
    in9.read(reinterpret_cast<char*>(&lo_9), 1); 
    in9.read(reinterpret_cast<char*>(&hi_9), 1);
    int size_9 = (hi_9 << 8) | lo_9;
    printf("0x%04x ",size_9);
    if(loc_9==2 and start_number==-1) start_number=size_9;
    if(loc_9==0 & dtc_size_9==-1){
        dtc_size_9=size_9>>4;
        tot_dtc_size_9+=dtc_size_9;
        line_number_dtc_9=lines_count_9;
        num_events_9++;
        Hist_line_number_dtc_9->Fill(line_number_dtc_9);
        Hist_dtc_event_size_vs_line_number_dtc_9->Fill(dtc_size_9,line_number_dtc_9);
        val_9=1;
	//printf(" 0x%08x: ",k_9*2);
	// printf("0x%04x ",size_9);

	printf("DTC");

    }

    if(loc_9==2 and val_9==1){
      //printf("0x%04x ",size_9);
    // printf("\n");
	  Hist_dtc_tag_vs_dtc_tag_minus_1_9->Fill(size_9-error_dtc_tag);

        dtc_tag_vec_9.push_back(size_9);
        dtc_size_vec_9.push_back(dtc_size_9);

        val_9=0;

	if(error_dtc_tag!=size_9-1 ){
	  printf("XXXXXXXXXXXXX ERROR HERE EW TAG XXXXXXXXXXXXXX");
	  ew_tag_wrong.push_back(lines_count_9);
	  Hist_dtc_tag_9->Fill(size_9);

	}
	error_dtc_tag=size_9;
	  Hist_dtc_tag_vs_event_number_9->Fill(size_9-event_number);

	  event_number++;

    }
    if(loc_9==0 & roc_size_9==-1  & lines_count_9>line_number_dtc_9+2){
        roc_size_9=size_9>>4;
        val_status_9=1;
        tot_roc_size_9+=roc_size_9;
        line_number_roc_9=lines_count_9;
        num_roc_9++;
        NUM_ROC_9++;

    }

 
    if(loc_9==1 and val_status_9==1 and (hi_9%16)==1 and val_9==0 and lines_count_9>line_number_dtc_9+2){
        line_number_roc_vec_9.push_back(line_number_roc_9);
        Hist_dtc_size_vs_roc_size_9->Fill(dtc_size_9,roc_size_9);
        roc_size_vec_9.push_back(roc_size_9);
        roc_not_empty_9=1;
        val_status_9=0;
	//	printf("roc size %d ", roc_size_9);
	//printf("ROC ");

    }
    if(loc_9==6  &  roc_not_empty_9==1  & lines_count_9>line_number_dtc_9+2 ){
      if(size_9==0x0100){
        roc_status_vec_9.push_back(1);
      }else if(size_9==0x0101){
        roc_status_vec_9.push_back(5);
      }else if(size_9==0x0108){
        roc_status_vec_9.push_back(9);
      }else if(size_9==0x0508){
        roc_status_vec_9.push_back(13);
      }else if(size_9==0x0180){
	roc_status_vec_9.push_back(17);

      }else{
	roc_status_vec_9.push_back(21);

      }

        roc_not_empty_9=0;

	printf("ROC STATUS");

    }
    loc_9 += 1;
    if (loc_9 == 8) {
       printf("\n");
        loc_9  = 0;
    }
    if((line_number_dtc_9+dtc_size_9-1)==lines_count_9 ){
        dtc_size_9=-1;
        Hist_NUM_ROCS_9->Fill(NUM_ROC_9);
        NUM_ROC_9=0;
    }
    if((line_number_roc_9+roc_size_9-1)==lines_count_9 ){
        roc_size_9=-1;

    }
 
    k_9++;
}
 printf("\n");
 printf("TOTAL NUMBER OF LINES %d\n",lines_count_9);
 printf("TOTAL NUMBER OF EVENTS %d\n",size(dtc_size_vec_9));
 printf("TOTAL NUMBER OF ROCS %d\n",num_roc_9);


 printf("TOTAL NUMBER OF ROCS  status %d\n",size(roc_status_vec_9));
printf("TOTAL NUMBER OF ROCS  size %d\n",size(roc_size_vec_9));
tot_dtc_size_9/=(size(dtc_size_vec_9));
tot_roc_size_9/=(size(roc_status_vec_9));



 for(int i=0;i<size(dtc_size_vec_9);i++){
   Hist_dtc_event_size_9->Fill(dtc_size_vec_9.at(i));
    Hist_residual_dtc_size_9->Fill(dtc_size_vec_9.at(i)-tot_dtc_size_9);
    Hist_event_vs_dtc_size_9->Fill( dtc_tag_vec_9.at(i),dtc_size_vec_9.at(i)-tot_dtc_size_9);
    Hist_event_vs_dtc_tag_9->Fill(dtc_tag_vec_9.at(i),dtc_tag_vec_9.at(i));

   
}

 for(int i=0;i<size(roc_status_vec_9);i++){
   if(roc_size_vec_9.at(i)==-1) {
 Hist_roc_size_vs_line_number_roc_9->Fill(1,line_number_roc_vec_9.at(i));
   Hist_line_number_roc_9->Fill(line_number_roc_vec_9.at(i));
   Hist_roc_size_9->Fill(1);
   // Hist_event_vs_roc_size_9->Fill(dtc_tag_vec_9.at(i),1);
   Hist_roc_status_9->Fill(roc_status_vec_9.at(i));
   // Hist_event_vs_roc_status_9->Fill(dtc_tag_vec_9.at(i),roc_status_vec_9.at(i));
   Hist_roc_size_vs_roc_status_9->Fill(roc_status_vec_9.at(i),1);
   }else{
   
    Hist_roc_size_vs_line_number_roc_9->Fill(roc_size_vec_9.at(i),line_number_roc_vec_9.at(i));
   Hist_line_number_roc_9->Fill(line_number_roc_vec_9.at(i));
   Hist_roc_size_9->Fill(roc_size_vec_9.at(i));
   //Hist_event_vs_roc_size_9->Fill(dtc_tag_vec_9.at(i),roc_size_vec_9.at(i));
   Hist_roc_status_9->Fill(roc_status_vec_9.at(i));
   //Hist_event_vs_roc_status_9->Fill(dtc_tag_vec_9.at(i),roc_status_vec_9.at(i));
   Hist_roc_size_vs_roc_status_9->Fill(roc_status_vec_9.at(i),roc_size_vec_9.at(i));
   }
  
  
}
printf("TOTAL NUMBER OF ROCS  size %d\n",size(roc_size_vec_9));

 vector<int> rocmean;
 int j=0;
 while(j<size(roc_status_vec_9)){
   int roc1=0;
 for(int i=0;i<64;i++){
   if(roc_size_vec_9.at(i)==-1) {
     roc1+=1;
   }else{
   roc1+=roc_size_vec_9.at(i);
   }
 }

 rocmean.push_back(roc1/64.);

 j=j+64;
 }
 j=0;
 while(j<size(rocmean)){
  for(int i=j;i<j+64;i++){
    Hist_event_vs_roc_size_64->Fill(dtc_tag_vec_9.at(i),roc_size_vec_9.at(i)-rocmean.at(j));
    Hist_roc_size_64->Fill(roc_size_vec_9.at(i)-rocmean.at(j));

  }
 j=j+1;

}


TCanvas * c1600 = new TCanvas("c1600","c1600");
Hist_roc_size_64->SetFillStyle(3005);
 Hist_roc_size_64->SetLineColor(4);


 Hist_roc_size_64->Draw("");
TCanvas * c160 = new TCanvas("c160","c160");
Hist_event_vs_roc_size_64->SetFillStyle(3005);
 Hist_event_vs_roc_size_64->SetLineColor(4);
Hist_event_vs_roc_size_64->SetTitle("ROC Size vs EW Tag");
Hist_event_vs_roc_size_64->GetXaxis()->SetTitle("EW Tag");
Hist_event_vs_roc_size_64->GetYaxis()->SetTitle("ROC size");

 Hist_event_vs_roc_size_64->Draw("");
 TCanvas * c3 = new TCanvas("c3", "c3");
 Hist_num_events_9->Fill((double)num_events_9);
 Hist_num_events_9->SetLineColor(4);
Hist_num_events_9->SetFillStyle(3005);
Hist_num_events_9->SetFillColor(4);
Hist_num_events_9->SetTitle("Number of events Distribution");
Hist_num_events_9->GetXaxis()->SetTitle("number of events");
Hist_num_events_9->GetYaxis()->SetTitle("counts");
Hist_num_events_9->Draw("");
//c3->SaveAs("Hist_num_events.pdf");

TCanvas * c1 = new TCanvas("c1", "c1");
Hist_dtc_event_size_9->SetLineColor(4);
Hist_dtc_event_size_9->SetFillStyle(3005);
Hist_dtc_event_size_9->SetFillColor(4);
Hist_dtc_event_size_9->SetTitle("Event Size Distribution");
Hist_dtc_event_size_9->GetXaxis()->SetTitle("Event Size");
Hist_dtc_event_size_9->GetYaxis()->SetTitle("counts");
Hist_dtc_event_size_9->Draw();

//c1->SaveAs("Hist_dtc_event_size.pdf");

TCanvas * c2 = new TCanvas("c2", "c2");
Hist_line_number_dtc_9->SetLineColor(4);
Hist_line_number_dtc_9->SetFillStyle(3005);
Hist_line_number_dtc_9->SetFillColor(4);
Hist_line_number_dtc_9->Draw();

//TCanvas * c4 = new TCanvas("c4", "c4");
//Hist_dtc_event_size_vs_line_number_dtc_9->SetLineColor(4);
//Hist_dtc_event_size_vs_line_number_dtc_9->Draw("BOX");

TCanvas * c5 = new TCanvas("c5", "c5");
Hist_roc_size_9->SetLineColor(4);
Hist_roc_size_9->SetFillStyle(3005);
Hist_roc_size_9->SetFillColor(4);
Hist_roc_size_9->GetXaxis()->SetRangeUser(1,10000);
Hist_roc_size_64->SetTitle("ROC Size Distribution");
Hist_roc_size_64->GetXaxis()->SetTitle("ROC Size");
Hist_roc_size_64->GetYaxis()->SetTitle("counts");
Hist_roc_size_9->Draw();


TCanvas * c6 = new TCanvas("c6", "c6");
Hist_line_number_roc_9->SetLineColor(4);
Hist_line_number_roc_9->SetFillStyle(3005);
Hist_line_number_roc_9->SetFillColor(4);
Hist_line_number_roc_9->Draw();

TCanvas * c60 = new TCanvas("c60", "c60");
Hist_dtc_tag_vs_event_number_9->SetLineColor(4);
Hist_dtc_tag_vs_event_number_9->SetFillStyle(3005);
Hist_dtc_tag_vs_event_number_9->SetFillColor(4);
Hist_dtc_tag_vs_event_number_9->Draw();

//c2->SaveAs("Hist_dtc_event_size.pdf");
//c4->SaveAs("Hist_dtc_event_size_vs_line_number_dtc.pdf");
//c5->SaveAs("Hist_roc_size.pdf");
//c6->SaveAs("Hist_line_number_roc.pdf");


//TCanvas * c7 = new TCanvas("c7", "c7");
//Hist_NUM_ROCS_9->SetLineColor(4);
//Hist_NUM_ROCS_9->SetFillStyle(3005);
//Hist_NUM_ROCS_9->SetFillColor(4);
//Hist_NUM_ROCS_9->Draw();

TCanvas * c8 = new TCanvas("c8", "c8");
Hist_roc_size_vs_line_number_roc_9->SetLineColor(4);
Hist_roc_size_vs_line_number_roc_9->SetTitle("ROC Size vs Line number");
Hist_roc_size_vs_line_number_roc_9->GetXaxis()->SetTitle("line number");
Hist_roc_size_vs_line_number_roc_9->GetYaxis()->SetTitle("ROC size");
Hist_roc_size_vs_line_number_roc_9->Draw("BOX");

//TCanvas * c9 = new TCanvas("c9", "c9");
//Hist_dtc_size_vs_roc_size_9->SetLineColor(4);
//Hist_dtc_size_vs_roc_size_9->Draw("BOX");

TCanvas * c10 = new TCanvas("c10", "c10");
Hist_dtc_tag_9->SetLineColor(4);
Hist_dtc_tag_9->SetFillStyle(3005);
Hist_dtc_tag_9->SetFillColor(4);
Hist_dtc_tag_9->Draw();


//c7->SaveAs("Hist_NUM_ROCS.pdf");
//c8->SaveAs("Hist_roc_size_vs_line_number_roc.pdf");
//c9->SaveAs("Hist_dtc_size_vs_roc_size.pdf");
//c10->SaveAs("Hist_dtc_tag.pdf");

//TCanvas * c11 = new TCanvas("c11", "c11");
//Hist_residual_dtc_size_9->SetLineColor(4);
//Hist_residual_dtc_size_9->Draw();


//TCanvas * c12 = new TCanvas("c12","c12");
//Hist_event_vs_dtc_size_9->SetLineColor(4);
//Hist_event_vs_dtc_size_9->Draw("BOX");



//c11->SaveAs("Hist_residual_dtc_size.pdf");
//c12->SaveAs("Hist_event_vs_dtc_size.pdf");


//TCanvas * c13 = new TCanvas("c13","c13");
//Hist_event_vs_dtc_tag_9->SetLineColor(4);
//Hist_event_vs_dtc_tag_9->Draw("BOX");

TCanvas * c14 = new TCanvas("c14","c14");
Hist_event_vs_roc_size_9->SetLineColor(4);

Hist_event_vs_roc_size_9->Draw("BOX");

TCanvas * c15 = new TCanvas("c15","c15");
 Hist_event_vs_roc_status_9->SetLineColor(4);
Hist_event_vs_roc_size_9->SetTitle("ROC Status vs EW tag");
Hist_event_vs_roc_size_9->GetXaxis()->SetTitle("EW tag");
Hist_event_vs_roc_size_9->GetYaxis()->SetTitle("ROC status");
Hist_event_vs_roc_status_9->Draw("BOX");

TCanvas * c16 = new TCanvas("c16","c16");
Hist_roc_size_vs_roc_status_9->SetLineColor(4);
Hist_roc_size_vs_roc_status_9->SetTitle("ROC Size vs ROC status");
Hist_roc_size_vs_roc_status_9->GetXaxis()->SetTitle("ROC status");
Hist_roc_size_vs_roc_status_9->GetYaxis()->SetTitle("ROC size");
Hist_roc_size_vs_roc_status_9->Draw("");

//TCanvas * c17 = new TCanvas("c17","c17");
//TProfile* p_9=Hist_event_vs_dtc_size_9->ProfileX();
//p_9->SetFillStyle(3005);
//p_9->SetFillColor(4);
//p_9->SetLineColor(4);
//p_9->Draw("");


TCanvas * c18 = new TCanvas("c18", "c18");
Hist_roc_status_9->SetLineColor(4);
Hist_roc_status_9->Draw();
TCanvas * c19 = new TCanvas("c19", "c19");
Hist_dtc_tag_vs_dtc_tag_minus_1_9->SetLineColor(4);
Hist_dtc_tag_vs_dtc_tag_minus_1_9->SetTitle("#Delta EW tag[i]-[i-1]");
Hist_dtc_tag_vs_dtc_tag_minus_1_9->GetXaxis()->SetTitle("#Delta EW tag");
Hist_dtc_tag_vs_dtc_tag_minus_1_9->GetYaxis()->SetTitle("counts");
Hist_dtc_tag_vs_dtc_tag_minus_1_9->Draw();
//c13->SaveAs("Hist_event_vs_dtc_tag.pdf");
//c14->SaveAs("Hist_event_vs_roc_size.pdf");
//c15->SaveAs("Hist_event_vs_roc_status.pdf");
//c16->SaveAs("Hist_roc_size_vs_roc_status.pdf");
//c17->SaveAs("Hist_event_vs_dtc.pdf");
//c18->SaveAs("Hist_roc_status.pdf");

 results  NewResults;
 NewResults.number_of_100=0;
 NewResults.number_of_180=0;
 NewResults.number_of_508=0;
 NewResults.number_of_101=0;
 NewResults.number_of_108=0;
 NewResults.number_of_other_errors=0;
 NewResults.number_of_events=size(dtc_size_vec_9);
printf("TOTAL NUMBER OF ROCS  size %d\n",NewResults.number_of_events);

 for(int i=0;i<size(roc_status_vec_9);i++){
   if(roc_status_vec_9.at(i)==1){
         NewResults.number_of_100++;
      }else if(roc_status_vec_9.at(i)==5){
         NewResults.number_of_101++;
      }else if(roc_status_vec_9.at(i)==9){
         NewResults.number_of_108++;
      }else if(roc_status_vec_9.at(i)==13){
        NewResults.number_of_508++;
      }else if(roc_status_vec_9.at(i)==17){
	 NewResults.number_of_180++;
      }else{
         NewResults.number_of_other_errors++;
      }



 }
 NewResults.number_of_start=start_number;
 printf("FILE COMPLETED\n");
 for(int i=0;i<size(ew_tag_wrong);i++)  printf("TOTAL NUMBER OF ROCS  error in tag  %d\n",ew_tag_wrong.at(i));

  if (in9.bad()) {
    std::cerr << "Error reading from file" << std::endl;
  }
  in9.close(); 
    return NewResults;
}
void printfile(string filename){
  results run6_ex= process(filename);
  printf("NUM EVE %d",run6_ex.number_of_events);
  printf("NUM EVE %d",run6_ex.number_of_start);

}
void open1file(){
  results run2_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/val/emulated_cf0_10000_mu2edaq09_0002.dat");
  results run3_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/val/emulated_cf0_10000_mu2edaq09_0003.dat");
  results run4_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/val/emulated_cf0_10000_mu2edaq09_0004.dat");
  results run5_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/val/emulated_cf0_10000_mu2edaq09_0005.dat");
  results run6_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/val/emulated_cf0_10000_mu2edaq09_0006.dat");
  results run7_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/val/emulated_cf0_10000_mu2edaq09_0007.dat");
  results run8_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/val/emulated_cf0_10000_mu2edaq09_0008.dat");
  results run1_ex= process("/exp/mu2e/data/projects/tracker/vst/datasets/val/external_cf0_10000_mu2edaq09_0001.dat");
  results run2_ex= process("/exp/mu2e/data/projects/tracker/vst/datasets/val/external_cf0_10000_mu2edaq09_0002.dat");
  results run3_ex= process("/exp/mu2e/data/projects/tracker/vst/datasets/val/external_cf0_10000_mu2edaq09_0003.dat");
  results run4_ex= process("/exp/mu2e/data/projects/tracker/vst/datasets/val/external_cf0_10000_mu2edaq09_0004.dat");
  results run5_ex= process("/exp/mu2e/data/projects/tracker/vst/datasets/val/external_cf0_10000_mu2edaq09_0005.dat");
  results run6_ex= process("/exp/mu2e/data/projects/tracker/vst/datasets/val/external_cf0_10000_mu2edaq09_0006.dat");
  results run7_ex= process("/exp/mu2e/data/projects/tracker/vst/datasets/val/external_cf0_10000_mu2edaq09_0007.dat");
  results run8_ex= process("/exp/mu2e/data/projects/tracker/vst/datasets/val/external_cf0_10000_mu2edaq09_0008.dat");
  results run9_ex= process("/exp/mu2e/data/projects/tracker/vst/datasets/val/external_cf0_10000_mu2edaq09_0009.dat");
  results run10_ex= process("/exp/mu2e/data/projects/tracker/vst/datasets/val/external_cf0_10000_mu2edaq09_0010.dat");
  vector<int> number_of_events_em{run2_em.number_of_events,run3_em.number_of_events,run4_em.number_of_events,run5_em.number_of_events,run6_em.number_of_events,run7_em.number_of_events,run8_em.number_of_events};
  vector<int> number_of_100_em{run2_em.number_of_100,run3_em.number_of_100,run4_em.number_of_100,run5_em.number_of_100,run6_em.number_of_100,run7_em.number_of_100,run8_em.number_of_100};
  vector<int> number_of_101_em{run2_em.number_of_101,run3_em.number_of_101,run4_em.number_of_101,run5_em.number_of_101,run6_em.number_of_101,run7_em.number_of_101,run8_em.number_of_101};
  vector<int> number_of_108_em{run2_em.number_of_108,run3_em.number_of_108,run4_em.number_of_108,run5_em.number_of_108,run6_em.number_of_108,run7_em.number_of_108,run8_em.number_of_108};
  vector<int> number_of_180_em{run2_em.number_of_180,run3_em.number_of_180,run4_em.number_of_180,run5_em.number_of_180,run6_em.number_of_180,run7_em.number_of_180,run8_em.number_of_180};
  vector<int> number_of_508_em{run2_em.number_of_508,run3_em.number_of_508,run4_em.number_of_508,run5_em.number_of_508,run6_em.number_of_508,run7_em.number_of_508,run8_em.number_of_508};
  vector<int> number_of_other_errors_em{run2_em.number_of_other_errors,run3_em.number_of_other_errors,run4_em.number_of_other_errors,run5_em.number_of_other_errors,run6_em.number_of_other_errors,run7_em.number_of_other_errors,run8_em.number_of_other_errors};
  vector<int> number_of_start_em{run2_em.number_of_start,run3_em.number_of_start,run4_em.number_of_start,run5_em.number_of_start,run6_em.number_of_start,run7_em.number_of_start,run8_em.number_of_start};
  vector<int> trial_em{2,3,4,5,6,7,8};
  vector<int> trial_ex{1,2,3,4,5,6,7,8,9,10};

  vector<int> number_of_events_ex{run1_ex.number_of_events,run2_ex.number_of_events,run3_ex.number_of_events,run4_ex.number_of_events,run5_ex.number_of_events,run6_ex.number_of_events,run7_ex.number_of_events,run8_ex.number_of_events,run9_ex.number_of_events,run10_ex.number_of_events};
  vector<int> number_of_100_ex{run1_ex.number_of_100,run2_ex.number_of_100,run3_ex.number_of_100,run4_ex.number_of_100,run5_ex.number_of_100,run6_ex.number_of_100,run7_ex.number_of_100,run8_ex.number_of_100,run9_ex.number_of_100,run10_ex.number_of_100};
  vector<int> number_of_101_ex{run1_ex.number_of_101,run2_ex.number_of_101,run3_ex.number_of_101,run4_ex.number_of_101,run5_ex.number_of_101,run6_ex.number_of_101,run7_ex.number_of_101,run8_ex.number_of_101,run9_ex.number_of_101,run10_ex.number_of_101};
  vector<int> number_of_108_ex{run1_ex.number_of_108,run2_ex.number_of_108,run3_ex.number_of_108,run4_ex.number_of_108,run5_ex.number_of_108,run6_ex.number_of_108,run7_ex.number_of_108,run8_ex.number_of_108,run9_ex.number_of_108,run10_ex.number_of_108};
  vector<int> number_of_180_ex{run1_ex.number_of_180,run2_ex.number_of_180,run3_ex.number_of_180,run4_ex.number_of_180,run5_ex.number_of_180,run6_ex.number_of_180,run7_ex.number_of_180,run8_ex.number_of_180,run9_ex.number_of_180,run10_ex.number_of_180};
  vector<int> number_of_508_ex{run1_ex.number_of_508,run2_ex.number_of_508,run3_ex.number_of_508,run4_ex.number_of_508,run5_ex.number_of_508,run6_ex.number_of_508,run7_ex.number_of_508,run8_ex.number_of_508,run9_ex.number_of_508,run10_ex.number_of_508};
  vector<int> number_of_other_errors_ex{run1_ex.number_of_other_errors,run2_ex.number_of_other_errors,run3_ex.number_of_other_errors,run4_ex.number_of_other_errors,run5_ex.number_of_other_errors,run6_ex.number_of_other_errors,run7_ex.number_of_other_errors,run8_ex.number_of_other_errors,run9_ex.number_of_other_errors,run10_ex.number_of_other_errors};
  vector<int> number_of_start_ex{run1_ex.number_of_start,run2_ex.number_of_start,run3_ex.number_of_start,run4_ex.number_of_start,run5_ex.number_of_start,run6_ex.number_of_start,run7_ex.number_of_start,run8_ex.number_of_start,run10_ex.number_of_start,run10_ex.number_of_start};

  TCanvas * c_n_e_0 = new TCanvas("c_n_e","c_n_e");
  TGraph *number_of_events_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_events_em[0]));
  number_of_events_em_gr->SetTitle("Emulated CFO: Number of events");
number_of_events_em_gr->SetMarkerStyle(20);
  number_of_events_em_gr->Draw();
c_n_e_0->SaveAs("emulated_num_events.pdf");
  TCanvas * c_n_e_1 = new TCanvas("c_n_e_1","c_n_e_1");
  TGraph *number_of_100_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_100_em[0]));
  number_of_100_em_gr->SetTitle("number of 0x100 emulated");
 number_of_100_em_gr->SetMarkerStyle(20);
  number_of_100_em_gr->Draw();
c_n_e_1->SaveAs("emulated_num_100.pdf");

  TCanvas * c_n_e_2 = new TCanvas("c_n_e_2","c_n_e_2");
  TGraph *number_of_101_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_101_em[0]));
  number_of_101_em_gr->SetTitle("number of 101 emulated");
number_of_101_em_gr->SetMarkerStyle(20);
  number_of_101_em_gr->Draw();
c_n_e_2->SaveAs("emulated_num_101.pdf");

  TCanvas * c_n_e_3 = new TCanvas("c_n_e_3","c_n_e_3");
  TGraph *number_of_108_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_108_em[0]));
  number_of_108_em_gr->SetTitle("number of 108 emulated");
number_of_108_em_gr->SetMarkerStyle(20);
  number_of_108_em_gr->Draw();
c_n_e_3->SaveAs("emulated_num_108.pdf");

  TCanvas * c_n_e_4 = new TCanvas("c_n_e_4","c_n_e_4");
  TGraph *number_of_180_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_180_em[0]));
  number_of_180_em_gr->SetTitle("number of 180 emulated");
number_of_180_em_gr->SetMarkerStyle(20);
  number_of_180_em_gr->Draw();
c_n_e_4->SaveAs("emulated_num_180.pdf");

  TCanvas * c_n_e_5 = new TCanvas("c_n_e_5","c_n_e_5");
  TGraph *number_of_508_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_508_em[0]));
  number_of_508_em_gr->SetTitle("number of 508 emulated");
number_of_508_em_gr->SetMarkerStyle(20);
  number_of_508_em_gr->Draw();
c_n_e_5->SaveAs("emulated_num_508.pdf");

  TCanvas * c_n_e_6 = new TCanvas("c_n_e_6","c_n_e_6");
  TGraph *number_of_other_errors_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_other_errors_em[0]));
  number_of_other_errors_em_gr->SetTitle("number of other_errors emulated");
 number_of_other_errors_em_gr->SetMarkerStyle(20);
  number_of_other_errors_em_gr->Draw();
c_n_e_6->SaveAs("emulated_num_oth_err.pdf");

  TCanvas * c_n_e_7 = new TCanvas("c_n_e_7","c_n_e_7");
  TGraph *number_of_start_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_start_em[0]));
  number_of_start_em_gr->SetTitle("number of start emulated");
 number_of_start_em_gr->SetMarkerStyle(20);
  number_of_start_em_gr->Draw();
c_n_e_7->SaveAs("emulated_num_start.pdf");


  TCanvas * c_n_e_e_0 = new TCanvas("c_n_e_e","c_n_e_e");
  TGraph *number_of_events_ex_gr=new TGraph(size(trial_ex),&(trial_ex[0]),&(number_of_events_ex[0]));
  number_of_events_ex_gr->SetTitle("External CFO: number of events");
number_of_events_ex_gr->SetMarkerStyle(20);
  number_of_events_ex_gr->Draw();
c_n_e_e_0->SaveAs("external_num_events.pdf");

  TCanvas * c_n_e_e_1 = new TCanvas("c_n_e_e_1","c_n_e_e_1");
  TGraph *number_of_100_ex_gr=new TGraph(size(trial_ex),&(trial_ex[0]),&(number_of_100_ex[0]));
  number_of_100_ex_gr->SetTitle("number of 0x100 external");
number_of_100_ex_gr->SetMarkerStyle(20);
  number_of_100_ex_gr->Draw();
c_n_e_e_1->SaveAs("external_num_100.pdf");

  TCanvas * c_n_e_e_2 = new TCanvas("c_n_e_e_2","c_n_e_e_2");
  TGraph *number_of_101_ex_gr=new TGraph(size(trial_ex),&(trial_ex[0]),&(number_of_101_ex[0]));
  number_of_101_ex_gr->SetTitle("number of 101 external");
number_of_101_ex_gr->SetMarkerStyle(20);
  number_of_101_ex_gr->Draw();
c_n_e_e_2->SaveAs("external_num_101.pdf");

  TCanvas * c_n_e_e_3 = new TCanvas("c_n_e_e_3","c_n_e_e_3");
  TGraph *number_of_108_ex_gr=new TGraph(size(trial_ex),&(trial_ex[0]),&(number_of_108_ex[0]));
  number_of_108_ex_gr->SetTitle("number of 108 external");
 number_of_108_ex_gr->SetMarkerStyle(20);
  number_of_108_ex_gr->Draw();
c_n_e_e_3->SaveAs("external_num_108.pdf");

  TCanvas * c_n_e_e_4 = new TCanvas("c_n_e_e_4","c_n_e_e_4");
  TGraph *number_of_180_ex_gr=new TGraph(size(trial_ex),&(trial_ex[0]),&(number_of_180_ex[0]));
  number_of_180_ex_gr->SetTitle("number of 180 external");
number_of_180_ex_gr->SetMarkerStyle(20);
  number_of_180_ex_gr->Draw();
c_n_e_e_4->SaveAs("external_num_180.pdf");

  TCanvas * c_n_e_e_5 = new TCanvas("c_n_e_e_5","c_n_e_e_5");
  TGraph *number_of_508_ex_gr=new TGraph(size(trial_ex),&(trial_ex[0]),&(number_of_508_ex[0]));
  number_of_508_ex_gr->SetTitle("number of 508 external");
number_of_508_ex_gr->SetMarkerStyle(20);
  number_of_508_ex_gr->Draw();

  TCanvas * c_n_e_e_6 = new TCanvas("c_n_e_e_6","c_n_e_e_6");
  TGraph *number_of_other_errors_ex_gr=new TGraph(size(trial_ex),&(trial_ex[0]),&(number_of_other_errors_ex[0]));
  number_of_other_errors_ex_gr->SetTitle("number of other_errors external");
number_of_other_errors_ex_gr->SetMarkerStyle(20);
  number_of_other_errors_ex_gr->Draw();
c_n_e_e_6->SaveAs("external_num_oth.pdf");

  TCanvas * c_n_e_e_7 = new TCanvas("c_n_e_e_7","c_n_e_e_7");
  TGraph *number_of_start_ex_gr=new TGraph(size(trial_ex),&(trial_ex[0]),&(number_of_start_ex[0]));
  number_of_start_ex_gr->SetTitle("number of start external");

  gStyle->SetOptStat(11111111);
  number_of_start_ex_gr->SetMarkerStyle(20);
  number_of_start_ex_gr->Draw();
c_n_e_e_7->SaveAs("external_num_start.pdf");

}



void open_file_em_10k(){
  results run1_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/emulated_10000.001");
  results run2_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/emulated_10000.002");
  results run3_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/emulated_10000.003");
  results run4_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/emulated_10000.004");
  results run5_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/emulated_10000.005");
  results run6_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/emulated_10000.006");
  results run7_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/emulated_10000.007");
  results run8_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/emulated_10000.008");
  results run9_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/emulated_10000.009");
  results run10_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/emulated_10000.010");
  results run11_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/emulated_10000.011");
  results run12_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/emulated_10000.012");
  results run13_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/emulated_10000.013");
  results run14_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/emulated_10000.014");
  results run15_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/emulated_10000.015");
  results run16_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/emulated_10000.016");
  results run17_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/emulated_10000.017");
  results run18_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/emulated_10000.018");
  results run19_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/emulated_10000.019");
  results run20_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/emulated_10000.020");
 
  vector<int> number_of_events_em{run1_em.number_of_events,run2_em.number_of_events,run3_em.number_of_events,run4_em.number_of_events,run5_em.number_of_events,run6_em.number_of_events,run7_em.number_of_events,run8_em.number_of_events,run9_em.number_of_events,run10_em.number_of_events,run11_em.number_of_events,run12_em.number_of_events,run13_em.number_of_events,run14_em.number_of_events,run15_em.number_of_events,run16_em.number_of_events,run17_em.number_of_events,run18_em.number_of_events,run19_em.number_of_events,run20_em.number_of_events};
  vector<int> number_of_100_em{run1_em.number_of_100,run2_em.number_of_100,run3_em.number_of_100,run4_em.number_of_100,run5_em.number_of_100,run6_em.number_of_100,run7_em.number_of_100,run8_em.number_of_100,run9_em.number_of_100,run10_em.number_of_100,run11_em.number_of_100,run12_em.number_of_100,run13_em.number_of_100,run14_em.number_of_100,run15_em.number_of_100,run16_em.number_of_100,run17_em.number_of_100,run18_em.number_of_100,run19_em.number_of_100,run20_em.number_of_100};
  vector<int> number_of_101_em{run1_em.number_of_101,run2_em.number_of_101,run3_em.number_of_101,run4_em.number_of_101,run5_em.number_of_101,run6_em.number_of_101,run7_em.number_of_101,run8_em.number_of_101,run9_em.number_of_101,run10_em.number_of_101,run11_em.number_of_101,run12_em.number_of_101,run13_em.number_of_101,run14_em.number_of_101,run15_em.number_of_101,run16_em.number_of_101,run17_em.number_of_101,run18_em.number_of_101,run19_em.number_of_101,run20_em.number_of_101};
  vector<int> number_of_108_em{run1_em.number_of_108,run2_em.number_of_108,run3_em.number_of_108,run4_em.number_of_108,run5_em.number_of_108,run6_em.number_of_108,run7_em.number_of_108,run8_em.number_of_108,run9_em.number_of_108,run10_em.number_of_108,run11_em.number_of_108,run12_em.number_of_108,run13_em.number_of_108,run14_em.number_of_108,run15_em.number_of_108,run16_em.number_of_108,run17_em.number_of_108,run18_em.number_of_108,run19_em.number_of_108,run20_em.number_of_108};
  vector<int> number_of_180_em{run1_em.number_of_180,run2_em.number_of_180,run3_em.number_of_180,run4_em.number_of_180,run5_em.number_of_180,run6_em.number_of_180,run7_em.number_of_180,run8_em.number_of_180,run9_em.number_of_180,run10_em.number_of_180,run11_em.number_of_180,run12_em.number_of_180,run13_em.number_of_180,run14_em.number_of_180,run15_em.number_of_180,run16_em.number_of_180,run17_em.number_of_180,run18_em.number_of_180,run19_em.number_of_180,run20_em.number_of_180};
  vector<int> number_of_508_em{run1_em.number_of_508,run2_em.number_of_508,run3_em.number_of_508,run4_em.number_of_508,run5_em.number_of_508,run6_em.number_of_508,run7_em.number_of_508,run8_em.number_of_508,run9_em.number_of_508,run10_em.number_of_508,run11_em.number_of_508,run12_em.number_of_508,run13_em.number_of_508,run14_em.number_of_508,run15_em.number_of_508,run16_em.number_of_508,run17_em.number_of_508,run18_em.number_of_508,run19_em.number_of_508,run20_em.number_of_508};
  vector<int> number_of_other_errors_em{run1_em.number_of_other_errors,run2_em.number_of_other_errors,run3_em.number_of_other_errors,run4_em.number_of_other_errors,run5_em.number_of_other_errors,run6_em.number_of_other_errors,run7_em.number_of_other_errors,run8_em.number_of_other_errors,run9_em.number_of_other_errors,run10_em.number_of_other_errors,run11_em.number_of_other_errors,run12_em.number_of_other_errors,run13_em.number_of_other_errors,run14_em.number_of_other_errors,run15_em.number_of_other_errors,run16_em.number_of_other_errors,run17_em.number_of_other_errors,run18_em.number_of_other_errors,run19_em.number_of_other_errors,run20_em.number_of_other_errors};
  vector<int> number_of_start_em{run1_em.number_of_start,run2_em.number_of_start,run3_em.number_of_start,run4_em.number_of_start,run5_em.number_of_start,run6_em.number_of_start,run7_em.number_of_start,run8_em.number_of_start,run9_em.number_of_start,run10_em.number_of_start,run11_em.number_of_start,run12_em.number_of_start,run13_em.number_of_start,run14_em.number_of_start,run15_em.number_of_start,run16_em.number_of_start,run17_em.number_of_start,run18_em.number_of_start,run19_em.number_of_start,run20_em.number_of_start};
  vector<int> trial_em{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

  TCanvas * c_n_e_0 = new TCanvas("c_n_e","c_n_e");
  TGraph *number_of_events_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_events_em[0]));
  number_of_events_em_gr->SetTitle("Emulated CFO, 10k: Number of events");
number_of_events_em_gr->SetMarkerStyle(20);
number_of_events_em_gr->GetXaxis()->SetTitle("run number");
number_of_events_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_events_em_gr->Draw();
c_n_e_0->SaveAs("emulated_10k_num_events.pdf");
  TCanvas * c_n_e_1 = new TCanvas("c_n_e_1","c_n_e_1");
  TGraph *number_of_100_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_100_em[0]));
  number_of_100_em_gr->SetTitle("Emulated CFO, 10k: number of 0x100");
 number_of_100_em_gr->SetMarkerStyle(20);
number_of_100_em_gr->GetXaxis()->SetTitle("run number");
number_of_100_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_100_em_gr->Draw();
c_n_e_1->SaveAs("emulated_10k_num_100.pdf");

  TCanvas * c_n_e_2 = new TCanvas("c_n_e_2","c_n_e_2");
  TGraph *number_of_101_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_101_em[0]));
  number_of_101_em_gr->SetTitle("Emulated CFO, 10k: number of 0x0101");
number_of_101_em_gr->SetMarkerStyle(20);
number_of_101_em_gr->GetXaxis()->SetTitle("run number");
number_of_101_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_101_em_gr->Draw();
c_n_e_2->SaveAs("emulated_10k_num_101.pdf");

  TCanvas * c_n_e_3 = new TCanvas("c_n_e_3","c_n_e_3");
  TGraph *number_of_108_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_108_em[0]));
  number_of_108_em_gr->SetTitle("Emulated CFO, 10k: number of 0x0108");
number_of_108_em_gr->SetMarkerStyle(20);
number_of_108_em_gr->GetXaxis()->SetTitle("run number");
number_of_108_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_108_em_gr->Draw();
c_n_e_3->SaveAs("emulated_10k_num_108.pdf");

  TCanvas * c_n_e_4 = new TCanvas("c_n_e_4","c_n_e_4");
  TGraph *number_of_180_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_180_em[0]));
  number_of_180_em_gr->SetTitle("Emulated CFO, 10k: number of 0x0180");
number_of_180_em_gr->SetMarkerStyle(20);
number_of_180_em_gr->GetXaxis()->SetTitle("run number");
number_of_180_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_180_em_gr->Draw();
c_n_e_4->SaveAs("emulated_10k_num_180.pdf");

  TCanvas * c_n_e_5 = new TCanvas("c_n_e_5","c_n_e_5");
  TGraph *number_of_508_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_508_em[0]));
  number_of_508_em_gr->SetTitle("Emulated CFO, 10k: number of 0x0508");
number_of_508_em_gr->SetMarkerStyle(20);
number_of_508_em_gr->GetXaxis()->SetTitle("run number");
number_of_508_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_508_em_gr->Draw();
c_n_e_5->SaveAs("emulated_10k_num_508.pdf");

  TCanvas * c_n_e_6 = new TCanvas("c_n_e_6","c_n_e_6");
  TGraph *number_of_other_errors_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_other_errors_em[0]));
  number_of_other_errors_em_gr->SetTitle("Emulated CFO, 10k: other errors");
 number_of_other_errors_em_gr->SetMarkerStyle(20);
number_of_other_errors_em_gr->GetXaxis()->SetTitle("run number");
number_of_other_errors_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_other_errors_em_gr->Draw();
c_n_e_6->SaveAs("emulated_10k_num_oth_err.pdf");

  TCanvas * c_n_e_7 = new TCanvas("c_n_e_7","c_n_e_7");
  TGraph *number_of_start_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_start_em[0]));
  number_of_start_em_gr->SetTitle("Emulated CFO, 10k: first event tag");
 number_of_start_em_gr->SetMarkerStyle(20);
number_of_start_em_gr->GetXaxis()->SetTitle("run number");
number_of_start_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_start_em_gr->Draw();
c_n_e_7->SaveAs("emulated_10k_num_start.pdf");


}

void open_file_ex_66(){
  results run1_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0066.001");
  results run2_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0066.002");
  results run3_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0066.003");
  results run4_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0066.004");
  results run5_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0066.005");
  results run6_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0066.006");
  results run7_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0066.007");
  results run8_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0066.008");
  results run9_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0066.009");
  results run10_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0066.010");
  results run11_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0066.011");
  results run12_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0066.012");
 
  vector<int> number_of_events_em{run1_em.number_of_events,run2_em.number_of_events,run3_em.number_of_events,run4_em.number_of_events,run5_em.number_of_events,run6_em.number_of_events,run7_em.number_of_events,run8_em.number_of_events,run9_em.number_of_events,run10_em.number_of_events,run11_em.number_of_events,run12_em.number_of_events};
  vector<int> number_of_100_em{run1_em.number_of_100,run2_em.number_of_100,run3_em.number_of_100,run4_em.number_of_100,run5_em.number_of_100,run6_em.number_of_100,run7_em.number_of_100,run8_em.number_of_100,run9_em.number_of_100,run10_em.number_of_100,run11_em.number_of_100,run12_em.number_of_100};
  vector<int> number_of_101_em{run1_em.number_of_101,run2_em.number_of_101,run3_em.number_of_101,run4_em.number_of_101,run5_em.number_of_101,run6_em.number_of_101,run7_em.number_of_101,run8_em.number_of_101,run9_em.number_of_101,run10_em.number_of_101,run11_em.number_of_101,run12_em.number_of_101};
  vector<int> number_of_108_em{run1_em.number_of_108,run2_em.number_of_108,run3_em.number_of_108,run4_em.number_of_108,run5_em.number_of_108,run6_em.number_of_108,run7_em.number_of_108,run8_em.number_of_108,run9_em.number_of_108,run10_em.number_of_108,run11_em.number_of_108,run12_em.number_of_108};
  vector<int> number_of_180_em{run1_em.number_of_180,run2_em.number_of_180,run3_em.number_of_180,run4_em.number_of_180,run5_em.number_of_180,run6_em.number_of_180,run7_em.number_of_180,run8_em.number_of_180,run9_em.number_of_180,run10_em.number_of_180,run11_em.number_of_180,run12_em.number_of_180};
  vector<int> number_of_508_em{run1_em.number_of_508,run2_em.number_of_508,run3_em.number_of_508,run4_em.number_of_508,run5_em.number_of_508,run6_em.number_of_508,run7_em.number_of_508,run8_em.number_of_508,run9_em.number_of_508,run10_em.number_of_508,run11_em.number_of_508,run12_em.number_of_508};
  vector<int> number_of_other_errors_em{run1_em.number_of_other_errors,run2_em.number_of_other_errors,run3_em.number_of_other_errors,run4_em.number_of_other_errors,run5_em.number_of_other_errors,run6_em.number_of_other_errors,run7_em.number_of_other_errors,run8_em.number_of_other_errors,run9_em.number_of_other_errors,run10_em.number_of_other_errors,run11_em.number_of_other_errors,run12_em.number_of_other_errors};
  vector<int> number_of_start_em{run1_em.number_of_start,run2_em.number_of_start,run3_em.number_of_start,run4_em.number_of_start,run5_em.number_of_start,run6_em.number_of_start,run7_em.number_of_start,run8_em.number_of_start,run9_em.number_of_start,run10_em.number_of_start,run11_em.number_of_start,run12_em.number_of_start};
  vector<int> trial_em{1,2,3,4,5,6,7,8,9,10,11,12};

  TCanvas * c_n_e_0 = new TCanvas("c_n_e","c_n_e");
  TGraph *number_of_events_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_events_em[0]));
  number_of_events_em_gr->SetTitle("External CFO, 66: Number of events");
number_of_events_em_gr->SetMarkerStyle(20);
number_of_events_em_gr->GetXaxis()->SetTitle("run number");
number_of_events_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_events_em_gr->Draw();
c_n_e_0->SaveAs("external_66events_num_events.pdf");
  TCanvas * c_n_e_1 = new TCanvas("c_n_e_1","c_n_e_1");
  TGraph *number_of_100_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_100_em[0]));
  number_of_100_em_gr->SetTitle("External CFO, 66: number of 0x0100");
 number_of_100_em_gr->SetMarkerStyle(20);
number_of_100_em_gr->GetXaxis()->SetTitle("run number");
number_of_100_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_100_em_gr->Draw();
c_n_e_1->SaveAs("external_66events_num_100.pdf");

  TCanvas * c_n_e_2 = new TCanvas("c_n_e_2","c_n_e_2");
  TGraph *number_of_101_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_101_em[0]));
  number_of_101_em_gr->SetTitle("External CFO, 66: number of 0x0101");
number_of_101_em_gr->SetMarkerStyle(20);
  number_of_101_em_gr->Draw();
c_n_e_2->SaveAs("external_66events_num_101.pdf");

  TCanvas * c_n_e_3 = new TCanvas("c_n_e_3","c_n_e_3");
  TGraph *number_of_108_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_108_em[0]));
  number_of_108_em_gr->SetTitle("External CFO, 66: number of 0x0108");
number_of_108_em_gr->SetMarkerStyle(20);
number_of_108_em_gr->GetXaxis()->SetTitle("run number");
number_of_108_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_108_em_gr->Draw();
c_n_e_3->SaveAs("external_66events_num_108.pdf");

  TCanvas * c_n_e_4 = new TCanvas("c_n_e_4","c_n_e_4");
  TGraph *number_of_180_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_180_em[0]));
  number_of_180_em_gr->SetTitle("External CFO, 66: number of 0x0180");
number_of_180_em_gr->SetMarkerStyle(20);
number_of_180_em_gr->GetXaxis()->SetTitle("run number");
number_of_180_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_180_em_gr->Draw();
c_n_e_4->SaveAs("external_66events_num_180.pdf");

  TCanvas * c_n_e_5 = new TCanvas("c_n_e_5","c_n_e_5");
  TGraph *number_of_508_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_508_em[0]));
  number_of_508_em_gr->SetTitle("External CFO, 66: number of 0x0508");
number_of_508_em_gr->SetMarkerStyle(20);
number_of_508_em_gr->GetXaxis()->SetTitle("run number");
number_of_508_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_508_em_gr->Draw();
c_n_e_5->SaveAs("external_66events_num_508.pdf");

  TCanvas * c_n_e_6 = new TCanvas("c_n_e_6","c_n_e_6");
  TGraph *number_of_other_errors_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_other_errors_em[0]));
  number_of_other_errors_em_gr->SetTitle("External CFO, 66: number of other errors");
 number_of_other_errors_em_gr->SetMarkerStyle(20);
number_of_other_errors_em_gr->GetXaxis()->SetTitle("run number");
number_of_other_errors_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_other_errors_em_gr->Draw();
c_n_e_6->SaveAs("external_66events_num_oth_err.pdf");

  TCanvas * c_n_e_7 = new TCanvas("c_n_e_7","c_n_e_7");
  TGraph *number_of_start_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_start_em[0]));
  number_of_start_em_gr->SetTitle("External CFO, 66: first event tag");
 number_of_start_em_gr->SetMarkerStyle(20);
number_of_start_em_gr->GetXaxis()->SetTitle("run number");
number_of_start_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_start_em_gr->Draw();
c_n_e_7->SaveAs("external_66events_num_start.pdf");



}

















void open_file_ex_130(){
  results run1_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0130.001");
  results run2_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0130.002");
  results run3_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0130.003");
  results run4_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0130.004");
  results run5_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0130.005");
  results run6_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0130.006");
  results run7_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0130.007");
  results run8_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0130.008");
  results run9_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0130.009");
  results run10_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0130.010");
 
  vector<int> number_of_events_em{run1_em.number_of_events,run2_em.number_of_events,run3_em.number_of_events,run4_em.number_of_events,run5_em.number_of_events,run6_em.number_of_events,run7_em.number_of_events,run8_em.number_of_events,run9_em.number_of_events,run10_em.number_of_events};
  vector<int> number_of_100_em{run1_em.number_of_100,run2_em.number_of_100,run3_em.number_of_100,run4_em.number_of_100,run5_em.number_of_100,run6_em.number_of_100,run7_em.number_of_100,run8_em.number_of_100,run9_em.number_of_100,run10_em.number_of_100};
  vector<int> number_of_101_em{run1_em.number_of_101,run2_em.number_of_101,run3_em.number_of_101,run4_em.number_of_101,run5_em.number_of_101,run6_em.number_of_101,run7_em.number_of_101,run8_em.number_of_101,run9_em.number_of_101,run10_em.number_of_101};
  vector<int> number_of_108_em{run1_em.number_of_108,run2_em.number_of_108,run3_em.number_of_108,run4_em.number_of_108,run5_em.number_of_108,run6_em.number_of_108,run7_em.number_of_108,run8_em.number_of_108,run9_em.number_of_108,run10_em.number_of_108};
  vector<int> number_of_180_em{run1_em.number_of_180,run2_em.number_of_180,run3_em.number_of_180,run4_em.number_of_180,run5_em.number_of_180,run6_em.number_of_180,run7_em.number_of_180,run8_em.number_of_180,run9_em.number_of_180,run10_em.number_of_180};
  vector<int> number_of_508_em{run1_em.number_of_508,run2_em.number_of_508,run3_em.number_of_508,run4_em.number_of_508,run5_em.number_of_508,run6_em.number_of_508,run7_em.number_of_508,run8_em.number_of_508,run9_em.number_of_508,run10_em.number_of_508};
  vector<int> number_of_other_errors_em{run1_em.number_of_other_errors,run2_em.number_of_other_errors,run3_em.number_of_other_errors,run4_em.number_of_other_errors,run5_em.number_of_other_errors,run6_em.number_of_other_errors,run7_em.number_of_other_errors,run8_em.number_of_other_errors,run9_em.number_of_other_errors,run10_em.number_of_other_errors};
  vector<int> number_of_start_em{run1_em.number_of_start,run2_em.number_of_start,run3_em.number_of_start,run4_em.number_of_start,run5_em.number_of_start,run6_em.number_of_start,run7_em.number_of_start,run8_em.number_of_start,run9_em.number_of_start,run10_em.number_of_start};
  vector<int> trial_em{1,2,3,4,5,6,7,8,9,10};

  TCanvas * c_n_e_0 = new TCanvas("c_n_e","c_n_e");
  TGraph *number_of_events_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_events_em[0]));
  number_of_events_em_gr->SetTitle("External CFO, 130: Number of events");
number_of_events_em_gr->SetMarkerStyle(20);
  number_of_events_em_gr->Draw();
  number_of_events_em_gr->GetXaxis()->SetTitle("run number");
 number_of_events_em_gr->GetYaxis()->SetTitle("number of events");
c_n_e_0->SaveAs("external_130_num_events.pdf");
  TCanvas * c_n_e_1 = new TCanvas("c_n_e_1","c_n_e_1");
  TGraph *number_of_100_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_100_em[0]));
  number_of_100_em_gr->SetTitle("External CFO, 130: number of 0x0100");
 number_of_100_em_gr->SetMarkerStyle(20);
  number_of_100_em_gr->Draw();
number_of_100_em_gr->GetXaxis()->SetTitle("run number");
number_of_100_em_gr->GetYaxis()->SetTitle("number of events");
c_n_e_1->SaveAs("external_130_num_100.pdf");

  TCanvas * c_n_e_2 = new TCanvas("c_n_e_2","c_n_e_2");
  TGraph *number_of_101_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_101_em[0]));
  number_of_101_em_gr->SetTitle("External CFO, 130: number of 0x0101");
number_of_101_em_gr->SetMarkerStyle(20);
number_of_101_em_gr->GetXaxis()->SetTitle("run number");
number_of_101_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_101_em_gr->Draw();
c_n_e_2->SaveAs("external_130_num_101.pdf");

  TCanvas * c_n_e_3 = new TCanvas("c_n_e_3","c_n_e_3");
  TGraph *number_of_108_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_108_em[0]));
  number_of_108_em_gr->SetTitle("External CFO, 130: number of 0x0108");
number_of_108_em_gr->SetMarkerStyle(20);
number_of_108_em_gr->GetXaxis()->SetTitle("run number");
number_of_108_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_108_em_gr->Draw();
c_n_e_3->SaveAs("external_130_num_108.pdf");

  TCanvas * c_n_e_4 = new TCanvas("c_n_e_4","c_n_e_4");
  TGraph *number_of_180_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_180_em[0]));
  number_of_180_em_gr->SetTitle("External CFO, 130: number of 0x0180");
number_of_180_em_gr->SetMarkerStyle(20);
  number_of_180_em_gr->Draw();
 number_of_180_em_gr->GetXaxis()->SetTitle("run number");
number_of_180_em_gr->GetYaxis()->SetTitle("number of events");
c_n_e_4->SaveAs("external_130_num_180.pdf");

  TCanvas * c_n_e_5 = new TCanvas("c_n_e_5","c_n_e_5");
  TGraph *number_of_508_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_508_em[0]));
  number_of_508_em_gr->SetTitle("External CFO, 130: number of 0x0508");
number_of_508_em_gr->SetMarkerStyle(20);
number_of_508_em_gr->GetXaxis()->SetTitle("run number");
number_of_508_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_508_em_gr->Draw();
c_n_e_5->SaveAs("external_130_num_508.pdf");

  TCanvas * c_n_e_6 = new TCanvas("c_n_e_6","c_n_e_6");
  TGraph *number_of_other_errors_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_other_errors_em[0]));
  number_of_other_errors_em_gr->SetTitle("External CFO, 130: number of other errors");
 number_of_other_errors_em_gr->SetMarkerStyle(20);
 number_of_other_errors_em_gr->GetXaxis()->SetTitle("run number");
number_of_other_errors_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_other_errors_em_gr->Draw();
c_n_e_6->SaveAs("external_130_num_oth_err.pdf");

  TCanvas * c_n_e_7 = new TCanvas("c_n_e_7","c_n_e_7");
  TGraph *number_of_start_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_start_em[0]));
  number_of_start_em_gr->SetTitle("External CFO, 130: first event tag");
 number_of_start_em_gr->SetMarkerStyle(20);
 number_of_start_em_gr->GetXaxis()->SetTitle("run number");
number_of_start_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_start_em_gr->Draw();
c_n_e_7->SaveAs("external_130_num_start.pdf");



}





void open_file_ex_258(){
  results run1_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0258.001");
  results run2_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0258.002");
  results run3_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0258.003");
  results run4_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0258.004");
  results run5_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0258.005");
  results run6_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0258.006");
  results run7_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0258.007");
  results run8_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0258.008");
  results run9_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0258.009");
  results run10_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0258.010");
   results run11_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0258.011");

  vector<int> number_of_events_em{run1_em.number_of_events,run2_em.number_of_events,run3_em.number_of_events,run4_em.number_of_events,run5_em.number_of_events,run6_em.number_of_events,run7_em.number_of_events,run8_em.number_of_events,run9_em.number_of_events,run10_em.number_of_events,run11_em.number_of_events};
  vector<int> number_of_100_em{run1_em.number_of_100,run2_em.number_of_100,run3_em.number_of_100,run4_em.number_of_100,run5_em.number_of_100,run6_em.number_of_100,run7_em.number_of_100,run8_em.number_of_100,run9_em.number_of_100,run10_em.number_of_100,run11_em.number_of_100};
  vector<int> number_of_101_em{run1_em.number_of_101,run2_em.number_of_101,run3_em.number_of_101,run4_em.number_of_101,run5_em.number_of_101,run6_em.number_of_101,run7_em.number_of_101,run8_em.number_of_101,run9_em.number_of_101,run10_em.number_of_101,run11_em.number_of_101};
  vector<int> number_of_108_em{run1_em.number_of_108,run2_em.number_of_108,run3_em.number_of_108,run4_em.number_of_108,run5_em.number_of_108,run6_em.number_of_108,run7_em.number_of_108,run8_em.number_of_108,run9_em.number_of_108,run10_em.number_of_108,run11_em.number_of_108};
  vector<int> number_of_180_em{run1_em.number_of_180,run2_em.number_of_180,run3_em.number_of_180,run4_em.number_of_180,run5_em.number_of_180,run6_em.number_of_180,run7_em.number_of_180,run8_em.number_of_180,run9_em.number_of_180,run10_em.number_of_180,run11_em.number_of_180};
  vector<int> number_of_508_em{run1_em.number_of_508,run2_em.number_of_508,run3_em.number_of_508,run4_em.number_of_508,run5_em.number_of_508,run6_em.number_of_508,run7_em.number_of_508,run8_em.number_of_508,run9_em.number_of_508,run10_em.number_of_508,run11_em.number_of_508};
  vector<int> number_of_other_errors_em{run1_em.number_of_other_errors,run2_em.number_of_other_errors,run3_em.number_of_other_errors,run4_em.number_of_other_errors,run5_em.number_of_other_errors,run6_em.number_of_other_errors,run7_em.number_of_other_errors,run8_em.number_of_other_errors,run9_em.number_of_other_errors,run10_em.number_of_other_errors,run11_em.number_of_other_errors};
  vector<int> number_of_start_em{run1_em.number_of_start,run2_em.number_of_start,run3_em.number_of_start,run4_em.number_of_start,run5_em.number_of_start,run6_em.number_of_start,run7_em.number_of_start,run8_em.number_of_start,run9_em.number_of_start,run10_em.number_of_start,run11_em.number_of_start};
  vector<int> trial_em{1,2,3,4,5,6,7,8,9,10,11};

  TCanvas * c_n_e_0 = new TCanvas("c_n_e","c_n_e");
  TGraph *number_of_events_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_events_em[0]));
  number_of_events_em_gr->SetTitle("External CFO, 258: Number of events");
number_of_events_em_gr->SetMarkerStyle(20);
  number_of_events_em_gr->Draw();
  number_of_events_em_gr->GetXaxis()->SetTitle("run number");
 number_of_events_em_gr->GetYaxis()->SetTitle("number of events");
c_n_e_0->SaveAs("external_258_num_events.pdf");
  TCanvas * c_n_e_1 = new TCanvas("c_n_e_1","c_n_e_1");
  TGraph *number_of_100_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_100_em[0]));
  number_of_100_em_gr->SetTitle("External CFO, 258: number of 0x0100");
 number_of_100_em_gr->SetMarkerStyle(20);
  number_of_100_em_gr->Draw();
number_of_100_em_gr->GetXaxis()->SetTitle("run number");
number_of_100_em_gr->GetYaxis()->SetTitle("number of events");
c_n_e_1->SaveAs("external_258_num_100.pdf");

  TCanvas * c_n_e_2 = new TCanvas("c_n_e_2","c_n_e_2");
  TGraph *number_of_101_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_101_em[0]));
  number_of_101_em_gr->SetTitle("External CFO, 258: number of 0x0101");
number_of_101_em_gr->SetMarkerStyle(20);
number_of_101_em_gr->GetXaxis()->SetTitle("run number");
number_of_101_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_101_em_gr->Draw();
c_n_e_2->SaveAs("external_258_num_101.pdf");

  TCanvas * c_n_e_3 = new TCanvas("c_n_e_3","c_n_e_3");
  TGraph *number_of_108_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_108_em[0]));
  number_of_108_em_gr->SetTitle("External CFO, 258: number of 0x0108");
number_of_108_em_gr->SetMarkerStyle(20);
number_of_108_em_gr->GetXaxis()->SetTitle("run number");
number_of_108_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_108_em_gr->Draw();
c_n_e_3->SaveAs("external_258_num_108.pdf");

  TCanvas * c_n_e_4 = new TCanvas("c_n_e_4","c_n_e_4");
  TGraph *number_of_180_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_180_em[0]));
  number_of_180_em_gr->SetTitle("External CFO, 258: number of 0x0180");
number_of_180_em_gr->SetMarkerStyle(20);
  number_of_180_em_gr->Draw();
 number_of_180_em_gr->GetXaxis()->SetTitle("run number");
number_of_180_em_gr->GetYaxis()->SetTitle("number of events");
c_n_e_4->SaveAs("external_258_num_180.pdf");

  TCanvas * c_n_e_5 = new TCanvas("c_n_e_5","c_n_e_5");
  TGraph *number_of_508_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_508_em[0]));
  number_of_508_em_gr->SetTitle("External CFO, 258: number of 0x0508");
number_of_508_em_gr->SetMarkerStyle(20);
number_of_508_em_gr->GetXaxis()->SetTitle("run number");
number_of_508_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_508_em_gr->Draw();
c_n_e_5->SaveAs("external_258_num_508.pdf");

  TCanvas * c_n_e_6 = new TCanvas("c_n_e_6","c_n_e_6");
  TGraph *number_of_other_errors_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_other_errors_em[0]));
  number_of_other_errors_em_gr->SetTitle("External CFO, 258: number of other errors");
 number_of_other_errors_em_gr->SetMarkerStyle(20);
 number_of_other_errors_em_gr->GetXaxis()->SetTitle("run number");
number_of_other_errors_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_other_errors_em_gr->Draw();
c_n_e_6->SaveAs("external_258_num_oth_err.pdf");

  TCanvas * c_n_e_7 = new TCanvas("c_n_e_7","c_n_e_7");
  TGraph *number_of_start_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_start_em[0]));
  number_of_start_em_gr->SetTitle("External CFO, 258: first event tag");
 number_of_start_em_gr->SetMarkerStyle(20);
 number_of_start_em_gr->GetXaxis()->SetTitle("run number");
number_of_start_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_start_em_gr->Draw();
c_n_e_7->SaveAs("external_258_num_start.pdf");



}




void open_file_ex_514(){
  results run1_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0514.001");
  results run2_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0514.002");
  results run3_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0514.003");
  results run4_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0514.004");
  results run5_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0514.005");
  results run6_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0514.006");
  results run7_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0514.007");
  results run8_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0514.008");
  results run9_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0514.009");
  results run10_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_0514.010");
 
  vector<int> number_of_events_em{run1_em.number_of_events,run2_em.number_of_events,run3_em.number_of_events,run4_em.number_of_events,run5_em.number_of_events,run6_em.number_of_events,run7_em.number_of_events,run8_em.number_of_events,run9_em.number_of_events,run10_em.number_of_events};
  vector<int> number_of_100_em{run1_em.number_of_100,run2_em.number_of_100,run3_em.number_of_100,run4_em.number_of_100,run5_em.number_of_100,run6_em.number_of_100,run7_em.number_of_100,run8_em.number_of_100,run9_em.number_of_100,run10_em.number_of_100};
  vector<int> number_of_101_em{run1_em.number_of_101,run2_em.number_of_101,run3_em.number_of_101,run4_em.number_of_101,run5_em.number_of_101,run6_em.number_of_101,run7_em.number_of_101,run8_em.number_of_101,run9_em.number_of_101,run10_em.number_of_101};
  vector<int> number_of_108_em{run1_em.number_of_108,run2_em.number_of_108,run3_em.number_of_108,run4_em.number_of_108,run5_em.number_of_108,run6_em.number_of_108,run7_em.number_of_108,run8_em.number_of_108,run9_em.number_of_108,run10_em.number_of_108};
  vector<int> number_of_180_em{run1_em.number_of_180,run2_em.number_of_180,run3_em.number_of_180,run4_em.number_of_180,run5_em.number_of_180,run6_em.number_of_180,run7_em.number_of_180,run8_em.number_of_180,run9_em.number_of_180,run10_em.number_of_180};
  vector<int> number_of_508_em{run1_em.number_of_508,run2_em.number_of_508,run3_em.number_of_508,run4_em.number_of_508,run5_em.number_of_508,run6_em.number_of_508,run7_em.number_of_508,run8_em.number_of_508,run9_em.number_of_508,run10_em.number_of_508};
  vector<int> number_of_other_errors_em{run1_em.number_of_other_errors,run2_em.number_of_other_errors,run3_em.number_of_other_errors,run4_em.number_of_other_errors,run5_em.number_of_other_errors,run6_em.number_of_other_errors,run7_em.number_of_other_errors,run8_em.number_of_other_errors,run9_em.number_of_other_errors,run10_em.number_of_other_errors};
  vector<int> number_of_start_em{run1_em.number_of_start,run2_em.number_of_start,run3_em.number_of_start,run4_em.number_of_start,run5_em.number_of_start,run6_em.number_of_start,run7_em.number_of_start,run8_em.number_of_start,run9_em.number_of_start,run10_em.number_of_start};
  vector<int> trial_em{1,2,3,4,5,6,7,8,9,10};

  TCanvas * c_n_e_0 = new TCanvas("c_n_e","c_n_e");
  TGraph *number_of_events_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_events_em[0]));
  number_of_events_em_gr->SetTitle("External CFO, 514: Number of events");
number_of_events_em_gr->SetMarkerStyle(20);
  number_of_events_em_gr->Draw();
  number_of_events_em_gr->GetXaxis()->SetTitle("run number");
 number_of_events_em_gr->GetYaxis()->SetTitle("number of events");
c_n_e_0->SaveAs("external_514_num_events.pdf");
  TCanvas * c_n_e_1 = new TCanvas("c_n_e_1","c_n_e_1");
  TGraph *number_of_100_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_100_em[0]));
  number_of_100_em_gr->SetTitle("External CFO, 514: number of 0x0100");
 number_of_100_em_gr->SetMarkerStyle(20);
  number_of_100_em_gr->Draw();
number_of_100_em_gr->GetXaxis()->SetTitle("run number");
number_of_100_em_gr->GetYaxis()->SetTitle("number of events");
c_n_e_1->SaveAs("external_514_num_100.pdf");

  TCanvas * c_n_e_2 = new TCanvas("c_n_e_2","c_n_e_2");
  TGraph *number_of_101_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_101_em[0]));
  number_of_101_em_gr->SetTitle("External CFO, 514: number of 0x0101");
number_of_101_em_gr->SetMarkerStyle(20);
number_of_101_em_gr->GetXaxis()->SetTitle("run number");
number_of_101_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_101_em_gr->Draw();
c_n_e_2->SaveAs("external_514_num_101.pdf");

  TCanvas * c_n_e_3 = new TCanvas("c_n_e_3","c_n_e_3");
  TGraph *number_of_108_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_108_em[0]));
  number_of_108_em_gr->SetTitle("External CFO, 514: number of 0x0108");
number_of_108_em_gr->SetMarkerStyle(20);
number_of_108_em_gr->GetXaxis()->SetTitle("run number");
number_of_108_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_108_em_gr->Draw();
c_n_e_3->SaveAs("external_514_num_108.pdf");

  TCanvas * c_n_e_4 = new TCanvas("c_n_e_4","c_n_e_4");
  TGraph *number_of_180_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_180_em[0]));
  number_of_180_em_gr->SetTitle("External CFO, 514: number of 0x0180");
number_of_180_em_gr->SetMarkerStyle(20);
  number_of_180_em_gr->Draw();
 number_of_180_em_gr->GetXaxis()->SetTitle("run number");
number_of_180_em_gr->GetYaxis()->SetTitle("number of events");
c_n_e_4->SaveAs("external_514_num_180.pdf");

  TCanvas * c_n_e_5 = new TCanvas("c_n_e_5","c_n_e_5");
  TGraph *number_of_508_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_508_em[0]));
  number_of_508_em_gr->SetTitle("External CFO, 514: number of 0x0508");
number_of_508_em_gr->SetMarkerStyle(20);
number_of_508_em_gr->GetXaxis()->SetTitle("run number");
number_of_508_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_508_em_gr->Draw();
c_n_e_5->SaveAs("external_514_num_508.pdf");

  TCanvas * c_n_e_6 = new TCanvas("c_n_e_6","c_n_e_6");
  TGraph *number_of_other_errors_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_other_errors_em[0]));
  number_of_other_errors_em_gr->SetTitle("External CFO, 514: number of other errors");
 number_of_other_errors_em_gr->SetMarkerStyle(20);
 number_of_other_errors_em_gr->GetXaxis()->SetTitle("run number");
number_of_other_errors_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_other_errors_em_gr->Draw();
c_n_e_6->SaveAs("external_514_num_oth_err.pdf");

  TCanvas * c_n_e_7 = new TCanvas("c_n_e_7","c_n_e_7");
  TGraph *number_of_start_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_start_em[0]));
  number_of_start_em_gr->SetTitle("External CFO, 514: first event tag");
 number_of_start_em_gr->SetMarkerStyle(20);
 number_of_start_em_gr->GetXaxis()->SetTitle("run number");
number_of_start_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_start_em_gr->Draw();
c_n_e_7->SaveAs("external_514_num_start.pdf");



}



void open_file_ex_1026(){
  results run1_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_1026.001");
  results run2_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_1026.002");
  results run3_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_1026.003");
  results run4_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_1026.004");
  results run5_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_1026.005");
  results run6_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_1026.006");
  results run7_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_1026.007");
  results run8_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_1026.008");
  results run9_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_1026.009");
  results run10_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/external_1026.010");
 
  vector<int> number_of_events_em{run1_em.number_of_events,run2_em.number_of_events,run3_em.number_of_events,run4_em.number_of_events,run5_em.number_of_events,run6_em.number_of_events,run7_em.number_of_events,run8_em.number_of_events,run9_em.number_of_events,run10_em.number_of_events};
  vector<int> number_of_100_em{run1_em.number_of_100,run2_em.number_of_100,run3_em.number_of_100,run4_em.number_of_100,run5_em.number_of_100,run6_em.number_of_100,run7_em.number_of_100,run8_em.number_of_100,run9_em.number_of_100,run10_em.number_of_100};
  vector<int> number_of_101_em{run1_em.number_of_101,run2_em.number_of_101,run3_em.number_of_101,run4_em.number_of_101,run5_em.number_of_101,run6_em.number_of_101,run7_em.number_of_101,run8_em.number_of_101,run9_em.number_of_101,run10_em.number_of_101};
  vector<int> number_of_108_em{run1_em.number_of_108,run2_em.number_of_108,run3_em.number_of_108,run4_em.number_of_108,run5_em.number_of_108,run6_em.number_of_108,run7_em.number_of_108,run8_em.number_of_108,run9_em.number_of_108,run10_em.number_of_108};
  vector<int> number_of_180_em{run1_em.number_of_180,run2_em.number_of_180,run3_em.number_of_180,run4_em.number_of_180,run5_em.number_of_180,run6_em.number_of_180,run7_em.number_of_180,run8_em.number_of_180,run9_em.number_of_180,run10_em.number_of_180};
  vector<int> number_of_508_em{run1_em.number_of_508,run2_em.number_of_508,run3_em.number_of_508,run4_em.number_of_508,run5_em.number_of_508,run6_em.number_of_508,run7_em.number_of_508,run8_em.number_of_508,run9_em.number_of_508,run10_em.number_of_508};
  vector<int> number_of_other_errors_em{run1_em.number_of_other_errors,run2_em.number_of_other_errors,run3_em.number_of_other_errors,run4_em.number_of_other_errors,run5_em.number_of_other_errors,run6_em.number_of_other_errors,run7_em.number_of_other_errors,run8_em.number_of_other_errors,run9_em.number_of_other_errors,run10_em.number_of_other_errors};
  vector<int> number_of_start_em{run1_em.number_of_start,run2_em.number_of_start,run3_em.number_of_start,run4_em.number_of_start,run5_em.number_of_start,run6_em.number_of_start,run7_em.number_of_start,run8_em.number_of_start,run9_em.number_of_start,run10_em.number_of_start};
  vector<int> trial_em{1,2,3,4,5,6,7,8,9,10};

  TCanvas * c_n_e_0 = new TCanvas("c_n_e","c_n_e");
  TGraph *number_of_events_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_events_em[0]));
  number_of_events_em_gr->SetTitle("External CFO, 1026: Number of events");
number_of_events_em_gr->SetMarkerStyle(20);
  number_of_events_em_gr->Draw();
  number_of_events_em_gr->GetXaxis()->SetTitle("run number");
 number_of_events_em_gr->GetYaxis()->SetTitle("number of events");
c_n_e_0->SaveAs("external_1026_num_events.pdf");
  TCanvas * c_n_e_1 = new TCanvas("c_n_e_1","c_n_e_1");
  TGraph *number_of_100_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_100_em[0]));
  number_of_100_em_gr->SetTitle("External CFO, 1026: number of 0x0100");
 number_of_100_em_gr->SetMarkerStyle(20);
  number_of_100_em_gr->Draw();
number_of_100_em_gr->GetXaxis()->SetTitle("run number");
number_of_100_em_gr->GetYaxis()->SetTitle("number of events");
c_n_e_1->SaveAs("external_1026_num_100.pdf");

  TCanvas * c_n_e_2 = new TCanvas("c_n_e_2","c_n_e_2");
  TGraph *number_of_101_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_101_em[0]));
  number_of_101_em_gr->SetTitle("External CFO, 1026: number of 0x0101");
number_of_101_em_gr->SetMarkerStyle(20);
number_of_101_em_gr->GetXaxis()->SetTitle("run number");
number_of_101_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_101_em_gr->Draw();
c_n_e_2->SaveAs("external_1026_num_101.pdf");

  TCanvas * c_n_e_3 = new TCanvas("c_n_e_3","c_n_e_3");
  TGraph *number_of_108_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_108_em[0]));
  number_of_108_em_gr->SetTitle("External CFO, 1026: number of 0x0108");
number_of_108_em_gr->SetMarkerStyle(20);
number_of_108_em_gr->GetXaxis()->SetTitle("run number");
number_of_108_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_108_em_gr->Draw();
c_n_e_3->SaveAs("external_1026_num_108.pdf");

  TCanvas * c_n_e_4 = new TCanvas("c_n_e_4","c_n_e_4");
  TGraph *number_of_180_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_180_em[0]));
  number_of_180_em_gr->SetTitle("External CFO, 1026: number of 0x0180");
number_of_180_em_gr->SetMarkerStyle(20);
  number_of_180_em_gr->Draw();
 number_of_180_em_gr->GetXaxis()->SetTitle("run number");
number_of_180_em_gr->GetYaxis()->SetTitle("number of events");
c_n_e_4->SaveAs("external_1026_num_180.pdf");

  TCanvas * c_n_e_5 = new TCanvas("c_n_e_5","c_n_e_5");
  TGraph *number_of_508_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_508_em[0]));
  number_of_508_em_gr->SetTitle("External CFO, 1026: number of 0x0508");
number_of_508_em_gr->SetMarkerStyle(20);
number_of_508_em_gr->GetXaxis()->SetTitle("run number");
number_of_508_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_508_em_gr->Draw();
c_n_e_5->SaveAs("external_1026_num_508.pdf");

  TCanvas * c_n_e_6 = new TCanvas("c_n_e_6","c_n_e_6");
  TGraph *number_of_other_errors_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_other_errors_em[0]));
  number_of_other_errors_em_gr->SetTitle("External CFO, 1026: number of other errors");
 number_of_other_errors_em_gr->SetMarkerStyle(20);
 number_of_other_errors_em_gr->GetXaxis()->SetTitle("run number");
number_of_other_errors_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_other_errors_em_gr->Draw();
c_n_e_6->SaveAs("external_1026_num_oth_err.pdf");

  TCanvas * c_n_e_7 = new TCanvas("c_n_e_7","c_n_e_7");
  TGraph *number_of_start_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_start_em[0]));
  number_of_start_em_gr->SetTitle("External CFO, 1026: first event tag");
 number_of_start_em_gr->SetMarkerStyle(20);
 number_of_start_em_gr->GetXaxis()->SetTitle("run number");
number_of_start_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_start_em_gr->Draw();
c_n_e_7->SaveAs("external_1026_num_start.pdf");



}



void open_file_em_100000(){
  results run1_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/emulated_100000.001");
  results run2_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/emulated_100000.002");
  results run3_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/emulated_100000.003");
  results run4_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/emulated_100000.004");
  results run5_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/emulated_100000.005");
  results run6_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/emulated_100000.006");
  results run7_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/emulated_100000.007");
  results run8_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/emulated_100000.008");
  results run9_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/emulated_100000.009");
  results run10_em= process("/exp/mu2e/data/projects/tracker/vst/datasets/2024-06-19/emulated_100000.010");
 
  vector<int> number_of_events_em{run1_em.number_of_events,run2_em.number_of_events,run3_em.number_of_events,run4_em.number_of_events,run5_em.number_of_events,run6_em.number_of_events,run7_em.number_of_events,run8_em.number_of_events,run9_em.number_of_events,run10_em.number_of_events};
  vector<int> number_of_100_em{run1_em.number_of_100,run2_em.number_of_100,run3_em.number_of_100,run4_em.number_of_100,run5_em.number_of_100,run6_em.number_of_100,run7_em.number_of_100,run8_em.number_of_100,run9_em.number_of_100,run10_em.number_of_100};
  vector<int> number_of_101_em{run1_em.number_of_101,run2_em.number_of_101,run3_em.number_of_101,run4_em.number_of_101,run5_em.number_of_101,run6_em.number_of_101,run7_em.number_of_101,run8_em.number_of_101,run9_em.number_of_101,run10_em.number_of_101};
  vector<int> number_of_108_em{run1_em.number_of_108,run2_em.number_of_108,run3_em.number_of_108,run4_em.number_of_108,run5_em.number_of_108,run6_em.number_of_108,run7_em.number_of_108,run8_em.number_of_108,run9_em.number_of_108,run10_em.number_of_108};
  vector<int> number_of_180_em{run1_em.number_of_180,run2_em.number_of_180,run3_em.number_of_180,run4_em.number_of_180,run5_em.number_of_180,run6_em.number_of_180,run7_em.number_of_180,run8_em.number_of_180,run9_em.number_of_180,run10_em.number_of_180};
  vector<int> number_of_508_em{run1_em.number_of_508,run2_em.number_of_508,run3_em.number_of_508,run4_em.number_of_508,run5_em.number_of_508,run6_em.number_of_508,run7_em.number_of_508,run8_em.number_of_508,run9_em.number_of_508,run10_em.number_of_508};
  vector<int> number_of_other_errors_em{run1_em.number_of_other_errors,run2_em.number_of_other_errors,run3_em.number_of_other_errors,run4_em.number_of_other_errors,run5_em.number_of_other_errors,run6_em.number_of_other_errors,run7_em.number_of_other_errors,run8_em.number_of_other_errors,run9_em.number_of_other_errors,run10_em.number_of_other_errors};
  vector<int> number_of_start_em{run1_em.number_of_start,run2_em.number_of_start,run3_em.number_of_start,run4_em.number_of_start,run5_em.number_of_start,run6_em.number_of_start,run7_em.number_of_start,run8_em.number_of_start,run9_em.number_of_start,run10_em.number_of_start};
  vector<int> trial_em{1,2,3,4,5,6,7,8,9,10};

  TCanvas * c_n_e_0 = new TCanvas("c_n_e","c_n_e");
  TGraph *number_of_events_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_events_em[0]));
  number_of_events_em_gr->SetTitle("Emulated CFO, 100000: Number of events");
number_of_events_em_gr->SetMarkerStyle(20);
  number_of_events_em_gr->Draw();
  number_of_events_em_gr->GetXaxis()->SetTitle("run number");
 number_of_events_em_gr->GetYaxis()->SetTitle("number of events");
c_n_e_0->SaveAs("emulated_100000_num_events.pdf");
  TCanvas * c_n_e_1 = new TCanvas("c_n_e_1","c_n_e_1");
  TGraph *number_of_100_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_100_em[0]));
  number_of_100_em_gr->SetTitle("Emulated CFO, 100000: number of 0x0100");
 number_of_100_em_gr->SetMarkerStyle(20);
  number_of_100_em_gr->Draw();
number_of_100_em_gr->GetXaxis()->SetTitle("run number");
number_of_100_em_gr->GetYaxis()->SetTitle("number of events");
c_n_e_1->SaveAs("emulated_100000_num_100.pdf");

  TCanvas * c_n_e_2 = new TCanvas("c_n_e_2","c_n_e_2");
  TGraph *number_of_101_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_101_em[0]));
  number_of_101_em_gr->SetTitle("Emulated CFO, 100000: number of 0x0101");
number_of_101_em_gr->SetMarkerStyle(20);
number_of_101_em_gr->GetXaxis()->SetTitle("run number");
number_of_101_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_101_em_gr->Draw();
c_n_e_2->SaveAs("emulated_100000_num_101.pdf");

  TCanvas * c_n_e_3 = new TCanvas("c_n_e_3","c_n_e_3");
  TGraph *number_of_108_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_108_em[0]));
  number_of_108_em_gr->SetTitle("Emulated CFO, 100000: number of 0x0108");
number_of_108_em_gr->SetMarkerStyle(20);
number_of_108_em_gr->GetXaxis()->SetTitle("run number");
number_of_108_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_108_em_gr->Draw();
c_n_e_3->SaveAs("emulated_100000_num_108.pdf");

  TCanvas * c_n_e_4 = new TCanvas("c_n_e_4","c_n_e_4");
  TGraph *number_of_180_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_180_em[0]));
  number_of_180_em_gr->SetTitle("Emulated CFO, 100000: number of 0x0180");
number_of_180_em_gr->SetMarkerStyle(20);
  number_of_180_em_gr->Draw();
 number_of_180_em_gr->GetXaxis()->SetTitle("run number");
number_of_180_em_gr->GetYaxis()->SetTitle("number of events");
c_n_e_4->SaveAs("emulated_100000_num_180.pdf");

  TCanvas * c_n_e_5 = new TCanvas("c_n_e_5","c_n_e_5");
  TGraph *number_of_508_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_508_em[0]));
  number_of_508_em_gr->SetTitle("Emulated CFO, 100000: number of 0x0508");
number_of_508_em_gr->SetMarkerStyle(20);
number_of_508_em_gr->GetXaxis()->SetTitle("run number");
number_of_508_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_508_em_gr->Draw();
c_n_e_5->SaveAs("emulated_100000_num_508.pdf");

  TCanvas * c_n_e_6 = new TCanvas("c_n_e_6","c_n_e_6");
  TGraph *number_of_other_errors_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_other_errors_em[0]));
  number_of_other_errors_em_gr->SetTitle("Emulated CFO, 100000: number of other errors");
 number_of_other_errors_em_gr->SetMarkerStyle(20);
 number_of_other_errors_em_gr->GetXaxis()->SetTitle("run number");
number_of_other_errors_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_other_errors_em_gr->Draw();
c_n_e_6->SaveAs("emulated_100000_num_oth_err.pdf");

  TCanvas * c_n_e_7 = new TCanvas("c_n_e_7","c_n_e_7");
  TGraph *number_of_start_em_gr=new TGraph(size(trial_em),&(trial_em[0]),&(number_of_start_em[0]));
  number_of_start_em_gr->SetTitle("Emulated CFO, 100000: first event tag");
 number_of_start_em_gr->SetMarkerStyle(20);
 number_of_start_em_gr->GetXaxis()->SetTitle("run number");
number_of_start_em_gr->GetYaxis()->SetTitle("number of events");
  number_of_start_em_gr->Draw();
c_n_e_7->SaveAs("emulated_100000_num_start.pdf");



}


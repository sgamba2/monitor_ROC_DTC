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
 
char data;
int k=0;


  // Loop until end of file
 /* while ( k<=106 and in.get(data)) { //in.read(&data, sizeof(data)) and
    // Process the byte (data)
    // ... (your code to handle the data)
     std::cout <<"new character:" << std::hex << static_cast<unsigned int>(data)<< std::endl; // Print the character to the console
    //std::cout << "Read one word in dec:" << std::hex << static_cast<unsigned int>(data) << std::endl;
        k++;
  }
    char h1;*/
unsigned char lo;
int loc     = 0;
unsigned char hi;
while(!in.eof()  and k<=4){
    for (int i=0; i<2016; i++) {
      if (loc == 0) printf(" 0x%08x: ",i*2);

        in.read(reinterpret_cast<char*>(&lo), 1);  // read low byte first
        in.read(reinterpret_cast<char*>(&hi), 1);
        int size = (hi << 8) | lo;
        printf("0x%04x ",size);
        //std::cout <<"0x"<<std::hex<<size<<" "; //
        loc += 1;
        if (loc == 8) {
            printf("\n");
            loc  = 0;
        }
          k++;
    }
}

   //int loc     = 0;
   //in.read(&h1,2);

      //while ( in.get(data) and k<=4) {
   /* for (int i=0; i<2016; i++) {
      if (loc == 0) printf(" 0x%08x: ",i*2);

        in.read(&h1,2);
        std::cout <<"0x"<<std::hex << static_cast<unsigned int>(h1)<<" "; //
        loc += 1;
        if (loc == 8) {
            printf("\n");
            loc  = 0;
        }
            k++;

    }*/
     // }

  // Check for errors during reading
  if (in.bad()) {
    std::cerr << "Error reading from file" << std::endl;
  }
  in.close(); // Close the file

    return;
}



/* char ch;
 int k=0;
  while (in.get(ch) and k<=4) {
    std::cout << ch; // Print the character to the console
    k++;
  }
    Float_t x,y,z;
    Int_t nlines = 0;
    auto f = TFile::Open("basic.root","RECREATE");
    TNtuple ntuple("ntuple","data from ascii file","x:y:z");
 
    while (1) {
        in >> x >> y >> z;
        if (!in.good()) break;
        if (nlines < 5) printf("x=%8f, y=%8f, z=%8f\n",x,y,z);
        ntuple.Fill(x,y,z);
        nlines++;
    }
    printf(" found %d points\n",nlines);
    
    while (!in.eof()){ //file.eof() checks to see if we've gotten the end of file character from the file.
        cout << in.get(); //this will output every single character in the file, one at a time.
    }
        in.close();

    f->Write();





 char data;
int k=0;
  // Loop until end of file
  while (in.read(&data, sizeof(data)) and k<=4) {
    // Process the byte (data)
    // ... (your code to handle the data)
    std::cout << "Read one byte: 0x" << std::hex << static_cast<unsigned int>(data) << std::endl;
        k++;

  }









    */
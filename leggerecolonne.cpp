#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include<bits/stdc++.h>

using namespace std;

int main() {
    // Apre il file in lettura
    ifstream inputFile("dati.txt");
    
    // Verifica se il file è stato aperto correttamente
    if (!inputFile.is_open()) {
        cerr << "impossible to open the file!" << endl;
        return 1;
    }
    
    // Variabili per memorizzare i dati
    int numero;
    string parola;
    int valore;
    string stringaHex;
    int stringaDec;
    
    // Vettori per memorizzare i dati letti
    vector<int> numeri;
    vector<string> parole;
    vector<int> valori;
    vector<string> stringheHex;
    vector<int> stringheDec;
    vector<int> hex;
    // Legge il file riga per riga
    string riga;
    while (getline(inputFile, riga)) {
        istringstream ss(riga);
        
        // Legge i dati da ogni riga
        ss >> numero >> parola >> valore >> stringaHex >> stringaDec;
        
        // Aggiunge i dati ai vettori
        numeri.push_back(numero);
        parole.push_back(parola);
        valori.push_back(valore);
        stringheHex.push_back(stringaHex);
        stringheDec.push_back(stringaDec);
        hex.push_back(stoul(stringaHex, 0, 16));
    }
    
    // Chiude il file
    inputFile.close();
    
    // Stampa i dati letti
    for (size_t i = 0; i < numeri.size(); ++i) {
        cout << "Numero: " << numeri[i] << ", Parola: " << parole[i] << ", Valore: " << valori[i] << ", Stringa Hex: " << stringheHex[i] << ", Stringa Dec: " << stringheDec[i] << endl;
        cout<<hex.at(i)<<endl;
    }
    
    return 0;
}
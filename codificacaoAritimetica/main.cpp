#include <iostream>
#include <fstream>
#include <vector>

using namespace std;



void initByteCount(vector<unsigned long>* bytes) {
    for (int i = 0; i < 256; i++) {
        bytes->push_back(0);
    }
}

void oddsCalculator(vector<double>* odds, vector<unsigned long>* occurrences, unsigned long sumOccurrences) {

    for (int i = 0; i < 256; i++) {
        odds->push_back(occurrences->at(i) / (double)sumOccurrences);
    }

}



// Função principal
int main() {

    // Leitura dos parâmetros
    unsigned int high = 999999, low = 0;
    //cout << "Digite o valor de high: ";
    //cin >> high;
    //cout << "Digite o valor de low: ";
    //cin >> low;
    
    vector<unsigned char> bytes;
    vector<unsigned int> outFileNumbers;
    vector<unsigned long> byteCount;
    vector<double> odds;

    initByteCount(&byteCount);

    
    /*cout << byteCount.size() << endl;
    cout << byteCount.at(0) << endl;*/

    fstream inFile;
    unsigned char read;
    inFile.open("teste.pdf", ios::in | ios::binary);

    while (inFile.read((char*)&read, sizeof(read))) {
        bytes.push_back(read);
        byteCount.at(read) += 1;
    }

    oddsCalculator(&odds, &byteCount, bytes.size());

    double sum = 0;

    for (int i = 0; i < odds.size(); i++) {
        cout << odds.at(i) << endl;
        sum += odds.at(i);
    }

    cout << sum << endl;

      
    inFile.close();

    return 0;
}
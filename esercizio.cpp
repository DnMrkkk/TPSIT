#include <iostream>
#include <fstream>
#define FILE_NAME_CSV "auto.csv"
using namespace std;

struct s_info{
    string categoria, marca, modello, colore;
    string giorni[2][7] = {{"lunedi", "martedi", "mercoledi", "giovedi", "venerdi", "sabato", "domenica"}, {"", "", "", "", "", "", ""}};

}parco1[8];


void vedi_macchine(){
    ifstream fin(FILE_NAME_CSV, ios::in);
    



    fin.close();
}

void prenota_macchina(){

}

short menu(){
    int scelta;
    while(true){
        cout << "1-Vedi macchine\n2- Prenota macchina>>";
        cin >> scelta;
        switch(scelta){
            case 1:
                vedi_macchine();
                break;
            case 2: 
                prenota_macchina();
            case 3:
                return 0;
        }
    }
}

int main(){

    menu();
    return 0;
}
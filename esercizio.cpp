#include <iostream>
#include <fstream>
#define FILE_NAME_CSV "auto.csv"
using namespace std;

int file_size = 0;

struct s_info{
    string categoria, marca, modello, colore;
    string giorni[2][7] = {{"lunedi", "martedi", "mercoledi", "giovedi", "venerdi", "sabato", "domenica"}, {"", "", "", "", "", "", ""}};

}parco1[8];


void vedi_macchine(){
    ifstream fin(FILE_NAME_CSV, ios::in);
    while(!fin.eof()){
        string appoggio;
        getline(fin, appoggio);
        cout << appoggio << endl;     
    }
    fin.close();
}

void inserimento(){
    int i = 0;
    ifstream fin(FILE_NAME_CSV, ios::in);
    while(!fin.eof()){
        for(int c = 0; c < 11; c++)
        {
            string appoge;
            fin >> appoge;
            switch(c){
                case 0:
                    parco1[i].categoria = appoge;
                    break;
                case 1:
                    parco1[i].marca = appoge;
                    break;
                case 2:
                    parco1[i].modello = appoge;
                    break;
                case 3:
                    parco1[i].colore = appoge;
                    break;
                case 4:
                    parco1[i].giorni[1][0] = appoge;
                    break;
                case 5:
                    parco1[i].giorni[1][1] = appoge;
                    break;
                case 6:
                    parco1[i].giorni[1][2] = appoge;
                    break;
                case 7:
                    parco1[i].giorni[1][3] = appoge;
                    break;
                case 8:
                    parco1[i].giorni[1][4] = appoge;
                    break;
                case 9:
                    parco1[i].giorni[1][5] = appoge;
                    break;
                case 10:
                    parco1[i].giorni[1][6] = appoge;
                    break;
            }
        }
        i++;
    }
    file_size = i;
    fin.close();
}

void prenota_macchina(){                                    //da completare
    cout << "Quale marca di macchina vuoi prenotare: ";
    string marca;
    cin >> marca;
    bool trovato = false;
    for(int i = 0; i < file_size; i++)
        if(parco1[i].marca == marca){
            trovato = true;
            break;
        }   

    if(trovato){
        cout << "Quale modello vuoi affittare: " << endl;       
        for(int i = 0; i < file_size; i++)
            if(parco1[i].marca == marca)
                cout << parco1[i].modello;
        string modello;
        cin >> modello;
    }    
}

short menu(){

    inserimento();
    int scelta;
    while(true){
        cout << "1-Vedi macchine\n2- Prenota macchina\n>>";
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
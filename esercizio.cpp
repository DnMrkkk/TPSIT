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
        for(int c = 1; c <= 11; c++)
        {
            string appoge;
            getline(fin, appoge, ',');
            switch(c){
                case 1:
                    parco1[i].categoria = appoge;
                    break;
                case 2:
                    parco1[i].marca = appoge;
                    break;
                case 3:
                    parco1[i].modello = appoge;
                    break;
                case 4:
                    parco1[i].colore = appoge;
                    break;
                case 5:
                    parco1[i].giorni[1][0] = appoge;
                    break;
                case 6:
                    parco1[i].giorni[1][1] = appoge;
                    break;
                case 7:
                    parco1[i].giorni[1][2] = appoge;
                    break;
                case 8:
                    parco1[i].giorni[1][3] = appoge;
                    break;
                case 9:
                    parco1[i].giorni[1][4] = appoge;
                    break;
                case 10:
                    parco1[i].giorni[1][5] = appoge;
                    break;
                case 11:
                    parco1[i].giorni[1][6] = appoge;
                    break;
            }
        }
        i++;
    }
    file_size = i;
    fin.close();
}

void messaggio_errore(){
    cout << "Giornata gia' affittata!" << endl;
}

void refresh_file(){

    fstream fout1(FILE_NAME_CSV, ios::out);
    fout1 << "";
    fout1.close();

    fstream fout(FILE_NAME_CSV, ios::app);

    for(int i = 0; i < file_size; i++){
        fout << parco1[i].categoria << "," << parco1[i].marca << "," << parco1[i].modello << "," << parco1[i].colore << ",";
        for(int c = 0; c < 7; c++){
            fout << parco1[i].giorni[1][c] << ",";
        }
        fout << endl;
    }


}

void prenota_macchina(){                                 
    cout << "Inserisci marca macchina da affittare: ";
    string marca;
    cin >> marca;
    bool trovato = false;


    for(int i = 0; i < file_size; i++){
        if(marca == parco1[i].marca){
            trovato = true;
            break;
        }
    }
    int riga_prenotazione = -1;
    if(trovato){
        for(int i = 0; i < file_size; i++){
            if(marca == parco1[i].marca){
                cout << parco1[i].modello << endl;
            }
        }

        string modello;
        cin >> modello;
        for(int i = 0; i < file_size; i++){
            if(modello == parco1[i].modello){
                cout << "Inserisci giorno da affittare: ";
                string giorno; 
                cin >> giorno;
                if(giorno == "lunedi"){
                    if(parco1[i].giorni[1][0] == "L")
                        parco1[i].giorni[1][0] = "A";
                    else
                        messaggio_errore();
                }else if(giorno == "martedi"){
                     if(parco1[i].giorni[1][1] == "L")
                        parco1[i].giorni[1][1] = "A";
                    else
                        messaggio_errore();
                }else if(giorno == "mercoledi"){
                    if(parco1[i].giorni[1][2] == "L")
                         parco1[i].giorni[1][2] = "A";
                    else
                        messaggio_errore();
                }else if(giorno == "giovedi"){
                     if(parco1[i].giorni[1][3] == "L")
                        parco1[i].giorni[1][3] = "A";
                    else
                        messaggio_errore();
                }else if(giorno == "venerdi"){
                    if(parco1[i].giorni[1][4] == "L")
                        parco1[i].giorni[1][4] = "A";
                    else
                        messaggio_errore();
                }else if(giorno == "sabato"){
                     if(parco1[i].giorni[1][5] == "L")
                        parco1[i].giorni[1][5] = "A";
                    else
                        messaggio_errore();
                }else if(giorno == "domenica"){
                    if(parco1[i].giorni[1][6] == "L")
                        parco1[i].giorni[1][6] = "A";
                    else
                        messaggio_errore();
                }else
                    cout << "Giornata non riconosciuta" << endl;
            break;
            }else
                cout << "Nessuna macchina trovata!" << endl;
    
        }
    }
    refresh_file();
}

short menu(){
    inserimento();
    int scelta;
    while(true){
        cout << "1-Vedi macchine\n2- Prenota macchina\n3- Esci\n>> ";
        cin >> scelta;
        switch(scelta){
            case 1:
                vedi_macchine();
                break;
            case 2: 
                prenota_macchina();
                break;
            case 3:
                return 0;
        }
    }
    return 0;
}

int main(){

    menu();
    return 0;
}
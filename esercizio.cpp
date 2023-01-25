#include <iostream>
#include <fstream>
#define FILE_NAME_CSV "auto.csv"

using namespace std;

int file_size = 0;


struct s_info{
    string categoria, marca, modello, colore;
    string giorni[7];
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
     fstream fin(FILE_NAME_CSV, ios::in);
    int i = 0;
    while(!fin.eof()){
        getline(fin, parco1[i].categoria, ',');
        if(parco1[i].categoria[0] == '\n')
            parco1[i].categoria = parco1[i].categoria.substr(1, parco1[i].categoria.length());

        getline(fin, parco1[i].marca, ',');
            if(parco1[i].marca[0] == ' ')
                parco1[i].marca = parco1[i].marca.substr(1, parco1[i].marca.length());

        getline(fin, parco1[i].modello, ',');
            if(parco1[i].modello[0] == ' ')
                parco1[i].modello = parco1[i].modello.substr(1, parco1[i].modello.length());

        getline(fin, parco1[i].colore, ',');
            if(parco1[i].colore[0] == ' ')
                parco1[i].colore = parco1[i].colore.substr(1, parco1[i].colore.length());

        for(int c = 0; c < 7; c++){
            getline(fin, parco1[i].giorni[c], ',');
            string app = parco1[i].giorni[c];
            if(app[0] == ' '){
                app = app.substr(1, app.length());
                parco1[i].giorni[c] = app;
            }
        }
        i++;
    }
    file_size = i;
    fin.close();
}


void refresh_file(){
    fstream fout(FILE_NAME_CSV, ios::out);
    fout << "";
    fout.close();

    fstream fout1(FILE_NAME_CSV, ios::app);
    for(int i = 0; i < file_size; i++){
        fout1 << parco1[i].categoria << "," << parco1[i].marca << "," << parco1[i].modello << "," << parco1[i].colore << ",";
        for(int c = 0; c < 7; c++){
            fout1 << parco1[i].giorni[c] << ",";
        }

        cout << endl;
    }

    fout1.close();

}

void prenota_macchina(){

    string cat;
    cout << "Inserisci categoria: ";
    cin >> cat;
    for(int i = 0; i < file_size; i++){
        if(parco1[i].categoria == cat){
            cout << parco1[i].marca << "," << parco1[i].modello << " ";
        cout << endl;
        }
    }

    cout << "Inserisci modello auto da prenotare: ";
    string mod;
    cin >> mod;
    for(int i = 0; i < file_size; i++){
        if(parco1[i].modello == mod){
            for(int c = 0; c < 7; c++)
                cout << parco1[i].giorni[c] << ",";

            int giornata;
            cout << endl << "Inserisci numero giornata (1-lunedi' 2-martedi'...): ";
            cin >> giornata;
            giornata--;
            if(parco1[i].giorni[giornata] == "L")
                parco1[i].giorni[giornata] = "A";
            else
                cout << "Giornata non disponibile!" << endl;
        }
    }

    refresh_file();

    cout << endl;
}

short menu(){

    inserimento();
    int scelta;
    while(true){
        cout << "1- Vedi macchine\n2- Prenota macchina\n3- Esci\n>> ";
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

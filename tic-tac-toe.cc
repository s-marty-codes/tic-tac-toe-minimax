/**
 * Tic-Tac-Toe
 * Originally developed: [December 2024]
 * Current Status: Baseline for AI implementation (Minimax)
 */

#include "tris.h"
#include <iostream>
using namespace std;
#include <cstdlib>

void inizializzaMatrice(char matrice[DIM][DIM])
{
    for (int i = 0; i < DIM; ++i) {
        for (int j = 0; j < DIM; ++j) {
            matrice[i][j] = ' ';
        }
    }
}

void stampaMatrice(const char matrice[DIM][DIM])
{
    for (int i = 0; i < DIM; ++i) {
        for (int j = 0; j < DIM; ++j) {
            cout << " " << matrice[i][j] << " ";
            if (j < DIM - 1) cout << "|";
        }
        cout << endl;
        if (i < DIM - 1) cout << "---+---+---" << endl;
    }
    cout << endl;
}

bool gioca(char matrice[DIM][DIM], bool turnoUtente, char simboloUtente, char simboloComputer){
    bool mossa = false;

    int casella, riga, colonna;
    if(turnoUtente){
        do{
            cout << "casella da giocare (1-9): ";
            cin >> casella;
            casella--;
            riga = casella / DIM;
            colonna = casella % DIM;
        } while(matrice[riga][colonna] != ' ');
        matrice[riga][colonna] = simboloUtente;
        mossa = true;
    }
    else{
        do{
            casella = rand() % 9;
            riga = casella / DIM;
            colonna = casella % DIM;
        } while(matrice[riga][colonna] != ' ');
        matrice[riga][colonna] = simboloComputer;
        mossa = true;
    }
    return mossa;
}

bool controllaVincita (const char matrice[DIM][DIM], char simbolo, bool &pareggio)
{
    bool vincita = false;
    // check rows and columns
    for(int i = 0; i < DIM; i++){
        if(matrice[i][0] == simbolo && matrice[i][1] == simbolo && matrice[i][2] == simbolo) vincita = true;
        if(matrice[0][i] == simbolo && matrice[1][i] == simbolo && matrice[2][i] == simbolo) vincita = true;    
    }

    // check diagonals
    if (matrice[0][0] == simbolo && matrice[1][1] == simbolo && matrice[2][2] == simbolo) vincita = true;
    if (matrice[0][2] == simbolo && matrice[1][1] == simbolo && matrice[2][0] == simbolo) vincita = true;
    
    pareggio = true;
    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++){
            if(matrice[i][j] == ' ') pareggio = false;
        }
    }

    return vincita;
}

void iniziaGioco() //called in the main
{
    char scacchiera[DIM][DIM];
    inizializzaMatrice(scacchiera);
    cout << "nuova partita di tris!" << endl;
    stampaMatrice(scacchiera);

    char opzione;
    bool turnoUtente, vincita, pareggio;
    char simboloUtente, simboloComputer;
    cout << "vuoi iniziare tu? (s/n) "; cin >> opzione;
    if(opzione == 's'){
        cout << "utente: X" << endl << "computer: O" << endl;
        simboloUtente = 'X';
        simboloComputer = 'O';

        turnoUtente = true;
    }
    else{
        cout << "utente: O" << endl << "computer: X" << endl;
        simboloUtente = 'O';
        simboloComputer = 'X';

        turnoUtente = false;
    }

    do{
        bool turno = gioca(scacchiera, turnoUtente, simboloUtente, simboloComputer);
        stampaMatrice(scacchiera);
        char simboloCorrente = (turnoUtente ? simboloUtente : simboloComputer);
        if(turno){
            vincita = controllaVincita(scacchiera, simboloCorrente, pareggio);
            if(pareggio) cout << "pareggio!" << endl;
            else if(vincita && turnoUtente) cout << "vittoria dell'utente!" << endl;
            else if(vincita && !turnoUtente) cout << "vittoria del computer!" << endl;
            turnoUtente = !turnoUtente;
        }
    } while(!vincita && !pareggio);
}

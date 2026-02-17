#include "tris.h"
#include <iostream>
using namespace std;
#include <cstdlib>

int main()
{
    srand(time(NULL));
    char opzione;
    cout << "vuoi giocare? (s/n) ";
    cin >> opzione;

    while(opzione == 's'){
        iniziaGioco();
        cout << "vuoi giocare? (s/n) ";
        cin >> opzione;
    }
    
    return 0;
}
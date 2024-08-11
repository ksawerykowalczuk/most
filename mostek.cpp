#include <iostream>
using namespace std;

void sortujOdNajszybszego(int czasy[], int iloscludzi) {
    bool czyzamienieni = true;
    while (czyzamienieni){
        czyzamienieni = false;
        for (int i = 0; i < iloscludzi - 1; i++) {
            if (czasy[i] > czasy[i + 1]) {
                int temporarnaZmienna = czasy[i];
                czasy[i] = czasy[i + 1];
                czasy[i + 1] = temporarnaZmienna;
                czyzamienieni = true;
            }
        }
        iloscludzi--;
    }
}

int przejscieMostu(int czasy[], int iloscludzi) {
    if (iloscludzi == 1) return czasy[0];
    if (iloscludzi == 2) return czasy[1];

    int minimalnyCzas = 0;

    while (iloscludzi > 3) {
        int czas_szybki = czasy[1] + czasy[0] + czasy[iloscludzi-1] + czasy[1];
        int czas_wolny = czasy[iloscludzi-1] + czasy[iloscludzi-2] + 2 * czasy[0];
        minimalnyCzas += min(czas_szybki, czas_wolny);
        iloscludzi -= 2;
    }

    if (iloscludzi == 3) {
        minimalnyCzas += czasy[2] + czasy[0] + czasy[1];
    } else if (iloscludzi == 2) {
        minimalnyCzas += czasy[1];
    }

    return minimalnyCzas;
}

int main() {
    int iloscludzi;
    cin >> iloscludzi;

    int czasy[iloscludzi];
    for (int i = 0; i < iloscludzi; i++) {
        cin >> czasy[i];
    }

    sortujOdNajszybszego(czasy, iloscludzi);

    int minimalnyCzas = przejscieMostu(czasy, iloscludzi);
    
    cout << minimalnyCzas << endl;
}

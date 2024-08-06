#include <iostream>
using namespace std;

int main()
{
    int iloscludzi;
    cin >> iloscludzi;
    int ludzie[iloscludzi];
    int najmniejsza;
    bool czywejscwogole=false;
    for (int i = 0; i < iloscludzi; i++)
    {
        cin >> ludzie[i];
        if (czywejscwogole == false)
        {
            najmniejsza = ludzie[i];
        }
        if (ludzie[i]<ludzie[i-1] && czywejscwogole)
        {
            najmniejsza = ludzie[i];
        }
        czywejscwogole = true;
    }
    int czasomierz=0;
    for (int i = 0; i < iloscludzi; i++)
    {
        czasomierz = czasomierz + ludzie[i];
    }
    int mnoznik=iloscludzi/2-1;
    czasomierz = najmniejsza*mnoznik+czasomierz;
    cout << czasomierz;
}
#include <iostream>
using namespace std;

int main()
{
    int iloscludzi;
    cin >> iloscludzi;
    int ludzie[iloscludzi];

    for (int i = 0; i < iloscludzi; i++)
    {
        cin >> ludzie[i];
    }

    for (int i = 0; i < iloscludzi - 1; i++)
    {
        int minimum = i;
        for (int j = i + 1; j < iloscludzi; j++)
        {
            if (ludzie[j] < ludzie[minimum])
            {
                minimum = j;
            }
        }

        int temp = ludzie[minimum];
        ludzie[minimum] = ludzie[i];
        ludzie[i] = temp;
    }

    int czasomierz = 0;

    while (iloscludzi > 3)
    {
        int czas1 = 2 * ludzie[0] + ludzie[iloscludzi - 1] + ludzie[iloscludzi - 2];
        int czas2 = 2 * ludzie[1] + ludzie[0] + ludzie[iloscludzi - 1];

        if (czas1 < czas2)
        {
            czasomierz = czasomierz + czas1;
        }
        else
        {
            czasomierz = czasomierz + czas2;
        }
        iloscludzi = iloscludzi - 2;
    }

    if (iloscludzi == 3)
    {
        czasomierz = czasomierz + ludzie[0] + ludzie[1] + ludzie[2];
    }
    if (iloscludzi == 2)
    {
        czasomierz = czasomierz + ludzie[1];
    }
    if (iloscludzi == 1)
    {
        czasomierz = czasomierz + ludzie[0];
    }

    cout << czasomierz;
}

#include <iostream>
#include <math.h>

using namespace std;

int w = 0, k = 0, n1 = 0, n2 = 0, reszta = 0, roz = 0, roz2 = 0, roz3 = 0, roz31 = 0;

int main()
{
    //tworzenie tabeli i liczby

    cout << "w = "; cin >> w;
    cout << "k = "; cin >> k;
    cout << "n = "; cin >> n1;

    roz = k * w;

    int tabela[roz];

    //

    n2 = n1;

    while(n1!=0){
        n1 = n1/2;
        roz2++;
    }
    roz2--;

    int tabela2[roz2];

    n1 = n2;

    while(n1!=0){
        reszta = n1%2;
        n1 = n1/2;
        tabela2[roz3] = reszta;
        roz3++;
    }
    roz3--;

    //

    roz31 = roz3;

    for(int i = 0; i < roz;){
        while(roz3>=0){
            tabela[i] = tabela2[roz3];
            roz3--;
            i++;
        }
        roz3 = roz31;
    }

    for(int j = 0; j < roz; j++){
        cout<< tabela[j];
    }


    return 0;
}
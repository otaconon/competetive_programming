#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <vector>
#include <random>

using namespace std;

void Sortuj(vector<int>& vec){
    for(int i = 0; i < vec.size() - 1; i++){
        for(int j = 0; j < vec.size() - i - 1; j++){
            if(vec[j] < vec[j + 1]){
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

void Losuj(vector<int>& vec){
    for(int i = 0; i < 5; i++){
        vec[i] = rand() % 6 + 1;
    }
}

void Sprawdz(vector<int>& vec){
    vector<int> liczby(6);
    for(int i = 0; i < vec.size(); i++){
        liczby[vec[i]-1]++;
    }

    for(int i = 0; i < liczby.size(); i++){
        if(liczby[i] == 5){
            cout << "POKER" << endl;
        }
        else if(liczby[i] == 4){
            cout << "Kareta" << endl;
        }
        else if(liczby[i] == 3){
            cout << "Trójka" << endl;
        }
        else if(liczby[i] == 2){
            cout << "Para" << endl;
        }
    }
}

int main()
{
    vector<int> gracz1(5);
    vector<int> gracz2(5);

    srand(time(0));
    Losuj(gracz1);
    Losuj(gracz2);

    Sortuj(gracz1);
    Sortuj(gracz2);

    Sprawdz(gracz1);
    Sprawdz(gracz2);

    cout << "Twoje kostki:" << endl;
    for(int i = 0; i < 5; i++){
        cout << gracz1[i] << " ";
    }
    cout << endl;
    cout << "Kostki przeciwnika:" << endl;
    for(int i = 0; i < 5; i++){
        cout << gracz2[i] << " ";
    }

    return 0;
}
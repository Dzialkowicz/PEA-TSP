//
//  main.cpp
//  PEA-TSP-BB
//
//  Created by Jakub Sanecki on 28.10.2017.
//  Copyright © 2017 Jakub Sanecki. All rights reserved.
//

#include <iostream>
#include "matrix.h"
using namespace std;

Matrix baseMatrix;

//1. Loading Matrix from file DONE
//2.

int main(int argc, const char * argv[]) {
    
        string menu("Wybierz akcje:\n"
                     "1 - Wczytaj graf z pliku *.txt\n"
                     "2 - Generuj losowy graf\n"
                     "3 - Wyswietl w postaci macierzy\n"
                     "4 - Znajdz rozwiazanie metoda podzialu i ograniczen\n"
                     "0- Zakoncz program");

    
    int menu_opt = 1;
    
    while(menu_opt != 0){
        //print out menu
        cout << menu;
        //get option input from user
        cin >> menu_opt;
        
        switch (menu_opt) {
            case 1:{
                string input_file;
                cout << "Pass the filename (.txt)\n";
                cin >> input_file;
                baseMatrix.loadFile(input_file);
                break;
            }
            case 2:{
                break;
            }
            case 3:{
                break;
            }
            case 4:{
                break;
            }
        }
    }
    
    //cout << "Hello, World!\n";
    return 0;
}

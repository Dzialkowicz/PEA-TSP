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
//2. Displaying Matrix
//3. Generating random Matrix

int main(int argc, const char * argv[]) {
    
        string menu("Choose options:\n"
                     "0 - Quit\n"
                     "1 - Load TSP data from file *.txt\n"
                     "2 - Generate path\n"
                     "3 - Display Matrix\n"
                     "4 - B&B\n");

    
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
                int matrixSize;
                int maxCost;
                cout<<"Pass Matrix Size: \n";
                cin>> matrixSize;
                cout<<"Pass Maximum Cost: \n";
                cin>>maxCost;
                baseMatrix = Matrix(matrixSize, maxCost);
                break;
            }
            case 3:{
                cout << baseMatrix<<"\n";
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

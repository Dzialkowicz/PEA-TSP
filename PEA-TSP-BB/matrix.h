//
//  matrix.h
//  PEA-TSP-BB
//
//  Created by Jakub Sanecki on 28.10.2017.
//  Copyright © 2017 Jakub Sanecki. All rights reserved.
//

#pragma once
#include<string>
#include<fstream>
#include<iostream>
#include<iomanip>

using namespace std;

class Matrix {
public:
    int** mat;
    int* noOfRows;
    int* noOfColumns;
    int matrixSize;
    int lowerBound;
    
    Matrix();
    Matrix(const Matrix&); //pass matrix as a refference
    Matrix(Matrix&, int i, int j); //creates matrix without i-th row and j-th column
    Matrix(int, int);//generate random matrix 1: matrixSize 2: maxCost
    Matrix& operator=(const Matrix&);
    void loadFile(string);
    
    friend ostream& operator<<(ostream&, Matrix&); //Inserting formated stream
    
    ~Matrix();
    
    
};

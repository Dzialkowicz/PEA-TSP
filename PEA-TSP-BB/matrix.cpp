//
//  matrix.cpp
//  PEA-TSP-BB
//
//  Created by Jakub Sanecki on 28.10.2017.
//  Copyright © 2017 Jakub Sanecki. All rights reserved.
//

#include <stdio.h>
#include "matrix.h"

//Object definition
Matrix::Matrix(){
    mat = nullptr;
    noOfRows = nullptr;
    noOfColumns = nullptr;
    matrixSize = 0;
    lowerBound = 0;
}

Matrix::Matrix(const Matrix& tmp){
    (*this) = tmp;
}

//Object destructor
Matrix::~Matrix(){
    if(mat){
        for(int i =0; i< matrixSize; i++){
            delete[] mat[i]; //delete all the insides
        }
        delete[] mat; //delete object
    }
    if(noOfRows){
        delete[] noOfRows;
    }
    if(noOfColumns){
        delete[] noOfColumns;
    }
}

void Matrix::loadFile(string filePath){
    
    fstream TSPFileStream; // defining file stream
    TSPFileStream.open(filePath.c_str(), ios::in); //get the file as input type
    
    //check if there are no error in file stream
    if(TSPFileStream.good()){
        
        //make sure matrix is not already existing
        if(mat){
            for(int i=0; i<matrixSize; i++)
            {
                delete[] mat[i];
            }
        }
        if(noOfRows){
            delete[] noOfRows;
        }
        if(noOfColumns){
            delete[] noOfColumns;
        }
        //Creating new instance from file
        //get the matrixSize from a File
        TSPFileStream >> matrixSize;
        //Prepare data of TSP before loading from file
        lowerBound = 0;
        noOfColumns = new int[matrixSize];
        noOfRows = new int [matrixSize];
        mat = new int*[matrixSize];
        
        for(int i = 0; i<matrixSize;i++){
            mat[i] = new int[matrixSize];
            noOfColumns[i] = i;
            noOfRows[i] = i;
        }
        //Get the TSP data from file
        for(int i = 0; i<matrixSize;i++){
            for(int j = 0; j<matrixSize;j++){
                TSPFileStream >>mat[i][j];
            }
        }
        //Close input stream
        TSPFileStream.close();
        cout << "File loaded SUCCESSFULLY!!!\n";
    }
    else{
        cout<<"File Not OK! ERROR during opening a file\n";
    }
}

//Generating Random Matrix

Matrix::Matrix(int _size, int _maxCost){
    matrixSize = _size;
    mat = new int*[matrixSize];
    
    //Setting base vars before filling with random data
    for(int i=0; i< matrixSize; i++){
        mat[i] = new int [matrixSize];
        noOfColumns = new int[matrixSize];
        noOfRows = new int [matrixSize];
        lowerBound = 0;
    }
    //Setting rows and columns numbers
    for (int i = 0; i<matrixSize; i++){
        noOfRows[i] = i;
        noOfColumns[i] = i;
    }
    //Filling Matrix with random data
    for (int i = 0; i<matrixSize; i++){
        for (int j = 0; j<matrixSize; j++){
            //Setting the diagonal to -1
            if(i==j){
                mat[i][j]= -1;
            }
            //Generate random number for each path with max cost given by user (rand returns number from size lower by 1 by given modulo)
            else{
                mat[i][j] = rand() % _maxCost +1;
            }
        }
    }
}
// << Operator
ostream& operator<<(ostream& stream, Matrix& _matrix){
    if(_matrix.matrixSize ==0){
        stream << "Empty Array\n.";
    }
    else{
        stream << "Matrix size: " <<_matrix.matrixSize;
        stream << "\n\n";
        for(int i =0; i<_matrix.matrixSize;i++){
            for(int j =0; j<_matrix.matrixSize;j++){
                stream <<setw(3) <<_matrix.mat[i][j] <<" ";
            }
            stream << "\n";
        }
    }
    return stream;
}

Matrix& Matrix::operator=(const Matrix& tmp){
    this->lowerBound = tmp.lowerBound;
    this->matrixSize = tmp.matrixSize;
    this->noOfColumns = new int[tmp.matrixSize];
    this->noOfRows = new int[tmp.matrixSize];
    
    for(int i = 0; i<tmp.matrixSize;i++){
        this -> noOfRows[i] = tmp.noOfRows[i];
        this -> noOfColumns[i] = tmp.noOfColumns[i];
    }
    
    this -> mat = new int*[tmp.matrixSize];
    
    for(int i = 0; i<tmp.matrixSize;i++){
        this ->mat[i] = new int[tmp.matrixSize];
    }
    
    for(int i = 0; i<tmp.matrixSize;i++){
        memcpy(this->mat[i], tmp.mat[i], sizeof(int)*tmp.matrixSize);
    }
    
    return (*this);
}



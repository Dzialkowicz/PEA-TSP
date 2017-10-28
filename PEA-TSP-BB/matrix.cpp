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

//Object destructor
Matrix::~Matrix(){
    if(mat){
        for(int i =0; i< matrixSize; i++){
            delete[] mat[i]; //delete all the insides
            delete[] mat; //delete object
        }
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
            for(int j = 0; i<matrixSize;j++){
                TSPFileStream >>mat[i][j];
            }
        }
        //Close input stream
        TSPFileStream.close();
    }
    cout<<"File Not OK! Error during opening a file";
    
}

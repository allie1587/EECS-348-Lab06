#include <iostream>
#include <fstream>
#include "stdio.h"

const int MAX_SIZE = 100;

int main(){
    char filename[100];
    std::cout << "Enter the file name: ";
    std::cin >> filename;
    std::ifstream file(filename);
    int size;
    file >> size;
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            file >> matrixA[i][j];
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            file >> matrixB[i][j];
        }   
    }
    file.close();
    std::cout << "\nMatrix A:\n";
    for (int i =0; i < size; i++){
        for (int j=0; j < size; j++){
            std::cout<< matrixA[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "Matrix B:\n";
    for (int i =0; i < size; i++){
        for (int j=0; j < size; j++){
            std::cout<< matrixB[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "Matrix Sum (A + B):\n";
    int matrixSum[MAX_SIZE][MAX_SIZE];
    for(int i=0; i < size; i++){
        for (int j=0; j < size; j++){
            matrixSum[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    for (int i =0; i < size; i++){
        for (int j=0; j < size; j++){
            printf("%2d ", matrixSum[i][j]);
        }
        std::cout << "\n";
    }
    std::cout << "Matrix Product (A * B):\n";
    int matrixProduct[MAX_SIZE][MAX_SIZE];
    for (int i=0; i< size; i++){
        for (int j=0; j < size; j++){
            matrixProduct[i][j] = 0;
            for (int k=0; k < size; k++){
                matrixProduct[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    for (int i =0; i < size; i++) {
        for (int j=0; j < size; j++){
            printf("%3d ", matrixProduct[i][j]);
        }
        std::cout << "\n";
    }
    std::cout << "Matrix Difference (A - B):\n";
    int matrixDifference[MAX_SIZE][MAX_SIZE];

    for (int i =0; i < size; i++){
        for (int i = 0; i < size; i++){
            for (int j=0; j< size; j++){
                matrixDifference[i][j] = matrixA[i][j] - matrixB[i][j];
            }
        }
        for (int j=0; j < size; j++){
            std::cout<< matrixDifference[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
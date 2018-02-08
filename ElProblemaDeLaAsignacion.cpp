//
//  main.cpp
//  ElProblemaDeLaAsignacion
//
//  Created by Guillermo on 4/2/18.
//  Copyright © 2018 Guillermo. All rights reserved.
//
//  El ejercicio consiste en una matriz b cuadratica tenemos x valores donde las filas son los trabajadores y las
//  columnas son los trabajos, deberemos conseguir asignar el trabajo mas baratod de cada trabajador pero que no este 
//  asignado ya, donde la asignacion la realizamos atraves de una matriz x de modo que por ejemplo para el caso:
//  1   2   3
//  1   2   3
//  1   2   3
//  La matriz X tendremos 
//  1   0   0
//  0   1   0
//  0   0   1   

#include <iostream>
using namespace std;

const int ROW = 3;
const int COL = 3;

void MostrarMatriz (int Matriz[ROW][COL]);
bool Haciendose (int MatrizX[ROW][COL], int Trabajo);

int main () {
    //  Variables
    int MatrizB[ROW][COL] = {0};
    int MatrizX[ROW][COL] = {0};
    int Coste = 999999999;
    int PosicionTrabajo = 0;
    
    //  Desarrollo del programa
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            cout << "Coste Trabajador " << i+1 << " en el trabajo " << j+1 << ": ";
            cin >> MatrizB[i][j];
        }
    }   //  Cargar MatrizB
    
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (Coste > MatrizB[i][j] && Haciendose(MatrizX, j) == false) {
                Coste = MatrizB[i][j];
                PosicionTrabajo = j;
            }
        }
        MatrizX[i][PosicionTrabajo] = 1;
        Coste = 999999;
        PosicionTrabajo = 0;
    }

    MostrarMatriz(MatrizB);
    cout << endl;
    MostrarMatriz(MatrizX);

    return 0;
}

void MostrarMatriz ( int Matriz[ROW][COL])  {
    for (int i =0;  i < ROW;  i++) {
        for (int j = 0;  j  < COL;  j++)  {
            cout << Matriz[i][j] << " ";
        }
        cout << endl;
    }
}

bool Haciendose (int MatrizX[ROW][COL], int Trabajo) {
    bool Haciendose = false;
    for (int i = 0; i < ROW && Haciendose == false; i++) {
        if (MatrizX[i][Trabajo] == 1){
            Haciendose = true;
        }
    }
    return Haciendose;
}

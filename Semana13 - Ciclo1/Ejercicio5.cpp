#include "pch.h"
#include "iostream"
const int filamatriz = 6;
const int columnamatriz = 8;

using namespace System;
using namespace std;

int RandInt(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void GenerarValoresA(int** M)
{
    for (int i = 0; i < filamatriz; i++)
    {
        for (int j = 0; j < columnamatriz; j++)
        {
            M[i][j] = RandInt(0, 20);
        }
    }
}

void ImprimirMatrizA(int** M)
{
    for (int i = 0; i < filamatriz; i++)
    {
        for (int j = 0; j < columnamatriz; j++)
        {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void GenerarValoresBCeros(int** MR)
{
    for (int i = 0; i < filamatriz; i++)
    {
        for (int j = 0; j < columnamatriz; j++)
        {
            MR[i][j] = 0;
        }
    }
}

void CalcularMatrizResultante(int** M, int** MR)
{
    int suma = 0;
    for (int i = 1; i < filamatriz - 1; i++)
    {
        for (int j = 1; j < columnamatriz - 1; j++)
        {
            suma = M[i][j] + M[i - 1][j] + M[i + 1][j] + M[i][j - 1] + M[i][j + 1];
            if (suma > 30)
            {
                MR[i][j] = 1;
            }
            else
            {
                MR[i][j] = 0;
            }
        }
    }
}

void ImprimirMatrizResultante(int** M, int** MR)
{
    for (int i = 0; i < filamatriz; i++)
    {
        for (int j = 0; j < columnamatriz; j++)
        {
            if (MR[i][j] == 1)
            {
                cout << "*" << "\t";
            }
            if (MR[i][j] == 0)
            {
                cout << " " << "\t";
            }
        }
        cout << endl;
    }
}

void LiberarMatrices(int** M, int** MR)
{
    for (int i = 0; i < filamatriz; i++)
    {
        delete[] M[i];
        delete[] MR[i];
    }
    delete[] M;
    delete[] MR;
}

int main()
{
    int** M = new int* [filamatriz];
    int** MR = new int* [filamatriz];
    for (int i = 0; i < filamatriz; i++)
    {
        M[i] = new int[columnamatriz];
        MR[i] = new int[columnamatriz];
    }

    GenerarValoresA(M);
    ImprimirMatrizA(M);
    GenerarValoresBCeros(MR);
    CalcularMatrizResultante(M, MR);
    ImprimirMatrizResultante(M, MR);
    LiberarMatrices(M, MR);

    system("pause>0");
    return 0;
}
#include "pch.h"
#include "iostream"

using namespace System;
using namespace std;

int RandInt(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int ValidarN()
{
    int N;
    do
    {
        cout << "Ingrese N: "; cin >> N;
    } while (N < 2 || N > 50);
    system("cls");
    return N;
}

void GenerarDatosMI(int** M, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            M[i][j] = RandInt(1, 20);
        }
    }
}

void ImprimirMatrizInicial(int** M, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void GenerarDatosMRCeros(int** MR, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            MR[i][j] = 0;
        }
    }
}

void GenerarMatrizResultante(int** M, int** MR, int N)
{
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            MR[i][j] = M[i][j] + M[j][i];
        }
    }
}

void ImprimirMatrizResultante(int** M, int** MR, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << MR[i][j] << "\t";
        }
        cout << endl;
    }
}

void LiberarMatrices(int** M, int** MR, int N)
{
    for (int i = 0; i < N; i++)
    {
        delete[] M[i];
        delete[] MR[i];
    }
    delete[] M;
    delete[] MR;
}

int main()
{
    srand(time(nullptr));
    int N = ValidarN();
    int** M = new int* [N]; //filas
    int** MR = new int* [N]; //filas
    for (int i = 0; i < N; i++)
    {
        M[i] = new int[N]; //columnas
        MR[i] = new int[N]; //columnas
    }

    GenerarDatosMI(M, N);
    ImprimirMatrizInicial(M, N);
    GenerarDatosMRCeros(MR, N);
    GenerarMatrizResultante(M, MR, N);
    ImprimirMatrizResultante(M, MR, N);
    LiberarMatrices(M, MR, N);

    system("pause>0");
    return 0;
}
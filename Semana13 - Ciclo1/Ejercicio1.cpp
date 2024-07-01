#include "pch.h"
#include "iostream"
const int filasmatriz = 50;

using namespace System;
using namespace std;

int RandInt(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void GenerarDatos(int M[][3], int filas)
{
    for (int i = 0; i < filas; i++)
    {
        M[i][0] = RandInt(1, 3);
        M[i][1] = RandInt(1, 30);
        M[i][2] = RandInt(1, 3);
    }
}

void MostrarDatos(int M[][3], int filas, int columnas)
{
    Console::SetCursorPosition(3, 0);
    cout << "Oficina";
    Console::SetCursorPosition(13, 0);
    cout << "Cant.Min";
    Console::SetCursorPosition(23, 0);
    cout << "Tipo Llamada" << endl;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << "\t" << M[i][j];
        }
        cout << endl;
    }
}

void DeterminarOficinasMayorCantMin(int M[][3], int filas)
{
    int OfiMinAcumulados[3] = { 0 };
    for (int i = 0; i < filas; i++)
    {
        int oficina = M[i][0];
        int minutos = M[i][1];
        OfiMinAcumulados[oficina - 1] += minutos;
    }

    int mayorMin = OfiMinAcumulados[0];
    for (int i = 1; i < 3; i++)
    {
        if (mayorMin < OfiMinAcumulados[i])
        {
            mayorMin = OfiMinAcumulados[i];
        }
    }

    cout << endl << "Oficina(s) con la mayor cantidad de minutos en llamadas: " << endl;
    for (int i = 0; i < 3; i++)
    {
        if (OfiMinAcumulados[i] == mayorMin)
        {
            cout << "Oficina " << i + 1 << " con " << mayorMin << " minutos." << endl;
        }
    }
}

void MontoTotalAPagarPorTipoLlamada(int M[][3], int filas)
{
    double tarifa[3] = { 0.30,0.80,1.50 };
    double MontoTotalPorTipo[3] = { 0.0 };

    for (int i = 0; i < filas; i++)
    {
        int minutos = M[i][1];
        int tipollamada = M[i][2];
        MontoTotalPorTipo[tipollamada - 1] += minutos * tarifa[tipollamada - 1];
    }

    cout << endl << "Monto total a pagar por tipo de llamada: " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Tipo de llamada " << i + 1 << ": S/" << MontoTotalPorTipo[i] << endl;
    }
}

//OTRA FORMA
//void determinarMontoTotalPorTipoDeLLamada(int M[][3], int filas) {
//    int cnt1, cnt2, cnt3;
//    cnt1 = cnt2 = cnt3 = 0;
//    for (int i = 0; i < filas; i++)
//    {
//        // evaluamos segun tipo de llamada
//        switch (M[i][2]) {
//            // incrementamos los minutos
//        case 1: cnt1 += M[i][1]; break;
//        case 2: cnt2 += M[i][1]; break;
//        case 3: cnt3 += M[i][1]; break;
//        }
//    }
//    cout << "El monto total por llamadas de tipo 1 es: " << 0.3 * cnt1 << endl;
//    cout << "El monto total por llamadas de tipo 2 es: " << 0.8 * cnt2 << endl;
//    cout << "El monto total por llamadas de tipo 3 es: " << 1.5 * cnt3 << endl;
//}

void TiempoPromParaOficinaVentasDeLos3TiposLLamada(int M[][3], int filas)
{
    int contTipollamada1 = 0;
    int contTipollamada2 = 0;
    int contTipollamada3 = 0;
    int ContMinutostipo1 = 0;
    int ContMinutostipo2 = 0;
    int ContMinutostipo3 = 0;

    for (int i = 0; i < filas; i++)
    {
        if (M[i][0] == 3)
        {
            switch (M[i][2])
            {
            case 1:
                ContMinutostipo1 += M[i][1];
                contTipollamada1++;
                break;
            case 2:
                ContMinutostipo2 += M[i][1];
                contTipollamada2++;
                break;
            case 3:
                ContMinutostipo3 += M[i][1];
                contTipollamada3++;
                break;
            }
        }
    }

    cout << endl << "Tiempo promedio por tipo de llamada para la oficina de ventas: " << endl;
    if (contTipollamada1 > 0) {
        cout << "Tiempo promedio de llamadas locales: " << (ContMinutostipo1 * 1.0) / contTipollamada1 << endl;
    }
    if (contTipollamada2 > 0) {
        cout << "Tiempo promedio de llamadas a celular: " << (ContMinutostipo2 * 1.0) / contTipollamada2 << endl;
    }
    if (contTipollamada3 > 0) {
        cout << "Tiempo promedio de llamadas internacionales: " << (ContMinutostipo3 * 1.0) / contTipollamada3 << endl;
    }
}

int main()
{
    srand(time(nullptr));
    int M[filasmatriz][3];

    GenerarDatos(M, filasmatriz);
    MostrarDatos(M, filasmatriz, 3);
    DeterminarOficinasMayorCantMin(M, filasmatriz);
    MontoTotalAPagarPorTipoLlamada(M, filasmatriz);
    TiempoPromParaOficinaVentasDeLos3TiposLLamada(M, filasmatriz);

    system("pause>0");
    return 0;
}

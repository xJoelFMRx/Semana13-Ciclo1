#include "pch.h"
#include "iostream"
const int filasMeses = 12;
const int columnasAgencias = 5;

using namespace System;
using namespace std;

int RandInt(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void ImprimirMes(int i)
{
	switch (i)
	{
	case 0: cout << "ENERO"; break;
	case 1: cout << "FEBRERO"; break;
	case 2: cout << "MARZO"; break;
	case 3: cout << "ABRIL"; break;
	case 4: cout << "MAYO"; break;
	case 5: cout << "JUNIO"; break;
	case 6: cout << "JULIO"; break;
	case 7: cout << "AGOSTO"; break;
	case 8: cout << "SEPTIEM"; break;
	case 9: cout << "OCTUBRE"; break;
	case 10: cout << "NOVIEM"; break;
	case 11: cout << "DICIEM"; break;
	}
}

void GenerarValores(int M[][columnasAgencias])
{
	for (int i = 0; i < filasMeses; i++)
	{
		for (int j = 0; j < columnasAgencias; j++)
		{
			M[i][j] = RandInt(1000, 8000);
		}
	}
}

void ImprimirValores(int M[][columnasAgencias])
{
	Console::SetCursorPosition(14, 0);
	cout << "Agencia 1";
	Console::SetCursorPosition(30, 0);
	cout << "Agencia 2";
	Console::SetCursorPosition(46, 0);
	cout << "Agencia 3";
	Console::SetCursorPosition(62, 0);
	cout << "Agencia 4";
	Console::SetCursorPosition(78, 0);
	cout << "Agencia 5" << endl;


	for (int i = 0; i < filasMeses; i++)
	{
		ImprimirMes(i);
		for (int j = 0; j < columnasAgencias; j++)
		{
			cout << "\t\t" << M[i][j];
		}
		cout << endl;
	}
}

void MostrarResumenVentasPorAgencia(int M[][columnasAgencias])
{
	int cnttmpventaspagencia = 0;
	cout << endl << "Resumen de ventas por Agencia: " << endl;
	for (int j = 0; j < columnasAgencias; j++)
	{
		for (int i = 0; i < filasMeses; i++)
		{
			cnttmpventaspagencia += M[i][j];
		}
		cout << "Agencia: " << j + 1 << ": " << cnttmpventaspagencia << endl;
		cnttmpventaspagencia = 0;
	}
}

void MostrarTotalVentasAgencia3(int M[][columnasAgencias])
{
	int conttotalventasagen3 = 0;
	for (int i = 0; i < filasMeses; i++)
	{
		conttotalventasagen3 += M[i][2];
	}
	cout << endl << "El total de ventas anuales de la Agencia 3 es: " << conttotalventasagen3;
}

void MostrarPromedioVentasMesDiciembre(int M[][columnasAgencias])
{
	int contVentasDic = 0;
	for (int j = 0; j < columnasAgencias; j++)
	{
		contVentasDic += M[11][j];
	}
	cout << endl << "El promedio de ventas en el mes de diciembres es: " << (contVentasDic * 1.0) / columnasAgencias;
}

void MostrarNumAgenciaMayorVentaMesMayo(int M[][columnasAgencias])
{
	int posmayorAgencia = 0;
	for (int j = 1; j < columnasAgencias; j++)
	{
		if (M[4][posmayorAgencia] < M[4][j])
		{
			posmayorAgencia = j;
		}
	}
	cout << endl << "El numero de la agencia que tuvo mayores ventas en el mes de mayo es " << posmayorAgencia + 1 << " con " << M[4][posmayorAgencia];
}

void MesMenoresVentas(int M[][columnasAgencias])
{
	int mesmenorventa = 0;
	int ventamenor = INT_MAX;

	for (int i = 0; i < filasMeses; i++)
	{
		int conttotalventames = 0;
		for (int j = 0; j < columnasAgencias; j++)
		{
			conttotalventames += M[i][j];
		}
		if (conttotalventames < ventamenor)
		{
			ventamenor = conttotalventames;
			mesmenorventa = i;
		}
	}
	cout << endl << "Las menores ventas anualmente se registraron en ";
	ImprimirMes(mesmenorventa);
	cout << " con un total de " << ventamenor << " ventas";
}

int main()
{
	srand(time(nullptr));
	int M[filasMeses][columnasAgencias];

	GenerarValores(M);
	ImprimirValores(M);
	MostrarResumenVentasPorAgencia(M);
	MostrarTotalVentasAgencia3(M);
	MostrarPromedioVentasMesDiciembre(M);
	MostrarNumAgenciaMayorVentaMesMayo(M);
	MesMenoresVentas(M);

	system("pause>0");
	return 0;
}
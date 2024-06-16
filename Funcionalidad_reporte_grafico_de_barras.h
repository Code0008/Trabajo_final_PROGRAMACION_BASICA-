#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include <ctime>
#include <cmath>

using namespace std;

int** datos = new int* [8];

extern void generar_matris_barras() {
	// datos[i]-> Accedemos a las filas de los años
	// new int[11]-> creamos las columnas de todos los meses
	for (int i = 0; i < 8; i++) {
		datos[i] = new int[12];
	}
}

extern void generar_datos() {
	srand(time(0));
	int years[] = { 2017, 2018, 2019, 2020, 2021, 2022, 2023, 2024 };
	int indice = 0;
	int n = sizeof(years) / sizeof(years[0]);
	for (int i = 0; i < 7; i++) {

		datos[i][0] = years[i];

		for (int j = 1; j < 12; j++) {
			datos[i][j] = rand() % 2000 + (5000 - 2000); // almacenamos numero de usuarios por mes en las columnas j
		}
		indice++;
	}
}

extern void see_Data() {
	for (int i = 0; i < 7; i++) {
		int promedio_anual = 0;
		for (int x = 0; x < 11; x++) {
			promedio_anual += datos[i][x];
		}
		cout << "Ano: " << datos[i][0] << "\nPromedio anual: " << promedio_anual / 12 << endl << endl;;

		cout << "Enero-Febrero\tMarzo-Abril\tAbril-Mayo\tMayo-Junio\tJunio-Julio" << endl;
		for (int j = 1; j < 6; j++) {
			cout << "   " << datos[i][j] << "\t\t";
		}cout << endl;
		cout << endl << "________________________________________________________________________________________________" << endl;
	}
}


extern void gen_grafico(int tamano, char caracter = 254) {
	for (int i = 0; i < tamano; i++) {
		cout << caracter;
	}
}

extern void see_first_semes(int year = 2024) {
	string meses[] = { "enero-febrero->", "febrero-marzo->", "marzo-abril->", "abril-mayo->", "mayo-junio->", "junio-julio->" };
	int indice = 0;
	int n = sizeof(meses) / sizeof(meses[0]);
	for (int i = 0; i < n; i++) {
		if (datos[i][0] == year) {
			indice = i;
			break;
		}
	}

	char** grafica = new char* [50];
	for (int i = 0; i < 50; i++) {
		grafica[i] = new char[6];
		for (int j = 0; j < 6; j++) {
			grafica[i][j] = 'x';
		}
	}
	cout << endl;
	for (int i = 1; i < 6; i++) {
		int cantida_de_veces = datos[indice][i] / 200;
		cout << endl;
		cout << cantida_de_veces << "Cantidad de veces";
		int max = 0;
		for (int j = 0; j < cantida_de_veces + 1; j++) {
			grafica[49 - j][i] = 254;
			max = j;
		}cout << endl;
		cout << max << "Maximo de " << i << "xdxd" << endl;
	}
	cout << endl;
	string cientos = "CIENTOS";
	for (int i = 0; i < 50; i++) {
		cout << "\t";

		for (int j = 1; j < 6; j++) {
			cout << grafica[i][j] << " \t|\t";
		}cout << "\n";
	}


}
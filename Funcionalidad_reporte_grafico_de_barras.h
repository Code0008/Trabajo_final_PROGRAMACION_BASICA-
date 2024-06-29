#pragma once
#include "COLORAMA.h"
#include "FUNCIONALIDADES.h"

using namespace std;



extern void generar_datos(int** datos) {
	srand(time(0));
	int years[] = { 2017, 2018, 2019, 2020, 2021, 2022, 2023, 2024 };
	int indice = 0;
	int n = sizeof(years) / sizeof(years[0]);
	for (int i = 0; i < 7; i++) {

		datos[i][0] = years[i];

		for (int j = 1; j < 13; j++) {
			datos[i][j] = rand() % 2000 + (5000 - 2000); 
		}
		indice++;
	}
}



extern void gen_grafico(int tamano, char caracter = 254) {
	for (int i = 0; i < tamano; i++) {
		cout << caracter;
	}
}

extern void see_first_semes(int year, int** datos, char semestre) {
	string meses[] = { "enero", "febrero", "marzo", "abril ", "mayo", "junio" };
	string meses_dos[] = { "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre" };
	int indice = 0;
	int n = sizeof(meses) / sizeof(meses[0]);
	bool imprimir = false;

	for (int i = 0; i < n; i++) {
		if (datos[i][0] == year) {
			indice = i;
			break;
		}
	}
	char** grafica = new char* [50];
	for (int i = 0; i < 50; i++) {
		grafica[i] = new char[7];
		for (int j = 0; j < 13; j++) {
			grafica[i][j] = 'x';
		}
	}
	for (int i = 1; i < 13; i++) {
		for (int j = 0; j < datos[indice][i]/200 + 1; j++) {
			grafica[49 - j][i] = 254;
		}
	}
	for (int i = 0; i < 50; i++) {
	
		switch (semestre)
		{

		case '1':
			if (imprimir == false) {
				for (int k = 1; k < 7; k++) {
					if (grafica[i][k] != 'x') {
						imprimir = true;
						break;
					}
				}
			}

			if (imprimir) {
				cout << " \t\t\t\t\t|\t";
				for (int j = 1; j < 7; j++) {
					cout <<LGREEN <<grafica[i][j] << RESET << ROSE "\t|\t";
				} cout << endl;
			}
			break;

		case '2':
			if (imprimir == false) {
				for (int k = 7; k < 13; k++) {
					if (grafica[i][k] != 'x') {
						imprimir = true;
						break;
					}
				}
			}
			if (imprimir) {
				cout << " \t\t\t\t\t|\t";
				for (int j = 7; j < 13; j++) {
					cout << LGREEN<<grafica[i][j] << RESET << ROSE"\t|\t";
				} cout << endl;
			}
			
			break;
			break;
		default:
			break;
		}
	}
	cout << " \t\t\t\t";
	switch (semestre)
	{
	case '1':
		
		for (int t = 0; t < n; t++) {

			cout << "        " << meses[t] << "    ";
		}break;

	case '2':
		cout << "\t\t";
		for (int t = 0; t < n; t++) {

			cout <<  meses_dos[t]<<"        ";
		}break;
	default:
		break;
	}
	cout << endl;
}



extern int** generar_datos_grafico_barras() {
	int** datos = new int* [8];

	for (int i = 0; i < 8; i++) {
		datos[i] = new int[13];
	}

	generar_datos(datos);
	return datos;
}


void grafico_de_barras(char selec, int ano){
	cout << LGREEN << "\t\t\t\t\t\t\t\t[!]" << CYAN << " GRAFICO PRIMER SEMESTRE " << ROSE << "[ ANO ]"<< ano <<RESET<< endl<< endl;
	switch (selec)
	{
	case '1':
		see_first_semes(ano, generar_datos_grafico_barras(), selec); break;
	case '2':
		see_first_semes(ano, generar_datos_grafico_barras(), selec);  break;
	default:
		break;
	}	
}




#pragma once
#include "cabecera_principales.h"
#include "FUNCIONALIDADES.h"



using namespace std;


int** make_data() {
	srand(time(NULL));
	int years[8] = { 2017, 2018, 2019, 2020, 2021, 2022, 2023, 2024 };
	int n = sizeof(years) / sizeof(years[0]);

	int** matriz = new int* [7];
	for (int i = 0; i < n; i++) {
		matriz[i] = new int[4];
		matriz[i][0] = years[i];
		matriz[i][1] = rand() % 10000 + (16666 - 10000);
		matriz[i][2] = rand() % 10000 + (16666 - 10000);
		matriz[i][3] = rand() % 10000 + (16666 - 10000);
	}
	/*				18-30  30-60 60-99
	| año		|		  |		|		|

	*/


	return matriz;
}



void see_data(int** data, int year) {
	cout << RESET;
	int indice = 0; 
	for (int i = 0; i < 7; i++) {
		if (year == data[i][0]) {
			indice = i;
			break;
		}
	}		
	cout << " \t\t\t\t\t\t\t\t\t";
	cout << ROSE <<"18-30\t30-60\t60-mas"<< RESET<<endl;
	cout << " \t\t\t\t\t\t\t\t\t";
	cout << LGREEN << "\tAÑO " <<ROSE << year<<RESET << endl;
	cout << " \t\t\t\t\t\t\t\t\t";
	cout << LGREEN;
	for (int i = 1; i < 4; i++) {
		cout << "|" << data[indice][i] << "|\t";
	}cout << RESET;
}


void principal_reporte_de_lectores_edad(int year) {
	int** data = make_data();
	see_data(data, year);

}
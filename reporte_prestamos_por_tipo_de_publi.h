#pragma once
#include "cabecera_principales.h"

using namespace std;

extern int ** make_data_reporte_porcentaje_publicacion() {
	srand(time(NULL));
	int** data = new int* [3];
	char tipo[] = { 'L', 'R', 'P' };
	for (int i = 0; i < 3; i++) {
		data[i] = new int[3];
		data[i][0] = tipo[i];
		data[i][1] = (rand() % 2000 + (5000 - 2000)) * 6;
		data[i][2] = rand() % 2000 + (data[i][1] - 2000)/3;
	}
	return data;
}

extern void see_datA_reporte_prestamos_tipo_publicacion(int ** data) {

	cout << LGREEN << "\t\t\t\t\t\t\t[!]" << CYAN << " REPORTE DE PORCENTAJES DE LIBROS PRESTADOS POR TIPO DE PUBLICACION " << ROSE <<endl;

	for (int i = 0; i < 3; i++) {
		cout << " \t\t\t\t\t\t\t\t\t";
		switch (i)
		{
		case 0:
			cout << LGREEN << (char)data[i][0]; break;
		case 1:
			cout << LGREEN << (char)data[i][0]; break;
		case 2:
			cout << LGREEN << (char)data[i][0]; break;
		default:
			break;
		}
		cout <<ROSE <<"| ";
		for (int j = 1; j < 3; j++) {
			cout << LGREEN  << data[i][j] << RESET << ROSE" |";
		}cout << endl;

	}
	cout << setprecision(2);
	for (int i = 0; i < 3; i++) {
		switch (i)
		{
		case 0:
			cout << " \t\t\t\t\t\t\t\t\t";
			cout << LGREEN << "prestados de libro %" << (float)data[i][2]*100/data[i][1]<<endl; break;
		case 1:
			cout << " \t\t\t\t\t\t\t\t\t";
			cout << LGREEN << "prestados de revista %" << (float)data[i][2] * 100 / data[i][1] << endl; break;
		case 2:
			cout << " \t\t\t\t\t\t\t\t\t";
			cout << LGREEN << "prestados de periodico %" << (float)data[i][2] * 100 / data[i][1]<< endl; break;
		default:
			break;
		}
	}
}

extern void call_reporte_prestmos() {
	int ** arreglo = make_data_reporte_porcentaje_publicacion();
	see_datA_reporte_prestamos_tipo_publicacion(arreglo);

}

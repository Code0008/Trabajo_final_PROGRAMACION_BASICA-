#pragma once

#include <iostream>
#include <string>
#include <ctype.h>


static bool verificar_string(string texto) {
	for (int i = 0; i < texto.length(); i++) {
		if (isdigit(texto[i])) { return true; }
	} 
}


void test_string() {
	string nombre;
	while (true) {
		cout << "ingresew nombre: " << endl;
		cin.ignore(); getline(cin, nombre);
		if (verificar_string(nombre) == true) {
			cout << "Ingrese bien el dato: " << endl;
		}else { break; }
	}
}




using namespace std;

string verif_date(string date_string) {
    bool verife = false;
    string year = "";
    string moth = "";
    string day = "";
    int end_days[] = { 31, 29, 31, 30, 31, 30 };

    for (int i = 0; i < date_string.length(); i++) {
        if (date_string[i] == '-') {
            i += 1;
        }
        if (i < 4) {
            if (isdigit(date_string[i])) {
                year += date_string[i];
            }
            else {
                break;
            }
        }
        if (i < 7 && i >= 5) {

            if (isdigit(date_string[i])) {
                moth += date_string[i];
            }
            else {
                break;
            }
        }
        if (i >= 8 && i <= 9) {
            if (isdigit(date_string[i])) {
                day += date_string[i];
            }
            else {
                break;
            }
        }
    }
    string fecha_real;
    string current = "";
    for (int i = 0; i < moth.length(); i++) {
        if (moth[i] != '0') {
            current += moth[i];
        }
    }

    fecha_real += year;
    fecha_real += current;
    fecha_real += day;
    return fecha_real;
}

int main() {
    string fecha_actua;
    //  0123456789
    string date_string = "2024-06-5";
    time_t timepo;
    tm timestamp;
    time(&timepo);
    localtime_s(&timestamp, &timepo);
    fecha_actua += to_string(timestamp.tm_year + 1900);
    fecha_actua += to_string(timestamp.tm_mon + 1);
    fecha_actua += to_string(timestamp.tm_mday);

    string x = verif_date(date_string);
    if (fecha_actua == x) {
        cout << "Misma fecha";
    }
    else { cout << "traxza"; }
}



#include <iostream>
#include <string>
#include <stdio.h>
#include <ctime>
#include <cmath>

using namespace std;

int** datos = new int* [8];

extern void generar_matris() {
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



int main() {
	generar_matris();
	generar_datos();
	see_first_semes(2020);
	//see_Data();


}
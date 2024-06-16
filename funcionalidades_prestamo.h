#pragma once
#include <iostream>
#include <stdio.h>
#include "FUNCIONALIDADES.h"
#include <string>
#include <string>
#include <cctype>



using namespace std;


LIBRO inventario_disponible[15] = {
    {202412340, "LIBRO", "EL_QUIJOTE_DE_LA_MANCHA", false},
	{202413830, "REVISTA", "NAT GEO NEW PUBLICATION", false},
	{202412334, "PERIODICO", "ABEJA REPUBLICANA", false},
	{202414555, "LIBRO", "CIEN_AÑOS_DE_SOLEDAD", false},
	{202415666, "REVISTA", "TIME_MAGAZINE", false},
	{202416777, "PERIODICO", "NEW_YORK_TIMES", false},
	{202417888, "LIBRO", "DON_QUIJOTE", false},
	{202418999, "REVISTA", "SCIENTIFIC_AMERICAN", false},
	{202419000, "PERIODICO", "WASHINGTON_POST", false},
	{202420111, "LIBRO", "LA_CASA_DE_LOS_ESPIRITUS", false},
	{202421222, "LIBRO", "1984", false},
	{202422333, "REVISTA", "FORBES", false},
	{202423444, "PERIODICO", "THE_GUARDIAN", false},
	{202424555, "LIBRO", "LA RUTA DEL TILIN", false},
	{202425666, "REVISTA", "THE_ECONOMIST", false}
};


extern void see_inventory() {
	cout << endl;
	cout << "\tCODIGO\tTIPO\tTITULO" << endl;
	for (int i = 0; i < 10; i++) {
		if (inventario_disponible[i].prestado == false) {
			cout << "\t" << inventario_disponible[i].codigo_libro << "\t|\t" << inventario_disponible[i].tipo_libro << "\t|\t" << inventario_disponible[i].titutlo_libro << endl;
		}
	}
}


static bool verif_codigo_libro(int usuario_id, string codigo_libro) {
	int n = sizeof(inventario_disponible) / sizeof(inventario_disponible[0]);
	if (verif_entero(codigo_libro)) {
		if (codigo_libro.length() == 9) {
			for (int i = 0; i < n; i++) {
				if (inventario_disponible[i].codigo_libro == stoi(codigo_libro) && inventario_disponible[i].prestado == false) {
					append_libro(usuario_id, codigo_libro);
					inventario_disponible[i].prestado = true;
					return true;
				}
			}
		}
	}
	return false;
}


static  string calculo_dia_devolucion(int usuario_id) {
	int dias_max=0;
	int n1 = sizeof(inventario_disponible) / sizeof(inventario_disponible[0]);

	int indice = 0;

	for (int i = 0; i < 50; i++) {
		if (usuarios[usuario_id].libros_tratados[i][3] == "true" && usuarios[usuario_id].libros_tratados[i + 1][3] == "void") {
			indice = i;
			break;
		}
	}
	for (int i = 0; i < n1; i++) {
		if (inventario_disponible[i].codigo_libro == stoi(usuarios[usuario_id].libros_tratados[indice][0])) {
			if (inventario_disponible[i].tipo_libro == "LIBRO" || inventario_disponible[i].tipo_libro == "REVISTA") {
				dias_max = 5;
				break;
			}
			else if (inventario_disponible[i].tipo_libro == "PERIODICO") {
				dias_max = 2;
				break;
			}
		}
	}
	int end_days[] = { 31, 29, 31, 30, 31, 30 };
	int n = sizeof(end_days) / sizeof(end_days[0]);
	int moth_end_day = 0;
	string tiempo_capturado;
	tm tiempo;
	time_t timestap;
	time(&timestap);
	localtime_s(&tiempo, &timestap);
	tiempo_capturado.append(to_string(tiempo.tm_year + 1900)); tiempo_capturado.append("/");
	for (int i = 0; i < n; i++) {
		moth_end_day = end_days[tiempo.tm_mon];
	}

	if (tiempo.tm_mday < tiempo.tm_mday + dias_max) { tiempo_capturado.append(to_string(tiempo.tm_mon + 1)); tiempo_capturado.append("/"); }
	else { tiempo_capturado.append(to_string(tiempo.tm_mon + 2)); }
	tiempo_capturado.append(to_string(tiempo.tm_mday + 5));
	return tiempo_capturado;
}

extern void generar_matris(int usuario_id = 0) {
	for (int i = 0; i < 50; i++) {
		usuarios[usuario_id].libros_tratados[i] = new string[4];
	}
	for (int i = 0; i < 50; i++) {
		usuarios[usuario_id].libros_tratados[i][3] = "void";
	}
}

extern  void see_matris(int usuario_id = 0) {
	for (int i = 0; i < 50; i++) {
		if (usuarios[usuario_id].libros_tratados[i][3] == "true") {
			cout << "\t";
			for (int j = 0; j < 4; j++) {
				cout << usuarios[usuario_id].libros_tratados[i][j] << "|";
			} cout << endl;
		}
	}
}


extern void obtener_informacion_prestamo(int usuario_id = 0) {
	see_inventory();
	string var_to_game;
	if (usuarios[usuario_id].DNI == "void") {
		while (true) {
			cout << "\n\t[+]Ingrese su numero de DNI: "; getline(cin, var_to_game);
			if (verif_dni(var_to_game)) {
				usuarios[usuario_id].DNI = var_to_game; break;
			}
			else { cout << RED << "\t[!]" << RESET << ORANGE << " Ingrese bien su DNI!\n" << RESET; }
		}
	}
	while (true) {
		var_to_game = "";
		cout << "\n\t[+]Ingrese el codigo del libro: "; getline(cin, var_to_game);
		if (verif_codigo_libro(usuario_id,var_to_game)) {
			break;
		}
		else {
			cout << RED << "\t[!]" << RESET << ORANGE << " Libro prestado o codigo invalido!\n" << RESET;
		}
	}
	cout << "\t[!] El dia maximo para devolver es: " << calculo_dia_devolucion(usuario_id) << endl;
}



static void boleta_prestamo(int usuario_id = 0) {
	estetica(100, '_'); cout << endl;
	cout << "\t"; estetica(5, '-'); cout << " " << usuarios[usuario_id].userID << endl;
	cout << "\t"; estetica(5, '-'); cout << " " << usuarios[usuario_id].DNI << endl;
	cout << "\t"; estetica(5, '-'); cout << " " << usuarios[usuario_id].NOMBRE_APELLIDO << endl;
	cout << "\t"; estetica(5, '-'); cout << " " << usuarios[usuario_id].EDAD << endl;
	cout << "\t"; estetica(5, '-'); cout << " " << usuarios[usuario_id].SEXO << endl;
	cout << "\t"; estetica(5, '-'); cout << " " << usuarios[usuario_id].direccion.CASA_DEPARTAMENTO << endl;
	cout << "\t"; estetica(5, '-'); cout << " " << usuarios[usuario_id].direccion.DIRECCION << endl;
	cout << "\t"; estetica(5, '-'); cout << " " << usuarios[usuario_id].direccion.DISTRITO << endl;
	cout << "\t"; estetica(5, '-'); cout << " " << usuarios[usuario_id].direccion.PROVINCIA << endl;
	cout << "\t"; estetica(5, '-'); cout << " " << usuarios[usuario_id].CELULAR << endl;
	cout << "\t"; estetica(5, '-'); cout << " " << usuarios[usuario_id].hora_operacion << endl;
	estetica(100, '_'); cout << endl;
	see_matris(usuario_id);

}

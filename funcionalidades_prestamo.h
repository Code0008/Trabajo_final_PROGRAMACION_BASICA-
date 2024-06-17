#pragma once
#include <iostream>
#include <stdio.h>
#include "FUNCIONALIDADES.h"
#include <string>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

LIBRO inventario_disponible[15] = {
	{202412340, 'L', "EL_QUIJOTE_DE_LA_MANCHA", false},
	{202414555, 'L', "CIEN_AÑOS_DE_SOLEDAD", false},
	{202417888, 'L', "DON_QUIJOTE", false},
	{202420111, 'L', "LA_CASA_DE_LOS_ESPIRITUS", false},
	{202421222, 'L', "1984", false},
	{202424555, 'L', "LA_RUTA_DEL_TILIN", false},
	{202413830, 'R', "NAT_GEO_NEW_PUBLICATION", false},
	{202415666, 'R', "TIME_MAGAZINE", false},
	{202418999, 'R', "SCIENTIFIC_AMERICAN", false},
	{202422333, 'R', "FORBES", false},
	{202425666, 'R', "THE_ECONOMIST", false},
	{202412334, 'P', "ABEJA_REPUBLICANA", false},
	{202416777, 'P', "NEW_YORK_TIMES", false},
	{202419000, 'P', "WASHINGTON_POST", false},
	{202423444, 'P', "THE_GUARDIAN", false}
};

extern void see_inventory() {
	cout << endl;
	cout<< MAGENTA; estetica(75, 177); cout << RESET<<endl ;
	cout <<"\t" <<MAGENTA << (char)177 << RESET << " CODIGO\t\t\t TIPO\t\t\t  TITULO" << endl;
	for (int i = 0; i < 15; i++) {
		switch (inventario_disponible[i].tipo_libro)
		{
		case 'P':
			if (inventario_disponible[i].prestado == false) {
				cout << "\t" <<MAGENTA <<(char)177 <<RESET<< ROSE << inventario_disponible[i].codigo_libro << RESET << GRAY<<setw(20) << setfill('-') <<RESET<< LGREEN << "PERIODICO"<<RESET<<GRAY<<"-------" << RESET << CYAN << inventario_disponible[i].titutlo_libro << RESET << endl;
			} break;
		case 'L':
			if (inventario_disponible[i].prestado == false) {
				cout <<"\t" <<MAGENTA<<(char)177<<RESET << ROSE << inventario_disponible[i].codigo_libro << RESET << GRAY<<setw(20) << setfill('-') << RESET<<LGREEN << "LIBRO"<<RESET <<GRAY<<"-----------" << RESET << CYAN << inventario_disponible[i].titutlo_libro << RESET << endl;
			} break;
		case 'R':
			if (inventario_disponible[i].prestado == false) {
				cout << "\t" <<MAGENTA <<(char)177 <<RESET<< ROSE << inventario_disponible[i].codigo_libro << RESET <<GRAY<< setw(20) << setfill('-') << RESET<<LGREEN << "REVISTA"<<RESET<<GRAY<<"---------" << RESET << CYAN << inventario_disponible[i].titutlo_libro << RESET << endl;
			} break;
		default:
			break;
		}
	}
	cout<< MAGENTA; estetica(75, 177); cout << RESET << endl;

}

static bool verif_codigo_libro(int usuario_id, string codigo_libro) {
	int n = sizeof(inventario_disponible) / sizeof(inventario_disponible[0]);
	if (verif_entero(codigo_libro)) {
		if (codigo_libro.length() == 9) {
			for (int i = 0; i < n; i++) {
				if (inventario_disponible[i].codigo_libro == stoi(codigo_libro) && inventario_disponible[i].prestado == false) {
					append_libro(usuario_id, codigo_libro, "prestamo");
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
			if (inventario_disponible[i].tipo_libro = 'L' || inventario_disponible[i].tipo_libro == 'R') {
				dias_max = 5;
				break;
			}
			else if (inventario_disponible[i].tipo_libro == 'P') {
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
	see_inventory();
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
	cout << "\t" <<(char)186; estetica(10, ' '); cout <<"ID USUARIO" << (char)175 <<" " << usuarios[usuario_id].userID << endl;
	cout << "\t" << (char)186; estetica(10, ' '); cout <<"DNI" << (char)175 << " " << usuarios[usuario_id].DNI << endl;
	cout << "\t" << (char)186; estetica(10, ' '); cout <<"NOMBRE" << (char)175 <<" " << usuarios[usuario_id].NOMBRE_APELLIDO << endl;
	cout << "\t" << (char)186; estetica(10, ' '); cout <<"EDAD" <<(char)175 << " "<<usuarios[usuario_id].EDAD << endl;
	cout << "\t" << (char)186; estetica(10, ' '); cout <<"SEXO" << (char)175 <<" "<< usuarios[usuario_id].SEXO << endl;
	cout << "\t" << (char)186; estetica(10, ' '); cout << "TIPO DOMICILIO" << (char)175 <<" " << usuarios[usuario_id].direccion.CASA_DEPARTAMENTO << endl;
	cout << "\t" << (char)186; estetica(10, ' '); cout << "DIRECCION" << (char)175 << " " << usuarios[usuario_id].direccion.DIRECCION << endl;
	cout << "\t" << (char)186; estetica(10, ' '); cout << "DISTRITO" << (char)175 <<" " << usuarios[usuario_id].direccion.DISTRITO << endl;
	cout << "\t" << (char)186; estetica(10, ' '); cout <<"PROVINCIA" << (char)175 <<" "<< usuarios[usuario_id].direccion.PROVINCIA << endl;
	cout << "\t" << (char)186; estetica(10, ' '); cout <<"NUMERO DE CELULAR" << (char)175 <<" " << usuarios[usuario_id].CELULAR << endl;
	cout << "\t" << (char)186; estetica(10, ' '); cout << "HORA DE INGRESO" << (char)175<<" " << usuarios[usuario_id].hora_operacion << endl;
	estetica(100, 238); cout << endl;
	see_matris(usuario_id);

}

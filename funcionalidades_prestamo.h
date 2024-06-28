#pragma once
#include <iostream>
#include <stdio.h>
#include "FUNCIONALIDADES.h"
#include <string>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

static string imprimir_estrellas( LIBRO * librito) {
	string stars;
	for (int i = 0; i < librito->estrellas; i++) {
		stars += "*";
	}
	return stars;
}

extern void see_inventory() {
	cout << endl;
	cout<< "\t\t\t" << MAGENTA; estetica(80, 177); cout << RESET << endl;
	cout <<"\t\t\t\t" <<MAGENTA << (char)177 << RESET << "   CODIGO\t\t\tTIPO\t\t\t TITULO( ESTRELLAS )" << endl;
	for (int i = 0; i < 15; i++) {
		switch (inventario_disponible[i].tipo_libro)
		{
		case 'P':
			if (inventario_disponible[i].prestado == false) {
				cout << "\t\t\t\t" <<MAGENTA <<(char)177<<"   " << RESET << ROSE << inventario_disponible[i].codigo_libro << RESET << GRAY << setw(20) << setfill('-') << RESET << LGREEN << "PERIODICO" << RESET << GRAY << "----------" << RESET << CYAN << inventario_disponible[i].titutlo_libro << YELLOW << " ( " << imprimir_estrellas(&inventario_disponible[i]) << " )" << endl;
			} break;
		case 'L':
			if (inventario_disponible[i].prestado == false) {
				cout <<"\t\t\t\t" <<MAGENTA<<(char)177<<"   " <<RESET << ROSE << inventario_disponible[i].codigo_libro << RESET << GRAY << setw(20) << setfill('-') << RESET << LGREEN << "LIBRO" << RESET << GRAY << "--------------" << RESET << CYAN << inventario_disponible[i].titutlo_libro << YELLOW << " ( " << imprimir_estrellas(&inventario_disponible[i]) <<" )" << endl;;
			} break;
		case 'R':
			if (inventario_disponible[i].prestado == false) {
				cout << "\t\t\t\t" <<MAGENTA <<(char)177 <<"   " << RESET << ROSE << inventario_disponible[i].codigo_libro << RESET << GRAY << setw(20) << setfill('-') << RESET << LGREEN << "REVISTA" << RESET << GRAY << "------------" << RESET << CYAN << inventario_disponible[i].titutlo_libro << YELLOW <<" ( " << imprimir_estrellas(&inventario_disponible[i]) <<" )" << endl;
			} break;
		default:
			break;
		}
	}
	cout<<"\t\t\t" << MAGENTA; estetica(80, 177); cout << RESET << endl;

}

static bool verif_codigo_libro(int cliente_id, string codigo_libro) {
	int n = sizeof(inventario_disponible) / sizeof(inventario_disponible[0]);
	if (verif_entero(codigo_libro)) {
		if (codigo_libro.length() == 9) {
			for (int i = 0; i < n; i++) {
				if (inventario_disponible[i].codigo_libro == stoi(codigo_libro) && inventario_disponible[i].prestado == false) {
					append_libro(cliente_id, codigo_libro, "prestamo");
					inventario_disponible[i].prestado = true;
					return true;
				}
			}
		}
	}
	return false;
}


static  string calculo_dia_devolucion(int cliente_id) {
	int dias_max=0;
	int n1 = sizeof(inventario_disponible) / sizeof(inventario_disponible[0]);

	int indice = 0;

	for (int i = 0; i < 50; i++) {
		if (clientes[cliente_id].libros_tratados[i][3] == "true" && clientes[cliente_id].libros_tratados[i + 1][3] == "void") {
			indice = i;
			break;
		}
	}
	for (int i = 0; i < n1; i++) {
		if (inventario_disponible[i].codigo_libro == stoi(clientes[cliente_id].libros_tratados[indice][0])) {
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

extern void generar_matris(int cliente_id = 0) {
	for (int i = 0; i < 50; i++) {
		clientes[cliente_id].libros_tratados[i] = new string[4];
	}
	for (int i = 0; i < 50; i++) {
		clientes[cliente_id].libros_tratados[i][3] = "void";
	}
}

extern  void see_matris(int cliente_id = 0) {
	for (int i = 0; i < 50; i++) {
		if (clientes[cliente_id].libros_tratados[i][3] == "true") {
			cout << "\t\t\t\t\t";
			for (int j = 0; j < 4; j++) {
				switch (j)
				{
				case 0: cout <<CYAN<< "CODIGO---" <<RESET<< ROSE<<clientes[cliente_id].libros_tratados[i][0];   break;
				case 1:  cout <<LGREEN <<"---HORA---" <<RESET<< GREEN<<clientes[cliente_id].libros_tratados[i][1];   break;
				case 2: cout << BLUE<<"--OPERACION---" <<RESET<< LGREEN<<clientes[cliente_id].libros_tratados[i][2];   break;
				default:
					break;
				}
			} cout << endl;
		}
	}
}

extern void obtener_informacion_prestamo(int cliente_id = 0) {
	
	string var_to_game;
	if (clientes[cliente_id].informacion_cliente.DNI == "void") {
		while (true) {
			cout << LGREEN << "\t\t\t\t[!]" << RESET << CYAN << " INGRESE SU DNI: " << RESET; getline(cin, var_to_game);
			if (verif_dni(var_to_game)) {
				clientes[cliente_id].informacion_cliente.DNI = var_to_game; break;
			}
			else { cout << RED << "\t\t\t\t[!]" << RESET << ORANGE << " Ingrese bien su DNI!\n" << RESET; }
		}
	}
	see_inventory();
	cout << endl;
	while (true) {
		var_to_game = "";
		cout << LGREEN << "\t\t\t\t\t[!]" << RESET << CYAN << " INGRESE CODIGO DEL LIBRO: " << RESET; getline(cin, var_to_game);
		if (verif_codigo_libro(cliente_id,var_to_game)) {
			break;
		}
		else {
			cout << RED << "\t\t\t\t\t[!]" << RESET << ORANGE << " Libro prestado o codigo invalido!\n" << RESET;
		}
	}
	cout << RED << "\t\t\t\t\t[!]" << RESET << LGREEN << " EL DIA MAXIMO PARA DEVOLVER ES (AÑO/MES/DIA): " << RESET <<RED<< calculo_dia_devolucion(cliente_id) << RESET<<endl;
}


static void boleta_prestamo(int cliente_id = 0) {
	cout << "\t\t\t\t\t"<<GRAY; estetica(65, '_'); cout << endl;
	cout << "\t\t\t\t\t\t\t\t" << LGREEN << "BOLETA FINAL DEL USUARIO" << RESET << endl;
	cout << "\t\t\t\t\t"; estetica(65, '_'); cout << endl;
	cout << "\t\t\t\t\t\t" <<(char)186; estetica(7, ' '); cout <<CYAN<<"ID USUARIO" << (char)175 <<" " << clientes[cliente_id].userID << RESET<<endl;
	cout << "\t\t\t\t\t\t" << GRAY << (char)186; estetica(7, ' '); cout <<LGREEN<<"DNI" << (char)175 << " " << clientes[cliente_id].informacion_cliente.DNI << RESET << endl;
	cout << "\t\t\t\t\t\t" << GRAY << (char)186; estetica(7, ' '); cout <<LGREEN<<"NOMBRE" << (char)175 <<" " << clientes[cliente_id].informacion_cliente.NOMBRE_APELLIDO << RESET << endl;
	cout << "\t\t\t\t\t\t" << GRAY << (char)186; estetica(7, ' '); cout <<LGREEN<<"EDAD" <<(char)175 << " "<<clientes[cliente_id].informacion_cliente.EDAD << RESET << endl;
	cout << "\t\t\t\t\t\t" << GRAY << (char)186; estetica(7, ' '); cout <<LGREEN<<"SEXO" << (char)175 <<" "<< clientes[cliente_id].informacion_cliente.SEXO<< RESET << endl;
	cout << "\t\t\t\t\t\t" << GRAY << (char)186; estetica(7, ' '); cout <<LGREEN <<"TIPO DOMICILIO" << (char)175 <<" " << clientes[cliente_id].direccion.CASA_DEPARTAMENTO << RESET << endl;
	cout << "\t\t\t\t\t\t" << GRAY << (char)186; estetica(7, ' '); cout << LGREEN<<"DIRECCION" << (char)175 << " " << clientes[cliente_id].direccion.DIRECCION << RESET << endl;
	cout << "\t\t\t\t\t\t" << GRAY << (char)186; estetica(7, ' '); cout << LGREEN<<"DISTRITO" << (char)175 <<" " << clientes[cliente_id].direccion.DISTRITO << RESET << endl;
	cout << "\t\t\t\t\t\t" << GRAY << (char)186; estetica(7, ' '); cout <<LGREEN<<"PROVINCIA" << (char)175 <<" "<< clientes[cliente_id].direccion.PROVINCIA << RESET << endl;
	cout << "\t\t\t\t\t\t" << GRAY << (char)186; estetica(7, ' '); cout <<LGREEN<<"NUMERO DE CELULAR" << (char)175 <<" " << clientes[cliente_id].contacto.CELULAR << RESET << endl;
	cout << "\t\t\t\t\t\t" << GRAY<<(char)186; estetica(7, ' '); cout <<CYAN <<"HORA DE INGRESO" << (char)175<<" " << clientes[cliente_id].hora_operacion << endl<<RESET;
	cout <<"\t\t\t\t\t"<<GRAY; estetica(64, 238); cout << endl;
	cout <<CYAN <<"\t\t\t\t\t\t\tINVENTARIO ACTUAL DEL CLIENTE " << endl;
	cout <<BLUE <<"\t\t\t\t\t"; estetica(65, '_'); cout << endl;
	see_matris(cliente_id);
	cout << BLUE<<"\t\t\t\t\t"; estetica(65, '_'); cout << endl;

}

#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include "STRUCTURAS.h"
#include "COLORAMA.h"
#include <string>
#include <cctype>

using namespace std;

LIBRO* inventario = new LIBRO[100];

USUARIO* usuarios = new USUARIO[100];

bool verif_string(string texto);
bool verif_dni(string dni);
bool verif_telefono(string telefono);
bool verif_entero(string entero);

static bool verif_dni(string dni) {
	if (dni.length() == 8) {
		if (verif_entero(dni)) {
			return true;
		}
		else { return false; }

	}
	else { return false; }
}

static bool verif_string(string texto) { 
	bool verif= true;
	for (int i = 0; i < texto.length(); i++) {
		if (isdigit(texto[i])) { return true; }
		else { continue; }
	} return false;
}

static bool verif_telefono(string telefono) {
	if (telefono.length() < 10 && telefono.length() > 1) { 
		bool verif = false;
		for (int i = 0; i < 9; i++) {
			if (isdigit(telefono[i])) { verif = true; }
			if (isdigit(telefono[i]) == false || telefono[i] == '+') { return false; }
		}
		return verif;
	}
	else { return false; }
}

static bool verif_entero(string verificar) {
	if (verificar.length() == 0) { return false; }
	bool verif = false;
	for (int i = 0; i < verificar.length(); i++) {
		if (isspace(verificar[i]) || !isprint(verificar[i])) { return false; }
		if (isdigit(verificar[i])) { verif = true; }
		else { return false; }
	}
	return verif;
}

extern void estetica(int tamano = 20, char caracter = '_') {
	cout << "\t";
	for (int i = 0; i < tamano; i++) {
		cout << caracter;
	}
}

extern string capture_time() {
	string tiempo_capturado;
	tm tiempo;
	time_t timestap;
	time(&timestap);
	localtime_s(&tiempo, &timestap);
	/*_______________*/
	tiempo_capturado.append(to_string(tiempo.tm_year + 1900)); tiempo_capturado.append("/");
	tiempo_capturado.append(to_string(tiempo.tm_mon + 1)); tiempo_capturado.append("/");
	tiempo_capturado.append(to_string(tiempo.tm_mday)); tiempo_capturado.append("/ -- ");
	tiempo_capturado.append(to_string(tiempo.tm_hour)); tiempo_capturado.append("(H):");;
	tiempo_capturado.append(to_string(tiempo.tm_min)); tiempo_capturado.append("(M):");
	tiempo_capturado.append(to_string(tiempo.tm_sec)); tiempo_capturado.append("(S)");
	return tiempo_capturado;
}

extern void obtener_informacion_usuario(int id_usuario) {
	string ingreso_jugar;
	usuarios[id_usuario].hora_operacion = capture_time();
	usuarios[id_usuario].userID = id_usuario;
	while (true) {
		cout << LGREEN << "\t[+]Ingrese nombre del usuario: " << RESET; getline(cin, usuarios[id_usuario].NOMBRE_APELLIDO);
		if (verif_string(usuarios[id_usuario].NOMBRE_APELLIDO)) { cout << RED << "\t[!]" << RESET << ORANGE << "INGRESE BIEN EL NOMBRE\n" << RESET; }
		else { break; }
	}
	while (true) {
		cout << LGREEN << "\t[+]Ingrese edad del usuario: " << RESET;  cin >> ingreso_jugar;
		if (verif_entero(ingreso_jugar)) { usuarios[id_usuario].EDAD = stoi(ingreso_jugar); break; }
		else { cout << RED << "\t[!]" << RESET << ORANGE << " Ingrese bien su edad!\n" << RESET; }
	}
	while (true) {
		cout << LGREEN << "\t[+]Seleccion de sexo:\n\t->(1)Masculino\n\t->(2)Femenino\n\t->(3)Cabrin" << RESET<<YELLOW << "\n\t--> " << RESET;; cin >> ingreso_jugar;
		if (verif_entero(ingreso_jugar)) { if (stoi(ingreso_jugar) == 1 || stoi(ingreso_jugar) == 2 || stoi(ingreso_jugar) == 3) { break; }  cout << RED << "\t[!]" << RESET << ORANGE << "Ingrese un valor correcto!\n " << RESET;
		}
		else { cout << RED << "\t[!]" << RESET << ORANGE << "Ingrese un valor correcto!\n " << RESET; }
	}
	switch (stoi(ingreso_jugar))
	{
	case 1: usuarios[id_usuario].SEXO = 'M'; break; case 2: usuarios[id_usuario].SEXO = 'F'; break; case 3: usuarios[id_usuario].SEXO = 'N'; break; default:break;
	}
	while (true) {
		cout << LGREEN << "\t[+]Ingrese su distrito: " << RESET; cin.ignore();  getline(cin, usuarios[id_usuario].direccion.DISTRITO);
		if (verif_string(usuarios[id_usuario].direccion.DISTRITO)) { cout << RED << "\t[!]" << RESET << ORANGE << "Ingrese bien los datos!\n" << RESET; }
		else { break; }
	}
	cout << LGREEN << "\t[+]Ingrese su direccion: " << RESET;  getline(cin, usuarios[id_usuario].direccion.DIRECCION);
	while (true) {
		cout << LGREEN << "\t[+]Seleccione:\n\t-->(1)Casa\n\t-->(2)Departamento"<<RESET << YELLOW << "\n\t--> " << RESET; cin >> ingreso_jugar;
		if (verif_entero(ingreso_jugar)) { if (stoi(ingreso_jugar) < 3 && stoi(ingreso_jugar) > 0) break; }
		else { cout << RED << "\t[!]" << RESET << ORANGE << "Ingrese un valor correcto!\n " << RESET; }
	}
	switch (stoi(ingreso_jugar))
	{
	case 1:  usuarios[id_usuario].direccion.CASA_DEPARTAMENTO = "CASA"; break; case 2:  usuarios[id_usuario].direccion.CASA_DEPARTAMENTO = "DEPARTAMENTO"; break; default:break;
	}
	while (true) {
		cout << LGREEN << "\t[+]Ingrese su numero de celular (SIN PREFIJO): " << RESET; cin.ignore();  cin >> ingreso_jugar;
		if (verif_telefono(ingreso_jugar) == false) { ingreso_jugar = " "; cout << RED << "\t[!]" << RESET << ORANGE << " Ingreso de forma erronea el numero telefnoico\n" << RESET; }
		else { usuarios[id_usuario].CELULAR = ingreso_jugar; break; }
	}
}

extern bool respuesta_continuar() {
	char respuesta;
	cout << endl;
	while (true) {
		cout << RED; estetica(20, '!'); cout << RESET;
		cout << LBLUE << "\t[!]desea hacer otra operacion?:<<" << RESET << RED" Y/N " << RESET << endl;
		cin >> respuesta; respuesta = toupper(respuesta);
		switch (respuesta){
		case 'Y':return true; break;
		case 'N': return false; break;
		default:break;
		}
	}
	cin.ignore();
}

extern int codigo_aleatorio(int inicio, int fin) {
	int gen;
	srand(time(NULL));
	gen = inicio + rand() % (fin + 1 - inicio);
	return gen;
}


extern bool verif_sancion(int usuario_id = 0) {
	if (usuarios[usuario_id].tiene_sancion == true) {
		return  true;
	}
	else { return false; }
}


extern void append_libro(int usuario_id = 0, string libro = "void", string tipo_operacion="vacio") {
	int indice = 0;

	for (int i = 0; i < 50; i++) {
		if (usuarios[usuario_id].libros_tratados[i][3] == "true" && usuarios[usuario_id].libros_tratados[i + 1][3] == "void") {
			indice = i + 1;
			break;
		}
	}
	for (int j = 0; j < 5; j++) {
		switch (j)
		{
		case 0:	usuarios[usuario_id].libros_tratados[indice][j] = libro;break;
		case 1: usuarios[usuario_id].libros_tratados[indice][j] = capture_time();break;
		case 2:	usuarios[usuario_id].libros_tratados[indice][j] = tipo_operacion;break;
		case 3:	usuarios[usuario_id].libros_tratados[indice][j] = "true";break;
		default:break;
		}
	}
}

extern int select() {
	string seleccion;
	while (true)
	{
		cout <<ORANGE<<"\t\t[!]"<< RESET<<LGREEN <<"Ingresar como " << RESET << YELLOW "administrador " << RESET << BG_ORANGE << BLUE"(1)"<< RESET<< endl;
		cout << ORANGE<<"\t\t[!]"<< RESET << LGREEN<< "Ingrsar como usuario normal " << RESET << BG_ORANGE << BLUE << "(2)"<< RESET << endl;
		cout <<YELLOW <<"\t\t--> "<< RESET; cin >> seleccion;
		if (verif_entero(seleccion)) { return stoi(seleccion);  }
		else { continue; }
	}
}


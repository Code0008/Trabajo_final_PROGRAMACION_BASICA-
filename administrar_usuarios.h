#pragma once
#include <iostream>
#include <stdio.h>
#include "FUNCIONALIDADES.h"
#include <string>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;
int verificar_clientes() {
	int totales_clientes = 0;
	for (int indice_cliente = 0; indice_cliente < 100; indice_cliente++) {
		if (clientes[indice_cliente].EDAD > 0) {
			totales_clientes++;
		}
	}

	return totales_clientes;
}


void ver_info_clinte(int indice_cliente) {
	cout << "\t\t\t\t" << CYAN; estetica(97, 219); cout << endl;
	cout << LGREEN << "\t\t\t\t\t[+] " << "ID_CLIENTE: " << clientes[indice_cliente].userID << endl;
	cout << LGREEN << "\t\t\t\t\t[+] " << "NOMBRE CLIENTE: " << clientes[indice_cliente].NOMBRE_APELLIDO << endl;
	cout << LGREEN << "\t\t\t\t\t[+] " << "DNI: " << clientes[indice_cliente].DNI << endl;
	cout << LGREEN << "\t\t\t\t\t[+] " << "EDAD: " << clientes[indice_cliente].EDAD << endl;
	cout << LGREEN << "\t\t\t\t\t[+] " << "SEXO: " << clientes[indice_cliente].SEXO << endl;
	cout << LGREEN << "\t\t\t\t\t[+] " << "PROVINCIA: " << clientes[indice_cliente].direccion.PROVINCIA << endl;
	cout << LGREEN << "\t\t\t\t\t[+] " << "DISTRITO: " << clientes[indice_cliente].direccion.DISTRITO << endl;
	cout << LGREEN << "\t\t\t\t\t[+] " << "DIRECCION: " << clientes[indice_cliente].direccion.DIRECCION << endl;
	cout << LGREEN << "\t\t\t\t\t[+] " << "CASA/APARTAMENTO: " << clientes[indice_cliente].direccion.CASA_DEPARTAMENTO << endl;
	cout << LGREEN << "\t\t\t\t\t[+] " << "NUMERO TELEFONICO " << clientes[indice_cliente].CELULAR << endl;
	cout << LGREEN << "\t\t\t\t\t[+] " << "correo: " << clientes[indice_cliente].correo_cliente.correo_contacto << endl;
	cout << LGREEN << "\t\t\t\t\t[+] " << "hora ingreso: " << clientes[indice_cliente].hora_operacion << endl;
	if (clientes[indice_cliente].tiene_sancion) {
		cout << "TIEMPO SANCION: " << clientes[indice_cliente].tiempo_sancion << endl;
	}
	see_matris(indice_cliente);
}


void modificar_atributos_clientes() {
	system("cls");
	int cliente_id;
	char sel;
	string nuevo_atributo;
	while (true) {
	
		cout << LGREEN << "\t\t\t\t\t[!]" << CYAN << " INGRESE EL ID DEL CLIENTE QUE QUIERE MODIFICAR: ";
		getline(cin, nuevo_atributo);

		if (verif_entero(nuevo_atributo)&& stoi(nuevo_atributo) <= verificar_clientes()) {
			cliente_id = stoi(nuevo_atributo);
			break;
		}
		else {
			cout << RED << "\t\t\t\t\t[!]" << RESET << ORANGE << "INGRESE UN VALOR VALIDO\n" << RESET;
		}

	}

	ver_info_clinte(cliente_id);

	while (true)
	{
		cout << MAGENTA << "\t\t\t\t";  estetica(97, 254); cout << RESET << endl;
		cout << LGREEN << "\t\t\t\t\t[!]" << CYAN << " INGRESE QUE ATRIBUTO QUIERE MODIFICAR";
		cout << LGREEN << "\t\t\t\t\t[!]" << CYAN << "EDITAR NOMBRE:" <<ROSE << "N" << endl;
		cout << LGREEN << "\t\t\t\t\t[!]" << CYAN << "EDITAR EDAD:" << ROSE << "E" << endl;
		cout << LGREEN << "\t\t\t\t\t[!]" << CYAN << "EDITAR DNI:" << ROSE << "D" << endl;
		cout << LGREEN << "\t\t\t\t\t[!]" << CYAN << "EDITAR DIRECCION:" << ROSE << "P" << endl;
		cout << LGREEN << "\t\t\t\t\t[!]" << CYAN << "EDITAR NUMERO DE CELULAR:" << ROSE << "T" << endl;
		cout << LGREEN << "\t\t\t\t\t[!]" << CYAN << "EDITAR CORREO: " << ROSE << "C" << endl;
		cout << RED << "\t\t\t\t\t[!!]" << ORANGE << " exit -> X" << endl;
		cout << LGREEN << "\t\t\t\t\t[+]" << ORANGE << " SELECCION -- > " << RESET; sel = _getch(); sel = toupper(sel);
			if (sel == 'X') {
				break;
			}
			switch (sel)
			{
			case 'M':
				while (true) {
					cout << LGREEN << "\n\t\t\t\t\t[+]" << ROSE << "INGRESE NUEVO NOMBRE:  " << RESET;
					getline(cin, nuevo_atributo); cout << endl;
					if (verif_string(nuevo_atributo) == false) {
						cout << RED << "\t\t\t\t\t[!!]" << ORANGE << " ESTA SEGURO??? Y/N " << endl;
						sel = _getch(); sel = toupper(sel);
						if (sel == 'Y') {
							clientes[cliente_id].NOMBRE_APELLIDO = nuevo_atributo;
							break;
						}
						else if (sel == 'N') {
							continue;
						}
						else {
							cout << RED << "\t\t\t\t\t[!]" << RESET << ORANGE << "INGRESE UN VALOR VALIDO\n" << RESET;
						}
					}
				}
				break;
			case 'E':
				cout << LGREEN << "\n\t\t\t\t\t[+]" << ROSE << "INGRESE NUEVA EDAD:  " << RESET;
				getline(cin, nuevo_atributo);
				if (verif_entero(nuevo_atributo)) {
					cout << RED << "\n\t\t\t\t\t[!!]" << ORANGE << " ESTA SEGURO??? Y/N " << endl;
					sel = _getch(); sel = toupper(sel);
					if (sel == 'Y') {
						clientes[cliente_id].EDAD = stoi(nuevo_atributo);
						break;
					}
					else if (sel == 'N') {
						continue;
					}
					else {
						cout << RED << "\n\t\t\t\t\t[!]" << RESET << ORANGE << "INGRESE UN VALOR VALIDO\n" << RESET;
					}
					
				}
				break;

			case 'D':
				cout << LGREEN << "\n\t\t\t\t\t[+]" << ROSE << "INGRESE NUEVA DNI:  " << RESET;
				getline(cin, nuevo_atributo);
				if (verif_dni(nuevo_atributo)) {
					cout << RED << "\n\t\t\t\t\t[!!]" << ORANGE << " ESTA SEGURO??? Y/N ";
					sel = _getch(); sel = toupper(sel);
					if (sel == 'Y') {
						clientes[cliente_id].DNI = nuevo_atributo;
						break;
					}
					else if (sel == 'N') {
						continue;
					}
					else {
						cout << RED << "\n\t\t\t\t\t[!]" << RESET << ORANGE << "INGRESE UN DNI VALIDO\n" << RESET;
					}
				}
				break;
			case 'P':
					cout << RED << "\n\t\t\t\t\t[!!]" << ORANGE << " ESTA SEGURO??? Y/N " ;
					sel = _getch(); sel = toupper(sel);
					if (sel == 'Y') {
						while (true) {
							cout << LGREEN << "\n\t\t\t\t\t[+]" << ROSE << "INGRESE NUEVA DIRECCION:  " << RESET;
							getline(cin, nuevo_atributo);
							if (verif_string(nuevo_atributo) == false  && nuevo_atributo.length() >= 5) {
								clientes[cliente_id].direccion.DIRECCION = nuevo_atributo;
								break;
							}
							else {
								cout << RED << "\n\t\t\t\t\t[!]" << RESET << ORANGE << "INGRESE UNA DIRECCION VALIDA\n" << RESET;
							}
						}
						while (true) {
							see_distritos();
							cout << LGREEN << "\n\n\t\t\t\t\t[!]" << RESET << CYAN << "Ingrese su distrito: " << RESET; getline(cin, nuevo_atributo);
							if (verif_distrito(nuevo_atributo) && nuevo_atributo.length() >= 5) {
								clientes[cliente_id].direccion.DISTRITO = nuevo_atributo;
								break;
							}
							else { cout << RED << "\n\t[!]" << RESET << ORANGE << "Ingrese un distrito\n" << RESET << endl; }
						}
						break;
					}
					else if (sel == 'N') {
						continue;
					}
				break;
			case 'T':
				while (true) {
					cout << LGREEN << "\n\t\t\t\t\t[!]" << RESET << CYAN << "Ingrese su numero telefonico: " << RESET;  cin >> nuevo_atributo;
					if (verif_telefono(nuevo_atributo) == false) { nuevo_atributo = " "; cout << RED << "\n\t\t\t\t[!]" << RESET << ORANGE << " Ingreso de forma erronea el numero telefnoico\n" << RESET; }
					else { clientes[cliente_id].CELULAR = nuevo_atributo; break; }
				}
				break;
			case 'C':

				while (true) {
					cout << LGREEN << "\n\t\t\t\t\t[!]" << RESET << CYAN << "Ingrese su correo electorico: " << RESET;  cin >> nuevo_atributo;
					if (verif_correo(nuevo_atributo)) { nuevo_atributo = " "; cout << RED << "\n\t\t\t\t[!]" << RESET << ORANGE << " Ingreso de forma erronea su correo\n" << RESET; }
					else { clientes[cliente_id].correo_cliente.correo_contacto = nuevo_atributo; break; }
				}
				break;
			default:
				break;
			}

		
		system("cls");
		ver_info_clinte(cliente_id);

	}

}




void ver_clientes_actuales() {
	system("cls");
		if (verificar_clientes() == 0) {
			cout << LGREEN << "\t\t\t\t\t[+] " << "NO HAY CLIENTES REGISTRADO " << endl;
		}
		else {
			for (int indice_cliente = 0; indice_cliente < verificar_clientes(); indice_cliente++) {
				ver_info_clinte(indice_cliente);
			}
		}
}

char valid_comand(string comandos) {
	if (comandos=="ver_clientes") {
		return 'v';
	}
	if (comandos == "cls") {
		return 'c';
	}
	if (comandos == "modificar_atributo") {
		return 'm';
	}

	return '_';
}

extern void main_administrar_cliente(int usuario_id) {

	string comando;
	while (true)
	{
		cout << endl<<MAGENTA << "\t\t\t\t";  estetica(97, 254); cout << RESET << endl;
		cout << "\t\t\t\t\t\t\t"<<CYAN<<"FUNCION-->"<< ROSE <<" COMMANDO" << endl;
		cout << LGREEN << "\t\t\t\t\t[!]" << CYAN << " Ver clientes actuales ->" << ROSE << "ver_clientes" << endl;
		cout << LGREEN << "\t\t\t\t\t[!]" << CYAN << " modificar data de cliente ->" << ROSE << "modificar_atributo" << endl;
		cout << LGREEN << "\t\t\t\t\t[!!]" << ROSE << " limpiar pantalla -> cls" << endl;
		cout << RED << "\t\t\t\t\t[!!]" << ORANGE << " exit -> exit" << endl;
		cout << LGREEN << "\t\t\t\t\t[+]" << ORANGE << " -- > " << RESET; getline(cin, comando);
		if (verif_string(comando) == false) {
			if (comando == "exit") {
				break;
			}
			switch (valid_comand(comando))
			{
			case 'v':
				cout << "\t\t\t\t" << CYAN; estetica(97, 219); cout << endl;
				ver_clientes_actuales();
				cout << "\t\t\t\t" << CYAN; estetica(97, 219); cout << endl;
				break;
			case 'c':
				system("cls"); break;

			case 'm':
				modificar_atributos_clientes();
			default:
				cout << RED << "\t\t\t\t\t[!] " << RESET << ORANGE << "INGRESE COMANDO VALIDO" << RESET << endl;
				break;
			}
		}
		else {
			cout << RED << "\t\t\t\t\t[!] " << RESET << ORANGE << "DISCULPE NO PUEDE INGRESAR" << RESET << endl;
		}
	}

}


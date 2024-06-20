#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "INFO_DE_MENUS.h"
#include "FUNCIONALIDADES.h"
#include "funcionalidades_prestamo.h"
#include "funcionalidades_devolucion.h"
#include "administradores.h"
#include <string>
//#include "TESTS.h"
#include "COLORAMA.h"
using namespace std;
int main() {
	RESET;
	int id_cliente = 0;
	system("mode con: cols=150 lines=50");
	while (true) {
		string seleccion;
		menu_seleccion();
		switch (select()) {
		case 1:
			system("cls");
			menu_adminsitrador();
			informacion_administrador();
			break;
		case 2:
			system("cls");
			cin.ignore();
			menu_login();
			obtener_informacion_usuario(id_cliente);
			generar_matris();
			while (true) {
				system("cls");
				menu_principal();  cout << endl;
				while (true) {
					cin.ignore();
					cout << ORANGE << "\t[!]" << RESET << LGREEN << " Ingrese seleccion: " << RESET;
					getline(cin, seleccion);
					if (verif_entero(seleccion)) { if (stoi(seleccion) == 1 || stoi(seleccion) == 2) { break; } else { cout << RED << "\t[!]" << RESET << ORANGE << "Ingrese una opcion valida!\n" << RESET; continue; } }
					else { cout << RED << "\t[!]" << RESET << ORANGE << "Ingrese una opcion valida!\n" << RESET; }
				}
				switch (stoi(seleccion))
				{
				case 1:
					if (verif_sancion(id_cliente)) {
						menu_de_sancion();
						break;
					}
					system("cls");
					menu_prestamo();
					obtener_informacion_prestamo(id_cliente);
					boleta_prestamo(id_cliente);
					break;
				case 2:
					menu_devulocion();
					obtener_informacion_devolucion(id_cliente);
					boleta_devolucion(id_cliente);
					break;
				default:
					break;
				}
				if (respuesta_continuar() != true) {
					id_cliente++;
					break; }
			} 
		case 3:
			cout << "prueba caso 3";
			break;
		}
		
	}
	return 0;
}


/*int main() {

	generar_matris_barras();
	generar_datos();
	see_first_semes();
	see_Data();
}*/

// CODIGO PENDEJO DE PENDEJOS ECHO PARA PENDEJOS

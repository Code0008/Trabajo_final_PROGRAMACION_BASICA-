#include "INFO_DE_MENUS.h"
#include "FUNCIONALIDADES.h"
#include "funcionalidades_prestamo.h"
#include "funcionalidades_devolucion.h"
#include "administradores.h"
//#include "TESTS.h"
#include "COLORAMA.h"
#include "cabecera_principales.h"

using namespace std;
int main() {
	RESET;
	int id_cliente = 0;
	string seleccion;
	char sel;
	int comentario_id=0;
	system("mode con: cols=200 lines=50");
	while (true) {
		menu_seleccion();
		switch (select()) {
		case '1':
			system("cls");
			menu_adminsitrador();
			informacion_administrador();
			
			break;
		case '2':
			system("cls");
			menu_login();
			obtener_informacion_usuario(id_cliente);
			generar_matris();
			while (true) {
				system("cls");
				menu_principal();  cout << endl;
				cin.ignore();
				while (true) {
					cout << ORANGE << "\t\t\t\t\t\t [!]" << RESET << LGREEN << " Ingrese seleccion: " << RESET;
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
					system("cls");
					menu_devulocion();
					obtener_informacion_devolucion(id_cliente);
					boleta_devolucion(id_cliente);
					while (true) {
						cout << endl;
						cout << ORANGE << "\t\t\t\t\t\t [!]" << RESET << LGREEN << " QUIERE REALIZAR COMENTARIO? Y/N" << RESET;
						cout << YELLOW << "\n\t\t\t\t\t" << (char)219 << "\t--> " << RESET; sel = _getch(); cout << endl;
						if (sel == 'Y' || sel == 'y') {
							make_comentario(id_cliente, comentario_id);
							comentario_id++;
							break;
						}
						else { break; }
					}
					break;
				default:
					break;
				}
				if (respuesta_continuar() != true) {
					system("cls");
					id_cliente++;
					cin.ignore();
					break;
				}
			} break;
		case '3':
			cout << "prueba caso 3";
			break;
		}
		
	}
	return 0;
}


#pragma once
#include "STRUCTURAS.h"
#include "COLORAMA.h"
#include "cabecera_principales.h"

using namespace std;


bool verif_string(string texto);
bool verif_dni(string dni);
bool verif_telefono(string telefono);
bool verif_entero(string entero);


bool verif_correo(string correo) {
	for (int i = 0; i < correo.length(); i++) {
		if (correo[i] == '@') {
			return true;
		}
	}
	return false;
}


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

extern bool verif_distrito( string distro_del_cliente) {
	for (int i = 0; i < 43; i++) {
		if (distritos[i] == distro_del_cliente) {
			return true;
		}
	}
	return false;
}
extern void see_distritos() {
	cout << "\t\t\t\t\t\t"<<YELLOW << "LISTA DE DISTRITOS DISPONIBLES" << endl;
	cout << "\t\t\t\t  "<<BLUE; estetica(60, 219); cout << RESET<<endl;
	int count = 0;
	for (int i = 0; i < 43; i++) {
		count++;
		cout <<ROSE <<"\t\t\t" << setw(28);
		cout << distritos[i];
		if (count == 2) {
			cout << endl;
			count = 0;
		}
	}
	cout << endl;
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
	char seleccione;
	clientes[id_usuario].hora_operacion = capture_time();
	clientes[id_usuario].userID = id_usuario;
	cout << RED << "\n\t\t\t\t[!]" << RESET << ORANGE << " ECUERDE PUEDE EDITAR LA INFORMACION DEJANDO UN MENSAJE A LOS ADMINISTRADORES\n" << RESET;
	while (true) {
		cout << LGREEN << "\t\t\t\t\t[!]" << RESET << CYAN << "Ingrese su nombre o nombre de usuario " << RESET; getline(cin, clientes[id_usuario].NOMBRE_APELLIDO);
		if (verif_string(clientes[id_usuario].NOMBRE_APELLIDO)) { cout << RED << "\t[!]" << RESET << ORANGE << "INGRESE BIEN EL NOMBRE\n" << RESET; }
		else { break; }
	}
	while (true) {
		cout << LGREEN << "\t\t\t\t\t[!]" << RESET << CYAN << "Ingrese su edad: " << RESET; cin >> ingreso_jugar;
		if (verif_entero(ingreso_jugar)) { clientes[id_usuario].EDAD = stoi(ingreso_jugar); break; }
		else { cout << RED << "\t\t\t\t[!]" << RESET << ORANGE << " Ingrese bien su edad!\n" << RESET; }
	}
	cin.ignore();
	while (true) {

		cout << LGREEN << "\t\t\t\t\t[+] "<<CYAN<<"Seleccion de sexo : \n\t\t\t\t\t->(1)Masculino\n\t\t\t\t\t->(2)Femenino\n\t\t\t\t\t->(3)Cabrin" << RESET << YELLOW << "\n\t\t\t\t\t--> " << RESET;; seleccione = _getch();
		if (seleccione == '1' || seleccione=='2'||seleccione=='3') {
			break;
		}
		else { cout <<endl<<endl<< RED << "\t\t\t\t[!]" << RESET << ORANGE << "Ingrese un valor correcto!\n " << RESET; }
	}
	switch (seleccione)
	{
	case '1': clientes[id_usuario].SEXO = 'M'; break; case '2': clientes[id_usuario].SEXO = 'F'; break; case '3': clientes[id_usuario].SEXO = 'N'; break; default:break;
	}
	cout << endl;
	while (true) {
		see_distritos();
		cout << LGREEN << "\t\t\t\t\t[!]" << RESET << CYAN << "Ingrese su distrito: " << RESET;; getline(cin, ingreso_jugar);
		if (verif_distrito(ingreso_jugar) && ingreso_jugar.length()>=5) {
				clientes[id_usuario].direccion.DISTRITO = ingreso_jugar;
				break;
		}
		else { cout << RED << "\t[!]" << RESET << ORANGE << "Ingrese un distrito\n" << RESET << endl; }
	}
	while (true) {
		cout << LGREEN << "\t\t\t\t\t[!]" << RESET << CYAN << "Ingrese su direccion: " << RESET;;  getline(cin, ingreso_jugar);
		if (ingreso_jugar.length() >= 5) {

			clientes[id_usuario].direccion.DIRECCION = ingreso_jugar;
			break;
		}
		else { continue; }
	}
	seleccione = '0';
	while (true) {
		cout << LGREEN << "\t\t\t\t\t[+]"<<CYAN<<"Seleccione:\n\t\t\t\t\t-->(1)Casa\n\t\t\t\t\t-->(2)Departamento" << RESET << YELLOW << "\n\t\t\t\t\t--> " << RESET; seleccione = _getch();
		if (seleccione == '1' || seleccione == '2') {
			break;
		}
		else { cout << RED << "\n\t\t\t\t[!]" << RESET << ORANGE << "Ingrese un valor correcto!\n " << RESET; }
	}
	switch (seleccione)
	{
	case '1':  clientes[id_usuario].direccion.CASA_DEPARTAMENTO = "CASA"; break; case '2':  clientes[id_usuario].direccion.CASA_DEPARTAMENTO = "DEPARTAMENTO"; break; default:break;
	}
	cout << endl;
	while (true) {
		cout << LGREEN << "\t\t\t\t\t[!]" << RESET << CYAN << "Ingrese su numero telefonico: " << RESET;  cin >> ingreso_jugar;
		if (verif_telefono(ingreso_jugar) == false) { ingreso_jugar = " "; cout << RED << "\n\t\t\t\t[!]" << RESET << ORANGE << " Ingreso de forma erronea el numero telefnoico\n" << RESET; }
		else { clientes[id_usuario].CELULAR = ingreso_jugar; break; }
	}
	
}

extern bool respuesta_continuar() {
	char respuesta;
	cout << endl;
	while (true) {
		cout << LBLUE << "\t\t\t\t\t[!]desea hacer otra operacion?:<<" << RESET << RED" Y/N " << RESET ;
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


extern bool verif_sancion(int cliente_id = 0) {
	if (clientes[cliente_id].tiene_sancion == true) {
		return  true;
	}
	else { return false; }
}


extern void append_libro(int cliente_id = 0, string libro = "void", string tipo_operacion="vacio") {
	int indice = 0;

	for (int i = 0; i < 50; i++) {
		if (clientes[cliente_id].libros_tratados[i][3] == "true" && clientes[cliente_id].libros_tratados[i + 1][3] == "void") {
			indice = i + 1;
			break;
		}
	}
	for (int j = 0; j < 5; j++) {
		switch (j)
		{
		case 0:	clientes[cliente_id].libros_tratados[indice][j] = libro;break;
		case 1: clientes[cliente_id].libros_tratados[indice][j] = capture_time();break;
		case 2:	clientes[cliente_id].libros_tratados[indice][j] = tipo_operacion;break;
		case 3:	clientes[cliente_id].libros_tratados[indice][j] = "true";break;
		default:break;
		}
	}
}

extern int select() {
	char seleccion;
	while (true)
	{
		cout << "\t\t\t\t"<<BLUE; estetica(49, 219); cout <<RESET<< endl; 
		cout << ORANGE << "\t\t\t\t\t" << (char)219<< ORANGE << "\t\t\t\t\t\t" << (char)219 << endl;
		cout <<ORANGE <<"\t\t\t\t\t"<< (char)219  <<  "\t[!]"<< RESET<<LGREEN <<"Ingresar como " << RESET << YELLOW "USUARIO " << RESET << BG_ORANGE << BLUE"(1)"<< RESET<< ORANGE << "\t\t" << (char)219  << endl;
		cout << ORANGE<<"\t\t\t\t\t" << (char)219 << "\t[!]"<< RESET << LGREEN<< "Ingrsar como cliente normal " << RESET << BG_ORANGE << BLUE << "(2)"<< RESET << ORANGE << "\t" << (char)219 << endl;
		cout << YELLOW << "\t\t\t\t\t" << (char)219 << "\t--> " << RESET; seleccion = _getch(); cout << endl;
		if (seleccion == '1' || seleccion == '2' || seleccion == '3') { return seleccion; }
		else { cout << endl; continue; }
	}
}


#pragma once
#include <stdio.h>
#include <conio.h>

using namespace std;


struct LIBRO {
	int codigo_libro;
	string tipo_libro;
	string titutlo_libro;
	bool prestado;
};

struct direccion_usuario {
	string DIRECCION = "void";
	string DISTRITO = "void";
	string PROVINCIA = "LIMA";
	string CASA_DEPARTAMENTO = "void";
};

struct USUARIO {
	int userID = 0;
	string DNI = "void";
	string NOMBRE_APELLIDO;
	int EDAD=0;
	char SEXO=0;
	direccion_usuario direccion;
	string CELULAR = "void";
	string hora_operacion = "void";
	string correo = "void";
	string** libros_tratados = new string*[100];
	bool tiene_sancion=false;
	string tiempo_sancion = "NO PRESENTA";
	/*
	*	0			1				2								3										4			
		| codigo | hora_tratado | operacion que se realizo(P/D) | Verificador_coompleto_operacion | tipo libro|
		1 fila  3 columnas

	*/
};

struct ADMINISTRADOR {

	string nombre_adminsitrador;
	string password;
	string hora_acceso;
	string correo_contacto;
	bool see_reportes = false;
	bool adm_users = false;
	/*
	Ver reportes | Desbloquear/Bloquear usuarios |
	|     V/F    | V/F							 |
	*/
};

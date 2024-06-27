#pragma once
#include <stdio.h>
#include <conio.h>
#include "Funcionalidad_reporte_grafico_de_barras.h"

using namespace std;


struct LIBRO {
	int codigo_libro;
	char tipo_libro;
	string titutlo_libro;
	bool prestado;
	float estrellas;
};

struct direccion_usuario {
	string DIRECCION = "void";
	string DISTRITO = "void";
	string PROVINCIA = "LIMA";
	string CASA_DEPARTAMENTO = "void";
};
struct almacenamiento_matrices {
	string** almacenamiento = new string * [100];
};

struct correo {
	string correo_contacto = "no presenta";
};
struct CLIENTE {
	int userID = 0;
	string DNI = "void";
	string NOMBRE_APELLIDO;
	int EDAD=0;
	char SEXO=0;
	direccion_usuario direccion;
	string CELULAR = "void";
	string hora_operacion = "void";
	correo correo_cliente;
	string** libros_tratados = new string*[100]; //inventario
	almacenamiento_matrices log_de_cliente;
	bool tiene_sancion=false;
	string tiempo_sancion = "NO PRESENTA";
	/*
	*	0			1				2								3										4			
		| codigo | hora_tratado | operacion que se realizo(P/D) | Verificador_coompleto_operacion | tipo libro|
		1 fila  3 columnas

	*/
};




struct USUARIO {
	string nombre_adminsitrador;
	string password;
	string hora_acceso;
	correo correo_usuario;
	bool see_reportes = false;
	bool adm_users = false;
	almacenamiento_matrices mensajes_usuario;
	almacenamiento_matrices log_usuario;
	/*
	Ver reportes | Desbloquear/Bloquear usuarios |
	|     V/F    | V/F							 |
	*/
	/*
	* 0				1						2				3					
	|indice_usuario| hora de ejecucion | proceso_ejecucion | verifiacdor
	*/
};

struct COMENTARIO {
	int comentario_id;
	int cliente_id;
	string comentario;
	string tiempo;
};
extern USUARIO usuarios[2] = {
	{"EnzoFavito", "Ufrjqf", "void", "enzofavito@biblio.com", true, true},
	{"RalphSito", "Xmfnijq","void", "ralphxshaiel@teamoshaiel.com", true, false}
};
LIBRO* inventario = new LIBRO[100];
COMENTARIO* comentarios = new COMENTARIO[100];
CLIENTE* clientes = new CLIENTE[100];
LIBRO inventario_disponible[15] = {
	{202412340, 'L', "EL_QUIJOTE_DE_LA_MANCHA", false, 5.0},
	{202414555, 'L', "CIEN_AÑOS_DE_SOLEDAD", false, 4.7},
	{202417888, 'L', "DON_QUIJOTE", false, 5.0},
	{202420111, 'L', "LA_CASA_DE_LOS_ESPIRITUS", false, 3.4},
	{202421222, 'L', "1984", false, 5.0},
	{202424555, 'L', "LA_RUTA_DEL_TILIN", false, 5.0},
	{202413830, 'R', "NAT_GEO_NEW_PUBLICATION", false , 4.5},
	{202415666, 'R', "TIME_MAGAZINE", false,3.3},
	{202418999, 'R', "SCIENTIFIC_AMERICAN", false, 3.9},
	{202422333, 'R', "FORBES", false, 5.0},
	{202425666, 'R', "THE_ECONOMIST", false, 5.0},
	{202412334, 'P', "ABEJA_REPUBLICANA", false, 5.0},
	{202416777, 'P', "NEW_YORK_TIMES", false, 4.9},
	{202419000, 'P', "WASHINGTON_POST", false, 4.5},
	{202423444, 'P', "THE_GUARDIAN", false, 2.5}
};

string distritos[43] = {

		 "Barranco", "Breña", "Carabayllo", "Cercado de Lima",
		"Cieneguilla", "Comas", "El Agustino", "Independencia", "Jesús María", "La Molina", "La Victoria",
		"Lince", "Los Olivos", "Lurín", "Magdalena del Mar", "Miraflores",
		"Pucusana", "Pueblo Libre", "Puente Piedra", "Punta Hermosa", "Punta Negra", "Rímac", "San Bartolo",
		"San Borja", "San Isidro", "San Juan de Lurigancho", "San Juan de Miraflores", "San Luis",
		"San Martín de Porres", "San Miguel", "Santa Anita",
		"Santiago de Surco", "Surquillo", "Villa El Salvador", "Villa María del Triunfo",
		"Bellavista", "Callao", "Carmen de La Legua Reynoso", "La Perla", "La Punta", "Ventanilla", "Mi Perú"

};

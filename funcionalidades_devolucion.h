#pragma once
#include <iostream>
#include <stdio.h>
#include "FUNCIONALIDADES.h"
#include <string>
#include <string>
#include <cctype>
#include <ctime>


using namespace std;



bool verif_date(string date_string, int menos_dias = 0, int usuario_id = 0) {
    bool verife = false;
    string year = "";
    string moth = "";
    string day = "";

    int end_days[] = { 31, 29, 31, 30, 31, 30 };
    int n = sizeof(end_days) / sizeof(end_days[0]);
    for (int i = 0; i < date_string.length(); i++) {
        if (date_string[i] == '-') {
            i += 1;
        }
        if (i < 4) {
            if (isdigit(date_string[i])) {
                year += date_string[i];
            }
            else {
                break;
            }
        }
        if (i < 7 && i >= 5) {
            if (isdigit(date_string[i])) {
                moth += date_string[i];
            }
            else {
                break;
            }
        }
        if (i >= 8 && i <= 9) {
            if (isdigit(date_string[i])) {
                day += date_string[i];
            }
            else {
                break;
            }
        }
    }
    string fecha_real;
    string current = "";
    bool verif_fecha_ingresada = false;
    for (int i = 0; i < moth.length(); i++) {
        if (moth[i] != '0') {
            current += moth[i];
        }
    }

    if (stoi(moth) <= 7 && stoi(day) < 31) {
        fecha_real += year;
        fecha_real += current;
        fecha_real += day;
        verif_fecha_ingresada = true;
    }
    if (verif_fecha_ingresada == false){
        return false;
    }

    // 2024-06-7
    ///// TERMINAMOS VERIFICACION DE FECHA INGRESADA 
    string fecha_devol;
    time_t timestamp;
    tm tiempo;
    time(&timestamp);
    localtime_s(&tiempo, &timestamp);
    int dia_final = end_days[stoi(current)-1];
    int dia_del_año = (stoi(current) * dia_final) - (30 - stoi(day)); // dia del año de la fecha real
    cout << dia_del_año << "traza dia del año" << endl;
    cout << "dia final" << dia_final << endl;
    cout << "dia deñ año tm " << tiempo.tm_yday << endl;
    if (dia_del_año <= tiempo.tm_yday-5) {
        usuarios[usuario_id].tiene_sancion = true;
          return true;
    }
    else {
        return true;
    }

}

static string tiempo_sancion() {
    string fecha_sancion;
    time_t timestamp;
    tm tiempo;
    time(&timestamp);
    localtime_s(&tiempo, &timestamp);
    fecha_sancion.append(to_string(tiempo.tm_mon + 2)); fecha_sancion.append("/");
    fecha_sancion.append(to_string(tiempo.tm_mday));
    return fecha_sancion;
}




static bool verif_codigo_libro_devolucion(string codigo_libro) {
    int n = sizeof(inventario_disponible) / sizeof(inventario_disponible[0]);
    if (verif_entero(codigo_libro)) {
        if (codigo_libro.length() == 9) {
            return true;
        }
    }
    return false;
}



extern void obtener_informacion_devolucion(int usuario_id = 0) { // veces_ejecutado para filas
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
        if (verif_codigo_libro_devolucion(var_to_game)) {
            append_libro(usuario_id, var_to_game);
            break;
        }
        else {
            cout << RED << "\t[!]" << RESET << ORANGE << " Ingrese de forma valida su codigo!\n" << RESET;
        }
    }
    while (true) {
        cout << "\n\t[+]Ingrese la fecha real devolucion(2024-xx-xx) "; getline(cin, var_to_game);
        if (verif_date(var_to_game, 5, usuario_id)) {
           
            break;
        }
        else { cout << RED << "\t[!]" << RESET << ORANGE << " Ingrese bien su DNI!\n" << RESET; }
    }


    if (usuarios[usuario_id].tiene_sancion) {
        cout << "Usted tiene una sancion de 1 mes corriendo desde hoy dia hasta " << tiempo_sancion() << endl;
        usuarios[usuario_id].tiempo_sancion = tiempo_sancion();
    }
    else {
        cout << "Felicidades usted esta en tiempo de entrega!" << endl;
    }
}

extern void boleta_devolucion(int usuario_id = 0) {
    estetica(100, '_'); cout << endl;
    cout << "\tID DEL USUARIO: "; estetica(5, '-'); cout << " " << usuarios[usuario_id].userID << endl;
    cout << "\tDNI del usuario: "; estetica(5, '-'); cout << " " << usuarios[usuario_id].DNI << endl;
    cout << "\tNombres y apellidos: "; estetica(5, '-'); cout << " " << usuarios[usuario_id].NOMBRE_APELLIDO << endl;
    cout << "\tEdad: "; estetica(5, '-'); cout << " " << usuarios[usuario_id].EDAD << endl;
    cout << "\tSexo: "; estetica(5, '-'); cout << " " << usuarios[usuario_id].SEXO << endl;
    cout << "\tCasa: "; estetica(5, '-'); cout << " " << usuarios[usuario_id].direccion.CASA_DEPARTAMENTO << endl;
    cout << "\tDireccion: "; estetica(5, '-'); cout << " " << usuarios[usuario_id].direccion.DIRECCION << endl;
    cout << "\tDistrito: "; estetica(5, '-'); cout << " " << usuarios[usuario_id].direccion.DISTRITO << endl;
    cout << "\tProvincia: "; estetica(5, '-'); cout << " " << usuarios[usuario_id].direccion.PROVINCIA << endl;
    cout << "\tCelular: "; estetica(5, '-'); cout << " " << usuarios[usuario_id].CELULAR << endl;
    cout << "\tHora: "; estetica(5, '-'); cout << " " << usuarios[usuario_id].hora_operacion << endl;
    cout << "\tSancion: "; estetica(5, '-'); cout << " " << usuarios[usuario_id].tiene_sancion << endl;
    cout << "\tTiempo sancion: "; estetica(5, '-'); cout << " " << usuarios[usuario_id].tiempo_sancion << endl;
    estetica(100, '_'); cout << endl;
    see_matris(usuario_id);

}
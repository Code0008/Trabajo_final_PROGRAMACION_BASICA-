#pragma once
#include <iostream>
#include <stdio.h>
#include "FUNCIONALIDADES.h"
#include <string>
#include <string>
#include <cctype>
#include <ctime>


using namespace std;

bool verif_date(string date_string, int menos_dias = 0, int cliente_id = 0) {


    switch (date_string.length()){
    case 9:  break;
    case 10: break;
    default: return false; break;
    }
    int count_verif_ = 0;
    for (int i = 0; i < date_string.length(); i++) {
        if (date_string[i] == '-') {
            count_verif_++;
        }
    }
    if (count_verif_ != 2) {
        return false;
    }
    bool verife = false;
    string year = "";
    string moth = "";
    string day = "";
    string fecha_devol;
    time_t timestamp;
    tm tiempo;
    time(&timestamp);
    localtime_s(&tiempo, &timestamp);
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

    if (stoi(moth) < 7 && stoi(day) < 31 && stoi(day)<= tiempo.tm_mday) {
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
  
    int dia_final = end_days[stoi(current)-1];
    int dia_del_ano = (stoi(current) * dia_final) - (30 - stoi(day)); // dia del año de la fecha real

    if (dia_del_ano <= tiempo.tm_yday-menos_dias) {
        clientes[cliente_id].tiene_sancion = true;
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

extern void obtener_informacion_devolucion(int cliente_id = 0) { // veces_ejecutado para filas
    string var_to_game;
    cout << endl;
    if (clientes[cliente_id].informacion_cliente.DNI == "void") {
        while (true) {
            cout << LGREEN << "\t\t\t\t\t[!]" << RESET << CYAN << " INGRESE SU DNI: " << RESET;  getline(cin, var_to_game);
            if (verif_dni(var_to_game)) {
                clientes[cliente_id].informacion_cliente.DNI = var_to_game; break;
            }
            else { cout << RED << "\t\t\t\t\t[!]" << RESET << ORANGE << " Ingrese bien su DNI!\n" << RESET; }
        }
    }
    while (true) {
        var_to_game = "";
        cout << LGREEN << "\t\t\t\t\t[!]" << RESET << CYAN << " INGRESE CODIGO DEL LIBRO: " << RESET;  getline(cin, var_to_game);
        if (verif_codigo_libro_devolucion(var_to_game)) {
            append_libro(cliente_id, var_to_game, "devolucion");
            break;
        }
        else {
            cout << RED << "\t\t\t\t\t[!]" << RESET << ORANGE << " Ingrese de forma valida su codigo!\n" << RESET;
        }
    }
    char tipo_publi ;
    int tipo_publi_dias = 0;
    while (true)
    {
        cout << LGREEN << "\t\t\t\t\t[!]" << RESET << CYAN << " INGRESE TIPO DE PUBLICACION (R)EVISTA/(L)IBRO/(): " << RESET;
        tipo_publi = _getch();
        tipo_publi = toupper(tipo_publi);
        if (tipo_publi == 'R' || tipo_publi == 'L' || tipo_publi == 'P') {
            break;
        }
        else { cout << RED << "\t\t\t\t\t[!]" << RESET << ORANGE << " Ingrese un tipo de publicacion correcta!\n" << RESET; }
    }
    switch (tipo_publi)
    {
    case 'R': tipo_publi_dias = 5; break;
    case 'L': tipo_publi_dias = 5; break;
    case 'P': tipo_publi_dias = 4; break;
    }
    cout << endl;
    while (true) {
        cout << LGREEN << "\t\t\t\t\t[+]" << RESET << CYAN << "Ingrese la fecha real devolucion(2024-mes-dia) " << RESET; ; getline(cin, var_to_game);
        if (verif_date(var_to_game, tipo_publi_dias, cliente_id)) {
           
            break;
        }
        else { cout << RED << "\t\t\t\t\t[!]" << RESET << ORANGE << " Ingrese bien la fecha!\n" << RESET; }
    }


    if (clientes[cliente_id].tiene_sancion) {
        cout << "\t\t\t\t\ttUsted tiene una sancion de 1 mes corriendo desde hoy dia hasta " << tiempo_sancion() << endl;
        clientes[cliente_id].tiempo_sancion = tiempo_sancion();
    }
    else {
        cout << "\t\t\t\t\t[!!]Felicidades usted esta en tiempo de entrega!" << endl;
    }
}

extern void boleta_devolucion(int cliente_id = 0) {
    cout << "\t\t\t\t\t" << GRAY; estetica(65, '_'); cout << endl;
    cout << "\t\t\t\t\t\t\t\t" << LGREEN << "BOLETA FINAL DEL USUARIO" << RESET << endl;
    cout << "\t\t\t\t\t"; estetica(65, '_'); cout << endl;
    cout << "\t\t\t\t\t\t" << (char)186; estetica(7, ' '); cout << CYAN << "ID USUARIO" << (char)175 << " " << clientes[cliente_id].userID << RESET << endl;
    cout << "\t\t\t\t\t\t" << GRAY << (char)186; estetica(7, ' '); cout << LGREEN << "DNI" << (char)175 << " " << clientes[cliente_id].informacion_cliente.DNI << RESET << endl;
    cout << "\t\t\t\t\t\t" << GRAY << (char)186; estetica(7, ' '); cout << LGREEN << "NOMBRE" << (char)175 << " " << clientes[cliente_id].informacion_cliente.NOMBRE_APELLIDO << RESET << endl;
    cout << "\t\t\t\t\t\t" << GRAY << (char)186; estetica(7, ' '); cout << LGREEN << "EDAD" << (char)175 << " " << clientes[cliente_id].informacion_cliente.EDAD << RESET << endl;
    cout << "\t\t\t\t\t\t" << GRAY << (char)186; estetica(7, ' '); cout << LGREEN << "SEXO" << (char)175 << " " << clientes[cliente_id].informacion_cliente.SEXO << RESET << endl;
    cout << "\t\t\t\t\t\t" << GRAY << (char)186; estetica(7, ' '); cout << LGREEN << "TIPO DOMICILIO" << (char)175 << " " << clientes[cliente_id].direccion.CASA_DEPARTAMENTO << RESET << endl;
    cout << "\t\t\t\t\t\t" << GRAY << (char)186; estetica(7, ' '); cout << LGREEN << "DIRECCION" << (char)175 << " " << clientes[cliente_id].direccion.DIRECCION << RESET << endl;
    cout << "\t\t\t\t\t\t" << GRAY << (char)186; estetica(7, ' '); cout << LGREEN << "DISTRITO" << (char)175 << " " << clientes[cliente_id].direccion.DISTRITO << RESET << endl;
    cout << "\t\t\t\t\t\t" << GRAY << (char)186; estetica(7, ' '); cout << LGREEN << "PROVINCIA" << (char)175 << " " << clientes[cliente_id].direccion.PROVINCIA << RESET << endl;
    cout << "\t\t\t\t\t\t" << GRAY << (char)186; estetica(7, ' '); cout << LGREEN << "NUMERO DE CELULAR" << (char)175 << " " << clientes[cliente_id].contacto.CELULAR << RESET << endl;
    cout << "\t\t\t\t\t\t" << GRAY << (char)186; estetica(7, ' '); cout << CYAN << "HORA DE INGRESO" << (char)175 << " " << clientes[cliente_id].hora_operacion << endl << RESET;
    cout << "\t\t\t\t\t\t" << GRAY << (char)186; estetica(7, ' '); cout << CYAN << "HORA DE INGRESO" << (char)175 << " " << clientes[cliente_id].tiene_sancion << endl << RESET;
    cout << "\t\t\t\t\t\t" << GRAY << (char)186; estetica(7, ' '); cout << CYAN << "HORA DE INGRESO" << (char)175 << " " << clientes[cliente_id].tiempo_sancion << endl << RESET;
    cout << "\t\t\t\t\t" << GRAY; estetica(64, 238); cout << endl;
    cout << CYAN << "\t\t\t\t\t\t\tINVENTARIO ACTUAL DEL CLIENTE " << endl;
    cout << BLUE << "\t\t\t\t\t"; estetica(65, '_'); cout << endl;
    see_matris(cliente_id);
    cout << BLUE << "\t\t\t\t\t"; estetica(65, '_'); cout << endl;

}

extern void make_comentario(int cliente_id, int comentari_id) {
    system("cls");
    cout << BLUE << "\t\t\t";  estetica(80, 219);
    cout << endl << endl << endl << endl;
    cout << LGREEN << "\t\t\t\t\t[!]" << RESET << CYAN << " BIENVENIDO AL APARTADO DE COMENTARIOS " << clientes[cliente_id].informacion_cliente.NOMBRE_APELLIDO<< RESET<<endl;  
    comentarios[comentari_id].comentario_id = comentari_id;
    comentarios[comentari_id].cliente_id = cliente_id;
    string mensaje;

    while (true) {
        cout << LGREEN << "\t\t\t\t\t[++]" << RESET << CYAN << " INGRESE SU correo electronico: " << RESET;
        getline(cin, mensaje);
        if (verif_correo(mensaje)) {
            clientes[cliente_id].contacto.correo_contacto = mensaje;
            break;
        }
        else {
            cout << RED << "\n\t\t\t\t[!]" << RESET << ORANGE << " Ingreso de forma erronea su correo\n" << RESET;
        }
        
    }
    cout << LGREEN << "\t\t\t\t\t[++]" << RESET << CYAN << " INGRESE SU COMENTARIO DEL ULTIMO LIBRO QUE DEVOLVIO: " << RESET;
    getline(cin, mensaje);
    while (true) {
        cout << LGREEN << "\t\t\t\t\t[!]" << RESET << CYAN << " cual seria la nota que le pondria al libro? 0-5: " << RESET;
        cin >> mensaje;
        if (verif_entero(mensaje) && stoi(mensaje)>=0 && stoi(mensaje)<=5 ) {
            break;
        }
        else{
            cout << RED << "\t\t\t\t\t[!]" << RESET << ORANGE << " INGRESE UNA CALIFICACION VALIDA!\n" << RESET;
        }
    }
    comentarios[comentari_id].tiempo = capture_time();
}

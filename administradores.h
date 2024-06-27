#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include "STRUCTURAS.h"
#include "COLORAMA.h"
#include "FUNCIONALIDADES.h"
#include "Funcionalidad_reporte_grafico_de_barras.h"
#include "reporte_prestamos_por_tipo_de_publi.h"
#include <string>
#include "maker_logs.h"
#include "REPORTE PUBLICACIONES QUE SE PASARON TIEMPO DE PUBLICACION.h"
#include "reporte_rango_de_edad.h"
#include "administrar_usuarios.h"
using namespace std;



static string verif_password(string password) {
    char* caracteres = new char[26];
    char* caracteres_dos = new char[26];
    int caracter_inicio = 65;
    int caracter_dos = 97;

    for (int i = 0; i < 25; i++) {
        caracteres[i] = caracter_inicio;
        caracter_inicio++;
    }
    for (int i = 0; i < 25; i++) {
        caracteres_dos[i] = caracter_dos;
        caracter_dos++;
    }

    string new_pasword;
    for (int i = 0; i < password.length(); i++) {
        if (!isalpha(password[i])) {
            return "";
        }
        char caracter_encriptado;
        for (int j = 0; j < 25; j++) {
            if (password[i] == caracteres[j]) {
                caracter_encriptado = caracteres[(j + 5) % 26];
                break;
            }
            else if (password[i] == caracteres_dos[j]) {
                caracter_encriptado = caracteres_dos[(j + 5) % 26];
                break;
            }
        }
        new_pasword += caracter_encriptado;
    }

    return new_pasword;
}

static int valid_username(string username) {
    int n = sizeof(usuarios) / sizeof(usuarios[0]);
    for (int i = 0; i < n; i++) {
        if (usuarios[i].nombre_adminsitrador == username) {
            usuarios[i].hora_acceso = capture_time();
            return i;
        }
    }
    return 8;

}

static bool validate_exist_passwor(string password, int indice_usuario) {
    string hashed_password = verif_password(password);
    if (hashed_password == usuarios[indice_usuario].password) {
        return true;
    }
    else {
        return false;
    }

}

char  seleccion_reporte(int indice_usuario, string comando) {
    agregar_log(indice_usuario, comando);
    if (comando == "grafico") {
        return 'g';
    }
    if (comando == "porcentaje") {
        return 'p';
    }
    if (comando == "pendiente") {
        return 'e';
    }
    if (comando == "lectores") {
        return 'l';
    }
    if (comando == "cls") {
        return 'c';
    }
    return 'x';
}

static void ingresar_a_reportes(int indice_usuario) {
    system("cls");
    system("cls");
    cout << endl<<endl<<endl<<endl;
    cout << MAGENTA<<"\t\t\t\t"; estetica(97, 254); cout << endl;
    cout << LGREEN << "\t\t\t\t\t[!]" << CYAN << "BIENVENDIO " << usuarios[indice_usuario].nombre_adminsitrador <<RESET<< endl;
    cout << ORANGE<<"\t\t\t\t\t[+]" << CYAN << " Por favor ingrese el reporte que quiere generar:" << endl;
    cout << "\t\t\t\t\t[+] " << ROSE << "COMANDOS" << endl;
    char seleccion;
    string var_game;
    string comando;
    while (true) {
        cout << MAGENTA<<"\t\t\t\t";  estetica(97, 254); cout << RESET << endl;
        cout << LGREEN << "\t\t\t\t\t[!]" << CYAN << " grafico barras ->"<<ROSE<<" grafico" << endl;
        cout << LGREEN << "\t\t\t\t\t[!]" << CYAN << " porcentaje de prestamo -> " << ROSE << "porcentaje" << endl;
        cout << LGREEN << "\t\t\t\t\t[!]" << CYAN << " pendientes de devolcion -> " << ROSE << "pendientes" << endl;
        cout << LGREEN<<"\t\t\t\t\t[!]" << CYAN << " lectores de rango de edad ->" << ROSE << " lectores" << endl;;
        cout << LGREEN << "\t\t\t\t\t[!!]" << ROSE << " limpiar pantalla -> cls" << endl;
        cout << RED<<"\t\t\t\t\t[!!]" << ORANGE << " exit -> exit" << endl;
        cout << LGREEN << "\t\t\t\t\t[+]"<<ORANGE<<" -- > "<<RESET; getline(cin, comando);
        if (comando == "exit") { 
            break; 
        }
        if (verif_string(comando)==false) {
            switch (seleccion_reporte(indice_usuario, comando))
            {
            case 'g':
                while (true) {
                    system("cls");
                    cout << endl << endl<<endl;
                    cout << "\t\t\t\t" << MAGENTA; estetica(97, 219); cout << endl;
                    cout << LGREEN << "\t\t\t\t\t[!]" << CYAN << " GRAFICO PRIMER SEMESTRE " << ROSE << "[ 1 ]" << endl;
                    cout << LGREEN << "\t\t\t\t\t[!]" << CYAN << " GRAFICO SEGUNDO SEMESTRE " << ROSE << "[ 2 ]" << endl;
                    cout << YELLOW << "\t\t\t\t\t--> "; seleccion = _getch(); cout << endl; 
                    if (seleccion == '1' || seleccion == '2') {
                        cout << LGREEN << "\t\t\t\t\t[!]" << CYAN << "ELIGE UN AÑO ENTRE " << ROSE << "(2017-2024) :" <<RESET; getline(cin,var_game); 
                        if (verif_entero(var_game) && stoi(var_game)>=2017 && stoi(var_game)<=2024) {
                            system("cls");
                            cout << endl << endl << endl;
                            cout << "\t\t\t\t" << CYAN; estetica(97, 219); cout << endl;
                            grafico_de_barras(seleccion, stoi(var_game)); cout << endl;
                            break;
                        }
                    }
                    else { cout << RED << "\t\t\t\t\t[!] " << RESET << ORANGE << "INGRESE BIEN LA INFORMACION POR FAVOR" << RESET << endl; }
                }break;
            case 'p':
                call_reporte_prestmos(); break;
            case 'e':
                cout << endl;
                cout << "\t\t\t\t" << MAGENTA; estetica(97, 219); cout << endl;
                cout << LGREEN << "\t\t\t\t\t[!]" << CYAN << "SE MOSTRARAN LOS CODIGOS DE LAS PUBLICACIONES FUERA DE TIEMPO" << ROSE << " AÑO ACTUAL";;

                principal_reporte_no_devueltos(); break;
            case 'l':
                cout << LGREEN << "\t\t\t\t\t[!]" << CYAN << "ELIGE UN AÑO ENTRE " << ROSE << "(2017-2024) :" << RESET; getline(cin, var_game);
                if (verif_entero(var_game) && stoi(var_game) >= 2017 && stoi(var_game) <= 2024) {
                    system("cls");
                    cout << endl << endl << endl;
                    cout << LGREEN << "\t\t\t\t\t\t\t\t[!]" << ROSE << " REPORTE DE CLIENTES EN RANGO DE EDAD " << RESET << endl;
                    cout << "\t\t\t\t" << CYAN; estetica(97, 219); cout << endl;
                    principal_reporte_de_lectores_edad(stoi(var_game)); cout << endl;
                    break;
                } break;
            case 'c': system("cls"); break;
            }
        }else {
            cout << RED << "\t\t\t\t\t[!] " << RESET << ORANGE << "DISCULPE NO PUEDE INGRESAR" << RESET << endl;
        }
    }

}


extern void informacion_administrador() {
    string var_to_game;
    int indice = 0;
    bool is_valid = false;
    int intentos = 0;
    while (true) {

        if (intentos == 3) {
            break;
        }
        cout << endl<<BLUE<<"\t\t\t\t\t"; estetica(49, 219); cout << endl;
        cout << endl;
        cout << ROSE "\t\t\t\t\t\t[+]" << RESET << LGREEN "ESCRIBA EXIT SI SE EQUIVOCO " << RESET<<endl;
        cout << ROSE "\t\t\t\t\t\t[+]" << RESET << LGREEN "Ingrese su nombre de administrativo: " << RESET;
        getline(cin, var_to_game);
        if (var_to_game == "exit") {
            break;
        }
        indice = valid_username(var_to_game);
        if (indice < 8) {
            cout << ROSE<<"\t\t\t\t\t\t[!]"<< RESET<< LGREEN<<"Ingrese su contrasena : " << RESET;
         
            getline(cin, var_to_game);
            if (validate_exist_passwor(var_to_game, indice)) {
                is_valid = true;
                break;
            }
            else {
                intentos++;
                cout << RED << "\t\t\t\t\t\t[!] " << RESET << ORANGE << " CONTRASEÑA MAL INGRESADA!" << RESET << endl;
                continue;
            }
        }
        else { intentos++; cout << RED << "\t\t\t\t\t\t[!] " << RESET << ORANGE  <<" USUARIO NO EXISTE" << RESET<< endl; continue; }
  
    }
    if (is_valid){
        system("cls");
        crear_logs_usuario(indice);
        cout << endl << endl << endl;

        while (true) {
        cout << MAGENTA << "\t\t\t\t\t";  estetica(97, 254); cout << RESET << endl;
        cout <<LGREEN <<"\t\t\t\t\t[!]" << CYAN<< "BIENVENDIO "<<ORANGE << usuarios[indice].nombre_adminsitrador << endl;
        cout << LGREEN<<"\t\t\t\t\t[!]" << CYAN << " hora de acceso " << usuarios[indice].hora_acceso << endl;
        cout <<LGREEN<< "\t\t\t\t\t[+]" << CYAN << " privilegios: " << endl;
        cout << LGREEN<<"\t\t\t\t\t[1]" << CYAN << " Ver reportes: " << bool(usuarios[indice].see_reportes) << endl;
        cout <<LGREEN<< "\t\t\t\t\t[2]" << CYAN << " Administrar usuarios y clientes: " << bool(usuarios[indice].adm_users) << endl;
        cout << RED << "\t\t\t\t\t[!!]" << ORANGE << " salir -> exit" << endl;
        char selec;
            while (true) {
                cout << endl;
                cout << ORANGE<<"\t\t\t\t\t--> "<<RESET;
                selec = _getch();
                selec = toupper(selec);
                if (selec == 'A' || selec == 'R'||selec == 'X') {
                    break;
                }

            }
            if (selec == 'X') {
                break;
            }
            switch (selec)
            {
            case 'A': if (usuarios[indice].adm_users != false) {
                main_administrar_cliente(indice);
            }
                    else {
                cout << RED << "\t\t\t\t\t[!]" << RESET << ORANGE << " NO TIENE PERMISO PARA ACCEDER\n" << RESET;
            } break;
            case 'R':
                if (usuarios[indice].see_reportes != false) {
                    ingresar_a_reportes(indice);
                }
                else {
                    cout << endl;
                    cout << RED << "\t\t\t\t\t[!]" << RESET << ORANGE << " N0 TIENE PERMISO PARA ACCEDER\n" << RESET;
                }
                break;
            default:
                break;
            }
        }

    }
    system("cls");
}


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
#include <string>
#include <cctype>
#include "maker_logs.h"
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
    return 'x';
}

static void ingresar_a_reportes(int indice_usuario) {
    system("cls");
    cin.ignore();
    system("cls");
    cout << endl;
    cout << "\t[+] Bienvendio " << usuarios[indice_usuario].nombre_adminsitrador << endl;
    cout << "\t[+] Por favor ingrese el reporte que quiere generar:" << endl;
    cout << "\t[+] COMANDOS" << endl;

    string comando;
    while (true) {
        cout << endl;
        cout << "\t[!] grafico barras -> grafico" << endl;
        cout << "\t[!] porcentaje de prestamo -> porcentaje" << endl;
        cout << "\t[!] pendientes de devolcion -> pendientes" << endl;
        cout << "\t[!] lectores de rango de edad -> lectores" << endl;;
        cout << "\t[!!] exit -> exit" << endl;
        cout << "\t[+] -- > "; getline(cin, comando);
        if (comando == "exit") { 
            break; 
        }
        if (verif_string(comando)==false) {
            switch (seleccion_reporte(indice_usuario, comando))
            {
            case 'g':
                grafico_de_barras();
                break;
            case 'p':
                cout << "porcentaje"; break;
            case 'e':
                cout << "pendientes"; break;
            case 'l':
                cout << "lectores"; break;
            }
        }else {
            cout << RED << "\t[!] " << RESET << ORANGE << "DISCULPE NO PUEDE INGRESAR" << RESET << endl;
        }
    }

}


extern void informacion_administrador() {
    string var_to_game;
    cin.ignore();
    int indice = 0;
    bool is_valid = false;
    int intentos = 0;
    while (true) {

        if (intentos == 3) {
            break;
        }
        cout << endl;
        cout << ROSE "\t[+]" << RESET << LGREEN "ESCRIBA EXIT SI SE EQUIVOCO " << RESET<<endl;
        cout << ROSE "\t[+]" << RESET << LGREEN "Ingrese su nombre de administrativo: " << RESET;
        getline(cin, var_to_game);
        if (var_to_game == "exit") {
            break;
        }
        indice = valid_username(var_to_game);
        if (indice < 8) {
            cout << ROSE<<"\t[!]"<< RESET<< LGREEN<<"Ingrese su contrasena : " << RESET;
            intentos++;
            getline(cin, var_to_game);
            if (validate_exist_passwor(var_to_game, indice)) {
                is_valid = true;
                break;
            }
            else {
                cout << RED << "\t[!] " << RESET << ORANGE << " CONTRASEÑA MAL INGRESADA!" << RESET << endl;
                continue;
            }
        }
        else { cout << RED << "\t[!] " << RESET << ORANGE  <<" USUARIO NO EXISTE" << RESET<< endl; continue; }
    }
    if (is_valid){
        crear_logs_usuario(indice);

        cout << "\t[!] BIENVENDIO " << usuarios[indice].nombre_adminsitrador << endl;
        cout << "\t[!] hora de acceso " << usuarios[indice].hora_acceso << endl;
        cout << "\t[+] privilegios: " << endl;
        cout << "\t Ver reportes: " << bool(usuarios[indice].see_reportes) << endl;
        cout << "\t Administrar usuarios y clientes: " << bool(usuarios[indice].adm_users) << endl;
        char selec;

        while (true) {
            while (true) {
                cout << endl;
                cout << "\t--> ";
                cin >> selec; selec = toupper(selec);
                if (selec == 'A' || selec == 'R') {
                    break;
                }

            }
            switch (selec)
            {
            case 'A': if (usuarios[indice].adm_users != false) {
                ingresar_a_reportes(indice);
            }
                    else {
                cout << RED << "\t[!] " << RESET << ORANGE << "DISCULPE NO PUEDE INGRESAR" << RESET << endl;
            } break;
            case 'R':
                if (usuarios[indice].see_reportes != false) {
                    ingresar_a_reportes(indice);
                }
                else {
                    cout << endl;
                    cout << RED << "\t[!] " << RESET << ORANGE << "NO PUEDE INGRESAR" << RESET << endl;
                }
                break;
            default:
                break;
            }
        }

    }

}






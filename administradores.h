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
ADMINISTRADOR administradores[2] = {
    {"EnzoFavito", "MtqfRzsit", "2024-06-8", "enzofavito@biblio.com", true, true},
    {"RalphSito", "Xmfnijq","2024-06-8", "ralphxshaiel@teamoshaiel.com", true, false}
};
static int valid_username(string username) {
    int n = sizeof(administradores) / sizeof(administradores[0]);
    for (int i = 0; i < n; i++) {
        if (administradores[i].nombre_adminsitrador == username) {
            return i;
        }
    }
    return 8;

}

static bool validate_exist_passwor(string password, int indice_adminstrador) {
    string hashed_password = verif_password(password);
    if (hashed_password == administradores[indice_adminstrador].password) {
        return true;
    }
    else {
        return false;
    }

}


static void ingresar_a_reportes() {


}


extern void informacion_administrador() {
    string var_to_game;
    cin.ignore();
    int indice = 0;
    bool is_valid = false;
    while (true) {
        cout << endl;
        cout << ROSE "\t[+]" << RESET << LGREEN "Ingrese su nombre de administrativo: " << RESET;
        getline(cin, var_to_game);
        indice = valid_username(var_to_game);
        if (indice < 8) {
            cout << ROSE<<"\t[!]"<< RESET<< LGREEN<<"Ingrese su contrasena : " << RESET;
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
    
    }

}






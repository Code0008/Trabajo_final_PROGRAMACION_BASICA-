#pragma once
#include "cabecera_principales.h"
#include "STRUCTURAS.h"
#include "COLORAMA.h"
#include "administradores.h"

using namespace std;


extern void crear_logs_usuario(int indice_usuario) {
    for (int i = 0; i < 100; i++) {
        usuarios[indice_usuario].log_usuario.almacenamiento[i] = new string[4];
        usuarios[indice_usuario].log_usuario.almacenamiento[i][3] = "vacio";
    }
}

extern void agregar_log(int indice_usuario, string proceso) {
    int indice_libre = 0;
    for (int i = 0; i < 100; i++) {
        if (usuarios[indice_usuario].log_usuario.almacenamiento[i][3] == "completo" && usuarios[indice_usuario].log_usuario.almacenamiento[i + 1][3] == "vacio") {
            indice_libre = i + 1;
            break;
        }
    }
    for (int i = 0; i < 4; i++) {
        switch (i)
        {
        case 0:
            usuarios[indice_usuario].log_usuario.almacenamiento[indice_libre][i] = to_string(indice_usuario);
            break;
        case 1:
            usuarios[indice_usuario].log_usuario.almacenamiento[indice_libre][i] = capture_time();
            break;
        case 2:
            usuarios[indice_usuario].log_usuario.almacenamiento[indice_libre][i] = proceso;
            break;
        case 3:
            usuarios[indice_usuario].log_usuario.almacenamiento[indice_libre][i] = "completo";
            break;
        default:
            break;
        }
    }
}
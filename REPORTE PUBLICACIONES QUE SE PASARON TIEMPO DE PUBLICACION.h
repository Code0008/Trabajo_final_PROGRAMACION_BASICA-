#pragma once
#include "cabecera_principales.h"
#include "FUNCIONALIDADES.h"
using namespace std;

int** mak_data() {
    int** informa = new int* [100];

    srand(time(NULL));
    time_t timestamp;
    tm tiemmpo;
    time(&timestamp);
    localtime_s(&tiemmpo, &timestamp);

    char tipo_publi[] = { 'L', 'R', 'P' };
    for (int i = 0; i < 100; i++) {
        informa[i] = new int[4];
        informa[i][0] = rand() % 202400000 + (202499999 - 202400000);
        informa[i][1] = rand() % 1+ (tiemmpo.tm_yday-1);
        informa[i][2] = rand() % 1 + (informa[i][1]-1);
        informa[i][3] = tipo_publi[rand() % 3];
    }
    for (int i = 0; i < 100; i++) {
        int current_day = informa[i][1];
        int current_day_dos = informa[i][2];
        int current_tipo_publi = informa[i][3];
        int j = i-1; 

        while (j >= 0 && informa[j+1][1] > current_day) {
            informa[j + 1][1] = informa[j][1];
            informa[j + 1][2] = informa[j][2];
            informa[j + 1][3] = informa[j][3];
            j -= 1;
        }

        informa[j + 1][1] = current_day;
        informa[j + 1][2] = current_day_dos;
        informa[j + 1][3] = current_tipo_publi;
    }


    return informa;
}

// indice 2: dia que pidio prestdo
// indice 1: dia qu devolvio 


extern void see_report_tipo_publi_no_devuelto(int ** data) {
    int** tabla_de_datos = new int*[50];
    for (int i = 0; i < 50; i++) {
        tabla_de_datos[i] = new int[3];
        for (int j = 0; j < 3; j++) {
            tabla_de_datos[i][j] = 0;
        }
    }

    int fila_end_lib = 49;
    int fila_end_per = 49;
    int fila_end_re = 49;


    
    for (int i = 0; i < 100; i++) {
        switch (data[i][3])
        {
        case 76: // libros
            tabla_de_datos[fila_end_lib][0] = data[i][0];
            fila_end_lib--;
            break;
        case 80: // periodico
            tabla_de_datos[fila_end_per][1] = data[i][0];
            fila_end_per--;
            break;
        case 82:
            tabla_de_datos[fila_end_re][2] = data[i][0];
            fila_end_re--;
            break;
        default:
            break;
        }
    }
 
 
    cout << endl;
    cout << " \t\t\t\t\t\t\t\t\t";
    cout << "   LIBROS " << setw(10) << "REVISTA" << setw(15) << "PERIODICOS" << endl;
    cout << " \t\t\t\t";
    cout << CYAN; estetica(97, 219); cout << RESET << endl;

    for (int i = 0; i < 50; i++) {
        bool isvalid = false;
        for (int k = 0; k < 3; k++) {
            if (tabla_de_datos[i][k] > 0) {
                isvalid = true;
                break;
            }
        }

        if (isvalid) {
            cout << ROSE<<" \t\t\t\t\t\tCODIGO\t\t\t"<< RESET;
            cout << LGREEN;
            for (int j = 0; j < 3; j++) {
              cout << setw(10) << setfill(' ')<<tabla_de_datos[i][j] ;
            }  cout << endl;
            cout << RESET;
        } 
      
    }
    cout << "\t\t\t";
    cout << " se mostrara de forma ascendente, en las ultimas filas se mostrara las que mas tiempo tienen de no devueltas en las primeras mostrara las mas reicentes  " << endl;
    cout << " \t\t\t\t";
    cout << CYAN; estetica(97, 219); cout << RESET << endl;
};

void principal_reporte_no_devueltos(){
    int** data = mak_data();
 
    see_report_tipo_publi_no_devuelto(data);
}
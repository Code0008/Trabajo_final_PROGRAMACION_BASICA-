#include"pch.h"
#include<iostream>
#include<string>
#include<cstdlib>//new y delete
#include<ctime>//rand y srand y fecha
#include <chrono>//fecha
#define VERDE "\033[32m"
#define RESET "\033[0m"
#define AZUL "\033[34m"
#define CELESTE "\033[36m"
#define ROJO "\033[31m"

using namespace std;
using namespace System;

struct datos_usuario
{
    int dni;
    string nombre_apellido;
    char sexo;
    string correo;
};
struct datos_libro
{
    int codigo;
    string titulo;
    char tipo;
    double costo;
    double venta;
    char local_disponiblidad;
};
struct modalidad
{
    char tipo_modalidad;
    char recojo;

};
struct fecha
{
    int hora;
    int minutos;
    int dia;
    int mes;
    int año;
};
struct datos_venta
{
    fecha fecha;
    modalidad modalidad;
    char local;
    datos_usuario datos_usuario;
    datos_libro datos_libro;
};

void opcion_menu(datos_venta* el_stock, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos);
void opcion_continuar(datos_venta* el_stock, datos_venta* venta_unitaria, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos);
void generacion_stock(datos_venta* stock);
void ventas_miraflores(datos_venta* el_stock, datos_venta* venta, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos);
void ventas_san_isidro(datos_venta* el_stock, datos_venta* venta, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos);
void ventas_whatsapp(datos_venta* el_stock, datos_venta* venta, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos);
void ventas_presencial(datos_venta* el_stock, datos_venta* venta, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos);
void mangas(datos_venta* venta, datos_venta* el_stock, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos);
void comic(datos_venta* venta, datos_venta* el_stock, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos);
void impresion_boleta(datos_venta* el_stock, datos_venta* venta_unitaria, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos);
void registrar_ventas(datos_venta* el_stock, datos_venta* venta_unitaria, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos);
void funcion_fecha();

string convertir_digito(int numero)
{
    switch (numero) {
    case 0:
        return "cero";
    case 1:
        return "uno";
    case 2:
        return "dos";
    case 3:
        return "tres";
    case 4:
        return "cuatro";
    case 5:
        return "cinco";
    case 6:
        return "seis";
    case 7:
        return "siete";
    case 8:
        return "ocho";
    case 9:
        return "nueve";
    default:
        return "";
    }
}
string convertir_menor_que_veinte(int numero)
{
    setlocale(LC_CTYPE, "Spanish");
    switch (numero) {
    case 10:
        return "diez";
    case 11:
        return "once";
    case 12:
        return "doce";
    case 13:
        return "trece";
    case 14:
        return "catorce";
    case 15:
        return "quince";
    case 16:
        return "dieciséis";
    case 17:
        return "diecisiete";
    case 18:
        return "dieciocho";
    case 19:
        return "diecinueve";
    default:
        return "";
    }
}
string convertir_decena(int numero)
{
    switch (numero) {
    case 2: return "veint";
    case 3: return "treinta";
    case 4: return "cuarenta";
    case 5: return "cincuenta";
    case 6: return "sesenta";
    case 7: return "setenta";
    case 8: return "ochenta";
    case 9: return "noventa";
    default: return "";
    }
}
string convertir_centena(int numero)
{
    setlocale(LC_CTYPE, "Spanish");
    switch (numero)
    {
    case 1:return "cien";
    case 2:return "doscientos";
    case 3:return "trescientos";
    case 4:return "cuatrocientos";
    case 5:return "quinientos";
    case 6:return "seiscientos";
    case 7:return "setecientrps";
    case 8:return "ochocientos";
    case 9:return "novecientos";
    default: return "";
    }
}
string convertir_numero_en_palabras(int numero)
{
    if (numero < 10)
    {
        return convertir_digito(numero);
    }
    else if (numero < 20)
    {
        return convertir_menor_que_veinte(numero);
    }
    else if (numero < 100)
    {
        int decena = numero / 10;
        int unidad = numero % 10;
        if (unidad == 0 && decena == 2)
        {
            return convertir_decena(decena) + "e";
        }
        else
        {
            if (decena >= 2 && decena < 3)
            {
                return convertir_decena(decena) + "i" + convertir_digito(unidad);
            }
            else
            {
                if (unidad == 0)
                {
                    return convertir_decena(decena);
                }
                else
                {
                    return convertir_decena(decena) + " y " + convertir_digito(unidad);
                }
            }
        }


    }
    else if (numero < 1000)
    {
        int centena = numero / 100;
        int decena = numero / 10 % 10;
        int unidad = numero % 10;
        if (unidad == 0 && decena == 0)
        {
            return convertir_centena(centena);
        }
        else if (centena == 1 && decena == 0)
        {
            return convertir_centena(centena) + "to " + convertir_digito(unidad);
        }

        else if (centena == 1 && decena >= 1 && decena < 2)
        {
            return convertir_centena(centena) + "to " + convertir_menor_que_veinte(decena * 10 + unidad);
        }
        else if (centena == 1 && decena >= 2 && decena < 3 && unidad == 0)
        {
            return convertir_centena(centena) + "to " + convertir_decena(decena) + "e";
        }
        else if (centena == 1 && decena == 2)
        {
            return convertir_centena(centena) + "to " + convertir_decena(decena) + "i" + convertir_digito(unidad);
        }
        else if (centena == 1 && decena >= 3 && unidad == 0)
        {
            return convertir_centena(centena) + "to " + convertir_decena(decena);
        }
        else if (centena == 1 && decena >= 3)
        {
            return convertir_centena(centena) + "to " + convertir_decena(decena) + " y " + convertir_digito(unidad);
        }
        else if (decena < 2 && decena >= 1)
        {
            return convertir_centena(centena) + " " + convertir_menor_que_veinte(decena * 10 + unidad);
        }
        else if (decena >= 2 && unidad != 0)
        {
            return convertir_centena(centena) + " " + convertir_decena(decena) + " y " + convertir_digito(unidad);
        }

        else if (unidad == 0)
        {
            return convertir_centena(centena) + " " + convertir_decena(decena);
        }
        else if (decena == 0)
        {
            return convertir_centena(centena) + " " + convertir_digito(unidad);
        }
        else
        {
            return convertir_centena(centena) + convertir_decena(decena) + " y " + convertir_digito(unidad);
        }
    }
    else {
        return "Número fuera de rango";
    }
}
void generacion_stock(datos_venta* stock)
{
    srand(time(0));
    for (int i = 0; i < 100; i++)
    {
        stock[i].datos_libro.codigo = 1000 + rand() % (9999 - 1000 + 1);

        /*
            |Miraflores |    | San Isidro|
            |Comic|Manga|    |Comic|Manga|
         |Thanos  |DragonB   SecWar|ChainsawMan01
         |Thor    |MHeroA    Spider|SpyxFamily01
         |TonyS.  |                |DeathNote01
        */
        if (i >= 90 && i < 100)
        {
            stock[i].datos_libro.titulo = "Chainsaw Man 01";
            stock[i].datos_libro.venta = 27.30;
            stock[i].datos_libro.tipo = 'M';
            stock[i].datos_libro.costo = 31.00;
            stock[i].datos_libro.local_disponiblidad = 'S';
        }
        else if (i >= 80 && i < 90)
        {
            stock[i].datos_libro.titulo = "Death Note 01";
            stock[i].datos_libro.venta = 27.30;
            stock[i].datos_libro.tipo = 'M';
            stock[i].datos_libro.costo = 31.00;
            stock[i].datos_libro.local_disponiblidad = 'S';
        }
        else if (i >= 70 && i < 80)
        {
            stock[i].datos_libro.titulo = "Jojos";
            stock[i].datos_libro.venta = 27.30;
            stock[i].datos_libro.tipo = 'M';
            stock[i].datos_libro.costo = 31.00;
            stock[i].datos_libro.local_disponiblidad = 'S';
        }
        else if (i >= 60 && i < 70)
        {
            stock[i].datos_libro.titulo = "Dragon Ball Super 03";
            stock[i].datos_libro.venta = 27.30;
            stock[i].datos_libro.tipo = 'M';
            stock[i].datos_libro.costo = 31.00;
            stock[i].datos_libro.local_disponiblidad = 'M';
        }
        else if (i >= 50 && i < 60)
        {
            stock[i].datos_libro.titulo = "My Hero Academy 01";
            stock[i].datos_libro.venta = 25.20;
            stock[i].datos_libro.tipo = 'M';
            stock[i].datos_libro.costo = 29.70;
            stock[i].datos_libro.local_disponiblidad = 'M';
        }
        else if (i >= 40 && i < 50)
        {
            stock[i].datos_libro.titulo = "Marvel Secret War";
            stock[i].datos_libro.venta = 109.00;
            stock[i].datos_libro.tipo = 'C';
            stock[i].datos_libro.costo = 120.00;
            stock[i].datos_libro.local_disponiblidad = 'S';
        }
        else if (i >= 30 && i < 40)
        {
            stock[i].datos_libro.titulo = "Marvel Ultimate Spiderman 2";
            stock[i].datos_libro.venta = 108.50;
            stock[i].datos_libro.tipo = 'C';
            stock[i].datos_libro.costo = 115.70;
            stock[i].datos_libro.local_disponiblidad = 'S';
        }
        else if (i >= 20 && i < 30)
        {
            stock[i].datos_libro.titulo = "Marvel Thanos. Poderes Cosmicos";
            stock[i].datos_libro.venta = 89.40;
            stock[i].datos_libro.tipo = 'C';
            stock[i].datos_libro.costo = 95.00;
            stock[i].datos_libro.local_disponiblidad = 'M';
        }
        else if (i >= 10 && i < 20)
        {
            stock[i].datos_libro.titulo = "Marvel Thor. Vikingos";
            stock[i].datos_libro.venta = 47.40;
            stock[i].datos_libro.tipo = 'C';
            stock[i].datos_libro.costo = 54.30;
            stock[i].datos_libro.local_disponiblidad = 'M';
        }
        else if (i >= 0 && i < 10)
        {
            stock[i].datos_libro.titulo = "Marvel Tony Stark. Iron Man 01";
            stock[i].datos_libro.venta = 46.00;
            stock[i].datos_libro.tipo = 'C';
            stock[i].datos_libro.costo = 51.00;
            stock[i].datos_libro.local_disponiblidad = 'M';
        }
    }
}
void opcion_menu(datos_venta* el_stock, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos)
{
    datos_venta* venta_unitaria;
    venta_unitaria = new datos_venta[1];
    int Opcion;
    cout << AZUL << "\t==============BIENVENIDO A LA LIBRERIA 'MORALEJA'==============\n" << RESET;

    cout << "\n\t\t\t Escoja opcion para registrar" << endl;
    cout << "\t\t\t-----------------------------------" << endl;
    cout << CELESTE "\t\t\t Opcion 1: COMPRAR EN MIRAFLORES " << endl;
    cout << "\t\t\t Opcion 2: COMPRAR EN SAN ISIDRO " << endl;
    cout << "\t\t\t Opcion 3: Salir del Sistema " << RESET << endl;
    cout << "\t\t\t-----------------------------------" << endl;
    cout << "\n";
    cout << "\tIngrese Opcion a registrar -> : "; cin >> Opcion;
    switch (Opcion)
    {
    case 1:
        venta_unitaria[0].local = 'M';
        ventas_miraflores(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
        break;
    case 2:
        venta_unitaria[0].local = 'S';
        ventas_san_isidro(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
        break;
    case 3:
        exit(0);
    default:
        cout << "\n\tOpcion ingresada inavalido " << endl;
        cout << "\tIntente nuevamente ingresando opcion correcta " << endl << endl;
        opcion_menu(el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
        break;
    }
}
void ventas_miraflores(datos_venta* el_stock, datos_venta* venta_unitaria, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos)
{
    int Opcion;

    cout << "\n\t\t\t Escoja opcion para registrar" << endl;
    cout << "\t\t\t-----------------------------------" << endl;
    cout << VERDE << "\t\t\t\t SEDE: MIRAFLORES" << RESET << endl;
    cout << CELESTE << "\t\t\t Opcion 1: MODALIDAD PRESENCIAL" << endl;
    cout << "\t\t\t Opcion 2: MODALIDAD WhatsApp" << endl;
    cout << "\t\t\t Opcion 3: VOLVER AL MENU" << RESET << endl;
    cout << "\t\t\t-----------------------------------" << endl;
    cout << "\n";
    cout << "\tIngrese Opcion a registrar -> : "; cin >> Opcion;
    switch (Opcion)
    {
    case 1:
        venta_unitaria[0].modalidad.tipo_modalidad = 'P';
        ventas_presencial(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
        break;
    case 2:
        venta_unitaria[0].modalidad.tipo_modalidad = 'W';
        ventas_whatsapp(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
        break;
    case 3:
        opcion_menu(el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
        break;
    default:
        cout << "\n\tOpcion ingresada inavalido " << endl;
        cout << "\tIntente nuevamente ingresando opcion correcta " << endl << endl;
        ventas_miraflores(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
        break;
    }
}
void ventas_san_isidro(datos_venta* el_stock, datos_venta* venta_unitaria, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos)
{
    int Opcion;

    cout << "\n\t\t\t Escoja opcion para registrar" << endl;
    cout << "\t\t\t-----------------------------------" << endl;
    cout << VERDE << "\t\t\t\t SEDE: SAN ISIDRO" << RESET << endl;
    cout << CELESTE << "\t\t\t Opcion 1: MODALIDAD PRESENCIAL:" << endl;
    cout << "\t\t\t Opcion 2: MODALIDAD WhatsApp" << endl;
    cout << "\t\t\t Opcion 3: VOLVER AL MENU" << RESET << endl;
    cout << "\t\t\t-----------------------------------" << endl;
    cout << "\n";
    cout << "\tIngrese Opcion a registrar -> : "; cin >> Opcion;
    switch (Opcion)
    {
    case 1:
        venta_unitaria[0].modalidad.tipo_modalidad = 'P';
        ventas_presencial(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
        break;
    case 2:
        venta_unitaria[0].modalidad.tipo_modalidad = 'W';
        ventas_whatsapp(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
        break;
    case 3:
        opcion_menu(el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
        break;
    default:
        cout << "\n\tOpcion ingresada inavalido " << endl;
        cout << "\tIntente nuevamente ingresando opcion correcta " << endl << endl;
        ventas_san_isidro(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
        break;
    }
}
void ventas_whatsapp(datos_venta* el_stock, datos_venta* venta_unitaria, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos)
{
    int Opcion;

    cout << "\n\t\t\t Escoja opcion para registrar" << endl;
    cout << "\t\t\t-----------------------------------" << endl;
    cout << VERDE << "\t\t\t\t SEDE: ";
    if (venta_unitaria[0].local == 'S')
    {
        cout << "SAN INSIDRO";
    }
    if (venta_unitaria[0].local == 'M')
    {
        cout << "MIRAFLORES";
    }
    cout << RESET << endl;
    cout << VERDE << "\t\t\t\t MODALIDAD: WHATSAPP" << RESET << endl;
    cout << CELESTE "\t\t\t Opcion 1: RECOJO EN TIENDA" << endl;
    cout << "\t\t\t Opcion 2: ENTREGA A DOMICILIO" << endl;
    cout << "\t\t\t Opcion 3: VOLVER A SELECCIÓN DE MODALIDADES" << RESET << endl;
    cout << "\t\t\t-----------------------------------" << endl;
    cout << "\n";
    cout << "\tIngrese Opcion a registrar -> : "; cin >> Opcion;
    switch (Opcion)
    {
    case 1:
        venta_unitaria[0].modalidad.recojo = 'T';

        break;
    case 2:
        venta_unitaria[0].modalidad.recojo = 'D';

        break;
    case 3:
        if (venta_unitaria[0].local == 'M')
        {
            ventas_miraflores(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
        }
        else if (venta_unitaria[0].local == 'S')
        {
            ventas_san_isidro(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
        }
        break;
    default:
        cout << "\n\tOpcion ingresada inavalido " << endl;
        cout << "\tIntente nuevamente ingresando opcion correcta " << endl << endl;
        ventas_whatsapp(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
        break;
    }
}
void ventas_presencial(datos_venta* el_stock, datos_venta* venta_unitaria, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos)
{
    int Opcion;

    generacion_stock(el_stock);
    cout << "\n\t\t\t Escoja opcion para registrar" << endl;
    cout << "\t\t\t-----------------------------------" << endl;
    cout << VERDE << "\t\t\t\t SEDE: ";
    if (venta_unitaria[0].local == 'S')
    {
        cout << "SAN INSIDRO";
    }
    if (venta_unitaria[0].local == 'M')
    {
        cout << "MIRAFLORES";
    }
    cout << RESET << endl;
    cout << VERDE << "\t\t\t\t MODALIDAD: PRESENCIAL" << RESET << endl;
    cout << CELESTE << "\t\t\t Opcion 1: MANGAS" << endl;
    cout << "\t\t\t Opcion 2: COMICS" << endl;
    cout << "\t\t\t Opcion 3: VOLVER A SELECCION DE MODALIDADES" << RESET << endl;
    cout << "\t\t\t-----------------------------------" << endl;
    cout << "\n";
    cout << "\tIngrese Opcion a registrar -> : "; cin >> Opcion;
    switch (Opcion)
    {
    case 1:
        venta_unitaria[0].datos_libro.tipo = 'M';
        mangas(venta_unitaria, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
        break;
    case 2:
        venta_unitaria[0].datos_libro.tipo = 'C';
        comic(venta_unitaria, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
        break;
    case 3:
        if (venta_unitaria[0].local == 'M')
        {
            ventas_miraflores(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
        }
        else if (venta_unitaria[0].local == 'S')
        {
            ventas_san_isidro(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
        }
        break;
    default:
        cout << "\n\tOpcion ingresada inavalido " << endl;
        cout << "\tIntente nuevamente ingresando opcion correcta " << endl << endl;
        ventas_presencial(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
        break;
    }
}
void mangas(datos_venta* venta_unitaria, datos_venta* el_stock, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos)
{
    int Opcion;

    cout << "\n\t\t\t Escoja opcion para registrar" << endl;
    cout << "\t\t\t-----------------------------------" << endl;
    cout << VERDE << "\t\t\t\t SEDE: ";
    if (venta_unitaria[0].local == 'S')
    {
        cout << "SAN INSIDRO";
    }
    if (venta_unitaria[0].local == 'M')
    {
        cout << "MIRAFLORES";
    }
    cout << RESET << endl;
    cout << VERDE << "\t\t\t\t MODALIDAD: PRESENCIAL" << RESET << endl;
    cout << VERDE << "\t\t\t\t TIPO DE LIBRO: MANGA" << RESET << endl;

    int iteracion = 0;
    for (int i = 0; i < 100; i = i + 10)
    {
        if (el_stock[i].datos_libro.tipo == 'M' && el_stock[i].datos_libro.local_disponiblidad == venta_unitaria[0].local)
        {
            cout << CELESTE << "\t\t\t OPCION " << iteracion + 1 << ": " << el_stock[i].datos_libro.titulo << RESET << endl;
            iteracion++;
        }
    }
    cout << "\t\t\t-----------------------------------" << endl;
    cout << "\n";
    cout << "\tIngrese Opcion a registrar -> : "; cin >> Opcion;
    int OpcionConfirmar;
    cout << endl << "\t\t\tDesea comprar el libro seleccionado? " << endl;
    cout << "\t\t\t-----------------------------------" << endl;
    cout << CELESTE << "\t\t\tOPCION 1: SI" << endl;
    cout << "\t\t\tOPCION 2: NO" << RESET << endl;
    cout << "\t\t\t-----------------------------------" << endl;
    cout << "\t\t\tIngrese Opcion a registrar ->"; cin >> OpcionConfirmar;
    if (iteracion == 2)
    {
        switch (Opcion)
        {
        case 1:
            if (cantidad_mangas_ya_vendidos[0] == 10)
            {
                cout << CELESTE << "\t\t\tLIBRO AGOTADO POR FAVOR ELIJA OTRO LIBRO" << RESET << endl;
                mangas(venta_unitaria, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
                break;
            }
            if (el_stock[50].datos_libro.titulo != "VACIO")
            {
                venta_unitaria[0].datos_libro.titulo = el_stock[50].datos_libro.titulo;
                el_stock[50].datos_libro.titulo = "VACIO";
                venta_unitaria[0].datos_libro.venta = el_stock[50].datos_libro.venta;
                venta_unitaria[0].datos_libro.costo = el_stock[50].datos_libro.costo;
                venta_unitaria[0].datos_libro.codigo = el_stock[50].datos_libro.codigo;
                cantidad_mangas_ya_vendidos[0]++;
                impresion_boleta(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
                break;
            }
            else
            {
                venta_unitaria[0].datos_libro.titulo = el_stock[50 + cantidad_mangas_ya_vendidos[0]].datos_libro.titulo;
                el_stock[50 + cantidad_mangas_ya_vendidos[0]].datos_libro.titulo = "VACIO";
                venta_unitaria[0].datos_libro.venta = el_stock[50].datos_libro.venta;
                venta_unitaria[0].datos_libro.costo = el_stock[50].datos_libro.costo;
                venta_unitaria[0].datos_libro.codigo = el_stock[50].datos_libro.codigo;
                cantidad_mangas_ya_vendidos[0]++;
                impresion_boleta(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
            }
            break;
        case 2:
            if (cantidad_mangas_ya_vendidos[1] == 10)
            {
                cout << CELESTE << "\t\t\tLIBRO AGOTADO POR FAVOR ELIJA OTRO LIBRO" << RESET << endl;
                mangas(venta_unitaria, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
                break;
            }
            if (el_stock[60].datos_libro.titulo != "VACIO")
            {
                venta_unitaria[0].datos_libro.titulo = el_stock[60].datos_libro.titulo;
                el_stock[60].datos_libro.titulo = "VACIO";
                venta_unitaria[0].datos_libro.venta = el_stock[60].datos_libro.venta;
                venta_unitaria[0].datos_libro.costo = el_stock[60].datos_libro.costo;
                venta_unitaria[0].datos_libro.codigo = el_stock[60].datos_libro.codigo;
                cantidad_mangas_ya_vendidos[1]++;
                impresion_boleta(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
                break;
            }
            else
            {
                venta_unitaria[0].datos_libro.titulo = el_stock[60 + cantidad_mangas_ya_vendidos[1]].datos_libro.titulo;
                el_stock[60 + cantidad_mangas_ya_vendidos[1]].datos_libro.titulo = "VACIO";
                venta_unitaria[0].datos_libro.venta = el_stock[60].datos_libro.venta;
                venta_unitaria[0].datos_libro.costo = el_stock[60].datos_libro.costo;
                venta_unitaria[0].datos_libro.codigo = el_stock[60].datos_libro.codigo;
                cantidad_mangas_ya_vendidos[1]++;
                impresion_boleta(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
            }

            break;
        case 3:
            ventas_presencial(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
            break;
        default:
            cout << "\n\tOpcion ingresada inavalido " << endl;
            cout << "\tIntente nuevamente ingresando opcion correcta " << endl << endl;
            comic(venta_unitaria, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
            break;
        }
    }
    else if (iteracion == 3)
    {
        switch (Opcion)
        {
        case 1:
            if (cantidad_mangas_ya_vendidos[2] == 10)
            {
                cout << CELESTE << "\t\t\tLIBRO AGOTADO POR FAVOR ELIJA OTRO LIBRO" << RESET << endl;
                mangas(venta_unitaria, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
                break;
            }
            if (el_stock[70].datos_libro.titulo != "VACIO")
            {
                venta_unitaria[0].datos_libro.titulo = el_stock[70].datos_libro.titulo;
                el_stock[70].datos_libro.titulo = "VACIO";
                venta_unitaria[0].datos_libro.venta = el_stock[70].datos_libro.venta;
                venta_unitaria[0].datos_libro.costo = el_stock[70].datos_libro.costo;
                venta_unitaria[0].datos_libro.codigo = el_stock[70].datos_libro.codigo;
                cantidad_mangas_ya_vendidos[2]++;
                impresion_boleta(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
                break;
            }
            else
            {
                venta_unitaria[0].datos_libro.titulo = el_stock[70 + cantidad_mangas_ya_vendidos[2]].datos_libro.titulo;
                el_stock[70 + cantidad_mangas_ya_vendidos[2]].datos_libro.titulo = "VACIO";
                venta_unitaria[0].datos_libro.venta = el_stock[70].datos_libro.venta;
                venta_unitaria[0].datos_libro.costo = el_stock[70].datos_libro.costo;
                venta_unitaria[0].datos_libro.codigo = el_stock[70].datos_libro.codigo;
                cantidad_mangas_ya_vendidos[2]++;
                impresion_boleta(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
            }
            break;
        case 2:
            if (cantidad_mangas_ya_vendidos[3] == 10)
            {
                cout << CELESTE << "\t\t\tLIBRO AGOTADO POR FAVOR ELIJA OTRO LIBRO" << RESET << endl;
                mangas(venta_unitaria, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
                break;
            }
            if (el_stock[80].datos_libro.titulo != "VACIO")
            {
                venta_unitaria[0].datos_libro.titulo = el_stock[80].datos_libro.titulo;
                el_stock[80].datos_libro.titulo = "VACIO";
                venta_unitaria[0].datos_libro.venta = el_stock[80].datos_libro.venta;
                venta_unitaria[0].datos_libro.costo = el_stock[80].datos_libro.costo;
                venta_unitaria[0].datos_libro.codigo = el_stock[80].datos_libro.codigo;
                cantidad_mangas_ya_vendidos[3]++;
                impresion_boleta(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
                break;
            }
            else
            {
                venta_unitaria[0].datos_libro.titulo = el_stock[80 + cantidad_mangas_ya_vendidos[3]].datos_libro.titulo;
                el_stock[80 + cantidad_mangas_ya_vendidos[3]].datos_libro.titulo = "VACIO";
                venta_unitaria[0].datos_libro.venta = el_stock[80].datos_libro.venta;
                venta_unitaria[0].datos_libro.costo = el_stock[80].datos_libro.costo;
                venta_unitaria[0].datos_libro.codigo = el_stock[80].datos_libro.codigo;
                cantidad_mangas_ya_vendidos[3]++;
                impresion_boleta(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
            }
            break;
        case 3:
            if (cantidad_mangas_ya_vendidos[4] == 10)
            {
                cout << CELESTE << "\t\t\tLIBRO AGOTADO POR FAVOR ELIJA OTRO LIBRO" << RESET << endl;
                mangas(venta_unitaria, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
                break;
            }
            if (el_stock[90].datos_libro.titulo != "VACIO")
            {
                venta_unitaria[0].datos_libro.titulo = el_stock[90].datos_libro.titulo;
                el_stock[90].datos_libro.titulo = "VACIO";
                venta_unitaria[0].datos_libro.venta = el_stock[90].datos_libro.venta;
                venta_unitaria[0].datos_libro.costo = el_stock[90].datos_libro.costo;
                venta_unitaria[0].datos_libro.codigo = el_stock[90].datos_libro.codigo;
                cantidad_mangas_ya_vendidos[4]++;
                impresion_boleta(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
                break;
            }
            else
            {
                venta_unitaria[0].datos_libro.titulo = el_stock[90 + cantidad_mangas_ya_vendidos[4]].datos_libro.titulo;
                el_stock[90 + cantidad_mangas_ya_vendidos[4]].datos_libro.titulo = "VACIO";
                venta_unitaria[0].datos_libro.venta = el_stock[90].datos_libro.venta;
                venta_unitaria[0].datos_libro.costo = el_stock[90].datos_libro.costo;
                venta_unitaria[0].datos_libro.codigo = el_stock[90].datos_libro.codigo;
                cantidad_mangas_ya_vendidos[4]++;
                impresion_boleta(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
            }


            break;
        case 4:
            ventas_presencial(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
            break;
        default:
            cout << "\n\tOpcion ingresada inavalido " << endl;
            cout << "\tIntente nuevamente ingresando opcion correcta " << endl << endl;
            comic(venta_unitaria, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
            break;
        }
    }
}
void comic(datos_venta* venta_unitaria, datos_venta* el_stock, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos)
{
    int Opcion;
    cout << "\n\t\t\t Escoja opcion para registrar" << endl;
    cout << "\t\t\t-----------------------------------" << endl;
    cout << VERDE << "\t\t\t\t SEDE: ";
    if (venta_unitaria[0].local == 'S')
    {
        cout << "SAN INSIDRO";
    }
    if (venta_unitaria[0].local == 'M')
    {
        cout << "MIRAFLORES";
    }
    cout << RESET << endl;
    cout << VERDE << "\t\t\t\t MODALIDAD: PRESENCIAL" << RESET << endl;
    cout << VERDE << "\t\t\t\t TIPO DE LIBRO: COMIC" << RESET << endl;
    //Mostramos los libros segun sede y tipo;  
    int iteracion = 0;
    for (int i = 0; i < 100; i = i + 10)
    {
        if (el_stock[i].datos_libro.tipo == 'C' && el_stock[i].datos_libro.local_disponiblidad == venta_unitaria[0].local)
        {
            cout << CELESTE << "\t\t\t\t Opcion " << iteracion + 1 << ": " << el_stock[i].datos_libro.titulo << RESET << endl;
            iteracion++;
        }
    }
    cout << CELESTE << "\t\t\t\t OPCION " << iteracion << ": VOLVER LA SELECCION DE MODALIDADES" << RESET << endl;
    cout << "\t\t\t-----------------------------------" << endl;
    cout << "\n";
    cout << "\t\t\tIngrese Opcion a registrar -> : "; cin >> Opcion;

    int OpcionConfirmar;
    cout << endl << "\t\t\tDesea comprar el libro seleccionado? ";
    cout << CELESTE << "\t\t\tOPCION 1: SI";
    cout << "\t\t\tOPCION 2: NO" << RESET;

    cin >> OpcionConfirmar;
    if (iteracion == 2)//Solo 2 comics significa sede san isidro //3 y 4
    {
        switch (Opcion)
        {
        case 1:
            if (OpcionConfirmar == 1)
            {
                if (cantidad_comics_ya_vendidos[3] == 10)
                {
                    cout << CELESTE << "\t\t\tLIBRO AGOTADO POR FAVOR ELIJA OTRO LIBRO" << RESET << endl;
                    comic(venta_unitaria, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
                    break;
                }
                if (el_stock[30].datos_libro.titulo != "VACIO")
                {
                    venta_unitaria[0].datos_libro.titulo = el_stock[30].datos_libro.titulo;
                    el_stock[0].datos_libro.titulo = "VACIO";
                    venta_unitaria[0].datos_libro.venta = el_stock[30].datos_libro.venta;
                    venta_unitaria[0].datos_libro.costo = el_stock[30].datos_libro.costo;
                    venta_unitaria[0].datos_libro.codigo = el_stock[30].datos_libro.codigo;
                    cantidad_comics_ya_vendidos[3]++;
                    impresion_boleta(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
                    break;
                }
                else
                {
                    venta_unitaria[0].datos_libro.titulo = el_stock[30 + cantidad_comics_ya_vendidos[3]].datos_libro.titulo;
                    el_stock[30 + cantidad_comics_ya_vendidos[3] - 1].datos_libro.titulo = "VACIO";
                    venta_unitaria[0].datos_libro.venta = el_stock[30].datos_libro.venta;
                    venta_unitaria[0].datos_libro.costo = el_stock[30].datos_libro.costo;
                    venta_unitaria[0].datos_libro.codigo = el_stock[30].datos_libro.codigo;
                    cantidad_comics_ya_vendidos[3]++;
                    impresion_boleta(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
                }
            }
            else if (OpcionConfirmar == 2)
            {
                comic(venta_unitaria, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
            }
            break;
        case 2:
            if (OpcionConfirmar == 1)
            {
                if (cantidad_comics_ya_vendidos[4] == 10)
                {
                    cout << CELESTE << "\t\t\tLIBRO AGOTADO POR FAVOR ELIJA OTRO LIBRO" << RESET << endl;
                    comic(venta_unitaria, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
                    break;
                }
                if (el_stock[40].datos_libro.titulo != "VACIO")
                {
                    venta_unitaria[0].datos_libro.titulo = el_stock[40].datos_libro.titulo;
                    el_stock[40].datos_libro.titulo = "VACIO";
                    venta_unitaria[0].datos_libro.venta = el_stock[40].datos_libro.venta;
                    venta_unitaria[0].datos_libro.costo = el_stock[40].datos_libro.costo;
                    venta_unitaria[0].datos_libro.codigo = el_stock[40].datos_libro.codigo;
                    cantidad_comics_ya_vendidos[4]++;
                    impresion_boleta(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
                    break;
                }
                else
                {
                    venta_unitaria[0].datos_libro.titulo = el_stock[40 + cantidad_comics_ya_vendidos[4]].datos_libro.titulo;
                    el_stock[40 + cantidad_comics_ya_vendidos[4]].datos_libro.titulo = "VACIO";
                    venta_unitaria[0].datos_libro.venta = el_stock[40].datos_libro.venta;
                    venta_unitaria[0].datos_libro.costo = el_stock[40].datos_libro.costo;
                    venta_unitaria[0].datos_libro.codigo = el_stock[40].datos_libro.codigo;
                    cantidad_comics_ya_vendidos[4]++;
                    impresion_boleta(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
                }
            }
            else if (OpcionConfirmar == 2)
            {
                comic(venta_unitaria, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
            }
            break;
        case 3:
            ventas_presencial(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
            break;
        default:
            cout << "\n\tOpcion ingresada inavalido " << endl;
            cout << "\tIntente nuevamente ingresando opcion correcta " << endl << endl;
            comic(venta_unitaria, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
            break;
        }
    }
    else if (iteracion == 3)  //3 Comics significa sede Miraflores 
    {
        switch (Opcion)
        {
        case 1:
            if (OpcionConfirmar == 1)
            {
                if (cantidad_comics_ya_vendidos[0] == 10)
                {
                    cout << CELESTE << "\t\t\tLIBRO AGOTADO POR FAVOR ELIJA OTRO LIBRO" << RESET << endl;
                    comic(venta_unitaria, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
                    break;
                }
                if (el_stock[0].datos_libro.titulo != "VACIO")
                {
                    venta_unitaria[0].datos_libro.titulo = el_stock[0].datos_libro.titulo;
                    el_stock[0].datos_libro.titulo = "VACIO";
                    venta_unitaria[0].datos_libro.venta = el_stock[0].datos_libro.venta;
                    venta_unitaria[0].datos_libro.costo = el_stock[0].datos_libro.costo;
                    venta_unitaria[0].datos_libro.codigo = el_stock[0].datos_libro.codigo;
                    cantidad_comics_ya_vendidos[0]++;
                    impresion_boleta(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
                    break;
                }
                else
                {
                    venta_unitaria[0].datos_libro.titulo = el_stock[0 + cantidad_comics_ya_vendidos[0]].datos_libro.titulo;
                    el_stock[0 + cantidad_comics_ya_vendidos[0] - 1].datos_libro.titulo = "VACIO";
                    venta_unitaria[0].datos_libro.venta = el_stock[0].datos_libro.venta;
                    venta_unitaria[0].datos_libro.costo = el_stock[0].datos_libro.costo;
                    venta_unitaria[0].datos_libro.codigo = el_stock[0].datos_libro.codigo;
                    cantidad_comics_ya_vendidos[0]++;
                    impresion_boleta(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
                }
            }
            else if (OpcionConfirmar == 2)
            {
                comic(venta_unitaria, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
            }
            break;
        case 2:
            if (OpcionConfirmar == 1)
            {
                if (cantidad_comics_ya_vendidos[1] == 10)
                {
                    cout << CELESTE << "\t\t\tLIBRO AGOTADO POR FAVOR ELIJA OTRO LIBRO" << RESET << endl;
                    comic(venta_unitaria, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
                    break;
                }
                if (el_stock[10].datos_libro.titulo != "VACIO")
                {
                    venta_unitaria[0].datos_libro.titulo = el_stock[10].datos_libro.titulo;
                    el_stock[10].datos_libro.titulo = "VACIO";
                    venta_unitaria[0].datos_libro.venta = el_stock[10].datos_libro.venta;
                    venta_unitaria[0].datos_libro.costo = el_stock[10].datos_libro.costo;
                    venta_unitaria[0].datos_libro.codigo = el_stock[10].datos_libro.codigo;
                    cantidad_comics_ya_vendidos[1]++;
                    impresion_boleta(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
                    break;
                }
                else
                {
                    venta_unitaria[0].datos_libro.titulo = el_stock[10 + cantidad_comics_ya_vendidos[1]].datos_libro.titulo;
                    el_stock[10 + cantidad_comics_ya_vendidos[1] - 1].datos_libro.titulo = "VACIO";
                    venta_unitaria[0].datos_libro.venta = el_stock[10].datos_libro.venta;
                    venta_unitaria[0].datos_libro.costo = el_stock[10].datos_libro.costo;
                    venta_unitaria[0].datos_libro.codigo = el_stock[10].datos_libro.codigo;
                    cantidad_comics_ya_vendidos[1]++;
                    impresion_boleta(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
                }
            }
            else if (OpcionConfirmar == 2)
            {
                comic(venta_unitaria, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
            }
            break;
        case 3:
            if (OpcionConfirmar == 1)
            {
                if (cantidad_comics_ya_vendidos[2] == 10)
                {
                    cout << CELESTE << "\t\t\tLIBRO AGOTADO POR FAVOR ELIJA OTRO LIBRO" << RESET << endl;
                    comic(venta_unitaria, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
                    break;
                }
                if (el_stock[20].datos_libro.titulo != "VACIO")
                {
                    venta_unitaria[0].datos_libro.titulo = el_stock[20].datos_libro.titulo;
                    el_stock[20].datos_libro.titulo = "VACIO";
                    venta_unitaria[0].datos_libro.venta = el_stock[20].datos_libro.venta;
                    venta_unitaria[0].datos_libro.costo = el_stock[20].datos_libro.costo;
                    venta_unitaria[0].datos_libro.codigo = el_stock[20].datos_libro.codigo;
                    cantidad_comics_ya_vendidos[2]++;
                    impresion_boleta(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
                    break;
                }
                else
                {
                    venta_unitaria[0].datos_libro.titulo = el_stock[20 + cantidad_comics_ya_vendidos[2]].datos_libro.titulo;
                    el_stock[20 + cantidad_comics_ya_vendidos[2] - 1].datos_libro.titulo = "VACIO";
                    venta_unitaria[0].datos_libro.venta = el_stock[20].datos_libro.venta;
                    venta_unitaria[0].datos_libro.costo = el_stock[20].datos_libro.costo;
                    venta_unitaria[0].datos_libro.codigo = el_stock[20].datos_libro.codigo;
                    cantidad_comics_ya_vendidos[2]++;
                    impresion_boleta(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
                }
            }
            else if (OpcionConfirmar == 2)
            {
                comic(venta_unitaria, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
            }
            break;
        case 4:
            ventas_presencial(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
            break;
        default:
            cout << "\n\tOpcion ingresada inavalido " << endl;
            cout << "\tIntente nuevamente ingresando opcion correcta " << endl << endl;
            comic(venta_unitaria, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
            break;
        }
    }

}
void impresion_boleta(datos_venta* el_stock, datos_venta* venta_unitaria, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos)
{
    float valor_igv = 0.18;
    float igv = venta_unitaria[0].datos_libro.venta * valor_igv;
    int subtotal = venta_unitaria[0].datos_libro.venta - igv;
    int parte_entera_de_venta = venta_unitaria[0].datos_libro.venta;
    float parte_decimal_de_venta = venta_unitaria[0].datos_libro.venta - parte_entera_de_venta;
    cout << endl;
    cout << "\t\t\t\t\tBOLETA DE COMPRA: " << endl;
    cout << "\t\t\t=========================================================" << endl;
    funcion_fecha();
    cout << "\t\t\t---------------------------------------------------------" << endl;
    cout << "\t\t\tCTD \t U.M. \t DESCRIPCION \t PRECIO UNIT. \t  IMPORTE" << endl;
    cout << "\t\t\t---------------------------------------------------------" << endl;
    cout << "\t\t\t1 \tUND \t " << venta_unitaria[0].datos_libro.titulo << " \t " << venta_unitaria[0].datos_libro.venta << " \t " << venta_unitaria[0].datos_libro.venta << endl;
    cout << "\t\t\t---------------------------------------------------------" << endl;
    cout << "\t\t\tOP. GRAVADA\tS/.\t:\t\t" << subtotal << endl;
    cout << "\t\t\tIGV : 18%\tS/.\t:\t\t" << igv << endl;
    cout << "\t\t\tVALOR VTA.\tS/.\t:\t\t" << subtotal << endl;
    cout << "\t\t\tIMPORTE TOTAL\tS/.\t:\t\t" << venta_unitaria[0].datos_libro.venta << endl << "\n";
    cout << "\t\t\tSON: " << convertir_numero_en_palabras(int(venta_unitaria[0].datos_libro.venta)) << " CON " << parte_decimal_de_venta * 100 << " / 100 SOLES" << endl;
    cout << "\t\t\t---------------------------------------------------------" << endl;
    cout << "\t\t\t\t  *** GRACIAS POR SU PREFERENCIA ***" << endl;
    opcion_continuar(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
}
void opcion_continuar(datos_venta* el_stock, datos_venta* venta_unitaria, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos) {
    int OpcionCont;
    do
    {
        cout << "\n\t\t\t Desea continuar o Salir?" << endl;
        cout << "\t\t\t--------------------------------------" << endl;
        cout << CELESTE << "\t\t\t Opcion 1 Continuar en el sistema :" << endl;
        cout << "\t\t\t Opcion 2 Salir del Sistema :" << RESET << endl;
        cout << "\t\t\t--------------------------------------" << endl;
        cout << "\n";
        cout << "\t\t\tIngrese Opcion -> : "; cin >> OpcionCont;
        if (OpcionCont < 1 || OpcionCont>2)
        {
            cout << "\n\tOpcion (" << OpcionCont << ") es incorrecto" << endl;
            cout << "\tIntente nuevamente ingresando opcion correcta " << endl << endl;
        }
    } while (OpcionCont < 1 || OpcionCont>2);
    switch (OpcionCont)
    {
    case 1:
        registrar_ventas(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
        delete[]venta_unitaria;
        cout << endl;
        opcion_menu(el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
        break;
    case 2:
        registrar_ventas(el_stock, venta_unitaria, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
        delete[]venta_unitaria;
        exit(0);
        break;
    default:
        break;
    }
}
void registrar_ventas(datos_venta* el_stock, datos_venta* venta_unitaria, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos)
{
    datos_venta* ventas_generales;
    ventas_generales = new datos_venta[100];
    int cantidad_de_libros_vendidos = 0;
    for (int i = 0; i < 5; i++)
    {
        cantidad_de_libros_vendidos += cantidad_mangas_ya_vendidos[i];
    }
    for (int i = 0; i < 5; i++)
    {
        cantidad_de_libros_vendidos += cantidad_comics_ya_vendidos[i];
    }
    for (int i = cantidad_de_libros_vendidos; i < cantidad_de_libros_vendidos + 1; i++)
    {
        ventas_generales[i].datos_libro.titulo = venta_unitaria[0].datos_libro.titulo;
        ventas_generales[i].datos_libro.codigo = venta_unitaria[0].datos_libro.codigo;
        ventas_generales[i].datos_libro.costo = venta_unitaria[0].datos_libro.costo;
        ventas_generales[i].datos_libro.venta = venta_unitaria[0].datos_libro.venta;
        ventas_generales[i].modalidad.tipo_modalidad = venta_unitaria[0].modalidad.tipo_modalidad;
        ventas_generales[i].local = venta_unitaria[0].local;
    }
}
void funcion_fecha()
{
    auto Actual = chrono::system_clock::now();
    auto ActualEpoch = chrono::system_clock::to_time_t(Actual);
    tm* TiempoLocal = localtime(&ActualEpoch);
    cout << "\t\t\tFecha: " << TiempoLocal->tm_mday << "/" << (TiempoLocal->tm_mon + 1) << "/" << (TiempoLocal->tm_year + 1900);
    cout << "\t\t\t" << (TiempoLocal->tm_hour) << ":" << (TiempoLocal->tm_min) << ":" << (TiempoLocal->tm_sec) << endl;
}
int main()
{
    int* cantidad_comics_ya_vendidos;
    int* cantidad_mangas_ya_vendidos;
    cantidad_comics_ya_vendidos = new int[5]();
    cantidad_mangas_ya_vendidos = new int[5]();
    datos_venta* el_stock;
    el_stock = new datos_venta[100];
    generacion_stock(el_stock);
    opcion_menu(el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
}
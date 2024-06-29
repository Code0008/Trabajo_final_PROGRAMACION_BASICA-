#pragma once
#include "cabecera_principales.h"
#include "FUNCIONALIDADES.h"
#include "COLORAMA.h"
using namespace std;

extern void menu_seleccion() {

    cout << "\n" << LBLUE
        "\t\t\t\t\t  ____  _                           _     _       \n"
        "\t\t\t\t\t |  _ \\(_)                         (_)   | |      \n"
        "\t\t\t\t\t | |_) |_  ___ _ ____   _____ _ __  _  __| | ___  \n"
        "\t\t\t\t\t |  _ <| |/ _ \\ '_ \\ \\ / / _ \\ '_ \\| |/ _` |/ _ \\ \n"
        "\t\t\t\t\t | |_) | |  __/ | | \\ V /  __/ | | | | (_| | (_) |\n"
        "\t\t\t\t\t |____/|_|\\___|_| |_|\\_/ \\___|_| |_|_|\\__,_|\\___/ \n"
        "\t\t\t\t\t                                                  \n"
        "\t                                                  " << RESET << endl;

}


extern void menu_login() {
    cout << endl;
    cout <<
        BG_BLACK << MAGENTA <<
        "\t\t\t   $$$$$$$\\ $$$$$$\\$$$$$$$$\\$$\\   $$\\$$\\    $$\\$$$$$$$$\\$$\\   $$\\$$$$$$\\$$$$$$$\\  $$$$$$\\  \n"
        "\t\t\t   $$  __$$\\\\_$$  _$$  _____$$$\\  $$ $$ |   $$ $$  _____$$$\\  $$ \\_$$  _$$  __$$\\$$  __$$\\ \n"
        "\t\t\t   $$ |  $$ | $$ | $$ |     $$$$\\ $$ $$ |   $$ $$ |     $$$$\\ $$ | $$ | $$ |  $$ $$ /  $$ |\n"
        "\t\t\t   $$$$$$$\\ | $$ | $$$$$\\   $$ $$\\$$ \\$$\\  $$  $$$$$\\   $$ $$\\$$ | $$ | $$ |  $$ $$ |  $$ |\n"
        "\t\t\t   $$  __$$\\  $$ | $$  __|  $$ \\$$$$ |\\$$\\$$  /$$  __|  $$ \\$$$$ | $$ | $$ |  $$ $$ |  $$ |\n"
        "\t\t\t   $$ |  $$ | $$ | $$ |     $$ |\\$$$ | \\$$$  / $$ |     $$ |\\$$$ | $$ | $$ |  $$ $$ |  $$ |\n"
        "\t\t\t   $$$$$$$  $$$$$$\\$$$$$$$$\\$$ | \\$$ |  \\$  /  $$$$$$$$\\$$ | \\$$ $$$$$$\\$$$$$$$  |$$$$$$  |\n"
        "\t\t\t   \\_______/\\______\\________\\__|  \\__|   \\_/   \\________\\__|  \\__\\______\\_______/ \\______/ \n" << RESET;
    cout << BLUE ; estetica(88, ' '); cout << endl;
    cout << BLUE<< "\t\t\t"; estetica(80, 219); cout << RESET << endl;
    cout << LGREEN << "\t\t\t\t\t\tfecha de ingreso: " << capture_time() << RESET << endl;
    cout << LGREEN << "\t\t\t\t\t\t-INGRESE INFORMACION BASICA DE USUARIO-\t\t\t" << RESET << endl;
    cout << BLUE<< "\t\t\t";  estetica(80, 219); cout << RESET << endl << endl;
}


extern void menu_principal() {
    cout << endl<<endl<<endl;
    cout << "\t\t\t\t" << MAGENTA;  estetica(99, 219); cout << endl << RESET;
    cout <<
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                          ...                                                                    " << MAGENTA << (char)219 << "\n" <<
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                        .,:;;;,.                                                                 " << MAGENTA << (char)219 << "\n"
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                      .';::::::;,;,.                                                             " << MAGENTA << (char)219 << "\n"
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                      .';::::::;,;,.                                                             " << MAGENTA << (char)219 << "\n"
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                     .,;;;;;;;;;:::;.                                                            " << MAGENTA << (char)219 << "\n"
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                     ';;;;;;;;,,;,;:;,.                           'll,',;ldd:.                   " << MAGENTA << (char)219 << "\n"
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                     .,,;ll;,,,;,,,;;:;.    .;:.     .';;;;;;;;;;o0NX0xdxxxdxc.                  " << MAGENTA << (char)219 << "\n"
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                     .',;:ccc;;:;',,,;:;. .;dKWOc:::coO000OOOO0KXNNKxc,'''''c;                   " << MAGENTA << (char)219 << "\n"
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                     .',;,;cl;,;;''.';,;',d0NNNKOkxkOOOOOkkxxxOXNXOl,'',;,''c:.                  " << MAGENTA << (char)219 << "\n"
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                     .',,,,,,,,,,'. .,,',ck0KKXXXXXXXXXXXXXXXXKXKko;''',;,''c:.                  " << MAGENTA << (char)219 << "\n"
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                       ..''''''..   .'',;o0KKKKKKKKKKKKKKKKKXXKKOl,'''''''',c:.                  " << MAGENTA << (char)219 << "\n"
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                         ......    .,coocdKXXX0xdddxxxxxkxx0XKKOoll:,',,;,''::.                  " << MAGENTA << (char)219 << "\n"
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                                   .;dkxcd0KXX0kxxxkkdlodddOKKOdoxOkoc:::,'';;.                  " << MAGENTA << (char)219 << "\n"
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                                   .,cooco0XXXXXXXXXKkdk0KKKOkdxO000Oxdo:'',,.                   " << MAGENTA << (char)219 << "\n"
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                                   .,;::,lO0KKKKKKKKK00OxdxxxkO00000Okdol;,;.                    " << MAGENTA << (char)219 << "\n"
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                                   .,;;;;d00kkd:;;:;;lxxoodxk0000K0xxl;;c:..                     " << MAGENTA << (char)219 << "\n"
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                                   .';,;dkkdc:,......';:odddxkOOOKkc;,..:c'                      " << MAGENTA << (char)219 << "\n"
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                                   .';clxdol,..........,odxkxxxkOOd... .:l,.                     " << MAGENTA << (char)219 << "\n"
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                                  .,;;;;,,:x0o. ...'d0O00KK000OO0x,..  ,,                        " << MAGENTA << (char)219 << "\n"
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                                  .,;,';;,:OWx. .',;kNNXXNNNNNXXNO:,.  ..                        " << MAGENTA << (char)219 << "\n"
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                                  .';',dkclKWO,.;cco0WNNNNNNNNNNN0c;;,,.                         " << MAGENTA << (char)219 << "\n"
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                                ...',''dkcl0N0lcdkkOKXXNNNNNXXXNN0l:okk;                         " << MAGENTA << (char)219 << "\n"
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                               ..',''''od:cx00OkOOOOdldKNNWNklo0NXK0kd:.                         " << MAGENTA << (char)219 << "\n"
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                              ..,;;;,'',;;cdxk0KKK0kdclxkkxxl:cOXNXKko;                          " << MAGENTA << (char)219 << "\n"
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                                 .';;,,,,,';oddxOKK0Odllllc::::cOXNXKko;                         " << MAGENTA << (char)219 << "\n"
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                                   ........,:::ldxkkOdlooolc:::lk00kocc;.                        " << MAGENTA << (char)219 << "\n"
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                                         ...,;::,':lccllllddolccc;,'.;;'..                       " << MAGENTA << (char)219 << "\n"
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                                           ..'cl;,',,,;:,,;;,'...  .';:,....                     " << MAGENTA << (char)219 << "\n"
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                                          ..,,,,,;::cdkkxoc'........lxol;......                  " << MAGENTA << (char)219 << "\n"
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                                         .';ldddc,';cdxc;ld;..''''.;k0xl:;,,...                  " << MAGENTA << (char)219 << "\n"
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                                         .,:ldol;..';:lxko:,'..'':oxkkdllc:,'..                  " << MAGENTA << (char)219 << "\n"
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                                        .;okOxxo'.'ccoxxdc;,..,:lddddxxxxoc,..                   " << MAGENTA << (char)219 << "\n"
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                                         .,cdo;lo'.:xkxooxxo;........;odoc:;'.                   " << MAGENTA << (char)219 << "\n"
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                                         .,,'..'...'''.''.'..        .'....                      " << MAGENTA << (char)219 << "\n"
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                                             ................                                    " << MAGENTA << (char)219 << "\n"
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                                              ..';cc;....,;:'                                    " << MAGENTA << (char)219 << "\n"
        "\t\t\t\t\t" << MAGENTA << (char)219 << WHITE << "                                              ..',::,....,;c;                                    " << MAGENTA << (char)219 << "\n";
    cout << "\t\t\t\t"<<MAGENTA;  estetica(99, 219); cout << endl << RESET;
    cout << YELLOW << "\n\t\t\t\t\t\t--> " << RESET << LGREEN << "SELECCION PRESTAMO   " << RESET << GRAY << "(1)" << RESET << YELLOW << "\n\t\t\t\t\t\t--> " << RESET << LGREEN << "SELECCION DEVOLUCION " << GRAY << "(2)" << RESET<<endl;
    cout << LGREEN << "\t\t\t\t[!] recuerde que puede modificar sus datos dejandole un comentrio a los administradores " << RESET << endl;


}


extern void menu_prestamo() {
    cout << endl << endl;
    cout << "\t\t\t\t" << CYAN;  estetica(69, 219); cout << endl << RESET;
    cout <<MAGENTA<< "\n"
        "\t\t\t\t\t  _____  _____  ______  _____ _______       __  __  ____  \n"
        "\t\t\t\t\t |  __ \\|  __ \\|  ____|/ ____|__   __|/\\   |  \\/  |/ __ \\ \n"
        "\t\t\t\t\t | |__) | |__) | |__  | (___    | |  /  \\  | \\  / | |  | |\n"
        "\t\t\t\t\t |  ___/|  _  /|  __|  \\___ \\   | | / /\\ \\ | |\\/| | |  | |\n"
        "\t\t\t\t\t | |    | | \\ \\| |____ ____) |  | |/ ____ \\| |  | | |__| |\n"
        "\t\t\t\t\t |_|    |_|  \\_\\______|_____/   |_/_/    \\_\\_|  |_|\\____/ \n";
    cout << "\t\t\t\t" << CYAN;  estetica(69, 219); cout << endl << RESET;
    cout << "\t\t\t\t" << MAGENTA;  estetica(69, 177); cout << endl << RESET;
}

extern void menu_de_sancion() {
    cout << RED << "[!]" << RESET << ORANGE << "EL USUARIO TIENE SANCION " << RESET << endl;

}



extern void menu_adminsitrador() {
    cout << BG_BLACK << MAGENTA <<
        "\t\t\t\t\t            _____  __  __ _____ _   _ _____  _____ _______ _____            _____   ____  _____  \n"
        "\t\t\t\t\t     /\\   |  __ \\|  \\/  |_   _| \\ | |_   _|/ ____|__   __|  __ \\     /\\   |  __ \\ / __ \\|  __ \\ \n"
        "\t\t\t\t\t    /  \\  | |  | | \\  / | | | |  \\| | | | | (___    | |  | |__) |   /  \\  | |  | | |  | | |__) |\n"
        "\t\t\t\t\t   / /\\ \\ | |  | | |\\/| | | | | . ` | | |  \\___ \\   | |  |  _  /   / /\\ \\ | |  | | |  | |  _  / \n"
        "\t\t\t\t\t  / ____ \\| |__| | |  | |_| |_| |\\  |_| |_ ____) |  | |  | | \\ \\  / ____ \\| |__| | |__| | | \\ \\ \n"
        "\t\t\t\t\t /_/    \\_\\_____/|_|  |_|_____|_| \\_|_____|_____/   |_|  |_|  \\_\\/_/    \\_\\_____/ \\____/|_|  \\_\\\n"
        "\t\t\t\t\t                                                                                                \n"
        "\t\t\t\t\t                                                                                                " << RESET;
}

extern void menu_devulocion() {
    cout << endl << endl;
    cout << "\t\t\t\t" << CYAN;  estetica(69, 219); cout << endl << RESET;
    cout <<MAGENTA<<"\n"
        "\t\t\t\t\t  _____  ________      ______  _     _    _  _____ _____ ____  _   _ \n"
        "\t\t\t\t\t |  __ \\|  ____\\ \\    / / __ \\| |   | |  | |/ ____|_   _/ __ \\| \\ | |\n"
        "\t\t\t\t\t | |  | | |__   \\ \\  / / |  | | |   | |  | | |      | || |  | |  \\| |\n"
        "\t\t\t\t\t | |  | |  __|   \\ \\/ /| |  | | |   | |  | | |      | || |  | | . ` |\n"
        "\t\t\t\t\t | |__| | |____   \\  / | |__| | |___| |__| | |____ _| || |__| | |\\  |\n"
        "\t\t\t\t\t |_____/|______|   \\/   \\____/|______\\____/ \\_____|_____\\____/|_| \\_|\n"
        "\t\t\t\t\t                                                                     " << endl;
    cout << "\t\t\t\t" << CYAN;  estetica(69, 219); cout << endl << RESET;
    cout << "\t\t\t\t" << MAGENTA;  estetica(69, 177); cout << endl << RESET;
}

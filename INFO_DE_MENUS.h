#pragma once
#include <iostream>
#include "FUNCIONALIDADES.h"
#include "COLORAMA.h"
using namespace std;

extern void menu_seleccion() {
        
    cout << "\n" << LBLUE
        "\t  ____  _                           _     _       \n"
        "\t |  _ \\(_)                         (_)   | |      \n"
        "\t | |_) |_  ___ _ ____   _____ _ __  _  __| | ___  \n"
        "\t |  _ <| |/ _ \\ '_ \\ \\ / / _ \\ '_ \\| |/ _` |/ _ \\ \n"
        "\t | |_) | |  __/ | | \\ V /  __/ | | | | (_| | (_) |\n"
        "\t |____/|_|\\___|_| |_|\\_/ \\___|_| |_|_|\\__,_|\\___/ \n"
        "\t                                                  \n"
        "\t                                                  " << RESET << endl;

}


extern void menu_login() {
    cout << endl;
    cout <<
        BG_BLACK << MAGENTA <<
        "\t\t$$$$$$$\\ $$$$$$\\$$$$$$$$\\$$\\   $$\\$$\\    $$\\$$$$$$$$\\$$\\   $$\\$$$$$$\\$$$$$$$\\  $$$$$$\\  \n"
        "\t\t$$  __$$\\\\_$$  _$$  _____$$$\\  $$ $$ |   $$ $$  _____$$$\\  $$ \\_$$  _$$  __$$\\$$  __$$\\ \n"
        "\t\t$$ |  $$ | $$ | $$ |     $$$$\\ $$ $$ |   $$ $$ |     $$$$\\ $$ | $$ | $$ |  $$ $$ /  $$ |\n"
        "\t\t$$$$$$$\\ | $$ | $$$$$\\   $$ $$\\$$ \\$$\\  $$  $$$$$\\   $$ $$\\$$ | $$ | $$ |  $$ $$ |  $$ |\n"
        "\t\t$$  __$$\\  $$ | $$  __|  $$ \\$$$$ |\\$$\\$$  /$$  __|  $$ \\$$$$ | $$ | $$ |  $$ $$ |  $$ |\n"
        "\t\t$$ |  $$ | $$ | $$ |     $$ |\\$$$ | \\$$$  / $$ |     $$ |\\$$$ | $$ | $$ |  $$ $$ |  $$ |\n"
        "\t\t$$$$$$$  $$$$$$\\$$$$$$$$\\$$ | \\$$ |  \\$  /  $$$$$$$$\\$$ | \\$$ $$$$$$\\$$$$$$$  |$$$$$$  |\n"
        "\t\t\\_______/\\______\\________\\__|  \\__|   \\_/   \\________\\__|  \\__\\______\\_______/ \\______/ \n" << RESET;
    cout << BG_BLACK << "\t"; estetica(88, ' '); cout << endl;
    cout <<  BLUE;  estetica(100, 219); cout << RESET<< endl;
    cout << LGREEN << "\t\t\t\tfecha de ingreso: " << capture_time() << RESET << endl;
    cout << LGREEN << "\t\t\t\t\t-INGRESE INFORMACION BASICA DE USUARIO-\t\t\t" << RESET << endl;
    cout <<  BLUE;  estetica(100, 219); cout << RESET << endl<< endl;
}


extern void menu_principal() {
    cout <<  LGREEN;
    cout << "                          ...                                                                       \n"
        "                        .,:;;;,.                                                                    \n"
        "                      .';::::::;,;,.                                                                \n"
        "                     .,;;;;;;;;;:::;.                                                               \n"
        "                     ';;;;;;;;,,;,;:;,.                           'll,',;ldd:.                      \n"
        "                     .,,;ll;,,,;,,,;;:;.    .;:.     .';;;;;;;;;;o0NX0xdxxxdxc.                     \n"
        "                     .',;:ccc;;:;',,,;:;. .;dKWOc:::coO000OOOO0KXNNKxc,'''''c;                      \n"
        "                     .',;,;cl;,;;''.';,;',d0NNNKOkxkOOOOOkkxxxOXNXOl,'',;,''c:.                     \n"
        "                     .',,,,,,,,,,'. .,,',ck0KKXXXXXXXXXXXXXXXXKXKko;''',;,''c:.                     \n"
        "                       ..''''''..   .'',;o0KKKKKKKKKKKKKKKKKXXKKOl,'''''''',c:.                     \n"
        "                         ......    .,coocdKXXX0xdddxxxxxkxx0XKKOoll:,',,;,''::.                     \n"
        "                                   .;dkxcd0KXX0kxxxkkdlodddOKKOdoxOkoc:::,'';;.                     \n"
        "                                   .,cooco0XXXXXXXXXKkdk0KKKOkdxO000Oxdo:'',,.                      \n"
        "                                   .,;::,lO0KKKKKKKKK00OxdxxxkO00000Okdol;,;.                       \n"
        "                                   .,;;;;d00kkd:;;:;;lxxoodxk0000K0xxl;;c:..                        \n"
        "                                   .';,;dkkdc:,......';:odddxkOOOKkc;,..:c'                         \n"
        "                                   .';clxdol,..........,odxkxxxkOOd... .:l,.                        \n"
        "                                   .,;;;;,,:x0o. ...'d0O00KK000OO0x,..  ,,                          \n"
        "                                   .,;,';;,:OWx. .',;kNNXXNNNNNXXNO:,.  ..                          \n"
        "                                   .';',dkclKWO,.;cco0WNNNNNNNNNNN0c;;,,.                           \n"
        "                                 ...',''dkcl0N0lcdkkOKXXNNNNNXXXNN0l:okk;                           \n"
        "                                ..',''''od:cx00OkOOOOdldKNNWNklo0NXK0kd:.                           \n"
        "                               ..,;;;,'',;;cdxk0KKK0kdclxkkxxl:cOXNXKko;                            \n"
        "                                 .';;,,,,,';oddxOKK0Odllllc::::cOXNXKko;                            \n"
        "                                   ........,:::ldxkkOdlooolc:::lk00kocc;.                           \n"
        "                                          ...,;::,':lccllllddolccc;,'.;;'..                         \n"
        "                                            ..'cl;,',,,;:,,;;,'...  .';:,....                       \n"
        "                                          ..,,,,,;::cdkkxoc'........lxol;......                     \n"
        "                                         .';ldddc,';cdxc;ld;..''''.;k0xl:;,,...                     \n"
        "                                         .,:ldol;..';:lxko:,'..'':oxkkdllc:,'..                     \n"
        "                                         .;okOxxo'.'ccoxxdc;,..,:lddddxxxxoc,..                     \n"
        "                                         .,cdo;lo'.:xkxooxxo;........;odoc:;'.                      \n"
        "                                          .,,'..'...'''.''.'..        .'....                        \n"
        "                                              ................                                      \n"
        "                                               ..';cc;....,;:'                                      \n"
        "                                               ..',::,....,;c;                                      \n"
        "                                                                " <<RESET<< endl;
    cout << endl;
    cout << MAGENTA; estetica(100, 219); cout << endl << RESET;
    cout <<YELLOW << "\n\t--> " << RESET <<LGREEN<<"SELECCION PRESTAMO   "<<RESET<<GRAY << "(1)" << RESET<< YELLOW << "\n\t--> " << RESET << LGREEN <<"SELECCION DEVOLUCION " << GRAY << "(2)" << RESET;

}


extern void menu_prestamo() {
    cout << "\n"
        "\t  _____  _____  ______  _____ _______       __  __  ____  \n"
        "\t |  __ \\|  __ \\|  ____|/ ____|__   __|/\\   |  \\/  |/ __ \\ \n"
        "\t | |__) | |__) | |__  | (___    | |  /  \\  | \\  / | |  | |\n"
        "\t |  ___/|  _  /|  __|  \\___ \\   | | / /\\ \\ | |\\/| | |  | |\n"
        "\t | |    | | \\ \\| |____ ____) |  | |/ ____ \\| |  | | |__| |\n"
        "\t |_|    |_|  \\_\\______|_____/   |_/_/    \\_\\_|  |_|\\____/ \n"
        "                                                          ";
}

extern void menu_de_sancion(){
    cout << RED << "[!]" << RESET << ORANGE<<"EL USUARIO TIENE SANCION " << RESET<< endl;

}



extern void menu_adminsitrador() {
    cout << BG_BLACK << MAGENTA <<
        "\t           _____  __  __ _____ _   _ _____  _____ _______ _____            _____   ____  _____  \n"
        "\t     /\\   |  __ \\|  \\/  |_   _| \\ | |_   _|/ ____|__   __|  __ \\     /\\   |  __ \\ / __ \\|  __ \\ \n"
        "\t    /  \\  | |  | | \\  / | | | |  \\| | | | | (___    | |  | |__) |   /  \\  | |  | | |  | | |__) |\n"
        "\t   / /\\ \\ | |  | | |\\/| | | | | . ` | | |  \\___ \\   | |  |  _  /   / /\\ \\ | |  | | |  | |  _  / \n"
        "\t  / ____ \\| |__| | |  | |_| |_| |\\  |_| |_ ____) |  | |  | | \\ \\  / ____ \\| |__| | |__| | | \\ \\ \n"
        "\t /_/    \\_\\_____/|_|  |_|_____|_| \\_|_____|_____/   |_|  |_|  \\_\\/_/    \\_\\_____/ \\____/|_|  \\_\\\n"
        "\t                                                                                                \n"
        "\t                                                                                                "<< RESET;

}

extern void menu_devulocion() {
    cout << "\n"
        "  _____  ________      ______  _     _    _  _____ _____ ____  _   _ \n"
        " |  __ \\|  ____\\ \\    / / __ \\| |   | |  | |/ ____|_   _/ __ \\| \\ | |\n"
        " | |  | | |__   \\ \\  / / |  | | |   | |  | | |      | || |  | |  \\| |\n"
        " | |  | |  __|   \\ \\/ /| |  | | |   | |  | | |      | || |  | | . ` |\n"
        " | |__| | |____   \\  / | |__| | |___| |__| | |____ _| || |__| | |\\  |\n"
        " |_____/|______|   \\/   \\____/|______\\____/ \\_____|_____\\____/|_| \\_|\n"
        "                                                                     \n"
        "                                                                     " << endl;

}

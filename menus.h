#ifndef MENUS_H
#define MENUS_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Opcion {
    string texto;
    char tecla;
};

class menu {
private:
    vector<Opcion> opciones;
    string titulo;

public:
    menu(string t = "Menu Principal");

    void agregar(string texto, char tecla);
    void mostrar();
    char leerOpcion();
};

#endif

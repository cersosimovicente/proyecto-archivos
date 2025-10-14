#include "menus.h"

menu::menu(string t) {
    titulo = t;
}

void menu::agregar(string texto, char tecla) {
    Opcion op;
    op.texto = texto;
    op.tecla = tecla;
    opciones.push_back(op);
}

void menu::mostrar() {
    cout << "\n========== " << titulo << " ==========\n";
    for (auto &op : opciones) {
        cout << "[" << op.tecla << "] " << op.texto << endl;
    }
    cout << "=====================================\n";
    cout << "Seleccione una opcion: ";
}

char menu::leerOpcion() {
    char opc;
    cin >> opc;
    return opc;
}

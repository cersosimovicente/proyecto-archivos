#ifndef ADMINCUENTAS_H
#define ADMINCUENTAS_H

#include <iostream>
#include <fstream>
#include <cstring>

class empleado
{
private:
    char nombre[30];
    int edad;
    float salario;

public:
    empleado();

    void ingresardatos();
    void verdatos();
    void recuperarCuentas(int &_totEmp, empleado Em[]);
    void escribirCuentas(int totEmp, empleado Em[]);
    void imprimirCuentas(int totEmp, empleado Em[]);
    void agregarCuenta(int &totEmp, empleado Em[]);
    void eliminarCuenta(int &totEmp, empleado Em[]);
    void removerposicion(int &totEmp, empleado Em[], int x);
};

#endif

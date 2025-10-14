#include "menus.h"
#include "adminCuentas.h"
#include <chrono>
#include <thread>
#include <conio.h>

void escribirCuentas(int totEmp, empleado Emple[]);

void recuperarCuentas(int &totEmp, empleado Emple[]);

int main()
{
    int totEmp = 0;      // Total de empleados registrados
    empleado Emple[100]; // arreglo de struct

    bool salir = false;
    // prepara menu
    menu mimenu;
    mimenu.agregar("Ver empleados registrados", '1');
    mimenu.agregar("Agregar empleado a la planilla", '2');
    mimenu.agregar("Modificar datos de empleado", '3');
    mimenu.agregar("Eliminar empleado del registro", '4');
    mimenu.agregar("Finalizar aplicacion", 's');

    std::this_thread::sleep_for(std::chrono::milliseconds(1500)); // pausa ejecucion por 1.5 segundos
    // Lee los datos de empleados almacenados en archivo binario
    Emple[totEmp].recuperarCuentas(totEmp, Emple);
    // ciclo principal
    do
    {
        system("cls");
        cout << "MANTENIMIENTO DE PLANILLA MENSUAL\n\n";
        mimenu.mostrar();

        switch (mimenu.leerOpcion())
        {
        case '1':
            Emple[totEmp].imprimirCuentas(totEmp, Emple);
            break;
        case '2':
               Emple[totEmp].agregarCuenta(totEmp,Emple);
            break;
        case '3':
            break;
        case '4':
               Emple[totEmp].eliminarCuenta(totEmp,Emple);
            break;

        default:
            salir = true;
            break;
        }

        if (salir)
            cout << "\nEl programa finalizara ahora";
        else
        {
            cout << "\n\nPresione cualquier tecla para regresar al menu";
            getch();
        }

    } while (!salir);

    Emple[totEmp].escribirCuentas(totEmp, Emple);

    return 0;
}

//compilar  g++ main.cpp adminCuentas.cpp menus.cpp -o programa.exe

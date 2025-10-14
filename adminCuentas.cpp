#include "adminCuentas.h"
#include <iomanip>
using namespace std;

empleado::empleado()
{
    strcpy(nombre, "FALTA");
    edad = 0;
    salario = 0;
}

void empleado::ingresardatos()
{
    cout << "Ingrese nombre: ";
    cin >> nombre;
    cout << "Ingrese edad: ";
    cin >> edad;
    cout << "Ingrese salario: ";
    cin >> salario;
}

void empleado::verdatos()
{
    cout << "\nNombre: " << nombre;
    cout << "\nEdad: " << edad;
    cout << "\nSalario: " << salario << endl;
}

void empleado::recuperarCuentas(int &_totEmp, empleado Em[])
{
    ifstream archi;
    ofstream archi2;
    int longi;
    _totEmp = 0;

    archi.open("cuentas.DAT", ios::binary);
    if (archi.is_open()) // Verifica si el archivo "archi" se abrió correctamente
    {
        archi.seekg(0, ios::end);           // ir al final
        longi = archi.tellg();              // obtener la posición actual, que es el tamaño del archivo
        _totEmp = longi / sizeof(empleado); // Calcula cuántos registros de tipo 'empleado' hay en el archivo
        archi.seekg(0, ios::beg);           // Devuelve el puntero al inicio del archivo para comenzar a leer

        // Lee todos los registros de empleados y los almacena en el arreglo Em[]
        for (int i = 0; i < _totEmp; i++)
            archi.read((char *)&Em[i], sizeof(empleado)); // Lee un registro completo (sizeof(empleado)) y lo guarda en Em[i]
        archi.close();                                    // Cierra el archivo después de leer
    }
    else
    {
        archi2.open("cuentas.DAT", ios::out); // Crea un nuevo archivo "cuentas.DAT" en modo escritura
        archi2.close();                       // Lo cierra inmediatamente después de crearlo
    }
}

void empleado::escribirCuentas(int totEmp, empleado Em[])
{
    ofstream archi;
    // Crea un objeto de salida de archivo para escribir datos binarios

    archi.open("cuentas.DAT", ios::binary);
    // Abre el archivo "cuentas.DAT" en modo binario.
    // Si el archivo no existe, se crea automáticamente.
    // Si existe, se sobrescribe (por defecto en ofstream).

    archi.seekp(0, ios::beg);
    // Mueve el puntero de escritura al inicio del archivo.
    // Esto asegura que los registros se escriban desde el principio.

    // Bucle para escribir todos los registros de empleados
    for (int i = 0; i < totEmp; i++)
        archi.write((char *)(&Em[i]), sizeof(empleado));
    // Convierte la dirección de Em[i] a char* porque write() requiere un puntero de bytes
    // Escribe sizeof(empleado) bytes en el archivo para cada empleado

    archi.close();
    // Cierra el archivo después de terminar la escritura
}

void empleado::imprimirCuentas(int totEmp, empleado Em[])
{
    cout << "\nLista de empleados registrados\n\n";
    // Imprime un encabezado para la lista de empleados

    if (totEmp == 0) // Verifica si no hay empleados registrados
    {
        cout << "(aun sin registros)\n";
        // Mensaje indicando que no hay registros
    }
    else
    {
        cout << "Tot. empleados: " << totEmp << endl;
        // Muestra el total de empleados registrados

        cout.setf(ios::left);
        // Alinea a la izquierda los campos siguientes

        cout << "\n # " << setw(25) << "nombre" << " Edad, sueldo base ($)\n";
        // Imprime el encabezado de la tabla: número, nombre, edad y sueldo base
        // setw(25) asegura que el campo 'nombre' tenga un ancho fijo de 25 caracteres

        cout.setf(ios::right);
        // Cambia la alineación a la derecha para los datos

        // Bucle para imprimir cada empleado
        for (int i = 0; i < totEmp; i++)
        {
            cout << endl
                 << setw(3) << i + 1;
            // Muestra el número de registro alineado a la derecha (ancho 3)

            Em[i].verdatos();
            // Llama al método verdatos() de cada empleado para imprimir sus datos
        }
    }
} // fin funcion imprimirCuentas

void empleado::agregarCuenta(int &totEmp, empleado Em[])
{
    cout << "Agregando al empleado # " << totEmp + 1;
    // Muestra en pantalla el número del nuevo empleado a agregar
    // totEmp + 1 porque los índices empiezan en 0, pero el conteo humano empieza en 1

    Em[totEmp].ingresardatos();
    // Llama al método ingresardatos() del objeto empleado en la posición totEmp
    // Este método debería solicitar al usuario que ingrese el nombre, edad, sueldo, etc.

    totEmp++;
    // Incrementa el contador de empleados, ya que se agregó uno nuevo
} // fin funcion agregarCuenta

void empleado::eliminarCuenta(int &totEmp, empleado Em[])
{
    int numEmp; // Variable para almacenar el número del empleado a eliminar (índice en el arreglo)

    cout << "\nEliminando a un empleado\n\n";
    // Mensaje de encabezado

    if (totEmp == 0) // Si no hay empleados registrados
        cout << "(aun sin registros)\n";
    // Aviso de que no hay registros para eliminar
    else
    {
        cout << "Lista actual de empleados:\n";
        // Muestra la lista de empleados antes de eliminar

        cout.setf(ios::left);
        // Alinea a la izquierda el encabezado de la tabla
        cout << "\n # " << setw(25) << "nombre" << " Edad, sueldo base ($)\n";
        // Encabezado de la tabla
        cout.setf(ios::right);
        // Cambia alineación a derecha para los datos

        // Muestra todos los empleados registrados
        for (int i = 0; i < totEmp; i++)
        {
            cout << endl
                 << setw(3) << i + 1;
            // Número del empleado alineado a la derecha (ancho 3)
            Em[i].verdatos();
            // Llama a verdatos() para mostrar los detalles del empleado
        }

        cout << "\n\nDigitenum de empleado a borrar: ";
        // Solicita al usuario el número del empleado a eliminar
        cin >> numEmp;

        numEmp--;
        // Ajusta el número ingresado al índice del arreglo (0 basado)

        removerposicion(totEmp, Em, numEmp);
        // Llama a la función removerposicion() que elimina al empleado en la posición indicada
        // Esta función debe mover los elementos posteriores para llenar el espacio

        totEmp--;
        // Disminuye el total de empleados porque se eliminó uno
    } // fin else
} // fin funcion eliminarCuenta

void empleado::removerposicion(int &totEmp, empleado Em[], int x)
{
    // Desplaza todos los elementos del arreglo una posición hacia atrás
    // comenzando desde la posición x, para "eliminar" el empleado en esa posición

    for (; x < totEmp - 1; x++)
        Em[x] = Em[x + 1];
    // Copia el elemento siguiente (x+1) en la posición actual (x)
    // Esto sobrescribe al empleado que queremos eliminar
    // y desplaza todos los siguientes una posición hacia atrás

} // fin funcion removerposicion

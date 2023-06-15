#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <limits>
#include "Clientes.h"

using namespace std;

Clientes Cliente[50];          //Instanciacion por defecto de nuestra base de datos de los clientes
int ubicC = 0;                 //Declaracion de variables globales en constante uso
int nro_T = 0;

bool verificarFecha(int cDia, int cMes, int cAnio) {
    if (cMes > 0 && cMes < 13) {
        if (cDia > 0 && cDia < 32) {
            if (cMes == 4 || cMes == 6, cMes == 9, cMes == 11) {
                if (cDia > 30) {
                    return false;
                }
            } else if (cMes == 2) {
                if (cDia > 29) {
                    return false;
                }
                if (cAnio < 2000 || cAnio > 2023) {
                    return false;
                }

            }
        }
        return true;
    } else if (cMes < 0 || cMes > 12) {
        return false;
    }
}            //LISTO

bool verificadorAlta(int cAnio) {
    if (cAnio < 2000 || cAnio > 2023) {
        return false;
    } else {
        return true;
    }
}                               //LISTO

void trSeisMeses() {


    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            if (Cliente[i].Transacciones[j].getAnio() == 2023 && Cliente[i].Transacciones[j].getMes() > 0 &&
                Cliente[i].Transacciones[j].getMes() < 7) {
                Cliente[i].Transacciones[j].mostrarTransaccion();
            }
        }
    }


}                                            //LISTO

void trAnio() {
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            if ((Cliente[i].Transacciones[j].getAnio() == 2023 || Cliente[i].Transacciones[j].getAnio() == 2022) &&
                Cliente[i].Transacciones[j].getMes() > 0 && Cliente[i].Transacciones[j].getMes() < 7) {
                Cliente[i].Transacciones[j].mostrarTransaccion();
            }
        }
    }
}                                                 //LISTO

void trTotal() {

    int i, j=0;
    for (i=0; i<50; i++) {
         while (Cliente[i].Transacciones[j].getCant() != 0) {
             Cliente[i].Transacciones[j].mostrarTransaccion();
             j++;
         }
    }

}               //LISTO

void menuTiempo() {
    int opc = 1;
    while (opc > 0 && opc < 4) {
        cout << "Ingrese el periodo de tiempo que requiere: " << endl;
        cout << "1. Por 6 meses" << endl;
        cout << "2. Por un anio" << endl;
        cout << "3. Total" << endl;
        cout << "4. Volver al menu principal" << endl;
        cin >> opc;

        switch (opc) {
            case 1:
                trSeisMeses();
                break;

            case 2:
                trAnio();
                break;

            case 3:
                trTotal();

                break;

        }
    }
}                     //LISTO

void generarClientesTxt() {

    ofstream archivoClientes;
    archivoClientes.open("Clientes.txt");
    for (int i = 0; i < 50; i++) {
        if (Cliente[i].getNumero() != 0) {
            archivoClientes << Cliente[i].getNumero() << "," << Cliente[i].getNombre() << ","
                            << Cliente[i].getApellido() << "," << Cliente[i].getTipo() << ","
                            << Cliente[i].getApertura() << "," << Cliente[i].getEstado() <<","<<Cliente[i].getSaldo()<< endl;
        }
    }
    archivoClientes.close();
    ifstream fileloaded;
}             //LISTO

void generarMovimientosTxt() {

        ofstream archivoMovimientos;
        archivoMovimientos.open("Movimientos.txt");
        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < 50; j++) {
                if (Cliente[i].Transacciones[j].getNroTran() != 0) {
                    archivoMovimientos << Cliente[i].getNumero() << "," << Cliente[i].Transacciones[j].getNroTran() << ","
                                       << Cliente[i].Transacciones[j].getCant() << ","
                                       << Cliente[i].Transacciones[j].getTipo() << ","
                                       << Cliente[i].Transacciones[j].getDia() << ","
                                       << Cliente[i].Transacciones[j].getMes() << ","
                                       << Cliente[i].Transacciones[j].getAnio() << endl;
                }
            }

        }
        archivoMovimientos.close();
        ifstream fileloaded;
    }                                   //LISTO

void altaCliente() {
    int num, cinApertura;
    string cinNombre, cinApellido, cinTipo, cinEstado;
    num = ubicC + 1;
    cout << "Nombre" << endl;
    cin >> cinNombre;
    cout << "Apellido" << endl;
    cin >> cinApellido;

    cout << "Tipo de cliente (plata, oro, black)" << endl;
    cin >> cinTipo;

    cout << "Momento de apertura de la cuenta" << endl;
    cin >> cinApertura;

    if (verificadorAlta(cinApertura)) {

        if (cinApertura >= 2020 && (cinTipo == "black" || cinTipo == "BLACK" || cinTipo == "Black")) {
            cout << "Los clientes con una antiguedad menor a 3 anios no pueden ser de tipo black" << endl;

        } else {

            Cliente[ubicC].tarjetas.limiteTarjetas(cinTipo);

            Cliente[ubicC] = Clientes(num, cinNombre, cinApellido, cinTipo, cinApertura, "ACTIVO", 0);

            cout << "Se le ha dado alta al cliente: " << Cliente[ubicC].getNombre() << " "
                 << Cliente[ubicC].getApellido() << endl;
            cout << "Su numero de cliente asignado es: " << num << endl;

            ubicC++;
        }
    } else {
        cout << "Anio invalido" << endl;
    }
}                    //LISTO

void bajaCliente() {
    int cinNumero;
    cout << "Ingrese el numero de cliente" << endl;
    cin >> cinNumero;

    for (int j = 0; j < 50; j++) {
        if (Cliente[j].getNumero() == cinNumero) {

            Cliente[j].baja(cinNumero);

        }
    }
}                    //LISTO

void extraccion() { //LISTO
    int cinNumero, dia, mes, anio, i = 0;
    long cinMonto;

    cout << "Ingrese el dia: " << endl;
    cin >> dia;
    cout << "Ingrese el mes: " << endl;
    cin >> mes;
    cout << "Ingrese el anio: " << endl;
    cin >> anio;

    if (verificarFecha(dia, mes, anio)) {

        cout << "Ingrese su numero de cliente" << endl;
        cin >> cinNumero;

        for (i = 0; i < 50; i++) {
            if (Cliente[i].getNumero() == cinNumero && Cliente[i].getEstado() == "ACTIVO") {

                cout << "Ingrese el monto a extraer" << endl;
                cin >> cinMonto;

                if (cinMonto <= Cliente[i].getSaldo() && cinMonto > 0) {

                    Cliente[i].setSaldo(Cliente[i].getSaldo() - cinMonto);

                    cout << "SU MONTO ACTUALIZADO ES DE: " << Cliente[i].getSaldo() << endl;

                    Cliente[i].Transacciones[nro_T] = Transacciones(nro_T + 1, Cliente[i].getSaldo(), cinMonto, "E",
                                                                    dia, mes, anio);

                    Cliente[i].Transacciones[nro_T].mostrarTransaccion();


                    i = 49;
                    nro_T++;

                } else {
                    cout << "ERROR: El monto ingresado es mayor al saldo o es negativo" << endl;

                    i = 49;

                }

            } else if (i == 49 && Cliente[i].getNumero() != cinNumero) {
                cout << "Cliente no encontrado o dado de baja" << endl;
            }
        }

    } else {
        cout << "La fecha ingresada es invalida" << endl;
    }

}                     //LISTO

void deposito() {
    int cinNumero, dia, mes, anio, i = 0;
    long cinMonto;

    cout << "Ingrese el dia: " << endl;
    cin >> dia;
    cout << "Ingrese el mes: " << endl;
    cin >> mes;
    cout << "Ingrese el anio: " << endl;
    cin >> anio;


    if (verificarFecha(dia, mes, anio)) {
        cout << "Ingrese su numero de cliente" << endl;
        cin >> cinNumero;
        for (i = 0; i < 50; i++) {
            if (Cliente[i].getNumero() == cinNumero && Cliente[i].getEstado() == "ACTIVO") {

                cout << "Ingrese el monto a depositar" << endl;
                cin >> cinMonto;

                if (cinMonto > 0) {

                    Cliente[i].setSaldo(Cliente[i].getSaldo() + cinMonto);

                    cout << "SU MONTO ACTUALIZADO ES DE: " << Cliente[i].getSaldo() << endl;

                    Cliente[i].Transacciones[nro_T] = Transacciones(nro_T + 1, Cliente[i].getSaldo(), cinMonto, "D",
                                                                    dia, mes, anio);

                    i = 49;
                    nro_T++;

                } else {
                    cout << "ERROR: El monto ingresado es negativo" << endl;
                    i = 49;
                }

            } else if (i == 49 && Cliente[i].getNumero() != cinNumero) {
                cout << "Cliente no encontrado o dado de baja" << endl;

            }
        }
    } else {
        cout << "La fecha ingresada es invalida" << endl;
    }

}                       //LISTO

void consultaPorNumeroCli() {               //LISTO
    int cinNumero;
    cout << "Ingrese el numero de cliente" << endl;
    cin >> cinNumero;
    for (int j = 0; j < 50; j++) {
        if (Cliente[j].getNumero() == cinNumero) {
            Cliente[j].mostrarCliente();
            j = 50;
        } else if (j == 49 && Cliente[j].getNumero() != cinNumero) {
            cout << "Cliente no encontrado" << endl;
        }
    }
}           //LISTO

void consultaTrPorNumCliente() {            //LISTO
    int cinNumero;
    cout << "Ingrese el numero de cliente: " << endl;
    cin >> cinNumero;

    bool bandera = false;

    for (int j = 0; j < 50; j++) {
        if (Cliente[j].getNumero() == cinNumero) {
            bandera = true;
        }
    }

    if (bandera) {
        for (int i = 0; i < 50; ++i) {
            if (Cliente[cinNumero - 1].Transacciones[i].getCant() != 0) {
                Cliente[cinNumero - 1].Transacciones[i].mostrarTransaccion();
            }
        }
    }

    if (!bandera) {
        cout << "Cliente no encontrado" << endl;
    }

}        //LISTO

void mostrarClientes() {                    //LISTO

    for (int i = 0; i < 50; i++) {
        if (Cliente[i].getNombre() != "") {
            cout << Cliente[i].getNumero() << " | " << Cliente[i].getNombre() << " | " << Cliente[i].getApellido()
                 << " | " << Cliente[i].getTipo() << " | " << Cliente[i].getApertura() << " | "
                 << Cliente[i].getEstado() <<" | "<<Cliente[i].getSaldo()<< endl;
        }
    }

}                //LISTO

void menuExtra() {
    int op = 1;
    while (op > 0 && op < 5) {
        cout << "Ingrese una opcion: " << endl;
        cout << "1. Consultar cliente (por numero)" << endl;
        cout << "2. Mostrar todos los clientes" << endl;
        cout << "3. Transacciones de cliente (por numero)" << endl;
        cout << "4. Informe de transacciones" << endl;
        cout << "5. Volver al menu principal" << endl;
        cin >> op;
        switch (op) {
            case 1:
                consultaPorNumeroCli();
                break;

            case 2: {
                mostrarClientes();
                break;
            }
            case 3: {
                consultaTrPorNumCliente();
                break;
            }
            case 4: {
                menuTiempo();
                break;
            }
        }
    }
}                      //LISTO

void leerArchivoCliente() {

    ifstream archivoClientes("Clientes.txt");
    string linea, dato;
    stringstream s;     //linea
    while (getline(archivoClientes, linea, '\n')) {

        s.str(linea);

        int cont = 0;

        while (getline(s, dato, ',')) {

            switch (cont) {
                case 0: {

                    int number1;
                    number1 = stoi(dato);
                    Cliente[ubicC].setNumero(number1);
                    break;
                }
                case 1: {
                    Cliente[ubicC].setNombre(dato);

                    break;
                }
                case 2: {
                    Cliente[ubicC].setApellido(dato);
                    break;
                }
                case 3: {
                    Cliente[ubicC].setTipo(dato);
                    break;
                }
                case 4: {

                    int number2;
                    number2 = stoi(dato);

                    Cliente[ubicC].setApertura(number2);
                    break;
                }
                case 5: {
                    Cliente[ubicC].setEstado(dato);

                    break;
                }
                case 6: {
                    int number3;
                    number3= stol(dato);
                    Cliente[ubicC].setSaldo(number3);
                }
            }
            cont++;
        }
        s.clear();
        ubicC++;      //en este while me voy elevando a uno en la ubic del cliente
    }
}             //LISTO

void leerArchivoMov() {

    ifstream archivoMovimientos("Movimientos.txt");
    string linea, dato;
    stringstream s;     //linea
    while (getline(archivoMovimientos, linea, '\n')) {

        s.str(linea);

        int cont = 0;

        while (getline(s, dato, ',')) {

            switch (cont) {
                case 0: {
                    int number1;
                    number1 = stoi(dato);
                    Cliente[ubicC].setNumero(number1);
                    break;
                }
                case 1: {

                    int number2;
                    number2 = stoi(dato);
                    Cliente[Cliente[ubicC].getNumero() - 1].Transacciones[nro_T].setNroTran(number2);

                    break;
                }
                case 2: {
                    float number3;
                    number3 = stol(dato);
                    Cliente[Cliente[ubicC].getNumero() - 1].Transacciones[nro_T].setCant(number3);
                    break;
                }
                case 3: {
                    Cliente[Cliente[ubicC].getNumero() - 1].Transacciones[nro_T].setTipo(dato);
                    break;
                }
                case 4: {
                    int number4;
                    number4 = stoi(dato);
                    Cliente[Cliente[ubicC].getNumero() - 1].Transacciones[nro_T].setDia(number4);
                    break;
                }
                case 5: {
                    int number5;
                    number5 = stoi(dato);
                    Cliente[Cliente[ubicC].getNumero() - 1].Transacciones[nro_T].setMes(number5);
                    break;
                }
                case 6: {
                    int number6;
                    number6 = stoi(dato);
                    Cliente[Cliente[ubicC].getNumero() - 1].Transacciones[nro_T].setAnio(number6);
                    break;
                }
            }
            cont++;
        }
        s.clear();
        nro_T++;      //en este while me voy elevando a uno en la ubic del cliente
    }

}                 //LISTO


int main() {
    int opcion = 1;
    bool entradaValida = false;
    ifstream fileloaded;

    leerArchivoCliente();
    leerArchivoMov();
    cout << '\n' << endl;
    cout << "Bienvenido a banco UCC" << endl;
    while (!entradaValida) {

        try {
            cout << '\n' << endl;
            cout << "Menu:" << endl;
            cout << "1. Alta cliente" << endl;               //Listo
            cout << "2. Baja cliente" << endl;               //Listo
            cout << "3. Extraccion de dinero" << endl;       //Listo
            cout << "4. Deposito de dinero" << endl;         //Listo
            cout << "5. Mas opciones" << endl;               //Listo
            cout << "6. Ver base de datos de clientes (txt)" << endl;
            cout << "7. Ver base de datos de transacciones (txt)" << endl;
            cout << "8. Salir" << endl;                      //Listo
            cout << '\n' << endl;
            cin >> opcion;

            if (!cin.good()) {
                throw runtime_error("ERROR: la opcion ingresada no es valida.");      //error generico
            } else {
                entradaValida = true;
            }

        } catch (const exception &error) {
            cout << error.what()
                 << endl;     //error.what() nos escribe la descripcion del error que le dimos anteriormente
        }
        cin.clear(); //limpia la opcion ingresada
        cin.ignore(numeric_limits<streamsize>::max(),
                   '\n'); //ignora todos los caracteres ingresados hasta que encuentra un salto de línea


        switch (opcion) {

            case 1:
                cout << '\n' << endl;
                altaCliente();
                entradaValida = false;
                break;
            case 2:
                cout << '\n' << endl;
                bajaCliente();
                entradaValida = false;
                break;
            case 3:
                cout << '\n' << endl;
                extraccion();
                entradaValida = false;
                break;
            case 4:
                cout << '\n' << endl;
                deposito();
                entradaValida = false;
                break;
            case 5:
                cout << '\n' << endl;
                menuExtra();
                entradaValida = false;
                break;
            case 6:
                cout << '\n' << endl;
                generarClientesTxt();
                entradaValida = false;
                break;
            case 7:
                cout << '\n' << endl;
                generarMovimientosTxt();
                entradaValida = false;
                break;
            case 8:
                break;
        }

    }

}

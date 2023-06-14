#include <iostream>
#include "Transacciones.h"
#include "tarjetas.h"
#ifndef PROYECTOFINAL_CLIENTES_H
#define PROYECTOFINAL_CLIENTES_H
using namespace std;

class Clientes {
protected:
    int numero;
    string nombre;
    string apellido;
    string tipo;
    int apertura;
    string estado;
    long saldo;
public:

    Transacciones Transacciones[50];

    tarjetas tarjetas;

    Clientes();
    Clientes(int, string, string, string, int, string, long);

    void setNumero(int _numero);
    void setNombre(string _nombre);
    void setApellido (string _apellido);
    void setTipo (string _tipo);
    void setApertura (int _apertura);
    void setEstado (string _estado);
    void setSaldo(long _saldo);

    int getNumero();
    string getNombre();
    string getApellido();
    string getTipo();
    int getApertura();
    string getEstado();
    long getSaldo();

    void baja(int);
    void mostrarCliente();
    void limiteTarjetas();

};


#endif //PROYECTOFINAl_CLIENTES_H

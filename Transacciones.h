//
// Created by COTYS on 24/5/2023.
//
#include <iostream>
using namespace std;
#ifndef PROYECTOFINAL_TRANSACCIONES_H
#define PROYECTOFINAL_TRANSACCIONES_H


class Transacciones {
protected:
    int nro_transaccion;
    float cantidad_total; //saldo actual
    float cantidad; //lo que extraemos/depositamos
    string tipo;
    int dia;
    int mes;
    int anio;
public:
    Transacciones();
    Transacciones(int, float, float, string, int, int , int);

    void setNroTran(int _nro_transaccion);
    void setCantTotal(float _cantidad_total);
    void setCant(float _cantidad);
    void setTipo(string _tipo);
    void setDia(int _dia);
    void setMes(int _mes);
    void setAnio(int _anio);

    int getNroTran();
    float getCantTotal();
    float getCant();
    string getTipo();
    int getDia();
    int getMes();
    int getAnio();



    void mostrarTransaccion();

};


#endif //PROYECTOFINAL_TRANSACCIONES_H

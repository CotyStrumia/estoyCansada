//
// Created by COTYS on 24/5/2023.
//

#include "Transacciones.h"


Transacciones::Transacciones() {
    nro_transaccion=0;
    cantidad_total=0;
    cantidad=0;
    tipo=" ";
    dia=0;
    mes=0;
    anio=0;
}

Transacciones::Transacciones(int _nro_transaccion, long _cantidad_total, long _cantidad, string _tipo, int _dia, int _mes, int _anio) {
    nro_transaccion=_nro_transaccion;
    cantidad_total=_cantidad_total;
    cantidad=_cantidad;
    tipo=_tipo;
    dia=_dia;
    mes=_mes;
    anio=_anio;
}

void Transacciones::setNroTran(int _nro_transaccion){
    nro_transaccion=_nro_transaccion;
}

void Transacciones::setCantTotal(long _cantidad_total) {
    cantidad_total=_cantidad_total;
}

void Transacciones::setCant(long _cantidad) {
    cantidad=_cantidad;
}

void Transacciones::setTipo(string _tipo) {
    tipo=_tipo;
}

void Transacciones::setDia(int _dia) {
    dia=_dia;
}

void Transacciones::setMes(int _mes) {
    mes=_mes;
}

void Transacciones::setAnio(int _anio) {
    anio=_anio;
}


int Transacciones::getNroTran() {
    return nro_transaccion;
}

long Transacciones::getCantTotal() {
    return cantidad_total;
}

long Transacciones::getCant() {
    return cantidad;
}

string Transacciones::getTipo() {
    return tipo;
}

int Transacciones::getDia() {
    return dia;
}

int Transacciones::getMes() {
    return mes;
}

int Transacciones::getAnio() {
    return anio;
}

void Transacciones::mostrarTransaccion() {
    cout << "NUMERO DE TRANSACCION: " << getNroTran() << endl;
    cout << "CANTIDAD: " << getCant() << endl;
    cout << "TIPO: " << getTipo() << endl;
    cout << "DIA: " << getDia() << endl;
    cout << "MES: " << getMes() << endl;
    cout << "ANIO: " << getAnio() << endl;
}


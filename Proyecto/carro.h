#pragma once
#include "factura.h"
#include <string>
#include <vector>
using namespace std;
class Carro{
    string placa;
    string marca;
    int cilindraje;
    int maxgas;
    int gasactual;
    vector<Factura*> facturas;
public:
    Carro(string,string,int,int);
    string toString() const;
    string getPlaca() const;
    string getMarca() const;
    int getMaxGas() const;
    int getGasActual() const;
    void setGasActual(int);
    void addFactura(Factura*);
    int promediokml()const;
    int promediokmg()const;
    int promediolempkm()const;
    int promediolempdia()const;
};

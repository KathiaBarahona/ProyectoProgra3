#ifndef CARRO_H
#define CARRO_H
#include"factura.h"
#include<qstring.h>
#include<QList>
using namespace std;
class Carro
{
    QString placa;
    QString marca;
    int cilindraje;
    double gasmax;
    double gasactual;
    int stops;
    QString tipo;
    QList<Factura> facturas;
public:
    Carro();
    Carro(QString ,QString ,int ,int , QString);
    QString getPlaca()const;
    QString getMarca()const;
    QString getTipo()const;
    void setTipo(QString);
    int getCilindraje()const;
    double getGasMax()const;
    double getGasActual()const;
    int getStops()const;
    void setPlaca(QString);
    void setMarca(QString);
    void setCilindraje(int);
    void setGasMax(double);
    void setGasActual(double);
    void setStops(int);
    void addFactura(const Factura&);
    double promediokml()const;
    double promediokmg()const;
    double promediolempkm()const;
    double promediolempdia()const;
    friend ostream& operator<<(ostream&, Carro&);

};

#endif // CARRO_H

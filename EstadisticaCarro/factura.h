#ifndef FACTURA_H
#define FACTURA_H
#include<qstring.h>
#include <iostream>
using std:: ostream;
using std:: istream;
class Factura
{
    QString fecha;
    double lempiras;
    double litros;
    double km;
public:
    Factura(double,double, double);
    Factura(const Factura&);
    QString toString() const;
    int getDia() const;
    double getLempiras()const;
    double getLitro()const;
    double getKm()const;
    friend ostream& operator<<(ostream&, Factura&);

};

#endif // FACTURA_H

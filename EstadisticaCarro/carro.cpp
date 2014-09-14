#include "carro.h"
#include "factura.h"
#include <vector>
#include <qstring.h>
Carro::Carro(){}
Carro::Carro(QString placa, QString marca, int cilindraje, int gasmax):placa(placa),marca(marca),cilindraje(cilindraje),gasmax(gasmax)
{
    gasactual=0;
    stops=0;
}
QString Carro::getPlaca()const{
    return placa;
}
QString Carro::getMarca()const{
    return marca;
}
int Carro::getCilindraje()const{
    return cilindraje;
}
double Carro::getGasMax()const{
    return gasmax;
}
double Carro::getGasActual()const{
    return gasactual;
}
int Carro::getStops()const{
    return stops;
}
void Carro::setGasActual(double gasactual){
     this->gasactual=gasactual;
}
void Carro::setStops(int stops){
    this->stops=stops;
}
void Carro::addFactura(const Factura &f){
    Factura fact(f);
    facturas.append(fact);
}
double Carro::promediokml()const{
    double promedio=0;
    for(int i=1;i<facturas.size();i++){
        promedio+=facturas[i].getKm()/facturas[i].getLitro();
    }
    return promedio/(facturas.size()-1);
}
double Carro::promediokmg()const{
    double promedio=0;
    for(int i=1;i<facturas.size();i++){
        promedio+=facturas[i].getKm()/(facturas[i].getLitro()*3.8);
    }
    return promedio/(facturas.size()-1);
}
double Carro::promediolempkm()const{
    double promedio=0;
    for(int i=1;i<facturas.size();i++){
        promedio+=facturas[i].getLempiras()/facturas[i].getKm();
    }
    return promedio/(facturas.size()-1);
}
double Carro::promediolempdia()const{
    double promedio=0;
    for(int i=1;i<facturas.size();i++){
        promedio+=(facturas[i].getDia()-facturas[i-1].getDia())/facturas[i].getKm();
    }
    return promedio/(facturas.size()-1);
}
ostream& operator <<(ostream& output,Carro& c){
    output<<c.placa.toStdString()<<","<<c.marca.toStdString()<<","<<c.cilindraje<<","<<c.gasmax<<","<<c.gasactual<<","<<c.stops<<"!";
    for(int i=0;i<c.facturas.size();i++)
      output<<c.facturas[i];

    return output;
}



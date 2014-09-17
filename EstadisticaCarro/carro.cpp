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
     if(gasactual>gasmax)
         gasactual=0;
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
    double kmtotales=0;
    double litrostotales=0;
    for(int i=1;i<facturas.size();i++){
        kmtotales+=facturas[i].getKm();
        litrostotales+=facturas[i].getLitro();
    }
    return kmtotales/litrostotales;
}
double Carro::promediokmg()const{
     return promediokml()*3.785412;
}
double Carro::promediolempkm()const{
    double kmtotales=0;
    double lempirastotales=0;
    for(int i=1;i<facturas.size();i++){
        lempirastotales+=facturas[i].getLempiras();
        kmtotales+=facturas[i].getKm();
    }
    return lempirastotales/kmtotales;
}
double Carro::promediolempdia()const{
    double diastotales=0;
    double lempirastotales=0;
    for(int i=1;i<facturas.size();i++){
        diastotales+=facturas[i].getDia()-facturas[i-1].getDia();
        lempirastotales+=facturas[i].getLempiras();
    }
    return lempirastotales/diastotales;
}
ostream& operator <<(ostream& output,Carro& c){
    output<<c.placa.toStdString()<<","<<c.marca.toStdString()<<","<<c.cilindraje<<","<<c.gasmax<<","<<c.gasactual<<","<<c.stops<<";";
    for(int i=0;i<c.facturas.size();i++)
      output<<c.facturas[i];
      output<<endl;
    return output;
}



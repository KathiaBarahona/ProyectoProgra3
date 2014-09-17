#include "carro.h"
#include "factura.h"
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <cstring>
Carro::Carro(string placa,string marca,int cilindraje,int maxgas):placa(placa),marca(marca),cilindraje(cilindraje),maxgas(maxgas)
{
    gasactual=0;
}
string Carro::toString() const{
    return placa;
}
string Carro::getPlaca() const{
    return placa;
}
string Carro::getMarca() const{
    return marca;
}
int Carro::getGasActual() const{
    return gasactual;
}
int Carro::getMaxGas()const{
    return maxgas;
}
void Carro::setGasActual(int gasactual){
    this->gasactual=gasactual;
}
void Carro::addFactura(Factura *f){
    facturas.push_back(f);
}
int Carro::promediokml()const{
    double suma=0;
    for(int i=1;i<(signed)facturas.size();i++){
        suma+=(double)(facturas[i]->getKm())/((double)facturas[i]->getLitros());
    }
    return suma/(double)(facturas.size()-1);
}
int Carro:: promediokmg()const{
    double suma=0;
    for(int i=1;i<(signed)facturas.size();i++){
        suma+=(double)(facturas[i]->getKm())/((double)(facturas[i]->getLitros())/3.8);
    }
    return suma/(double)(facturas.size()-1);
}
int Carro::promediolempkm()const{
    double suma=0;
    for(int i=1;i<(signed)facturas.size();i++){
        suma+=(double)(facturas[i]->getLempiras())/(double)(facturas[i]->getKm());
    }
    return suma/(double)(facturas.size()-1);
}
int Carro::promediolempdia()const{
    double suma=0;
    int dia=0;
    char*cadena=NULL;
    char*cadena2=NULL;
    for(int i=1;i< (signed)facturas.size();i++){
        cadena=new char[(facturas[i]->getFecha()).size()+1];
        strcpy(cadena,(facturas[i]->getFecha()).c_str());
        cadena2=strtok(cadena,"/");
        dia=atoi(cadena2);
        strcpy(cadena,(facturas[i-1]->getFecha()).c_str());
        cadena2=strtok(cadena,"/");
        dia-=atoi(cadena2);
        suma+=(double)(facturas[i]->getLempiras())/(double)dia;
    }
    return suma/(double)(facturas.size()-1);
}

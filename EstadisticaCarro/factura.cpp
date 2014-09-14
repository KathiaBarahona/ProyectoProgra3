#include "factura.h"
#include "carro.h"
#include <qstring.h>
#include <time.h>
#include <sstream>
#include <cstring>
#include <iostream>
using namespace std;
Factura::Factura(double gasmax, double gasactual,double km):km(km)
{
    stringstream ss;
    litros=gasmax-gasactual;
    lempiras= litros * 25.00;
    time_t t = time(0);
    struct tm *ltm = localtime(& t);
    ss<<ltm->tm_mday<<"/"<<(1+ltm->tm_mon)<<"/"<<(1900+ltm->tm_year);
    fecha=(ss.str()).c_str();
}
Factura:: Factura(const Factura &f){
    litros=f.litros;
    lempiras=f.lempiras;
    fecha=f.fecha;
    km=f.km;
}
QString Factura::toString() const{
    stringstream ss;
    ss<<"Fecha: "<<fecha.toStdString()<<"\nLempiras: L."<<lempiras<<"\nLitros: "<<litros;
    if(km!=0)
        ss <<" L\nKilometros: "<<km<<"km";
    return (ss.str()).c_str();
}
int Factura::getDia() const{
    string fecha2= fecha.toStdString();
    char*cadena=new char[fecha2.size()];
    char*cadena2=NULL;
    strcpy(cadena,(fecha2).c_str());
    cadena2=strtok(cadena,"/");
    return atoi(cadena2);
}
double Factura::getLempiras()const{
    return lempiras;
}
double Factura::getLitro()const{
    return litros;
}
double Factura::getKm()const{
    return km;
}
void Factura:: setFecha(QString fecha){
    this->fecha=fecha;
}

void Factura:: setLempiras(double lempiras){
    this->lempiras=lempiras;
}

void Factura:: setKm(double km){
    this->km=km;
}

void Factura:: setLitro(double litros){
    this->litros=litros;
}

ostream& operator <<(ostream& output,Factura& f){

    output<<f.fecha.toStdString()<<","<<f.lempiras<<","<<f.litros<<","<<f.km<<"&";
    return output;


}



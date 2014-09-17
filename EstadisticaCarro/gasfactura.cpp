#include "gasfactura.h"
#include "factura.h"
#include "carro.h"
#include "ui_gasfactura.h"
#include<iostream>
using namespace std;

GasFactura::GasFactura(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GasFactura)
{
    ui->setupUi(this);
}

GasFactura::~GasFactura()
{
    delete ui;
}
void GasFactura::setCarro(Carro* car){
    c=car;
    if(c->getStops()==0){
        ui->lt_gasactual->setVisible(false);
        ui->lt_km->setVisible(false);
    }else{
        ui->lt_gasactual->setVisible(true);
        ui->lt_km->setVisible(true);
    }
    ui->sc_factura->setText("");
    ui->lt_gasactual->setText("");
    ui->lt_km->setText("");

}

void GasFactura::on_pushButton_clicked()
{

    if(c->getStops()!=0){
        c->setGasActual(ui->lt_gasactual->text().toDouble());
        if(ui->lt_km->text()==""){
            Factura f(c->getGasMax(),c->getGasActual(),0,c->getTipo());
            c->addFactura(f);
            ui->sc_factura->setText(f.toString());
        }
        else{
            Factura f(c->getGasMax(),c->getGasActual(),ui->lt_km->text().toDouble(),c->getTipo());
            c->addFactura(f);
            ui->sc_factura->setText(f.toString());
        }
    }else{
        Factura f(c->getGasMax(),0,0,c->getTipo());
        c->setStops(1);
        c->addFactura(f);
        ui->sc_factura->setText(f.toString());
    }

}



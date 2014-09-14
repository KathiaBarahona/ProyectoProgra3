#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_gasfactura.h"
#include "gasfactura.h"
#include "carro.h"
#include "factura.h"
#include <sstream>
#include <QMessageBox>
#include <QList>
#include <iostream>
#include <QCloseEvent>
#include <QFileDialog>
#include <QFile>
#include <ostream>
#include <fstream>

using namespace std;
MainWindow::MainWindow(QWidget *parent) :

    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    ui->treeWidget->setColumnCount(3);
    treeItem = new QTreeWidgetItem(ui->treeWidget);
    treeItem->setText(0,"Placa");
    treeItem->setText(1,"Marca");
    treeItem->setText(2,"Cilindraje");

    QString archivo = QFileDialog::getOpenFileName(this,tr("Open File"),"",tr("Files (*.txt)"));
    if(archivo!=""){
        string temp;
        char* cadena=NULL;
        char* cadena2=NULL;
        char* cadena3=NULL;
        char* cadena4=NULL;
        int vuelta=0;
        int vuelta2=0;
        QString placa;
        QString marca;
        int cilindraje;
        double gasmax;
        double gasactual;
        int stops;
        QString fecha;
        double lempiras;
        double litros;
        double km;
        ifstream entrada(archivo.toStdString().c_str());
        while(!entrada.eof()){
            getline(entrada,temp);
            cadena=new char[temp.size()+1];
            strcpy(cadena,temp.c_str());
            cadena2= strtok(cadena,"!");
            vuelta=0;
            while(cadena2!=NULL){
                vuelta2=0;
                if(vuelta==0){
                    cadena3=strtok(cadena2,",");
                    while(cadena3!=NULL){
                        if(vuelta2==0)
                            placa=cadena3;
                        if(vuelta2==1)
                            marca=cadena3;
                        if(vuelta2==2){
                            QString c;
                            c=cadena3;
                            cilindraje=c.toInt();
                        }
                        if(vuelta2==3){
                            QString g;
                            g=cadena3;
                            gasmax=g.toDouble();
                        }
                        if(vuelta2==4){
                            QString g;
                            g=cadena3;
                            gasactual=g.toDouble();
                        }
                        if(vuelta2==5){
                            QString s;
                            s=cadena3;
                            stops=s.toInt();
                        }
                        vuelta2++;
                        cadena3= strtok(NULL,",");

                    }
                    carros.push_back(new Carro(placa,marca,cilindraje,gasmax));
                    carros[carros.size()-1]->setGasActual(gasactual);
                    carros[carros.size()-1]->setStops(stops);

                }else{
                    cadena3=strtok(cadena2,"&");
                    while(cadena3!=NULL){
                        cadena4=strtok(cadena3,",");
                        while(cadena4!=NULL){
                            if(vuelta2==0)
                                fecha=cadena3;
                            if(vuelta2==1){
                                QString l;
                                l=cadena3;
                                lempiras=l.toInt();
                            }
                            if(vuelta2==2){
                                QString l;
                                l=cadena3;
                                litros=l.toDouble();
                            }
                            if(vuelta2==3){
                                QString k;
                                k=cadena3;
                                km=k.toDouble();
                            }
                            cadena4= strtok(NULL,",");
                        }
                        vuelta2++;
                        cadena3= strtok(NULL,"&");
                    }
                    Factura f(0,0,0);
                    f.setFecha(fecha);
                    f.setKm(km);
                    f.setLempiras(lempiras);
                    f.setLitro(litros);
                    carros[carros.size()-1]->addFactura(f);
                }
                vuelta++;
                cadena2= strtok(NULL,"!");
            }

        }


        entrada.close();
        cout<<carros.size()<<endl;
        for(int i=0;i<carros.size();i++){
            QTreeWidgetItem *treeItem2=new QTreeWidgetItem();
            treeItem2->setText(0,carros[i]->getPlaca());
            treeItem2->setText(1,carros[i]->getMarca());
            treeItem2->setText(2,QString::number(carros[i]->getCilindraje()));
            treeItem->addChild(treeItem2);
            ui->listWidget->addItem(new QListWidgetItem(carros[i]->getPlaca()));
        }
    }



}
void MainWindow:: closeEvent(QCloseEvent *event){
    QMessageBox mb;
    mb.setText("Desea guardar?");

    mb.setStandardButtons(QMessageBox::No | QMessageBox::Yes);
    mb.setDefaultButton(QMessageBox::Yes);
    int result = mb.exec();
    if(result==QMessageBox::Yes){
        QString archivo = QFileDialog::getSaveFileName(this,tr("Save File"),"",tr("Files (*.txt)"));
        if(archivo!=""){
            ofstream salida;
            salida.open(archivo.toStdString().c_str(),ios::binary|ios::app);
            for(int i=0;i<carros.size();i++){
                salida<<*carros[i];
            }

            salida.close();}


    }
    event->accept();




}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Carro *c=new Carro(ui->lt_placa->text(),ui->lt_marca->text(),(ui->lt_cilindraje->text()).toInt(),(ui->lt_gasmax->text()).toInt());
    ui->lt_placa->setText("");
    ui->lt_marca->setText("");
    ui->lt_cilindraje->setText("");
    ui->lt_gasmax->setText("");
    carros.append(c);
    QTreeWidgetItem *treeItem2=new QTreeWidgetItem();
    treeItem2->setText(0,c->getPlaca());
    treeItem2->setText(1,c->getMarca());
    treeItem2->setText(2,QString::number(c->getCilindraje()));
    treeItem->addChild(treeItem2);
    ui->listWidget->addItem(new QListWidgetItem(c->getPlaca()));



}




void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item)
{

    int indice;
    bool bandera=false;

    for(int i=0;i<carros.size();i++){
        if(item->text(0)==carros[i]->getPlaca() && item->text(1)==carros[i]->getMarca()&&item->text(2).toInt()==carros[i]->getCilindraje()){
            indice=i;
            bandera=true;
            break;
        }
    }
    if(bandera){
        GasFactura gasfactura ;
        gasfactura.setCarro(carros[indice]);
        gasfactura.setModal(true);
        gasfactura.exec();
    }

}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    int indice;
    bool bandera=false;
    for(int i=0;i<carros.size();i++){
        if(item->text()==carros[i]->getPlaca()){
            indice=i;
            bandera=true;
            break;
        }
    }
    if(bandera){
        stringstream ss;
        ss<<"Promedio km/L: "<<carros[indice]->promediokml()<<"\nPromedio km/G: "<<carros[indice]->promediokmg()
         <<"\nPromedio Lemp/km: "<<carros[indice]->promediolempkm()<<"\nPromedio Lemp/dia: "<<carros[indice]->promediolempdia();
        ui->tf_promedios->setText(ss.str().c_str());
    }
}

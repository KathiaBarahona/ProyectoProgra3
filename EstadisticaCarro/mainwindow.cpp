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
    string temp;
    Factura f(0,0,0);
    char * cadena=NULL;
    char * cadena2=NULL;
    char * cadena3=NULL;
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
    vector<char *> cf;
    ui->treeWidget->setColumnCount(3);
    treeItem = new QTreeWidgetItem(ui->treeWidget);
    treeItem->setText(0,"Placa");
    treeItem->setText(1,"Marca");
    treeItem->setText(2,"Cilindraje");

    QString archivo = QFileDialog::getOpenFileName(this,tr("Open File"),"",tr("Files (*.txt)"));
    if(archivo!=""){

        ifstream entrada(archivo.toStdString().c_str());
        while(!entrada.eof()){
            getline(entrada,temp);
            cadena=new char[temp.size()+1];
            strcpy(cadena,temp.c_str());
            cadena2 = strtok(cadena,";");
            while(cadena2!=NULL){
                cf.push_back(cadena2);
                cadena2 = strtok(NULL,";");

            }
            for(int i=0;i<(signed)cf.size();i++){
                cadena3= new char[temp.size()+1];
                cadena3= strtok(cf[i],",");
                vuelta2=0;
                while(cadena3 != NULL){
                    if(i==0){
                        if(vuelta2==0){
                            placa=QString::fromStdString(cadena3);
                        }
                        if(vuelta2==1){
                            marca=QString::fromStdString(cadena3);
                        }
                        if(vuelta2==2){
                            cilindraje=QString::fromStdString(cadena3).toInt();
                        }
                        if(vuelta2==3){
                            gasmax=QString::fromStdString(cadena3).toDouble();
                        }
                        if(vuelta2==4){
                            gasactual=QString::fromStdString(cadena3).toDouble();
                        }
                        if(vuelta2==5){
                            stops=QString::fromStdString(cadena3).toInt();
                            carros.push_back(new Carro(placa,marca,cilindraje,gasmax));
                            carros[carros.size()-1]->setGasActual(gasactual);
                            carros[carros.size()-1]->setStops(stops);
                        }

                    }else{

                        if(vuelta2==0){
                            fecha=QString::fromStdString(cadena3);
                            f.setFecha(fecha);
                        }
                        if(vuelta2==1){
                            lempiras=QString::fromStdString(cadena3).toDouble();
                            f.setLempiras(lempiras);
                        }
                        if(vuelta2==2){
                            litros=QString::fromStdString(cadena3).toDouble();
                            f.setLitro(litros);
                        }
                        if(vuelta2==3){
                            km=QString::fromStdString(cadena3).toDouble();
                            f.setKm(km);
                            carros[carros.size()-1]->addFactura(f);
                        }

                    }
                    vuelta2++;
                    cadena3= strtok(NULL,",");
                }
            }
            cf.clear();
        }
        entrada.close();
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
            salida.open(archivo.toStdString().c_str(),ios::out|ios::trunc);
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

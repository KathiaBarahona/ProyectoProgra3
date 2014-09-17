#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "carro.h"
#include "factura.h"
#include <vector>
#include <iostream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    ui->treeWidget->setColumnCount(2);
    addTreeRoot("Placa","Marca");
}
vector<Carro*> carros;
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::addTreeRoot(QString name, QString description){
    QTreeWidgetItem *treeItem = new QTreeWidgetItem(ui->treeWidget);
    treeItem->setText(0, name);
        treeItem->setText(1, description);
        addTreeChild(treeItem, name , "Child_first");
        addTreeChild(treeItem, name , "Child_second");
}
void MainWindow::addTreeChild(QTreeWidgetItem *parent,
                  QString name, QString description)
{
    QTreeWidgetItem *treeItem = new QTreeWidgetItem();
    treeItem->setText(0, name);
    treeItem->setText(1, description);
    parent->addChild(treeItem);
}

void MainWindow::on_pushButton_clicked()
{
    string placa=(ui->tl_placa->text()).toStdString();
    string marca=(ui->tl_marca->text()).toStdString();
    string d=((ui->tl_cilindraje->text()).toStdString());
    char*cadena=new char[d.size()+1];
    strcpy(cadena,((ui->tl_cilindraje->text()).toStdString()).c_str());
    int cilindraje=atoi(cadena);
    d=((ui->tl_capacidad->text()).toStdString());
    cadena=new char[d.size()+1];
    strcpy(cadena,((ui->tl_capacidad->text()).toStdString()).c_str());
    int maxgas=atoi(cadena);
    Carro* c=new Carro(placa,marca,cilindraje,maxgas);
    ui->tl_placa->setText("");
    ui->tl_marca->setText("");
    ui->tl_cilindraje->setText("");
    ui->tl_capacidad->setText("");
    carros.push_back(c);
     QTreeWidgetItem *treeItem = new QTreeWidgetItem(ui->treeWidget);
     addTreeChild(treeItem, QString::to->getPlaca()),(QString)(c->getMarca()));


}

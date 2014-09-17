#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTreeWidget>
#include <QListWidget>
#include <QBrush>
#include <QMainWindow>
#include "carro.h"
#include "factura.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    QTreeWidgetItem *treeItem ;
    QList <Carro*> carros;
    int posicion;
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private slots:
    void closeEvent(QCloseEvent * event);
     void itemstree();
    void on_pushButton_clicked();

    void on_treeWidget_itemClicked(QTreeWidgetItem *item);

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_Eliminar_tabBarClicked(int index);

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

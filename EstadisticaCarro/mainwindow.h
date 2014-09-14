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
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void closeEvent(QCloseEvent * event);

    void on_pushButton_clicked();

    void on_treeWidget_itemClicked(QTreeWidgetItem *item);

    void on_listWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

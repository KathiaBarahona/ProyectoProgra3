#ifndef GASFACTURA_H
#define GASFACTURA_H
#include "carro.h"
#include "factura.h"
#include <QDialog>

namespace Ui {
class GasFactura;
}

class GasFactura : public QDialog
{
    Q_OBJECT
    Carro* c;

public:
    explicit GasFactura(QWidget *parent = 0);
    ~GasFactura();
    void setCarro(Carro*);


private slots:
    void on_pushButton_clicked();


private:
    Ui::GasFactura *ui;
};

#endif // GASFACTURA_H

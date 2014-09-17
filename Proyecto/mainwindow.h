#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTreeWidget>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    void addTreeRoot(QString name, QString description);
    void addTreeChild(QTreeWidgetItem *parent, QString name, QString description);
};

#endif // MAINWINDOW_H

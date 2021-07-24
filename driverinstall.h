#ifndef DRIVERINSTALL_H
#define DRIVERINSTALL_H

#include <QMainWindow>
#include<QtSql/QSqlQueryModel>

namespace Ui {
class driverinstall;
}

class driverinstall : public QMainWindow
{
    Q_OBJECT

public:
    explicit driverinstall(QWidget *parent = nullptr);
    ~driverinstall();

private slots:
    void on_main_triggered();

    void on_nazad_triggered();



private:
    Ui::driverinstall *ui;
     QSqlQueryModel* drinstmodel;
};

#endif // DRIVERINSTALL_H

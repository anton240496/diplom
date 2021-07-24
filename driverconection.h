#ifndef DRIVERCONECTION_H
#define DRIVERCONECTION_H

#include <QMainWindow>
#include<QtSql/QSqlQueryModel>

namespace Ui {
class driverconection;
}

class driverconection : public QMainWindow
{
    Q_OBJECT

public:
    explicit driverconection(QWidget *parent = nullptr);
    ~driverconection();

private slots:
    void on_main_triggered();

    void on_nazad_triggered();


    void on_deflr_clicked();

private:
    Ui::driverconection *ui;
     QSqlQueryModel* drconmodel;
};

#endif // DRIVERCONECTION_H

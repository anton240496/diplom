#ifndef MSTART_H
#define MSTART_H

#include <QMainWindow>
#include<QtSql/QSqlQueryModel>

namespace Ui {
class mstart;
}

class mstart : public QMainWindow
{
    Q_OBJECT

public:
    explicit mstart(QWidget *parent = nullptr);
    ~mstart();

private slots:




    void on_regimcp_clicked();

    void on_nazat_triggered();

    void on_komputernetwork_clicked();





private:
    Ui::mstart *ui;
     QSqlQueryModel* smodel;
};

#endif // MSTART_H

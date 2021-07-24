#ifndef COMPNETWORK_H
#define COMPNETWORK_H

#include <QMainWindow>
#include <QtSql/QSqlQueryModel>

namespace Ui {
class compnetwork;
}

class compnetwork : public QMainWindow
{
    Q_OBJECT

public:
    explicit compnetwork(QWidget *parent = nullptr);
    ~compnetwork();

private slots:




    void on_deflr_clicked();

    void on_main_triggered();

    void on_faks_clicked();

private:
    Ui::compnetwork *ui;
    QSqlQueryModel* knmodel;
};

#endif // COMPNETWORK_H

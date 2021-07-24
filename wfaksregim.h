#ifndef WFAKSREGIM_H
#define WFAKSREGIM_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>

namespace Ui {
class wfaksregim;
}

class wfaksregim : public QMainWindow
{
    Q_OBJECT

public:
    explicit wfaksregim(QWidget *parent = nullptr);
    ~wfaksregim();

private slots:




    void on_deflr_clicked();

    void on_tras_clicked();

    void on_main_triggered();

private:
    Ui::wfaksregim *ui;

    QSqlDatabase db;
    QSqlQueryModel* model;
};

#endif // WFAKSREGIM_H

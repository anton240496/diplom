#ifndef TRASIROVKA_H
#define TRASIROVKA_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>

namespace Ui {
class trasirovka;
}

class trasirovka : public QMainWindow
{
    Q_OBJECT

public:
    explicit trasirovka(QWidget *parent = nullptr);
    ~trasirovka();

private slots:




    void on_deflr_clicked();

    void on_main_triggered();

    void on_nazad_triggered();

private:
    Ui::trasirovka *ui;

    QSqlDatabase db;
    QSqlQueryModel* model;
};

#endif // TRASIROVKA_H

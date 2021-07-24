#ifndef FAKSDEVISE_H
#define FAKSDEVISE_H

#include <QMainWindow>
#include<QtSql/QSqlQueryModel>

namespace Ui {
class faksdevise;
}

class faksdevise : public QMainWindow
{
    Q_OBJECT

public:
    explicit faksdevise(QWidget *parent = nullptr);
    ~faksdevise();

private slots:


    void on_faskd_clicked(const QModelIndex &index);

    void on_main_triggered();

    void on_rolik_clicked();

    void on_tormoz_clicked();

private:
    Ui::faksdevise *ui;
    QSqlQueryModel* fdmodel;
};

#endif // FAKSDEVISE_H

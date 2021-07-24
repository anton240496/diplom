#ifndef PRINTS_H
#define PRINTS_H

#include <QMainWindow>
#include<QtSql/QSqlQueryModel>

namespace Ui {
class prints;
}

class prints : public QMainWindow
{
    Q_OBJECT

public:
    explicit prints(QWidget *parent = nullptr);
    ~prints();

private slots:
    void on_main_triggered();

    void on_nazad_triggered();



    void on_prints_2_clicked(const QModelIndex &index);

    void on_katrig_clicked();

private:
    Ui::prints *ui;
    QSqlQueryModel* printsmodel;
};

#endif // PRINTS_H

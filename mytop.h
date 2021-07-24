#ifndef MYTOP_H
#define MYTOP_H

#include <QMainWindow>
#include<QtSql/QSqlQueryModel>

namespace Ui {
class mytop;
}

class mytop : public QMainWindow
{
    Q_OBJECT

public:
    explicit mytop(QWidget *parent = nullptr);
    ~mytop();

private slots:


    void on_main_triggered();

    void on_mytop_2_triggered();



    void on_tmytop_clicked(const QModelIndex &index);

    void on_katrig_clicked();

    void on_pushButton_clicked();

private:
    Ui::mytop *ui;
    QSqlQueryModel* mytmodel;
};

#endif // MYTOP_H

#ifndef PYTNA_H
#define PYTNA_H

#include <QMainWindow>
#include<QtSql/QSqlQueryModel>


namespace Ui {
class pytna;
}

class pytna : public QMainWindow
{
    Q_OBJECT

public:
    explicit pytna(QWidget *parent = nullptr);
    ~pytna();

private slots:
    void on_main_triggered();

    void on_nazad_triggered();


    void on_pytna_2_clicked(const QModelIndex &index);

    void on_paper_clicked();

    void on_fuser_clicked();

    void on_katrig_clicked();

private:
    Ui::pytna *ui;
     QSqlQueryModel* pytmodel;
};

#endif // PYTNA_H

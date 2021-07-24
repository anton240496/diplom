#ifndef MQUALITU_H
#define MQUALITU_H

#include <QMainWindow>
#include"mainwindow.h"
#include<QtSql/QSqlQueryModel>

namespace Ui {
class mqualitu;
}

class mqualitu : public QMainWindow
{
    Q_OBJECT

public:
    explicit mqualitu(QWidget *parent = nullptr);
    ~mqualitu();

 //  MainWindow*  mwin;

private slots:




    void on_qualitypictures_clicked(const QModelIndex &index);

    void on_main_triggered();



    void on_densityimage_clicked();

    void on_mytop_clicked();

    void on_edgeimage_clicked();

    void on_fon_clicked();

    void on_empty_clicked();

    void on_skew_clicked();



    void on_stripdir_clicked();


    void on_notpinnecopi_clicked();

    void on_gorizontline_clicked();

    void on_ribe_clicked();

    void on_pytna_clicked();

    void on_prints_clicked();




    void on_emptyimage_clicked();

signals:
    void avtor();

private:
    Ui::mqualitu *ui;
    QSqlQueryModel* qpmodel;
};

#endif // MQUALITU_H

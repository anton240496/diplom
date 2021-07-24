#ifndef EMPTYIMAGE_H
#define EMPTYIMAGE_H

#include <QMainWindow>
#include<QtSql/QSqlQueryModel>

namespace Ui {
class emptyimage;
}

class emptyimage : public QMainWindow
{
    Q_OBJECT

public:
    explicit emptyimage(QWidget *parent = nullptr);
    ~emptyimage();

private slots:
    void on_main_triggered();

    void on_nazad_triggered();



    void on_emptyim_clicked(const QModelIndex &index);

    void on_katrig_clicked();

private:
    Ui::emptyimage *ui;
     QSqlQueryModel* emimmodel;
};

#endif // EMPTYIMAGE_H

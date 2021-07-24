#ifndef EMPTY_H
#define EMPTY_H

#include <QMainWindow>
#include<QtSql/QSqlQueryModel>

namespace Ui {
class empty;
}

class empty : public QMainWindow
{
    Q_OBJECT

public:
    explicit empty(QWidget *parent = nullptr);
    ~empty();

private slots:
    void on_main_triggered();

    void on_nazad_triggered();



    void on_empty_2_clicked(const QModelIndex &index);

    void on_paper_clicked();

    void on_katrig_clicked();

private:
    Ui::empty *ui;
         QSqlQueryModel* emmodel;
};

#endif // EMPTY_H

#ifndef TERM_H
#define TERM_H

#include <QMainWindow>
#include<QtSql/QSqlQueryModel>

namespace Ui {
class term;
}

class term : public QMainWindow
{
    Q_OBJECT

public:
    explicit term(QWidget *parent = nullptr);
    ~term();

private slots:


    void on_main_triggered();

    void on_nazad_triggered();



    void on_term_2_clicked(const QModelIndex &index);

private:
    Ui::term *ui;
     QSqlQueryModel* termmodel;
};

#endif // TERM_H

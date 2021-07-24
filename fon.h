#ifndef FON_H
#define FON_H

#include <QMainWindow>
#include<QtSql/QSqlQueryModel>

namespace Ui {
class fon;
}

class fon : public QMainWindow
{
    Q_OBJECT

public:
    explicit fon(QWidget *parent = nullptr);
    ~fon();

private slots:
    void on_main_triggered();

    void on_nazad_triggered();



    void on_fon_2_clicked(const QModelIndex &index);

    void on_katrig_clicked();

private:
    Ui::fon *ui;
     QSqlQueryModel* fonmodel;
};

#endif // FON_H

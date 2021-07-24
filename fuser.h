#ifndef FUSER_H
#define FUSER_H

#include <QMainWindow>
#include<QtSql/QSqlQueryModel>

namespace Ui {
class fuser;
}

class fuser : public QMainWindow
{
    Q_OBJECT

public:
    explicit fuser(QWidget *parent = nullptr);
    ~fuser();

private slots:


    void on_main_triggered();



    void on_fuser_2_clicked(const QModelIndex &index);

    void on_term_clicked();

    void on_silval_clicked();

private:
    Ui::fuser *ui;
    QSqlQueryModel* fusmodel;
};

#endif // FUSER_H

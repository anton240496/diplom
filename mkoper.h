#ifndef MKOPER_H
#define MKOPER_H

#include <QMainWindow>
#include <QtSql/QSqlQueryModel>

namespace Ui {
class mkoper;
}

class mkoper : public QMainWindow
{
    Q_OBJECT

public:
    explicit mkoper(QWidget *parent = nullptr);
    ~mkoper();

private slots:






    void on_faks_clicked();

    void on_deflr_clicked();

    void on_mainwin_triggered();

private:
    Ui::mkoper *ui;
    QSqlQueryModel* kpmodel;
};

#endif // MKOPER_H

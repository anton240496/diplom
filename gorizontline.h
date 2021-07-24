#ifndef GORIZONTLINE_H
#define GORIZONTLINE_H

#include <QMainWindow>
#include<QtSql/QSqlQueryModel>

namespace Ui {
class gorizontline;
}

class gorizontline : public QMainWindow
{
    Q_OBJECT

public:
    explicit gorizontline(QWidget *parent = nullptr);
    ~gorizontline();

private slots:
    void on_main_triggered();

    void on_nazad_triggered();





    void on_gorlin_clicked(const QModelIndex &index);

    void on_paper_clicked();

    void on_pushButton_clicked();

private:
    Ui::gorizontline *ui;
      QSqlQueryModel* gorlmodel;
};

#endif // GORIZONTLINE_H

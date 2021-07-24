#ifndef SKEW_H
#define SKEW_H

#include <QMainWindow>
#include<QtSql/QSqlQueryModel>

namespace Ui {
class skew;
}

class skew : public QMainWindow
{
    Q_OBJECT

public:
    explicit skew(QWidget *parent = nullptr);
    ~skew();

private slots:
    void on_main_triggered();

    void on_nazad_triggered();



    void on_skew_2_clicked(const QModelIndex &index);

    void on_kaset_clicked();

    void on_katrig_clicked();

private:
    Ui::skew *ui;
    QSqlQueryModel* skewmodel;
};

#endif // SKEW_H

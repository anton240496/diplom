#ifndef STRIPSDIRECTION_H
#define STRIPSDIRECTION_H

#include <QMainWindow>
#include<QtSql/QSqlQueryModel>

namespace Ui {
class stripsdirection;
}

class stripsdirection : public QMainWindow
{
    Q_OBJECT

public:
    explicit stripsdirection(QWidget *parent = nullptr);
    ~stripsdirection();

private slots:
    void on_main_triggered();

    void on_nazad_triggered();



    void on_strdir_clicked(const QModelIndex &index);

    void on_fuser_clicked();

    void on_katrig_clicked();

private:
    Ui::stripsdirection *ui;
      QSqlQueryModel* strdirmodel;
};

#endif // STRIPSDIRECTION_H

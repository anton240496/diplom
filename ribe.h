#ifndef RIBE_H
#define RIBE_H

#include <QMainWindow>
#include<QtSql/QSqlQueryModel>
namespace Ui {
class ribe;
}

class ribe : public QMainWindow
{
    Q_OBJECT

public:
    explicit ribe(QWidget *parent = nullptr);
    ~ribe();

private slots:
    void on_main_triggered();

    void on_nazad_triggered();



    void on_ribe_2_clicked(const QModelIndex &index);

    void on_paper_clicked();

    void on_katrig_clicked();

private:
    Ui::ribe *ui;
     QSqlQueryModel* ribemodel;
};

#endif // RIBE_H

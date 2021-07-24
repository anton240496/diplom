#ifndef EDGEIMAGE_H
#define EDGEIMAGE_H

#include <QMainWindow>
#include<QtSql/QSqlQueryModel>
namespace Ui {
class edgeimage;
}

class edgeimage : public QMainWindow
{
    Q_OBJECT

public:
    explicit edgeimage(QWidget *parent = nullptr);
    ~edgeimage();

private slots:
    void on_main_triggered();

    void on_nazad_triggered();



    void on_edge_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_katrig_clicked();

private:
    Ui::edgeimage *ui;
    QSqlQueryModel* edgemodel;
};

#endif // EDGEIMAGE_H

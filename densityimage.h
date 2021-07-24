#ifndef DENSITYIMAGE_H
#define DENSITYIMAGE_H

#include <QMainWindow>
#include<QtSql/QSqlQueryModel>

namespace Ui {
class densityimage;
}

class densityimage : public QMainWindow
{
    Q_OBJECT

public:
    explicit densityimage(QWidget *parent = nullptr);
    ~densityimage();

private slots:


    void on_main_triggered();

    void on_nazad_triggered();



    void on_density_clicked(const QModelIndex &index);

    void on_katrig_clicked();

private:
    Ui::densityimage *ui;
     QSqlQueryModel* denimmodel;
};

#endif // DENSITYIMAGE_H

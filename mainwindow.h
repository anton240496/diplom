#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include"QtSql/QSqlDatabase"// пакет для свпедение о базе данных

#include<QtSql/QSqlTableModel> // пакет для свпедениях о таблицах

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:// слоты для взаимодействия с виджетами
    void on_avtor_clicked();



    void on_checkBox_clicked();




private:
    Ui::MainWindow *ui;// виджеты qt


    QSqlDatabase db; // переменная для прописыания входа в базу данных
};
#endif // MAINWINDOW_H

#ifndef MFYPOZITRONIK_H
#define MFYPOZITRONIK_H

#include <QMainWindow>
#include<QtSql/QSqlQueryModel>
#include<QFileDialog>


namespace Ui {
class mfypozitronik;
}



class mfypozitronik : public QMainWindow
{
    Q_OBJECT

public:
    explicit mfypozitronik(QWidget *parent = nullptr);
    ~mfypozitronik();


  public :QString str, oldproblem, oldopican, oldinstruction;

private slots:



    void on_mfypoz_clicked(const QModelIndex &index);

    void on_main_triggered();

    void on_tormoz_clicked();

    void on_rolik_clicked();

    void on_telval_clicked();

   void create();
   // void select();


    void on_add_clicked();

    void on_image_clicked();


    void on_insert_clicked();

    void on_delete_2_clicked();

    void on_pushButton_clicked();



private:
    Ui::mfypozitronik *ui;
     QSqlQueryModel* mfymodel;
};

#endif // MFYPOZITRONIK_H

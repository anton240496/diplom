#include "mstart.h"
#include "ui_mstart.h"
#include "mkoper.h"
#include <QtSql/QSqlQuery>
#include <QDebug>
#include<QSqlError>
#include"mainwindow.h"
#include"mainmenu.h"
#include"compnetwork.h"
mstart::mstart(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mstart)
{
    ui->setupUi(this);

         QSqlQuery query = QSqlQuery ();

        query.exec( "CREATE TABLE IF NOT EXISTS start ( id int primary key, решение varchar , ответ varchar)" );

        query.prepare("insert into start (id, решение, ответ) values"
                      "(1,'Дисплей некоретно работает','Перезагрузите устройство если проблема осталась обратитесь к специалисту, проблема более сложная'),"
                              "(2,'Проблема связана с копированием изображения или его печати','Нажмите на кнопку настройки при копирование и печати изображения'),"
                              "(3,'Иначе проблема с сетью', ' Нажмите на кнопку настройки сетевого подключения')"

                              "ON CONFLICT (id) DO NOTHING");

        if( !query.exec() )
            qDebug() << "Error inserting image into table:\n" << query.lastError();


        smodel = new QSqlQueryModel();
        smodel ->setQuery("SELECT решение, ответ FROM public.start");
        smodel->setHeaderData(0,Qt::Horizontal,"возможные Проблемы");
           smodel->setHeaderData(1,Qt::Horizontal,"решения");


        ui->tabstart->setModel(smodel);
        ui->tabstart->horizontalHeader()->setDefaultSectionSize(220);
           ui->tabstart->verticalHeader()->setDefaultSectionSize(100);
        ui->tabstart->show();
}

mstart::~mstart()
{
    delete ui;
}





void mstart::on_regimcp_clicked()
{
      hide();
    mkoper* window = new mkoper();
    window->show();

}

void mstart::on_nazat_triggered()
{
    hide();
    mainmenu* window = new mainmenu();
    window->show();
}

void mstart::on_komputernetwork_clicked()
{
    hide();
    compnetwork* window = new compnetwork();
    window->show();
}








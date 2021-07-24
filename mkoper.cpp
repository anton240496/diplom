#include "mkoper.h"
#include "ui_mkoper.h"
#include <QtSql/QSqlQuery>
#include<QDebug>
#include "mqualitu.h"
#include "wfaksregim.h"
#include <QSqlError>
#include"mainwindow.h"
#include "mainmenu.h"

mkoper::mkoper(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mkoper)
{
    ui->setupUi(this);

    QSqlQuery query = QSqlQuery ();

   query.exec( "CREATE TABLE IF NOT EXISTS kopper ( id int primary key, решение varchar , ответ varchar)" );

   query.prepare("insert into kopper (id, решение, ответ) values"
                 "(1,'Проблема не в изобажении на бумаге','Для начало посмотрите чистое ли стекло экспонирование, протрите его'),"
                         "(2,'На бумаге после пеати не качественное изображение','Нажмите на кнопку некачественное изображение при дефекте лазерной печати'),"
                         "(3,'Нету нужного решения', 'Нажмите на кнопку настройки факсимильного режима')"
                         "ON CONFLICT (id) DO NOTHING");

   if( !query.exec() )
       qDebug() << "Error inserting image into table:\n" << query.lastError();

    kpmodel = new QSqlQueryModel();
    kpmodel ->setQuery("SELECT решение, ответ FROM public.kopper");
    kpmodel->setHeaderData(0,Qt::Horizontal,"возможные Проблемы");
       kpmodel->setHeaderData(1,Qt::Horizontal,"решения");




    ui->koper->setModel(kpmodel);
    ui->koper->horizontalHeader()->setDefaultSectionSize(220);
       ui->koper->verticalHeader()->setDefaultSectionSize(100);
    ui->koper->show();
}

mkoper::~mkoper()
{
    delete ui;
}




void mkoper::on_faks_clicked()
{
   hide();
    wfaksregim* window = new wfaksregim();
      window->show();
}

void mkoper::on_deflr_clicked()
{
   hide();
    mqualitu* window = new mqualitu();
    window->show();
}

void mkoper::on_mainwin_triggered()
{
    hide();
    mainmenu* window = new mainmenu();
    window->show();
}

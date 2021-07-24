#include "wfaksregim.h"
#include "ui_wfaksregim.h"
#include<QtSql/QSqlRelationalDelegate>
#include<QtSql/QSqlQuery>
#include<QDebug>
#include<QtSql/QSqlError>
#include"mqualitu.h"
#include"trasirovka.h"
#include"mainwindow.h"
#include"mainmenu.h"

wfaksregim::wfaksregim(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::wfaksregim)
{
    ui->setupUi(this);

    QSqlQuery query = QSqlQuery (db);
     query.exec( "CREATE TABLE IF NOT EXISTS faksregim ( id int primary key, решение varchar not null, ответ varchar not null)" );
     query.prepare("insert into faksregim (id, решение, ответ) values "
                   "(1,'Проблема в некоторых режимах','Проверьте настройки устройства, попробуйте протестировать устройство в этом режиме'), "
                   "(2,'Проблема осталась','Нажнмите на кнопку дефект лазерной печати'),"
                   "(3,'Проблема в связи с удаленным аппаратором', 'Проверьте связь вашего и удаленного устройства'),"
                   "(4, 'Решение не найдено','Сделайте трасировку и перейдите в дефект лазерной печати')"
                   "ON CONFLICT (id) DO NOTHING");
     if( !query.exec() )
         qDebug() << "Error inserting image into table:\n" << query.lastError();



     model = new QSqlQueryModel();
     model ->setQuery("SELECT решение,ответ FROM public.faksregim");
     model->setHeaderData(0,Qt::Horizontal,"Описание Проблемы");
        model->setHeaderData(1,Qt::Horizontal,"решение");




     ui->faksregim->setModel(model);
     ui->faksregim->horizontalHeader()->setDefaultSectionSize(220);
        ui->faksregim->verticalHeader()->setDefaultSectionSize(100);
     ui->faksregim->show();
}

wfaksregim::~wfaksregim()
{
    delete ui;
}





void wfaksregim::on_deflr_clicked()
{
    hide();
    mqualitu* window = new mqualitu();
    window->show();
}

void wfaksregim::on_tras_clicked()
{
     hide();
    trasirovka* window = new trasirovka();
    window->show();
}

void wfaksregim::on_main_triggered()
{
    hide();
    mainmenu* window = new mainmenu();
    window->show();
}

#include "trasirovka.h"
#include "ui_trasirovka.h"
#include<QtSql/QSqlRelationalDelegate>
#include<QtSql/QSqlQuery>
#include<QDebug>
#include<QtSql/QSqlError>
#include"mqualitu.h"
#include"mainwindow.h"
#include"mainmenu.h"
#include"wfaksregim.h"

trasirovka::trasirovka(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::trasirovka)
{
    ui->setupUi(this);

    QSqlQuery query = QSqlQuery (db);
     query.exec( "CREATE TABLE IF NOT EXISTS trasirovka ( id int primary key, фирма varchar not null, инструкция varchar not null)" );
     query.prepare("insert into trasirovka (id, фирма, инструкция) values (1,'HP','Меню->Сервис->Печать'), "
                   "(2,' Xerox','Диагностика->Трассировка->Отправить'),"
                   "(3,'Сanon','Настройки->Трассировка->Печать')"
                   "ON CONFLICT (id) DO NOTHING");
     if( !query.exec() )
         qDebug() << "Error inserting image into table:\n" << query.lastError();


     model = new QSqlQueryModel();
     model ->setQuery("SELECT фирма, инструкция FROM public.trasirovka");




     ui->trasirovka_2->setModel(model);
     ui->trasirovka_2->horizontalHeader()->setDefaultSectionSize(300);
        ui->trasirovka_2->verticalHeader()->setDefaultSectionSize(50);
     ui->trasirovka_2->show();
}

trasirovka::~trasirovka()
{
    delete ui;
}




void trasirovka::on_deflr_clicked()
{
   hide();
    mqualitu* window = new mqualitu();
    window->show();
}

void trasirovka::on_main_triggered()
{
    hide();
    mainmenu* window = new mainmenu();
    window->show();
}

void trasirovka::on_nazad_triggered()
{
    hide();
    wfaksregim* window = new wfaksregim();
    window->show();
}

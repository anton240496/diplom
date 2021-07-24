#include "mytop.h"
#include "ui_mytop.h"
#include "mainwindow.h"
#include "mainmenu.h"
#include "mqualitu.h"
#include<QtSql/QSqlRecord>
#include<QtSql/QSqlQuery>
#include<QPixmap>
#include<QDebug>
#include<QSqlError>
#include "paper.h"
#include "instfuser.h"

mytop::mytop(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mytop)
{
    ui->setupUi(this);

    QSqlQuery query = QSqlQuery ();
     query.exec( "CREATE TABLE IF NOT EXISTS mytop ( id int primary key, проблема varchar , ответ varchar, пример_изображения_или_замены bytea)" );
     query.prepare("insert into mytop (id, проблема, ответ, пример_изображения_или_замены) values"
" (1,'Проверьте тип бумаги','Используемая бумага не соответствует техническим требованиям','Нажмите на кнопку - чаще всего используемый тип бумаги в принтере'),"
"(2, 'Бумага изначальная мятая, долго лежит один лист','Возьмите новые листы, из недавно открытой пачки', 'К проблеме не требуется инструкций или изображения'),"
"(3,'Проблема в фьюзере','Снимите и вновь его установите, перезагрузите устройство(нажмите на кнопку переустановка и замена фьюзера',  'pic/fuser.jpg'),"
"(4,'На пути транспортировки бумаге есть посторонние материалы и повреждения','Удалите посторонние материалы и устраните повреждения', 'К проблеме не требуется инструкций или изображения'),"
"(5,'Иначе это узел фьюзера', 'Замените фьюзер(нажмите на кнопку переустанока и замена фьюзера)', 'pic/fuser.jpg')"
                   "ON CONFLICT (id) DO NOTHING");

     if( !query.exec() )
         qDebug() << "Error inserting image into table:\n" << query.lastError();
     mytmodel = new QSqlQueryModel();
     mytmodel ->setQuery("SELECT проблема, ответ, пример_изображения_или_замены FROM public.mytop order by id asc");
     mytmodel->setHeaderData(0,Qt::Horizontal,"Описание Проблемы");
        mytmodel->setHeaderData(1,Qt::Horizontal,"решение");

     mytmodel->setHeaderData(2,Qt::Horizontal,"изображение\n или замена\n детали");

     ui->tmytop->setModel(mytmodel);
     ui->tmytop->horizontalHeader()->setDefaultSectionSize(300);
        ui->tmytop->verticalHeader()->setDefaultSectionSize(100);
     ui->tmytop->show();
}

mytop::~mytop()
{
    delete ui;
}


void mytop::on_main_triggered()
{
    hide();
    mainmenu* window = new mainmenu();
    window->show();
}

void mytop::on_mytop_2_triggered()
{
    hide();
    mqualitu* window = new mqualitu();
    window->show();
}



void mytop::on_tmytop_clicked(const QModelIndex &index)
{

    QPixmap temp_non;
    temp_non = ui->tmytop->model()->data(ui->tmytop->model()->index(index.row(),2)).toString();

    ui->lpic_2->setPixmap(temp_non);
 ui->lpic_2->setScaledContents(true);
}


void mytop::on_katrig_clicked()
{
    paper* window = new paper();
    window->show();
}

void mytop::on_pushButton_clicked()
{
    instfuser* window = new instfuser();
    window->show();

}

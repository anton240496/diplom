#include "compnetwork.h"
#include "ui_compnetwork.h"
#include <QSqlError>
#include <QtSql/QSqlQuery>
#include<QDebug>
#include "mqualitu.h"
#include"mainwindow.h"
#include"mainmenu.h"
#include"driverconection.h"

compnetwork::compnetwork(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::compnetwork)
{
    ui->setupUi(this);

    QSqlQuery query = QSqlQuery ();
  query.exec( "CREATE TABLE IF NOT EXISTS compnet ( id int primary key, решение varchar , ответ varchar)" );

  query.prepare("insert into compnet (id, решение, ответ) values(1,'Проблема с интернет сетью','Замените кабель порта'),"
                        "(2,'Нет соединения с устройством, где расположен файл на печать','Попробуйте вытащить и снова стаывить флешку или преходник в разъем'),"
                    "(3,'Проблема с соединением осталась','Повреждение в флешке, либо если устройство компютер - нажмите на кнопку установить драйвера'),"
                "(4,'На бумаге после печати не качественное изображение', 'Нажмите на кнопку дефект лазерной печати'),"
                  "(5,'Нет подходящего решения', 'Проблема в приложение компьютера из которого вы пытаетесь распечатать файл, попробуйте его перезагрузить')"
                        "ON CONFLICT (id) DO NOTHING");

  if( !query.exec() )
      qDebug() << "Error inserting image into table:\n" << query.lastError();

  knmodel = new QSqlQueryModel();
  knmodel ->setQuery("SELECT решение, ответ FROM public.compnet order by id asc");
   knmodel->setHeaderData(0,Qt::Horizontal,"Описание Проблемы");
      knmodel->setHeaderData(1,Qt::Horizontal,"решение");



  ui->compnet->setModel(knmodel);
  ui->compnet->horizontalHeader()->setDefaultSectionSize(220);
     ui->compnet->verticalHeader()->setDefaultSectionSize(100);
  ui->compnet->show();

}

compnetwork::~compnetwork()
{
    delete ui;
}




void compnetwork::on_deflr_clicked()
{
    hide();
    mqualitu* window = new mqualitu();
    window->show();
}

void compnetwork::on_main_triggered()
{
    hide();
    mainmenu* window = new mainmenu();
    window->show();
}

void compnetwork::on_faks_clicked()
{
    hide();
    driverconection* window = new driverconection();
    window->show();
}

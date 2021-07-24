#include "fon.h"
#include "ui_fon.h"
#include "mainmenu.h"
#include "mqualitu.h"
#include<QtSql/QSqlRecord>
#include<QtSql/QSqlQuery>
#include<QPixmap>
#include<QDebug>
#include<QSqlError>
#include"katrig.h"


fon::fon(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fon)
{
    ui->setupUi(this);

    QSqlQuery query = QSqlQuery ();
     query.exec( "CREATE TABLE IF NOT EXISTS fon ( id int primary key, проблема varchar , ответ varchar, пример_изображения_или_замены bytea)" );
     query.prepare("insert into fon (id, проблема, ответ, пример_изображения_или_замены) values"
" (1,'Стекло экспонирования(сканирования) грязное','Прочистите его от пили и загрязнений сухой тряпкой','pic/fon/eksp.jpg'),"
"(2, 'Контакт заземления барабана грязный(фото чистого барабана справа)', 'Прочистите контакт заземление барабана, сжатым воздухом или сухой тряпкой','pic/fon/baraban.jpg'),"
"(3, 'Картридж не правильно поставлен','Снимите и заново поставьте картридж', 'Нажмите на кноку переустановка катриджа'),"
"(4, 'Картридж закончился или поврежден','Поставьте новый картридж', 'Нажмите на кноку переустановка катриджа'),"
"(5,'Проверьте BTR (ролик переноса для печати, его фото справа) на наличие загрязнений и повреждений', 'Почистите BTR, если есть повреждения, замените его откройте крышку, достаньте картридж, под ним тот самый ролик', 'pic/fon/btr.jpg'),"
"(6,'Проблема с HVPC (высоковольтный блок)', 'Снимите и вновь его установите, возмоно его надо заменить','pic/fon/hvpc.jpg'),"
"(7,'Нету нужной проблемы', 'Замените MCU PWB и ESS, возмоно предется обратитсяы в сервис','pic/fon/mcu.jpg')"
                   "ON CONFLICT (id) DO NOTHING");

     if( !query.exec() )
         qDebug() << "Error inserting image into table:\n" << query.lastError();
     fonmodel = new QSqlQueryModel();
     fonmodel ->setQuery("SELECT проблема, ответ, пример_изображения_или_замены FROM public.fon order by id asc");
     fonmodel->setHeaderData(0,Qt::Horizontal,"Описание Проблемы");
        fonmodel->setHeaderData(1,Qt::Horizontal,"решение");

     fonmodel->setHeaderData(2,Qt::Horizontal,"изображение\n или замена\n детали");




     ui->fon_2->setModel(fonmodel);
     ui->fon_2->horizontalHeader()->setDefaultSectionSize(300);
             ui->fon_2->verticalHeader()->setDefaultSectionSize(150);


     ui->fon_2->resizeRowsToContents();
     ui->fon_2->show();
}

fon::~fon()
{
    delete ui;
}

void fon::on_main_triggered()
{
    hide();
    mainmenu* window = new mainmenu();
    window->show();
}

void fon::on_nazad_triggered()
{
    hide();
    mqualitu* window = new mqualitu();
    window->show();
}



void fon::on_fon_2_clicked(const QModelIndex &index)
{
    QPixmap temp_non;
    temp_non = ui->fon_2->model()->data(ui->fon_2->model()->index(index.row(),2)).toString();

    ui->lpic_2->setPixmap(temp_non);
 ui->lpic_2->setScaledContents(true);
}

void fon::on_katrig_clicked()
{
    katrig* window = new katrig();
    window->show();
}

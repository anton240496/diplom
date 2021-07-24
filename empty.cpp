#include "empty.h"
#include "ui_empty.h"
#include "mainmenu.h"
#include "mqualitu.h"
#include<QtSql/QSqlRecord>
#include<QtSql/QSqlQuery>
#include<QPixmap>
#include<QDebug>
#include<QSqlError>
#include "paper.h"
#include"katrig.h"

empty::empty(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::empty)
{
    ui->setupUi(this);

    QSqlQuery query = QSqlQuery ();
     query.exec( "CREATE TABLE IF NOT EXISTS empty ( id int primary key, проблема varchar , ответ varchar, пример_изображения_или_замены bytea)" );
     query.prepare("insert into empty (id, проблема, ответ, пример_изображения_или_замены) values"
" (1,'Используемая бумага не соответствует техническим требованиям','Воспользуйтесь рекомендованной бумагой','Нажмите на кнопку чаще всего используемый тип бумаги в принтере'),"
"(2, 'Давно лежит бумага, один лист,возможно она мятая', 'Возьмите новую бумагу, из только что распакованной пачки','К проблеме не требуется инструкций или изображения'),"
"(3, 'Картридж не правильно поставлен','снимите и заново поставьте картридж', 'Нажмите на кнопку переустановка катриджа'),"
"(4, 'Картридж закончился или поврежден','Поставьте новый картридж', 'Нажмите на кнопку переустановка катриджа'),"
"(5,'Проверьте BTR (ролик переноса для печати) на наличие загрязнений и повреждений', 'Почистите BTR, если есть повреждения, замените его откройте крышку, достаньте картридж, под ним тот самый ролик', 'pic/empty/btr.jpg'),"
"(6,'Нету нужной проблемы', 'Замените MCU PWB и ESS, Возмоно предется обратитсяы в сервис','pic/empty/mcu.jpg')"
                   "ON CONFLICT (id) DO NOTHING");

     if( !query.exec() )
         qDebug() << "Error inserting image into table:\n" << query.lastError();
     emmodel = new QSqlQueryModel();
     emmodel ->setQuery("SELECT проблема, ответ, пример_изображения_или_замены FROM public.empty order by id asc");
     emmodel->setHeaderData(0,Qt::Horizontal,"Описание Проблемы");
        emmodel->setHeaderData(1,Qt::Horizontal,"решение");
     emmodel->setHeaderData(2,Qt::Horizontal,"изображение\n или замена\n детали");




     ui->empty_2->setModel(emmodel);
     ui->empty_2->horizontalHeader()->setDefaultSectionSize(300);
        ui->empty_2->verticalHeader()->setDefaultSectionSize(150);

     ui->empty_2->resizeRowsToContents();
     ui->empty_2->show();
}

empty::~empty()
{
    delete ui;
}

void empty::on_main_triggered()
{
    hide();
    mainmenu* window = new mainmenu();
    window->show();
}

void empty::on_nazad_triggered()
{
    hide();
    mqualitu* window = new mqualitu();
    window->show();
}


void empty::on_empty_2_clicked(const QModelIndex &index)
{
    QPixmap temp_non;
    temp_non = ui->empty_2->model()->data(ui->empty_2->model()->index(index.row(),2)).toString();

    ui->lpic_2->setPixmap(temp_non);
 ui->lpic_2->setScaledContents(true);
}

void empty::on_paper_clicked()
{
    paper* window = new paper();
    window->show();
}

void empty::on_katrig_clicked()
{
    katrig* window = new katrig();
    window->show();
}

#include "ribe.h"
#include "ui_ribe.h"
#include"mainmenu.h"
#include"mqualitu.h"
#include<QtSql/QSqlRecord>
#include<QtSql/QSqlQuery>
#include<QPixmap>
#include<QDebug>
#include<QSqlError>
#include"paper.h"
#include"katrig.h"

ribe::ribe(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ribe)
{
    ui->setupUi(this);

    QSqlQuery query = QSqlQuery ();
     query.exec( "CREATE TABLE IF NOT EXISTS ribe ( id int primary key, проблема varchar , ответ varchar, пример_изображения_или_замены bytea)" );
     query.prepare("insert into ribe (id, проблема, ответ, пример_изображения_или_замены) values "
" (1,'Используемая бумага не соответствует техническим требованиям','Воспользуйтесь рекомендованной бумагой','Нажмите на кнопку чаще всего используемый тип бумаги в принтере'),"
"(2, 'Давно лежит бумага, один лист,возможно она мятая', 'Возьмите новую бумагу, из только что распакованной пачки','К проблеме не требуется инструкций или изображения'),"
"(3, 'Картридж не правильно поставлен','Снимите и заново поставьте картридж', 'Нажмите на кноку переустановка катриджа'),"
"(4, 'Картридж закончился или поврежден','Поставьте новый картридж', 'Нажмите на кноку переустановка катриджа'),"
"(5,'Проверьте BTR (ролик переноса для печати) на наличие загрязнений и повреждений', 'Почистите BTR, если есть повреждения, замените его откройте крышку, достаньте картридж, под ним тот самый ролик', 'pic/ribe/btr.jpg'),"
"(6,'Проблема в hvps в высоковольтном блоке','Снимите и вновь установите HVPS (высоковольтный блок), выключите и включите питание, начните печать', 'pic/ribe/hvpc.jpg'),"
"(7,'Проблема осталась','Замените  HVPS (высоковольтный блок, возможно надо обратиться к специалисту)', 'pic/ribe/hvpc.jpg')"
                   "ON CONFLICT (id) DO NOTHING");

     if( !query.exec() )
         qDebug() << "Error inserting image into table:\n" << query.lastError();
     ribemodel = new QSqlQueryModel();
     ribemodel ->setQuery("SELECT проблема, ответ, пример_изображения_или_замены FROM public.ribe order by id asc");
     ribemodel->setHeaderData(0,Qt::Horizontal,"Описание Проблемы");
        ribemodel->setHeaderData(1,Qt::Horizontal,"решение");

     ribemodel->setHeaderData(2,Qt::Horizontal,"изображение\n или замена\n детали");

     ui->ribe_2->setModel(ribemodel);
     ui->ribe_2->horizontalHeader()->setDefaultSectionSize(300);
        ui->ribe_2->verticalHeader()->setDefaultSectionSize(100);
     ui->ribe_2->show();
}

ribe::~ribe()
{
    delete ui;
}

void ribe::on_main_triggered()
{
     hide();
    mainmenu* window = new mainmenu();
    window->show();
}

void ribe::on_nazad_triggered()
{
    hide();
    mqualitu* window = new mqualitu();
    window->show();
}


void ribe::on_ribe_2_clicked(const QModelIndex &index)
{
    QPixmap temp_non;
    temp_non = ui->ribe_2->model()->data(ui->ribe_2->model()->index(index.row(),2)).toString();

    ui->lpic_2->setPixmap(temp_non);
 ui->lpic_2->setScaledContents(true);
}

void ribe::on_paper_clicked()
{

    paper* window = new paper();
    window->show();
}

void ribe::on_katrig_clicked()
{
    katrig* window = new katrig();
    window->show();
}

#include "pytna.h"
#include "ui_pytna.h"
#include "mainmenu.h"
#include "mqualitu.h"
#include"paper.h"
#include<QtSql/QSqlRecord>
#include<QtSql/QSqlQuery>
#include<QPixmap>
#include<QDebug>
#include<QSqlError>
#include"instfuser.h"
#include"katrig.h"

pytna::pytna(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pytna)
{
    ui->setupUi(this);

    QSqlQuery query = QSqlQuery ();
     query.exec( "CREATE TABLE IF NOT EXISTS pytna ( id int primary key, проблема varchar , ответ varchar, пример_изображения_или_замены bytea)" );
     query.prepare("insert into pytna (id, проблема, ответ, пример_изображения_или_замены) values "
"(1, 'Картридж не правильно поставлен','Снимите и заново поставьте картридж', 'Нажмите на кноку переустановка катриджа'),"
"(2, 'Картридж закончился или поврежден','Поставьте новый картридж', 'Нажмите на кноку переустановка катриджа'),"
"(3,'Проверьте BTR (ролик переноса для печати) на наличие загрязнений и повреждений', 'Почистите BTR, если есть повреждения, замените его откройте крышку, достаньте картридж, под ним тот самый ролик', 'pic/pytna/btr.jpg'),"
"(4,'Проверьте, нет ли загрязнений на пути транспортировки бумаги(к подготовке печати изображения)', 'Почистите транспортер бумаги сухой тряпкой  исжатымвоздухом', 'К проблеме не требуется инструкций или изображения'),"
"(5,'Нагревальный вал черный(на нем много тонера)', 'Почистите его сухой тряпкой, сжатым воздузом','pic/pytna/val.jpg'),"
"(6,'Проблема в фьюзера', 'Нажмите на кнопку замена фьюзера','pic/pytna/fuser.jpg'),"
"(7,'Используемая бумага не соответствует техническим требованиям','Воспользуйтесь рекомендованной бумагой','Нажмите на кнопку чаще всего используемый тип бумаги в принтере'),"
"(8, 'Давно лежит бумага, один лист,возможно она мятая', 'Возьмите новую бумагу, из только что распакованной пачки','К проблеме не требуется инструкций или изображения'),"
"(9,'Проблема осталась','Замените  HVPS (высоковольтный блок, возможно надо обратиться к специалисту', 'pic/pytna/hvpc.jpg')"
                   "ON CONFLICT (id) DO NOTHING");

     if( !query.exec() )
         qDebug() << "Error inserting image into table:\n" << query.lastError();
     pytmodel = new QSqlQueryModel();
     pytmodel ->setQuery("SELECT проблема, ответ, пример_изображения_или_замены FROM public.pytna order by id asc");
     pytmodel->setHeaderData(0,Qt::Horizontal,"Описание Проблемы");
        pytmodel->setHeaderData(1,Qt::Horizontal,"решение");

     pytmodel->setHeaderData(2,Qt::Horizontal,"изображение\n или замена\n детали");

     ui->pytna_2->setModel(pytmodel);
     ui->pytna_2->horizontalHeader()->setDefaultSectionSize(300);
        ui->pytna_2->verticalHeader()->setDefaultSectionSize(100);

     ui->pytna_2->show();
}

pytna::~pytna()
{
    delete ui;
}

void pytna::on_main_triggered()
{
    hide();
    mainmenu* window = new mainmenu();
    window->show();
}

void pytna::on_nazad_triggered()
{
    hide();
    mqualitu* window = new mqualitu();
    window->show();
}



void pytna::on_pytna_2_clicked(const QModelIndex &index)
{
    QPixmap temp_non;
    temp_non = ui->pytna_2->model()->data(ui->pytna_2->model()->index(index.row(),2)).toString();

    ui->lpic_2->setPixmap(temp_non);
 ui->lpic_2->setScaledContents(true);
}

void pytna::on_paper_clicked()
{

    paper* window = new paper();
    window->show();
}

void pytna::on_fuser_clicked()
{

    instfuser* window = new instfuser();
    window->show();
}

void pytna::on_katrig_clicked()
{
    katrig* window = new katrig();
    window->show();
}

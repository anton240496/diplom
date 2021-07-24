#include "skew.h"
#include "ui_skew.h"
#include "mainmenu.h"
#include "mqualitu.h"
#include<QtSql/QSqlRecord>
#include<QtSql/QSqlQuery>
#include<QPixmap>
#include<QDebug>
#include<QSqlError>
#include "kaset.h"
#include"katrig.h"
skew::skew(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::skew)
{
    ui->setupUi(this);

    QSqlQuery query = QSqlQuery ();
     query.exec( "CREATE TABLE IF NOT EXISTS skew ( id int primary key, проблема varchar , ответ varchar, пример_изображения_или_замены bytea)" );
     query.prepare("insert into skew (id, проблема, ответ, пример_изображения_или_замены) values"
" (1,'Аппарат не установлен на устойчивой горизонтальной поверхности','Установите аппарат на устойчивую горизонтальную поверхность', 'К проблеме не требуется инструкций или изображения'),"
"(2,'Картридж не правильно поставлен','Снимите и заново поставьте картридж', 'Нажмите на кноку переустановка катриджа'),"
"(3,'Проверьте правильно ли установлена кассета для бумаги', 'Правильно установите кассету для бумаги', 'Нажмите на кнопку переустановка касеты'),"
"(4,'Проверьте есть ли повреждения или загрязнения на пути транспортировки бумаги, к процесу печати', 'Устраните повреждения, прочистите все сухой тряпкой, сжатым воздухом','Не требуетсяы изображений или инструкций'),"
"(5,'Нету нужной проблемы', 'Замените MCU PWB и ESS, возмоно предется обратитсяы в сервис','pic/mcu.jpg')"
                   "ON CONFLICT (id) DO NOTHING");

     if( !query.exec() )
         qDebug() << "Error inserting image into table:\n" << query.lastError();
     skewmodel = new QSqlQueryModel();
     skewmodel ->setQuery("SELECT проблема, ответ, пример_изображения_или_замены FROM public.skew order by id asc");
     skewmodel->setHeaderData(0,Qt::Horizontal,"Описание Проблемы");
        skewmodel->setHeaderData(1,Qt::Horizontal,"решение");

     skewmodel->setHeaderData(2,Qt::Horizontal,"изображение\n или замена\n детали");




     ui->skew_2->setModel(skewmodel);
     ui->skew_2->horizontalHeader()->setDefaultSectionSize(300);
        ui->skew_2->verticalHeader()->setDefaultSectionSize(100);


     ui->skew_2->resizeRowsToContents();
     ui->skew_2->show();
}

skew::~skew()
{
    delete ui;
}

void skew::on_main_triggered()
{
    hide();
    mainmenu* window = new mainmenu();
    window->show();
}

void skew::on_nazad_triggered()
{
    hide();
    mqualitu* window = new mqualitu();
    window->show();
}



void skew::on_skew_2_clicked(const QModelIndex &index)
{
    QPixmap temp_non;
    temp_non = ui->skew_2->model()->data(ui->skew_2->model()->index(index.row(),2)).toString();

    ui->lpic_2->setPixmap(temp_non);
 ui->lpic_2->setScaledContents(true);
}

void skew::on_kaset_clicked()
{
    kaset* window = new kaset();
    window->show();
}

void skew::on_katrig_clicked()
{
    katrig* window = new katrig();
    window->show();
}

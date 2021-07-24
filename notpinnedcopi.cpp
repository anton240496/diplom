#include "notpinnedcopi.h"
#include "ui_notpinnedcopi.h"
#include "mainmenu.h"
#include "mqualitu.h"
#include<QtSql/QSqlRecord>
#include<QtSql/QSqlQuery>
#include<QPixmap>
#include<QDebug>
#include<QSqlError>
#include "paper.h"
#include "instfuser.h"


notpinnedcopi::notpinnedcopi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::notpinnedcopi)
{
    ui->setupUi(this);

    QSqlQuery query = QSqlQuery ();
     query.exec( "CREATE TABLE IF NOT EXISTS notpin ( id int primary key, проблема varchar , ответ varchar, пример_изображения_или_замены bytea)" );
     query.prepare("insert into notpin (id, проблема, ответ, пример_изображения_или_замены) values"
" (1,'Проверьте тип бумаги','Используемая бумага не соответствует техническим требованиям','Нажмите на кнопку - чаще всего используемый тип бумаги в принтере'),"
"(2, 'Бумага изначальная мятая, долго лежит один лист','Возьмите новые листы, из недавно открытой пачки', 'К проблеме не требуется инструкций или изображения'),"
"(3,'Проверьте напряжение питания, напряжение питания должно быть 220v ','Подключитесь к розетке с допустимым напряжением питания',  'К проблеме не требуется инструкций или изображения'),"
"(4,'Проверьте ровно ли установлен фьюзер','Установител ровно фьзер(фото справа)', 'pic/fuser.jpg'),"
"(5,'Сделайте диагностику, проерьте температуру закреплениия','Настройте температуру в пределе 200 градусов', 'К проблеме не требуется инструкций или изображения'),"
"(6,'После проверки температуры проблема осталась', 'Нажмите на кнопку замена фьюзера(вид фьюзера справа)', 'pic/fuser.jpg')"
                   "ON CONFLICT (id) DO NOTHING");

     if( !query.exec() )
         qDebug() << "Error inserting image into table:\n" << query.lastError();
     notpinmodel = new QSqlQueryModel();
     notpinmodel ->setQuery("SELECT проблема, ответ, пример_изображения_или_замены FROM public.notpin order by id asc");
     notpinmodel->setHeaderData(0,Qt::Horizontal,"Описание Проблемы");
        notpinmodel->setHeaderData(1,Qt::Horizontal,"решение");

     notpinmodel->setHeaderData(2,Qt::Horizontal,"изображение\n или замена\n детали");

     ui->notpin->setModel(notpinmodel);

     ui->notpin->horizontalHeader()->setDefaultSectionSize(300);
        ui->notpin->verticalHeader()->setDefaultSectionSize(100);
     ui->notpin->show();
}

notpinnedcopi::~notpinnedcopi()
{
    delete ui;
}

void notpinnedcopi::on_main_triggered()
{
    hide();
    mainmenu* window = new mainmenu();
    window->show();
}

void notpinnedcopi::on_nazad_triggered()
{
    hide();
    mqualitu* window = new mqualitu();
    window->show();
}




void notpinnedcopi::on_notpin_clicked(const QModelIndex &index)
{
    QPixmap temp_non;
    temp_non = ui->notpin->model()->data(ui->notpin->model()->index(index.row(),2)).toString();

    ui->lpic_2->setPixmap(temp_non);
 ui->lpic_2->setScaledContents(true);
}

void notpinnedcopi::on_paper_clicked()
{
    paper* window = new paper();
    window->show();
}

void notpinnedcopi::on_fuser_clicked()
{
    instfuser* window = new instfuser();
    window->show();
}

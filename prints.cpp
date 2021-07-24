#include "prints.h"
#include "ui_prints.h"
#include "mainmenu.h"
#include "mqualitu.h"
#include<QtSql/QSqlRecord>
#include<QtSql/QSqlQuery>
#include<QPixmap>
#include<QDebug>
#include<QSqlError>
#include"katrig.h"

prints::prints(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::prints)
{
    ui->setupUi(this);

    QSqlQuery query = QSqlQuery ();
     query.exec( "CREATE TABLE IF NOT EXISTS prints ( id int primary key, проблема varchar , ответ varchar, пример_изображения_или_замены bytea)" );
     query.prepare("insert into prints (id, проблема, ответ, пример_изображения_или_замены) values "
" (1,'Проверьте движущиеся элементы каретки (сканирование) на наличие посторонних материалов ','Прочистите сканер, зеркала, стекло, уберите все постороние материалы','К проблеме не требуется инструкций или изображения'),"
"(2, 'Картридж не правильно поставлен','снимите и заново поставьте картридж', 'Нажмите на кноку переустановка катриджа'),"
"(3, 'Картридж закончился или поврежден','Поставьте новый картридж', 'Нажмите на кноку переустановка катриджа'),"
"(4,'Проблема в hvps в высоковольтном блоке','Выключите устройство снимите и вновь установите его и включите устройство', 'pic/hvpc.jpg'),"
"(5,'Проверьте правильно ли подключены разъемы', 'Подключите разъемы','К проблеме не требуется инструкций или изображения'),"
"(6,'Проверьте проводку на обрыв цепи и короткое замыкание', 'Устраните обрыв цепи или короткое замыкание','К проблеме не требуется инструкций или изображения'),"
"(7,'Проблема осталась','Замените  HVPS (высоковольтный блок, возможно надо обратиться к специалисту)', 'pic/hvpc.jpg')"
                   "ON CONFLICT (id) DO NOTHING");

     if( !query.exec() )
         qDebug() << "Error inserting image into table:\n" << query.lastError();
     printsmodel = new QSqlQueryModel();
     printsmodel ->setQuery("SELECT проблема, ответ, пример_изображения_или_замены FROM public.prints order by id asc");
     printsmodel->setHeaderData(0,Qt::Horizontal,"Описание Проблемы");
        printsmodel->setHeaderData(1,Qt::Horizontal,"решение");

     printsmodel->setHeaderData(2,Qt::Horizontal,"изображение\n или замена\n детали");

     ui->prints_2->setModel(printsmodel);
     ui->prints_2->horizontalHeader()->setDefaultSectionSize(300);
        ui->prints_2->verticalHeader()->setDefaultSectionSize(100);

     ui->prints_2->show();
}

prints::~prints()
{
    delete ui;
}

void prints::on_main_triggered()
{
    hide();
    mainmenu* window = new mainmenu();
    window->show();
}

void prints::on_nazad_triggered()
{
    hide();
    mqualitu* window = new mqualitu();
    window->show();
}



void prints::on_prints_2_clicked(const QModelIndex &index)
{
    QPixmap temp_non;
    temp_non = ui->prints_2->model()->data(ui->prints_2->model()->index(index.row(),2)).toString();

    ui->lpic_2->setPixmap(temp_non);
 ui->lpic_2->setScaledContents(true);
}

void prints::on_katrig_clicked()
{
    katrig* window = new katrig();
    window->show();
}

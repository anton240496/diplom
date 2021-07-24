#include "edgeimage.h"
#include "ui_edgeimage.h"
#include "mainmenu.h"
#include "mqualitu.h"
#include<QtSql/QSqlRecord>
#include<QtSql/QSqlQuery>
#include<QPixmap>
#include<QDebug>
#include<QSqlError>
#include"instfuser.h"
#include"katrig.h"



edgeimage::edgeimage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::edgeimage)
{
    ui->setupUi(this);

    QSqlQuery query = QSqlQuery ();
     query.exec( "CREATE TABLE IF NOT EXISTS edge ( id int primary key, проблема varchar , ответ varchar, пример_изображения_или_замены bytea)" );
     query.prepare("insert into edge (id, проблема, ответ, пример_изображения_или_замены) values"
" (1,'Картридж не правильно поставлен','Cнимите и заново поставьте картридж','Нажмите на кноку переустановка катриджа'),"
"(2, 'Картридж закончился или поврежден ','Поставьте новый картридж', 'Нажмите на кноку переустановка катриджа'),"
"(3,'Снимите узел фьюзера(фото справа, сверху), Проверьте, нет ли загрязнений на поверхности нагревательного вала(фото справа, внизу)', 'Почистите нагревательный вал. Если загрязнения удалить трудно - нажмите на кнопку замена фьюзера', 'pic/valfuser.png'),"
"(4,'Нету нужной проблемы', 'Замените MCU PWB и ESS PWB(фото справа(электрическое стираемое перепрограммируемое ПЗУ)) или обратитесь в техническое обслуживание','pic/dynasi/mcu.jpg')"
                   "ON CONFLICT (id) DO NOTHING");

     if( !query.exec() )
         qDebug() << "Error inserting image into table:\n" << query.lastError();
     edgemodel = new QSqlQueryModel();
     edgemodel ->setQuery("SELECT проблема, ответ, пример_изображения_или_замены FROM public.edge order by id asc");
     edgemodel->setHeaderData(0,Qt::Horizontal,"Описание Проблемы");
        edgemodel->setHeaderData(1,Qt::Horizontal,"решение");

     edgemodel->setHeaderData(2,Qt::Horizontal,"изображение\n или замена\n детали");




     ui->edge->setModel(edgemodel);
     ui->edge->horizontalHeader()->setDefaultSectionSize(300);
        ui->edge->verticalHeader()->setDefaultSectionSize(100);
     ui->edge->show();
}

edgeimage::~edgeimage()
{
    delete ui;
}

void edgeimage::on_main_triggered()
{
    hide();
    mainmenu* window = new mainmenu();
    window->show();
}

void edgeimage::on_nazad_triggered()
{
    hide();
    mqualitu* window = new mqualitu();
    window->show();
}


void edgeimage::on_edge_clicked(const QModelIndex &index)
{
    QPixmap temp_non;
    temp_non = ui->edge->model()->data(ui->edge->model()->index(index.row(),2)).toString();

    ui->lpic_2->setPixmap(temp_non);
 ui->lpic_2->setScaledContents(true);

}

void edgeimage::on_pushButton_clicked()
{
    instfuser* window = new instfuser();
    window->show();
}

void edgeimage::on_katrig_clicked()
{
    katrig* window = new katrig();
    window->show();
}

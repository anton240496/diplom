#include "faksdevise.h"
#include "ui_faksdevise.h"
#include<QtSql/QSqlRecord>
#include<QtSql/QSqlQuery>
#include<QPixmap>
#include<QDebug>
#include<QSqlError>
#include"mainwindow.h"
#include"mainmenu.h"
#include"rolikpodachi.h"
#include"termoplenk.h"

faksdevise::faksdevise(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::faksdevise)
{
    ui->setupUi(this);

    QSqlQuery query = QSqlQuery ();
     query.exec( "CREATE TABLE IF NOT EXISTS faksdevice ( id int primary key, проблема varchar , ответ varchar, пример_изображения_или_замены bytea)" );
     query.prepare("insert into faksdevice (id, проблема, ответ, пример_изображения_или_замены) values "
"(1,'Не включается печатающее устройство','Замените блок  на такой же новый(обратите внимание на информацию на старом блоке(V и А) и на разъем подключение к устройству)','pic/faskd/block.jpg'),"
"(2, 'На листе при печати вертикальные белые полосы ','Замените термопленку, нажмите на кнопку замена термопленки', 'pic/faskd/whitepol.jpg'),"
"(3,'Факс мнет или рвет бумагу','Замените или востановите ролик',  'Нажмите на кнопку очистка, снятие ролика'),"
"(4,'Черные полосы на листе при сканирование','Сделайте профилатику сканера, почистите тряпочкой всю оптику', 'pic/faskd/blackpol.jpg'),"
"(5,'Не отрезает принятый лист','Износ ножей замена или ремонт их (Отверткой выкрутите винт и крепящий нож, установите нож и завинтите обратно винт)', 'pic/faskd/noj.jpg'),"
"(6,'Не принимает, не отправляет сообщения','Проверьте связи, возможной произошел сбой в линии связи ', 'К проблеме не требуется инструкций или изображений'),"
"(7,'Часть листа чистое, указание на не полное принятие бумаги','Сверьте его с изображением справа, замените или отремонтируйте прижимной механизм(замените пружину)', 'pic/faskd/polempty.jpg'),"
"(8,'Нет нужной проблемы','Выход из строя электроники', 'В таком случае дешевле и легче будет купить новый аппарат')"
                   "ON CONFLICT (id) DO NOTHING");

     if( !query.exec() )
         qDebug() << "Error inserting image into table:\n" << query.lastError();
     fdmodel = new QSqlQueryModel();
     fdmodel ->setQuery("SELECT проблема, ответ, пример_изображения_или_замены FROM public.faksdevice order by id asc");
     fdmodel->setHeaderData(0,Qt::Horizontal,"Описание Проблемы");
        fdmodel->setHeaderData(1,Qt::Horizontal,"решение");

     fdmodel->setHeaderData(2,Qt::Horizontal,"изображение\n или замена\n детали");

     ui->faskd->setModel(fdmodel);

     ui->faskd->horizontalHeader()->setDefaultSectionSize(300);
        ui->faskd->verticalHeader()->setDefaultSectionSize(100);
//      ui->faskd->resizeColumnToContents(1);
    // ui->faskd->resizeColumnToContents(2);
//     ui->faskd->resizeRowsToContents();
     ui->faskd->show();
}

faksdevise::~faksdevise()
{
    delete ui;
}




void faksdevise::on_faskd_clicked(const QModelIndex &index)
{
    QPixmap temp_non;
    temp_non = ui->faskd->model()->data(ui->faskd->model()->index(index.row(),2)).toString();

    ui->lpic_2->setPixmap(temp_non);
 ui->lpic_2->setScaledContents(true);
}

void faksdevise::on_main_triggered()
{
    hide();
    mainmenu* window = new mainmenu();
    window->show();
}

void faksdevise::on_rolik_clicked()
{
    rolikpodachi* window = new rolikpodachi();
    window->show();
}

void faksdevise::on_tormoz_clicked()
{
    termoplenk* window = new termoplenk();
    window->show();
}

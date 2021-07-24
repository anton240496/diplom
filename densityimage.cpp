#include "densityimage.h"
#include "ui_densityimage.h"
#include"mainmenu.h"
#include"mqualitu.h"
#include<QtSql/QSqlRecord>
#include<QtSql/QSqlQuery>
#include<QPixmap>
#include<QDebug>
#include<QSqlError>
#include"katrig.h"

densityimage::densityimage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::densityimage)
{
    ui->setupUi(this);

    QSqlQuery query = QSqlQuery ();
     query.exec( "CREATE TABLE IF NOT EXISTS density ( id int primary key, проблема varchar , ответ varchar, пример_изображения_или_замены bytea)" );
     query.prepare("insert into density (id, проблема, ответ, пример_изображения_или_замены) values"
"(1,'Стекло экспонирования(ксерокса) грязное','Прочистите или замените стекло','pic/dynasi/eksp.jpg'),"
"(2,'Контакт заземления барабана грязный и поврежден','Прочистите сжатым воздухом или сухой тряпкой контакт заземление барабана и устраните повреждения', 'pic/dynasi/katr.jpg'),"
"(3,'Картридж не правильно поставлен','Снимите и заново поставьте картридж',  'Нажмите на кнопку переустановка и замена катриджа'),"
"(4,'Картридж закончился или поврежден ','Поставьте новый картридж', 'Нажмите на кнопку переустановка и замена катриджа'),"
"(5,'Напечатаете черную копию, во время процесса выключите устройство. Проверьте, после работы, осталось ли на барабане значительное количество тонера', 'Если осталось, замените HVPS (высоковольтный блок) и замените MCU PWB(фото внизу справа).(электрическое стираемое перепрограммируемое ПЗУ) или обратитесь в техническое обслуживание','pic/dynasi/hvpsmcu.jpg'),"
"(6,'Нет нужной проблемы', 'Замените MCU PWB и ESS PWB(фото справа(электрическое стираемое перепрограммируемое ПЗУ) или обратитесь в техническое обслуживание','pic/dynasi/mcu.jpg')"
                   "ON CONFLICT (id) DO NOTHING");

     if( !query.exec() )
         qDebug() << "Error inserting image into table:\n" << query.lastError();
     denimmodel = new QSqlQueryModel();
     denimmodel ->setQuery("SELECT проблема, ответ, пример_изображения_или_замены FROM public.density order by id asc");
     denimmodel->setHeaderData(0,Qt::Horizontal,"Описание Проблемы");
        denimmodel->setHeaderData(1,Qt::Horizontal,"решение");
     denimmodel->setHeaderData(2,Qt::Horizontal,"изображение\n или замена\n детали");

     ui->density->setModel(denimmodel);
     ui->density->horizontalHeader()->setDefaultSectionSize(300);
        ui->density->verticalHeader()->setDefaultSectionSize(150);
     ui->density->show();
}

densityimage::~densityimage()
{
    delete ui;
}



void densityimage::on_main_triggered()
{
    hide();
    mainmenu* window = new mainmenu();
    window->show();
}

void densityimage::on_nazad_triggered()
{
     hide();
    mqualitu* window = new mqualitu();
    window->show();
}




void densityimage::on_density_clicked(const QModelIndex &index)
{
    QPixmap temp_non;
    temp_non = ui->density->model()->data(ui->density->model()->index(index.row(),2)).toString();

    ui->lpic_2->setPixmap(temp_non);
 ui->lpic_2->setScaledContents(true);

}

void densityimage::on_katrig_clicked()
{
    katrig* window = new katrig();
    window->show();
}

#include "gorizontline.h"
#include "ui_gorizontline.h"
#include "mainmenu.h"
#include "mqualitu.h"
#include<QtSql/QSqlRecord>
#include<QtSql/QSqlQuery>
#include<QPixmap>
#include<QDebug>
#include<QSqlError>
#include"instfuser.h"
#include"paper.h"

gorizontline::gorizontline(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gorizontline)
{
    ui->setupUi(this);

    QSqlQuery query = QSqlQuery ();
     query.exec( "CREATE TABLE IF NOT EXISTS gorlin ( id int primary key, проблема varchar , ответ varchar, пример_изображения_или_замены bytea)" );
     query.prepare("insert into gorlin (id, проблема, ответ, пример_изображения_или_замены) values"
" (1,'Проверьте движущиеся элементы каретки (сканирования) на наличие посторонних материалов ','Прочистите сканер, зеркала, стекло, уберите все постороние материалы','К проблеме не требуется инструкций или изображения'),"
" (2,'Картридж не правильно поставлен','снимите и заново поставьте картридж','нажмите на кноку переустановка катриджа'),"
"(3, 'Картридж закончился или поврежден','поставьте новый картридж', 'нажмите на кноку переустановка катриджа'),"
"(4,'Проверьте BTR (ролик переноса для печати) на наличие загрязнений и повреждений', 'Почистите BTR, если есть повреждения, замените его откройте крышку, достаньте картридж, под ним тот самый ролик', 'pic/gorlin/btr.jpg'),"
"(5,'Расстояние между черными или белыми линиями на листе 78 мм(окружность нагреательного вала)', 'Замените MCU PWB и ESS PWB(фото справа(электрическое стираемое перепрограммируемое ПЗУ)) или обратитесь в техническое обслуживание', 'pic/gorlin/mcu.jpg'),"
"(6,'Нагревальный вал черный(на нем тонер)', 'Почистите его сухой тряпкой, сжатым воздузом','pic/gorlin/val.jpg'),"
"(7,'Иначе проблема в фьюзера', 'Нажмите на кнопку замена фьюзера','pic/gorlin/fuser.jpg')"
                   "ON CONFLICT (id) DO NOTHING");

     if( !query.exec() )
         qDebug() << "Error inserting image into table:\n" << query.lastError();
     gorlmodel = new QSqlQueryModel();
     gorlmodel ->setQuery("SELECT проблема, ответ, пример_изображения_или_замены FROM public.gorlin order by id asc");
     gorlmodel->setHeaderData(0,Qt::Horizontal,"Описание Проблемы");
        gorlmodel->setHeaderData(1,Qt::Horizontal,"решение");

     gorlmodel->setHeaderData(2,Qt::Horizontal,"изображение\n или замена\n детали");

     ui->gorlin->setModel(gorlmodel);

     ui->gorlin->horizontalHeader()->setDefaultSectionSize(300);
        ui->gorlin->verticalHeader()->setDefaultSectionSize(100);


     ui->gorlin->show();

}

gorizontline::~gorizontline()
{
    delete ui;
}

void gorizontline::on_main_triggered()
{
    hide();
    mainmenu* window = new mainmenu();
    window->show();
}

void gorizontline::on_nazad_triggered()
{
    hide();
    mqualitu* window = new mqualitu();
    window->show();
}



void gorizontline::on_gorlin_clicked(const QModelIndex &index)
{
    QPixmap temp_non;
    temp_non = ui->gorlin->model()->data(ui->gorlin->model()->index(index.row(),2)).toString();

    ui->lpic_2->setPixmap(temp_non);
 ui->lpic_2->setScaledContents(true);
}

void gorizontline::on_paper_clicked()
{
    paper* window = new paper();
    window->show();
}

void gorizontline::on_pushButton_clicked()
{
    instfuser* window = new instfuser();
    window->show();
}

#include "mqualitu.h"
#include "ui_mqualitu.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"mainwindow.h"
#include"mainmenu.h"
#include"edgeimage.h"

//#include<QtSql/QSqlRecord>
#include<QtSql/QSqlQuery>//пакет для построение запросов
#include<QPixmap>// для изображений
#include<QDebug>// окно компиляции
#include<QSqlError>// прописывание ошибки sql запроса

#include"densityimage.h"
#include"mytop.h"
#include "fon.h"
#include "empty.h"
#include "skew.h"
#include "stripsdirection.h"
#include "notpinnedcopi.h"
#include "gorizontline.h"
#include "ribe.h"
#include "pytna.h"
#include "prints.h"
#include "emptyimage.h"

mqualitu::mqualitu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mqualitu)
{
    ui->setupUi(this);

          QSqlQuery query = QSqlQuery ();// создать таблицу если ее нету, прописать два запроса
          // создать таблицу// вставить в таблицу данные
           query.exec( "CREATE TABLE IF NOT EXISTS qualitypictures ( id int primary key, проблема varchar , признаки varchar, изображение bytea)" );
           query.prepare("insert into qualitypictures (id, проблема, признаки, изображение) values "
    "(1,'Малая плотность изображения','Малая плотность всего изображения', 'pic/qual/mp.jpg'),"
    "(2, 'Мятый отпечаток','Лист отпечатка помят, морщинист или порван', 'нет изображения'),"
    "(3,'Остаточное изображение','посторонние, некачественное изображение',  'pic/qual/o.jpg'),"
    "(4,'Фон','Полностью черный лист', 'pic/qual/fon.jpg'),"
    "(5,'Пропуск изображения','Часть изображения отсутствует', 'pic/qual/pim.jpg'),"
    "(6,'Перекос, неправильная регистрация','Напечатанные изображения не параллельны кромкам листа бумаги', 'pic/qual/per.jpg'),"
    "(7,'Полосы, линии и мазки в направлении подачи бумаги','Вертикальные черные линии или белые штрихи, ориентированные в направлении подачи бумаги ', 'pic/qual/pollin.jpg'),"
    "(8,'Незакрепленная копия','изображение легко можно стереть', 'pic/qual/nk.jpg'),"
    "(9,'Повторяющиеся полосы','Горизонтальные черные линии или белые штрихи', 'pic/qual/povpogor.jpg'),"
    "(10,'Рябь','Неравномерная плотность', 'pic/qual/rab.jpg'),"
    "(11,'Пятна','Пятна тонера, нерегулярно распределенные по всей странице', 'pic/qual/patn.jpg'),"
    "(12,'Полностью черные отпечатки','Отпечаток полностью черен', 'pic/qual/cherop.jpg'),"
    "(13,'Пустой лист','Отпечаток полностью бел', 'pic/qual/empty.jpg')"
    "ON CONFLICT (id) DO NOTHING");

           if( !query.exec() )//если ошибка с запросами написать это в вокно компилятора
               qDebug() << "Error inserting image into table:\n" << query.lastError();


        qpmodel = new QSqlQueryModel();
        qpmodel ->setQuery("SELECT проблема, признаки, изображение FROM public.qualitypictures order by id asc");//запрос о таблице
         qpmodel->setHeaderData(0,Qt::Horizontal,"возможные проблемы");
        qpmodel->setHeaderData(2,Qt::Horizontal,"изображение");// переименование некоторых столбцов, подсчет с нуля



        ui->qualitypictures->setModel(qpmodel);
        //ui->qualitypictures->resizeColumnsToContents();
    //    ui->qualitypictures->horizontalHeader()->setDefaultSectionSize(300);
    //       ui->qualitypictures->verticalHeader()->setDefaultSectionSize(60);
        //ui->qualitypictures->resizeRowsToContents();

        ui->qualitypictures->show();
}

mqualitu::~mqualitu()
{
    delete ui;
}


void mqualitu::on_qualitypictures_clicked(const QModelIndex &index)
{
    QPixmap temp_non;
    temp_non = ui->qualitypictures->model()->data(ui->qualitypictures->model()->index(index.row(),2)).toString();

    ui->lpic_2->setPixmap(temp_non);
 ui->lpic_2->setScaledContents(true);

    }



void mqualitu::on_main_triggered()
{
    hide();
    mainmenu* window = new mainmenu();
    window->show();
}



void mqualitu::on_densityimage_clicked()
{
     hide();
    densityimage* window = new densityimage();
    window->show();
}

void mqualitu::on_mytop_clicked()
{
    hide();
   mytop* window = new mytop();
   window->show();
}

void mqualitu::on_edgeimage_clicked()
{
    hide();
   edgeimage* window = new edgeimage();
   window->show();
}

void mqualitu::on_fon_clicked()
{
    hide();
   fon* window = new fon();
   window->show();
}

void mqualitu::on_empty_clicked()
{
    hide();
   empty* window = new empty();
   window->show();
}

void mqualitu::on_skew_clicked()
{
    hide();
   skew* window = new skew();
   window->show();
}

void mqualitu::on_stripdir_clicked()
{
    hide();
   stripsdirection* window = new stripsdirection();
   window->show();
}



void mqualitu::on_notpinnecopi_clicked()
{
    hide();
   notpinnedcopi* window = new notpinnedcopi();
   window->show();
}

void mqualitu::on_gorizontline_clicked()
{
    hide();
   gorizontline* window = new gorizontline();
   window->show();
}

void mqualitu::on_ribe_clicked()
{
    hide();
   ribe* window = new ribe();
   window->show();
}

void mqualitu::on_pytna_clicked()
{
    hide();
   pytna* window = new pytna();
   window->show();
}

void mqualitu::on_prints_clicked()
{
    hide();
   prints* window = new prints();
   window->show();
}

void mqualitu::on_emptyimage_clicked()
{
    hide();
   emptyimage* window = new emptyimage();
   window->show();
}

#include "term.h"
#include "ui_term.h"
#include "mainwindow.h"
#include "mainmenu.h"
#include "fuser.h"
#include<QtSql/QSqlRecord>
#include<QtSql/QSqlQuery>
#include<QPixmap>
#include<QDebug>
#include<QSqlError>

term::term(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::term)
{
    ui->setupUi(this);

    QSqlQuery query = QSqlQuery ();
     query.exec( "CREATE TABLE IF NOT EXISTS term ( id int primary key, проблема varchar , ответ varchar, пример_изображения_или_замены bytea)" );
     query.prepare("insert into term (id, проблема, ответ, пример_изображения_или_замены) values"
                   " (1,'листы после печати очень горячие или нетеплые','Зафиксируете правильно тонер: откройте крышку найдите тонер,аккуратно переустановите его', 'pic/fuser/toner.jpg'),"
"(2, 'листы после печати теплые, их температура в норме','снимите разъемы, прочистите контакты в площадке', 'нет изображения')"
                   "ON CONFLICT (id) DO NOTHING");

     if( !query.exec() )
         qDebug() << "Error inserting image into table:\n" << query.lastError();
     termmodel = new QSqlQueryModel();
     termmodel ->setQuery("SELECT проблема, ответ, пример_изображения_или_замены FROM public.term order by id asc");
     termmodel->setHeaderData(0,Qt::Horizontal,"Описание Проблемы");
        termmodel->setHeaderData(1,Qt::Horizontal,"решение");

     termmodel->setHeaderData(2,Qt::Horizontal,"изображение или замена детали");

     ui->term_2->setModel(termmodel);
     ui->term_2->horizontalHeader()->setDefaultSectionSize(375);
        ui->term_2->verticalHeader()->setDefaultSectionSize(100);
//  ui->term_2->resizeColumnToContents(1);
//       ui->term_2->resizeColumnToContents(2);
//      ui->term_2->resizeRowsToContents();
     ui->term_2->show();

}

term::~term()
{
    delete ui;
}



void term::on_main_triggered()
{
     hide();
     mainmenu* window = new mainmenu();
     window->show();
}

void term::on_nazad_triggered()
{
     hide();
     fuser* window = new fuser();
     window->show();
}



void term::on_term_2_clicked(const QModelIndex &index)
{
    QPixmap temp_non;
    temp_non = ui->term_2->model()->data(ui->term_2->model()->index(index.row(),2)).toString();

    ui->lpic_2->setPixmap(temp_non);
 ui->lpic_2->setScaledContents(true);

}

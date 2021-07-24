#include "fuser.h"
#include "ui_fuser.h"
#include "mainwindow.h"
#include "mainmenu.h"
#include "term.h"
#include<QtSql/QSqlRecord>
#include<QtSql/QSqlQuery>
#include<QPixmap>
#include<QDebug>
#include<QSqlError>
#include"tefval.h"


fuser::fuser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fuser)
{
    ui->setupUi(this);

    QSqlQuery query = QSqlQuery ();
     query.exec( "CREATE TABLE IF NOT EXISTS fuser ( id int primary key, проблема varchar , ответ varchar, варианты varchar, пример_изображения_или_замены bytea)" );
     query.prepare("insert into fuser (id, проблема, ответ,  варианты, пример_изображения_или_замены) values "
"(1,'На панели управления горят все три светодиода','Проверьте термопредохранитель (2а 250 градусов - это норма)если он не в норме перезагрузите устройство', 'Если в норме->нажмите на кнопку в проблема в термопредохранителе','pic/fuser/term.jpg'),"
"(2, 'После перезагрузки на панели все равно управления горят все три светодиода','Проведите диагностику всего устройства', 'Возможно проблема более сложная, обратитесь к специалисту', 'pic/fuser/term.jpg'),"
"(3,'На бумаге не закрепляется часть изображения',  'Уберите тонер с нагревательного элемента','Один вариат', 'К проблеме не требуется инструкций или изображения'),"
"(4,'На обратной стороне распечатанного листа видны посторонние предметы','Проблема в силиконовом вале','Один вариат', 'Нажмите на кнопку замена тефлонового вала'),"
"(5,'Во время работы устройства слышан скрип', 'Прочистите тонер','Один вариат', 'pic/fuser/toner.jpg'),"
"(6,'После печати привод вращается дольше обычного','Прочистите сжатым воздухом оптический датчик','один вариат', 'pic/fuser/opt.jpg'),"
"(7,'На выходе застревает бумага', 'Почистите резиновые ролики(фотоо справа)','Один вариат','pic/fuser/rol.jpg')"
                   "ON CONFLICT (id) DO NOTHING");

     if( !query.exec() )
         qDebug() << "Error inserting image into table:\n" << query.lastError();
      fusmodel = new QSqlQueryModel();
     fusmodel ->setQuery("SELECT проблема, ответ,  варианты, пример_изображения_или_замены FROM public.fuser order by id asc");
     fusmodel->setHeaderData(0,Qt::Horizontal,"Описание Проблемы");
        fusmodel->setHeaderData(1,Qt::Horizontal,"решение");

     fusmodel->setHeaderData(3,Qt::Horizontal,"изображение\n или замена\n детали");

     ui->fuser_2->setModel(fusmodel);
     ui->fuser_2->horizontalHeader()->setDefaultSectionSize(220);
        ui->fuser_2->verticalHeader()->setDefaultSectionSize(100);
     ui->fuser_2->show();
}

fuser::~fuser()
{
    delete ui;
}



void fuser::on_main_triggered()
{
    hide();
    mainmenu* window = new mainmenu();
    window->show();
}


void fuser::on_fuser_2_clicked(const QModelIndex &index)
{

    QPixmap temp_non;
    temp_non = ui->fuser_2->model()->data(ui->fuser_2->model()->index(index.row(),3)).toString();

    ui->lpic_2->setPixmap(temp_non);
 ui->lpic_2->setScaledContents(true);

}

void fuser::on_term_clicked()
{
    hide();
    term* window = new term();
    window->show();
}

void fuser::on_silval_clicked()
{
    tefval* window = new tefval();
    window->show();
}

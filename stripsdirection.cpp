#include "stripsdirection.h"
#include "ui_stripsdirection.h"
#include "mainmenu.h"
#include "mainwindow.h"
#include<QtSql/QSqlRecord>
#include<QtSql/QSqlQuery>
#include<QPixmap>
#include<QDebug>
#include<QSqlError>
#include "instfuser.h"
#include "katrig.h"
#include "mqualitu.h"

stripsdirection::stripsdirection(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::stripsdirection)
{
    ui->setupUi(this);

    QSqlQuery query = QSqlQuery ();
     query.exec( "CREATE TABLE IF NOT EXISTS strdir ( id int primary key, проблема varchar , ответ varchar, пример_изображения_или_замены bytea)" );
     query.prepare("insert into strdir (id, проблема, ответ, пример_изображения_или_замены) values"
 " (1,'Проверьте, нет ли царапин и загрязнений на зеркалах','Прочистите зеркало, устраните повреждения','pic/strdir/zer.jpg'),"
"(2,'Картридж не правильно поставлен','Снимите и заново поставьте картридж',  'Нажмите на кнопку переустановка и замена катриджа'),"
"(3,'Картридж закончился или поврежден ','Поставьте новый картридж', 'Нажмите на кнопку переустановка и замена катриджа'),"
"(4,'Проверьте BTR (ролик переноса для печати) на наличие загрязнений и повреждений', 'Почистите BTR, если есть повреждения, замените его откройте крышку, достаньте картридж, под ним тот самый ролик', 'pic/strdir/btr.jpg'),"
"(5,'Проверьте есть ли повреждения или загрязнения на пути транспортировки бумаги, к процесу печати', 'Устраните повреждения, прочистите все сухой тряпкой, сжатым воздухом','К проблеме не требуется инструкций или изображения'),"
"(6,'Проверьте зеркало каретки', 'Зеркало грязное или повреждено, прочистите зеркало каретки(смотри фото справа)','pic/strdir/kar.jpg'),"
"(7,'Проблема в узле фьюзера', 'Замените фьюзер(нажмите на кнопку переустанока и замена фьюзера)', 'pic/strdir/fuser.jpg'),"
"(8,'Проверьте, нет ли на ROS (Блок для лазеров) царапин и не повреждено ли оно','Прочистите блок, откройте крышку, извлеките катридж, снимите блок','pic/strdir/las.jpg'),"
"(9,'После устранение проблемы дефект все равно остался','Вернитесь в верх таблицы, возможно после устранения появились новые проблемы','К проблеме не требуется инструкций или изображения'),"
"(10,'Нет нужной проблемы', 'Замените MCU PWB и ESS PWB (электрическое стираемое перепрограммируемое ПЗУ) или обратитесь в техническое обслуживание','pic/strdir/mcu.jpg')"
                   "ON CONFLICT (id) DO NOTHING");

     if( !query.exec() )
         qDebug() << "Error inserting image into table:\n" << query.lastError();
     strdirmodel = new QSqlQueryModel();
     strdirmodel ->setQuery("SELECT проблема, ответ, пример_изображения_или_замены FROM public.strdir order by id asc");
     strdirmodel->setHeaderData(0,Qt::Horizontal,"Описание Проблемы");
        strdirmodel->setHeaderData(1,Qt::Horizontal,"решение");

     strdirmodel->setHeaderData(2,Qt::Horizontal,"изображение\n или замена\n детали");

     ui->strdir->setModel(strdirmodel);
     ui->strdir->horizontalHeader()->setDefaultSectionSize(300);
        ui->strdir->verticalHeader()->setDefaultSectionSize(100);
     ui->strdir->show();
}

stripsdirection::~stripsdirection()
{
    delete ui;
}

void stripsdirection::on_main_triggered()
{
    hide();
    mainmenu* window = new mainmenu();
    window->show();
}

void stripsdirection::on_nazad_triggered()
{
    hide();
   mqualitu* window = new mqualitu();
   window->show();
}



void stripsdirection::on_strdir_clicked(const QModelIndex &index)
{
    QPixmap temp_non;
    temp_non = ui->strdir->model()->data(ui->strdir->model()->index(index.row(),2)).toString();

    ui->lpic_2->setPixmap(temp_non);
 ui->lpic_2->setScaledContents(true);

}

void stripsdirection::on_fuser_clicked()
{
    instfuser* window = new instfuser();
    window->show();
}

void stripsdirection::on_katrig_clicked()
{
    katrig* window = new katrig();
    window->show();
}

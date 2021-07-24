#include "emptyimage.h"
#include "ui_emptyimage.h"
#include "mainmenu.h"
#include "mqualitu.h"
#include<QtSql/QSqlRecord>
#include<QtSql/QSqlQuery>
#include<QPixmap>
#include<QDebug>
#include<QSqlError>
#include"katrig.h"

emptyimage::emptyimage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::emptyimage)
{
    ui->setupUi(this);

    QSqlQuery query = QSqlQuery ();
     query.exec( "CREATE TABLE IF NOT EXISTS emptyim ( id int primary key, проблема varchar , ответ varchar, пример_изображения_или_замены bytea)" );
     query.prepare("insert into emptyim (id, проблема, ответ, пример_изображения_или_замены) values"
" (1,'Контакт заземления барабана загрязнен и неповрежден','Почистите контакт заземления барабана и устраните повреждения','pic/emptyim/bar.jpg'),"
"(2,'Картридж не правильно поставлен','снимите и заново поставьте картридж',  'Нажмите на кнопку переустановка и замена катриджа'),"
"(3,'Картридж закончился или поврежден ','Поставьте новый картридж', 'Нажмите на кнопку переустановка и замена катриджа'),"
"(4,'Проверьте правильное ли подключены разъемы', 'Подключите праильно разъемы.','Не требуется изображений или инструкций'),"
"(5,'Проверьте, нет ли на ROS (Блок для лазеров, фото спраа) царапин и не повреждено ли оно','Прочистите блок, откройте крышку, извлеките катридж, снимите блок','pic/strdir/las.jpg'),"
"(6,'Измерьте напряжение на контакте MCU PWB(фото справа), напряжение не равно  +5 В','замените MCU PWB','К проблеме не требуется инструкций или изображения'),"
"(7,'Проверьте проводку  на обрыв цепи и короткое замыкание', 'устраните короткое замыкание','pic/strdir/mcu.jpg'),"
"(8,'После проверки проблема осталась', 'Замените блок лазера(фото справа), откройте крышку, извлеките катридж, поменяйте блок','pic/strdir/las.jpg'),"
"(9,'Напечатайте черную копию,во время цекла печати подачи бумаги выключите устойство, провреьте осталось ли на поверхности барабана  тонер(фото справа)', 'Замените BTR (ролик для печати), затем HVPS (высоковольтный блок) и MCU PWB(электрическое стираемое перепрограммируемое ПЗУ), возможно придется обратися к специалисту', 'pic/emptyim/bhm.jpg')"
                   "ON CONFLICT (id) DO NOTHING");

     if( !query.exec() )
         qDebug() << "Error inserting image into table:\n" << query.lastError();
     emimmodel = new QSqlQueryModel();
     emimmodel ->setQuery("SELECT проблема, ответ, пример_изображения_или_замены FROM public.emptyim order by id asc");
     emimmodel->setHeaderData(0,Qt::Horizontal,"Описание Проблемы");
        emimmodel->setHeaderData(1,Qt::Horizontal,"решение");
     emimmodel->setHeaderData(2,Qt::Horizontal,"изображение\n или замена\n детали");

     ui->emptyim->setModel(emimmodel);
     ui->emptyim->horizontalHeader()->setDefaultSectionSize(300);
        ui->emptyim->verticalHeader()->setDefaultSectionSize(100);

     ui->emptyim->show();
}

emptyimage::~emptyimage()
{
    delete ui;
}

void emptyimage::on_main_triggered()
{
    hide();
    mainmenu* window = new mainmenu();
    window->show();
}

void emptyimage::on_nazad_triggered()
{
    hide();
    mqualitu* window = new mqualitu();
    window->show();
}


void emptyimage::on_emptyim_clicked(const QModelIndex &index)
{
    QPixmap temp_non;
    temp_non = ui->emptyim->model()->data(ui->emptyim->model()->index(index.row(),2)).toString();

    ui->lpic_2->setPixmap(temp_non);
 ui->lpic_2->setScaledContents(true);
}

void emptyimage::on_katrig_clicked()
{
    katrig* window = new katrig();
    window->show();
}

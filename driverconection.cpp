#include "driverconection.h"
#include "ui_driverconection.h"
#include "mainmenu.h"
#include "compnetwork.h"
#include<QtSql/QSqlRecord>
#include<QtSql/QSqlQuery>
#include<QPixmap>
#include<QDebug>
#include<QSqlError>
#include"driverinstall.h"

driverconection::driverconection(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::driverconection)
{
    ui->setupUi(this);

    //    CREATE TABLE IF NOT EXISTS drivcon ( id int primary key, variant varchar , instruction1 varchar,
    //                                        instruction2 varchar, instruction3 varchar,
    //                                        instruction4 varchar, instruction5 varchar, instruction6 varchar)
        QSqlQuery query = QSqlQuery ();
         query.exec( "CREATE TABLE IF NOT EXISTS drivcon ( id int primary key, variant varchar , instruction1 varchar, instruction2 varchar, instruction3 varchar,"
                     "instruction4 varchar, instruction5 varchar, instruction6 varchar)" );
         query.prepare("insert into drivcon (id, variant, instruction1, instruction2, instruction3, instruction4, instruction5, instruction6) values"
    " (1,'подключение к компьютеру через USB соединение',"
                       "'убедитесь, что компьютер включен, и на нем есть интернет-подключение',"
                       "'включите принтер','подсоедините кабель USB к порту USB на задней стороне принтера, а затем подсоедините этот кабель к компьютеру',"
                       "'при отображении окна на принтере  (найдено новое оборудование), выполните все инструкции по установке драйвера, которые будут написаны, а затем попробуйте выполнить печать',"
                       "'если вы можете пользоваться принтером, драйвер установлен, поэтому нет необходимости выполнять дальнейших инструкций',"
                       "'если вы не можете пользоваться принтером, нажмите на кнопку устанока самого драйвера'),"
                       "(2,'подключение принтера с помощью мастера настройки беспроводной сети',"
                       "'потребуется следующее:имя сети (SSID),пароль безопасности для сети (ключ WEP или парольная фраза WPA), компьютер, подключенный к той же беспроводной сети, принтер с поддержкой беспроводного подключения:во время установки принтер должен находиться рядом с компьютером',"
                       "'убедитесь, что принтер, маршрутизатор и компьютер включены',"
                       "'убедитесь в том, что ваш компьютер и принтер подключены к одной и той же беспроводной сети',"
                       "'отсоедините от принтера все кабели USB и Ethernet',"
                       "'на панели управления принтера выберите меню Настройка, Сеть или Беспроводная сеть',"
                       "'выберите пункт Мастер установки в беспроводной сети и следуйте инструкциям на экране, чтобы подключить принтер,нажмите на кнопку устанока самого драйвера'),"
                       "(3,'при наличии поддержки используйте Wi-Fi Protected Setup (WPS) для подключения принтера',"
                       "'на панели управления принтера нажмите кнопку беспроводной сети',"
                       "'после того, как замигает световой индикатор беспроводной сети, отпустите эту кнопку',"
                       "'в течение двух минут нажмите и удерживайте кнопку WPS на маршрутизаторе беспроводной сети',"
                       "'подождите в течение двух минут, пока принтер и маршрутизатор устанавливают сетевое подключение',"
                       "'нажмите на кнопку устанока самого драйвера','перейдите дальще подключение завершено'),"
                       "(4,'подключение принтера к компьютеру через маршрутизатор с помощью стандартного кабеля Ethernet',"
                       "'подготовка: убедитесь в исправной работе кабелья Ethernet, убедитесь в наличии сетевого маршрутизатора с доступными портами Ethernet',"
                       "'подключите компьютер к маршрутизатору',"
                       "'возьмите кабель Ethernet. не используйте стандартный телефонный кабель',"
                       "'подключение: влючите принтер',"
                       "'снимите заглушку или защитную крышку с порта Ethernet на задней стороне принтера',"
                       "'подключите кабель Ethernet к принтеру и доступному порту на маршрутизаторе, нажмите на кнопку устанока самого драйвер')"

                       "ON CONFLICT (id) DO NOTHING");

         if( !query.exec() )
             qDebug() << "Error inserting image into table:\n" << query.lastError();
         drconmodel = new QSqlQueryModel();
         drconmodel ->setQuery("SELECT variant, instruction1, instruction2, instruction3, instruction4, instruction5, instruction6 FROM public.drivcon order by id asc");
         drconmodel->setHeaderData(0,Qt::Horizontal,"варианты подключения");
         drconmodel->setHeaderData(1,Qt::Horizontal,"пошаговая \nинструкция(1 шаг)");
          drconmodel->setHeaderData(2,Qt::Horizontal,"пошаговая \nинструкция(2 шаг)");
           drconmodel->setHeaderData(3,Qt::Horizontal,"пошаговая \nинструкция(3 шаг)");
            drconmodel->setHeaderData(4,Qt::Horizontal,"пошаговая \nинструкция(4 шаг)");
             drconmodel->setHeaderData(5,Qt::Horizontal,"пошаговая \nинструкция(5 шаг)");
              drconmodel->setHeaderData(6,Qt::Horizontal,"пошаговая \nинструкция(6 шаг)");



         ui->drivcon->setModel(drconmodel);

         ui->drivcon->horizontalHeader()->setDefaultSectionSize(185);
            ui->drivcon->verticalHeader()->setDefaultSectionSize(330);

         ui->drivcon->show();
}

driverconection::~driverconection()
{
    delete ui;
}

void driverconection::on_main_triggered()
{
    hide();
    mainmenu* window = new mainmenu();
    window->show();
}

void driverconection::on_nazad_triggered()
{
    hide();
    compnetwork* window = new compnetwork();
    window->show();
}



void driverconection::on_deflr_clicked()
{
    hide();
    driverinstall* window =new driverinstall();
    window->show();
}


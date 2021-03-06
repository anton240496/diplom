#include "driverinstall.h"
#include "ui_driverinstall.h"
#include "mainmenu.h"
#include "driverconection.h"
#include<QtSql/QSqlRecord>
#include<QtSql/QSqlQuery>
#include<QPixmap>
#include<QDebug>
#include<QSqlError>

driverinstall::driverinstall(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::driverinstall)
{
    ui->setupUi(this);

    QSqlQuery query = QSqlQuery ();
     query.exec( "CREATE TABLE IF NOT EXISTS drinst ( id int primary key, variant varchar , instruction12 varchar, instruction34 varchar, instruction56 varchar,"
                 "instruction78 varchar, instruction910 varchar, instruction1112 varchar, instruction13 varchar)" );
     query.prepare("insert into drinst (id, variant, instruction12, instruction34, instruction56, "
                   "instruction78, instruction910, instruction1112, instruction13) values"
" (1,'по сетевому подключению в ОС Windows 10 или Windows 8',"
                   "'1.В ОС Windows найдите и откройте раздел Панель управления 2.Выберите Устройства и принтеры, затем нажмите Добавление принтера.',"
                   "'3.В окне выберите устройство или принтер для добавления к этому ПК, выберите принтер, нажмите Далее, а затем следуйте инструкциям на экране для установки драйвера. Если ваш принтер не указан в списке, перейдите к выполнению следующих действий."
                   "4.Нажмите Необходимый принтер отсутствует в списке, а затем выберите Добавить локальный или сетевой принтер с параметрами, заданными вручную',"
                   "'5.Нажмите кнопку Далее.6.Выберите порт, который будет использоваться принтером, например USB001 для принтера, подключенного через интерфейс USB, затем нажмите кнопку Далее.',"
                   "'7.Нажмите Центр обновления Windows, а затем дождитесь обновления драйверов печати.8.Выберите HP, Hewlett-Packard или Hewlett Packard на панели Производитель, затем выберите имя принтера на панели Принтеры.',"
                   "'9.Если ваш принтер указан в списке, выберите его, нажмите кнопку Далее, а затем следуйте инструкциям на экране для установки драйвера.10.Если ваш принтер не указан в списке, дважды нажмите стрелку (Назад) в левом верхнем углу окна, чтобы вернуться к шагу Найти принтер по другим параметрам, а затем перейдите к выполнению следующих действий.',"
                   "'11.Выберите Добавить принтер по его TCP/IP-адресу или имени узла, затем нажмите Далее, пропечатайте или сканируйте документ, если все работает, значит драйвер установлен','инструкция завершена'),"

                   "(2,'по сетевому подключению в ОС Windows 7 или Windows Vista.',"
                   "'1.В ОС Windows найдите и откройте раздел Панель управления. 2.Выберите Устройства и принтеры, затем нажмите Установка принтера.',"
                   "'3.Выберите Добавить сетевой, беспроводной или Bluetooth-принтер. 4.В окне Выберите принтер выберите свой принтер, нажмите кнопку Далее, а затем следуйте инструкциям на экране для установки драйвера. Если ваш принтер не указан в списке, нажмите стрелку (Назад) для возврата к предыдущему окну и перейдите к выполнению следующих действий.',"
                   "'5.Выберите Добавить локальный принтер. 6.Выберите Использовать существующий порт (LPT1: Порт принтера) и нажмите кнопку Далее.',"
                   "'7.Нажмите Центр обновления Windows, а затем дождитесь обновления драйверов печати. 8.Выберите HP, Hewlett-Packard или Hewlett Packard на панели Производитель, затем выберите имя принтера на панели Принтеры."
                   "Если ваш принтер указан в списке, выберите его, нажмите кнопку Далее, а затем следуйте инструкциям на экране для установки драйвера. Если ваш принтер не указан в списке, нажмите стрелку (Назад) в левом верхнем углу окна, чтобы вернуться к окну Выбор типа устанавливаемого принтера, а затем перейдите к выполнению следующих действий.',"
                   "'9.Выберите Добавить сетевой, беспроводной или Bluetooth-принтер, а затем нажмите Нужный принтер отсутствует в списке 10.Выберите Добавить принтер по его TCP/IP-адресу или имени узла, затем нажмите Далее.',"
                   "'11.Выберите Автоматическое определение в раскрывающемся списке Тип устройства. 12.Введите IP-адрес принтера в текстовое поле и нажмите кнопку Далее.Чтобы найти IP-адрес принтера, напечатайте отчет о проверке беспроводной сети или страницы конфигурации сети.',"
                   "'13.Подождите, пока компьютер подключится к принтеру, затем нажмите кнопку Далее, чтобы установить драйвер печати, пропечатайте или сканируйте документ, если все работает, значит драйвер установлен'),"

                   "(3,'Интерфейс USB (Windows 10, 8)',"
                   "'1.В ОС Windows найдите и откройте раздел Панель управления.2.Выберите Устройства и принтеры, затем нажмите Добавление принтера.',"
                   "'3.В окне Выберите устройство или принтер для добавления к этому ПК выберите принтер, нажмите Далее, а затем следуйте инструкциям на экране для установки драйвера. Если ваш принтер не указан в списке, перейдите к выполнению следующих действий."
                   "4.Нажмите Необходимый принтер отсутствует в списке, а затем выберите Добавить локальный или сетевой принтер с параметрами, заданными вручную.',"
                   "'5.Нажмите кнопку Далее. 6.Выберите Использовать существующий порт (USB001: Порт виртуального принтера для USB), а затем нажмите Далее.',"
                   "'7.Нажмите Центр обновления Windows, а затем дождитесь обновления драйверов печати. 8.Выберите HP, Hewlett-Packard или Hewlett Packard на панели Производитель, затем выберите имя принтера на панели Принтеры.',"
                   "'9.Нажмите Далее и следуйте инструкциям на экране для установки драйвера.10.Отсоедините кабель USB принтера от компьютера и подключите его снова.',"
                   "'пропечатайте или сканируйте документ, если все работает, значит драйвер установлен',"
                   "'инструкция завершена'),"

                   "(4,'Интерфейс USB (Windows 7, Vista)',"
                   "'1.В ОС Windows найдите и откройте раздел Панель управления. 2.Выберите Устройства и принтеры, затем нажмите Установка принтера.',"
                   "'3.Выберите Добавить локальный принтер. 4.Выберите Использовать существующий порт (USB001: Порт виртуального принтера для USB), а затем нажмите Далее.',"
                   "'5.Нажмите Центр обновления Windows, а затем дождитесь обновления драйверов печати.6.Выберите HP, Hewlett-Packard или Hewlett Packard на панели Производитель, затем выберите имя принтера на панели Принтеры',"
                   "'7.Нажмите Далее и следуйте инструкциям на экране для установки драйвера.8.Отсоедините кабель USB принтера от компьютера и подключите его снова.',"
                   "'инструкция завершена',"
                   "'инструкция завершена',"
                   "'инструкция завершена')"

                   "ON CONFLICT (id) DO NOTHING");

     if( !query.exec() )
         qDebug() << "Error inserting image into table:\n" << query.lastError();
     drinstmodel = new QSqlQueryModel();
     drinstmodel ->setQuery("SELECT variant, instruction12, instruction34, instruction56, "
                            "instruction78, instruction910, instruction1112, instruction13 FROM public.drinst order by id asc");
     drinstmodel->setHeaderData(0,Qt::Horizontal,"подключение сетевое или\n интерфейс системы");
     drinstmodel->setHeaderData(1,Qt::Horizontal,"пошаговая \nинструкция(1,2 шаг)");
      drinstmodel->setHeaderData(2,Qt::Horizontal,"пошаговая \nинструкция(3,4 шаг)");
       drinstmodel->setHeaderData(3,Qt::Horizontal,"пошаговая \nинструкция(5,6 шаг)");
        drinstmodel->setHeaderData(4,Qt::Horizontal,"пошаговая \nинструкция(7,8 шаг)");
         drinstmodel->setHeaderData(5,Qt::Horizontal,"пошаговая \nинструкция(9,10 шаг)");
          drinstmodel->setHeaderData(6,Qt::Horizontal,"пошаговая \nинструкция(11,12 шаг)");
            drinstmodel->setHeaderData(7,Qt::Horizontal,"пошаговая \nинструкция(13 шаг)");



     ui->drivinst->setModel(drinstmodel);
    //  ui->drivinst->resizeRowsToContents();
     ui->drivinst->horizontalHeader()->setDefaultSectionSize(160);
        ui->drivinst->verticalHeader()->setDefaultSectionSize(600);

     ui->drivinst->show();
}

driverinstall::~driverinstall()
{
    delete ui;
}

void driverinstall::on_main_triggered()
{
    hide();
    mainmenu* window = new mainmenu();
    window->show();
}

void driverinstall::on_nazad_triggered()
{
    hide();
    driverconection* window = new driverconection();
    window->show();
}


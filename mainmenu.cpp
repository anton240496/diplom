#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "mstart.h"
#include "mkoper.h"
#include "wfaksregim.h"
#include "wfaksregim.h"
#include "compnetwork.h"
#include "mfypozitronik.h"
#include "faksdevise.h"
#include "mqualitu.h"
#include"mainwindow.h"
#include"fuser.h"
#include "instruction.h"



mainmenu::mainmenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainmenu)
{
    ui->setupUi(this);
}

mainmenu::~mainmenu()
{
    delete ui;
}

void mainmenu::on_start_clicked()
{

  hide();
        mstart* window = new mstart();
           window->show();
}

void mainmenu::on_pcopymode_clicked()
{
    hide();
    mkoper* window = new mkoper();
       window->show();
}

void mainmenu::on_pfaksmodel_clicked()
{
     hide();
    wfaksregim* window = new wfaksregim();
       window->show();
}

void mainmenu::on_pcomputernetwork_clicked()
{
     hide();
    compnetwork* window = new compnetwork();
       window->show();
}

void mainmenu::on_ppositronicsmpf_clicked()
{
     hide();
    mfypozitronik* window = new mfypozitronik();
       window->show();
}

void mainmenu::on_pfacsdevice_clicked()
{
    hide();
   faksdevise* window = new faksdevise();
      window->show();
}

void mainmenu::on_fuser_clicked()
{
    hide();
   fuser* window = new fuser();
      window->show();

}

void mainmenu::on_pqualitypictures_clicked()
{
     hide();
    mqualitu* window = new mqualitu();
 window->show();

}

void mainmenu::on_avtor_triggered()
{
    hide();
    MainWindow* window = new MainWindow();
    window->show();
}

void mainmenu::on_inst_triggered()
{

    instruction* window = new instruction();
    window->show();
}

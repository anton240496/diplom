#include "tormozpol.h"
#include "ui_tormozpol.h"

tormozpol::tormozpol(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tormozpol)
{
    ui->setupUi(this);
}

tormozpol::~tormozpol()
{
    delete ui;
}

void tormozpol::on_pushButton_clicked()
{
    hide();
}

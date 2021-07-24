#include "instfuser.h"
#include "ui_instfuser.h"

instfuser::instfuser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::instfuser)
{
    ui->setupUi(this);
}

instfuser::~instfuser()
{
    delete ui;
}

void instfuser::on_pushButton_clicked()
{
    hide();
}

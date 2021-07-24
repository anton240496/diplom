#include "termoplenk.h"
#include "ui_termoplenk.h"

termoplenk::termoplenk(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::termoplenk)
{
    ui->setupUi(this);
}

termoplenk::~termoplenk()
{
    delete ui;
}

void termoplenk::on_pushButton_3_clicked()
{
    hide();
}

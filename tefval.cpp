#include "tefval.h"
#include "ui_tefval.h"


tefval::tefval(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tefval)
{
    ui->setupUi(this);
}

tefval::~tefval()
{
    delete ui;
}

void tefval::on_pushButton_clicked()
{
    hide();
    \
}

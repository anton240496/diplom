#include "kaset.h"
#include "ui_kaset.h"

kaset::kaset(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::kaset)
{
    ui->setupUi(this);
}

kaset::~kaset()
{
    delete ui;
}

void kaset::on_pushButton_clicked()
{
    hide();
}

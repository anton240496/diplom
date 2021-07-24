#include "rolikpodachi.h"
#include "ui_rolikpodachi.h"

rolikpodachi::rolikpodachi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::rolikpodachi)
{
    ui->setupUi(this);
}

rolikpodachi::~rolikpodachi()
{
    delete ui;
}

void rolikpodachi::on_pushButton_clicked()
{
    hide();
}

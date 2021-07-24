#include "katrig.h"
#include "ui_katrig.h"

katrig::katrig(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::katrig)
{
    ui->setupUi(this);
}

katrig::~katrig()
{
    delete ui;
}

void katrig::on_pushButton_clicked()
{
    hide();
}

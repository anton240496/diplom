#include "paper.h"
#include "ui_paper.h"

paper::paper(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::paper)
{
    ui->setupUi(this);
}

paper::~paper()
{
    delete ui;
}

void paper::on_pushButton_clicked()
{
    hide();
}

#include "instruction.h"
#include "ui_instruction.h"


instruction::instruction(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::instruction)
{
    ui->setupUi(this);
}

instruction::~instruction()
{
    delete ui;
}

void instruction::on_pushButton_clicked()
{
    hide();
}

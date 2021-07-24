#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QMessageBox>// пакет для сообщение о ошибки в случае неверного ввода
#include <QDebug> // для прописыание информации в окно компилятора
#include<QtSql/QSqlQuery>// для прописавании в окно компилятора какие ошибки были допущены

#include "mainmenu.h"

#include<QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_checkBox_clicked()// ставим или не ставим галочку
{
    QFile file("auth.txt");

    if (!file.open(QFile::ReadOnly | QFile :: Text))// если не открыть текстовый файл
    {
        qDebug() << "dontread"; // прописывать в окно компилятора не прочтен файл
    }else if (ui->checkBox->isChecked()){//иначе если галочка стоит
        QTextStream stream(&file);

        QString buffer = stream.readLine(0);// вытащить первую строку из файла, где прописан сервер
        ui->host->setEchoMode(QLineEdit::EchoMode::NoEcho);
        ui->host->setEnabled(false);
        ui ->host->setText(buffer);

      QString buffer1 = stream.readLine(0);//  следущею строку, база
      ui->baza->setEchoMode(QLineEdit::EchoMode::NoEcho);
      ui->baza->setEnabled(false);
      ui ->baza->setText(buffer1);

        QString buffer2 = stream.readLine(0);// логин
        ui->login->setEchoMode(QLineEdit::EchoMode::NoEcho);// в слоту невидимые символы
        ui->login->setEnabled(false);// слот неактиный
        ui ->login->setText(buffer2); // название слота для заполнения пароля


    }else {file.close();// иначе если галочка не стоит

      ui->host->setEnabled(true);// слот активный
      ui->host->setText("");
      ui->host->setEchoMode(QLineEdit::EchoMode::Normal);// инфоррмация в нем заполнять в нормальном текстовом виде

      ui->baza->setEnabled(true);
      ui->baza->setText("");
      ui->baza->setEchoMode(QLineEdit::EchoMode::Normal);

       ui->login->setEnabled(true);
       ui->login->setEchoMode(QLineEdit::EchoMode::Normal);
       ui->login->setText("");
        qDebug() << "nodata";
    }
    file.close();

}

void MainWindow::on_avtor_clicked()// при нажатии кнопки входа
{


    db = QSqlDatabase:: addDatabase("QPSQL"); // проверить все заполненнные поля
    db.setHostName(""+ui->host->text());
    db.setDatabaseName(""+ui->baza->text());
    db.setUserName(""+ui->login->text());
    db.setPassword(""+ui->parol->text());



    if (!db.open()){// если не верно открыть окно ошибки
             ui->parol->setText("");
         QMessageBox::critical(this, "ошибка", "введите праильно пользоателя и пароль");


      }
    else {// иначе
       qDebug() << "Success!";
       hide();// закрыть окно входа
       mainmenu* window = new mainmenu();// поставить указатель окна "главное меню"
       window->show(); // открыть окно гланое меню

    }
}







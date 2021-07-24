#ifndef INSTFUSER_H
#define INSTFUSER_H

#include <QMainWindow>

namespace Ui {
class instfuser;
}

class instfuser : public QMainWindow
{
    Q_OBJECT

public:
    explicit instfuser(QWidget *parent = nullptr);
    ~instfuser();

private slots:
    void on_pushButton_clicked();

private:
    Ui::instfuser *ui;
};

#endif // INSTFUSER_H

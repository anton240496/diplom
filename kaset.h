#ifndef KASET_H
#define KASET_H

#include <QMainWindow>

namespace Ui {
class kaset;
}

class kaset : public QMainWindow
{
    Q_OBJECT

public:
    explicit kaset(QWidget *parent = nullptr);
    ~kaset();

private slots:
    void on_pushButton_clicked();

private:
    Ui::kaset *ui;
};

#endif // KASET_H
